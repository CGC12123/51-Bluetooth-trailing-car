#include "motor.h"

//int motor_pwm=get_pwm();

void L_motor_go()
{
	IN11=1;
	IN12=0;
}
void L_motor_back()	 //��ǰ��ת
{
	IN11 = 0;
	IN12 = 1;
}
void L_motor_stop()	 //��ǰͣת
{
	IN11 = 0;
	IN12 = 0;
}

void R_motor_go()	 //��ǰ��ת
{
 	IN13 = 1;
	IN14 = 0;
}
void R_motor_back()	 //��ǰ��ת
{
	IN13 = 0;
	IN14 = 1;
}
void R_motor_stop()	 //��ǰͣת
{
	IN13 = 0;
	IN14 = 0;
}

/*
void LF_motor_go()		 //��ǰ��ת
{
	IN11 = 1;
	IN12 = 0;
}
void LF_motor_back()	 //��ǰ��ת
{
	IN11 = 0;
	IN12 = 1;
}
void LF_motor_stop()	 //��ǰͣת
{
	IN11 = 0;
	IN12 = 0;
}
///////////////////////////////////
void RF_motor_go()		 //��ǰ��ת
{
 	IN13 = 1;
	IN14 = 0;
}
void RF_motor_back()	 //��ǰ��ת
{
	IN13 = 0;
	IN14 = 1;
}
void RF_motor_stop()	 //��ǰͣת
{
	IN13 = 0;
	IN14 = 0;
}
///////////////////////////////////
void LR_motor_go()		 //�����ת
{
	IN21 = 1;
	IN22 = 0;
}
void LR_motor_back()	 //���ת
{
	IN21 = 0;
	IN22 = 1;
}
void LR_motor_stop()	 //���ͣת
{
	IN21 = 0;
	IN22 = 0;
}
///////////////////////////////////
void RR_motor_go()		 //�Һ���ת
{
	IN23 = 1;
	IN24 = 0;
}
void RR_motor_back()	 //�Һ�ת
{
	IN23 = 0;
	IN24 = 1;
}
void RR_motor_stop()	 //�Һ�ͣת
{
	IN23 = 0;
	IN24 = 0;
}
*/


