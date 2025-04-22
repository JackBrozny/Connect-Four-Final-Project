#include "Screen_Driver.h"
#include <stdio.h>

void openStartupScreen(){
	LCD_Clear(0, LCD_COLOR_WHITE);
    HAL_Delay(200);
    
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

    LCD_DisplayChar(LCD_PIXEL_WIDTH - 43,LCD_PIXEL_HEIGHT * 2 / 3,'s');
    LCD_DisplayChar(LCD_PIXEL_WIDTH - 47,LCD_PIXEL_HEIGHT * 2 / 3,'r');
    LCD_DisplayChar(LCD_PIXEL_WIDTH - 53,LCD_PIXEL_HEIGHT * 2 / 3,'e');
    LCD_DisplayChar(LCD_PIXEL_WIDTH - 59,LCD_PIXEL_HEIGHT * 2 / 3,'y');
    LCD_DisplayChar(LCD_PIXEL_WIDTH - 65,LCD_PIXEL_HEIGHT * 2 / 3,'a');
    LCD_DisplayChar(LCD_PIXEL_WIDTH - 67,LCD_PIXEL_HEIGHT * 2 / 3,'l');
    LCD_DisplayChar(LCD_PIXEL_WIDTH - 75,LCD_PIXEL_HEIGHT * 2 / 3,'P');
    LCD_DisplayChar(LCD_PIXEL_WIDTH - 85,LCD_PIXEL_HEIGHT * 2 / 3,'2');

    STMPE811_TouchData touchdata;

    while (1){ //Used polling demo logic
        if (returnTouchStateAndLocation(&touchdata) == STMPE811_State_Pressed) {
			/* Touch valid */
            LCD_Clear(0, LCD_COLOR_WHITE);

			printf("\nX: %03d\nY: %03d\n", touchdata.x, touchdata.y);
            if (TM_STMPE811_TouchInRectangle(&touchdata, LCD_PIXEL_WIDTH / 4 - 40, LCD_PIXEL_HEIGHT * 2 / 3 - 40, 40 * 2, 40 * 2)){
                LCD_Clear(0, LCD_COLOR_RED); // Placeholder for second screen
                break;
            }
            else if (TM_STMPE811_TouchInRectangle(&touchdata, LCD_PIXEL_WIDTH * 3 / 4 - 40, LCD_PIXEL_HEIGHT * 2 / 3 - 40, 40 * 2, 40 * 2)){
                LCD_Clear(0, LCD_COLOR_BLUE); //Placeholder for second screen
                break;
            }
        }
    }

    openPlayScreen();
}

void openPlayScreen(){
    LCD_Clear(0, LCD_COLOR_WHITE);
    HAL_Delay(500);

    //Display empty grid
    uint16_t Ypos = LCD_PIXEL_HEIGHT / 2 - 5;
    for (uint8_t i = 0; i < 6; i++){
        uint16_t Xpos = LCD_PIXEL_WIDTH / 8;
        for (uint8_t j = 0; j < 7; j++){
            LCD_Draw_Circle_Fill(Xpos, Ypos, 12, LCD_COLOR_BLACK);
            Xpos += LCD_PIXEL_WIDTH / 8;
        }
        Ypos += LCD_PIXEL_WIDTH / 8;
    }
}
