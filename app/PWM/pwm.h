#ifndef _pwm_H
#define _pwm_H

#include "public.h"
#include "motor.h"


extern u8 gtim_scale;
extern u8 g_speed;

void pwm_init(u8 tim_h,u8 tim_l,u8 tim_scale);


#endif