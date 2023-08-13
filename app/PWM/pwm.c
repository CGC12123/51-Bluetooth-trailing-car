#include"pwm.h"

u8 gtim_h=0;
u8 gtim_l=0;
u8 gtim_scale=0;
u8 pwml=0;
u8 pwmr=0;
u8 g_speed=0;

void pwm_init(u8 tim_h,u8 tim_l,u8 tim_scale)//tim*tim_scale=������
{  	
	gtim_h=tim_h;
	gtim_l=tim_l;
	gtim_scale=tim_scale;

	TMOD|=0X01;//ѡ��ʱ��0ģʽ(����λ����)��������ʽ1
	TH0=gtim_h;//���߰�λ������ʱ������ֵ
	TL0=gtim_l;
	ET0=1;//�򿪶�ʱ��0�ж�����
	EA=1;//�����ж�
	TR0=1;//�򿪶�ʱ��			
}

void pwm() interrupt 1
{	
	static u16 time=0;

	TH0=gtim_h;
	TL0=gtim_l;

	time++;
	
	if(time>gtim_scale)
		time=0;

	//if(time<=gduty)	
	if(time<=g_speed)
	{
		EN1A=1;
		EN1B=1;		 //���õ缫ʹ��
	}
	else	
	{
		EN1A=0;
		EN1B=0;
	}
}
