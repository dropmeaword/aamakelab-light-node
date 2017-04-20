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
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].r = 0;
    leds[i].g = 0;
    leds[i].b = 0;
  }
}

void paint_one_color(CRGB col) {
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = col;
  }
  FastLED.show();
}

void paint_testpattern() {
  paint_one_color(CRGB::Red);
  FastLED.show();
  delay(1000);
  paint_one_color(CRGB::Green);
  FastLED.show();
  delay(1000);
  paint_one_color(CRGB::Blue);
  FastLED.show();
  delay(1000);
  paint_one_color(CRGB::White);
  FastLED.show();
  delay(1000);
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



