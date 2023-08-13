#ifndef _IO_DEFINITION_H
#define _IO_DEFINITION_H

#include "public.h"

//只用一个l298n，两个电机公用一个l298n的in口

//电机引脚，接l298n
sbit IN11 = P3^6;	 //左
sbit IN12 = P3^5;	 
sbit IN13 = P3^4;	 //右
sbit IN14 = P3^3;
//sbit IN21 = P3^5;	 //左后
//sbit IN22 = P3^6;
//sbit IN23 = P3^3;	 //右后
//sbit IN24 = P3^4;

//电机使能

sbit EN1A = P3^7; 	
sbit EN1B = P3^2;
//sbit EN2A = P3^7;
//sbit EN2B = P3^2;

//红外检测
sbit D1 = P1^4; //左外
sbit D2 = P1^3; //左内
sbit D3 = P1^2;	//中间
sbit D4 = P1^1;	//右内
sbit D5 = P1^0; //右外

#endif