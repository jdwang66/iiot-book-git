void setup() {
    
  Serial1.begin(9600);  // 使用TX1, RX1
  Serial.begin(9600);

  pinMode(13, OUTPUT);  // LED 
  pinMode(8, OUTPUT);  // RS-485的DE, RE
}

void loop() { 
  char getdata; 

  digitalWrite(8,LOW);  //DE=RE=0, 接收模式
  
  if(Serial1.available()){
    getdata=Serial1.read();
    Serial.print("received:");
    Serial.println(getdata);
    
    if(getdata=='1'){ 
      digitalWrite(13,HIGH);  //Led ON
      delay(100);
      digitalWrite(8,HIGH);  // DE=RE=1, 傳送模式
      Serial1.print('3');
      Serial.println("Send 3");
      delay(100);      
      digitalWrite(8,LOW);  // DE=RE=0, 接收模式
    }

    if (getdata=='2') {           
      digitalWrite(13,LOW);  //Led OFF

      delay(100);
      digitalWrite(8,HIGH);  //DE=RE=1, 傳送模式
      Serial1.print('4');
      Serial.println("Send 4");
      delay(100);      
      digitalWrite(8,LOW);  // DE=RE=0, 接收模式
    }    
  }
}
