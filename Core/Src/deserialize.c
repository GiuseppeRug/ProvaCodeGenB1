#include "deserialize.h"

#include <string.h> /* memcpy */

int deserializeLocalStateB1(const uint8_t *buf, size_t len, BUS_LocalStateB1 *state) {
    if (len < LOCALSTATEB1_FRAME_SIZE)
        return -1;

    size_t i = 0;

    memcpy(&state->speed, &buf[i], sizeof(BUS_Speed));
    i += sizeof(BUS_Speed);

    memcpy(&state->temperature, &buf[i], sizeof(Temperature));
    i += sizeof(Temperature);

    memcpy(&state->batteryLevel, &buf[i], sizeof(BatteryLevel));
    i += sizeof(BatteryLevel);

    return 0;
}

int deserializeLocalStateB2(const uint8_t *buf, size_t len, BUS_LocalStateB2 *state) {
    if (len < LOCALSTATEB2_FRAME_SIZE)
        return -1;

    size_t i = 0;

    memcpy(&state->sonar, &buf[i], sizeof(BUS_Sonar));
    i += sizeof(BUS_Sonar);

    memcpy(&state->gyroscope, &buf[i], sizeof(Gyroscope));
    i += sizeof(Gyroscope);

    memcpy(&state->remoteController, &buf[i], sizeof(BUS_RemoteController));
    i += sizeof(BUS_RemoteController);

    return 0;
}

int deserializeGlobalState(const uint8_t *buf, size_t len, BUS_GlobalState *state) {
    if (len < GLOBALSTATE_FRAME_SIZE)
        return -1;

    size_t i = 0;

    if (deserializeLocalStateB1(&buf[i], LOCALSTATEB1_FRAME_SIZE, &state->localStateB1) != 0)
        return -1;
    i += LOCALSTATEB1_FRAME_SIZE;

    if (deserializeLocalStateB2(&buf[i], LOCALSTATEB2_FRAME_SIZE, &state->localStateB2) != 0)
        return -1;

    return 0;
}

int deserializeDecision(const uint8_t *buf, size_t len, BUS_Decision *state) {
    if (len < DECISION_FRAME_SIZE)
        return -1;

    size_t i = 0;

    memcpy(&state->actuator, &buf[i], sizeof(ENUM_Actuator));
    i += sizeof(ENUM_Actuator);

    memcpy(&state->roverAction, &buf[i], sizeof(ENUM_RoverAction));
    i += sizeof(ENUM_RoverAction);

    /* FIX: prima mancava safeAction */
    memcpy(&state->safeAction, &buf[i], sizeof(ENUM_SafeAction));
    i += sizeof(ENUM_SafeAction);

    return 0;
}
