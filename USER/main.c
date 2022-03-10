#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "usmart.h"
#include "rtc.h"
#include "digital_led.h"
#include "image2lcd.h"
#include "stdlib.h"
#include "BEEP.h"
#include "shownum.h"
//ALIENTEK Mini STM32�����巶������13
//RTCʵʱʱ��ʵ��  
//����֧�֣�www.openedv.com
//������������ӿƼ����޹�˾
 	

extern const u8 gImage_image1[];
 int main(void)
 { 
	u8 t;	
	u8 zd=1;
	 


	HEADCOLOR *imginfo;
	imginfo=(HEADCOLOR*)gImage_image1;
	srand(imginfo->h*imginfo->w);
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);// �����ж����ȼ�����2
	delay_init();	    	 //��ʱ������ʼ��	  
	uart_init(9600);	 	//���ڳ�ʼ��Ϊ9600
	LED_Init();				//��ʼ����LED���ӵ�Ӳ���ӿ�
 	LCD_Init();				//��ʼ��LCD
	usmart_dev.init(72);	//��ʼ��USMART		

	while(RTC_Init())		//RTC��ʼ��	��һ��Ҫ��ʼ���ɹ�
	{ 
		LCD_ShowString(60,130,200,16,16,"RTC ERROR!   ");	
		delay_ms(800);
		LCD_ShowString(60,130,200,16,16,"RTC Trying...");	
	}		    						

	draw_str.Auto_Size_Scal = 5;
        draw_str.Draw_Pen_Size = 2;
				  				POINT_COLOR = BLACK;
    BACK_COLOR = BLACK;
draw_str.Digital_Draw_Line = DrawLine;

	image_display(0,0,(u8*)gImage_image1);
	delay_ms(3000);


	POINT_COLOR = BLACK;
	
		image_display(0,0,(u8*)gImage_image1);
		Drawday(calendar.w_year,calendar.w_month,calendar.w_date);
		Drawhour(calendar.hour);
		Drawmin(calendar.min);
		draw_str.Digital_Draw_Line =DrawLine2;
		Drawsec1(calendar.sec);
		Drawsec2(calendar.sec);
	while(1)
	{								    
		if(fade_calendar.w_year!=calendar.w_year||fade_calendar.w_date!=calendar.w_date)
		{	 
			draw_str.Digital_Draw_Line =DrawLine3_CLEAR;
			Drawday(fade_calendar.w_year,fade_calendar.w_month,fade_calendar.w_date);
			draw_str.Digital_Draw_Line =DrawLine;
			Drawday(calendar.w_year,calendar.w_month,calendar.w_date);
		}
		
		if(fade_calendar.hour!=calendar.hour)
		{
			draw_str.Digital_Draw_Line =DrawLine3_CLEAR;
			Drawhour(fade_calendar.hour);
			draw_str.Digital_Draw_Line =DrawLine;
			Drawhour(calendar.hour);
		}
		
		if(fade_calendar.min!=calendar.min)
		{
			draw_str.Digital_Draw_Line =DrawLine3_CLEAR;
			Drawmin(fade_calendar.min);
			draw_str.Digital_Draw_Line =DrawLine;
			Drawmin(calendar.min);
			
		}
		
		if(fade_calendar.sec!=calendar.sec)
		{
			if(fade_calendar.sec/10!=calendar.sec/10)
			{
				draw_str.Digital_Draw_Line =DrawLine3_CLEAR;
				Drawsec1(fade_calendar.sec);
				draw_str.Digital_Draw_Line =DrawLine2;
				Drawsec1(calendar.sec);
			}
			if(calendar.min==0 && zd==1)
			{
				BEEP = 0;
				delay_ms(388);
				BEEP = 1;
				delay_ms(100);
				BEEP = 0;
				delay_ms(388);
				BEEP = 1;
				zd=0;
			}else if(calendar.min==0 && zd==0)
			{
				delay_ms(800);
			}
			else{
			delay_ms(800);
			zd = 1;
			}
		
			if(fade_calendar.sec%10!=calendar.sec%10)
			{
				draw_str.Digital_Draw_Line =DrawLine3_CLEAR;
				Drawsec2(fade_calendar.sec);
				draw_str.Digital_Draw_Line =DrawLine2;
				Drawsec2(calendar.sec);
			}
		}
		
//			LCD_ShowNum(60,162,calendar.hour,2,16);									  
//			LCD_ShowNum(84,162,calendar.min,2,16);									  
//			LCD_ShowNum(108,162,calendar.sec,2,16);
			if(ALA_calendar.w_year == calendar.w_year&&ALA_calendar.w_month == calendar.w_month&&ALA_calendar.w_date == calendar.w_date&&ALA_calendar.hour == calendar.hour&&ALA_calendar.min == calendar.min&&ALA_calendar.sec == calendar.sec)
	{
				BEEP = 0;
				if(fade_calendar.sec!=calendar.sec)
		{
			if(fade_calendar.sec/10!=calendar.sec/10)
			{
				draw_str.Digital_Draw_Line =DrawLine3_CLEAR;
				Drawsec1(fade_calendar.sec);
				draw_str.Digital_Draw_Line =DrawLine2;
				Drawsec1(calendar.sec);
			}
			if(calendar.min==0 && zd==1)
			{
				BEEP = 0;
				delay_ms(388);
				BEEP = 1;
				delay_ms(100);
				BEEP = 0;
				delay_ms(388);
				BEEP = 1;
				zd=0;
			}else if(calendar.min==0 && zd==0)
			{
				delay_ms(800);
			}
			else{
			delay_ms(800);
			zd = 1;
			}
		
			if(fade_calendar.sec%10!=calendar.sec%10)
			{
				draw_str.Digital_Draw_Line =DrawLine3_CLEAR;
				Drawsec2(fade_calendar.sec);
				draw_str.Digital_Draw_Line =DrawLine2;
				Drawsec2(calendar.sec);
			}
		}
		
			}
		}	
			
		
	}										    

 
 
		
		
		
		
		
//		Drawday();
//		Drawmoment();
//		draw_str.Digital_Draw_Line = DrawLine2;
//		Drawsec();
//		
//		delay_ms(3000);
//		draw_str.Digital_Draw_Line =DrawLine3_CLEAR;
//		Digital_Draw_num(160,111,6,40,36,6,1);
//		draw_str.Digital_Draw_Line =DrawLine2;
//		Digital_Draw_num(160,111,6,40,36,9,1);
//		
//		delay_ms(3000);
//		draw_str.Digital_Draw_Line =DrawLine3_CLEAR;
//		Digital_Draw_num(160,111,6,40,36,9,1);
//		draw_str.Digital_Draw_Line =DrawLine2;
//		Digital_Draw_num(160,111,6,40,36,0,1);
//		
//			delay_ms(3000);
//		draw_str.Digital_Draw_Line =DrawLine3_CLEAR;
//		Digital_Draw_num(160,111,6,40,36,0,1);
//		draw_str.Digital_Draw_Line =DrawLine2;
//		Digital_Draw_num(160,111,6,40,36,1,1);
//		
//			delay_ms(3000);
//		draw_str.Digital_Draw_Line =DrawLine3_CLEAR;
//		Digital_Draw_num(160,111,6,40,36,1,1);
//		draw_str.Digital_Draw_Line =DrawLine2;
//		Digital_Draw_num(160,111,6,40,36,2,1);
		
	//	while(1);
	
//		sprintf((char*)temp,"2022-2-27");
//		LCD_ShowString(83,38,10,12,6,temp);
	//Digital_Draw_num(100,50,widget,60,120,counter-1,0);
		
	//delay_ms(1000);
//	LCD_Clear(WHITE);


