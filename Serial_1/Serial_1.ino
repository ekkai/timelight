void setup() {
  // 오렌지보드와 컴퓨터 간 시리얼 통신속도를 9600으로 설정합니다.
  Serial.begin(9600);
}

void loop() {
  // 오렌지보드에서 컴퓨터로 1초마다 메세지를 보냅니다.
  Serial.print("Hello World! ");
  Serial.println("KocoaFAB LOVE");
  delay(1000);
}
