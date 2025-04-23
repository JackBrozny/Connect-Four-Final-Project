/*
 * Board_Driver.h
 *
 *  Created on: April 25, 2025
 *      Author: Jack Brozny
 */

// STMP811 INTERRUPT PORT: GPIOA PIN: 15

#include "Board_Driver.h"


static uint8_t hoveringPiecePos;

GamePiece_t Board[ROWS][COLUMNS];
GamePiece_t columnSelection[COLUMNS];
static bool isPlayerBlue;


void Board_SetHoveringPiece(){
    hoveringPiecePos = BOARD_COLUMN_4; // Center of board
    Screen_DisplayHoveringPiece(isPlayerBlue);
}

void Board_ShiftHoveringPieceRight(){
    if (hoveringPiecePos < BOARD_COLUMN_7){
        hoveringPiecePos++;
        Screen_MoveHoveringPieceRight(isPlayerBlue);
    }
    HAL_Delay(150);
}

void Board_ShiftHoveringPieceLeft(){
    if (hoveringPiecePos > BOARD_COLUMN_1){
        hoveringPiecePos--;
        Screen_MoveHoveringPieceLeft(isPlayerBlue);
    }
    HAL_Delay(150);
}

void Board_DropPiece(){
    for (uint8_t row = BOARD_ROW_1; row <= BOARD_ROW_6; row++){ //Iterate down through rows
        if (Board[row][hoveringPiecePos] != EMPTY){ //If the current iterated slot is full, fill the one on top
            if (isPlayerBlue){
                Board[row-1][hoveringPiecePos] = BLUE;
            }
            else{
                Board[row-1][hoveringPiecePos] = RED;
            }
            Screen_DrawPiece(Screen_ColumnToCoords(hoveringPiecePos), Screen_RowToCoords(row-1), isPlayerBlue);
            break;
        }
        else if (row == BOARD_ROW_6){//If the iterated row makes it to the bottom, fill current slot
            if (isPlayerBlue){
                Board[row][hoveringPiecePos] = BLUE;
            }
            else{
                Board[row][hoveringPiecePos] = RED;
            }
            Screen_DrawPiece(Screen_ColumnToCoords(hoveringPiecePos), Screen_RowToCoords(row), isPlayerBlue);
            break;
        }
    }

    isPlayerBlue = !isPlayerBlue;
}

void Board_CheckForWin(){

}

void Board_PlayPolling(){
    isPlayerBlue = true;
    Board_SetHoveringPiece();
    while (1){ //Used polling demo logic
        if (returnTouchStateAndLocation(&touchdata) == STMPE811_State_Pressed) {
			/* Touch valid */

            if (TM_STMPE811_TouchInRectangle(&touchdata, 0, 0, LCD_PIXEL_WIDTH/2, LCD_PIXEL_HEIGHT)){
                Board_ShiftHoveringPieceRight();
            }
            else{
                Board_ShiftHoveringPieceLeft();
            }
        }
    }
}

