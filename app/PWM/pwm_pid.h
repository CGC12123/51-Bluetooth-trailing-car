#ifndef _PEML_H
#define _PEML_H

#include "io_definition.h"


extern u8 gtim_scale;
extern u8 g_speed_l;
extern u8 g_speed_r;


void pwm_pid_init(u8 tim_h,u8 tim_l,u8 tim_scale);


#endif