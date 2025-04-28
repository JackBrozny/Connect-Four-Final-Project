/*
 * Board_Driver.h
 *
 *  Created on: April 25, 2025
 *      Author: Jack Brozny
 */

// STMP811 INTERRUPT PORT: GPIOA PIN: 15

#include "Board_Driver.h"

static uint8_t hoveringPiecePos;
static uint8_t placedPieceRow; // Used to check for win condition


GamePiece_t Board[ROWS][COLUMNS];
GamePiece_t columnSelection[COLUMNS];
static bool isPlayerBlue;
static bool isStillPlaying;

void Board_Reset(){
    isPlayerBlue = true;
    isStillPlaying = true;
    
    for (uint8_t row = BOARD_ROW_1; row <= BOARD_ROW_6; row++){
        for (uint8_t col = BOARD_COLUMN_1; col <= BOARD_COLUMN_7; col++){
            Board[row][col] = EMPTY;
        }
    }
}

bool Board_GetisStillPlaying(){
    return isStillPlaying;
}

bool Board_GetisPlayerBlue(){
    return isPlayerBlue;
}

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
    if (Board[BOARD_ROW_1][hoveringPiecePos] == EMPTY){
        for (uint8_t row = BOARD_ROW_1; row <= BOARD_ROW_6; row++){ //Iterate down through rows
            if (Board[row][hoveringPiecePos] != EMPTY){ //If the current iterated slot is full, fill the one on top
                if (isPlayerBlue){
                    Board[row-1][hoveringPiecePos] = BLUE;
                }
                else{
                    Board[row-1][hoveringPiecePos] = RED;
                }
                placedPieceRow = row-1;
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
                placedPieceRow = row;
                Screen_DrawPiece(Screen_ColumnToCoords(hoveringPiecePos), Screen_RowToCoords(row), isPlayerBlue);
                break;
            }
        }
        if (Board_CheckEndCondition())
            return;
        isPlayerBlue = !isPlayerBlue;
    }
    
    Board_SetHoveringPiece();
}

bool Board_CheckForWin(uint8_t placedRow, uint8_t placedCol){ // Brute force checks for win in all 4 directions
    uint8_t matchCount = 1; // Number of pieces in a row

    GamePiece_t placedPieceColor;
    if (isPlayerBlue){
        placedPieceColor = BLUE;
    }
    else{
        placedPieceColor = RED;
    }
    GamePiece_t comparePieceColor = EMPTY; //Set to empty to fix compiler warnings
    
    int8_t rowIter, colIter; // Use signed ints to evaluate if a number is sometimes < 0

    ///////////////////////////////CHECK HORIZONTAL 4-IN-A-ROWS
    rowIter = placedRow;
    colIter = placedCol - 1;
    while (colIter >= BOARD_COLUMN_1){ //Iterates columns to the left
        comparePieceColor = Board[rowIter][colIter];
        if (placedPieceColor == comparePieceColor){
            matchCount++;
            colIter--;
        }
        else{
            if (matchCount == 4)
            {
                //WIN
                isStillPlaying = false;             
                return true;
            }
            break;
        }
    }
    colIter = placedCol + 1;
    while (colIter <= BOARD_COLUMN_7){ // Iterates columns to the right
        comparePieceColor = Board[rowIter][colIter];
        if(placedPieceColor == comparePieceColor){
            matchCount++;
            colIter++;
        }
        else{
            break;
        }
    }

    if (matchCount == 4){
        // WIN  
        isStillPlaying = false;             
        return true;
    }
    matchCount = 1;


    

    ////////////////////////////CHECK VERTICAL 4-IN-A-ROWS
    rowIter = placedRow - 1;
    colIter = placedCol;
    while (rowIter >= BOARD_ROW_1){ //Iterates columns to the left
        comparePieceColor = Board[rowIter][colIter];
        if (placedPieceColor == comparePieceColor){
            matchCount++;
            rowIter--;
        }
        else{
            if (matchCount == 4)
            {
                //WIN
                isStillPlaying = false;             
                return true;
            }
            break;
        }
    }
    rowIter = placedRow + 1;
    while (rowIter <= BOARD_ROW_6){ // Iterates columns to the right
        comparePieceColor = Board[rowIter][colIter];
        if(placedPieceColor == comparePieceColor){
            matchCount++;
            rowIter++;
        }
        else{
            break;
        }
    }

    if (matchCount == 4){
        // WIN
        isStillPlaying = false;             
        return true;
    }
    matchCount = 1;


    ////////////////////////////CHECK DIAGONAL TOP LEFT TO BOTTOM RIGHT 4-IN-A-ROWS
    rowIter = placedRow - 1;
    colIter = placedCol - 1;
    while (rowIter >= BOARD_ROW_1 && colIter >= BOARD_COLUMN_1){ //Iterates columns to the left
        comparePieceColor = Board[rowIter][colIter];
        if (placedPieceColor == comparePieceColor){
            matchCount++;
            rowIter--;
            colIter--;
        }
        else{
            if (matchCount == 4)
            {
                //WIN
                isStillPlaying = false;             
                return true;
            }
            break;
        }
    }
    rowIter = placedRow + 1;
    colIter = placedCol + 1;
    while (colIter <= BOARD_COLUMN_7 && rowIter <= BOARD_ROW_6){ // Iterates columns to the right
        comparePieceColor = Board[rowIter][colIter];
        if(placedPieceColor == comparePieceColor){
            matchCount++;
            rowIter++;
            colIter++;
        }
        else{
            break;
        }
    }

    if (matchCount == 4){
        // WIN       
        isStillPlaying = false;             
        return true;
    }
    matchCount = 1;


    ////////////////////////////CHECK DIAGONAL TOP RIGHT TO BOTTOM LEFT 4-IN-A-ROWS
    rowIter = placedRow + 1;
    colIter = placedCol - 1;
    while (rowIter <= BOARD_ROW_6 && colIter >= BOARD_COLUMN_1){ //Iterates columns to the left
        comparePieceColor = Board[rowIter][colIter];
        if (placedPieceColor == comparePieceColor){
            matchCount++;
            rowIter++;
            colIter--;
        }
        else{
            if (matchCount == 4)
            {
                //WIN
                isStillPlaying = false;             
                return true;
            }
            break;
        }
    }
    rowIter = placedRow - 1;
    colIter = placedCol + 1;
    while (colIter <= BOARD_COLUMN_7 && rowIter >= BOARD_ROW_1){ // Iterates columns to the right
        comparePieceColor = Board[rowIter][colIter];
        if(placedPieceColor == comparePieceColor){
            matchCount++;
            rowIter--;
            colIter++;
        }
        else{
            break;
        }
    }

    if (matchCount == 4){
        // WIN
        isStillPlaying = false;             
        return true;
    }

    return false;
}

bool Board_CheckForTie(){
    for (uint8_t colIter = BOARD_COLUMN_1; colIter <= BOARD_COLUMN_7; colIter++){
        if (Board[BOARD_ROW_1][colIter] == EMPTY){
            return false;
        }
    }
    
    isStillPlaying = false;
    return true;
}

/*
0 -> No end condition
1 -> Win
2 -> Tie
*/
uint8_t Board_CheckEndCondition(){
    if (Board_CheckForWin(placedPieceRow, hoveringPiecePos)){
        return 1; 
    }
    if (Board_CheckForTie()){
        return 2;
    }

    return 0;
}


void Board_PlayPolling(){
    isPlayerBlue = true;
    Board_SetHoveringPiece();
    while (isStillPlaying){ //Used polling demo logic
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

