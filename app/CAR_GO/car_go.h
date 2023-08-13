#ifndef _car_go_H
#define _car_go_H

#include "public.h"
#include "motor.h"
#include "io_definition.h"
/*
sbit IN11 = P0^5;
sbit IN12 = P0^6;
sbit IN13 = P0^3;
sbit IN14 = P0^4;
sbit IN21 = P3^5;
sbit IN22 = P3^6;
sbit IN23 = P3^3;
sbit IN24 = P3^4;
*/


void car_go();
void car_back();
void car_right_go();
void car_left_go();
void car_stop();
void car_left_stop();
void car_right_stop();

#endif