#ifndef INC_DESERIALIZE_H_
#define INC_DESERIALIZE_H_

#include <stddef.h>
#include <stdint.h>

#include "UART_frames.h"


/* Prototipi */
int deserializeLocalStateB1(const uint8_t *buf, size_t len, BUS_LocalStateB1 *state);
int deserializeLocalStateB2(const uint8_t *buf, size_t len, BUS_LocalStateB2 *state);
int deserializeGlobalState(const uint8_t *buf, size_t len, BUS_GlobalState *state);
int deserializeDecision(const uint8_t *buf, size_t len, BUS_Decision *state);

#endif /* INC_DESERIALIZE_H_ */
