#ifndef INC_PRINT_H_
#define INC_PRINT_H_

#include <stdio.h>
#include <string.h>

#include "UART_frames.h"

#include "usart.h"
extern UART_HandleTypeDef huart2;

/* Funzioni di stampa UART */
void uartPrint(const char *msg);
void printMsg(const char *pData);

/* Stampa degli stati */
void printLocalStateB1(const BUS_LocalStateB1 *s);
void printLocalStateB2(const BUS_LocalStateB2 *s);
void printGlobalState(const BUS_GlobalState *g);

/* Stampa decisione */
void printDecision(const BUS_Decision *d);

/* Debug dimensioni frame */
void UART_PrintFrameSizes(void);

#endif /* INC_PRINT_H_ */
