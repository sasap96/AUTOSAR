/* MISRA RULE 19.15 VIOLATION: The file tcb.h is intentionally included multiple times. 
 * The file consists of multiple parts which are used only if the including file has 
 * set a certain define macro (osdPreTCB/osdPostTCB). Each part has a separate double 
 * include preventer. Typical MISRA checkers will not be able to find these multiple 
 * double include preventers.
 */
/* PRQA S 0883 EOF */
/* file: tcb.h, automatically generated by gencanoe.exe, Version: 5.02 */
/* configuration read from: C:\Users\nituser\AppData\Local\Temp\Cfg_Gen-1729668396287-7\OsProxyFiles-1729669053820-0\Os_ActiveEcuC.arxml.oil */
/* generation at  : Wed Oct 23 09:37:37 2024 */
/* Unlimited license 1234567890 for CANoeEmu Generic License */
/* Implementation: CANoeOsekEmu */
/* Version of general code: 5.31 */

#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif
#define osdVrmGenMajRelNum 5
#define osdVrmGenMinRelNum 2
#if defined USE_QUOTE_INCLUDES
 #include "vrm.h"
#else
 #include <vrm.h>
#endif

#if osdPreTCB
#ifndef _PRE_TCB_H
#define _PRE_TCB_H

#define osdCompiler osdCompilerMicrosoftVisualC

#define osdByteSize 8U
#define osdLib 1
#define CC ECC2

#define osdSC SC1

#define osdSupportEnableDisableIntSource 0

#define STATUS_LEVEL EXTENDED_STATUS

#define osdFullPreempt 0
#define osdMixedPreempt 1
#define osdNonPreempt 0

#define osdNumberOfAllTasks 4
#define osdNumberOfBasicTasks 2
#define osdNumberOfExtendedTasks 2
#define osdTimingProtectionUsed 0
#define osdNumberOfPriorities 4
#define osdNumberOfAllResources 1
#define osdNumberOfTaskResources 1
#define osdNumberOfInterruptResources 0
#define osdNumberOfInternalResources 0
#define osdResAccessMaskBits 32
#define osdNumberOfAlarms 4
#define osdNumberOfVarAlarms 4
#define osdNumberOfVarHeapAlarms 0
#define osdNumberOfStatHeapAlarms 0
#define osdNumberOfAlarmCallback 0
#define osdNumberOfAlarmSetEvent 4
#define osdNumberOfAlarmActivateTask 0
#define osdNumberOfAlarmIncrementCounter 0
#define osdAlarmsOnSystemTimer 1
#define osdAlarmsOnHiResSystemTimer 0
#define osdUseGeneratedFastAlarm 
#define osdUseHeap 0
#define osdNumberOfCounters 1
#define osdNumberOfSWCounters 0
#define osdUseCounterAPI 1
#define osdNumberOfScheduleTables 0
#define osdNumberOfHiResSchedTabs 0
#define osdScheduleTablesOnSystemTimer 0
#define osdScheduleTableSyncUsed 0
#define osdNumberOfSTExpiryPoints 0
#define osdNumberOfSTSetEvent 0
#define osdNumberOfSTActivateTask 0
#define osdNumberOfSTEntries 0
#define osdNumberOfApplications 0
#define osdNumberOfTrustedFunctions 0

#define osdNumberOfNonTrustedFunctions 0

#define osdNumberOfCat2ISRs 5
#define osdNumberOfISRs 5
#define osdTypeHeaderInclude 0

#define osdStackCheck 0
#define osdStackUsageMeasurement 0

#define osdEnableAssertions 1

#define osdORTIDebug 0
#define osdORTIVersion  not used anymore!
#define osdORTIStdVersion 200
#define osdORTIEnabled 0

#define osdEventMaskTypeSize 4

#define osdNumberOfAppModes 2

#define OSDEFAULTAPPMODE 0x01

#define osdGetServiceIdMacros 0
#define osdParameterAccessMacros 0

#define osdTimingMeasurement 0
#define osdProtectAndMeasureAll 0
#define osdAsSelected 0
#define osdOnlyMeasureAll 0

#define osdProtReactKillTaskIsrAllowed  0
#define osdProtReactKillApplAllowed     0
#define osdProtReactKillApplRestAllowed 0
#define osdMultiStack 0
#define osdSingleStackOptimized 1
#define osdSingleStackOptimizedCS 2
#define osdSingleStackOsek 3
#define osdStackModel osdMultiStack


/* CANoeEmu specific defines */
#define osdResAccessMaskBits 32
#define osdUserDefinedSystemTimer 0
#define osdUseHighResolutionTimer 0
#define osdScheduleTableSyncUsed 0
#define osdTimingProtectionUsed  0
#define osdKillTaskIsrPossible   0
#define osdNumberOfPeripheralRegions 0U
#define CORRECTION_FACTOR_VTTOS_DIVIDER ((double)1)
#define osdSystemCounterNeeded 1
#define osdNumberOfReservedCANoeEmuTasks 1

/* ---------------------------------------- */
#define OSTICKDURATION 1000000UL   /* expected duration of a system counter tick in nanoseconds */

/* max(number of priority,number of tasks) */

#define osdRTSize 1

#define osdSysErrorHook 0
#define osdErrorHook 0
#define osdPreTaskHook 0
#define osdPostTaskHook 0
#define osdStartupHook 0
#define osdShutdownHook 1
#define osdProtectionHook 0

#if osdProtectionHook

 #if (osdTimingProtectionUsed && osdProtReactKillTaskIsrAllowed)
  #define osdKillTaskIsrPossible 1
 #endif /*(osdTimingProtectionUsed && osdProtReactKillTaskIsrAllowed)*/

 #if ((osdSC == SC4) && (defined osdTimingProtectionUsed) && (osdProtReactKillApplAllowed || osdProtReactKillApplRestAllowed))
  #ifndef osdKillTaskIsrPossible
   #define osdKillTaskIsrPossible 1
  #endif
  #define osdKillApplPossible 1
 #endif /* (osdSC == SC4) && (defined osdTimingProtectionUsed) && (osdProtReactKillApplAllowed || osdProtReactKillApplRestAllowed))*/

#endif /* osdProtectionHook */

#if ((osdSC == SC3) || (osdSC == SC4)) && (!defined osdTerminateApplicationNotUsed)
 #ifndef osdKillTaskIsrPossible /* prevent from double-definition */
  #define osdKillTaskIsrPossible 1
 #endif
 #ifndef osdKillApplPossible
  #define osdKillApplPossible 1
 #endif
#endif /* ((osdSC == SC3) || (osdSC == SC4)) */

#ifndef osdKillTaskIsrPossible
 #define osdKillTaskIsrPossible 0
#endif

#ifndef osdKillApplPossible
 #define osdKillApplPossible 0
#endif

#define osdNumberOfProcesses (osdNumberOfAllTasks+osdNumberOfCat2ISRs)

#endif /* _PRE_TCB_H (double include preventer) */
#endif /* osdPreTCB */

/* Start of invariant part */
#if osdPostTCB
/* (POST because types have to be defined in OSEK.H) */

#ifndef OS_TCB_POST_INVARIANT /* double include preventer */
#define OS_TCB_POST_INVARIANT

   osqRAM0 extern osqRAM1 osqRAM2 osPrioFlagType osqRAM3 osQReadyPrios[];

   extern osqTcbRAM1 osqTcbRAM2 EventMaskType osqTcbRAM3 osTcbWaitEventMask[];


#if ((osdSC == SC3) || (osdSC == SC4))
   extern osqTcbRAM1 osqTcbRAM2 ApplicationStateType osqTcbRAM3 osApplicationState [];
#endif

#if (CC==BCC2) || (CC==ECC2)
      extern osqTcbRAM1 osqTcbRAM2 osQEntryCountType osqTcbRAM3 osQReadyTaskHead[];
      extern osqTcbRAM1 osqTcbRAM2 osQEntryCountType osqTcbRAM3 osQReadyTaskTail[];
      extern osqTcbRAM1 volatile osqTcbRAM2 TickType osqTcbRAM3 osCounter[];

     osqROM0 extern osqROM1 const osqROM2 osQEntryCountType osqROM3 oskQMaxActivations[];
     osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskCounterMaxAllowedValue[];
     osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskCounterTicksPerBase[];
     osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskCounterMinCycle[];

     osqROM0 extern osqROM1 const osqROM2 osuint8 osqROM3 oskAlarmCounterRef[];

#else
      extern osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osQReadyTask[];
#endif


   osqROM0 extern osqROM1 const osqROM2 osTaskFlagType osqROM3 oskTcbTaskFlags[];
   extern osqTcbRAM1 osqTcbRAM2 EventMaskType osqTcbRAM3 osTcbSetEventMask[];

#if ((CC == BCC2) || (CC == ECC2))
      extern osqROM0 osqPTcbRAM1 osqPTcbRAM2 TaskType osqPTcbRAM3 * osqROM1 const osqROM2 osqROM3 oskQActivationQueues[];

      extern osqTcbRAM1 osqTcbRAM2 osActivationCountType osqTcbRAM3 osTcbActivationCount[];
#endif

   extern osqTcbRAM1 osqTcbRAM2 osStackPtrType osqTcbRAM3 osTcbSP[];
   extern osqTcbRAM1 osqTcbRAM2 osTaskStateType osqTcbRAM3 osTcbTaskState[];
   #if osdORTIDebug
   extern osqTcbRAM1 osqTcbRAM2 osPrioType osqTcbRAM3 osTcbActualPrio[];
   extern osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbORTIServiceId[];
   #endif
   #if STATUS_LEVEL == EXTENDED_STATUS
   #if (osdNumberOfInternalResources > 0) || (osdNumberOfInterruptResources > 0)
    extern osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbResourceCounter[];
   #else
     #if osdLib
      extern osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbResourceCounter[];
     #endif
   #endif
   #endif

   osqROM0 extern osqROM1 const osqROM2 osPrioType osqROM3 oskTcbHomePrio[]; 
   osqROM0 extern osqROM1 const osqROM2 osActivationCountType osqROM3 oskTcbAllowedActivations[];

   osqROM0 extern osqROM1 const osqROM2 osPrioFlagType osqROM3 oskTcbReadyPrioMask[];
   
   osqROM0 extern osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskTcbReadyPrioOffset[];

/* Resources */

   extern osqTcbRAM1 osqTcbRAM2 osPrioType osqTcbRAM3 osResSavedPrio[];
   #if STATUS_LEVEL == EXTENDED_STATUS && ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))
      extern osqTcbRAM1 osqTcbRAM2 osResCounterType osqTcbRAM3 osResOccupationCounter[];
   #endif
   #if ((STATUS_LEVEL == EXTENDED_STATUS) && osdEnableAssertions && ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))) || osdORTIDebug
      extern osqTcbRAM1 osqTcbRAM2 TaskType osqTcbRAM3 osResActualTask[];
   #endif
   #if STATUS_LEVEL == EXTENDED_STATUS && ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))
   #if (osdNumberOfInternalResources > 0) || (osdNumberOfInterruptResources > 0)
   extern osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osTcbResourceCounter[];
   #endif
   #endif
   
   osqROM0 extern osqROM1 const osqROM2 osPrioType osqROM3 oskResCeilingPrio[];
   osqROM0 extern osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskResCeilingPrioOffset[];
   osqROM0 extern osqROM1 const osqROM2 osPrioFlagType osqROM3 oskResCeilingPrioMask[];

#if (osdNumberOfInternalResources > 0)
   osqROM0 extern osqROM1 const osqROM2 osPrioType osqROM3 oskResInternalCeilingPrio[];
   osqROM0 extern osqROM1 const osqROM2 osPrioFlagType osqROM3 oskResInternalCeilingPrioMask[];
   osqROM0 extern osqROM1 const osqROM2 osPrioOffsetType osqROM3 oskResInternalCeilingPrioOffset[];
#endif
/* alarms */

   extern osqTcbRAM1 osqTcbRAM2 TickType osqTcbRAM3 osAlarmTime[];
   extern osqTcbRAM1 osqTcbRAM2 osuint8 osqTcbRAM3 osAlarmActivated[];
   extern osqTcbRAM1 osqTcbRAM2 osHeapType osqTcbRAM3 osAlarmHeap[];    /* Minimum Heap */

   osqROM0 extern osqROM1 const osqROM2 AlarmBaseType osqROM3 oskAlarmDefinitions;

   extern osqTcbRAM1 osqTcbRAM2 TickType osqTcbRAM3 osAlarmCycleTime[];

   osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskStaticAlarmTime[];
   osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskStaticAlarmCycleTime[];

   osqROM0 extern osqROM1 const osqROM2 TaskType osqROM3 oskAlarmTask[];
   osqROM0 extern osqROM1 const osqROM2 EventMaskType osqROM3 oskAlarmEvent[];
      osqROM0 extern osqROM1 const osqROM2 osuint8 osqROM3 oskAlarmAction[];
   #if (osdNumberOfAlarmCallback > 0)
      osqROM0 extern osAlarmCallbackType osqROM1 const osqROM2 osqROM3 oskAlarmCallback[];
   #endif
   #if (osdNumberOfAlarmIncrementCounter > 0)
     osqROM0 extern osqROM1 const osqROM2 CounterType osqROM3 oskAlarmIncrementCounterID[];
   #endif

/* schedule tables */

#if (osdNumberOfScheduleTables > 0)
   osqRAM0 extern osqRAM1 osqRAM2 osSTIndexType osqRAM3 osSTCurrentIndex[];
   osqRAM0 extern osqRAM1 osqRAM2 osSTOffsetType osqRAM3 osSTCounter[];
   osqRAM0 extern osqRAM1 osqRAM2 ScheduleTableStatusType osqRAM3 osSTState[];
   osqRAM0 extern osqRAM1 osqRAM2 ScheduleTableType osqRAM3 osSTNextTable[];
   osqRAM0 extern osqRAM1 osqRAM2 osuint8 osqRAM3 osHasBeenNexted[];

   osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskAutostartScheduleTableOffset[];
   osqROM0 extern osqROM1 const osqROM2 osuint8 osqROM3 oskScheduleTableAutoStart[];
   osqROM0 extern osqROM1 const osqROM2 CounterType osqROM3 oskCounterOfST[];
   osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskSTMaxAllowed[];
   osqROM0 extern osqROM1 const osqROM2 osSTIndexType osqROM3 oskSTStartIndex[];
   osqROM0 extern osqROM1 const osqROM2 osSTOffsetType osqROM3 oskScheduleTableInitialOffset[];
   #if ((osdScheduleTableSyncUsed != 0) || (STATUS_LEVEL == EXTENDED_STATUS))
      osqROM0 extern osqROM1 const osqROM2 osuint8 osqROM3 oskSTSyncKind[];
   #endif
#endif

#if ((defined(osdTestMacros)) || (osdLib) || (osdSC== SC3) || (osdSC== SC4))
   #define osPreTaskHook  osInterPreTaskHook
   #define osPostTaskHook osInterPostTaskHook
#else
   #define osPreTaskHook  PreTaskHook
   #define osPostTaskHook PostTaskHook
#endif

#if osdLib
   #define osrRTSize                     oskRTSize 
   #define osrNumberOfPriorities         oskNumberOfPriorities
   #define osrNumberOfAppModes           oskNumberOfAppModes
   #define osrNumberOfAllTasks           oskNumberOfAllTasks
   #define osrNumberOfAllResources       oskNumberOfAllResources
   #define osrNumberOfTaskResources      oskNumberOfTaskResources
   #define osrNumberOfInterruptResources oskNumberOfInterruptResources
   #define osrNumberOfInternalResources  oskNumberOfInternalResources
   #define osrNumberOfExtendedTasks      oskNumberOfExtendedTasks
   #define osrNumberOfAlarms             oskNumberOfAlarms
   #define osrNumberOfVarAlarms          oskNumberOfVarAlarms
   #define osrNumberOfVarHeapAlarms      oskNumberOfVarHeapAlarms
   #define osrNumberOfStatHeapAlarms     oskNumberOfStatHeapAlarms
   #define osrNumberOfScheduleTables     oskNumberOfScheduleTables
   #define osrSystemTimer                oskSystemTimer
   #define osrNumberOfCounters           oskNumberOfCounters

   extern const osRTSizeType               oskRTSize;
   extern const osAppModeIndexType         oskNumberOfAppModes;
   extern const osTaskIndexType            oskNumberOfAllTasks;
   extern const osTaskIndexType            oskNumberOfExtendedTasks;
   extern const osPrioType                 oskNumberOfPriorities;
   extern const osResourceIndexType        oskNumberOfAllResources;
   extern const osResourceIndexType        oskNumberOfTaskResources;
   extern const osResourceIndexType        oskNumberOfInterruptResources;
   extern const osResourceIndexType        oskNumberOfInternalResources;

   extern const osAlarmIndexType           oskNumberOfAlarms;
   extern const osAlarmIndexType           oskNumberOfVarAlarms;
   extern const osAlarmIndexType           oskNumberOfVarHeapAlarms;
   extern const osAlarmIndexType           oskNumberOfStatHeapAlarms;

   extern const ScheduleTableType          oskNumberOfScheduleTables;
   extern const CounterType                oskSystemTimer;
   extern const CounterType                oskNumberOfCounters;

   extern const TickType oskMaxAllowedValue;
   extern const TickType oskTicksPerBase;
   extern const TickType oskMinCycle;
   extern const osuint8 oskAlarmAutoStart[];

   extern const osuint8 oskTcbAutoStart[];


   extern const osVersionVariantCodingType oskLibVersionVariant;
   /* in library variant provide prototypes for interHook-functions */
   extern void osInterPreTaskHook(void);
   extern void osInterPostTaskHook(void);
   extern void osInterStartupHook(void);
   extern void osInterShutdownHook(StatusType Error);
   extern void osInterErrorHook(StatusType Error);
   extern void osInterCOMErrorHook(StatusType Error);

#else
   #define osrRTSize                      osdRTSize 
   #define osrNumberOfPriorities          osdNumberOfPriorities 
   #define osrNumberOfAppModes            osdNumberOfAppModes
   #define osrNumberOfAllTasks            osdNumberOfAllTasks
   #define osrNumberOfAllResources        osdNumberOfAllResources
   #define osrNumberOfTaskResources       osdNumberOfTaskResources
   #define osrNumberOfInterruptResources  osdNumberOfInterruptResources
   #define osrNumberOfInternalResources   osdNumberOfInternalResources
   #define osrNumberOfExtendedTasks       osdNumberOfExtendedTasks
   #define osrNumberOfAlarms              osdNumberOfAlarms
   #define osrNumberOfVarAlarms           osdNumberOfVarAlarms
   #define osrNumberOfVarHeapAlarms       osdNumberOfVarHeapAlarms
   #define osrNumberOfStatHeapAlarms      osdNumberOfStatHeapAlarms
   #define osrNumberOfScheduleTables      osdNumberOfScheduleTables
   #define osrSystemTimer                 SystemTimer
   #define osrNumberOfCounters            osdNumberOfCounters
   /* in source code variant map hook routines directly to user functions */
#if ((osdSC== SC1) || (osdSC== SC2))
   #define osInterStartupHook             StartupHook
   #define osInterErrorHook               ErrorHook
   #define osInterShutdownHook            ShutdownHook
   #define osInterCOMErrorHook            COMErrorHook
#else
   extern void osInterStartupHook(void);
   extern void osInterErrorHook(StatusType Error);
   extern void osInterShutdownHook(StatusType Error);
   extern void osInterCOMErrorHook(StatusType Error);
#endif
#endif

#endif /* ifndef OS_TCB_POST_INVARIANT */ /* double include preventer */
#endif /* osdPostTCB */
/* End of invariant part */
#if osdPostTCB
#ifndef _POST_TCB_H
#define _POST_TCB_H


/* task start functions (only for call tree) */
void SchM_Taskfunc(void);
void Init_Taskfunc(void);
void IO_Taskfunc(void);
void My_Taskfunc(void);

/* Tasks */
#define SchM_Task ((TaskType)0)
#define IO_Task ((TaskType)1)
#define Init_Task ((TaskType)2)
#define My_Task ((TaskType)3)


#if (osdKillTaskIsrPossible || (osdSC== SC3) || (osdSC== SC4))
#if (osdNumberOfAllTasks > 0)
   extern osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osTcbLockedResource[osdNumberOfAllTasks];
#else
   extern osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osTcbLockedResource[1];
#endif
#endif
/* Resources */

#define OsResource ((ResourceType)0)


#if (STATUS_LEVEL == EXTENDED_STATUS) && osdEnableAssertions
 #if ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed)))
osqROM0 extern osqROM1 const osqROM2 osResAccessMaskType osqROM3 oskResAccessMask[osdNumberOfAllResources][1];


 #endif /* ((!defined(osdGetResourceNotUsed)) || (!defined(osdReleaseResourceNotUsed))) */
#endif /* (STATUS_LEVEL == EXTENDED_STATUS) && osdEnableAssertions */

#if (osdKillTaskIsrPossible || (osdSC == SC3) || (osdSC == SC4))
#if (osdNumberOfAllResources > 0)
   extern osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osResNextLockedResource[osdNumberOfAllResources];
#else
   extern osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osResNextLockedResource[1];
#endif
#endif

/* Counter */

#define SystemTimer ((CounterType) 0)

osqROM0 extern osqROM1 const osqROM2 TickType osqROM3 oskCounterMaxAllowedValue[1];
#define OSMAXALLOWEDVALUE_SystemTimer OSMAXALLOWEDVALUE
#define OSTICKSPERBASE_SystemTimer OSTICKSPERBASE
#define OSMINCYCLE_SystemTimer OSMINCYCLE
#define OSNANOSECONDSPERTICK_SystemTimer OSNANOSECONDSPERTICK





/* Time constants for counter SystemTimer */

/* Events */

#define Rte_Ev_Cyclic2_SchM_Task_0_10ms ((EventMaskType)(0x00000001))/* AUTO */
#define Rte_Ev_Cyclic2_SchM_Task_0_20ms ((EventMaskType)(0x00000002))/* AUTO */
#define Rte_Ev_Run_Fee_Fee_MainFunction ((EventMaskType)(0x00000004))/* AUTO */
#define Rte_Ev_Cyclic_IO_Task_0_200ms ((EventMaskType)(0x00000001))/* AUTO */
#define Rte_Ev_Run_CpSaInteriorLightFront_RCtSaInteriorLightSwitchLight ((EventMaskType)(0x00000002))/* AUTO */
/* Alarms */

/* Maximum possible allowed value of the system counter in ticks */
#define OSMAXALLOWEDVALUE (0xffffffffUL)

/* Minimum allowed number of ticks for a cyclic alarm */
#define OSMINCYCLE 1

/* Number of ticks required to reach specific unit of the system counter */
#define OSTICKSPERBASE 1

/* tick time duration in nanoseconds */
#define OSNANOSECONDSPERTICK 1000000

#define USEC(x) ( ((TickType)(((((osuint32)(x))) + ( 1000UL  / 2 )) / 1000UL ))) /*	valid range for x: 0..4294966795	*/
#define MSEC(x) ( ((TickType)(((((osuint32)(x))))))) /*	valid range for x: 0..4294967295	*/
#define SEC(x) ( ((TickType)(((((osuint32)(x)) * 1000UL ))))) /*	valid range for x: 0..4294967	*/
#define OS_NS2TICKS_SystemTimer(x) ( ((TickType)(((((osuint32)(x))) + ( 1000000UL  / 2 )) / 1000000UL ))) /*	valid range for x: 0..4294467295	*/
#define OS_US2TICKS_SystemTimer(x) ( ((TickType)(((((osuint32)(x))) + ( 1000UL  / 2 )) / 1000UL ))) /*	valid range for x: 0..4294966795	*/
#define OS_MS2TICKS_SystemTimer(x) ( ((TickType)(((((osuint32)(x))))))) /*	valid range for x: 0..4294967295	*/
#define OS_SEC2TICKS_SystemTimer(x) ( ((TickType)(((((osuint32)(x)) * 1000UL ))))) /*	valid range for x: 0..4294967	*/
#define OS_TICKS2NS_SystemTimer(x) ( ((PhysicalTimeType)(((((osuint32)(x)) * 1000000UL ))))) /*	valid range for x: 0..4294	*/
#define OS_TICKS2US_SystemTimer(x) ( ((PhysicalTimeType)(((((osuint32)(x)) * 1000UL ))))) /*	valid range for x: 0..4294967	*/
#define OS_TICKS2MS_SystemTimer(x) ( ((PhysicalTimeType)(((((osuint32)(x))))))) /*	valid range for x: 0..4294967295	*/
#define OS_TICKS2SEC_SystemTimer(x) ( ((PhysicalTimeType)(((((osuint32)(x))) + ( 1000UL  / 2 )) / 1000UL ))) /*	valid range for x: 0..4294966795	*/


/* Alarms */
#define Rte_Al_TE2_SchM_Task_0_10ms ((AlarmType)0)
#define Rte_Al_TE2_SchM_Task_0_20ms ((AlarmType)1)
#define Rte_Al_TE_Fee_Fee_MainFunction ((AlarmType)2)
#define Rte_Al_TE_IO_Task_0_200ms ((AlarmType)3)


osqROM0 extern osqROM1 const osqROM2 osuint8 osqROM3 oskAlarmAutoStart[];
osqROM0 extern osqROM1 const osqROM2 osuint8 osqROM3 oskScheduleTableAutoStart[];
osqROM0 extern osqROM1 const osqROM2 osuint8 osqROM3 oskScheduleTableAutoStartType[];
osqROM0 extern osqROM1 const osqROM2 osuint8 osqROM3 oskTcbAutoStart[];

/* prototypes for alarm callback functions */
/* Schedule Tables */


/* ISRs */

#define osdIsrCanIsrWakeup_0Cat 2
#define osdIsrCanIsrTx_0Cat 2
#define osdIsrCanIsrErr_0Cat 2
#define osdIsrCanIsrRx_0Cat 2
#define osdIsrosTimerInterruptCat 2
/* Category 2 ISRs: */

#define CanIsrWakeup_0  ((ISRType) 0)
#define CanIsrTx_0  ((ISRType) 1)
#define CanIsrErr_0  ((ISRType) 2)
#define CanIsrRx_0  ((ISRType) 3)
#define osTimerInterrupt  ((ISRType) 4)

#if ((osdSC== SC3) || (osdSC== SC4))
   extern osqROM0 osqROM1 const osqROM2 MemoryAddressType osqROM3 oskISRMemoryAccessLow[][];
   extern osqROM0 osqROM1 const osqROM2 MemoryAddressType osqROM3 oskISRMemoryAccessHigh[][];
#endif

#if (osdKillTaskIsrPossible || (osdSC== SC3) || (osdSC== SC4))
#if (osdNumberOfCat2ISRs > 0)
   extern osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osIcbLockedResource[osdNumberOfCat2ISRs];
#else
   extern osqTcbRAM1 osqTcbRAM2 osResourceIndexType osqTcbRAM3 osIcbLockedResource[1];
#endif
#endif

/* ISR prototypes */
extern void CanIsrWakeup_0func(void);
extern void CanIsrTx_0func(void);
extern void CanIsrErr_0func(void);
extern void CanIsrRx_0func(void);
extern void osTimerInterruptfunc(void);

#endif /* _POST_TCB_H (double include preventer) */
#endif /* osdPostTCB */

#if osdPreTCB
#ifndef _PRE_TCBCOM_H
#define _PRE_TCBCOM_H


/* No COM-object defined in the OIL-file => No messages! */
#define osdUseCOM                       0
#define osdNumberOfAllMessages          0
#define osdNumberOfMessageQueues        0
#define osdNumberOfRxMessages           0
#define osdNumberOfTxMessages           0
#define osdNumberOfMsgFlagNotifics      0
#define osdNumberOfMsgCallbackNotifics  0
#define osdNumberOfMessagesToInitialize 0
#define osdComErrorHook                 0
#define osdComUseGetServiceID           0
#define osdComUseParameterAccess        0
#define osdComStartComExtension         0
#define osdComStatusLevel               osdComStandard

#endif
#endif


 /* Interrupt source IDs */

#define IRQ_SystemTimer   0
#define IRQ_RESERVED_0   1
#define IRQ_RESERVED_1   2
#define IRQ_RESERVED_2   3
#define IRQ_RESERVED_3   4
#define IRQ_CanIsrTx_0   5
#define IRQ_CanIsrRx_0   6
#define IRQ_CanIsrErr_0   7
#define IRQ_CanIsrWakeup_0   8
#define IRQ_CanIsrTx_1   9
#define IRQ_CanIsrRx_1   10
#define IRQ_CanIsrErr_1   11
#define IRQ_CanIsrWakeup_1   12
#define IRQ_CanIsrTx_2   13
#define IRQ_CanIsrRx_2   14
#define IRQ_CanIsrErr_2   15
#define IRQ_CanIsrWakeup_2   16
#define IRQ_CanIsrTx_3   17
#define IRQ_CanIsrRx_3   18
#define IRQ_CanIsrErr_3   19
#define IRQ_CanIsrWakeup_3   20
#define IRQ_CanIsrTx_4   21
#define IRQ_CanIsrRx_4   22
#define IRQ_CanIsrErr_4   23
#define IRQ_CanIsrWakeup_4   24
#define IRQ_CanIsrTx_5   25
#define IRQ_CanIsrRx_5   26
#define IRQ_CanIsrErr_5   27
#define IRQ_CanIsrWakeup_5   28
#define IRQ_CanIsrTx_6   29
#define IRQ_CanIsrRx_6   30
#define IRQ_CanIsrErr_6   31
#define IRQ_CanIsrWakeup_6   32
#define IRQ_CanIsrTx_7   33
#define IRQ_CanIsrRx_7   34
#define IRQ_CanIsrErr_7   35
#define IRQ_CanIsrWakeup_7   36
#define IRQ_CanIsrTx_8   37
#define IRQ_CanIsrRx_8   38
#define IRQ_CanIsrErr_8   39
#define IRQ_CanIsrWakeup_8   40
#define IRQ_CanIsrTx_9   41
#define IRQ_CanIsrRx_9   42
#define IRQ_CanIsrErr_9   43
#define IRQ_CanIsrWakeup_9   44
#define IRQ_CanIsrTx_10   45
#define IRQ_CanIsrRx_10   46
#define IRQ_CanIsrErr_10   47
#define IRQ_CanIsrWakeup_10   48
#define IRQ_CanIsrTx_11   49
#define IRQ_CanIsrRx_11   50
#define IRQ_CanIsrErr_11   51
#define IRQ_CanIsrWakeup_11   52
#define IRQ_CanIsrTx_12   53
#define IRQ_CanIsrRx_12   54
#define IRQ_CanIsrErr_12   55
#define IRQ_CanIsrWakeup_12   56
#define IRQ_CanIsrTx_13   57
#define IRQ_CanIsrRx_13   58
#define IRQ_CanIsrErr_13   59
#define IRQ_CanIsrWakeup_13   60
#define IRQ_CanIsrTx_14   61
#define IRQ_CanIsrRx_14   62
#define IRQ_CanIsrErr_14   63
#define IRQ_CanIsrWakeup_14   64
#define IRQ_CanIsrTx_15   65
#define IRQ_CanIsrRx_15   66
#define IRQ_CanIsrErr_15   67
#define IRQ_CanIsrWakeup_15   68
#define IRQ_LinIsr_0   69
#define IRQ_LinIsr_1   70
#define IRQ_LinIsr_2   71
#define IRQ_LinIsr_3   72
#define IRQ_LinIsr_4   73
#define IRQ_LinIsr_5   74
#define IRQ_LinIsr_6   75
#define IRQ_LinIsr_7   76
#define IRQ_LinIsr_8   77
#define IRQ_LinIsr_9   78
#define IRQ_LinIsr_10   79
#define IRQ_LinIsr_11   80
#define IRQ_LinIsr_12   81
#define IRQ_LinIsr_13   82
#define IRQ_LinIsr_14   83
#define IRQ_LinIsr_15   84
#define IRQ_LinIsr_16   85
#define IRQ_LinIsr_17   86
#define IRQ_LinIsr_18   87
#define IRQ_LinIsr_19   88
#define IRQ_LinIsr_20   89
#define IRQ_LinIsr_21   90
#define IRQ_LinIsr_22   91
#define IRQ_LinIsr_23   92
#define IRQ_LinIsr_24   93
#define IRQ_LinIsr_25   94
#define IRQ_LinIsr_26   95
#define IRQ_LinIsr_27   96
#define IRQ_LinIsr_28   97
#define IRQ_LinIsr_29   98
#define IRQ_LinIsr_30   99
#define IRQ_LinIsr_31   100
#define IRQ_EthIsrRx_0   101
#define IRQ_EthIsrTx_0   102
#define IRQ_EthIsrRx_1   103
#define IRQ_EthIsrTx_1   104
#define IRQ_EthIsrRx_2   105
#define IRQ_EthIsrTx_2   106
#define IRQ_EthIsrRx_3   107
#define IRQ_EthIsrTx_3   108
#define IRQ_EthIsrRx_4   109
#define IRQ_EthIsrTx_4   110
#define IRQ_EthIsrRx_5   111
#define IRQ_EthIsrTx_5   112
#define IRQ_EthIsrRx_6   113
#define IRQ_EthIsrTx_6   114
#define IRQ_EthIsrRx_7   115
#define IRQ_EthIsrTx_7   116
#define IRQ_Fr_IrqLine0   117
#define IRQ_Fr_IrqTimer0   118
#define IRQ_Fr_IrqLine1   119
#define IRQ_Fr_IrqTimer1   120
#define IRQ_Fr_IrqLine2   121
#define IRQ_Fr_IrqTimer2   122
#define IRQ_VttSysVarIsr_0   123
#define IRQ_GptIsr_0   124
#define IRQ_GptIsr_1   125
#define IRQ_GptIsr_2   126
#define IRQ_GptIsr_3   127
#define IRQ_GptIsr_4   128
#define IRQ_GptIsr_5   129
#define IRQ_GptIsr_6   130
#define IRQ_GptIsr_7   131
#define IRQ_GptIsr_8   132
#define IRQ_GptIsr_9   133
#define IRQ_GptIsr_10   134
#define IRQ_GptIsr_11   135
#define IRQ_GptIsr_12   136
#define IRQ_GptIsr_13   137
#define IRQ_GptIsr_14   138
#define IRQ_GptIsr_15   139
#define IRQ_GptIsr_16   140
#define IRQ_GptIsr_17   141
#define IRQ_GptIsr_18   142
#define IRQ_GptIsr_19   143
#define IRQ_GptIsr_20   144
#define IRQ_GptIsr_21   145
#define IRQ_GptIsr_22   146
#define IRQ_GptIsr_23   147
#define IRQ_GptIsr_24   148
#define IRQ_GptIsr_25   149
#define IRQ_GptIsr_26   150
#define IRQ_GptIsr_27   151
#define IRQ_GptIsr_28   152
#define IRQ_GptIsr_29   153
#define IRQ_GptIsr_30   154
#define IRQ_GptIsr_31   155
#define IRQ_GptIsr_32   156
#define IRQ_GptIsr_33   157
#define IRQ_GptIsr_34   158
#define IRQ_GptIsr_35   159
#define IRQ_GptIsr_36   160
#define IRQ_GptIsr_37   161
#define IRQ_GptIsr_38   162
#define IRQ_GptIsr_39   163
#define IRQ_GptIsr_40   164
#define IRQ_GptIsr_41   165
#define IRQ_GptIsr_42   166
#define IRQ_GptIsr_43   167
#define IRQ_GptIsr_44   168
#define IRQ_GptIsr_45   169
#define IRQ_GptIsr_46   170
#define IRQ_GptIsr_47   171
#define IRQ_GptIsr_48   172
#define IRQ_GptIsr_49   173
#define IRQ_AdcIsr_0   174
#define IRQ_AdcIsr_1   175
#define IRQ_AdcIsr_2   176
#define IRQ_AdcIsr_3   177
#define IRQ_AdcIsr_4   178
#define IRQ_AdcIsr_5   179
#define IRQ_AdcIsr_6   180
#define IRQ_AdcIsr_7   181
#define IRQ_AdcIsr_8   182
#define IRQ_AdcIsr_9   183
#define IRQ_AdcIsr_10   184
#define IRQ_AdcIsr_11   185
#define IRQ_AdcIsr_12   186
#define IRQ_AdcIsr_13   187
#define IRQ_AdcIsr_14   188
#define IRQ_AdcIsr_15   189
#define IRQ_AdcIsr_16   190
#define IRQ_AdcIsr_17   191
#define IRQ_AdcIsr_18   192
#define IRQ_AdcIsr_19   193
#define IRQ_AdcIsr_20   194
#define IRQ_AdcIsr_21   195
#define IRQ_AdcIsr_22   196
#define IRQ_AdcIsr_23   197
#define IRQ_AdcIsr_24   198
#define IRQ_AdcIsr_25   199
#define IRQ_AdcIsr_26   200
#define IRQ_AdcIsr_27   201
#define IRQ_AdcIsr_28   202
#define IRQ_AdcIsr_29   203
#define IRQ_AdcIsr_30   204
#define IRQ_AdcIsr_31   205
#define IRQ_AdcIsr_32   206
#define IRQ_AdcIsr_33   207
#define IRQ_AdcIsr_34   208
#define IRQ_AdcIsr_35   209
#define IRQ_AdcIsr_36   210
#define IRQ_AdcIsr_37   211
#define IRQ_AdcIsr_38   212
#define IRQ_AdcIsr_39   213
#define IRQ_AdcIsr_40   214
#define IRQ_AdcIsr_41   215
#define IRQ_AdcIsr_42   216
#define IRQ_AdcIsr_43   217
#define IRQ_AdcIsr_44   218
#define IRQ_AdcIsr_45   219
#define IRQ_AdcIsr_46   220
#define IRQ_AdcIsr_47   221
#define IRQ_AdcIsr_48   222
#define IRQ_AdcIsr_49   223
#define IRQ_IcuIsr_0   224
#define IRQ_IcuIsr_1   225
#define IRQ_IcuIsr_2   226
#define IRQ_IcuIsr_3   227
#define IRQ_IcuIsr_4   228
#define IRQ_IcuIsr_5   229
#define IRQ_IcuIsr_6   230
#define IRQ_IcuIsr_7   231
#define IRQ_IcuIsr_8   232
#define IRQ_IcuIsr_9   233
#define IRQ_IcuIsr_10   234
#define IRQ_IcuIsr_11   235
#define IRQ_IcuIsr_12   236
#define IRQ_IcuIsr_13   237
#define IRQ_IcuIsr_14   238
#define IRQ_IcuIsr_15   239
#define IRQ_IcuIsr_16   240
#define IRQ_IcuIsr_17   241
#define IRQ_IcuIsr_18   242
#define IRQ_IcuIsr_19   243
#define IRQ_IcuIsr_20   244
#define IRQ_IcuIsr_21   245
#define IRQ_IcuIsr_22   246
#define IRQ_IcuIsr_23   247
#define IRQ_IcuIsr_24   248
#define IRQ_IcuIsr_25   249
#define IRQ_IcuIsr_26   250
#define IRQ_IcuIsr_27   251
#define IRQ_IcuIsr_28   252
#define IRQ_IcuIsr_29   253
#define IRQ_IcuIsr_30   254
#define IRQ_IcuIsr_31   255
#define IRQ_IcuIsr_32   256
#define IRQ_IcuIsr_33   257
#define IRQ_IcuIsr_34   258
#define IRQ_IcuIsr_35   259
#define IRQ_IcuIsr_36   260
#define IRQ_IcuIsr_37   261
#define IRQ_IcuIsr_38   262
#define IRQ_IcuIsr_39   263
#define IRQ_IcuIsr_40   264
#define IRQ_IcuIsr_41   265
#define IRQ_IcuIsr_42   266
#define IRQ_IcuIsr_43   267
#define IRQ_IcuIsr_44   268
#define IRQ_IcuIsr_45   269
#define IRQ_IcuIsr_46   270
#define IRQ_IcuIsr_47   271
#define IRQ_IcuIsr_48   272
#define IRQ_IcuIsr_49   273
#define IRQ_PwmIsr_0   274
#define IRQ_PwmIsr_1   275
#define IRQ_PwmIsr_2   276
#define IRQ_PwmIsr_3   277
#define IRQ_PwmIsr_4   278
#define IRQ_PwmIsr_5   279
#define IRQ_PwmIsr_6   280
#define IRQ_PwmIsr_7   281
#define IRQ_PwmIsr_8   282
#define IRQ_PwmIsr_9   283
#define IRQ_PwmIsr_10   284
#define IRQ_PwmIsr_11   285
#define IRQ_PwmIsr_12   286
#define IRQ_PwmIsr_13   287
#define IRQ_PwmIsr_14   288
#define IRQ_PwmIsr_15   289
#define IRQ_PwmIsr_16   290
#define IRQ_PwmIsr_17   291
#define IRQ_PwmIsr_18   292
#define IRQ_PwmIsr_19   293
#define IRQ_PwmIsr_20   294
#define IRQ_PwmIsr_21   295
#define IRQ_PwmIsr_22   296
#define IRQ_PwmIsr_23   297
#define IRQ_PwmIsr_24   298
#define IRQ_PwmIsr_25   299
#define IRQ_PwmIsr_26   300
#define IRQ_PwmIsr_27   301
#define IRQ_PwmIsr_28   302
#define IRQ_PwmIsr_29   303
#define IRQ_PwmIsr_30   304
#define IRQ_PwmIsr_31   305
#define IRQ_PwmIsr_32   306
#define IRQ_PwmIsr_33   307
#define IRQ_PwmIsr_34   308
#define IRQ_PwmIsr_35   309
#define IRQ_PwmIsr_36   310
#define IRQ_PwmIsr_37   311
#define IRQ_PwmIsr_38   312
#define IRQ_PwmIsr_39   313
#define IRQ_PwmIsr_40   314
#define IRQ_PwmIsr_41   315
#define IRQ_PwmIsr_42   316
#define IRQ_PwmIsr_43   317
#define IRQ_PwmIsr_44   318
#define IRQ_PwmIsr_45   319
#define IRQ_PwmIsr_46   320
#define IRQ_PwmIsr_47   321
#define IRQ_PwmIsr_48   322
#define IRQ_PwmIsr_49   323
#define IRQ_SpiIsrTx_0   324
#define IRQ_SpiIsrRx_0   325
#define IRQ_SpiIsrTx_1   326
#define IRQ_SpiIsrRx_1   327
#define IRQ_SpiIsrTx_2   328
#define IRQ_SpiIsrRx_2   329
#define IRQ_SpiIsrTx_3   330
#define IRQ_SpiIsrRx_3   331
#define IRQ_SpiIsrTx_4   332
#define IRQ_SpiIsrRx_4   333
#define IRQ_SpiIsrTx_5   334
#define IRQ_SpiIsrRx_5   335
#define IRQ_SpiIsrTx_6   336
#define IRQ_SpiIsrRx_6   337
#define IRQ_SpiIsrTx_7   338
#define IRQ_SpiIsrRx_7   339
#define IRQ_SpiIsrTx_8   340
#define IRQ_SpiIsrRx_8   341
#define IRQ_SpiIsrTx_9   342
#define IRQ_SpiIsrRx_9   343
#define IRQ_SpiIsrTx_10   344
#define IRQ_SpiIsrRx_10   345
#define IRQ_SpiIsrTx_11   346
#define IRQ_SpiIsrRx_11   347
#define IRQ_SpiIsrTx_12   348
#define IRQ_SpiIsrRx_12   349
#define IRQ_SpiIsrTx_13   350
#define IRQ_SpiIsrRx_13   351
#define IRQ_SpiIsrTx_14   352
#define IRQ_SpiIsrRx_14   353
#define IRQ_SpiIsrTx_15   354
#define IRQ_SpiIsrRx_15   355
#define IRQ_SpiIsrTx_16   356
#define IRQ_SpiIsrRx_16   357
#define IRQ_SpiIsrTx_17   358
#define IRQ_SpiIsrRx_17   359
#define IRQ_SpiIsrTx_18   360
#define IRQ_SpiIsrRx_18   361
#define IRQ_SpiIsrTx_19   362
#define IRQ_SpiIsrRx_19   363
#define IRQ_SpiIsrTx_20   364
#define IRQ_SpiIsrRx_20   365
#define IRQ_SpiIsrTx_21   366
#define IRQ_SpiIsrRx_21   367
#define IRQ_SpiIsrTx_22   368
#define IRQ_SpiIsrRx_22   369
#define IRQ_SpiIsrTx_23   370
#define IRQ_SpiIsrRx_23   371
#define IRQ_SpiIsrTx_24   372
#define IRQ_SpiIsrRx_24   373
#define IRQ_SpiIsrTx_25   374
#define IRQ_SpiIsrRx_25   375
#define IRQ_SpiIsrTx_26   376
#define IRQ_SpiIsrRx_26   377
#define IRQ_SpiIsrTx_27   378
#define IRQ_SpiIsrRx_27   379
#define IRQ_SpiIsrTx_28   380
#define IRQ_SpiIsrRx_28   381
#define IRQ_SpiIsrTx_29   382
#define IRQ_SpiIsrRx_29   383
#define IRQ_SpiIsrTx_30   384
#define IRQ_SpiIsrRx_30   385
#define IRQ_SpiIsrTx_31   386
#define IRQ_SpiIsrRx_31   387
#define IRQ_SpiIsrTx_32   388
#define IRQ_SpiIsrRx_32   389
#define IRQ_SpiIsrTx_33   390
#define IRQ_SpiIsrRx_33   391
#define IRQ_SpiIsrTx_34   392
#define IRQ_SpiIsrRx_34   393
#define IRQ_SpiIsrTx_35   394
#define IRQ_SpiIsrRx_35   395
#define IRQ_SpiIsrTx_36   396
#define IRQ_SpiIsrRx_36   397
#define IRQ_SpiIsrTx_37   398
#define IRQ_SpiIsrRx_37   399
#define IRQ_SpiIsrTx_38   400
#define IRQ_SpiIsrRx_38   401
#define IRQ_SpiIsrTx_39   402
#define IRQ_SpiIsrRx_39   403
#define IRQ_SpiIsrTx_40   404
#define IRQ_SpiIsrRx_40   405
#define IRQ_SpiIsrTx_41   406
#define IRQ_SpiIsrRx_41   407
#define IRQ_SpiIsrTx_42   408
#define IRQ_SpiIsrRx_42   409
#define IRQ_SpiIsrTx_43   410
#define IRQ_SpiIsrRx_43   411
#define IRQ_SpiIsrTx_44   412
#define IRQ_SpiIsrRx_44   413
#define IRQ_SpiIsrTx_45   414
#define IRQ_SpiIsrRx_45   415
#define IRQ_SpiIsrTx_46   416
#define IRQ_SpiIsrRx_46   417
#define IRQ_SpiIsrTx_47   418
#define IRQ_SpiIsrRx_47   419
#define IRQ_SpiIsrTx_48   420
#define IRQ_SpiIsrRx_48   421
#define IRQ_SpiIsrTx_49   422
#define IRQ_SpiIsrRx_49   423
#define IRQ_CddIsr_0   424
#define IRQ_CddIsr_1   425
#define IRQ_CddIsr_2   426
#define IRQ_CddIsr_3   427
#define IRQ_CddIsr_4   428
#define IRQ_CddIsr_5   429
#define IRQ_CddIsr_6   430
#define IRQ_CddIsr_7   431
#define IRQ_CddIsr_8   432
#define IRQ_CddIsr_9   433
#define IRQ_CddIsr_10   434
#define IRQ_CddIsr_11   435
#define IRQ_CddIsr_12   436
#define IRQ_CddIsr_13   437
#define IRQ_CddIsr_14   438
#define IRQ_CddIsr_15   439
#define IRQ_CddIsr_16   440
#define IRQ_CddIsr_17   441
#define IRQ_CddIsr_18   442
#define IRQ_CddIsr_19   443
#define IRQ_CddIsr_20   444
#define IRQ_CddIsr_21   445
#define IRQ_CddIsr_22   446
#define IRQ_CddIsr_23   447
#define IRQ_CddIsr_24   448
#define IRQ_CddIsr_25   449
#define IRQ_CddIsr_26   450
#define IRQ_CddIsr_27   451
#define IRQ_CddIsr_28   452
#define IRQ_CddIsr_29   453
#define IRQ_CddIsr_30   454
#define IRQ_CddIsr_31   455
#define IRQ_CddIsr_32   456
#define IRQ_CddIsr_33   457
#define IRQ_CddIsr_34   458
#define IRQ_CddIsr_35   459
#define IRQ_CddIsr_36   460
#define IRQ_CddIsr_37   461
#define IRQ_CddIsr_38   462
#define IRQ_CddIsr_39   463
#define IRQ_CddIsr_40   464
#define IRQ_CddIsr_41   465
#define IRQ_CddIsr_42   466
#define IRQ_CddIsr_43   467
#define IRQ_CddIsr_44   468
#define IRQ_CddIsr_45   469
#define IRQ_CddIsr_46   470
#define IRQ_CddIsr_47   471
#define IRQ_CddIsr_48   472
#define IRQ_CddIsr_49   473

extern const osuint16 oskNumberOfInterruptSources;

/* Variable to save the interrupt number which causes an Unhandled exception */
extern osuint16  osISRUnhandledException_Number;

extern osuint8 VTTOs_GetInterruptName(osint32 isr, const char ** interruptName);
#define VTTOS_IRQ_OK (0x00)
#define VTTOS_IRQ_UNKNOWN (0x01)


/* END OF C:\Users\nituser\Desktop\Autosar homework\M2\E1\_E1_SoftwareComponents\Appl\GenDataVtt\tcb.h */

