/*
 * Game_Driver.h
 *
 *  Created on: April 17, 2025
 *      Author: Jack Brozny
 */

#ifndef INC_SCREEN_DRIVER_H_
#define INC_SCREEN_DRIVER_H_

#include "LCD_Driver.h"
#include <stdio.h>
#include <stdbool.h>

extern STMPE811_TouchData touchdata;

#define SLOT_SPACE LCD_PIXEL_WIDTH/8

#define SCREEN_COLUMN_1 SLOT_SPACE
#define SCREEN_COLUMN_2 SLOT_SPACE*2
#define SCREEN_COLUMN_3 SLOT_SPACE*3
#define SCREEN_COLUMN_4 SLOT_SPACE*4
#define SCREEN_COLUMN_5 SLOT_SPACE*5
#define SCREEN_COLUMN_6 SLOT_SPACE*6
#define SCREEN_COLUMN_7 SLOT_SPACE*7

#define SCREEN_ROW_1 SLOT_SPACE*5
#define SCREEN_ROW_2 SLOT_SPACE*6
#define SCREEN_ROW_3 SLOT_SPACE*7
#define SCREEN_ROW_4 SLOT_SPACE*8
#define SCREEN_ROW_5 SLOT_SPACE*9
#define SCREEN_ROW_6 SLOT_SPACE*10


void Screen_OpenStartupScreen();
void Screen_OpenPlayScreen(bool isOnePlayer);
void Screen_OpenWinStats(bool isPlayerBlue);
void Screen_OpenTieScreen();
void Screen_DisplayHoveringPiece(bool isPlayerBlue);
void Screen_MoveHoveringPieceRight(bool isPlayerBlue);
void Screen_MoveHoveringPieceLeft(bool isPlayerBlue);
void Screen_DrawPiece(uint16_t Xpos, uint16_t Ypos, bool isPlayerBlue);

// Converts a row or column position to its pixel coordinates on the LCD screen
uint16_t Screen_RowToCoords(uint8_t position);
uint16_t Screen_ColumnToCoords(uint8_t position);


#endif 