/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Board1.h
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

#ifndef Board1_h_
#define Board1_h_
#ifndef Board1_COMMON_INCLUDES_
#define Board1_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "math.h"
#endif                                 /* Board1_COMMON_INCLUDES_ */

#include "Board1_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* user code (top of header file) */
#include "serialize.h"
#include "deserialize.h"
#include "stubFunctions.h"

/* Block states (default storage) for system '<Root>' */
typedef struct {
  BUS_GlobalState board2GlobalState;   /* '<Root>/SupervisorB1' */
  BUS_LocalStateB1 board1LocalState;   /* '<Root>/SupervisorB1' */
  BUS_LocalStateB2 board2LocalState;   /* '<Root>/SupervisorB1' */
  BUS_Decision board1Decision;         /* '<Root>/SupervisorB1' */
  BUS_Decision board2Decision;         /* '<Root>/SupervisorB1' */
  real_T continua_start;               /* '<Root>/SupervisorB1' */
  uint32_T exit_port_index_CommunicationPh;/* '<Root>/SupervisorB1' */
  uint32_T exit_port_index_ComputeDecision;/* '<Root>/SupervisorB1' */
  uint32_T exit_port_index_ExchangeDecisio;/* '<Root>/SupervisorB1' */
  uint32_T exit_port_index_D_Receive;  /* '<Root>/SupervisorB1' */
  uint32_T exit_port_index_D_Transmit; /* '<Root>/SupervisorB1' */
  uint32_T exit_port_index_ExchangeGlobalS;/* '<Root>/SupervisorB1' */
  uint32_T exit_port_index_GL_Receive; /* '<Root>/SupervisorB1' */
  uint32_T exit_port_index_GL_Transmit;/* '<Root>/SupervisorB1' */
  uint32_T exit_port_index_ExchangeLocalSt;/* '<Root>/SupervisorB1' */
  uint32_T exit_port_index_LS_Receive; /* '<Root>/SupervisorB1' */
  uint32_T exit_port_index_LS_Transmit;/* '<Root>/SupervisorB1' */
  uint8_T tx_buffer[64];               /* '<Root>/SupervisorB1' */
  uint8_T rx_buffer[64];               /* '<Root>/SupervisorB1' */
  uint8_T received;                    /* '<Root>/SupervisorB1' */
  uint8_T txPayload;                   /* '<Root>/SupervisorB1' */
  uint8_T rxPayload;                   /* '<Root>/SupervisorB1' */
  uint8_T is_active_c15_Board1;        /* '<Root>/SupervisorB1' */
  uint8_T is_RoverState;               /* '<Root>/SupervisorB1' */
  uint8_T is_CommunicationPhase;       /* '<Root>/SupervisorB1' */
  uint8_T is_ComputeDecision;          /* '<Root>/SupervisorB1' */
  uint8_T is_ExchangeDecision;         /* '<Root>/SupervisorB1' */
  uint8_T is_D_Transmit;               /* '<Root>/SupervisorB1' */
  uint8_T is_ExchangeGlobalState;      /* '<Root>/SupervisorB1' */
  uint8_T is_GL_Transmit;              /* '<Root>/SupervisorB1' */
  uint8_T is_ExchangeLocalState;       /* '<Root>/SupervisorB1' */
  uint8_T is_LS_Transmit;              /* '<Root>/SupervisorB1' */
} DW_Board1_T;

/* External inputs (root inport signals with default storage) */
typedef struct {
  BUS_Speed speed;                     /* '<Root>/speed' */
  real32_T temperature;                /* '<Root>/temperature' */
  real32_T batteryLevel;               /* '<Root>/batteryLevel' */
  BUS_SetPoint setPoint;               /* '<Root>/setPoint' */
  ENUM_RoverAction roverAction;        /* '<Root>/roverAction' */
  ENUM_SafeAction safeAction;          /* '<Root>/safeAction' */
  real_T In1;                          /* '<Root>/In1' */
} ExtU_Board1_T;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  ENUM_UserAction currentUserAction;   /* '<Root>/currentUserAction' */
  BUS_GlobalState board1GlobalState;   /* '<Root>/board1GlobalState' */
} ExtY_Board1_T;

/* Real-time Model Data Structure */
struct tag_RTM_Board1_T {
  const char_T * volatile errorStatus;
};

/* Block states (default storage) */
extern DW_Board1_T Board1_DW;

/* External inputs (root inport signals with default storage) */
extern ExtU_Board1_T Board1_U;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_Board1_T Board1_Y;

/* Model entry point functions */
extern void Board1_initialize(void);
extern void Board1_step(void);
extern void Board1_terminate(void);

/* Real-time Model object */
extern RT_MODEL_Board1_T *const Board1_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Board1'
 * '<S1>'   : 'Board1/SupervisorB1'
 */
#endif                                 /* Board1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
