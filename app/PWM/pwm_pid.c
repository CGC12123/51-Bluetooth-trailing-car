//同时更改左右的pwm

#include"pwm_pid.h"

u8 gtim_h_l=0;
u8 gtim_l_l=0;
u8 gtim_scale_l=0;
u8 gduty_l=0;

u8 g_speed_l=0;
u8 g_speed_r=0;


void pwm_pid_init(u8 tim_h,u8 tim_l,u8 tim_scale)//tim*tim_scale=总周期
{  	
	gtim_h_l=tim_h;
	gtim_l_l=tim_l;
	gtim_scale_l=tim_scale;

	TMOD|=0X10;//选择定时器0模式(高四位控制)，工作方式1
	TH1=gtim_h_l;//（高八位）给定时器赋初值
	TL1=gtim_l_l;
	ET1=1;//打开定时器0中断允许
	EA=1;//打开总中断
	TR1=1;//打开定时器			
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
		EN1A=1;		 //设置电极使能   
	}
	else
	{	
		EN1A=0;		 //设置电极使能	   
	}

	if(time<=g_speed_r)
	{	
		EN1B=1;		 //设置电极使能   
	}
	else
	{	
		EN1B=0;		 //设置电极使能	   
	}
}


