/*
 * AI_Driver.h
 *
 *  Created on: April 28, 2025
 *      Author: Jack Brozny
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