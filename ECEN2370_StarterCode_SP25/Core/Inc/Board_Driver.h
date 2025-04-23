/*
 * Board_Driver.h
 *
 *  Created on: April 25, 2025
 *      Author: Jack Brozny
 */

#ifndef INC_BOARD_DRIVER_H_
#define INC_BOARD_DRIVER_H_

#include "Screen_Driver.h"
typedef enum{
    EMPTY,
    RED,
    BLUE
} GamePiece_t;


#define ROWS 6
#define COLUMNS 7

#define BOARD_COLUMN_1 0
#define BOARD_COLUMN_2 1
#define BOARD_COLUMN_3 2
#define BOARD_COLUMN_4 3
#define BOARD_COLUMN_5 4
#define BOARD_COLUMN_6 5
#define BOARD_COLUMN_7 6

#define BOARD_ROW_1 0
#define BOARD_ROW_2 1
#define BOARD_ROW_3 2
#define BOARD_ROW_4 3
#define BOARD_ROW_5 4
#define BOARD_ROW_6 5


void Board_SetHoveringPiece();
void Board_DropPiece();
void Board_CheckForWin();
void Board_PlayPolling();

#endif /* INC_GAME_DRIVER_H_ */