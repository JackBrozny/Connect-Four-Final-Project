#include "Game_Driver.h"

void startupScreen(){
	LCD_Clear(0, LCD_COLOR_WHITE);
    // HAL_Delay(1500);
    
    // //Flashy intro
    // LCD_Draw_Expanding_Circle(100, 100, LCD_COLOR_BLUE);
    // LCD_Draw_Expanding_Circle(200, 150, LCD_COLOR_YELLOW);    
    // LCD_Draw_Expanding_Circle(130, 250, LCD_COLOR_GREEN);
    // LCD_Draw_Expanding_Circle(LCD_X_CENTER, LCD_Y_CENTER, LCD_COLOR_WHITE);
    // HAL_Delay(1000);

    //Display title
	LCD_SetTextColor(LCD_COLOR_BLACK);
	LCD_SetFont(&Font16x24);

    LCD_DisplayChar(40,20,'C');
	LCD_DisplayChar(55,20,'o');
	LCD_DisplayChar(70,20,'n');
	LCD_DisplayChar(85,20,'n');
	LCD_DisplayChar(100,20,'e');
    LCD_DisplayChar(115,20,'c');
	LCD_DisplayChar(130,20,'t');

	LCD_DisplayChar(150,20,'F');
	LCD_DisplayChar(165,20,'o');
	LCD_DisplayChar(180,20,'u');
	LCD_DisplayChar(195,20,'r');

    //Display player selections
    LCD_Draw_Circle_Fill(LCD_PIXEL_WIDTH / 4, LCD_PIXEL_HEIGHT * 2 / 3, 40, LCD_COLOR_BLUE2); 
    LCD_Draw_Circle_Fill(LCD_PIXEL_WIDTH * 3 / 4, LCD_PIXEL_HEIGHT * 2 / 3, 40, LCD_COLOR_RED); 

    LCD_SetFont(&Font12x12);
    LCD_DisplayChar(38,LCD_PIXEL_HEIGHT * 2 / 3,'1');
    LCD_DisplayChar(48,LCD_PIXEL_HEIGHT * 2 / 3,'P');
    LCD_DisplayChar(56,LCD_PIXEL_HEIGHT * 2 / 3,'l');
    LCD_DisplayChar(58,LCD_PIXEL_HEIGHT * 2 / 3,'a');
    LCD_DisplayChar(64,LCD_PIXEL_HEIGHT * 2 / 3,'y');
    LCD_DisplayChar(70,LCD_PIXEL_HEIGHT * 2 / 3,'e');
    LCD_DisplayChar(76,LCD_PIXEL_HEIGHT * 2 / 3,'r');

    LCD_DisplayChar(LCD_PIXEL_WIDTH - 43,LCD_PIXEL_HEIGHT * 2 / 3),'s');
    LCD_DisplayChar(LCD_PIXEL_WIDTH - 47,LCD_PIXEL_HEIGHT * 2 / 3,'r');
    LCD_DisplayChar(LCD_PIXEL_WIDTH - 53,LCD_PIXEL_HEIGHT * 2 / 3,'e');
    LCD_DisplayChar(LCD_PIXEL_WIDTH - 59,LCD_PIXEL_HEIGHT * 2 / 3,'y');
    LCD_DisplayChar(LCD_PIXEL_WIDTH - 65,LCD_PIXEL_HEIGHT * 2 / 3,'a');
    LCD_DisplayChar(LCD_PIXEL_WIDTH - 67,LCD_PIXEL_HEIGHT * 2 / 3,'l');
    LCD_DisplayChar(LCD_PIXEL_WIDTH - 75,LCD_PIXEL_HEIGHT * 2 / 3,'P');
    LCD_DisplayChar(LCD_PIXEL_WIDTH - 85,LCD_PIXEL_HEIGHT * 2 / 3,'2');




}
