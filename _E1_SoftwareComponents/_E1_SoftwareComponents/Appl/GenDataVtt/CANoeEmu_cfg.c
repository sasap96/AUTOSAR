/**********************************************************************************************************************
 *  DO NOT EDIT!!! This file is automatically generated.
 *  -------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  Copyright (c) 2013 by Vector Informatik GmbH. All rights reserved.
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CANoeEmu_cfg.c
 *  ECU-Instance:  MyECU
 *  Generated at:  2024-10-23  09:37:52
 *
 *     Generator:  VTT Visual Studio Project Generator (VttVsProjectGenerator.exe)
 *
 *   Description:  CANoeEmu configuration file
 *********************************************************************************************************************/


/*******************************************************************************
 * Includes
 *******************************************************************************/

#include "CANoeAPI.h"
#include "main.h"
#include "Vtt_Hook.h"
#include "Vtt_Rte.h"
#include "VttCntrl_Base.h"
#include "VttCntrl_Can.h"
#include "VttCntrl_Det.h"
#include "VttCntrl_Dio.h"
#include "VttCntrl_Fls.h"
#include "VttCntrl_Mcu.h"
#include "osek.h"


/*******************************************************************************
 * Global state change handler of CANoeEmu. It propagates state changes to the 
 * configured modules.
 *******************************************************************************/

void CANoeAPI_OnStateChange(uint8 action, uint8 oldState, uint8 newState)
{
  VttCan_OnStateChange(action, oldState, newState);
  VttCntrl_Base_OnStateChange(action, oldState, newState);
  VttCntrl_Det_OnStateChange(action, oldState, newState);
  VttDio_OnStateChange(action, oldState, newState);
  VttFls_OnStateChange(action, oldState, newState);
  VttHook_OnStateChange(action, oldState, newState);
  VttMcu_OnStateChange(action, oldState, newState);
  VttRte_OnStateChange(action, oldState, newState);
}


/*******************************************************************************
 * Init hook function of CANoeEmu.
 *******************************************************************************/

void CANoeAPI_InitHook(void)
{
#if (CANOEAPI_VERSION >= 228)
  CANoeAPI_SetNameOfEcuInstance("MyECU");
  CANoeAPI_SetNameOfWriteTab("VTT MyECU");
  CANoeAPI_SetRootNameSpaceOfSystemVariables("VTT::MyECU");
  CANoeAPI_SetVariantName("");
  CANoeAPI_MapChannel("CAN", CANOEAPI_BUSTYPE_CAN, 0);
  CANoeAPI_FreezeChannelMapping();
#else
  #pragma message ("CANoeEmu Library is older than version 2.28, channel mapping from VTT tool is ignored!")
  CANoeAPI_SetNameOfEcuInstance("MyECU");
  CANoeAPI_SetNameOfWriteTab("VTT MyECU");
  CANoeAPI_SetRootNameSpaceOfSystemVariables("VTT::MyECU");
#endif
  

  {
    unsigned int major, minor, patch;
    CANoeAPI_GetLibraryVersion(&major, &minor, &patch);
    if (CANOEEMU_MAJOR_VERSION!=major || CANOEEMU_MINOR_VERSION!=minor || CANOEEMU_PATCH_VERSION!=patch)
    {
      CANoeAPI_WriteString("Version Conflict Error: Header file and library of CANoeEmu are inconsistent!");
      return;
    }
  }

  CANoeAPI_SetMainFunction(&main);
  CANoeAPI_ConfigureInterruptController(oskNumberOfInterruptSources,32);
  CANoeAPI_SetEcuStateHandler(&CANoeAPI_OnStateChange);
#if (CANOEAPI_VERSION >= 213)
  CANoeAPI_SetInitValueOfPowerSupply(1);
  CANoeAPI_SetExecutionMode(CANOEAPI_EXECUTE_PREEMPTIVE_MULTITHREAD);
#endif
#if (CANOEAPI_VERSION >= 217)
  // Configure Timing parameters of the emulation
  CANoeAPI_ConfigureTiming(CANOEAPI_TIMING_TICKDURATION, 1000);
  CANoeAPI_ConfigureTiming(CANOEAPI_TIMING_PREISR, 1);
  CANoeAPI_ConfigureTiming(CANOEAPI_TIMING_POSTISR, 1);
  CANoeAPI_ConfigureTiming(CANOEAPI_TIMING_PRETASK, 1);
  CANoeAPI_ConfigureTiming(CANOEAPI_TIMING_TASKSWITCH, 1);
#endif
#if (CANOEAPI_VERSION >= 218)
  CANoeAPI_ReInitializeSectionOnReset( ".vbss");
  CANoeAPI_ReInitializeSectionOnReset( ".vdata");
#endif
#if (CANOEAPI_VERSION >= 222)
  CANoeAPI_ConfigureNumberOfCores(1);
  CANoeAPI_ConfigureNumberOfNonMaskableInterruptLevels(0);
  CANoeAPI_ConfigureNumberOfSystemTimers(1);
  CANoeAPI_ConfigureNumberOfHRTimers(0);
#endif
#if (CANOEAPI_VERSION >= 231)
  CANoeAPI_ConfigureCoreStartup(0, CANOEAPI_CORE_AUTOSTART);
#endif
}