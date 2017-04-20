#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <Metro.h>

#include "wifisettings.h"

#include "led_stuff.h"
#include "pir_stuff.h"
#include "osc_stuff.h"
#include "wifi_stuff.h"


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

//  bool sensorState = read_pir();
  // @NOTE doing nothing with this yet
}
