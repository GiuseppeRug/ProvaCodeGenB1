/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Board1_types.h
 *
 * Code generated for Simulink model 'Board1'.
 *
 * Model version                  : 2.60
 * Simulink Coder version         : 24.1 (R2024a) 19-Nov-2023
 * C/C++ source code generated on : Tue Dec 23 15:50:49 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef Board1_types_h_
#define Board1_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_BUS_Speed_
#define DEFINED_TYPEDEF_FOR_BUS_Speed_

typedef struct {
  real32_T motor1;
  real32_T motor2;
  real32_T motor3;
  real32_T motor4;
} BUS_Speed;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_SetPoint_
#define DEFINED_TYPEDEF_FOR_BUS_SetPoint_

typedef struct {
  real32_T leftAxis;
  real32_T rightAxis;
} BUS_SetPoint;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_Decision_
#define DEFINED_TYPEDEF_FOR_BUS_Decision_

typedef struct {
  int32_T actuator;
  int32_T roverAction;
  int32_T safeAction;
} BUS_Decision;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_LocalStateB1_
#define DEFINED_TYPEDEF_FOR_BUS_LocalStateB1_

typedef struct {
  BUS_Speed speed;
  real32_T temperature;
  real32_T batteryLevel;
} BUS_LocalStateB1;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_Sonar_
#define DEFINED_TYPEDEF_FOR_BUS_Sonar_

typedef struct {
  uint16_T left;
  uint16_T front;
  uint16_T right;
} BUS_Sonar;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_RemoteController_
#define DEFINED_TYPEDEF_FOR_BUS_RemoteController_

typedef struct {
  int16_T x_lever;
  int16_T y_lever;
  uint16_T buttons;
} BUS_RemoteController;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_LocalStateB2_
#define DEFINED_TYPEDEF_FOR_BUS_LocalStateB2_

typedef struct {
  BUS_Sonar sonar;
  real32_T gyroscope;
  BUS_RemoteController remoteController;
} BUS_LocalStateB2;

#endif

#ifndef DEFINED_TYPEDEF_FOR_BUS_GlobalState_
#define DEFINED_TYPEDEF_FOR_BUS_GlobalState_

typedef struct {
  BUS_LocalStateB1 localStateB1;
  BUS_LocalStateB2 localStateB2;
} BUS_GlobalState;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENUM_CoherenceErrors_
#define DEFINED_TYPEDEF_FOR_ENUM_CoherenceErrors_

typedef enum {
  NO_ERROR = 0,                        /* Default value */
  PARTNER_STATE_INCOHERENCE,
  OWN_STATE_INCOHERENCE,
  COMBO_ERROR
} ENUM_CoherenceErrors;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENUM_UserAction_
#define DEFINED_TYPEDEF_FOR_ENUM_UserAction_

typedef enum {
  UA_NONE = 0,                         /* Default value */
  UA_FORWARD,
  UA_ROTATE_LEFT,
  UA_ROTATE_RIGHT,
  UA_BACKWARD,
  UA_BRAKING_HARD,
  UA_BRAKING_SMOOTH
} ENUM_UserAction;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENUM_StatusBattery_
#define DEFINED_TYPEDEF_FOR_ENUM_StatusBattery_

typedef enum {
  BATT_STATUS_OK = 0,                  /* Default value */
  BATT_STATUS_LOW_WARN,
  BATT_STATUS_CRITICAL
} ENUM_StatusBattery;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENUM_StatusEncoder_
#define DEFINED_TYPEDEF_FOR_ENUM_StatusEncoder_

typedef enum {
  STATUS_ALL_OK = 0,                   /* Default value */
  STATUS_E1_FAIL = 1,
  STATUS_E2_FAIL = 2,
  STATUS_E3_FAIL = 4,
  STATUS_E4_FAIL = 8,
  STATUS_E1E2_FAIL = 3,
  STATUS_E1E3_FAIL = 5,
  STATUS_E1E4_FAIL = 9,
  STATUS_E2E3_FAIL = 6,
  STATUS_E2E4_FAIL = 10,
  STATUS_E3E4_FAIL = 12,
  STATUS_E1E2E3_FAIL = 7,
  STATUS_E1E2E4_FAIL = 11,
  STATUS_E1E3E4_FAIL = 13,
  STATUS_E2E3E4_FAIL = 14,
  STATUS_ALL_FAIL = 15
} ENUM_StatusEncoder;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENUM_StatusTemperature_
#define DEFINED_TYPEDEF_FOR_ENUM_StatusTemperature_

typedef enum {
  TEMP_DATA_OK = 0,                    /* Default value */
  TEMP_DATA_ANOMALOUS
} ENUM_StatusTemperature;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENUM_RoverAction_
#define DEFINED_TYPEDEF_FOR_ENUM_RoverAction_

typedef enum {
  RA_IDLE = 0,                         /* Default value */
  RA_FORWARD = 1,
  RA_ROTATE_LEFT = 2,
  RA_ROTATE_RIGHT = 3,
  RA_BRAKING_HARD = 5,
  RA_BRAKING_SMOOTH = 6
} ENUM_RoverAction;

#endif

#ifndef DEFINED_TYPEDEF_FOR_ENUM_SafeAction_
#define DEFINED_TYPEDEF_FOR_ENUM_SafeAction_

typedef enum {
  SA_NONE = 0,                         /* Default value */
  SA_SWERVE_LEFT,
  SA_SWERVE_RIGHT,
  SA_BRAKING_HARD,
  SA_BRAKING_SMOOTH
} ENUM_SafeAction;

#endif

// NOSTRI NON GENERATI
typedef float Gyroscope;
typedef float BatteryLevel;
typedef float Temperature;


// DOVEVA GENERARE
typedef enum {
  BOARD1 = 0,                         /* Default value */
  BOARD2 = 1
} ENUM_Actuator;


/* Forward declaration for rtModel */
typedef struct tag_RTM_Board1_T RT_MODEL_Board1_T;

#endif                                 /* Board1_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
