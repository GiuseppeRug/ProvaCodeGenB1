#include "stubFunctions.h"

// Da levareeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee
#include "Board1_types.h"
#include "deserialize.h"
#include "print.h"
/* Implementazioni stub (funzioni vuote) */

uint8_t CheckRTR(void)
{
	static uint8_t prova = 0;
	if (prova == 0){
		prova = 1;
		return 1;
	}
    return 0;
}

void UartTransmitIT(uint8_t *pData, size_t size)
{
    /* Stub */
	BUS_LocalStateB1 tmp;
	deserializeLocalStateB1(pData, size, &tmp);
    printLocalStateB1(&tmp);
}

void UartReceiveIT(uint8_t *pData, size_t size)
{
    /* Stub */
    (void)pData;
    (void)size;
}
