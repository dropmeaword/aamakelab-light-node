#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <Metro.h>

#include "wifisettings.h"

#include "led_stuff.h"
#include "pir_stuff.h"
#include "osc_stuff.h"
#include "wifi_stuff.h"

// sampling rate of sensor
Metro canRead = Metro(20); // in ms

bool sensorState = false;
bool lastState = true;

void setup() {
  Serial.begin(115200);
  init_wifi();
  init_led_strip();
  init_pir();

  paint_testpattern();
  paint_one_color(CRGB::Black);
}

void loop() {
  state_loop();
  osc_message_pump();

  // check if it's time to check the sensor
  if( canRead.check() ) {
    sensorState = read_pir();
    if( (lastState == false) && (sensorState == true) ) {
      // sensor has detected movement
      osc_dispatch_sensor();
    }
    lastState = sensorState;
  } // if
}
