#include <stdio.h>
#include <string.h>

unsigned char GetCheckCode(const char * pSendBuf, int num) 
{
	//計算LRC
	unsigned char byLrc = 0;
	unsigned char pBuf[2];
	int nData = 0;
	int i;

	for(i=0; i<num; i+=2)
	{
		//每兩個需要發送的ASCII碼轉化為一個十六進位數
		pBuf [0] = pSendBuf [i];
		pBuf [1] = pSendBuf [i+1];	
		sscanf(pBuf,"%x",&nData);	
		byLrc += nData;
	}

	byLrc = ~ byLrc;  //反相
	byLrc ++;  //加1
	return byLrc;
}

int main()
{
	unsigned char *buf="010304010001";  //Modbus ASCII格式碼
	int num=strlen(buf);
	printf("num=%d\n", num);  //印出長度
	
	unsigned char lrc=GetCheckCode(buf,num);  //計算LRC
	printf("LRC = %x\n",lrc);
	
	return 0;
}

