#include <Adafruit_NeoPixel.h>

#define PIN       A2 // On Trinket or Gemma, suggest changing this to 1
#define NUMPIXELS 15
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
uint32_t tmr;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  for (int i = 0; i < NUMPIXELS; i++) {
    pixels.clear();
    pixels.setPixelColor(i, pixels.Color(240, 17, 214));
    pixels.show();
    delay(200);
  }
}

void yield() {
  Serial.println("Not delay!");
}
