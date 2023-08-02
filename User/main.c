#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "OLED.h"
#include "Serial.h"
#include "Key.h"

int main(void)
{
	OLED_Init();
	Key_Init();
	Serial_Initilize();
	OLED_ShowString(1, 1, "TxPackage:");
	OLED_ShowString(3, 1, "RxPackage:");
	//填充发送缓冲区数组
	Serial_TxPackage[0]=0x01;
	Serial_TxPackage[1]=0x02;
	Serial_TxPackage[2]=0x03;
	Serial_TxPackage[3]=0x04;
	while(1)
	{
		if(Key_GetNum()==1)
		{
			Serial_TxPackage[0]++;
			Serial_TxPackage[1]++;
			Serial_TxPackage[2]++;
			Serial_TxPackage[3]++;
			Serial_SendPackage();
			OLED_ShowHexNum(2, 1, Serial_TxPackage[0], 2);
			OLED_ShowHexNum(2, 4, Serial_TxPackage[1], 2);
			OLED_ShowHexNum(2, 7, Serial_TxPackage[2], 2);
			OLED_ShowHexNum(2, 10, Serial_TxPackage[3], 2);
			Delay_s(1);
		}
		if(Serial_GetRxFlag()==1)
		{
			OLED_ShowHexNum(4, 1, Serial_RxPackage[0], 2);
			OLED_ShowHexNum(4, 4, Serial_RxPackage[1], 2);
			OLED_ShowHexNum(4, 7, Serial_RxPackage[2], 2);
			OLED_ShowHexNum(4, 10, Serial_RxPackage[3], 2);
		}
	}
}
