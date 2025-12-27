#include "print.h"

/* -------------------------------------------------- */
/* Funzioni di base                                   */
/* -------------------------------------------------- */

void uartPrint(const char *msg) {
	HAL_UART_Transmit(&huart2, (uint8_t*) msg, strlen(msg), HAL_MAX_DELAY);
}

void printMsg(const char *pData) {
	HAL_UART_Transmit(&huart2, (uint8_t*) pData, strlen(pData),
	HAL_MAX_DELAY);
}

void clearScreen(){
	  printMsg(CLRSCR);
}

/* -------------------------------------------------- */
/* Stampa stati locali                                */
/* -------------------------------------------------- */

void printLocalStateB1(const BUS_LocalStateB1 *s) {
	char msg[128];

	snprintf(msg, sizeof(msg), "LocalStateB1\r\n");
	uartPrint(msg);

	snprintf(msg, sizeof(msg), "  Speed: %.2f %.2f %.2f %.2f\r\n",
			s->speed.motor1, s->speed.motor2, s->speed.motor3, s->speed.motor4);
	uartPrint(msg);

	snprintf(msg, sizeof(msg), "  Temperature: %.2f C\r\n", s->temperature);
	uartPrint(msg);

	snprintf(msg, sizeof(msg), "  Battery: %.2f %%\r\n", s->batteryLevel);
	uartPrint(msg);
}

void printLocalStateB2(const BUS_LocalStateB2 *s) {
	char msg[192];

	snprintf(msg, sizeof(msg), "LocalStateB2\r\n");
	uartPrint(msg);

	snprintf(msg, sizeof(msg), "  Sonar: L=%d F=%d R=%d\r\n", s->sonar.left,
			s->sonar.front, s->sonar.right);
	uartPrint(msg);

	snprintf(msg, sizeof(msg), "  Gyroscope: %.2f\r\n", s->gyroscope);
	uartPrint(msg);

	snprintf(msg, sizeof(msg),
			"  RemoteController: x_lever=%d y_lever=%d buttons=%d\r\n",
			s->remoteController.x_lever, s->remoteController.y_lever,
			s->remoteController.buttons);
	uartPrint(msg);
}

/* -------------------------------------------------- */
/* Stato globale                                      */
/* -------------------------------------------------- */

void printGlobalState(const BUS_GlobalState *g) {
	char msg[64];

	snprintf(msg, sizeof(msg), "GlobalState\r\n");
	uartPrint(msg);

	printLocalStateB1(&g->localStateB1);
	printLocalStateB2(&g->localStateB2);
}

/* -------------------------------------------------- */
/* Decisione                                          */
/* -------------------------------------------------- */

void printDecision(const BUS_Decision *d) {
	char msg[128];

	snprintf(msg, sizeof(msg), "Decision\r\n");
	uartPrint(msg);

	snprintf(msg, sizeof(msg), "  actuator=%d\r\n", (int) d->actuator);
	uartPrint(msg);

	snprintf(msg, sizeof(msg), "  roverAction=%d\r\n", (int) d->roverAction);
	uartPrint(msg);

	snprintf(msg, sizeof(msg), "  safeAction=%d\r\n", (int) d->safeAction);
	uartPrint(msg);
}

/* -------------------------------------------------- */
/* Debug frame sizes                                  */
/* -------------------------------------------------- */

void UART_PrintFrameSizes(void) {
	char buf[64];
	int len;

#define PRINT_SIZE(name, value)                                  \
    do {                                                         \
        len = snprintf(buf, sizeof(buf),                         \
                       "%-30s : %lu\r\n",                        \
                       name, (unsigned long)(value));            \
        HAL_UART_Transmit(&huart2,                               \
                          (uint8_t *)buf,                        \
                          len,                                   \
                          HAL_MAX_DELAY);                        \
    } while (0)

	/* --- Sensori --- */
	PRINT_SIZE("SPEED_FRAME_SIZE", SPEED_FRAME_SIZE);
	PRINT_SIZE("TEMPERATURE_FRAME_SIZE", TEMPERATURE_FRAME_SIZE);
	PRINT_SIZE("BATTERYLEVEL_FRAME_SIZE", BATTERYLEVEL_FRAME_SIZE);
	PRINT_SIZE("SONAR_FRAME_SIZE", SONAR_FRAME_SIZE);
	PRINT_SIZE("GYROSCOPE_FRAME_SIZE", GYROSCOPE_FRAME_SIZE);
	PRINT_SIZE("REMOTECONTROLLER_FRAME_SIZE", REMOTECONTROLLER_FRAME_SIZE);

	/* --- Stati --- */
	PRINT_SIZE("LOCALSTATEB1_FRAME_SIZE", LOCALSTATEB1_FRAME_SIZE);
	PRINT_SIZE("LOCALSTATEB2_FRAME_SIZE", LOCALSTATEB2_FRAME_SIZE);
	PRINT_SIZE("GLOBALSTATE_FRAME_SIZE", GLOBALSTATE_FRAME_SIZE);

	/* --- Decisione / Controllo --- */
	PRINT_SIZE("SETPOINT_FRAME_SIZE", SETPOINT_FRAME_SIZE);
	PRINT_SIZE("DECISION_FRAME_SIZE", DECISION_FRAME_SIZE);

#undef PRINT_SIZE
}
