#include <Wire.h>
#include <TimeLib.h>
#include <DS1307RTC.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(25, 6, NEO_GRB + NEO_KHZ800);
uint32_t hoursColor = strip.Color(255, 187, 0);
uint32_t minutesColor = strip.Color(0, 255, 0);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(255);
}

void loop() {
  tmElements_t tm; // RTC 객체 선언

  if (RTC.read(tm)) { //RTC 모듈로 부터 데이터가 들어온다면
    int hours = tm.Hour; //시(hour) 데이터를 hours 변수에 담는다.
    int minutes = tm.Minute; //분(minute) 데이터를 minutes 변수에 담는다.
    int seconds = tm.Second; //초(second) 데이터를 seconds 변수에 담는다.

    // 시 설정, 00 대신 켜야하는 LED의 번호를 넣어주세요
    if (hours == 1 || hours == 13) {  // 한시
      strip.setPixelColor(00, hoursColor);
      strip.setPixelColor(00, hoursColor);
    }
    else if (hours == 2 || hours == 14) {  // 두시
      strip.setPixelColor(00, hoursColor);
      strip.setPixelColor(00, hoursColor);
    }
    else if (hours == 3 || hours == 15) {  // 세시
      strip.setPixelColor(00, hoursColor);
      strip.setPixelColor(00, hoursColor);
    }
    else if (hours == 4 || hours == 16) {  // 네시
      strip.setPixelColor(00, hoursColor);
      strip.setPixelColor(00, hoursColor);
    }
    else if (hours == 5 || hours == 17) {  // 다섯시
      strip.setPixelColor(00, hoursColor);
      strip.setPixelColor(00, hoursColor);
    }
    else if (hours == 6 || hours == 18) {  // 여섯시
      strip.setPixelColor(00, hoursColor);
      strip.setPixelColor(00, hoursColor);
    }
    else if (hours == 7 || hours == 19) {  // 일곱시
      strip.setPixelColor(00, hoursColor);
      strip.setPixelColor(00, hoursColor);
    }
    else if (hours == 8 || hours == 20) {  // 여덟시
      strip.setPixelColor(00, hoursColor);
      strip.setPixelColor(00, hoursColor);
    }
    else if (hours == 9 || hours == 21) {  // 아홉시
      strip.setPixelColor(00, hoursColor);
      strip.setPixelColor(00, hoursColor);
    }
    else if (hours == 10 || hours == 22) {  // 열시
      strip.setPixelColor(00, hoursColor);
      strip.setPixelColor(00, hoursColor);
    }
    else if (hours == 11 || hours == 23) {  // 열한시
      strip.setPixelColor(00, hoursColor);
      strip.setPixelColor(00, hoursColor);
    }
    else if (hours == 12 || hours == 24) {  // 열두시
      strip.setPixelColor(00, hoursColor);
      strip.setPixelColor(00, hoursColor);
    }
    else ;

    // =====================================================
    // 분 설정, 00 대신 켜야하는 LED의 번호를 넣어주세요
    // 가운데 LED는 빼셔도 됩니다.
    if (minutes > 4 && minutes < 10) {  // 오분
      strip.setPixelColor(00, minutesColor);
      strip.setPixelColor(00, minutesColor);
    }
    else if (minutes > 9 && minutes < 15) {  // 십분
      strip.setPixelColor(00, minutesColor);
      strip.setPixelColor(00, minutesColor);
    }
    else if (minutes > 14 && minutes < 20) {  // 십오분
      strip.setPixelColor(00, minutesColor);
      strip.setPixelColor(00, minutesColor);
    }
    else if (minutes > 19 && minutes < 25) {  // 이십분
      strip.setPixelColor(00, minutesColor);
      strip.setPixelColor(00, minutesColor);
    }
    else if (minutes > 24 && minutes < 30) {  // 이십오분
      strip.setPixelColor(00, minutesColor);
      strip.setPixelColor(00, minutesColor);
    }
    else if (minutes > 29 && minutes < 35) {  // 삼십분
      strip.setPixelColor(00, minutesColor);
      strip.setPixelColor(00, minutesColor);
    }
    else if (minutes > 34 && minutes < 40) {  // 삼십오분
      strip.setPixelColor(00, minutesColor);
      strip.setPixelColor(00, minutesColor);
    }
    else if (minutes > 39 && minutes < 45) {  // 사십분
      strip.setPixelColor(00, minutesColor);
      strip.setPixelColor(00, minutesColor);
    }
    else if (minutes > 44 && minutes < 50) {  // 사십오분
      strip.setPixelColor(00, minutesColor);
      strip.setPixelColor(00, minutesColor);
    }
    else if (minutes > 49 && minutes < 55) {  // 오십분
      strip.setPixelColor(00, minutesColor);
      strip.setPixelColor(00, minutesColor);
    }
    else if (minutes > 54 && minutes < 60) {  // 오십오분
      strip.setPixelColor(00, minutesColor);
      strip.setPixelColor(00, minutesColor);
    }
    else { // 0분 (60분)
      strip.setPixelColor(00, minutesColor);
      strip.setPixelColor(00, minutesColor);
    }
    strip.setPixelColor(12, minutesColor);

    // 5분에 한번씩 led 초기화
    if ((minutes % 5) == 0 && seconds == 0) {
      strip.clear();
    }
    strip.show();
  }
  delay(1000);
}

