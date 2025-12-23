#ifndef INC_STUBFUNCTIONS_H_
#define INC_STUBFUNCTIONS_H_

#include <stdint.h>
#include <stddef.h>

/* Prototipi delle funzioni stub */

uint8_t CheckRTR(void);

void UartTransmitIT(uint8_t *pData, size_t size);

void UartReceiveIT(uint8_t *pData, size_t size);

#endif /* INC_STUBFUNCTIONS_H_ */
