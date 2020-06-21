#include <stdio.h>
#include <string.h>

unsigned char GetCheckCode(const char * pSendBuf, int num) 
{
	//�p��LRC
	unsigned char byLrc = 0;
	unsigned char pBuf[2];
	int nData = 0;
	int i;

	for(i=0; i<num; i+=2)
	{
		//�C��ӻݭn�o�e��ASCII�X��Ƭ��@�ӤQ���i���
		pBuf [0] = pSendBuf [i];
		pBuf [1] = pSendBuf [i+1];	
		sscanf(pBuf,"%x",&nData);	
		byLrc += nData;
	}

	byLrc = ~ byLrc;  //�Ϭ�
	byLrc ++;  //�[1
	return byLrc;
}

int main()
{
	unsigned char *buf="010304010001";  //Modbus ASCII�榡�X
	int num=strlen(buf);
	printf("num=%d\n", num);  //�L�X����
	
	unsigned char lrc=GetCheckCode(buf,num);  //�p��LRC
	printf("LRC = %x\n",lrc);
	
	return 0;
}

