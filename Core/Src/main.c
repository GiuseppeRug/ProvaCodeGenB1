/* USER CODE BEGIN Header */
/* PROVA COD GEN B1 */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "Board1.h"
#include "sensors.h"
#include "decision.h"
#include "print.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define Board1_IN_Execution            ((uint8_T)3U)
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* Block states (default storage) */
extern DW_Board1_T Board1_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Board1_T Board1_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Board1_T Board1_Y;

extern B_Board1_T Board1_B;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_LPUART1_UART_Init();
  MX_USART2_UART_Init();
  /* USER CODE BEGIN 2 */
  clearScreen();
  printMsg("PROVA COD GEN B1\r\n");

  uint8_t flagStampa = 1;

  // Coming from Sensors
  Board1_U.speed = (BUS_Speed) {32.3f, 32.3f, 32.3f, 32.3f};
  Board1_U.temperature = (Temperature) 32.3f;
  Board1_U.batteryLevel = (BatteryLevel) 32.3f;

  // Coming from ModelAction
  Board1_Y.roverAction = RA_IDLE;
  Board1_Y.safeAction = RA_IDLE;
  Board1_Y.setPoint = (BUS_SetPoint) {32.3f, 32.3f};

  // Continua
  Board1_U.continua = 0;

  // Receive che dovrebbe essere gestito dalla receive it
  Board1_DW.received = 0;

  Board1_initialize();
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

		Board1_step();

		if (flagStampa == 1) {
			if (Board1_DW.is_ExchangeDecision == Board1_IN_Execution) {
				printGlobalState(&Board1_B.board1GlobalState);
				printDecision(&Board1_DW.board1Decision);
				flagStampa = 0;
			}
		}
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == LPUART1) {

		uint32_t err = huart->ErrorCode;

		printMsg("UART ERROR: ");

		if (err & HAL_UART_ERROR_ORE) {
			printMsg("ORE ");
		}
		if (err & HAL_UART_ERROR_FE) {
			printMsg("FE ");
		}
		if (err & HAL_UART_ERROR_NE) {
			printMsg("NE ");
		}
		if (err & HAL_UART_ERROR_PE) {
			printMsg("PE ");
		}

		printMsg("\r\n");

		// --- recovery minimo indispensabile ---
		__HAL_UART_CLEAR_OREFLAG(huart);
		__HAL_UART_CLEAR_FEFLAG(huart);
		__HAL_UART_CLEAR_NEFLAG(huart);
		__HAL_UART_CLEAR_PEFLAG(huart);

		HAL_UART_AbortReceive_IT(huart);

	}
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
