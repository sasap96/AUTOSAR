/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtApMySwc.c
 *        Config:  C:\Users\nituser\Desktop\Autosar homework\M2\E1\Generators\Rte/"C:/Users/nituser/Desktop/Autosar homework/M2/E1/_E1_SoftwareComponents/MyECU.dpa"
 *     SW-C Type:  CtApMySwc
 *  Generated at:  Wed Oct 23 09:38:42 2024
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  C-Code implementation template for SW-C <CtApMySwc>
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of version logging area >>                DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/* PRQA S 0777, 0779 EOF */ /* MD_Rte_0777, MD_Rte_0779 */

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of version logging area >>                  DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *
 * AUTOSAR Modelling Object Descriptions
 *
 **********************************************************************************************************************
 *
 * Data Types:
 * ===========
 * IdtDoorState
 *   boolean has the value space required to support the mathematical concept of 
 *      binary-valued logic: {true, false}.
 *
 *********************************************************************************************************************/

#include "Rte_CtApMySwc.h"


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of include and declaration area >>        DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of include and declaration area >>          DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *
 * Used AUTOSAR Data Types
 *
 **********************************************************************************************************************
 *
 * Primitive Types:
 * ================
 * boolean: Boolean (standard type)
 *
 * Enumeration Types:
 * ==================
 * IdtDoorState: Enumeration of integer in interval [0...1] with enumerators
 *   CMDOORSTATE_DOORCLOSED (0U)
 *   CMDOORSTATE_DOOROPEN (1U)
 *
 *********************************************************************************************************************/


#define CtApMySwc_START_SEC_CODE
#include "CtApMySwc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RCtApMySwcCode
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on DataReceivedEvent for DataElementPrototype <DeDoorState> of PortPrototype <PpDoorStateFrontLeft>
 *   - triggered on DataReceivedEvent for DataElementPrototype <DeDoorState> of PortPrototype <PpDoorStateFrontRight>
 *
 **********************************************************************************************************************
 *
 * Input Interfaces:
 * =================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Read_PpDoorStateFrontRight_DeDoorState(IdtDoorState *data)
 *
 *   Implicit S/R API:
 *   -----------------
 *   IdtDoorState Rte_IRead_RCtApMySwcCode_PpDoorStateFrontLeft_DeDoorState(void)
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpLightStateFront_DeLightState(IdtDoorState data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtApMySwcCode_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtApMySwc_CODE) RCtApMySwcCode(void) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtApMySwcCode
 *********************************************************************************************************************/
    IdtLightState light_state = CLightOff;
    IdtDoorState right_door_state = CDoorClosed;
    IdtDoorState left_door_state = CDoorClosed;

    /* Once data is received on PpDoorState (since it is triggered by data receive event)
     * RCtApMySwcCode will be called, and execute code.
     */
    Rte_Read_PpDoorStateFrontRight_DeDoorState(&right_door_state);
    left_door_state = Rte_IRead_RCtApMySwcCode_PpDoorStateFrontLeft_DeDoorState();
    /* Once state is read, process and write light. */
    if ((right_door_state == TRUE) || (left_door_state == TRUE))
    {
        light_state = TRUE;
    }
    else
    {
        light_state = FALSE;
    }
    Rte_Write_PpLightStateFront_DeLightState(light_state);


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CtApMySwc_STOP_SEC_CODE
#include "CtApMySwc_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of function definition area >>            DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of function definition area >>              DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of removed code area >>                   DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of removed code area >>                     DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

/**********************************************************************************************************************
 MISRA 2004 violations and justifications
 *********************************************************************************************************************/

/* module specific MISRA deviations:
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

*/
