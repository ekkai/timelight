#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <Adafruit_NeoPixel.h>

// 6번핀에 연결된 25구 Neopixel LED를 셋팅해줍니다.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(25, 6, NEO_GRB + NEO_KHZ800);

// 시간을 표현하기 위해 시, 분 LED 색상을 정해줍니다.
uint32_t hoursColor = strip.Color(255, 187, 0);
uint32_t minutesColor = strip.Color(0, 255, 0);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(255);
}

void loop() {
  tmElements_t tm;

  // RTC모듈로 부터 현재 시간을 받은 뒤 현재 시간에 맞게 LED를 켜줍니다.
  if (RTC.read(tm)) {
    int hours = tm.Hour;
    int minutes = tm.Minute;
    int seconds = tm.Second;

    // 현재 시간을 표현하기 위해 각 시간별로 LED를 셋팅합니다.
    if (hours == 1 || hours == 13) {
      strip.setPixelColor(3, hoursColor);
      strip.setPixelColor(8, hoursColor);
    }
    else if (hours == 2 || hours == 14) {
      strip.setPixelColor(9, hoursColor);
      strip.setPixelColor(8, hoursColor);
    }
    else if (hours == 3 || hours == 15) {
      strip.setPixelColor(14, hoursColor);
      strip.setPixelColor(13, hoursColor);
    }
    else if (hours == 4 || hours == 16) {
      strip.setPixelColor(19, hoursColor);
      strip.setPixelColor(18, hoursColor);
    }
    else if (hours == 5 || hours == 17) {
      strip.setPixelColor(23, hoursColor);
      strip.setPixelColor(18, hoursColor);
    }
    else if (hours == 6 || hours == 18) {
      strip.setPixelColor(17, hoursColor);
      strip.setPixelColor(22, hoursColor);
    }
    else if (hours == 7 || hours == 19) {
      strip.setPixelColor(21, hoursColor);
      strip.setPixelColor(16, hoursColor);
    }
    else if (hours == 8 || hours == 20) {
      strip.setPixelColor(15, hoursColor);
      strip.setPixelColor(16, hoursColor);
    }
    else if (hours == 9 || hours == 21) {
      strip.setPixelColor(10, hoursColor);
      strip.setPixelColor(11, hoursColor);
    }
    else if (hours == 10 || hours == 22) {
      strip.setPixelColor(5, hoursColor);
      strip.setPixelColor(6, hoursColor);
    }
    else if (hours == 11 || hours == 23) {
      strip.setPixelColor(1, hoursColor);
      strip.setPixelColor(6, hoursColor);
    }
    else if (hours == 12 || hours == 24) {
      strip.setPixelColor(2, hoursColor);
      strip.setPixelColor(7, hoursColor);
    }
    else ;

    // ========================================================
    // 현재 분을 표현하기 위해 각 분 별로 LED를 셋팅합니다.
    if (minutes > 4 && minutes < 10) {
      strip.setPixelColor(3, minutesColor);
      strip.setPixelColor(8, minutesColor);
    }
    else if (minutes > 9 && minutes < 15) {
      strip.setPixelColor(9, minutesColor);
      strip.setPixelColor(8, minutesColor);
    }
    else if (minutes > 14 && minutes < 20) {
      strip.setPixelColor(14, minutesColor);
      strip.setPixelColor(13, minutesColor);
    }
    else if (minutes > 19 && minutes < 25) {
      strip.setPixelColor(19, minutesColor);
      strip.setPixelColor(18, minutesColor);
    }
    else if (minutes > 24 && minutes < 30) {
      strip.setPixelColor(23, minutesColor);
      strip.setPixelColor(18, minutesColor);
    }
    else if (minutes > 29 && minutes < 35) {
      strip.setPixelColor(22, minutesColor);
      strip.setPixelColor(17, minutesColor);
    }
    else if (minutes > 34 && minutes < 40) {
      strip.setPixelColor(21, minutesColor);
      strip.setPixelColor(16, minutesColor);
    }
    else if (minutes > 39 && minutes < 45) {
      strip.setPixelColor(15, minutesColor);
      strip.setPixelColor(16, minutesColor);
    }
    else if (minutes > 44 && minutes < 50) {
      strip.setPixelColor(10, minutesColor);
      strip.setPixelColor(11, minutesColor);
    }
    else if (minutes > 49 && minutes < 55) {
      strip.setPixelColor(5, minutesColor);
      strip.setPixelColor(6, minutesColor);
    }
    else if (minutes > 54 && minutes < 60) {
      strip.setPixelColor(1, minutesColor);
      strip.setPixelColor(6, minutesColor);
    }
    else {
      strip.setPixelColor(2, minutesColor);
      strip.setPixelColor(7, minutesColor);
    }
    strip.setPixelColor(12, minutesColor);

    // 5분마다 새로운 분을 표현해야하기 때문에 전체 LED를 초기화 해줍니다.
    if ((minutes % 5) == 0 && seconds == 0) {
      strip.clear();
    }
    strip.show();
  }
  delay(1000);
}

