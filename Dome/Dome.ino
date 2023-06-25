#include <Adafruit_NeoPixel.h>
#include <esp_now.h>
#include <WiFi.h>

// #define PIN  19

// #define NUMPIXELS 1

// Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
// Adafruit_NeoPixel pixels2(NUMPIXELS, 18, NEO_GRB + NEO_KHZ800);
// Adafruit_NeoPixel pixels3(NUMPIXELS, 5, NEO_GRB + NEO_KHZ800);
// Adafruit_NeoPixel pixels4(NUMPIXELS, 17, NEO_GRB + NEO_KHZ800);
// Adafruit_NeoPixel pixels5(NUMPIXELS, 16, NEO_GRB + NEO_KHZ800);

// #define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

typedef struct BodyReceiveData {
    int16_t psi = 0;
    int16_t domeLightMode = 0;
    float bodyBattery;
} BodyReceiveData;
 
BodyReceiveData bodyData;


void OnDataReceive(const uint8_t * mac, const uint8_t *incomingData, int len) {
    memcpy(&bodyData, incomingData, sizeof(bodyData));
    Serial.print(bodyData.psi); Serial.print(", ");
    Serial.print(bodyData.domeLightMode); Serial.print(", ");
    Serial.println(bodyData.bodyBattery);
}

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
      return;
  }
  esp_now_register_recv_cb(OnDataReceive);

//   pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
//   pixels2.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
//   pixels3.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
//   pixels4.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
//   pixels5.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
}

void loop() {
  // clear(); // Set all pixel colors to 'off'

  // show(0, 150, 0);

  // Serial.println(analogRead(32));


  // delay(DELAYVAL); // Pause before next pass through loop

  // clear();

  // show(150, 0, 0);

  // Serial.println(analogRead(32));


  // delay(DELAYVAL); // Pause before next pass through loop

  // clear();

  // show(0, 0, 150);

  // Serial.println(analogRead(32));


  // delay(DELAYVAL); // Pause before next pass through loop
}

// void clear()
// {
//   pixels.clear();
//   pixels2.clear();
//   pixels3.clear();
//   pixels4.clear();
//   pixels5.clear();
// }

// void show(uint8_t r, uint8_t g, uint8_t b)
// {
//   pixels.setPixelColor(0, pixels.Color(r, g, b));
//   pixels2.setPixelColor(0, pixels2.Color(r, g, b));
//   pixels3.setPixelColor(0, pixels3.Color(r, g, b));
//   pixels4.setPixelColor(0, pixels4.Color(r, g, b));
//   pixels5.setPixelColor(0, pixels5.Color(r, g, b));

//   pixels.show();
//   pixels2.show();
//   pixels3.show();
//   pixels4.show();
//   pixels5.show();

// }