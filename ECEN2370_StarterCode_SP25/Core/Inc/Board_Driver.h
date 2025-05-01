/*
 * Board_Driver.h
 *
 *  Created on: April 25, 2025
 *      Author: Jack Brozny
 */

#ifndef INC_BOARD_DRIVER_H_
#define INC_BOARD_DRIVER_H_

#include "Screen_Driver.h"
#include "AI_Driver.h"

/**
 * @brief State of a board slot.
 * 
 */
typedef enum{
    EMPTY, /**< Empty slot. */
    RED,    /**< Red piece in slot. */
    BLUE    /**< Blue piece in slot. */
} GamePiece_t;

/**
 * @name Board dimensions
 * @brief Number of rows an columns for initializing board array.
 * @{
 */
#define ROWS 6
#define COLUMNS 7
/**@} */

/**
 * @defgroup BoardCoords board array constants
 * @brief Board array positions
 * 
 */

 /**
  * @name Board columns
  * @ingroup BoardCoords
  * 
  * @{
  */
#define BOARD_COLUMN_1 0
#define BOARD_COLUMN_2 1
#define BOARD_COLUMN_3 2
#define BOARD_COLUMN_4 3
#define BOARD_COLUMN_5 4
#define BOARD_COLUMN_6 5
#define BOARD_COLUMN_7 6
/**@} */

 /**
  * @name Board rows
  * @ingroup BoardCoords
  * 
  * @{
  */
#define BOARD_ROW_1 0
#define BOARD_ROW_2 1
#define BOARD_ROW_3 2
#define BOARD_ROW_4 3
#define BOARD_ROW_5 4
#define BOARD_ROW_6 5
/**@} */

void Board_Reset();
bool Board_GetisStillPlaying();
bool Board_GetisPlayerBlue();
uint8_t Board_GetredWins();
uint8_t Board_GetblueWins();
void Board_SetHoveringPiece();
void Board_ShiftHoveringPieceRight();
void Board_ShiftHoveringPieceLeft();
void Board_DropPiece();
void Board_PlayAIMove();
bool Board_CheckForWin(uint8_t placedRow, uint8_t placedCol);
bool Board_CheckForTie();
uint8_t Board_CheckEndCondition();
void Board_PlayPolling();

#endif /* INC_GAME_DRIVER_H_ */