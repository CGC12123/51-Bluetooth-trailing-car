//ͬʱ�������ҵ�pwm

#include"pwm_pid.h"

u8 gtim_h_l=0;
u8 gtim_l_l=0;
u8 gtim_scale_l=0;
u8 gduty_l=0;

u8 g_speed_l=0;
u8 g_speed_r=0;


void pwm_pid_init(u8 tim_h,u8 tim_l,u8 tim_scale)//tim*tim_scale=������
{  	
	gtim_h_l=tim_h;
	gtim_l_l=tim_l;
	gtim_scale_l=tim_scale;

	TMOD|=0X10;//ѡ��ʱ��0ģʽ(����λ����)��������ʽ1
	TH1=gtim_h_l;//���߰�λ������ʱ������ֵ
	TL1=gtim_l_l;
	ET1=1;//�򿪶�ʱ��0�ж�����
	EA=1;//�����ж�
	TR1=1;//�򿪶�ʱ��			
}

void pwm_pid() interrupt 3
{	
	static u16 time=0;

	TH0=gtim_h_l;
	TL0=gtim_l_l;

	time++;

	if(time>=gtim_scale_l)	
		time=0;	

	if(time<=g_speed_l)
	{	
		EN1A=1;		 //���õ缫ʹ��   
	}
	else
	{	
		EN1A=0;		 //���õ缫ʹ��	   
	}

	if(time<=g_speed_r)
	{	
		EN1B=1;		 //���õ缫ʹ��   
	}
	else
	{	
		EN1B=0;		 //���õ缫ʹ��	   
	}
}


