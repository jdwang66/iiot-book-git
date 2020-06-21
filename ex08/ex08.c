#include <stdio.h>
unsigned short getCrc(unsigned char *data, int len)
{
	unsigned short crc=0xffff;  //��l��
	int i,j;
	unsigned char LSB;
	
	for (i=0;i<len;i++) {
		crc ^= data[i];  //xor�B��
		for (j=0;j<8;j++) {
			LSB= crc & 1;  //����bit0
			crc=crc >> 1;  //�k��1��
			if (LSB) {  //bit0��1
				crc ^= 0xA001;  //xor�B��
			} 
		}
	}
	
	return ((crc & 0xff00) >> 8) | ((crc & 0x0ff) << 8);  //���C�줸�ե洫
}
int main()
{
	unsigned char tmp[]={0x01,0x03,0x21,0x02,0x00,0x02}; //Modbus RTU�X
	printf("%x\n",getCrc(tmp,6));  //�p��ΦL�XCRC
	return 0;
}

