#include <ESP8266WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <Metro.h>

#include "wifisettings.h"

#include "led_stuff.h"
#include "osc_stuff.h"
#include "wifi_stuff.h"


void setup() {
  Serial.begin(115200);
  init_led_strip();
  init_wifi();
}

void loop() {
  state_loop();
  osc_message_pump();
  
  if(updated) {
    FastLED.show();
    updated = false;
  }
}
