void setup() {
  
  Serial1.begin(9600);  // 使用TX1, RX1
  Serial.begin(9600);
  pinMode(8, OUTPUT);  //RS-485 DE及RE接腳
}

void loop() {
  char getdata;
  
  digitalWrite(8,HIGH);  // DE=RE=1, 傳送模式
  Serial1.print('1');
  Serial.println("Send 1");

  delay(100);
  digitalWrite(8,LOW);  // DE=RE=0, 接收模式
  delay(100);

  if(Serial1.available()){
    getdata=Serial1.read();
    Serial.print("received:");
    Serial.println(getdata);    
  }

  digitalWrite(8,HIGH);  //DE=RE=1, 傳送模式
  
  delay(5000);
  Serial1.print('2');
  Serial.println("Send 2");

  delay(100);
  digitalWrite(8,LOW);  // DE=RE=0, 接收模式
  delay(100);

  if(Serial1.available()){
    getdata=Serial1.read();
    Serial.print("received:");
    Serial.println(getdata);    
  }
  digitalWrite(8,HIGH);  //DE=RE=1, 傳送模式
  delay(5000);
}
