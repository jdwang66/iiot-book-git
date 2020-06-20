const  int  LED=9;

void  setup() {
  pinMode(LED, OUTPUT);
}

void  loop() {
  for (int i = 0; i < 256; i++) {
    analogWrite(LED, i);  // LED由暗變亮
    delay(10);
  }
  for (int i = 255; i >= 0; i--) {
    analogWrite(LED, i);  //LED由亮變暗
    delay(10);
  }
}
