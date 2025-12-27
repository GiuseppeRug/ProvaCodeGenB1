#include <Board_types.h>
#include "stubFunctions.h"

// Da levareeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
#include "deserialize.h"
#include "print.h"
#include "Board1.h"

extern UART_HandleTypeDef hlpuart1; 	// UART per comunicazione tra schede

extern UART_HandleTypeDef huart2; 		// UART per Putty

extern DW_Board1_T Board1_DW;			//Riferimento alla board

void B1checkPrintReceive();
//void B1checkPrintTransmit();
void B1checkPrintTransmit(uint8_t* pData);


/* Implementazioni stub (funzioni vuote) */
//uint8_t CheckRTR(void) {
//	static uint8_t prova = 0;
//	if (prova == 0) {
//		prova = 1;
//		return 1;
//	}
//	return 0;
//}
//
//void UartTransmitIT(uint8_t *pData, size_t size) {
//	/* Stub */
//	BUS_LocalStateB1 tmp;
//	deserializeLocalStateB1(pData, size, &tmp);
//	printLocalStateB1(&tmp);
//}
//
//void UartReceiveIT(uint8_t *pData, size_t size) {
//
//}
/* Implementazioni stub */
//ritorna GPIO_PIN_RESET oppure GPIO_PIN_SET. Rispettivamente 0 o 1.
uint8_t CheckRTR(void)
{
	return HAL_GPIO_ReadPin(RTR_IN_GPIO_Port, RTR_IN_Pin);
}

char msgT[] = { "B1 Transmitted\n\r" };
void UartTransmitIT(uint8_t *pData, size_t size) {
	HAL_UART_Transmit(&huart2, (uint8_t*)msgT, sizeof(msgT), HAL_MAX_DELAY);
	HAL_UART_Transmit(&hlpuart1, pData, size, HAL_MAX_DELAY);
	B1checkPrintTransmit(pData);

	//HAL_UART_Transmit_IT(&hlpuart1, pData, size);
}
char msgRR[] = { "B1 Wait receive\n\r" };
void UartReceiveIT(uint8_t *pData, size_t size) {
	Board1_DW.received = 0; 										//pulisco il falg
	HAL_UART_Transmit(&huart2, (uint8_t*)msgRR, sizeof(msgRR), HAL_MAX_DELAY);

	HAL_UART_Receive_IT(&hlpuart1, pData, size);
	HAL_GPIO_WritePin(RTR_OUT_GPIO_Port, RTR_OUT_Pin,GPIO_PIN_SET); // Notifico la disponibilità a ricevere


}

char msgR[] = { "B1 Received\n\r" };
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
	if (huart->Instance == hlpuart1.Instance) {
		HAL_UART_Transmit(&huart2, (uint8_t*)msgR, sizeof(msgR), HAL_MAX_DELAY);
		if (Board1_DW.received == 0) {
			Board1_DW.received = 1;
			HAL_GPIO_WritePin(RTR_OUT_GPIO_Port, RTR_OUT_Pin,GPIO_PIN_RESET);
			//B1checkPrintReceive();
		}
	}
}

void B1checkPrintReceive(){
	static uint8_t  cont = 0;
	switch (cont) {
		case 0:
			BUS_LocalStateB2 tmpLS;
			deserializeLocalStateB2(&Board1_DW.rx_buffer[0], sizeof(BUS_LocalStateB2), &tmpLS);
			printMsg("RECEIVED\r\n");
			printLocalStateB2(&tmpLS);
			break;
		case 1:
			BUS_GlobalState tmpGS;
			deserializeGlobalState(&Board1_DW.rx_buffer[0], sizeof(BUS_GlobalState), &tmpGS);
			printMsg("RECEIVED\r\n");
			printGlobalState(&tmpGS);
			break;
		case 2:
			BUS_Decision tmpD;
			deserializeDecision(&Board1_DW.rx_buffer[0], sizeof(BUS_Decision), &tmpD);
			printMsg("RECEIVED\r\n");
			printDecision(&tmpD);
			break;
		default:
			break;
	}
	cont = (cont + 1) % 3;
}

//void B1checkPrintTransmit(){
//	static uint8_t  cont = 0;
//	switch (cont) {
//		case 0:
//			BUS_LocalStateB1 tmpLS;
//			deserializeLocalStateB1(&Board1_DW.tx_buffer[0], sizeof(BUS_LocalStateB1), &tmpLS);
//			printMsg("TRANSMITTED\r\n");
//			printLocalStateB1(&tmpLS);
//			break;
//		case 1:
//			BUS_GlobalState tmpGS;
//			deserializeGlobalState(&Board1_DW.tx_buffer[0], sizeof(BUS_GlobalState), &tmpGS);
//			printMsg("TRANSMITTED\r\n");
//			printGlobalState(&tmpGS);
//			break;
//		case 2:
//			BUS_Decision tmpD;
//			deserializeDecision(&Board1_DW.tx_buffer[0], sizeof(BUS_Decision), &tmpD);
//			printMsg("TRANSMITTED\r\n");
//			printDecision(&tmpD);
//			break;
//		default:
//			break;
//	}
//	cont = (cont + 1) % 3;
//}

void B1checkPrintTransmit(uint8_t* pData ){
	static uint8_t  cont = 0;
	switch (cont) {
		case 0:
			BUS_LocalStateB1 tmpLS;
			deserializeLocalStateB1(pData, sizeof(BUS_LocalStateB1), &tmpLS);
			printMsg("TRANSMITTED\r\n");
			printLocalStateB1(&tmpLS);
			break;
		case 1:
			BUS_GlobalState tmpGS;
			deserializeGlobalState(pData, sizeof(BUS_GlobalState), &tmpGS);
			printMsg("TRANSMITTED\r\n");
			printGlobalState(&tmpGS);
			break;
		case 2:
			BUS_Decision tmpD;
			deserializeDecision(pData, sizeof(BUS_Decision), &tmpD);
			printMsg("TRANSMITTED\r\n");
			printDecision(&tmpD);
			break;
		default:
			break;
	}
	cont = (cont + 1) % 3;
}

