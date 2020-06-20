#include <SPI.h>
#include <Ethernet.h>
#include "MgsModbus.h"

MgsModbus Mb;
int  inByte = 0; // incoming serial byte

byte mac[] = {0x90, 0xA2, 0xDA, 0x0E, 0x94, 0xB5 };
IPAddress ip(192, 168, 1, 20);  // 設定Ethernet IP
IPAddress gateway(192, 168, 1, 1);  // 設定閘道器
IPAddress subnet(255, 255, 255, 0);  // 設定網路遮罩

void setup()
{  
  Serial.begin(9600);
  Serial.println("Serial interface started");
  
  Ethernet.begin(mac, ip, gateway, subnet);
  Serial.println("Ethernet interface started"); 
  
  Serial.print("My IP address: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {    
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    Serial.print("."); 
  }
  Serial.println();
  
  // print menu
  Serial.println("0 - print the first 12 words of the MbData space");
  Serial.println("1 - fill MbData with 0x0000 hex");
  Serial.println("2 - fill MbData with 0x00, 0x01, 0x02, 0x03");  
  Serial.println("3 - fill MbData with 0xAAA hex");
}

void loop()
{
  if (Serial.available() > 0) {    
    inByte = Serial.read();

    if (inByte == '0') {  //輸入0
      for (int i=0;i<12;i++) {
        Serial.print("address: "); 
        Serial.print(i); 
        Serial.print("Data: "); 
        Serial.println(Mb.MbData[i], HEX);
      }
    }  
    if (inByte == '1') {  //輸入1
      for (int i=0;i<12;i++) {
        Mb.MbData[i] = 0x0000;
      }
    }  
    if (inByte == '2') {  //輸入2
      Mb.MbData[0]=0x0000;
      Mb.MbData[1]=0x0001;
      Mb.MbData[2]=0x0002;
      Mb.MbData[3]=0x0003;      
    }  
    if (inByte == '3') {  //輸入3
      for (int i=0;i<12;i++) {
        Mb.MbData[i] = 0xAAA;
      }
    }
  }

  Mb.MbsRun();  // server receive data
}
