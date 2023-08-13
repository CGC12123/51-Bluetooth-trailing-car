#include "car_go.h"

void car_go()
{
	L_motor_go();
	R_motor_go();
}

void car_back()
{
	L_motor_back();
	R_motor_back();
}

void car_right_go()
{
	L_motor_go();
	R_motor_stop();			
}

void car_left_go()
{
	L_motor_stop();
	R_motor_go();
}

void car_stop()
{
	L_motor_stop();
	R_motor_stop();
}

void car_left_stop() 	//¾²Ö¹×ó×ª
{
	L_motor_back();
	R_motor_go();
}

void car_right_stop() 	//¾²Ö¹ÓÒ×ª
{
	L_motor_go();
	R_motor_back();
}

/*
void car_go() 
{
	void LF_motor_go();
	void RF_motor_go();
	void LR_motor_go();
	void RR_motor_go();
}

void car_back()
{
	void LF_motor_back();
	void RF_motor_back();
	void LR_motor_back();
	void RR_motor_back();
}

void car_right_go()
{
	void LF_motor_go();
	void RF_motor_stop();
	void LR_motor_go();
	void RR_motor_stop();			
}

void car_left_go()
{
	void LF_motor_stop();
	void RF_motor_go();
	void LR_motor_stop();
	void RR_motor_go();
}

void car_stop()
{
	void LF_motor_stop();
	void RF_motor_stop();
	void LR_motor_stop();
	void RR_motor_stop();
}

void car_left_stop()
{
	void LF_motor_back();
	void RF_motor_go();
	void LR_motor_back();
	void RR_motor_go();
}

void car_right_stop()
{
	void LF_motor_go();
	void RF_motor_back();
	void LR_motor_go();
	void RR_motor_back();
}
*/