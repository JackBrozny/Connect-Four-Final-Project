/**
  ******************************************************************************
  * @file    AI_Driver.h
  * @author  Jack Brozny
  * @brief   Header file for AI_Driver.c.
  ******************************************************************************
  */ 

#ifndef INC_AI_DRIVER_H_
#define INC_AI_DRIVER_H_

#include "stm32f4xx_hal.h"

 /**
  * @brief RNG Initialization Function
  * @param None
  * @retval None
  */
void MX_RNG_Init(void);

/**
 * @brief Returns a random 32 bit integer from the RNG peripheral.
 * 
 */
uint32_t AI_GenerateColumn();


#endif