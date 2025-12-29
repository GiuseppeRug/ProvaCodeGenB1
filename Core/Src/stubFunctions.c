#include "stubFunctions.h"

// Da levareeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
#include "deserialize.h"
#include "print.h"
#include "Board1.h"

extern UART_HandleTypeDef hlpuart1; 	// UART per comunicazione tra schede

extern UART_HandleTypeDef huart2; 		// UART per Putty

extern DW_Board1_T Board1_DW;			//Riferimento alla board

void B1checkPrintReceive();
void B1checkPrintTransmit();

/* Implementazioni stub */
//ritorna GPIO_PIN_RESET oppure GPIO_PIN_SET. Rispettivamente 0 o 1.
uint8_t CheckRTR(void) {
	return HAL_GPIO_ReadPin(RTR_IN_GPIO_Port, RTR_IN_Pin);
}

void UartTransmitIT(uint8_t *pData, size_t size) {
	printMsg("B1 Transmitted\n\r\r\n");
	HAL_UART_Transmit(&hlpuart1, pData, size, HAL_MAX_DELAY);
	//B1checkPrintTransmit(pData);
}

void UartReceiveIT(uint8_t *pData, size_t size) {
	Board1_DW.received = 0; 						//pulisco il falg
	printMsg("B1 Wait receive\n\r");

	if (HAL_UART_Receive_IT(&hlpuart1, pData, size) != HAL_OK) {
		printMsg("B1 RECEVE_INIT_ERR\n\r");
	} else {
		HAL_GPIO_WritePin(RTR_OUT_GPIO_Port, RTR_OUT_Pin, GPIO_PIN_SET); // Notifico la disponibilità a ricevere
	}
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == LPUART1) {
		printMsg("B1 Received\n\r");
		if (Board1_DW.received == 0) {
			Board1_DW.received = 1;
			HAL_GPIO_WritePin(RTR_OUT_GPIO_Port, RTR_OUT_Pin, GPIO_PIN_RESET);
			//B1checkPrintReceive();
		}
	}
}

void B1checkPrintReceive() {
	static uint8_t cont = 0;
	switch (cont) {
	case 0:
		BUS_LocalStateB2 tmpLS;
		deserializeLocalStateB2(&Board1_DW.rx_buffer[0],
				sizeof(BUS_LocalStateB2), &tmpLS);
		printMsg("RECEIVED\r\n");
		printLocalStateB2(&tmpLS);
		break;
	case 1:
		BUS_GlobalState tmpGS;
		deserializeGlobalState(&Board1_DW.rx_buffer[0], sizeof(BUS_GlobalState),
				&tmpGS);
		printMsg("RECEIVED\r\n");
		printGlobalState(&tmpGS);
		break;
	case 2:
		BUS_Decision tmpD;
		deserializeDecision(&Board1_DW.rx_buffer[0], sizeof(BUS_Decision),
				&tmpD);
		printMsg("RECEIVED\r\n");
		printDecision(&tmpD);
		break;
	default:
		break;
	}
	cont = (cont + 1) % 3;
}

void B1checkPrintTransmit() {
	static uint8_t cont = 0;
	switch (cont) {
	case 0:
		BUS_LocalStateB1 tmpLS;
		deserializeLocalStateB1(&Board1_DW.tx_buffer[0],
				sizeof(BUS_LocalStateB1), &tmpLS);
		printMsg("TRANSMITTED\r\n");
		printLocalStateB1(&tmpLS);
		break;
	case 1:
		BUS_GlobalState tmpGS;
		deserializeGlobalState(&Board1_DW.tx_buffer[0], sizeof(BUS_GlobalState),
				&tmpGS);
		printMsg("TRANSMITTED\r\n");
		printGlobalState(&tmpGS);
		break;
	case 2:
		BUS_Decision tmpD;
		deserializeDecision(&Board1_DW.tx_buffer[0], sizeof(BUS_Decision),
				&tmpD);
		printMsg("TRANSMITTED\r\n");
		printDecision(&tmpD);
		break;
	default:
		break;
	}
	cont = (cont + 1) % 3;
}

