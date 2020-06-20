const  int  LED=13;
const  int  Button=7;
boolean  lastButton=LOW;  //前一次按鈕狀態
boolean  currentButton=LOW;  //目前按鈕狀態
boolean  ledOn=false;  //LED狀態

boolean  debounce(boolean last) {
  // 清除機械彈跳
  boolean  current = digitalRead(Button);  //讀取目前輸入訊號
  if  (last != current) {  //若輸入訊號產生變化
    delay(5);  //延遲5毫秒
    current = digitalRead(Button);  //再讀取一次輸入訊號
  }
  return current;
}

void  setup() {
  pinMode(LED, OUTPUT);
  pinMode(Button, INPUT);
}

void  loop() {
  currentButton = debounce(lastButton); 
// 開關按下時，輸入訊號會由LOW變為HIGH
  if (lastButton == LOW && currentButton == HIGH)        
    ledOn = !ledOn;  //LED狀態反相  
  lastButton = currentButton;  //確保放開按鈕開關
  digitalWrite(LED, ledOn);
}
