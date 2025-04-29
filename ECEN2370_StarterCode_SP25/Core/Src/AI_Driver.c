/*
 * AI_Driver.c
 *
 *  Created on: April 28, 2025
 *      Author: Jack Brozny
 */

#include "AI_Driver.h"
#include <stdint.h>

 RNG_HandleTypeDef hrng;

 /**
  * @brief RNG Initialization Function
  * @param None
  * @retval None
  */
void MX_RNG_Init(void)
{

  /* USER CODE BEGIN RNG_Init 0 */

  /* USER CODE END RNG_Init 0 */

  /* USER CODE BEGIN RNG_Init 1 */

  /* USER CODE END RNG_Init 1 */
  hrng.Instance = RNG;
  if (HAL_RNG_Init(&hrng) != HAL_OK)
  {
    while (1) {}
  }
  /* USER CODE BEGIN RNG_Init 2 */

  /* USER CODE END RNG_Init 2 */

}

uint32_t AI_GenerateColumn(){
    uint32_t col;

    HAL_RNG_GenerateRandomNumber(&hrng, &col);
    return col % 8; // Returns a number 0-7
}