#ifndef _IO_DEFINITION_H
#define _IO_DEFINITION_H

#include "public.h"

//ֻ��һ��l298n�������������һ��l298n��in��

//������ţ���l298n
sbit IN11 = P3^6;	 //��
sbit IN12 = P3^5;	 
sbit IN13 = P3^4;	 //��
sbit IN14 = P3^3;
//sbit IN21 = P3^5;	 //���
//sbit IN22 = P3^6;
//sbit IN23 = P3^3;	 //�Һ�
//sbit IN24 = P3^4;

//���ʹ��

sbit EN1A = P3^7; 	
sbit EN1B = P3^2;
//sbit EN2A = P3^7;
//sbit EN2B = P3^2;

//������
sbit D1 = P1^4; //����
sbit D2 = P1^3; //����
sbit D3 = P1^2;	//�м�
sbit D4 = P1^1;	//����
sbit D5 = P1^0; //����

#endif