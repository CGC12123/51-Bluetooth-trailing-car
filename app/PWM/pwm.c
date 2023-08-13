#include"pwm.h"

u8 gtim_h=0;
u8 gtim_l=0;
u8 gtim_scale=0;
u8 pwml=0;
u8 pwmr=0;
u8 g_speed=0;

void pwm_init(u8 tim_h,u8 tim_l,u8 tim_scale)//tim*tim_scale=总周期
{  	
	gtim_h=tim_h;
	gtim_l=tim_l;
	gtim_scale=tim_scale;

	TMOD|=0X01;//选择定时器0模式(高四位控制)，工作方式1
	TH0=gtim_h;//（高八位）给定时器赋初值
	TL0=gtim_l;
	ET0=1;//打开定时器0中断允许
	EA=1;//打开总中断
	TR0=1;//打开定时器			
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
		EN1B=1;		 //设置电极使能
	}
	else	
	{
		EN1A=0;
		EN1B=0;
	}
}
