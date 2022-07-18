#include "oledfont.h" 

#include <stdlib.h>
#include <stdio.h>
#include "AC_Math.h"

/*清屏*/
 void FDraw_Clear( unsigned char Image[8][128] )
 {
	 memset( Image , 0 , 8*128 );
 }
 void FDraw_ClearLines( unsigned char Image[8][128] , unsigned char start , unsigned char count )
 {
	 if( start + count > 8 )
		 return;
	 for( unsigned char i = start ; i < start + count ; ++i )
		memset( Image[i] , 0 , 1*128 );
 }
/*清屏*/

/*Logo*/
	static const unsigned char Font_Logo[8][64] = 
	{	
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x07,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x07,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x1F,0x07,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x07,0x0F,0x1C,0x10,0x01,0x07,0x1F,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x1F,0x07,0x01,0x00,0x08,0x1C,0x3E,0x7F,0x3E,0x1C,0x08,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xFF,0xFF,0xFF,0x3F,0x67,0xF3,0xF9,0xFC,0xFE,0xFF,0xFF,0xFF,0xFF,0xFC,0xF0,0xF0,0xFE,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x7F,0x0F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x80,0x60,0x70,0x3C,0x1F,0x0F,0x03,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0F,0x3F,0xDF,0xEF,0xF7,0xFB,0xFF,0xFD,0xFE,0x7F,0x3F,0xBF,0x9F,0x1F,0x0F,0x0F,0x07,0x07,0x83,0xE3,0xFB,0xF9,0xFD,0xFD,0xFD,0xFD,0xFC,0xFE,0xFE,0xFE,0x3E,0x0E,0x01,0x01,0x01,0x01,0x03,0x07,0x0F,0xFF,0xFF,0xFF,0x78,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x0F,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0xE0,0x80,0x00,0x80,0x80,0xC0,0xC0,0xE0,0xE0,0xE0,0xF0,0xF0,0xF0,0xF8,0xF8,0xF8,0xF8,0xFB,0xFB,0xFF,0xFF,0xFF,0xFF,0xFF,0xFB,0xFB,0xFB,0xFF,0xF3,0xF0,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x06,0x06,0x0E,0x1E,0x3E,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0x1E,0x0E,0x0E,0x0E,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xF8,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0xFE,0x7E,0x3E,0x1E,0x0E,0x06,0x06,0x00,0x00,0x00,0x00,0x00},
		{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},
	};
	static const unsigned char Font_Logo_Rows = sizeof(Font_Logo) / sizeof(Font_Logo[0]);
	static const unsigned char Font_Logo_Columns = sizeof(Font_Logo[0]) / sizeof(Font_Logo[0][0]);
	bool FDraw_Logo( unsigned char Image[8][128] , unsigned char StRow , unsigned char StColumn )
	{
		if( Font_Logo_Rows + StRow > 8 )
			return false;
		if( Font_Logo_Columns + StColumn > 128 )
			return false;
		
		for( unsigned char i = 0 ; i < Font_Logo_Rows ; ++i )
			memcpy( &Image[StRow + i][StColumn] , Font_Logo[i] , Font_Logo_Columns );
		return true;
	}
/*Logo*/

/*ASCII 32-123*/
	static const unsigned char Font_8x6[][6] =
	{
		{0x00, 0x00, 0x00, 0x00, 0x00, 0x00},// sp
		{0x00, 0x00, 0x00, 0xF4, 0x00, 0x00},// !
		{0x00, 0x00, 0xE0, 0x00, 0xE0, 0x00},// "
		{0x00, 0x28, 0xFE, 0x28, 0xFE, 0x28},// #
		{0x00, 0x24, 0x54, 0xFE, 0x54, 0x48},// $
		{0x00, 0x46, 0x26, 0x10, 0xC8, 0xC4},// %
		{0x00, 0x6C, 0x92, 0xAA, 0x44, 0x0A},// &
		{0x00, 0x00, 0xA0, 0xC0, 0x00, 0x00},// '
		{0x00, 0x00, 0x38, 0x44, 0x82, 0x00},// (
		{0x00, 0x00, 0x82, 0x44, 0x38, 0x00},// )
		{0x00, 0x28, 0x10, 0x7C, 0x10, 0x28},// *
		{0x00, 0x10, 0x10, 0x7C, 0x10, 0x10},// +
		{0x00, 0x00, 0x00, 0x05, 0x06, 0x00},// ,
		{0x00, 0x10, 0x10, 0x10, 0x10, 0x10},// -
		{0x00, 0x00, 0x06, 0x06, 0x00, 0x00},// .
		{0x00, 0x04, 0x08, 0x10, 0x20, 0x40},// /
		{0x00, 0x7C, 0x8A, 0x92, 0xA2, 0x7C},// 0
		{0x00, 0x00, 0x42, 0xFE, 0x02, 0x00},// 1
		{0x00, 0x42, 0x86, 0x8A, 0x92, 0x62},// 2
		{0x00, 0x84, 0x82, 0xA2, 0xD2, 0x8C},// 3
		{0x00, 0x18, 0x28, 0x48, 0xFE, 0x08},// 4
		{0x00, 0xE4, 0xA2, 0xA2, 0xA2, 0x9C},// 5
		{0x00, 0x3C, 0x52, 0x92, 0x92, 0x0C},// 6
		{0x00, 0x80, 0x8E, 0x90, 0xA0, 0xC0},// 7
		{0x00, 0x6C, 0x92, 0x92, 0x92, 0x6C},// 8
		{0x00, 0x60, 0x92, 0x92, 0x94, 0x78},// 9
		{0x00, 0x00, 0x6C, 0x6C, 0x00, 0x00},// :
		{0x00, 0x00, 0x6A, 0x6C, 0x00, 0x00},// ;
		{0x00, 0x10, 0x28, 0x44, 0x82, 0x00},// <
		{0x00, 0x28, 0x28, 0x28, 0x28, 0x28},// =
		{0x00, 0x00, 0x82, 0x44, 0x28, 0x10},// >
		{0x00, 0x40, 0x80, 0x8A, 0x90, 0x60},// ?
		{0x00, 0x4C, 0x92, 0x9A, 0x8A, 0x7C},// @
		{0x00, 0x3E, 0x48, 0x88, 0x48, 0x3E},// A
		{0x00, 0xFE, 0x92, 0x92, 0x92, 0x6C},// B
		{0x00, 0x7C, 0x82, 0x82, 0x82, 0x44},// C
		{0x00, 0xFE, 0x82, 0x82, 0x44, 0x38},// D
		{0x00, 0xFE, 0x92, 0x92, 0x92, 0x82},// E
		{0x00, 0xFE, 0x90, 0x90, 0x90, 0x80},// F
		{0x00, 0x7C, 0x82, 0x92, 0x92, 0x5E},// G
		{0x00, 0xFE, 0x10, 0x10, 0x10, 0xFE},// H
		{0x00, 0x00, 0x82, 0xFE, 0x82, 0x00},// I
		{0x00, 0x04, 0x02, 0x82, 0xFC, 0x80},// J
		{0x00, 0xFE, 0x10, 0x28, 0x44, 0x82},// K
		{0x00, 0xFE, 0x02, 0x02, 0x02, 0x02},// L
		{0x00, 0xFE, 0x40, 0x30, 0x40, 0xFE},// M
		{0x00, 0xFE, 0x20, 0x10, 0x08, 0xFE},// N
		{0x00, 0x7C, 0x82, 0x82, 0x82, 0x7C},// O
		{0x00, 0xFE, 0x90, 0x90, 0x90, 0x60},// P
		{0x00, 0x7C, 0x82, 0x8A, 0x84, 0x7A},// Q
		{0x00, 0xFE, 0x90, 0x98, 0x94, 0x62},// R
		{0x00, 0x62, 0x92, 0x92, 0x92, 0x8C},// S
		{0x00, 0x80, 0x80, 0xFE, 0x80, 0x80},// T
		{0x00, 0xFC, 0x02, 0x02, 0x02, 0xFC},// U
		{0x00, 0xF8, 0x04, 0x02, 0x04, 0xF8},// V
		{0x00, 0xFC, 0x02, 0x1C, 0x02, 0xFC},// W
		{0x00, 0xC6, 0x28, 0x10, 0x28, 0xC6},// X
		{0x00, 0xE0, 0x10, 0x0E, 0x10, 0xE0},// Y
		{0x00, 0x86, 0x8A, 0x92, 0xA2, 0xC2},// Z
		{0x00, 0x00, 0xFE, 0x82, 0x82, 0x00},// [
		{0x00, 0xAA, 0x54, 0xAA, 0x54, 0xAA},// 55
		{0x00, 0x00, 0x82, 0x82, 0xFE, 0x00},// ]
		{0x00, 0x20, 0x40, 0x80, 0x40, 0x20},// ^
		{0x00, 0x02, 0x02, 0x02, 0x02, 0x02},// _
		{0x00, 0x00, 0x80, 0x40, 0x20, 0x00},// '
		{0x00, 0x04, 0x2A, 0x2A, 0x2A, 0x1E},// a
		{0x00, 0xFE, 0x12, 0x22, 0x22, 0x1C},// b
		{0x00, 0x1C, 0x22, 0x22, 0x22, 0x04},// c
		{0x00, 0x1C, 0x22, 0x22, 0x12, 0xFE},// d
		{0x00, 0x1C, 0x2A, 0x2A, 0x2A, 0x18},// e
		{0x00, 0x10, 0x7E, 0x90, 0x80, 0x40},// f
		{0x00, 0x18, 0x25, 0x25, 0x25, 0x3E},// g
		{0x00, 0xFE, 0x10, 0x20, 0x20, 0x1E},// h
		{0x00, 0x00, 0x22, 0xBE, 0x02, 0x00},// i
		{0x00, 0x02, 0x01, 0x21, 0xBE, 0x00},// j
		{0x00, 0xFE, 0x08, 0x14, 0x22, 0x00},// k
		{0x00, 0x00, 0x82, 0xFE, 0x02, 0x00},// l
		{0x00, 0x3E, 0x20, 0x18, 0x20, 0x1E},// m
		{0x00, 0x3E, 0x10, 0x20, 0x20, 0x1E},// n
		{0x00, 0x1C, 0x22, 0x22, 0x22, 0x1C},// o
		{0x00, 0x3F, 0x24, 0x24, 0x24, 0x18},// p
		{0x00, 0x18, 0x24, 0x24, 0x18, 0x3F},// q
		{0x00, 0x3E, 0x10, 0x20, 0x20, 0x10},// r
		{0x00, 0x12, 0x2A, 0x2A, 0x2A, 0x04},// s
		{0x00, 0x20, 0xFC, 0x22, 0x02, 0x04},// t
		{0x00, 0x3C, 0x02, 0x02, 0x04, 0x3E},// u
		{0x00, 0x38, 0x04, 0x02, 0x04, 0x38},// v
		{0x00, 0x3C, 0x02, 0x0C, 0x02, 0x3C},// w
		{0x00, 0x22, 0x14, 0x08, 0x14, 0x22},// x
		{0x00, 0x38, 0x05, 0x05, 0x05, 0x3E},// y
		{0x00, 0x22, 0x26, 0x2A, 0x32, 0x22},// z
	};
	static const unsigned char Font_8x6_Count = sizeof(Font_8x6) / sizeof(Font_8x6[0]);
	bool FDraw_Font8x6( unsigned char Image[8][128] , const char* str , unsigned char StRow , unsigned char StColumn )
	{
		if( StRow > 8-1 )
			return false;
		signed short length = -1;
		for( unsigned char i = 0 ; i < 255 ; ++i )
		{
			if( str[i] == '\0' )
			{
				length = i;
				break;
			}
		}
		if( length < 0 )
			return false;
		if( StColumn + length*6 > 128 )
			return false;
		
		for( unsigned char i = 0 ; i < length ; ++i )
		{
			unsigned char FontInd = str[i];
			if( FontInd < 32 || FontInd >= 32 + Font_8x6_Count )
				FontInd = 0;
			else
				FontInd -= 32;
			memcpy( &Image[StRow][StColumn+i*6] , Font_8x6[FontInd] , 6 );
		}
		
		return true;
	}
	
	static const unsigned char Font_16x8[][2][8]=
	{
		{{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},// 0
		{{0x00,0x00,0x00,0x1F,0x00,0x00,0x00,0x00},{0x00,0x00,0x00,0xCC,0x0C,0x00,0x00,0x00}},//! 1
		{{0x00,0x08,0x30,0x60,0x08,0x30,0x60,0x00},{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},//" 2
		{{0x02,0x03,0x1E,0x02,0x03,0x1E,0x02,0x00},{0x20,0xFC,0x20,0x20,0xFC,0x20,0x20,0x00}},//# 3
		{{0x00,0x0E,0x11,0x3F,0x10,0x0C,0x00,0x00},{0x00,0x18,0x04,0xFF,0x84,0x78,0x00,0x00}},//$ 4
		{{0x0F,0x10,0x0F,0x00,0x07,0x18,0x00,0x00},{0x00,0x84,0x38,0xC0,0x78,0x84,0x78,0x00}},//% 5
		{{0x00,0x0F,0x10,0x11,0x0E,0x00,0x00,0x00},{0x78,0x84,0xC4,0x24,0x98,0xE4,0x84,0x08}},//& 6
		{{0x08,0x68,0x70,0x00,0x00,0x00,0x00,0x00},{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},//' 7
		{{0x00,0x00,0x00,0x07,0x18,0x20,0x40,0x00},{0x00,0x00,0x00,0xE0,0x18,0x04,0x02,0x00}},//( 8
		{{0x00,0x40,0x20,0x18,0x07,0x00,0x00,0x00},{0x00,0x02,0x04,0x18,0xE0,0x00,0x00,0x00}},//) 9
		{{0x02,0x02,0x01,0x0F,0x01,0x02,0x02,0x00},{0x40,0x40,0x80,0xF0,0x80,0x40,0x40,0x00}},//* 10
		{{0x00,0x00,0x00,0x0F,0x00,0x00,0x00,0x00},{0x80,0x80,0x80,0xF8,0x80,0x80,0x80,0x00}},//+ 11
		{{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},{0x01,0x0D,0x0E,0x00,0x00,0x00,0x00,0x00}},//, 12
		{{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},{0x00,0x80,0x80,0x80,0x80,0x80,0x80,0x80}},//- 13
		{{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},{0x00,0x0C,0x0C,0x00,0x00,0x00,0x00,0x00}},//. 14
		{{0x00,0x00,0x00,0x00,0x01,0x06,0x18,0x20},{0x00,0x06,0x18,0x60,0x80,0x00,0x00,0x00}},/// 15
		{{0x00,0x07,0x08,0x10,0x10,0x08,0x07,0x00},{0x00,0xF0,0x08,0x04,0x04,0x08,0xF0,0x00}},//0 16
		{{0x00,0x08,0x08,0x1F,0x00,0x00,0x00,0x00},{0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x00}},//1 17
		{{0x00,0x0E,0x10,0x10,0x10,0x11,0x0E,0x00},{0x00,0x0C,0x14,0x24,0x44,0x84,0x0C,0x00}},//2 18
		{{0x00,0x0C,0x10,0x11,0x11,0x12,0x0C,0x00},{0x00,0x18,0x04,0x04,0x04,0x88,0x70,0x00}},//3 19
		{{0x00,0x00,0x03,0x04,0x08,0x1F,0x00,0x00},{0x00,0xE0,0x20,0x24,0x24,0xFC,0x24,0x00}},//4 20
		{{0x00,0x1F,0x10,0x11,0x11,0x10,0x10,0x00},{0x00,0x98,0x84,0x04,0x04,0x88,0x70,0x00}},//5 21
		{{0x00,0x07,0x08,0x11,0x11,0x18,0x00,0x00},{0x00,0xF0,0x88,0x04,0x04,0x88,0x70,0x00}},//6 22
		{{0x00,0x1C,0x10,0x10,0x13,0x1C,0x10,0x00},{0x00,0x00,0x00,0xFC,0x00,0x00,0x00,0x00}},//7 23
		{{0x00,0x0E,0x11,0x10,0x10,0x11,0x0E,0x00},{0x00,0x38,0x44,0x84,0x84,0x44,0x38,0x00}},//8 24
		{{0x00,0x07,0x08,0x10,0x10,0x08,0x07,0x00},{0x00,0x00,0x8C,0x44,0x44,0x88,0xF0,0x00}},//9 25
		{{0x00,0x00,0x00,0x03,0x03,0x00,0x00,0x00},{0x00,0x00,0x00,0x0C,0x0C,0x00,0x00,0x00}},//: 26
		{{0x00,0x00,0x00,0x01,0x00,0x00,0x00,0x00},{0x00,0x00,0x01,0x06,0x00,0x00,0x00,0x00}},//; 27
		{{0x00,0x00,0x01,0x02,0x04,0x08,0x10,0x00},{0x00,0x80,0x40,0x20,0x10,0x08,0x04,0x00}},//< 28
		{{0x02,0x02,0x02,0x02,0x02,0x02,0x02,0x00},{0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x00}},//= 29
		{{0x00,0x10,0x08,0x04,0x02,0x01,0x00,0x00},{0x00,0x04,0x08,0x10,0x20,0x40,0x80,0x00}},//> 30
		{{0x00,0x0E,0x12,0x10,0x10,0x10,0x0F,0x00},{0x00,0x00,0x00,0x0C,0x6C,0x80,0x00,0x00}},//? 31
		{{0x03,0x0C,0x13,0x14,0x17,0x08,0x07,0x00},{0xE0,0x18,0xE4,0x24,0xC4,0x28,0xD0,0x00}},//@ 32
		{{0x00,0x00,0x03,0x1C,0x07,0x00,0x00,0x00},{0x04,0x3C,0xC4,0x40,0x40,0xE4,0x1C,0x04}},//A 33
		{{0x10,0x1F,0x11,0x11,0x11,0x0E,0x00,0x00},{0x04,0xFC,0x04,0x04,0x04,0x88,0x70,0x00}},//B 34
		{{0x03,0x0C,0x10,0x10,0x10,0x10,0x1C,0x00},{0xE0,0x18,0x04,0x04,0x04,0x08,0x10,0x00}},//C 35
		{{0x10,0x1F,0x10,0x10,0x10,0x08,0x07,0x00},{0x04,0xFC,0x04,0x04,0x04,0x08,0xF0,0x00}},//D 36
		{{0x10,0x1F,0x11,0x11,0x17,0x10,0x08,0x00},{0x04,0xFC,0x04,0x04,0xC4,0x04,0x18,0x00}},//E 37
		{{0x10,0x1F,0x11,0x11,0x17,0x10,0x08,0x00},{0x04,0xFC,0x04,0x00,0xC0,0x00,0x00,0x00}},//F 38
		{{0x03,0x0C,0x10,0x10,0x10,0x1C,0x00,0x00},{0xE0,0x18,0x04,0x04,0x44,0x78,0x40,0x00}},//G 39
		{{0x10,0x1F,0x10,0x00,0x00,0x10,0x1F,0x10},{0x04,0xFC,0x84,0x80,0x80,0x84,0xFC,0x04}},//H 40
		{{0x00,0x10,0x10,0x1F,0x10,0x10,0x00,0x00},{0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x00}},//I 41
		{{0x00,0x00,0x10,0x10,0x1F,0x10,0x10,0x00},{0x03,0x01,0x01,0x01,0xFE,0x00,0x00,0x00}},//J 42
		{{0x10,0x1F,0x11,0x03,0x14,0x18,0x10,0x00},{0x04,0xFC,0x04,0x80,0x64,0x1C,0x04,0x00}},//K 43
		{{0x10,0x1F,0x10,0x00,0x00,0x00,0x00,0x00},{0x04,0xFC,0x04,0x04,0x04,0x04,0x0C,0x00}},//L 44
		{{0x10,0x1F,0x1F,0x00,0x1F,0x1F,0x10,0x00},{0x04,0xFC,0x00,0xFC,0x00,0xFC,0x04,0x00}},//M 45
		{{0x10,0x1F,0x0C,0x03,0x00,0x10,0x1F,0x10},{0x04,0xFC,0x04,0x00,0xE0,0x18,0xFC,0x00}},//N 46
		{{0x07,0x08,0x10,0x10,0x10,0x08,0x07,0x00},{0xF0,0x08,0x04,0x04,0x04,0x08,0xF0,0x00}},//O 47
		{{0x10,0x1F,0x10,0x10,0x10,0x10,0x0F,0x00},{0x04,0xFC,0x84,0x80,0x80,0x80,0x00,0x00}},//P 48
		{{0x07,0x08,0x10,0x10,0x10,0x08,0x07,0x00},{0xF0,0x18,0x24,0x24,0x1C,0x0A,0xF2,0x00}},//Q 49
		{{0x10,0x1F,0x11,0x11,0x11,0x11,0x0E,0x00},{0x04,0xFC,0x04,0x00,0xC0,0x30,0x0C,0x04}},//R 50
		{{0x00,0x0E,0x11,0x10,0x10,0x10,0x1C,0x00},{0x00,0x1C,0x04,0x84,0x84,0x44,0x38,0x00}},//S 51
		{{0x18,0x10,0x10,0x1F,0x10,0x10,0x18,0x00},{0x00,0x00,0x04,0xFC,0x04,0x00,0x00,0x00}},//T 52
		{{0x10,0x1F,0x10,0x00,0x00,0x10,0x1F,0x10},{0x00,0xF8,0x04,0x04,0x04,0x04,0xF8,0x00}},//U 53
		{{0x10,0x1E,0x11,0x00,0x00,0x13,0x1C,0x10},{0x00,0x00,0xE0,0x1C,0x70,0x80,0x00,0x00}},//V 54
		{{0x1F,0x10,0x00,0x1F,0x00,0x10,0x1F,0x00},{0xC0,0x3C,0xE0,0x00,0xE0,0x3C,0xC0,0x00}},//W 55
		{{0x10,0x18,0x16,0x01,0x01,0x16,0x18,0x10},{0x04,0x0C,0x34,0xC0,0xC0,0x34,0x0C,0x04}},//X 56
		{{0x10,0x1C,0x13,0x00,0x13,0x1C,0x10,0x00},{0x00,0x00,0x04,0xFC,0x04,0x00,0x00,0x00}},//Y 57
		{{0x08,0x10,0x10,0x10,0x13,0x1C,0x10,0x00},{0x04,0x1C,0x64,0x84,0x04,0x04,0x18,0x00}},//Z 58
		{{0x00,0x00,0x00,0x7F,0x40,0x40,0x40,0x00},{0x00,0x00,0x00,0xFE,0x02,0x02,0x02,0x00}},//[ 59
		{{0x00,0x30,0x0C,0x03,0x00,0x00,0x00,0x00},{0x00,0x00,0x00,0x80,0x60,0x1C,0x03,0x00}},//\ 60
		{{0x00,0x40,0x40,0x40,0x7F,0x00,0x00,0x00},{0x00,0x02,0x02,0x02,0xFE,0x00,0x00,0x00}},//] 61
		{{0x00,0x00,0x20,0x40,0x40,0x40,0x20,0x00},{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},//^ 62
		{{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00},{0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x01}},//_ 63
		{{0x00,0x40,0x40,0x20,0x00,0x00,0x00,0x00},{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},//` 64
		{{0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00},{0x00,0x98,0x24,0x44,0x44,0x44,0xFC,0x04}},//a 65
		{{0x10,0x1F,0x00,0x01,0x01,0x00,0x00,0x00},{0x00,0xFC,0x88,0x04,0x04,0x88,0x70,0x00}},//b 66
		{{0x00,0x00,0x00,0x01,0x01,0x01,0x00,0x00},{0x00,0x70,0x88,0x04,0x04,0x04,0x88,0x00}},//c 67
		{{0x00,0x00,0x00,0x01,0x01,0x11,0x1F,0x00},{0x00,0x70,0x88,0x04,0x04,0x08,0xFC,0x04}},//d 68
		{{0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00},{0x00,0xF8,0x44,0x44,0x44,0x44,0xC8,0x00}},//e 69
		{{0x00,0x01,0x01,0x0F,0x11,0x11,0x11,0x18},{0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x00}},//f 70
		{{0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00},{0x00,0xD6,0x29,0x29,0x29,0xC9,0x06,0x00}},//g 71
		{{0x10,0x1F,0x00,0x01,0x01,0x01,0x00,0x00},{0x04,0xFC,0x84,0x00,0x00,0x04,0xFC,0x04}},//h 72
		{{0x00,0x01,0x19,0x19,0x00,0x00,0x00,0x00},{0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x00}},//i 73
		{{0x00,0x00,0x00,0x01,0x19,0x19,0x00,0x00},{0x00,0x03,0x01,0x01,0x01,0xFE,0x00,0x00}},//j 74
		{{0x10,0x1F,0x00,0x00,0x01,0x01,0x01,0x00},{0x04,0xFC,0x24,0x40,0xB4,0x0C,0x04,0x00}},//k 75
		{{0x00,0x10,0x10,0x1F,0x00,0x00,0x00,0x00},{0x00,0x04,0x04,0xFC,0x04,0x04,0x00,0x00}},//l 76
		{{0x01,0x01,0x01,0x01,0x01,0x01,0x01,0x00},{0x04,0xFC,0x04,0x00,0xFC,0x04,0x00,0xFC}},//m 77
		{{0x01,0x01,0x00,0x01,0x01,0x01,0x00,0x00},{0x04,0xFC,0x84,0x00,0x00,0x04,0xFC,0x04}},//n 78
		{{0x00,0x00,0x01,0x01,0x01,0x01,0x00,0x00},{0x00,0xF8,0x04,0x04,0x04,0x04,0xF8,0x00}},//o 79
		{{0x01,0x01,0x00,0x01,0x01,0x00,0x00,0x00},{0x01,0xFF,0x85,0x04,0x04,0x88,0x70,0x00}},//p 80
		{{0x00,0x00,0x00,0x01,0x01,0x01,0x01,0x00},{0x00,0x70,0x88,0x04,0x04,0x05,0xFF,0x01}},//q 81
		{{0x01,0x01,0x01,0x00,0x01,0x01,0x01,0x00},{0x04,0x04,0xFC,0x84,0x04,0x00,0x80,0x00}},//r 82
		{{0x00,0x00,0x01,0x01,0x01,0x01,0x01,0x00},{0x00,0xCC,0x24,0x24,0x24,0x24,0x98,0x00}},//s 83
		{{0x00,0x01,0x01,0x07,0x01,0x01,0x00,0x00},{0x00,0x00,0x00,0xF8,0x04,0x04,0x00,0x00}},//t 84
		{{0x01,0x01,0x00,0x00,0x00,0x01,0x01,0x00},{0x00,0xF8,0x04,0x04,0x04,0x08,0xFC,0x04}},//u 85
		{{0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01},{0x00,0x80,0x70,0x0C,0x10,0x60,0x80,0x00}},//v 86
		{{0x01,0x01,0x00,0x01,0x00,0x01,0x01,0x01},{0xF0,0x0C,0x30,0xC0,0x30,0x0C,0xF0,0x00}},//w 87
		{{0x00,0x01,0x01,0x00,0x01,0x01,0x01,0x00},{0x00,0x04,0x8C,0x74,0x70,0x8C,0x04,0x00}},//x 88
		{{0x01,0x01,0x01,0x00,0x00,0x01,0x01,0x01},{0x01,0x81,0x71,0x0E,0x18,0x60,0x80,0x00}},//y 89
		{{0x00,0x01,0x01,0x01,0x01,0x01,0x01,0x00},{0x00,0x84,0x0C,0x34,0x44,0x84,0x0C,0x00}},//z 90
		{{0x00,0x00,0x00,0x00,0x01,0x3E,0x40,0x40},{0x00,0x00,0x00,0x00,0x00,0xFC,0x02,0x02}},//{ 91
		{{0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00},{0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00}},//| 92
		{{0x00,0x40,0x40,0x3E,0x01,0x00,0x00,0x00},{0x00,0x02,0x02,0xFC,0x00,0x00,0x00,0x00}},//} 93
		{{0x00,0x60,0x80,0x80,0x40,0x40,0x20,0x20},{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}},//~ 94
	};
	static const unsigned char Font_16x8_Count = sizeof(Font_16x8) / sizeof(Font_16x8[0]);
	bool FDraw_Font16x8( unsigned char Image[8][128] , const char* str , unsigned char StRow , unsigned char StColumn )
	{
		if( StRow > 8-2 )
			return false;
		signed short length = -1;
		for( unsigned char i = 0 ; i < 255 ; ++i )
		{
			if( str[i] == '\0' )
			{
				length = i;
				break;
			}
		}
		if( length < 0 )
			return false;
		if( StColumn + length*8 > 128 )
			return false;
		
		for( unsigned char i = 0 ; i < length ; ++i )
		{
			unsigned char FontInd = str[i];
			if( FontInd < 32 || FontInd >= 32 + Font_8x6_Count )
				FontInd = 0;
			else
				FontInd -= 32;
			memcpy( &Image[StRow][StColumn+i*8] , Font_16x8[FontInd][0] , 8 );
			memcpy( &Image[StRow+1][StColumn+i*8] , Font_16x8[FontInd][1] , 8 );
		}
		
		return true;
	}
/*ASCII 32-123*/

/*勾叉点*/
	static const unsigned char Font_Tick8x6[] = {0x04,0x06,0x03,0x1C,0x70,0xC0};
	static const unsigned char Font_Cross8x6[] = {0x42,0x24,0x18,0x18,0x24,0x42};
	bool FDraw_TickCross8x6( unsigned char Image[8][128] , bool Tick, unsigned char StRow , unsigned char StColumn )
	{
		if( StRow > 8-1 )
			return false;
		signed short length = -1;
		if( StColumn + 6 > 128 )
			return false;
		if( Tick )
			memcpy( &Image[StRow][StColumn] , Font_Tick8x6 , 6 );
		else
			memcpy( &Image[StRow][StColumn] , Font_Cross8x6 , 6 );
		return true;
	}
	
	static const unsigned char Font_Point8x6[] = {0x00,0x00,0x18,0x18,0x00,0x00};
	bool FDraw_Point8x6( unsigned char Image[8][128] , unsigned char StRow , unsigned char StColumn )
	{
		if( StRow > 8-1 )
			return false;
		signed short length = -1;
		if( StColumn + 6 > 128 )
			return false;
		memcpy( &Image[StRow][StColumn] , Font_Point8x6 , 6 );
		return true;
	}
/*勾叉点*/
	
/*画竖直进度条*/
	bool FDraw_VerticalProgressBar24x14( unsigned char Image[8][128] , float progress , unsigned char StRow , unsigned char StColumn )
	{
		if( StRow > 8-3 )
			return false;
		signed short length = -1;
		if( StColumn + 14 > 128 )
			return false;
		
		//求进度显示格子数
		progress += 20;
		if( progress > 140 )
			progress = 140;
		else if( progress < 0 )
			progress = 0;
		unsigned int progress_b = progress / 140.0f * 24;
		progress_b = ( 1 << progress_b ) - 1;
		
		//前两行（空行）
		memset( &Image[StRow+0][StColumn] , 0x90 , 2 );
		memset( &Image[StRow+1][StColumn] , 0x18 , 2 );
		memset( &Image[StRow+2][StColumn] , 0x09 , 2 );	
		//前两行（空行）
		memset( &Image[StRow+0][StColumn+2] , 0x80 , 1 );
		memset( &Image[StRow+1][StColumn+2] , 0x00 , 1 );
		memset( &Image[StRow+2][StColumn+2] , 0x01 , 1 );	
		//进度条
		memset( &Image[StRow+0][StColumn+3] , (progress_b>>16) | 0x80 , 2 );
		memset( &Image[StRow+1][StColumn+3] , (progress_b>>8) | 0x0 , 2 );
		memset( &Image[StRow+2][StColumn+3] , (progress_b>>0) | 0x1 , 2 );
		//前两行（空行）
		memset( &Image[StRow+0][StColumn+5] , 0x80 , 1 );
		memset( &Image[StRow+1][StColumn+5] , 0x00 , 1 );
		memset( &Image[StRow+2][StColumn+5] , 0x01 , 1 );	
		//后两行（空行）
		memset( &Image[StRow+0][StColumn+6] , 0x90 , 2 );
		memset( &Image[StRow+1][StColumn+6] , 0x18 , 2 );
		memset( &Image[StRow+2][StColumn+6] , 0x09 , 2 );
		
		//写进度数字
		char num_str[5];
		sprintf( num_str , "%3.0f" , progress - 20 );
		unsigned int FontInd;
		//0
		FontInd = num_str[0];
		if( FontInd < 32 || FontInd >= 32 + Font_8x6_Count )
			FontInd = 0;
		else
			FontInd -= 32;
		memcpy( &Image[StRow+0][StColumn+8] , Font_8x6[FontInd] , 6 );
		//1
		FontInd = num_str[1];
		if( FontInd < 32 || FontInd >= 32 + Font_8x6_Count )
			FontInd = 0;
		else
			FontInd -= 32;
		memcpy( &Image[StRow+1][StColumn+8] , Font_8x6[FontInd] , 6 );
		//2
		FontInd = num_str[2];
		if( FontInd < 32 || FontInd >= 32 + Font_8x6_Count )
			FontInd = 0;
		else
			FontInd -= 32;
		memcpy( &Image[StRow+2][StColumn+8] , Font_8x6[FontInd] , 6 );
		
		return true;
	}
/*画竖直进度条*/