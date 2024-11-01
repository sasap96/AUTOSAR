/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *          File:  CtSaDoor.c
 *        Config:  C:\Users\nituser\Desktop\Autosar homework\M2\E1\_E1_SoftwareComponents/"C:/Users/nituser/Desktop/Autosar homework/M2/E1/_E1_SoftwareComponents/MyECU.dpa"
 *     SW-C Type:  CtSaDoor
 *  Generated at:  Wed Oct 23 09:38:43 2024
 *
 *     Generator:  MICROSAR RTE Generator Version 4.9.0
 *                 RTE Core Version 1.9.0
 *       License:  Unlimited license CBD0000000 for N/A
 *
 *   Description:  C-Code implementation template for SW-C <CtSaDoor>
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

#include "Rte_CtSaDoor.h"


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


#define CtSaDoor_START_SEC_CODE
#include "CtSaDoor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */

/**********************************************************************************************************************
 *
 * Runnable Entity Name: RCtSaDoorReadDoor
 *
 *---------------------------------------------------------------------------------------------------------------------
 *
 * Executed if at least one of the following trigger conditions occurred:
 *   - triggered on TimingEvent every 200ms
 *
 **********************************************************************************************************************
 *
 * Output Interfaces:
 * ==================
 *   Explicit S/R API:
 *   -----------------
 *   Std_ReturnType Rte_Write_PpDooState_DeDoorState(Rte_Instance self, IdtDoorState data)
 *
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of documentation area >>                  DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtSaDoorReadDoor_doc
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of documentation area >>                    DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/

FUNC(void, CtSaDoor_CODE) RCtSaDoorReadDoor(Rte_Instance self) /* PRQA S 0850 */ /* MD_MSR_19.8 */
{
/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << Start of runnable implementation >>             DO NOT CHANGE THIS COMMENT!
 * Symbol: RCtSaDoorReadDoor
 *********************************************************************************************************************/
    /*
    * Hard code value to true, then send this data to using provider port.
    * This function is triggered every 200ms. Since this is set to true,
    * this means that SaLight will be also triggered every 200ms.
    */
    IdtDoorState data = CDoorClosed;
    Rte_Write_PpDooState_DeDoorState(self, data);

/**********************************************************************************************************************
 * DO NOT CHANGE THIS COMMENT!           << End of runnable implementation >>               DO NOT CHANGE THIS COMMENT!
 *********************************************************************************************************************/
}


#define CtSaDoor_STOP_SEC_CODE
#include "CtSaDoor_MemMap.h" /* PRQA S 5087 */ /* MD_MSR_19.1 */


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
