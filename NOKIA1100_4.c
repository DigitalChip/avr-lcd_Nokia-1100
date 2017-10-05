#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>

#include "nokia1100_lcd_lib.h"	// Подключаем драйвер LCD-контроллера NOKIA1100

int main(void)
{

	nlcd_Init();
	_delay_ms(100);

		
  while(1)
  {
	nlcd_GotoXY(0,0);

	nlcd_PrintF(PSTR("ПИШЕМ КИРИЛЛИЦЕЙ")); // Другой способ задания строк в программной памяти
	nlcd_PrintF(PSTR("----------------"));
	nlcd_PrintF(PSTR(" DigitalChip.ru "));
	nlcd_PrintF(PSTR("  представляет  "));
	nlcd_PrintF(PSTR(" NOKIA 1100 LCD "));
	nlcd_PrintF(PSTR("  demonstration "));
	nlcd_PrintF(PSTR("----------------"));
	
	_delay_ms(8000);
//
	nlcd_GotoXY(2,7);
	nlcd_PrintF(PSTR("Clear screen"));
	_delay_ms(4000);
	nlcd_Clear();
//
	nlcd_GotoXY(1,7);
	nlcd_PrintF(PSTR("Pixel function"));

	for (unsigned char i = 0; i<96; i++)
	{
		for (unsigned char j = 0; j<57; j++)
		{
			nlcd_Pixel(i,j,PIXEL_ON);
			j++;
		}
		i++;
	}
	_delay_ms(4000);
//
	nlcd_Clear();
	nlcd_GotoXY(0,7);
	nlcd_PrintF(PSTR("Line function   "));
					  
	nlcd_Line (3,4,90,41, PIXEL_ON);
	nlcd_Line (95,0,30,55, PIXEL_ON);
	nlcd_Line (20,20,70,60, PIXEL_ON);
	
	_delay_ms(4000);

//
	nlcd_Clear();
	nlcd_GotoXY(0,7);
	nlcd_PrintF(PSTR("Circle function "));



	nlcd_Circle(50,30,20, FILL_OFF, PIXEL_ON);
	_delay_ms(4000);

//
	nlcd_GotoXY(0,7);
	nlcd_PrintF(PSTR("Fill circle     "));

	nlcd_Circle(40,25,15, FILL_ON, PIXEL_ON);
	_delay_ms(4000);
//
	nlcd_GotoXY(0,7);
	nlcd_PrintF(PSTR("Fill rectangle  "));

	nlcd_Rect (10,10,55,38,FILL_ON, PIXEL_ON);
	_delay_ms(4000);

//
	nlcd_GotoXY(0,7);
	nlcd_PrintF(PSTR("Rectangle invers"));

	nlcd_Rect (20,20,45,34,FILL_OFF, PIXEL_INV);
	_delay_ms(4000);

//
	nlcd_GotoXY(0,7);
	nlcd_PrintF(PSTR("Pixel inversion "));

	for (unsigned char i = 0; i<96; i++)
	{
		for (unsigned char j = 0; j<57; j++)
		{
			nlcd_Pixel(i,j,PIXEL_INV);
			j++;
		}
		i++; i++;
	}
	_delay_ms(4000);
//

	nlcd_Clear();

	nlcd_PrintF(PSTR(" GRAPH MODE DEMO")); 
	nlcd_PrintF(PSTR("----------------"));
	nlcd_PrintF(PSTR("   End of demo  "));
	nlcd_PrintF(PSTR("                "));
	nlcd_PrintF(PSTR("   see more on  "));
	nlcd_PrintF(PSTR(" digitalchip.ru "));
	nlcd_PrintF(PSTR("----------------"));
	
	_delay_ms(8000);

	nlcd_Clear();
   }
}
