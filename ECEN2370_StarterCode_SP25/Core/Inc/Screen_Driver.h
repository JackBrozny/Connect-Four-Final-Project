/**
  ******************************************************************************
  * @file    Screen_Driver.h
  * @author  Jack Brozny
  * @brief   Header file for handling visuals of the LCD screen.
  ******************************************************************************
  * 
  * This header mostly controls visuals for the LCD screen like displaying screens, 
  * buttons, moving game pieces, and converting the pieces stored positions to pixel 
  * coordinates on the screen. Some non-visual data is recorded like the start and end 
  * ticks and the number of wins by each color.
  ******************************************************************************
  */ 

#ifndef INC_SCREEN_DRIVER_H_
#define INC_SCREEN_DRIVER_H_

#include "LCD_Driver.h"
#include <stdio.h>
#include <stdbool.h>

/**
 * @brief Defines the vertical and horizontal distance between each slot on the board
 *        in pixels on the LCD screen.
 * 
 */
#define SLOT_SPACE LCD_PIXEL_WIDTH/8

/**
 * @name End game conditions.
 * 
 * @{
 */
#define WIN 1
#define TIE 2
/**@} */

/**
 * @defgroup ScreenCoords Screen coordinate constants
 * @brief Pixel coordinates for rows and columns of the board on the LCD screen
 * 
 * These values define the X and Y positions for the columns and rows of the board.
 * The origin is at the top left of the screen, so Column 1 is the leftmost column,
 * and Row 1 is the top column 
 */

/**
 * @name X-coordinates of each column in pixels.
 * @ingroup ScreenCoords
 * 
 * @{
 */
#define SCREEN_COLUMN_1 SLOT_SPACE
#define SCREEN_COLUMN_2 SLOT_SPACE*2
#define SCREEN_COLUMN_3 SLOT_SPACE*3
#define SCREEN_COLUMN_4 SLOT_SPACE*4
#define SCREEN_COLUMN_5 SLOT_SPACE*5
#define SCREEN_COLUMN_6 SLOT_SPACE*6
#define SCREEN_COLUMN_7 SLOT_SPACE*7
/**@} */

/**
 * @name Y-coordinates of each row in pixels.
 * @ingroup ScreenCoords
 * 
 * @{
 */
#define SCREEN_ROW_1 SLOT_SPACE*5
#define SCREEN_ROW_2 SLOT_SPACE*6
#define SCREEN_ROW_3 SLOT_SPACE*7
#define SCREEN_ROW_4 SLOT_SPACE*8
#define SCREEN_ROW_5 SLOT_SPACE*9
#define SCREEN_ROW_6 SLOT_SPACE*10
/**@} */

/**
 * @brief Displays game title and mode selection options. 
 * 
 * This function displays the startup screen with buttons for 1 player and
 * 2 player modes. It then enters a polling loop until one of the options
 * is selected
 */
void Screen_OpenStartupScreen();

/**
 * @brief Displays an empty board where each slot is black and records the start tick.
 * 
 */
void Screen_OpenPlayScreen();

/**
 * @brief Displays the winner and end results.
 * 
 * This function displays the winning color and waits 3 seconds to let the players
 * see the final game board. It incrementsggghghhghghhghgghg It then changes the screen to show the win counts for
 * each color, shows the time played for that round in seconds, displays a play 
 * again button, and enters a polling loop until the button is pressed.
 * 
 * @param isPlayerBlue Determines which player's turn.
 * @param result Win or tie.
 */
void Screen_OpenEndScreen(bool isPlayerBlue, uint8_t result);

/**
 * @brief Displays play again button.
 * 
 * This function displays the button on the LCD screen, as well as entering a polling loop
 * to wait until the player presses it.
 */
void Screen_DisplayPlayAgainButton();

/**
 * @brief Displays piece to be dropped.
 * 
 * This visually clears wherever the hovering piece used to be and displays a new piece
 * at the center column.
 * 
 * @param isPlayerBlue Determines whether piece is blue or red.
 */
void Screen_DisplayHoveringPiece(bool isPlayerBlue);

/**
 * @name Hovering piece movement
 * @brief Moves hovering piece one column to the right or left.
 * 
 * These functions clears the old piece on the LCD screen and displays a new piece
 * one column to the right or left. They only change the visual data of the piece.
 * 
 * @param isPlayerBlue Determines if piece is blue or red.
 * @{
 */
void Screen_MoveHoveringPieceRight(bool isPlayerBlue);
void Screen_MoveHoveringPieceLeft(bool isPlayerBlue);
/**@} */

/**
 * @brief Displays a game piece on the screen.
 * 
 * This function is used to display a piece at the given coordinates.
 * 
 * @param Xpos X-coordinate of the piece.
 * @param Ypos Y-coordinate of the piece.
 * @param isPlayerBlue Determines if piece is blue or red.
 */
void Screen_DrawPiece(uint16_t Xpos, uint16_t Ypos, bool isPlayerBlue);

/**
 * @name Coordinate conversion
 * @brief Converts a position on the board to pixel coordinates.
 * 
 * The positions of pieces in rows and columns are stored as 0-5 and 0-6
 * in an array. These functions convert those positions to pixel coordinates
 * that the LCD screen can use to display pieces.
 * 
 * @param position Row or column.
 * @return uint16_t Value in pixels.
 * 
 * @{
 */
uint16_t Screen_RowToCoords(uint8_t position);
uint16_t Screen_ColumnToCoords(uint8_t position);
/**@} */

/**
 * @name isOnePlayer modification
 * @brief Getter and setter functions for isOnePlayer.
 * 
 * @return true In one player mode.
 * @return false In two player mode.
 * @{
 */
bool Screen_GetisOnePlayer();
void Screen_SetisOnePlayer(bool newVal);
/**@} */

/**
 * @brief Getter function for LCD touch data.
 * 
 * @return STMPE811_TouchData* LCD screen touch data.
 */
STMPE811_TouchData* Screen_GetPTouchData();

#endif 