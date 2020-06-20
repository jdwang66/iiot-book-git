#include <stdio.h>
unsigned short getCrc(unsigned char *data, int len)
{
	unsigned short crc=0xffff;  //初始值
	int i,j;
	unsigned char LSB;
	
	for (i=0;i<len;i++) {
		crc ^= data[i];  //xor運算
		for (j=0;j<8;j++) {
			LSB= crc & 1;  //測試bit0
			crc=crc >> 1;  //右移1位
			if (LSB) {  //bit0為1
				crc ^= 0xA001;  //xor運算
			} 
		}
	}
	
	return ((crc & 0xff00) >> 8) | ((crc & 0x0ff) << 8);  //高低位元組交換
}
int main()
{
	unsigned char tmp[]={0x01,0x03,0x21,0x02,0x00,0x02}; //Modbus RTU碼
	printf("%x\n",getCrc(tmp,6));  //計算及印出CRC
	return 0;
}

