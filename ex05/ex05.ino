const  int  POT=A0;
void  setup() {
  Serial.begin(9600);  //設定傳輸速度9600 bps
}
void  loop() {
  int  val = analogRead(POT);  //讀取A0類比輸入值
  int  per=map(val, 0, 1023, 0, 100);  //限制在0~100
  Serial.print("Analog Reading: ");  //輸出資料至序列埠
  Serial.print(val);  //顯示類比值
  Serial.print("  Percentage:  ");
    Serial.print(per);  //顯示百分比值
  Serial.println("%");
  delay(1000);  // 等待1秒
}
