#ifndef __shownumber_H
#define __shownumber_H	 
#include "delay.h"
#include "lcd.h"
#include "digital_led.h"
#include "stdlib.h"
#include "shownum.h"

	void DrawLine(u16 x1, u16 y1, u16 x2, u16 y2,u16 color);
	void DrawLine2(u16 x1, u16 y1, u16 x2, u16 y2,u16 color);
	void DrawLine3_CLEAR(u16 x1, u16 y1, u16 x2, u16 y2,u16 color);	
	void Drawday(u16 year,u16 month,u16 date);
	void Drawhour(u16 hour);
	void Drawmin(u16 min);
	void Drawsec1(u16 sec);
	void Drawsec2(u16 sec);		 				    
#endif
