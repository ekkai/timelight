void setup() {
  // 피에조부저가 연결된 11번핀의 역할을 OUTPUT으로 설정해줍니다.
  pinMode(11, OUTPUT);
}

void loop() {
  //11번 핀에 연결되어 있는 피에조 부저를 330 주파수로 0.5초간 켜줍니다.
  tone(11, 330, 500);
  delay(500);

  // 피에조 부저의 소리를 꺼줍니다.
  noTone(11);
  delay(500);
}









