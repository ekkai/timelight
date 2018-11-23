#include <Adafruit_NeoPixel.h>

// 6번핀에 연결된 25구 Neopixel LED를 셋팅해줍니다.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(25, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  // 버튼이 연결된 3, 4번핀의 역할을 INPUT으로 설정해줍니다.
  pinMode(3, INPUT);
  pinMode(4, INPUT);
}

void loop() {
  // 3번핀과 4번핀에 연결된 버튼의 상태값을 각각 받습니다.
  int left = digitalRead(3);
  int right = digitalRead(4);

  // 양쪽 버튼을 모두 눌렀으면 LED가 녹색으로 켜집니다.
  if (left == 0 && right == 0) {
    for (int i = 0 ; i < 25 ; i++) {
      strip.setPixelColor(i, strip.Color(0, 255, 0));
    }
    strip.show();
  }
  // 3번핀에 연결된 버튼이나 4번핀에 연결된 버튼을 하나라도 눌리면 LED를 모두 꺼줍니다.
  else  {
    strip.clear();
    strip.show();
  }
  delay(100);
}

