const  byte  LDR1= A0;    //光敏電阻分壓輸入腳
const  byte  led = 13;    //LED燈輸出腳
int  readLDR1=0;    //光敏電阻電壓值

void  setup() {
  pinMode(led,OUTPUT);
}

void  loop() {
  readLDR1=analogRead(LDR1);  //讀取光敏電阻類比電壓輸入 
  if (readLDR1 >= 500) {  
  // 若類比輸入值大於500，LED亮
    digitalWrite(led, HIGH);
  } else {
    // 否則LED暗
    digitalWrite(led, LOW);
}
  delay(2000);
}
