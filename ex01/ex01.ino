const  int  LED=13;

void  setup() {
  pinMode(LED, OUTPUT);
}

void  loop() {
  for (int i=0; i<=20; i+=2){
    digitalWrite(LED, HIGH);  // LED亮
    delay(i*10);  // 延遲由0秒至2秒
    digitalWrite(LED, LOW);  // LED暗
    delay(i*10);  // 延遲由0秒至2秒
  }

  for (int i=20; i>=0; i-=2){
    digitalWrite(LED, HIGH);  // LED亮
    delay(i*10);  // 延遲由2秒至0秒
    digitalWrite(LED, LOW);  // LED暗
    delay(i*10);  // 延遲由2秒至0秒
  }
}
