// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <esp_now.h>
#include <WiFi.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        19 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 1 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2(NUMPIXELS, 18, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3(NUMPIXELS, 5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4(NUMPIXELS, 17, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels5(NUMPIXELS, 16, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

void setup() {
  // These lines are specifically to support the Adafruit Trinket 5V 16 MHz.
  // Any other board, you can remove this part (but no harm leaving it):
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  // END of Trinket-specific code.

  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
      return;
  }
  Serial.begin(115200);

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels2.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels3.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels4.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  pixels5.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  clear(); // Set all pixel colors to 'off'

  show(0, 150, 0);

  Serial.println(analogRead(32));


  delay(DELAYVAL); // Pause before next pass through loop

  clear();

  show(150, 0, 0);

  Serial.println(analogRead(32));


  delay(DELAYVAL); // Pause before next pass through loop

  clear();

  show(0, 0, 150);

  Serial.println(analogRead(32));


  delay(DELAYVAL); // Pause before next pass through loop
}

void clear()
{
  pixels.clear();
  pixels2.clear();
  pixels3.clear();
  pixels4.clear();
  pixels5.clear();
}

void show(uint8_t r, uint8_t g, uint8_t b)
{
  pixels.setPixelColor(0, pixels.Color(r, g, b));
  pixels2.setPixelColor(0, pixels2.Color(r, g, b));
  pixels3.setPixelColor(0, pixels3.Color(r, g, b));
  pixels4.setPixelColor(0, pixels4.Color(r, g, b));
  pixels5.setPixelColor(0, pixels5.Color(r, g, b));

  pixels.show();
  pixels2.show();
  pixels3.show();
  pixels4.show();
  pixels5.show();

}