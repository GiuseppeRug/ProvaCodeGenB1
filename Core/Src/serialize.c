#include "serialize.h"

#include <string.h> /* memcpy */

size_t serializeLocalStateB1(uint8_t *buf, const BUS_LocalStateB1 *state) {
    size_t i = 0;

    memcpy(&buf[i], &state->speed, sizeof(BUS_Speed));
    i += sizeof(BUS_Speed);

    memcpy(&buf[i], &state->temperature, sizeof(Temperature));
    i += sizeof(Temperature);

    memcpy(&buf[i], &state->batteryLevel, sizeof(BatteryLevel));
    i += sizeof(BatteryLevel);

    return i; /* Idealmente = LOCALSTATEB1_FRAME_SIZE */
}

size_t serializeLocalStateB2(uint8_t *buf, const BUS_LocalStateB2 *state) {
    size_t i = 0;

    memcpy(&buf[i], &state->sonar, sizeof(BUS_Sonar));
    i += sizeof(BUS_Sonar);

    memcpy(&buf[i], &state->gyroscope, sizeof(Gyroscope));
    i += sizeof(Gyroscope);

    memcpy(&buf[i], &state->remoteController, sizeof(BUS_RemoteController));
    i += sizeof(BUS_RemoteController);

    return i; /* Idealmente = LOCALSTATEB2_FRAME_SIZE */
}

size_t serializeGlobalState(uint8_t *buf, const BUS_GlobalState *state) {
    size_t i = 0;

    i += serializeLocalStateB1(&buf[i], &state->localStateB1);
    i += serializeLocalStateB2(&buf[i], &state->localStateB2);

    return i; /* Idealmente = GLOBALSTATE_FRAME_SIZE */
}

size_t serializeDecision(uint8_t *buf, const BUS_Decision *state) {
    size_t i = 0;

    memcpy(&buf[i], &state->actuator, sizeof(ENUM_Actuator));
    i += sizeof(ENUM_Actuator);

    memcpy(&buf[i], &state->roverAction, sizeof(ENUM_RoverAction));
    i += sizeof(ENUM_RoverAction);

    memcpy(&buf[i], &state->safeAction, sizeof(ENUM_SafeAction));
    i += sizeof(ENUM_SafeAction);

    return i; /* Idealmente = DECISION_FRAME_SIZE */
}
