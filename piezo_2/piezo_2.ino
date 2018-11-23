// 각 음계별 주파수를 선언해줍니다.
int c = 262;
int d = 294;
int e = 330;
int f = 349;
int g = 392;
int a = 440;
int b = 494;

// 학교종이 땡땡떙 멜로디를 제작합니다.
int c1 = 523;
int notes[25] = { g, g, a, a, g, g, e, g, g, e, e, d, g, g, a, a, g, g, e, g, e, d, e, c };

void setup() {
  // 피에조부저가 연결된 11번핀의 역할을 OUTPUT으로 설정해줍니다.
  pinMode(11, OUTPUT);
}

void loop() {
  // 1절을 재생합니다.
  for (int i = 0; i < 12; i++) {
    tone (11, notes[i], 200);
    delay(300);
  }

  delay(100);

  // 2절을 재생합니다.
  for (int i = 12; i < 25; i++) {
    tone (11, notes[i], 200);
    delay(300);
  }
}

