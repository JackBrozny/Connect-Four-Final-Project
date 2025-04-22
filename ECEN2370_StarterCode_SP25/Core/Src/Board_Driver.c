/*
 * Board_Driver.h
 *
 *  Created on: April 25, 2025
 *      Author: Jack Brozny
 */

// ASK*******************************
/* 
Should I have a global array defined here? Or is it better to define the array in main and have the functions
in this file pass that array as an argument?  
*/

// STMP811 INTERRUPT PORT: GPIOA PIN: 15

#include "Board_Driver.h"

typedef enum{
    EMPTY,
    RED,
    BLUE
} GamePiece_t;

#define ROWS 6
#define COLUMNS 7

GamePiece_t Board[ROWS][COLUMNS];
