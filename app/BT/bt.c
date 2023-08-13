#include "bt.h"

void UART_Init(void)		
{
	PCON &= 0x7F;		
	SCON = 0x50;		
	TMOD &= 0x0F;		
	TMOD |= 0x20;		
	TL1 = 0xFD;	
	TH1 = 0xFD;		
	ET1 = 0;		
	TR1 = 1;		
	EA=1;		
	ES=1;		
}

void UART_Routine() interrupt 4
{
	u16 S;
	if(RI==1)  
	{
		car_stop();
		S=SBUF;
		switch(S)		
		{
			case ('1'):
			{	
				car_go();
				delay_ms(600);
				car_stop();
				break;
			}
			case ('2'):	
			{	
				car_back();
				delay_ms(600);
				car_stop();
				break;
			}
			case ('3'):	
			{	
				car_left_go();
				delay_ms(500);
				car_stop();
				break;
			}
			case ('4'):	
			{	
				car_right_go();
				delay_ms(500);
				car_stop();
				break;
			}
			case ('5'):	
			{	
				car_left_stop();
				delay_ms(1000);
				car_stop();
				break;
			}
			case ('6'):	
			{	
				car_right_stop();
				delay_ms(1000);
				car_stop();
				break;
			}
			case ('0'):
				car_stop();break;
		   	case ('s'):
			{
				car_go();
				delay_ms(500);
				car_right_go();
				delay_ms(500);
				car_go();
				delay_ms(500);
				car_right_go();
				delay_ms(500);
				car_go();
				delay_ms(500);
				car_right_go();
				delay_ms(500);
				car_go();
				delay_ms(500);
				car_stop();break;
			}
		}	
		RI=0;
	}
}