/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  Rte.c
 *        Config:  MyECU.dpa
 *   ECU-Project:  MyECU
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  RTE implementation file
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

/* PRQA S 0777, 0779, 0781, 0857 EOF */ /* MD_Rte_0777, MD_Rte_0779, MD_Rte_0781, MD_MSR_1.1_857 */

#define RTE_CORE
#include "Os.h" /* PRQA S 0828, 0883 */ /* MD_MSR_1.1_828, MD_Rte_Os */
#include "Rte_Type.h"
#include "Rte_Main.h"

#include "Rte_BswM.h"
#include "Rte_ComM.h"
#include "Rte_CtApMySwc.h"
#include "Rte_CtCddIoHwAb.h"
#include "Rte_CtSaDisplay.h"
#include "Rte_CtSaDoor.h"
#include "Rte_CtSaInteriorLight.h"
#include "Rte_Dem.h"
#include "Rte_Det.h"
#include "Rte_EcuM.h"
#include "Rte_NvM.h"
#include "SchM_BswM.h"
#include "SchM_Can.h"
#include "SchM_CanIf.h"
#include "SchM_CanNm.h"
#include "SchM_CanSM.h"
#include "SchM_Com.h"
#include "SchM_ComM.h"
#include "SchM_Dem.h"
#include "SchM_Det.h"
#include "SchM_EcuM.h"
#include "SchM_Fee.h"
#include "SchM_Fls.h"
#include "SchM_Nm.h"
#include "SchM_NvM.h"
#include "SchM_PduR.h"

#include "Rte_Hook.h"

#include "Com.h"
#if defined(IL_ASRCOM_VERSION)
# define RTE_USE_COM_TXSIGNAL_RDACCESS
#endif

#include "Rte_Cbk.h"

/* AUTOSAR 3.x compatibility */
#if !defined (STATIC)
# define STATIC static
#endif


/**********************************************************************************************************************
 * API for enable / disable interrupts global
 *********************************************************************************************************************/

#if defined(osDisableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableAllInterrupts() osDisableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_DisableAllInterrupts() DisableAllInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableGlobalKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableAllInterrupts() osEnableGlobalKM()   /* MICROSAR OS */
#else
# define Rte_EnableAllInterrupts() EnableAllInterrupts()   /* AUTOSAR OS */
#endif

/**********************************************************************************************************************
 * API for enable / disable interrupts up to the systemLevel
 *********************************************************************************************************************/

#if defined(osDisableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_DisableOSInterrupts() osDisableLevelKM()   /* MICROSAR OS */
#else
# define Rte_DisableOSInterrupts() SuspendOSInterrupts()   /* AUTOSAR OS */
#endif

#if defined(osEnableLevelKM) && !defined(RTE_DISABLE_ENHANCED_INTERRUPT_LOCK_API)
# define Rte_EnableOSInterrupts() osEnableLevelKM()   /* MICROSAR OS */
#else
# define Rte_EnableOSInterrupts() ResumeOSInterrupts()   /* AUTOSAR OS */
#endif


/**********************************************************************************************************************
 * Buffers for unqueued S/R
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(boolean, RTE_VAR_NOINIT) Rte_CpApMySwc_PpDisplayState_DeDisplayBusState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_NOINIT) Rte_CpApMySwc_PpDisplayState_DeLightOnOffCounter; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(uint32, RTE_VAR_NOINIT) Rte_CpApMySwc_PpDisplayState_DeOdometerValue; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(boolean, RTE_VAR_NOINIT) Rte_CpApMySwc_PpDisplayState_DeOdometerWriteRequestPending; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(IdtLightState, RTE_VAR_NOINIT) Rte_CpApMySwc_PpLightStateFront_DeLightState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(IdtDisplayIgnitionState, RTE_VAR_NOINIT) Rte_CpSaDisplay_PpLocalIgnitionState_DeIgnitionState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(IdtDoorState, RTE_VAR_NOINIT) Rte_CpSaDoorFrontLeft_PpDoorState_DeDoorState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
VAR(IdtDoorState, RTE_VAR_NOINIT) Rte_CpSaDoorFrontRight_PpDoorState_DeDoorState; /* PRQA S 0850, 3408, 1504 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Buffers for implicit communication
 *********************************************************************************************************************/

#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

VAR(Rte_tsMy_Task, RTE_VAR_NOINIT) Rte_My_Task; /* PRQA S 0850, 0759, 3408, 1504 */ /* MD_MSR_19.8, MD_MSR_18.4, MD_Rte_3408, MD_MSR_8.10 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * API Prototypes
 *********************************************************************************************************************/
FUNC(Std_ReturnType, RTE_CODE) Rte_CallInst1_CtSaDoor_PpDoorIoHwAb_ReadChannel(P2VAR(IdtDioValueType, AUTOMATIC, RTE_CTSADOOR_APPL_VAR) value); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(Std_ReturnType, RTE_CODE) Rte_WriteInst1_CtSaDoor_PpDoorState_DeDoorState(IdtDoorState data); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(Std_ReturnType, RTE_CODE) Rte_CallInst2_CtSaDoor_PpDoorIoHwAb_ReadChannel(P2VAR(IdtDioValueType, AUTOMATIC, RTE_CTSADOOR_APPL_VAR) value); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */
FUNC(Std_ReturnType, RTE_CODE) Rte_WriteInst2_CtSaDoor_PpDoorState_DeDoorState(IdtDoorState data); /* PRQA S 0850, 3447 */ /* MD_MSR_19.8, MD_Rte_3447 */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Component Data Structures
 *********************************************************************************************************************/

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CtSaDoor, RTE_CONST) Rte_Instance_CpSaDoorFrontLeft =
{
  /* Port API section */
  {
    Rte_CallInst1_CtSaDoor_PpDoorIoHwAb_ReadChannel,
  },
  {
    Rte_WriteInst1_CtSaDoor_PpDoorState_DeDoorState,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

/* PRQA S 0850, 3408, 1504 L1 */ /* MD_MSR_19.8, MD_Rte_3408, MD_MSR_8.10 */
CONST(struct Rte_CDS_CtSaDoor, RTE_CONST) Rte_Instance_CpSaDoorFrontRight =
{
  /* Port API section */
  {
    Rte_CallInst2_CtSaDoor_PpDoorIoHwAb_ReadChannel,
  },
  {
    Rte_WriteInst2_CtSaDoor_PpDoorState_DeDoorState,
  },
  /* Vendor specific section */
};
/* PRQA L:L1 */

#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



#define RTE_START_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 * Data structures for mode management
 *********************************************************************************************************************/

VAR(uint8, RTE_VAR_NOINIT) Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode; /* PRQA S 3408 */ /* MD_Rte_3408 */
STATIC VAR(Rte_ModeInfoType_ComM_UM_USR_CHNL_CAN00_currentMode, RTE_VAR_NOINIT) Rte_ModeInfo_ComM_UM_USR_CHNL_CAN00_currentMode;

VAR(uint8, RTE_VAR_NOINIT) Rte_ModeMachine_ComM_UM_USR_CHNL_CAN00_currentMode; /* PRQA S 3408 */ /* MD_Rte_3408 */

VAR(uint8, RTE_VAR_NOINIT) Rte_ModeMachine_CpApMySwc_PpBswMRequestShutdown_BswM_MDGP_MdgBswMRequestShutdown; /* PRQA S 3408 */ /* MD_Rte_3408 */

#define RTE_STOP_SEC_VAR_NOINIT_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

#define RTE_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */



/* PRQA S 3408 L1 */ /* MD_Rte_3408 */
CONST(EventMaskType, RTE_CONST) Rte_ModeExitEventMask_ComM_UM_USR_CHNL_CAN00_currentMode[3] =
{
  Rte_Ev_Run_CpApMySwc_RCtApMySwcComM_ModeChange_FULL_COMM_Exit, /* COMM_FULL_COMMUNICATION */
  (EventMaskType) 0, /* COMM_NO_COMMUNICATION */
  (EventMaskType) 0  /* COMM_SILENT_COMMUNICATION */
};
/* PRQA L:L1 */

/* PRQA S 3408 L1 */ /* MD_Rte_3408 */
CONST(EventMaskType, RTE_CONST) Rte_ModeEntryEventMask_ComM_UM_USR_CHNL_CAN00_currentMode[3] =
{
  Rte_Ev_Run_CpApMySwc_RCtApMySwcComM_ModeChange_FULL_COMM_Entry, /* COMM_FULL_COMMUNICATION */
  (EventMaskType) 0, /* COMM_NO_COMMUNICATION */
  (EventMaskType) 0  /* COMM_SILENT_COMMUNICATION */
};
/* PRQA L:L1 */



#define RTE_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * Timer handling
 *********************************************************************************************************************/

#define RTE_USEC_SystemTimer(val) ((TickType)RTE_CONST_USEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_Rte_0342 */
#define RTE_MSEC_SystemTimer(val) ((TickType)RTE_CONST_MSEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_Rte_0342 */
#define RTE_SEC_SystemTimer(val)  ((TickType)RTE_CONST_SEC_SystemTimer_##val) /* PRQA S 0342 */ /* MD_Rte_0342 */

#define RTE_CONST_MSEC_SystemTimer_0 (0UL)

#define RTE_CONST_MSEC_SystemTimer_10 (10UL)

#define RTE_CONST_MSEC_SystemTimer_20 (20UL)

#define RTE_CONST_MSEC_SystemTimer_200 (200UL)

#define RTE_CONST_MSEC_SystemTimer_5 (5UL)


/**********************************************************************************************************************
 * Internal definitions
 *********************************************************************************************************************/

#define RTE_TASK_TIMEOUT_EVENT_MASK   ((EventMaskType)0x01)
#define RTE_TASK_WAITPOINT_EVENT_MASK ((EventMaskType)0x02)

/**********************************************************************************************************************
 * RTE life cycle API
 *********************************************************************************************************************/

#define RTE_START_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

FUNC(void, RTE_CODE) SchM_Init(void)
{
  /* activate the tasks */
  (void)ActivateTask(SchM_Task); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE2_SchM_Task_0_20ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(20)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_Fee_Fee_MainFunction, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(5)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE2_SchM_Task_0_10ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(10)); /* PRQA S 3417 */ /* MD_Rte_Os */

}

FUNC(Std_ReturnType, RTE_CODE) Rte_Start(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* set default values for internal data */
  Rte_CpApMySwc_PpDisplayState_DeDisplayBusState = FALSE;
  Rte_CpApMySwc_PpDisplayState_DeLightOnOffCounter = 0U;
  Rte_CpApMySwc_PpDisplayState_DeOdometerValue = 0U;
  Rte_CpApMySwc_PpDisplayState_DeOdometerWriteRequestPending = FALSE;
  Rte_CpApMySwc_PpLightStateFront_DeLightState = 0U;
  Rte_CpSaDisplay_PpLocalIgnitionState_DeIgnitionState = 0U;
  Rte_CpSaDoorFrontLeft_PpDoorState_DeDoorState = 0U;
  Rte_CpSaDoorFrontRight_PpDoorState_DeDoorState = 0U;

  /* mode management initialization part 1 */

  Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = RTE_MODE_ESH_Mode_STARTUP;

  Rte_ModeMachine_ComM_UM_USR_CHNL_CAN00_currentMode = RTE_MODE_ComMMode_COMM_NO_COMMUNICATION;

  Rte_ModeMachine_CpApMySwc_PpBswMRequestShutdown_BswM_MDGP_MdgBswMRequestShutdown = RTE_MODE_MdgBswMRequestShutdown_BSWM_REQUESTSHUTDOWN_INACTIVE;

  /* activate the tasks */
  (void)ActivateTask(IO_Task); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)ActivateTask(My_Task); /* PRQA S 3417 */ /* MD_Rte_Os */

  /* activate the alarms used for TimingEvents */
  (void)SetRelAlarm(Rte_Al_TE_IO_Task_0_200ms, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(200)); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)SetRelAlarm(Rte_Al_TE_CpApMySwc_RCtApMySwcCode, RTE_MSEC_SystemTimer(0) + (TickType)1, RTE_MSEC_SystemTimer(200)); /* PRQA S 3417 */ /* MD_Rte_Os */

  return RTE_E_OK;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Stop(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE_IO_Task_0_200ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_CpApMySwc_RCtApMySwcCode); /* PRQA S 3417 */ /* MD_Rte_Os */

  return RTE_E_OK;
}

FUNC(void, RTE_CODE) SchM_Deinit(void)
{
  /* deactivate alarms */
  (void)CancelAlarm(Rte_Al_TE2_SchM_Task_0_10ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE2_SchM_Task_0_20ms); /* PRQA S 3417 */ /* MD_Rte_Os */
  (void)CancelAlarm(Rte_Al_TE_Fee_Fee_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */

}

FUNC(void, RTE_CODE) Rte_InitMemory(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
}


/**********************************************************************************************************************
 * Internal/External Tx connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApMySwc_PpDisplayState_DeDisplayBusState(boolean data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CpApMySwc_PpDisplayState_DeDisplayBusState = *(&data);
  /* scheduled trigger for runnables: RCtApDisplayBusStateHandling */
  (void)SetEvent(IO_Task, Rte_Ev_Run_CpSaDisplay_RCtApDisplayBusStateHandling); /* PRQA S 3417 */ /* MD_Rte_Os */
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApMySwc_PpDisplayState_DeLightOnOffCounter(uint32 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CpApMySwc_PpDisplayState_DeLightOnOffCounter = *(&data);
  /* scheduled trigger for runnables: RCtApDisplayLightOnOffHandling */
  (void)SetEvent(IO_Task, Rte_Ev_Run_CpSaDisplay_RCtApDisplayLightOnOffHandling); /* PRQA S 3417 */ /* MD_Rte_Os */
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApMySwc_PpDisplayState_DeOdometerValue(uint32 data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CpApMySwc_PpDisplayState_DeOdometerValue = *(&data);
  /* scheduled trigger for runnables: RCtApDisplayOdometerValue */
  (void)SetEvent(IO_Task, Rte_Ev_Run_CpSaDisplay_RCtApDisplayOdometerValue); /* PRQA S 3417 */ /* MD_Rte_Os */
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApMySwc_PpDisplayState_DeOdometerWriteRequestPending(boolean data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CpApMySwc_PpDisplayState_DeOdometerWriteRequestPending = *(&data);
  /* scheduled trigger for runnables: RCtApDisplayOdometerWriteRequestPending */
  (void)SetEvent(IO_Task, Rte_Ev_Run_CpSaDisplay_RCtApDisplayOdometerWriteRequestPending); /* PRQA S 3417 */ /* MD_Rte_Os */
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApMySwc_PpLightStateFront_DeLightState(IdtLightState data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CpApMySwc_PpLightStateFront_DeLightState = *(&data);
  /* scheduled trigger for runnables: RCtSaInteriorLightSwitchLight */
  (void)SetEvent(IO_Task, Rte_Ev_Run_CpSaInteriorLightFront_RCtSaInteriorLightSwitchLight); /* PRQA S 3417 */ /* MD_Rte_Os */
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_Write_CtApMySwc_PpLightStateRear_DeLightState(IdtLightState data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  ret |= Com_SendSignal(ComConf_ComSignal_sig_RearInteriorLight_Out, (&data)); /* PRQA S 0850 */ /* MD_MSR_19.8 */
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_WriteInst1_CtSaDoor_PpDoorState_DeDoorState(IdtDoorState data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CpSaDoorFrontLeft_PpDoorState_DeDoorState = *(&data);
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */

FUNC(Std_ReturnType, RTE_CODE) Rte_WriteInst2_CtSaDoor_PpDoorState_DeDoorState(IdtDoorState data) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  Rte_CpSaDoorFrontRight_PpDoorState_DeDoorState = *(&data);
  return ret;
} /* PRQA S 6010, 6030, 6050 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL */


/**********************************************************************************************************************
 * Internal C/S connections
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_CallInst1_CtSaDoor_PpDoorIoHwAb_ReadChannel(P2VAR(IdtDioValueType, AUTOMATIC, RTE_CTSADOOR_APPL_VAR) value) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */


  RCtCddIoHwAb_PpDoorFrontLeft_ReadChannel(value);


  return ret;
}

FUNC(Std_ReturnType, RTE_CODE) Rte_CallInst2_CtSaDoor_PpDoorIoHwAb_ReadChannel(P2VAR(IdtDioValueType, AUTOMATIC, RTE_CTSADOOR_APPL_VAR) value) /* PRQA S 0850, 1505, 3673 */ /* MD_MSR_19.8, MD_MSR_8.10, MD_Rte_Qac */
{
  Std_ReturnType ret = RTE_E_OK; /* PRQA S 3197 */ /* MD_Rte_3197 */


  RCtCddIoHwAb_PpDoorFrontRight_ReadChannel(value);


  return ret;
}


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode(uint8 nextMode) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (nextMode >= 5)
  {
    Rte_CallDetReportError(RTE_SWITCH_SERVICE_ID, RTE_E_DET_MODEARGUMENT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  else
  {
    SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode = nextMode;
    ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Mode reading API (Rte_Mode)
 *********************************************************************************************************************/

FUNC(uint8, RTE_CODE) Rte_Mode_BswM_Notification_ESH_ModeNotification_BswM_MDGP_ESH_Mode(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  return Rte_ModeMachine_BswM_Switch_ESH_ModeSwitch_BswM_MDGP_ESH_Mode;
}

FUNC(uint8, RTE_CODE) Rte_Mode_BswM_Notification_SWC_MODE_NOTIFICATION_BswM_MDGP_MdgBswMRequestShutdown_BswM_MDGP_MdgBswMRequestShutdown(void) /* PRQA S 3408 */ /* MD_Rte_3408 */
{
  return Rte_ModeMachine_CpApMySwc_PpBswMRequestShutdown_BswM_MDGP_MdgBswMRequestShutdown;
}


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_ComM_UM_USR_CHNL_CAN00_currentMode(uint8 nextMode) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  SuspendOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  if (nextMode >= 3U)
  {
    ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_CallDetReportError(RTE_SWITCH_SERVICE_ID, RTE_E_DET_MODEARGUMENT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  else if (Rte_ModeMachine_ComM_UM_USR_CHNL_CAN00_currentMode == RTE_TRANSITION_ComMMode)
  {
    ret = RTE_E_LIMIT;
    ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }
  else
  {
    EventMaskType ModeSwitchEventMask;
    uint8 currentMode = Rte_ModeMachine_ComM_UM_USR_CHNL_CAN00_currentMode;

    ModeSwitchEventMask = Rte_ModeExitEventMask_ComM_UM_USR_CHNL_CAN00_currentMode[currentMode] | Rte_ModeEntryEventMask_ComM_UM_USR_CHNL_CAN00_currentMode[nextMode];

    if (ModeSwitchEventMask != (EventMaskType)0)
    {
      Rte_ModeInfo_ComM_UM_USR_CHNL_CAN00_currentMode.Rte_ModeQueue[0] = nextMode;

      Rte_ModeMachine_ComM_UM_USR_CHNL_CAN00_currentMode = RTE_TRANSITION_ComMMode;
      ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      (void)SetEvent(My_Task, ModeSwitchEventMask); /* PRQA S 3417 */ /* MD_Rte_Os */
    }
    else
    {
      Rte_ModeMachine_ComM_UM_USR_CHNL_CAN00_currentMode = nextMode;
      ResumeOSInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    }
  }

  return ret;
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */


/**********************************************************************************************************************
 * Mode Switch API (Rte_Switch)
 *********************************************************************************************************************/

FUNC(Std_ReturnType, RTE_CODE) Rte_Switch_CtApMySwc_PpBswMRequestShutdown_BswM_MDGP_MdgBswMRequestShutdown(uint8 nextMode) /* PRQA S 0850, 1505 */ /* MD_MSR_19.8, MD_MSR_8.10 */
{
  Std_ReturnType ret = RTE_E_OK;

  if (nextMode >= 2)
  {
    Rte_CallDetReportError(RTE_SWITCH_SERVICE_ID, RTE_E_DET_MODEARGUMENT); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    ret = RTE_E_LIMIT;
  }
  else
  {
    Rte_DisableAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
    Rte_ModeMachine_CpApMySwc_PpBswMRequestShutdown_BswM_MDGP_MdgBswMRequestShutdown = nextMode;
    Rte_EnableAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */
  }

  return ret;
} /* PRQA S 6050 */ /* MD_MSR_STCAL */


/**********************************************************************************************************************
 * Task bodies for RTE controlled tasks
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Task:     IO_Task
 * Priority: 3
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(IO_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;


  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic_IO_Task_0_200ms | Rte_Ev_Run_CpSaDisplay_RCtApDisplayBusStateHandling | Rte_Ev_Run_CpSaDisplay_RCtApDisplayLightOnOffHandling | Rte_Ev_Run_CpSaDisplay_RCtApDisplayOdometerValue | Rte_Ev_Run_CpSaDisplay_RCtApDisplayOdometerWriteRequestPending | Rte_Ev_Run_CpSaInteriorLightFront_RCtSaInteriorLightSwitchLight); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(IO_Task, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic_IO_Task_0_200ms | Rte_Ev_Run_CpSaDisplay_RCtApDisplayBusStateHandling | Rte_Ev_Run_CpSaDisplay_RCtApDisplayLightOnOffHandling | Rte_Ev_Run_CpSaDisplay_RCtApDisplayOdometerValue | Rte_Ev_Run_CpSaDisplay_RCtApDisplayOdometerWriteRequestPending | Rte_Ev_Run_CpSaInteriorLightFront_RCtSaInteriorLightSwitchLight)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic_IO_Task_0_200ms) != (EventMaskType)0)
    {
      /* call runnable */
      RCtApDisplayReadIgnitionSignal();

      /* call runnable */
      RCtSaDoorReadDoor(&Rte_Instance_CpSaDoorFrontRight);

      /* call runnable */
      RCtSaDoorReadDoor(&Rte_Instance_CpSaDoorFrontLeft);
    }

    if ((ev & Rte_Ev_Run_CpSaDisplay_RCtApDisplayBusStateHandling) != (EventMaskType)0)
    {
      /* call runnable */
      RCtApDisplayBusStateHandling();
    }

    if ((ev & Rte_Ev_Run_CpSaDisplay_RCtApDisplayLightOnOffHandling) != (EventMaskType)0)
    {
      /* call runnable */
      RCtApDisplayLightOnOffHandling();
    }

    if ((ev & Rte_Ev_Run_CpSaDisplay_RCtApDisplayOdometerValue) != (EventMaskType)0)
    {
      /* call runnable */
      RCtApDisplayOdometerValue();
    }

    if ((ev & Rte_Ev_Run_CpSaDisplay_RCtApDisplayOdometerWriteRequestPending) != (EventMaskType)0)
    {
      /* call runnable */
      RCtApDisplayOdometerWriteRequestPending();
    }

    if ((ev & Rte_Ev_Run_CpSaInteriorLightFront_RCtSaInteriorLightSwitchLight) != (EventMaskType)0)
    {
      /* call runnable */
      RCtSaInteriorLightSwitchLight((uint8)0);
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     My_Task
 * Priority: 2
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(My_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;


  /* call runnable */
  RCtApMySwc_Init();

  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Run_CpApMySwc_RCtApMySwcCode | Rte_Ev_Run_CpApMySwc_RCtApMySwcComM_ModeChange_FULL_COMM_Entry | Rte_Ev_Run_CpApMySwc_RCtApMySwcComM_ModeChange_FULL_COMM_Exit); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(My_Task, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Run_CpApMySwc_RCtApMySwcCode | Rte_Ev_Run_CpApMySwc_RCtApMySwcComM_ModeChange_FULL_COMM_Entry | Rte_Ev_Run_CpApMySwc_RCtApMySwcComM_ModeChange_FULL_COMM_Exit)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Run_CpApMySwc_RCtApMySwcCode) != (EventMaskType)0)
    {
      /* read implicit data */
      *(&Rte_My_Task.Rte_RB.Rte_CtApMySwc_RCtApMySwcCode.Rte_PpDoorStateFrontLeft_DeDoorState.value) = Rte_CpSaDoorFrontLeft_PpDoorState_DeDoorState;
      (void)Com_ReceiveSignal(ComConf_ComSignal_sig_State_RearLeftDoor_In, (&Rte_My_Task.Rte_RB.Rte_CtApMySwc_RCtApMySwcCode.Rte_PpDoorStateRearLeft_DeDoorState.value)); /* PRQA S 3453 */ /* MD_MSR_19.7 */

      /* call runnable */
      RCtApMySwcCode();
    }

    if ((ev & Rte_Ev_Run_CpApMySwc_RCtApMySwcComM_ModeChange_FULL_COMM_Exit) != (EventMaskType)0)
    {
      /* call runnable */
      RCtApMySwcComM_ModeChange_FULL_COMM_Exit();
    }

    if ((ev & Rte_Ev_Run_CpApMySwc_RCtApMySwcComM_ModeChange_FULL_COMM_Entry) != (EventMaskType)0)
    {
      /* call runnable */
      RCtApMySwcComM_ModeChange_FULL_COMM_Entry();
    }

    if (((ev & Rte_Ev_Run_CpApMySwc_RCtApMySwcComM_ModeChange_FULL_COMM_Entry) != (EventMaskType)0) || ((ev & Rte_Ev_Run_CpApMySwc_RCtApMySwcComM_ModeChange_FULL_COMM_Exit) != (EventMaskType)0))
    {

      Rte_CheckDetErrorContinue(Rte_ModeMachine_ComM_UM_USR_CHNL_CAN00_currentMode == RTE_TRANSITION_ComMMode, RTE_TASK_SERVICE_ID, RTE_E_DET_TRANSITIONSTATE); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      Rte_DisableAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */

      Rte_ModeMachine_ComM_UM_USR_CHNL_CAN00_currentMode = Rte_ModeInfo_ComM_UM_USR_CHNL_CAN00_currentMode.Rte_ModeQueue[0];

      Rte_EnableAllInterrupts(); /* PRQA S 3109 */ /* MD_MSR_14.3 */


    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

/**********************************************************************************************************************
 * Task:     SchM_Task
 * Priority: 6
 * Schedule: FULL
 *********************************************************************************************************************/
TASK(SchM_Task) /* PRQA S 3408, 1503 */ /* MD_Rte_3408, MD_MSR_14.1 */
{
  EventMaskType ev;


  for(;;)
  {
    (void)WaitEvent(Rte_Ev_Cyclic2_SchM_Task_0_10ms | Rte_Ev_Cyclic2_SchM_Task_0_20ms | Rte_Ev_Run_Fee_Fee_MainFunction); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)GetEvent(SchM_Task, &ev); /* PRQA S 3417 */ /* MD_Rte_Os */
    (void)ClearEvent(ev & (Rte_Ev_Cyclic2_SchM_Task_0_10ms | Rte_Ev_Cyclic2_SchM_Task_0_20ms | Rte_Ev_Run_Fee_Fee_MainFunction)); /* PRQA S 3417 */ /* MD_Rte_Os */

    if ((ev & Rte_Ev_Cyclic2_SchM_Task_0_20ms) != (EventMaskType)0)
    {
      /* call runnable */
      ComM_MainFunction_0();
    }

    if ((ev & Rte_Ev_Cyclic2_SchM_Task_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      CanSM_MainFunction();

      /* call schedulable entity */
      CanNm_MainFunction();

      /* call schedulable entity */
      Com_MainFunctionRx();

      /* call schedulable entity */
      Com_MainFunctionTx();

      /* call runnable */
      Dem_MainFunction();

      /* call runnable */
      EcuM_MainFunction();

      /* call runnable */
      NvM_MainFunction();

      /* call schedulable entity */
      Can_MainFunction_Mode();

      /* call runnable */
      BswM_MainFunction();

      /* call schedulable entity */
      Can_MainFunction_BusOff();

      /* call schedulable entity */
      Can_MainFunction_Wakeup();
    }

    if ((ev & Rte_Ev_Run_Fee_Fee_MainFunction) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Fee_MainFunction();
    }

    if ((ev & Rte_Ev_Cyclic2_SchM_Task_0_10ms) != (EventMaskType)0)
    {
      /* call schedulable entity */
      Fls_MainFunction();
    }
  }
} /* PRQA S 6010, 6030, 6050, 6080 */ /* MD_MSR_STPTH, MD_MSR_STCYC, MD_MSR_STCAL, MD_MSR_STMIF */

#define RTE_STOP_SEC_CODE
#include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
   MD_Rte_0342:  MISRA rule: 19.13
     Reason:     For efficient code the use of macros and the operator '##' is necessary.
     Risk:       The used compiler is not ANSI/ISO C89 compatible. No functional risk.
     Prevention: AUTOSAR is based on ANSI/ISO C89. Compatible compilers are required.

   MD_Rte_0777:  MISRA rule: 5.1
     Reason:     The defined RTE naming convention may result in identifiers with more than 31 characters. The compliance to this rule is under user's control.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects to be unique within the significant characters.

   MD_Rte_0779:  MISRA rule: 5.1
     Reason:     The defined RTE naming convention may result in identifiers with more than 31 characters. The compliance to this rule is under user's control.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects to be unique within the significant characters.

   MD_Rte_0781:  MISRA rule: 5.6
     Reason:     The name is being used as a structure/union member as well as being a label, tag or ordinary identifier.
                 The compliance to this rule is under user's control.
     Risk:       Ambiguous identifiers can lead to compiler errors / warnings.
     Prevention: Verified during compile time. If the compiler reports an error or warning, the user has to rename the objects leading to the violation.

   MD_Rte_3408:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_3447:  MISRA rule: 8.8
     Reason:     For the purpose of monitoring during calibration or debugging it is necessary to use non-static declarations.
                 This is covered in the MISRA C compliance section of the Rte specification.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Os:
     Reason:     This justification is used as summary justification for all deviations caused by the MICROSAR OS
                 which is for testing of the RTE. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

   MD_Rte_Qac:
     Reason:     This justification is used as summary justification for all deviations caused by wrong analysis tool results.
                 The used analysis tool QAC 7.0 sometimes creates wrong messages. Those deviations are no issues in the RTE code.
     Risk:       No functional risk.
     Prevention: Not required.

*/
