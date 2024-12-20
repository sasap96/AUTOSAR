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
 *          File:  Rte_CtSaInteriorLight.h
 *        Config:  C:/CanCollege/Autosar4/E3_Communication/MyECU.dpa
 *     SW-C Type:  CtSaInteriorLight
 *  Generated at:  Wed Apr 27 09:43:03 2016
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  Application header file for SW-C <CtSaInteriorLight> (Contract Phase)
 *********************************************************************************************************************/

/* double include prevention */
#ifndef _RTE_CTSAINTERIORLIGHT_H
# define _RTE_CTSAINTERIORLIGHT_H

# ifdef RTE_APPLICATION_HEADER_FILE
#  error Multiple application header files included.
# endif
# define RTE_APPLICATION_HEADER_FILE
# ifndef RTE_PTR2ARRAYBASETYPE_PASSING
#  define RTE_PTR2ARRAYBASETYPE_PASSING
# endif

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# define RTE_MULTI_INST_API

/* include files */

# include "Rte_CtSaInteriorLight_Type.h"
# include "Rte_DataHandleType.h"


/**********************************************************************************************************************
 * Component Data Structures and Port Data Structures
 *********************************************************************************************************************/

struct Rte_PDS_CtSaInteriorLight_PiLightDefectIoHwAb_R
{
  P2FUNC(Std_ReturnType, RTE_CODE, Call_ReadChannel) (P2VAR(IdtDioValueType, AUTOMATIC, RTE_CTSAINTERIORLIGHT_APPL_VAR) value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
};

struct Rte_PDS_CtSaInteriorLight_PiLightIoHwAb_R
{
  P2FUNC(Std_ReturnType, RTE_CODE, Call_WriteChannel) (IdtDioValueType value); /* PRQA S 0850 */ /* MD_MSR_19.8 */
};

struct Rte_PDS_CtSaInteriorLight_PiLightState_R
{
  P2FUNC(Std_ReturnType, RTE_CODE, Read_DeLightState) (P2VAR(IdtLightState, AUTOMATIC, RTE_CTSAINTERIORLIGHT_APPL_VAR)); /* PRQA S 0850 */ /* MD_MSR_19.8 */
};

struct Rte_CDS_CtSaInteriorLight
{
  /* Port API section */
  struct Rte_PDS_CtSaInteriorLight_PiLightDefectIoHwAb_R PpInteriorLightDefect;
  struct Rte_PDS_CtSaInteriorLight_PiLightIoHwAb_R PpInteriorLightIoHwAb;
  struct Rte_PDS_CtSaInteriorLight_PiLightState_R PpLightState;
  /* Vendor specific section */
};

# define RTE_START_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

extern CONSTP2CONST(struct Rte_CDS_CtSaInteriorLight, RTE_CONST, RTE_CONST) Rte_Inst_CtSaInteriorLight; /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define RTE_STOP_SEC_CONST_UNSPECIFIED
# include "MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

typedef P2CONST(struct Rte_CDS_CtSaInteriorLight, TYPEDEF, RTE_CONST) Rte_Instance;


/**********************************************************************************************************************
 * Init Values for unqueued S/R communication (primitive types only)
 *********************************************************************************************************************/

# define Rte_InitValue_PpLightState_DeLightState (0U)



/**********************************************************************************************************************
 * Rte_Read_<p>_<d> (explicit S/R communication with isQueued = false)
 *********************************************************************************************************************/
# define Rte_Read_PpLightState_DeLightState(self, data) ((self)->PpLightState.Read_DeLightState(data)) /* PRQA S 3453 */ /* MD_MSR_19.7 */


/**********************************************************************************************************************
 * Rte_Call_<p>_<o> (C/S invocation)
 *********************************************************************************************************************/
# define Rte_Call_PpInteriorLightDefect_ReadChannel(self, arg1) ((self)->PpInteriorLightDefect.Call_ReadChannel(arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */
# define Rte_Call_PpInteriorLightIoHwAb_WriteChannel(self, arg1) ((self)->PpInteriorLightIoHwAb.Call_WriteChannel(arg1)) /* PRQA S 3453 */ /* MD_MSR_19.7 */




# define CtSaInteriorLight_START_SEC_CODE
# include "CtSaInteriorLight_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 *
 * Runnable Entity Name: RCtSaInteriorLightSwitchLight
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <DeLightState> of PortPrototype <PpLightState>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_PpLightState_DeLightState(Rte_Instance self, IdtLightState *data)
 *
 * Client/Server Interfaces:
 * =========================
 *   Server Invocation:
 *   ------------------
 *   Std_ReturnType Rte_Call_PpInteriorLightDefect_ReadChannel(Rte_Instance self, IdtDioValueType *value)
 *     Synchronous Server Invocation. Timeout: None
 *   Std_ReturnType Rte_Call_PpInteriorLightIoHwAb_WriteChannel(Rte_Instance self, IdtDioValueType value)
 *     Synchronous Server Invocation. Timeout: None
 *
 *********************************************************************************************************************/

# define RTE_RUNNABLE_RCtSaInteriorLightSwitchLight RCtSaInteriorLightSwitchLight
FUNC(void, CtSaInteriorLight_CODE) RCtSaInteriorLightSwitchLight(Rte_Instance self); /* PRQA S 0850 */ /* MD_MSR_19.8 */

# define CtSaInteriorLight_STOP_SEC_CODE
# include "CtSaInteriorLight_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* _RTE_CTSAINTERIORLIGHT_H */
