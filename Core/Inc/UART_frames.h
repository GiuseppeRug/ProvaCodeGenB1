#ifndef INC_UART_FRAMES_H_
#define INC_UART_FRAMES_H_

#include "Board1_types.h"

/* --- Dimensioni dei tipi base dei sensori --- */

#define SPEED_FRAME_SIZE            (sizeof(BUS_Speed))

#define TEMPERATURE_FRAME_SIZE      (sizeof(Temperature))

#define BATTERYLEVEL_FRAME_SIZE     (sizeof(BatteryLevel))

#define SONAR_FRAME_SIZE            (sizeof(BUS_Sonar))

#define GYROSCOPE_FRAME_SIZE        (sizeof(Gyroscope))

#define REMOTECONTROLLER_FRAME_SIZE (sizeof(BUS_RemoteController))

/* --- Stati --- */

/* LocalStateB1 = Speed + Temperature + BatteryLevel */
#define LOCALSTATEB1_FRAME_SIZE	( SPEED_FRAME_SIZE + TEMPERATURE_FRAME_SIZE +\
								BATTERYLEVEL_FRAME_SIZE )

/* LocalStateB2 = Sonar + Gyroscope + RemoteController */
#define LOCALSTATEB2_FRAME_SIZE ( SONAR_FRAME_SIZE + GYROSCOPE_FRAME_SIZE + \
								REMOTECONTROLLER_FRAME_SIZE )

/* GlobalState = LocalStateB1 + LocalStateB2 */
#define GLOBALSTATE_FRAME_SIZE ( LOCALSTATEB1_FRAME_SIZE + LOCALSTATEB2_FRAME_SIZE )

/* --- Decisione / Controllo --- */

/* SetPoint = 2 float */
#define SETPOINT_FRAME_SIZE (sizeof(BUS_SetPoint))
/* Decision = 2 int (ENUM_Actuator, ENUM_RoverAction) */
#define DECISION_FRAME_SIZE ( sizeof(ENUM_Actuator) + sizeof(ENUM_RoverAction) + sizeof(ENUM_SafeAction))

#endif /* INC_UART_FRAMES_H_ */
