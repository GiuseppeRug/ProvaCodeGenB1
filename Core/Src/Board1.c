/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: Board1.c
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

#include "Board1.h"
#include "rtwtypes.h"
#include "Board1_types.h"


// NOSTRI INCLUDE
#include "serialize.h"
#include "deserialize.h"
#include "stubFunctions.h"

/* Named constants for Chart: '<Root>/SupervisorB1' */
#define B_IN_StateCoherenceVerification ((uint8_T)3U)
#define Boar_IN_ComputingOwnGlobalState ((uint8_T)1U)
#define Board1_IN_ActuatorSelection    ((uint8_T)1U)
#define Board1_IN_CommunicationPhase   ((uint8_T)1U)
#define Board1_IN_ComputeDecision      ((uint8_T)1U)
#define Board1_IN_D_Receive            ((uint8_T)1U)
#define Board1_IN_D_Transmit           ((uint8_T)2U)
#define Board1_IN_ExchangeDecision     ((uint8_T)2U)
#define Board1_IN_ExchangeGlobalState  ((uint8_T)3U)
#define Board1_IN_ExchangeLocalState   ((uint8_T)4U)
#define Board1_IN_Execution            ((uint8_T)3U)
#define Board1_IN_GL_Receive           ((uint8_T)2U)
#define Board1_IN_GL_Transmit          ((uint8_T)3U)
#define Board1_IN_LS_Receive           ((uint8_T)1U)
#define Board1_IN_LS_Transmit          ((uint8_T)2U)
#define Board1_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define Board1_IN_NotCommunicating     ((uint8_T)2U)
#define Board1_IN_ReceivingRTR         ((uint8_T)1U)
#define Board1_IN_Trasmit              ((uint8_T)2U)
#define Board1_IN_UserActionComputation ((uint8_T)4U)
#define Board1_SIZE_DECISION           ((uint8_T)24U)
#define Board1_SIZE_GLOBAL_STATE       ((uint8_T)40U)
#define Board1_SIZE_LOCAL_STATE_B1     ((uint8_T)24U)
#define Board1_SIZE_LOCAL_STATE_B2     ((uint8_T)16U)
#define Board_IN_EmergencyStateAnalysis ((uint8_T)2U)

/* Block states (default storage) */
DW_Board1_T Board1_DW;

/* External inputs (root inport signals with default storage) */
ExtU_Board1_T Board1_U;

/* External outputs (root outports fed by signals with default storage) */
ExtY_Board1_T Board1_Y;

/* Real-time model */
static RT_MODEL_Board1_T Board1_M_;
RT_MODEL_Board1_T *const Board1_M = &Board1_M_;

/* Forward declaration for local functions */
static ENUM_UserAction Board1_computeUserAction(int16_T x_lever, int16_T y_lever);

/* Function for Chart: '<Root>/SupervisorB1' */
static ENUM_UserAction Board1_computeUserAction(int16_T x_lever, int16_T y_lever)
{
  ENUM_UserAction userAction;
  userAction = UA_NONE;
  if (x_lever < 0) {
    userAction = UA_ROTATE_LEFT;
  } else if (x_lever > 0) {
    userAction = UA_ROTATE_RIGHT;
  } else if (y_lever > 0) {
    userAction = UA_FORWARD;
  } else if (y_lever < 0) {
    userAction = UA_BACKWARD;
  }

  return userAction;
}

/* Model step function */
void Board1_step(void)
{
  real_T continua_prev;

  /* Chart: '<Root>/SupervisorB1' incorporates:
   *  Inport: '<Root>/In1'
   *  Inport: '<Root>/batteryLevel'
   *  Inport: '<Root>/speed'
   *  Inport: '<Root>/temperature'
   *  Outport: '<Root>/board1GlobalState'
   */
  continua_prev = Board1_DW.continua_start;
  Board1_DW.continua_start = Board1_U.In1;
  if (Board1_DW.is_active_c15_Board1 == 0U) {
    Board1_DW.is_active_c15_Board1 = 1U;

    /*  board1Decision.actuator = ENUM_Actuator.BOARD1;
       board1Decision.userAction = ENUM_UserAction.UA_NONE;
       inizializzaizone fasulla di decision con interi e non enum */
    Board1_DW.board1Decision.actuator = 1;
    Board1_DW.board1Decision.roverAction = 2;
    Board1_DW.board1Decision.safeAction = 3;

    /* Outport: '<Root>/currentUserAction' */
    /*  variabili locali
       Inizializzazione valori di output */
    Board1_Y.currentUserAction = UA_NONE;
    Board1_DW.is_RoverState = Board1_IN_NotCommunicating;
  } else if (Board1_DW.is_RoverState == Board1_IN_CommunicationPhase) {
    switch (Board1_DW.is_CommunicationPhase) {
     case Board1_IN_ComputeDecision:
      switch (Board1_DW.is_ComputeDecision) {
       case Board1_IN_ActuatorSelection:
        Board1_DW.is_ComputeDecision = Board1_IN_NO_ACTIVE_CHILD;
        Board1_DW.exit_port_index_ComputeDecision = 2U;
        break;

       case Board_IN_EmergencyStateAnalysis:
        Board1_DW.is_ComputeDecision = Board1_IN_UserActionComputation;

        /* Outport: '<Root>/currentUserAction' incorporates:
         *  Outport: '<Root>/board1GlobalState'
         */
        Board1_Y.currentUserAction = Board1_computeUserAction
          (Board1_Y.board1GlobalState.localStateB2.remoteController.x_lever,
           Board1_Y.board1GlobalState.localStateB2.remoteController.y_lever);
        break;

       case B_IN_StateCoherenceVerification:
        Board1_DW.is_ComputeDecision = Board_IN_EmergencyStateAnalysis;
        break;

       default:
        /* case IN_UserActionComputation: */
        Board1_DW.is_ComputeDecision = Board1_IN_ActuatorSelection;

        /*  en: board1Decision.actuator = actuatorSelection(board1Decision.actuator); */
        break;
      }

      if (Board1_DW.exit_port_index_ComputeDecision == 2U) {
        Board1_DW.exit_port_index_ComputeDecision = 0U;
        Board1_DW.is_CommunicationPhase = Board1_IN_ExchangeDecision;
        Board1_DW.txPayload = Board1_SIZE_DECISION;
        Board1_DW.rxPayload = Board1_SIZE_DECISION;
        serializeDecision(&Board1_DW.tx_buffer[0], (BUS_Decision *)
                          &Board1_DW.board1Decision);
        Board1_DW.is_ExchangeDecision = Board1_IN_D_Transmit;

        /*  Aspettando la disponibilit� del partner per trasmettere */
        Board1_DW.is_D_Transmit = Board1_IN_ReceivingRTR;
      }
      break;

     case Board1_IN_ExchangeDecision:
      switch (Board1_DW.is_ExchangeDecision) {
       case Board1_IN_D_Receive:
        if (Board1_DW.received == 1) {
          Board1_DW.exit_port_index_D_Receive = 2U;
        }

        if (Board1_DW.exit_port_index_D_Receive == 2U) {
          Board1_DW.exit_port_index_D_Receive = 0U;
          deserializeDecision(&Board1_DW.rx_buffer[0], Board1_DW.rxPayload,
                              (BUS_Decision *)&Board1_DW.board2Decision);
          Board1_DW.is_ExchangeDecision = Board1_IN_Execution;
        }
        break;

       case Board1_IN_D_Transmit:
        if (Board1_DW.is_D_Transmit == Board1_IN_ReceivingRTR) {
          if (CheckRTR() != 0) {
            Board1_DW.is_D_Transmit = Board1_IN_Trasmit;
            UartTransmitIT(&Board1_DW.tx_buffer[0], Board1_DW.txPayload);
          }
        } else {
          /* case IN_Trasmit: */
          Board1_DW.is_D_Transmit = Board1_IN_NO_ACTIVE_CHILD;
          Board1_DW.exit_port_index_D_Transmit = 2U;
        }

        if (Board1_DW.exit_port_index_D_Transmit == 2U) {
          Board1_DW.exit_port_index_D_Transmit = 0U;
          Board1_DW.is_ExchangeDecision = Board1_IN_D_Receive;

          /* Pronto a ricevere */
          UartReceiveIT(&Board1_DW.rx_buffer[0], Board1_DW.rxPayload);
        }
        break;

       default:
        /* case IN_Execution: */
        if (continua_prev != Board1_DW.continua_start) {
          Board1_DW.is_ExchangeDecision = Board1_IN_NO_ACTIVE_CHILD;
          Board1_DW.exit_port_index_ExchangeDecisio = 2U;
        }
        break;
      }

      if (Board1_DW.exit_port_index_ExchangeDecisio == 2U) {
        Board1_DW.exit_port_index_ExchangeDecisio = 0U;
        Board1_DW.is_CommunicationPhase = Board1_IN_NO_ACTIVE_CHILD;
        Board1_DW.exit_port_index_CommunicationPh = 2U;
      }
      break;

     case Board1_IN_ExchangeGlobalState:
      switch (Board1_DW.is_ExchangeGlobalState) {
       case Boar_IN_ComputingOwnGlobalState:
        serializeGlobalState(&Board1_DW.tx_buffer[0], (BUS_GlobalState *)
                             &Board1_Y.board1GlobalState);
        Board1_DW.is_ExchangeGlobalState = Board1_IN_GL_Transmit;

        /*  Aspettando la disponibilit� del partner per trasmettere */
        Board1_DW.is_GL_Transmit = Board1_IN_ReceivingRTR;
        break;

       case Board1_IN_GL_Receive:
        if (Board1_DW.received == 1) {
          Board1_DW.exit_port_index_GL_Receive = 2U;
        }

        if (Board1_DW.exit_port_index_GL_Receive == 2U) {
          Board1_DW.exit_port_index_GL_Receive = 0U;
          deserializeGlobalState(&Board1_DW.rx_buffer[0], Board1_DW.rxPayload,
            (BUS_GlobalState *)&Board1_DW.board2GlobalState);

          /* stampaBuffer(board2LocalState); */
          Board1_DW.is_ExchangeGlobalState = Board1_IN_NO_ACTIVE_CHILD;
          Board1_DW.exit_port_index_ExchangeGlobalS = 2U;
        }
        break;

       default:
        /* case IN_GL_Transmit: */
        if (Board1_DW.is_GL_Transmit == Board1_IN_ReceivingRTR) {
          if (CheckRTR() != 0) {
            Board1_DW.is_GL_Transmit = Board1_IN_Trasmit;
            UartTransmitIT(&Board1_DW.tx_buffer[0], Board1_DW.txPayload);
          }
        } else {
          /* case IN_Trasmit: */
          Board1_DW.is_GL_Transmit = Board1_IN_NO_ACTIVE_CHILD;
          Board1_DW.exit_port_index_GL_Transmit = 2U;
        }

        if (Board1_DW.exit_port_index_GL_Transmit == 2U) {
          Board1_DW.exit_port_index_GL_Transmit = 0U;
          Board1_DW.is_ExchangeGlobalState = Board1_IN_GL_Receive;

          /* Pronto a ricevere */
          UartReceiveIT(&Board1_DW.rx_buffer[0], Board1_DW.rxPayload);
        }
        break;
      }

      if (Board1_DW.exit_port_index_ExchangeGlobalS == 2U) {
        Board1_DW.exit_port_index_ExchangeGlobalS = 0U;
        Board1_DW.is_CommunicationPhase = Board1_IN_ComputeDecision;
        Board1_DW.is_ComputeDecision = B_IN_StateCoherenceVerification;
      }
      break;

     default:
      /* case IN_ExchangeLocalState: */
      if (Board1_DW.is_ExchangeLocalState == Board1_IN_LS_Receive) {
        if (Board1_DW.received == 1) {
          Board1_DW.exit_port_index_LS_Receive = 2U;
        }

        if (Board1_DW.exit_port_index_LS_Receive == 2U) {
          Board1_DW.exit_port_index_LS_Receive = 0U;
          deserializeLocalStateB2(&Board1_DW.rx_buffer[0], Board1_DW.rxPayload,
            (BUS_LocalStateB2 *)&Board1_DW.board2LocalState);
          Board1_DW.is_ExchangeLocalState = Board1_IN_NO_ACTIVE_CHILD;
          Board1_DW.exit_port_index_ExchangeLocalSt = 2U;
        }
      } else {
        /* case IN_LS_Transmit: */
        if (Board1_DW.is_LS_Transmit == Board1_IN_ReceivingRTR) {
          if (CheckRTR() != 0) {
            Board1_DW.is_LS_Transmit = Board1_IN_Trasmit;
            UartTransmitIT(&Board1_DW.tx_buffer[0], Board1_DW.txPayload);
          }
        } else {
          /* case IN_Trasmit: */
          Board1_DW.is_LS_Transmit = Board1_IN_NO_ACTIVE_CHILD;
          Board1_DW.exit_port_index_LS_Transmit = 2U;
        }

        if (Board1_DW.exit_port_index_LS_Transmit == 2U) {
          Board1_DW.exit_port_index_LS_Transmit = 0U;
          Board1_DW.is_ExchangeLocalState = Board1_IN_LS_Receive;

          /* Pronto a ricevere */
          UartReceiveIT(&Board1_DW.rx_buffer[0], Board1_DW.rxPayload);
        }
      }

      if (Board1_DW.exit_port_index_ExchangeLocalSt == 2U) {
        Board1_DW.exit_port_index_ExchangeLocalSt = 0U;
        Board1_DW.is_CommunicationPhase = Board1_IN_ExchangeGlobalState;
        Board1_DW.txPayload = Board1_SIZE_GLOBAL_STATE;
        Board1_DW.rxPayload = Board1_SIZE_GLOBAL_STATE;
        Board1_DW.is_ExchangeGlobalState = Boar_IN_ComputingOwnGlobalState;
        Board1_Y.board1GlobalState.localStateB1 = Board1_DW.board1LocalState;

        /*  forse dovrei fare una copia del backup all'inizio del mio stato,
           siccome durante la trasmissione le variabili possono cambiare */
        Board1_Y.board1GlobalState.localStateB2 = Board1_DW.board2LocalState;
      }
      break;
    }

    if (Board1_DW.exit_port_index_CommunicationPh == 2U) {
      Board1_DW.exit_port_index_CommunicationPh = 0U;
      Board1_DW.is_RoverState = Board1_IN_NotCommunicating;
    }
  } else {
    /* case IN_NotCommunicating: */
    Board1_DW.board1LocalState.speed = Board1_U.speed;
    Board1_DW.board1LocalState.temperature = Board1_U.temperature;
    Board1_DW.board1LocalState.batteryLevel = Board1_U.batteryLevel;
    Board1_DW.is_RoverState = Board1_IN_CommunicationPhase;
    Board1_DW.is_CommunicationPhase = Board1_IN_ExchangeLocalState;
    Board1_DW.txPayload = Board1_SIZE_LOCAL_STATE_B1;
    Board1_DW.rxPayload = Board1_SIZE_LOCAL_STATE_B2;
    serializeLocalStateB1(&Board1_DW.tx_buffer[0], (BUS_LocalStateB1 *)
                          &Board1_DW.board1LocalState);

    /* stampaBuffer(tx_buffer); */
    Board1_DW.is_ExchangeLocalState = Board1_IN_LS_Transmit;

    /*  Aspettando la disponibilit� del partner per trasmettere */
    Board1_DW.is_LS_Transmit = Board1_IN_ReceivingRTR;
  }

  /* End of Chart: '<Root>/SupervisorB1' */
}

/* Model initialize function */
void Board1_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void Board1_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
