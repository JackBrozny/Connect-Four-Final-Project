/**
  ******************************************************************************
  * @file    Board_Driver.h
  * @author  Jack Brozny
  * @brief   Header file for handling board and game data.
  ******************************************************************************
  * 
  * This file handles the actual game logic and board data. Uses functions from
  * the Screen Driver to control visuals.
  ******************************************************************************
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

/**
 * @brief Reset board data
 * 
 */
void Board_Reset();

/**
 * @brief isStillPlaying getter function
 * 
 * @return true Game is still going
 * @return false Game has ended
 */
bool Board_GetisStillPlaying();

/**
 * @brief isPlayerBlue getter function
 * 
 * @return true Blue player's turn
 * @return false Red player's turn
 */
bool Board_GetisPlayerBlue();

/**
 * @brief redWins getter function
 * 
 * @return uint8_t Number of red wins
 */
uint8_t Board_GetredWins();

/**
 * @brief blueWins getter function
 * 
 * @return uint8_t Number of blue wins
 */
uint8_t Board_GetblueWins();

/**
 * @defgroup PieceMovement Piece movement functions
 * @brief Piece movement functions
 * 
 * @{
 */
 
/**
 * @brief Sets hovering piece at center column
 * 
 * This function sets the position of the hovering piece to the middle column
 * and displays a red or blue piece on the LCD screen depending on which player's
 * turn it is.
 * 
 */
void Board_SetHoveringPiece();

/**
 * @brief Moves hovering piece one column to the right
 * 
 * This function changes the stored data of the hovering piece to one column to the
 * right. If the piece is on the furthest right column, it does nothing.
 * 
 */
void Board_ShiftHoveringPieceRight();

/**
 * @brief Moves hovering piece one column to the left
 * 
 * This function changes the stored data of the hovering piece to one column to the
 * Left. If the piece is on the furthest Left column, it does nothing.
 * 
 */
void Board_ShiftHoveringPieceLeft();

/**
 * @brief Drops the piece into column it's hovering over
 * 
 * This function iterates down each row until it reaches a filled slot and then places
 * the piece on the row above it. It checks for a win or a tie, makes it the other player's
 * turn, and resets the hovering piece.
 * 
 */
void Board_DropPiece();
/**@} */

/**
 * @brief Plays a random move in 1 player mode
 * 
 * this function gets a random column, moves the hovering piece to that position, and
 * then drops the piece. This only gets called from the user button interrupt.
 * 
 */
void Board_PlayAIMove();

/**
 * @defgroup EndCheck End condition functions
 * @brief End condition functions
 * 
 * @{
 */

/**
 * @brief Checks for a 4-in-a-row
 * 
 * This function checks for a 4-in-a-row in every possible direction. This is called
 * every time a piece is dropped
 * 
 * @param placedRow Placed piece row
 * @param placedCol Placed piece column
 * @return true There is a 4-in-a-row
 * @return false There is not a 4-in-a-row
 */
bool Board_CheckForWin(uint8_t placedRow, uint8_t placedCol);

/**
 * @brief Checks for a tie
 * 
 * This function checks for a tie by checking if only the top row is filled, since that
 * the only way that could happen is if the rest of the board is filled without any 
 * 4-in-a-rows.
 * 
 * @return true There is a tie
 * @return false There is not a tie
 */
bool Board_CheckForTie();

/**
 * @brief Checks for win or tie
 * 
 * This function calls the win and tie checker functions and returns a value depending
 * on which, if any, are true.
 * 
 * @return uint8_t End result
 */
uint8_t Board_CheckEndCondition();
/**@} */

/**
 * @brief Gameplay polling loop
 * 
 * This function enters a polling loop that occurs for the entire game. It checks for
 * touch screen input to move the hovering piece right or left and only breaks when the
 * isStillPlaying flag is changed to signify the game has ended.
 * 
 */
void Board_PlayPolling();

#endif /* INC_GAME_DRIVER_H_ */