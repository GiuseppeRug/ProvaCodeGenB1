#ifndef INC_SERIALIZE_H_
#define INC_SERIALIZE_H_

#include <stddef.h>
#include <stdint.h>

#include "Board1_types.h"

/* Prototipi */
size_t serializeLocalStateB1(uint8_t *buf, const BUS_LocalStateB1 *state);
size_t serializeLocalStateB2(uint8_t *buf, const BUS_LocalStateB2 *state);
size_t serializeGlobalState(uint8_t *buf, const BUS_GlobalState *state);
size_t serializeDecision(uint8_t *buf, const BUS_Decision *state);

#endif /* INC_SERIALIZE_H_ */
