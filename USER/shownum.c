#include "shownum.h"


	void DrawLine(u16 x1, u16 y1, u16 x2, u16 y2,u16 color)
{
    POINT_COLOR = NOKIA;
    LCD_DrawLine(x1,y1,x2,y2);
}

void DrawLine2(u16 x1, u16 y1, u16 x2, u16 y2,u16 color)
{
    POINT_COLOR = NOKIA;
    LCD_DrawLine(x1,y1,x2,y2);
}

void DrawLine3_CLEAR(u16 x1, u16 y1, u16 x2, u16 y2,u16 color)
{
    POINT_COLOR = BACKGROUND;
    LCD_DrawLine(x1,y1,x2,y2);
}

	void Drawday(u16 year,u16 month,u16 date)
	{
		u16 temp1,temp2,temp3,temp4,temp5,temp6,temp;
		u16 tempa,tempb,tempc;
		u16 tempa1,tempb1,tempc1;
		temp = year;
		temp4 = temp%10;
		temp3 = temp/10%10;
		temp2 = temp/10/10%10;
		temp1 = temp/10/10/10&10;
		
		tempa = month;
		tempb = tempa%10;
		tempc = tempa/10;
		
		tempa1= date;
		tempb1 = tempa1%10;
		tempc1 = tempa1/10;
		
		
		Digital_Draw_num(78,38,1,12,16,temp1,0);
		Digital_Draw_num(95,38,1,12,16,temp2,0);
		Digital_Draw_num(112,38,1,12,16,temp3,0);
		Digital_Draw_num(129,38,1,12,16,temp4,0);
		Digital_Draw_num(149,38,1,12,16,tempc,0);
		Digital_Draw_num(166,38,1,12,16,tempa,0);
		Digital_Draw_num(186,38,1,12,16,tempc1,0);
		Digital_Draw_num(203,38,1,12,16,tempb1,0);
	}
	
	void Drawhour(u16 hour)
	{	
		u16 temp1,temp2,temp3,temp4,temp5;
		
		temp1 = hour;
		temp2 = hour/10;
		temp3 = hour%10;
	
		Digital_Draw_num(90,63,6,25,40,temp2,0);
		Digital_Draw_num(120,63,6,25,40,temp3,0);
		
	}
	
	void Drawmin(u16 min)
	{
		u16 temp1,temp2,temp3;
		temp1 = min;
		temp2 = min/10;
		temp3 = min%10;
		Digital_Draw_num(160,63,6,25,40,temp2,0);
		Digital_Draw_num(190,63,6,25,40,temp3,0);
	}
	void Drawsec1(u16 sec)
	{
		u16 temp1;
		temp1 = sec/10;
		Digital_Draw_num(130,111,4,40,36,temp1,1);
	}
	
	void Drawsec2(u16 sec)
	{
		u16 temp2;
		temp2 = sec%10;
		Digital_Draw_num(180,111,4,40,36,temp2,1);
	}
