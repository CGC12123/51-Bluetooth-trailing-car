#include "motor.h"

//int motor_pwm=get_pwm();

void L_motor_go()
{
	IN11=1;
	IN12=0;
}
void L_motor_back()	 //左前反转
{
	IN11 = 0;
	IN12 = 1;
}
void L_motor_stop()	 //左前停转
{
	IN11 = 0;
	IN12 = 0;
}

void R_motor_go()	 //右前正转
{
 	IN13 = 1;
	IN14 = 0;
}
void R_motor_back()	 //右前反转
{
	IN13 = 0;
	IN14 = 1;
}
void R_motor_stop()	 //右前停转
{
	IN13 = 0;
	IN14 = 0;
}

/*
void LF_motor_go()		 //左前正转
{
	IN11 = 1;
	IN12 = 0;
}
void LF_motor_back()	 //左前反转
{
	IN11 = 0;
	IN12 = 1;
}
void LF_motor_stop()	 //左前停转
{
	IN11 = 0;
	IN12 = 0;
}
///////////////////////////////////
void RF_motor_go()		 //右前正转
{
 	IN13 = 1;
	IN14 = 0;
}
void RF_motor_back()	 //右前反转
{
	IN13 = 0;
	IN14 = 1;
}
void RF_motor_stop()	 //右前停转
{
	IN13 = 0;
	IN14 = 0;
}
///////////////////////////////////
void LR_motor_go()		 //左后正转
{
	IN21 = 1;
	IN22 = 0;
}
void LR_motor_back()	 //左后反转
{
	IN21 = 0;
	IN22 = 1;
}
void LR_motor_stop()	 //左后停转
{
	IN21 = 0;
	IN22 = 0;
}
///////////////////////////////////
void RR_motor_go()		 //右后正转
{
	IN23 = 1;
	IN24 = 0;
}
void RR_motor_back()	 //右后反转
{
	IN23 = 0;
	IN24 = 1;
}
void RR_motor_stop()	 //右后停转
{
	IN23 = 0;
	IN24 = 0;
}
*/


