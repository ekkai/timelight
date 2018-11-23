#include <Adafruit_NeoPixel.h>

// 6번핀에 연결된 25구 Neopixel LED를 셋팅해줍니다.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(25, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
}

void loop() {
  // 1번칸에 있는 LED를 빨간색으로 셋팅 후 켜줍니다.
  strip.setPixelColor(1, strip.Color(255, 0, 0));
  strip.show();
  delay(200);

  // 23번칸에 있는 LED를 빨간색으로 셋팅 후 켜줍니다.
  strip.setPixelColor(23, strip.Color(255, 0, 0));
  strip.show();
  delay(200);

  // 모든 LED를 꺼줍니다.
  strip.clear();
  strip.show();
  delay(200);
}

