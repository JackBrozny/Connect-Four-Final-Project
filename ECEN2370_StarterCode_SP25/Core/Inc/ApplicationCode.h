/**
  ******************************************************************************
  * @file    ApplicationCode.h
  * @author  Jack Brozny
  * @brief   Header file for ApplicationCode.c.
  ******************************************************************************
  * 
  * This file is used to abstract lower level functions for a simpler main.
  * 
  ******************************************************************************
  */ 




#ifndef INC_APPLICATIONCODE_H_
#define INC_APPLICATIONCODE_H_

#include "stm32f4xx_hal.h"
#include "Board_Driver.h"
#include <stdio.h>

/**
 * @brief Initializes LCD screen and touch functionality
 * 
 */
void ApplicationInit(void);

/**
 * @brief Resets game board data
 * 
 */
void resetBoard();

/**
 * @brief Opens startup screen
 * 
 * This fucntion opens the startup screen and enters a polling loop
 * to wait for the player to choose 1 or 2 player mode.
 * 
 */
void LCD_StartUp(void);

/**
 * @brief Enters main gameplay loop
 * 
 * 
 */
void startGamePolling();

/**
 * @brief Displays end screen
 * 
 */
void displayEndScreen();

/**
 * @brief Enters infinite loop when error occurs
 * 
 */
extern void Error_Handler(void);

#if (COMPILE_TOUCH_FUNCTIONS == 1)
/**
 * @brief Demo to show touchscreen functionality
 * 
 */
void LCD_Touch_Polling_Demo(void);
#endif // (COMPILE_TOUCH_FUNCTIONS == 1)

#endif /* INC_APPLICATIONCODE_H_ */
