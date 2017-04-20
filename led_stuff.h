#include "FastLED.h"

#define NUM_STRIPS 1
#define NUM_LEDS_PER_STRIP 36
#define NUM_LEDS (NUM_LEDS_PER_STRIP * NUM_STRIPS)

#define DATA_PIN D2
#define CLOCK_PIN D3

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];

boolean updated, once = false;

void init_led_strip() {
  Serial.println("initialize LED strip");
  FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
}

void paint_one_color(CRGB col) {
  Serial.println("SINGLE COLOR");
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = col;
  }

  updated = true;
}

void paint_gradient(CRGB a, CRGB b) {
  Serial.println("GRADIENT");
  fill_gradient_RGB(leds,
                    0,
                    a,
                    NUM_LEDS-1,
                    b,
                    LONGEST_HUES);
  updated = true;
}

void paint_screen(int *values) {
}



