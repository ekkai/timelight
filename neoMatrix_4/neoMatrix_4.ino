#include <Adafruit_NeoPixel.h>

// 6번핀에 연결된 25구 Neopixel LED를 셋팅해줍니다.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(25, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
}

void loop() {
  // 하트모양을 포현하는데 켜줘야하는 LED를 각각 빨간색으로 셋팅 후 켜줍니다.
  strip.setPixelColor(1, strip.Color(255, 0, 0));
  strip.setPixelColor(3, strip.Color(255, 0, 0));
  strip.setPixelColor(5, strip.Color(255, 0, 0));
  strip.setPixelColor(7, strip.Color(255, 0, 0));
  strip.setPixelColor(9, strip.Color(255, 0, 0));
  strip.setPixelColor(10, strip.Color(255, 0, 0));
  strip.setPixelColor(14, strip.Color(255, 0, 0));
  strip.setPixelColor(16, strip.Color(255, 0, 0));
  strip.setPixelColor(18, strip.Color(255, 0, 0));
  strip.setPixelColor(22, strip.Color(255, 0, 0));
  strip.show();
  delay(200);
}

