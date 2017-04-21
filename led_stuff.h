#include "FastLED.h"

#define NUM_STRIPS 1
#define NUM_LEDS_PER_STRIP 36
#define NUM_LEDS (NUM_LEDS_PER_STRIP * NUM_STRIPS)

#define DATA_PIN D2
#define CLOCK_PIN D3

CRGB leds[NUM_STRIPS * NUM_LEDS_PER_STRIP];

boolean updated, once = false;

void custom_fill_gradient_RGB( CRGB* leds,
                   uint16_t startpos, CRGB startcolor,
                   uint16_t endpos,   CRGB endcolor )
{
    // if the points are in the wrong order, straighten them
    if( endpos < startpos ) {
        uint16_t t = endpos;
        CRGB tc = endcolor;
        startpos = t;
        startcolor = tc;
        endcolor = startcolor;
        endpos = startpos;
    }

    saccum87 rdistance87;
    saccum87 gdistance87;
    saccum87 bdistance87;

    rdistance87 = (endcolor.r - startcolor.r) << 7;
    gdistance87 = (endcolor.g - startcolor.g) << 7;
    bdistance87 = (endcolor.b - startcolor.b) << 7;

    uint16_t pixeldistance = endpos - startpos;
    //uint16_t p2 = pixeldistance / 2;
    //int16_t divisor = p2 ? p2 : 1;

    int16_t divisor = pixeldistance ? pixeldistance : 1;

    saccum87 rdelta87 = rdistance87 / divisor;
    saccum87 gdelta87 = gdistance87 / divisor;
    saccum87 bdelta87 = bdistance87 / divisor;

    // added 
    rdelta87 *= 2;
    gdelta87 *= 2;
    bdelta87 *= 2;

    accum88 r88 = startcolor.r << 8;
    accum88 g88 = startcolor.g << 8;
    accum88 b88 = startcolor.b << 8;

    for( uint16_t i = startpos; i <= endpos; i++) {
        leds[i] = CRGB( r88 >> 8, g88 >> 8, b88 >> 8);
        r88 += rdelta87;
        g88 += gdelta87;
        b88 += bdelta87;
    }
}

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
  paint_one_color(CRGB::Black);
  FastLED.show();
}

void paint_gradient(CRGB a, CRGB b) {
  custom_fill_gradient_RGB(leds, 0, a, 18, b);
  custom_fill_gradient_RGB(leds, 18, b, NUM_LEDS, a);
  FastLED.show();
}

void paint_screen(int *values) {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i].r = values[i*3];
    leds[i].g = values[(i*3)+1];
    leds[i].b = values[(i*3)+2];
  }
  FastLED.show();
}



