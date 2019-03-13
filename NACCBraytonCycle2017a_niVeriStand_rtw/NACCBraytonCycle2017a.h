/*
 * NACCBraytonCycle2017a.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "NACCBraytonCycle2017a".
 *
 * Model version              : 1.151
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Mar 06 17:30:56 2019
 *
 * Target selection: NIVeriStand.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_NACCBraytonCycle2017a_h_
#define RTW_HEADER_NACCBraytonCycle2017a_h_
#include <math.h>
#include <string.h>
#include <stddef.h>
#ifndef NACCBraytonCycle2017a_COMMON_INCLUDES_
# define NACCBraytonCycle2017a_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* NACCBraytonCycle2017a_COMMON_INCLUDES_ */

#include "NACCBraytonCycle2017a_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define NACCBraytonCycle2017a_rtModel  RT_MODEL_NACCBraytonCycle2017_T

/* Block signals for system '<S62>/calculate  conversion' */
typedef struct {
  real_T Subtract5;                    /* '<S69>/Subtract5' */
  real_T Product6[7];                  /* '<S69>/Product6' */
} B_calculateconversion_NACCBra_T;

/* Block signals (auto storage) */
typedef struct {
  real_T UnitOffset;                   /* '<S51>/UnitOffset' */
  real_T UnitOffset_h;                 /* '<S52>/UnitOffset' */
  real_T ndot;                         /* '<S1>/Merge1' */
  real_T ndot_e;                       /* '<S13>/Memory9' */
  real_T psi[7];                       /* '<S13>/Memory4' */
  real_T psi_k[7];                     /* '<S9>/Memory4' */
  real_T ndot_ea;                      /* '<S12>/Memory9' */
  real_T psi_n[7];                     /* '<S12>/Memory4' */
  real_T psi_b[7];                     /* '<S7>/Memory4' */
  real_T Switch2;                      /* '<S137>/Switch2' */
  real_T MultiportSwitch;              /* '<S129>/Multiport Switch' */
  real_T ndot_i;                       /* '<S138>/Gain' */
  real_T T;                            /* '<S138>/Gain1' */
  real_T p;                            /* '<S138>/Gain2' */
  real_T x[7];                         /* '<S138>/Gain3' */
  real_T psi_o[7];                     /* '<S138>/Gain4' */
  real_T Hdot;                         /* '<S138>/S-Function1' */
  real_T Sdot;                         /* '<S138>/S-Function1' */
  real_T Gdot;                         /* '<S138>/S-Function1' */
  real_T Cpdot;                        /* '<S138>/S-Function1' */
  real_T Subtract2;                    /* '<S129>/Subtract2' */
  real_T Product;                      /* '<S62>/Product' */
  real_T Saturation;                   /* '<S64>/Saturation' */
  real_T Hdot_d;                       /* '<S11>/Memory3' */
  real_T Product_a;                    /* '<S70>/Product' */
  real_T Saturation_m;                 /* '<S72>/Saturation' */
  real_T Hdot_j;                       /* '<S10>/Memory3' */
  real_T Product1;                     /* '<S86>/Product1' */
  real_T p2;                           /* '<S78>/Product14' */
  real_T Sum2;                         /* '<S78>/Sum2' */
  real_T Saturation_p;                 /* '<S100>/Saturation' */
  real_T Sum7;                         /* '<S101>/Sum7' */
  real_T Switch2_g;                    /* '<S113>/Switch2' */
  real_T MultiportSwitch_i;            /* '<S105>/Multiport Switch' */
  real_T ndot_k;                       /* '<S114>/Gain' */
  real_T T_d;                          /* '<S114>/Gain1' */
  real_T p_b;                          /* '<S114>/Gain2' */
  real_T x_f[7];                       /* '<S114>/Gain3' */
  real_T psi_e[7];                     /* '<S114>/Gain4' */
  real_T Hdot_f;                       /* '<S114>/S-Function1' */
  real_T Sdot_c;                       /* '<S114>/S-Function1' */
  real_T Gdot_i;                       /* '<S114>/S-Function1' */
  real_T Cpdot_b;                      /* '<S114>/S-Function1' */
  real_T Subtract2_k;                  /* '<S105>/Subtract2' */
  real_T Saturation_l;                 /* '<S124>/Saturation' */
  real_T Sum7_h;                       /* '<S125>/Sum7' */
  real_T UnitOffset_l;                 /* '<S161>/UnitOffset' */
  real_T UnitOffset_f;                 /* '<S162>/UnitOffset' */
  real_T ndot_ka;                      /* '<S17>/Merge1' */
  real_T T_c;                          /* '<S166>/Gain1' */
  real_T x_a[7];                       /* '<S166>/Gain3' */
  real_T psi_c[7];                     /* '<S166>/Gain4' */
  real_T Hdot_c;                       /* '<S166>/S-Function1' */
  real_T Sdot_k;                       /* '<S166>/S-Function1' */
  real_T Gdot_j;                       /* '<S166>/S-Function1' */
  real_T Cpdot_j;                      /* '<S166>/S-Function1' */
  real_T SFunction1_o1[7];             /* '<S165>/S-Function1' */
  real_T SFunction_o1;                 /* '<S169>/S-Function' */
  real_T SFunction_o2;                 /* '<S169>/S-Function' */
  real_T SFunction_o3;                 /* '<S169>/S-Function' */
  real_T SFunction1_o1_i[7];           /* '<S167>/S-Function1' */
  real_T p_h;                          /* '<S152>/Gain2' */
  real_T Add3;                         /* '<S147>/Add3' */
  real_T ndot_o;                       /* '<S152>/Gain' */
  real_T psi_cv[7];                    /* '<S152>/Gain4' */
  real_T MultiportSwitch1[7];          /* '<S147>/Multiport Switch1' */
  real_T Saturation_f;                 /* '<S151>/Saturation' */
  real_T T_g;                          /* '<S152>/Gain1' */
  real_T x_b[7];                       /* '<S152>/Gain3' */
  real_T Hdot_h;                       /* '<S152>/S-Function1' */
  real_T Sdot_l;                       /* '<S152>/S-Function1' */
  real_T Gdot_n;                       /* '<S152>/S-Function1' */
  real_T Cpdot_i;                      /* '<S152>/S-Function1' */
  real_T Sum6;                         /* '<S147>/Sum6' */
  real_T ndot_m;                       /* '<S150>/S-Function' */
  real_T T_go;                         /* '<S150>/S-Function' */
  real_T p_p;                          /* '<S150>/S-Function' */
  real_T Hdot_cl;                      /* '<S150>/S-Function' */
  real_T Sdot_e;                       /* '<S150>/S-Function' */
  real_T Gdot_k;                       /* '<S150>/S-Function' */
  real_T Cpdot_l;                      /* '<S150>/S-Function' */
  real_T x_j[7];                       /* '<S150>/S-Function' */
  real_T psi_h[7];                     /* '<S150>/S-Function' */
  real_T Qenv;                         /* '<S150>/S-Function' */
  real_T num_iterations;               /* '<S150>/S-Function' */
  real_T ndot_b;                       /* '<S136>/S-Function' */
  real_T T_n;                          /* '<S136>/S-Function' */
  real_T p_pc;                         /* '<S136>/S-Function' */
  real_T Hdot_d0;                      /* '<S136>/S-Function' */
  real_T Sdot_k0;                      /* '<S136>/S-Function' */
  real_T Gdot_km;                      /* '<S136>/S-Function' */
  real_T Cpdot_e;                      /* '<S136>/S-Function' */
  real_T x_o[7];                       /* '<S136>/S-Function' */
  real_T psi_cu[7];                    /* '<S136>/S-Function' */
  real_T iter;                         /* '<S136>/S-Function' */
  real_T ndot_c;                       /* '<S131>/S-Function' */
  real_T T_p;                          /* '<S131>/S-Function' */
  real_T p_a;                          /* '<S131>/S-Function' */
  real_T Hdot_o;                       /* '<S131>/S-Function' */
  real_T Sdot_m;                       /* '<S131>/S-Function' */
  real_T Gdot_b;                       /* '<S131>/S-Function' */
  real_T Cpdot_g;                      /* '<S131>/S-Function' */
  real_T x_k[7];                       /* '<S131>/S-Function' */
  real_T psi_m[7];                     /* '<S131>/S-Function' */
  real_T Qenv_p;                       /* '<S131>/S-Function' */
  real_T num_iterations_a;             /* '<S131>/S-Function' */
  real_T ndot_ol;                      /* '<S126>/S-Function' */
  real_T T_e;                          /* '<S126>/S-Function' */
  real_T p_a5;                         /* '<S126>/S-Function' */
  real_T Hdot_i;                       /* '<S126>/S-Function' */
  real_T Sdot_ce;                      /* '<S126>/S-Function' */
  real_T Gdot_m;                       /* '<S126>/S-Function' */
  real_T Cpdot_p;                      /* '<S126>/S-Function' */
  real_T x_ac[7];                      /* '<S126>/S-Function' */
  real_T psi_a[7];                     /* '<S126>/S-Function' */
  real_T Qenv_k;                       /* '<S126>/S-Function' */
  real_T num_iterations_f;             /* '<S126>/S-Function' */
  real_T ndot_n;                       /* '<S112>/S-Function' */
  real_T T_m;                          /* '<S112>/S-Function' */
  real_T p_n;                          /* '<S112>/S-Function' */
  real_T Hdot_jo;                      /* '<S112>/S-Function' */
  real_T Sdot_kk;                      /* '<S112>/S-Function' */
  real_T Gdot_h;                       /* '<S112>/S-Function' */
  real_T Cpdot_c;                      /* '<S112>/S-Function' */
  real_T x_d[7];                       /* '<S112>/S-Function' */
  real_T psi_l[7];                     /* '<S112>/S-Function' */
  real_T iter_n;                       /* '<S112>/S-Function' */
  real_T ndot_nq;                      /* '<S107>/S-Function' */
  real_T T_h;                          /* '<S107>/S-Function' */
  real_T p_g;                          /* '<S107>/S-Function' */
  real_T Hdot_n;                       /* '<S107>/S-Function' */
  real_T Sdot_f;                       /* '<S107>/S-Function' */
  real_T Gdot_l;                       /* '<S107>/S-Function' */
  real_T Cpdot_a;                      /* '<S107>/S-Function' */
  real_T x_dg[7];                      /* '<S107>/S-Function' */
  real_T psi_i[7];                     /* '<S107>/S-Function' */
  real_T Qenv_n;                       /* '<S107>/S-Function' */
  real_T num_iterations_d;             /* '<S107>/S-Function' */
  real_T ndot_bl;                      /* '<S102>/S-Function' */
  real_T T_gf;                         /* '<S102>/S-Function' */
  real_T p_a1;                         /* '<S102>/S-Function' */
  real_T Hdot_b;                       /* '<S102>/S-Function' */
  real_T Sdot_n;                       /* '<S102>/S-Function' */
  real_T Gdot_f;                       /* '<S102>/S-Function' */
  real_T Cpdot_aq;                     /* '<S102>/S-Function' */
  real_T x_ff[7];                      /* '<S102>/S-Function' */
  real_T psi_f[7];                     /* '<S102>/S-Function' */
  real_T Qenv_d;                       /* '<S102>/S-Function' */
  real_T num_iterations_j;             /* '<S102>/S-Function' */
  real_T ndot_c0;                      /* '<S92>/Gain' */
  real_T p_f;                          /* '<S92>/Gain2' */
  real_T x_da[7];                      /* '<S92>/Gain3' */
  real_T psi_ip[7];                    /* '<S92>/Gain4' */
  real_T Hdot_du;                      /* '<S92>/S-Function1' */
  real_T Sdot_d;                       /* '<S92>/S-Function1' */
  real_T Gdot_fo;                      /* '<S92>/S-Function1' */
  real_T Cpdot_i4;                     /* '<S92>/S-Function1' */
  real_T SFunction1_o1_c[7];           /* '<S91>/S-Function1' */
  real_T ndot_f;                       /* '<S84>/S-Function' */
  real_T T_do;                         /* '<S84>/S-Function' */
  real_T p_gc;                         /* '<S84>/S-Function' */
  real_T Hdot_e;                       /* '<S84>/S-Function' */
  real_T Sdot_a;                       /* '<S84>/S-Function' */
  real_T Gdot_c;                       /* '<S84>/S-Function' */
  real_T Cpdot_br;                     /* '<S84>/S-Function' */
  real_T x_p[7];                       /* '<S84>/S-Function' */
  real_T psi_g[7];                     /* '<S84>/S-Function' */
  real_T iter_j;                       /* '<S84>/S-Function' */
  real_T ndot_l;                       /* '<S81>/S-Function' */
  real_T T_j;                          /* '<S81>/S-Function' */
  real_T p_bs;                         /* '<S81>/S-Function' */
  real_T Hdot_jv;                      /* '<S81>/S-Function' */
  real_T Sdot_p;                       /* '<S81>/S-Function' */
  real_T Gdot_l1;                      /* '<S81>/S-Function' */
  real_T Cpdot_h;                      /* '<S81>/S-Function' */
  real_T x_ju[7];                      /* '<S81>/S-Function' */
  real_T psi_al[7];                    /* '<S81>/S-Function' */
  real_T Qenv_b;                       /* '<S81>/S-Function' */
  real_T num_iterations_n;             /* '<S81>/S-Function' */
  real_T ndot_d;                       /* '<S71>/S-Function' */
  real_T T_po;                         /* '<S71>/S-Function' */
  real_T p_c;                          /* '<S71>/S-Function' */
  real_T Hdot_k;                       /* '<S71>/S-Function' */
  real_T Sdot_fc;                      /* '<S71>/S-Function' */
  real_T Gdot_ny;                      /* '<S71>/S-Function' */
  real_T Cpdot_o;                      /* '<S71>/S-Function' */
  real_T x_ok[7];                      /* '<S71>/S-Function' */
  real_T psi_mo[7];                    /* '<S71>/S-Function' */
  real_T Qenv_o;                       /* '<S71>/S-Function' */
  real_T num_iterations_i;             /* '<S71>/S-Function' */
  real_T ndot_nu;                      /* '<S63>/S-Function' */
  real_T T_mj;                         /* '<S63>/S-Function' */
  real_T p_e;                          /* '<S63>/S-Function' */
  real_T Hdot_f5;                      /* '<S63>/S-Function' */
  real_T Sdot_ki;                      /* '<S63>/S-Function' */
  real_T Gdot_f0;                      /* '<S63>/S-Function' */
  real_T Cpdot_aw;                     /* '<S63>/S-Function' */
  real_T x_dt[7];                      /* '<S63>/S-Function' */
  real_T psi_le[7];                    /* '<S63>/S-Function' */
  real_T Qenv_e;                       /* '<S63>/S-Function' */
  real_T num_iterations_o;             /* '<S63>/S-Function' */
  real_T ndot_lp;                      /* '<S56>/Gain' */
  real_T T_gw;                         /* '<S56>/Gain1' */
  real_T p_d;                          /* '<S56>/Gain2' */
  real_T x_g[7];                       /* '<S56>/Gain3' */
  real_T psi_eg[7];                    /* '<S56>/Gain4' */
  real_T Hdot_a;                       /* '<S56>/S-Function1' */
  real_T Sdot_c0;                      /* '<S56>/S-Function1' */
  real_T Gdot_nyp;                     /* '<S56>/S-Function1' */
  real_T Cpdot_f;                      /* '<S56>/S-Function1' */
  real_T SFunction1_o1_n[7];           /* '<S55>/S-Function1' */
  real_T SFunction_o1_j;               /* '<S59>/S-Function' */
  real_T SFunction_o2_f;               /* '<S59>/S-Function' */
  real_T SFunction_o3_o;               /* '<S59>/S-Function' */
  real_T SFunction1_o1_o[7];           /* '<S57>/S-Function1' */
  real_T ndot_nc;                      /* '<S166>/Gain' */
  real_T p_pg;                         /* '<S166>/Gain2' */
  int32_T SFunction1_o5;               /* '<S138>/S-Function1' */
  int32_T SFunction1_o5_g;             /* '<S114>/S-Function1' */
  int32_T SFunction1_o5_d;             /* '<S166>/S-Function1' */
  int32_T SFunction1_o2;               /* '<S165>/S-Function1' */
  int32_T SFunction_o4;                /* '<S169>/S-Function' */
  int32_T SFunction1_o2_g;             /* '<S167>/S-Function1' */
  int32_T SFunction1_o5_m;             /* '<S152>/S-Function1' */
  int32_T error_codes;                 /* '<S150>/S-Function' */
  int32_T error_codes_i;               /* '<S136>/S-Function' */
  int32_T error_codes_j;               /* '<S131>/S-Function' */
  int32_T error_codes_i0;              /* '<S126>/S-Function' */
  int32_T error_codes_o;               /* '<S112>/S-Function' */
  int32_T error_codes_m;               /* '<S107>/S-Function' */
  int32_T error_codes_d;               /* '<S102>/S-Function' */
  int32_T SFunction1_o5_mw;            /* '<S92>/S-Function1' */
  int32_T SFunction1_o2_b;             /* '<S91>/S-Function1' */
  int32_T error_codes_do;              /* '<S84>/S-Function' */
  int32_T error_codes_p;               /* '<S81>/S-Function' */
  int32_T error_codes_m4;              /* '<S71>/S-Function' */
  int32_T error_codes_n;               /* '<S63>/S-Function' */
  int32_T SFunction1_o5_o;             /* '<S56>/S-Function1' */
  int32_T SFunction1_o2_gm;            /* '<S55>/S-Function1' */
  int32_T SFunction_o4_a;              /* '<S59>/S-Function' */
  int32_T SFunction1_o2_p;             /* '<S57>/S-Function1' */
  B_calculateconversion_NACCBra_T calculateconversion_b;/* '<S70>/calculate  conversion' */
  B_calculateconversion_NACCBra_T calculateconversion;/* '<S62>/calculate  conversion' */
} B_NACCBraytonCycle2017a_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T Memory9_PreviousInput;        /* '<S13>/Memory9' */
  real_T Memory4_PreviousInput[7];     /* '<S13>/Memory4' */
  real_T Memory1_PreviousInput;        /* '<S13>/Memory1' */
  real_T Memory2_PreviousInput;        /* '<S13>/Memory2' */
  real_T Memory3_PreviousInput;        /* '<S13>/Memory3' */
  real_T Memory9_PreviousInput_i;      /* '<S9>/Memory9' */
  real_T Memory4_PreviousInput_b[7];   /* '<S9>/Memory4' */
  real_T Memory1_PreviousInput_b;      /* '<S9>/Memory1' */
  real_T Memory2_PreviousInput_o;      /* '<S9>/Memory2' */
  real_T Memory3_PreviousInput_h;      /* '<S9>/Memory3' */
  real_T Memory9_PreviousInput_iv;     /* '<S12>/Memory9' */
  real_T Memory4_PreviousInput_f[7];   /* '<S12>/Memory4' */
  real_T Memory1_PreviousInput_e;      /* '<S12>/Memory1' */
  real_T Memory2_PreviousInput_n;      /* '<S12>/Memory2' */
  real_T Memory3_PreviousInput_e;      /* '<S12>/Memory3' */
  real_T Memory9_PreviousInput_a;      /* '<S8>/Memory9' */
  real_T Memory4_PreviousInput_p[7];   /* '<S8>/Memory4' */
  real_T Memory1_PreviousInput_p;      /* '<S8>/Memory1' */
  real_T Memory2_PreviousInput_ow;     /* '<S8>/Memory2' */
  real_T Memory3_PreviousInput_d;      /* '<S8>/Memory3' */
  real_T Memory9_PreviousInput_b;      /* '<S7>/Memory9' */
  real_T Memory4_PreviousInput_i[7];   /* '<S7>/Memory4' */
  real_T Memory1_PreviousInput_m;      /* '<S7>/Memory1' */
  real_T Memory2_PreviousInput_e;      /* '<S7>/Memory2' */
  real_T Memory3_PreviousInput_m;      /* '<S7>/Memory3' */
  real_T Memory8_PreviousInput[7];     /* '<S7>/Memory8' */
  real_T Memory4_PreviousInput_e[7];   /* '<S11>/Memory4' */
  real_T Memory9_PreviousInput_o;      /* '<S11>/Memory9' */
  real_T Memory2_PreviousInput_m;      /* '<S11>/Memory2' */
  real_T Memory3_PreviousInput_a;      /* '<S11>/Memory3' */
  real_T Memory4_PreviousInput_m[7];   /* '<S10>/Memory4' */
  real_T Memory9_PreviousInput_d;      /* '<S10>/Memory9' */
  real_T Memory2_PreviousInput_d;      /* '<S10>/Memory2' */
  real_T Memory3_PreviousInput_k;      /* '<S10>/Memory3' */
  real_T Memory1_PreviousInput_l[4];   /* '<S78>/Memory1' */
  real_T Memory_PreviousInput;         /* '<S86>/Memory' */
  real_T Memory8_PreviousInput_l[7];   /* '<S9>/Memory8' */
  real_T Memory8_PreviousInput_p[7];   /* '<S8>/Memory8' */
  real_T SFunction_T_CAL_DWORK;        /* '<S150>/S-Function' */
  real_T SFunction_T_CAL_DWORK_m;      /* '<S136>/S-Function' */
  real_T SFunction_T_CAL_DWORK_a;      /* '<S131>/S-Function' */
  real_T SFunction_T_CAL_DWORK_n;      /* '<S126>/S-Function' */
  real_T SFunction_T_CAL_DWORK_f;      /* '<S112>/S-Function' */
  real_T SFunction_T_CAL_DWORK_o;      /* '<S107>/S-Function' */
  real_T SFunction_T_CAL_DWORK_h;      /* '<S102>/S-Function' */
  real_T SFunction_T_CAL_DWORK_mu;     /* '<S84>/S-Function' */
  real_T SFunction_T_CAL_DWORK_p;      /* '<S81>/S-Function' */
  real_T SFunction_T_CAL_DWORK_c;      /* '<S71>/S-Function' */
  real_T SFunction_T_CAL_DWORK_o1;     /* '<S63>/S-Function' */
  void *SFunction_PWORK[4];            /* '<S150>/S-Function' */
  void *SFunction_PWORK_l[4];          /* '<S136>/S-Function' */
  void *SFunction_PWORK_a[4];          /* '<S131>/S-Function' */
  void *SFunction_PWORK_le[4];         /* '<S126>/S-Function' */
  void *SFunction_PWORK_i[4];          /* '<S112>/S-Function' */
  void *SFunction_PWORK_m[4];          /* '<S107>/S-Function' */
  void *SFunction_PWORK_h[4];          /* '<S102>/S-Function' */
  void *SFunction_PWORK_c[4];          /* '<S84>/S-Function' */
  void *SFunction_PWORK_mg[4];         /* '<S81>/S-Function' */
  void *SFunction_PWORK_cz[4];         /* '<S71>/S-Function' */
  void *SFunction_PWORK_ai[4];         /* '<S63>/S-Function' */
} DW_NACCBraytonCycle2017a_T;

/* External inputs (root inport signals with auto storage) */
typedef struct {
  real_T In1;                          /* '<Root>/In1' */
  real_T In2;                          /* '<Root>/In2' */
  real_T In3;                          /* '<Root>/In3' */
  real_T In4;                          /* '<Root>/In4' */
  real_T In5;                          /* '<Root>/In5' */
  real_T In6;                          /* '<Root>/In6' */
  real_T In7;                          /* '<Root>/In7' */
  real_T In8;                          /* '<Root>/In8' */
  real_T In9;                          /* '<Root>/In9' */
  real_T In10;                         /* '<Root>/In10' */
  real_T In11;                         /* '<Root>/In11' */
} ExtU_NACCBraytonCycle2017a_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Out1;                         /* '<Root>/Out1' */
  real_T Out2;                         /* '<Root>/Out2' */
  real_T Out3;                         /* '<Root>/Out3' */
  real_T Out4;                         /* '<Root>/Out4' */
  real_T Out5;                         /* '<Root>/Out5' */
  real_T Out6;                         /* '<Root>/Out6' */
  real_T Out7;                         /* '<Root>/Out7' */
  real_T Out8;                         /* '<Root>/Out8' */
  real_T Out9;                         /* '<Root>/Out9' */
  real_T Out10;                        /* '<Root>/Out10' */
  real_T Out11;                        /* '<Root>/Out11' */
  real_T Out12;                        /* '<Root>/Out12' */
  real_T Out13;                        /* '<Root>/Out13' */
  real_T Out14;                        /* '<Root>/Out14' */
  real_T Out15;                        /* '<Root>/Out15' */
  real_T Out16;                        /* '<Root>/Out16' */
  real_T Out17;                        /* '<Root>/Out17' */
  real_T Out18;                        /* '<Root>/Out18' */
  real_T Out19;                        /* '<Root>/Out19' */
  real_T Out20;                        /* '<Root>/Out20' */
  real_T Out21;                        /* '<Root>/Out21' */
  real_T Out22;                        /* '<Root>/Out22' */
  real_T Out23;                        /* '<Root>/Out23' */
  real_T Out24;                        /* '<Root>/Out24' */
  real_T Out25;                        /* '<Root>/Out25' */
  real_T Out26;                        /* '<Root>/Out26' */
  real_T Out27;                        /* '<Root>/Out27' */
  real_T Out28;                        /* '<Root>/Out28' */
} ExtY_NACCBraytonCycle2017a_T;

/* Backward compatible GRT Identifiers */
#define rtB                            NACCBraytonCycle2017a_B
#define BlockIO                        B_NACCBraytonCycle2017a_T
#define rtU                            NACCBraytonCycle2017a_U
#define ExternalInputs                 ExtU_NACCBraytonCycle2017a_T
#define rtY                            NACCBraytonCycle2017a_Y
#define ExternalOutputs                ExtY_NACCBraytonCycle2017a_T
#define rtP                            NACCBraytonCycle2017a_P
#define Parameters                     P_NACCBraytonCycle2017a_T
#define rtDWork                        NACCBraytonCycle2017a_DW
#define D_Work                         DW_NACCBraytonCycle2017a_T

/* Parameters for system: '<S1>/MassFlow' */
struct P_MassFlow_NACCBraytonCycle20_T_ {
  real_T Gain_Gain;                    /* Expression: 1000
                                        * Referenced by: '<S46>/Gain'
                                        */
};

/* Parameters for system: '<S62>/calculate  conversion' */
struct P_calculateconversion_NACCBra_T_ {
  real_T CompareToConstant1_const;     /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S68>/Constant'
                                        */
  real_T Gain1_Gain;                   /* Expression: -1
                                        * Referenced by: '<S65>/Gain1'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S65>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 1e-19
                                        * Referenced by: '<S65>/Saturation2'
                                        */
  real_T Saturation2_UpperSat_m;       /* Expression: inf
                                        * Referenced by: '<S69>/Saturation2'
                                        */
  real_T Saturation2_LowerSat_p;       /* Expression: 1e-19
                                        * Referenced by: '<S69>/Saturation2'
                                        */
};

/* Parameters (auto storage) */
struct P_NACCBraytonCycle2017a_T_ {
  real_T TH_THERM_H_P_STATE_HM_CONV_LIMIT;/* Variable: TH_THERM_H_P_STATE_HM_CONV_LIMIT
                                           * Referenced by:
                                           *   '<S63>/S-Function'
                                           *   '<S71>/S-Function'
                                           *   '<S81>/S-Function'
                                           *   '<S107>/S-Function'
                                           *   '<S131>/S-Function'
                                           *   '<S150>/S-Function'
                                           *   '<S102>/S-Function'
                                           *   '<S126>/S-Function'
                                           */
  real_T TH_THERM_H_P_STATE_NUM_ITER_MAX;/* Variable: TH_THERM_H_P_STATE_NUM_ITER_MAX
                                          * Referenced by:
                                          *   '<S63>/S-Function'
                                          *   '<S71>/S-Function'
                                          *   '<S81>/S-Function'
                                          *   '<S107>/S-Function'
                                          *   '<S131>/S-Function'
                                          *   '<S150>/S-Function'
                                          *   '<S102>/S-Function'
                                          *   '<S126>/S-Function'
                                          */
  real_T TH_THERM_H_P_STATE_T_CONV_LIMIT;/* Variable: TH_THERM_H_P_STATE_T_CONV_LIMIT
                                          * Referenced by:
                                          *   '<S63>/S-Function'
                                          *   '<S71>/S-Function'
                                          *   '<S81>/S-Function'
                                          *   '<S107>/S-Function'
                                          *   '<S131>/S-Function'
                                          *   '<S150>/S-Function'
                                          *   '<S102>/S-Function'
                                          *   '<S126>/S-Function'
                                          */
  real_T TH_THERM_NDOT_MIN;            /* Variable: TH_THERM_NDOT_MIN
                                        * Referenced by:
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S150>/S-Function'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        */
  real_T TH_THERM_S_P_STATE_NUM_ITER_MAX;/* Variable: TH_THERM_S_P_STATE_NUM_ITER_MAX
                                          * Referenced by:
                                          *   '<S84>/S-Function'
                                          *   '<S112>/S-Function'
                                          *   '<S136>/S-Function'
                                          */
  real_T TH_THERM_S_P_STATE_SM_CONV_LIMIT;/* Variable: TH_THERM_S_P_STATE_SM_CONV_LIMIT
                                           * Referenced by:
                                           *   '<S84>/S-Function'
                                           *   '<S112>/S-Function'
                                           *   '<S136>/S-Function'
                                           */
  real_T TH_THERM_S_P_STATE_T_CONV_LIMIT;/* Variable: TH_THERM_S_P_STATE_T_CONV_LIMIT
                                          * Referenced by:
                                          *   '<S84>/S-Function'
                                          *   '<S112>/S-Function'
                                          *   '<S136>/S-Function'
                                          */
  real_T th_Antoine_A[7];              /* Variable: th_Antoine_A
                                        * Referenced by:
                                        *   '<S55>/S-Function1'
                                        *   '<S56>/S-Function1'
                                        *   '<S57>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S165>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S167>/S-Function1'
                                        *   '<S59>/S-Function'
                                        *   '<S91>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_Antoine_B[7];              /* Variable: th_Antoine_B
                                        * Referenced by:
                                        *   '<S55>/S-Function1'
                                        *   '<S56>/S-Function1'
                                        *   '<S57>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S165>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S167>/S-Function1'
                                        *   '<S59>/S-Function'
                                        *   '<S91>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_Antoine_C[7];              /* Variable: th_Antoine_C
                                        * Referenced by:
                                        *   '<S55>/S-Function1'
                                        *   '<S56>/S-Function1'
                                        *   '<S57>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S165>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S167>/S-Function1'
                                        *   '<S59>/S-Function'
                                        *   '<S91>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_Cp_liq_T_max[7];           /* Variable: th_Cp_liq_T_max
                                        * Referenced by:
                                        *   '<S56>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        */
  real_T th_Cp_liq_T_min[7];           /* Variable: th_Cp_liq_T_min
                                        * Referenced by:
                                        *   '<S56>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        */
  real_T th_E_liq[7];                  /* Variable: th_E_liq
                                        * Referenced by:
                                        *   '<S59>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_M[7];                      /* Variable: th_M
                                        * Referenced by:
                                        *   '<S54>/M1'
                                        *   '<S56>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S83>/M1'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S111>/M1'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S135>/M1'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S164>/M1'
                                        *   '<S166>/S-Function1'
                                        *   '<S188>/M1'
                                        *   '<S254>/M1'
                                        *   '<S298>/M1'
                                        *   '<S331>/M1'
                                        *   '<S397>/M1'
                                        *   '<S430>/M1'
                                        *   '<S474>/M1'
                                        *   '<S59>/S-Function'
                                        *   '<S90>/M1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S104>/M1'
                                        *   '<S122>/M1'
                                        *   '<S126>/S-Function'
                                        *   '<S128>/M1'
                                        *   '<S146>/M1'
                                        *   '<S169>/S-Function'
                                        *   '<S61>/M1'
                                        *   '<S67>/M1'
                                        *   '<S75>/M1'
                                        *   '<S94>/M1'
                                        *   '<S155>/M1'
                                        *   '<S171>/M1'
                                        */
  real_T th_NASA_T_max[7];             /* Variable: th_NASA_T_max
                                        * Referenced by:
                                        *   '<S56>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        */
  real_T th_NASA_T_mid[7];             /* Variable: th_NASA_T_mid
                                        * Referenced by:
                                        *   '<S56>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        */
  real_T th_NASA_T_min[7];             /* Variable: th_NASA_T_min
                                        * Referenced by:
                                        *   '<S56>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        */
  real_T th_T_c[7];                    /* Variable: th_T_c
                                        * Referenced by:
                                        *   '<S55>/S-Function1'
                                        *   '<S56>/S-Function1'
                                        *   '<S57>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S165>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S167>/S-Function1'
                                        *   '<S59>/S-Function'
                                        *   '<S91>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_T_fg_ref[7];               /* Variable: th_T_fg_ref
                                        * Referenced by:
                                        *   '<S56>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        */
  real_T th_T_triple[7];               /* Variable: th_T_triple
                                        * Referenced by:
                                        *   '<S55>/S-Function1'
                                        *   '<S56>/S-Function1'
                                        *   '<S57>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S165>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S167>/S-Function1'
                                        *   '<S59>/S-Function'
                                        *   '<S91>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_T_v_ref[7];                /* Variable: th_T_v_ref
                                        * Referenced by:
                                        *   '<S59>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_const_R;                   /* Variable: th_const_R
                                        * Referenced by: '<S78>/Gas Konstant'
                                        */
  real_T th_density_calculation_mode;  /* Variable: th_density_calculation_mode
                                        * Referenced by:
                                        *   '<S59>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_evap_enth_A[7];            /* Variable: th_evap_enth_A
                                        * Referenced by:
                                        *   '<S55>/S-Function1'
                                        *   '<S56>/S-Function1'
                                        *   '<S57>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S165>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S167>/S-Function1'
                                        *   '<S91>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        */
  real_T th_evap_enth_B[7];            /* Variable: th_evap_enth_B
                                        * Referenced by:
                                        *   '<S55>/S-Function1'
                                        *   '<S56>/S-Function1'
                                        *   '<S57>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S165>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S167>/S-Function1'
                                        *   '<S91>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        */
  real_T th_evap_enth_C[7];            /* Variable: th_evap_enth_C
                                        * Referenced by:
                                        *   '<S55>/S-Function1'
                                        *   '<S56>/S-Function1'
                                        *   '<S57>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S165>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S167>/S-Function1'
                                        *   '<S91>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        */
  real_T th_evap_enth_T_min[7];        /* Variable: th_evap_enth_T_min
                                        * Referenced by:
                                        *   '<S55>/S-Function1'
                                        *   '<S56>/S-Function1'
                                        *   '<S57>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S165>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S167>/S-Function1'
                                        *   '<S91>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        */
  real_T th_gas_eos_method;            /* Variable: th_gas_eos_method
                                        * Referenced by:
                                        *   '<S55>/S-Function1'
                                        *   '<S56>/S-Function1'
                                        *   '<S57>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S165>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S167>/S-Function1'
                                        *   '<S59>/S-Function'
                                        *   '<S91>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_hm_fg[7];                  /* Variable: th_hm_fg
                                        * Referenced by:
                                        *   '<S56>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        */
  real_T th_liquid_eos_method;         /* Variable: th_liquid_eos_method
                                        * Referenced by:
                                        *   '<S55>/S-Function1'
                                        *   '<S56>/S-Function1'
                                        *   '<S57>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S165>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S167>/S-Function1'
                                        *   '<S91>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        */
  real_T th_omega[7];                  /* Variable: th_omega
                                        * Referenced by:
                                        *   '<S55>/S-Function1'
                                        *   '<S56>/S-Function1'
                                        *   '<S57>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S165>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S167>/S-Function1'
                                        *   '<S59>/S-Function'
                                        *   '<S91>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_p_c[7];                    /* Variable: th_p_c
                                        * Referenced by:
                                        *   '<S55>/S-Function1'
                                        *   '<S56>/S-Function1'
                                        *   '<S57>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S165>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S167>/S-Function1'
                                        *   '<S59>/S-Function'
                                        *   '<S91>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_rho_liq[7];                /* Variable: th_rho_liq
                                        * Referenced by:
                                        *   '<S59>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_rho_liq_A[7];              /* Variable: th_rho_liq_A
                                        * Referenced by:
                                        *   '<S59>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_rho_liq_B[7];              /* Variable: th_rho_liq_B
                                        * Referenced by:
                                        *   '<S59>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_rho_liq_C[7];              /* Variable: th_rho_liq_C
                                        * Referenced by:
                                        *   '<S59>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_rho_liq_D[7];              /* Variable: th_rho_liq_D
                                        * Referenced by:
                                        *   '<S59>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T th_sm_fg[7];                  /* Variable: th_sm_fg
                                        * Referenced by:
                                        *   '<S56>/S-Function1'
                                        *   '<S63>/S-Function'
                                        *   '<S71>/S-Function'
                                        *   '<S81>/S-Function'
                                        *   '<S84>/S-Function'
                                        *   '<S107>/S-Function'
                                        *   '<S112>/S-Function'
                                        *   '<S114>/S-Function1'
                                        *   '<S131>/S-Function'
                                        *   '<S136>/S-Function'
                                        *   '<S138>/S-Function1'
                                        *   '<S150>/S-Function'
                                        *   '<S152>/S-Function1'
                                        *   '<S166>/S-Function1'
                                        *   '<S92>/S-Function1'
                                        *   '<S102>/S-Function'
                                        *   '<S126>/S-Function'
                                        */
  real_T th_vm_c[7];                   /* Variable: th_vm_c
                                        * Referenced by:
                                        *   '<S59>/S-Function'
                                        *   '<S169>/S-Function'
                                        */
  real_T CombustionChamber_A_total;    /* Mask Parameter: CombustionChamber_A_total
                                        * Referenced by: '<S63>/S-Function'
                                        */
  real_T CombustionChamber1_A_total;   /* Mask Parameter: CombustionChamber1_A_total
                                        * Referenced by: '<S71>/S-Function'
                                        */
  real_T HpStatewithHeatExchange_A_total;/* Mask Parameter: HpStatewithHeatExchange_A_total
                                          * Referenced by: '<S81>/S-Function'
                                          */
  real_T HPCTAH_A_total;               /* Mask Parameter: HPCTAH_A_total
                                        * Referenced by: '<S102>/S-Function'
                                        */
  real_T HpStatewithHeatExchange_A_tot_i;/* Mask Parameter: HpStatewithHeatExchange_A_tot_i
                                          * Referenced by: '<S107>/S-Function'
                                          */
  real_T LPCTAH_A_total;               /* Mask Parameter: LPCTAH_A_total
                                        * Referenced by: '<S126>/S-Function'
                                        */
  real_T HpStatewithHeatExchange_A_tot_d;/* Mask Parameter: HpStatewithHeatExchange_A_tot_d
                                          * Referenced by: '<S131>/S-Function'
                                          */
  real_T HpStatewithHeatLoss_A_total;  /* Mask Parameter: HpStatewithHeatLoss_A_total
                                        * Referenced by: '<S150>/S-Function'
                                        */
  real_T TpxState_Cp_liq[28];          /* Mask Parameter: TpxState_Cp_liq
                                        * Referenced by: '<S56>/S-Function1'
                                        */
  real_T TpxState_Cp_liq_n[28];        /* Mask Parameter: TpxState_Cp_liq_n
                                        * Referenced by: '<S92>/S-Function1'
                                        */
  real_T TpxState1_Cp_liq[28];         /* Mask Parameter: TpxState1_Cp_liq
                                        * Referenced by: '<S152>/S-Function1'
                                        */
  real_T TpxState_Cp_liq_d[28];        /* Mask Parameter: TpxState_Cp_liq_d
                                        * Referenced by: '<S166>/S-Function1'
                                        */
  real_T TpxState_Cp_liq_k[28];        /* Mask Parameter: TpxState_Cp_liq_k
                                        * Referenced by: '<S138>/S-Function1'
                                        */
  real_T TpxState_Cp_liq_l[28];        /* Mask Parameter: TpxState_Cp_liq_l
                                        * Referenced by: '<S114>/S-Function1'
                                        */
  real_T CombustionChamber_H_Loss;     /* Mask Parameter: CombustionChamber_H_Loss
                                        * Referenced by: '<S63>/S-Function'
                                        */
  real_T CombustionChamber1_H_Loss;    /* Mask Parameter: CombustionChamber1_H_Loss
                                        * Referenced by: '<S71>/S-Function'
                                        */
  real_T InitialCondition7_Hdot;       /* Mask Parameter: InitialCondition7_Hdot
                                        * Referenced by: '<S13>/Memory3'
                                        */
  real_T InitialCondition3_Hdot;       /* Mask Parameter: InitialCondition3_Hdot
                                        * Referenced by: '<S9>/Memory3'
                                        */
  real_T InitialCondition6_Hdot;       /* Mask Parameter: InitialCondition6_Hdot
                                        * Referenced by: '<S12>/Memory3'
                                        */
  real_T InitialCondition2_Hdot;       /* Mask Parameter: InitialCondition2_Hdot
                                        * Referenced by: '<S8>/Memory3'
                                        */
  real_T InitialCondition1_Hdot;       /* Mask Parameter: InitialCondition1_Hdot
                                        * Referenced by: '<S7>/Memory3'
                                        */
  real_T InitialCondition5_Hdot;       /* Mask Parameter: InitialCondition5_Hdot
                                        * Referenced by: '<S11>/Memory3'
                                        */
  real_T InitialCondition4_Hdot;       /* Mask Parameter: InitialCondition4_Hdot
                                        * Referenced by: '<S10>/Memory3'
                                        */
  real_T Mixer_Mode;                   /* Mask Parameter: Mixer_Mode
                                        * Referenced by: '<S147>/Constan'
                                        */
  real_T LPGasTurbine_Mode;            /* Mask Parameter: LPGasTurbine_Mode
                                        * Referenced by:
                                        *   '<S129>/T-normal1'
                                        *   '<S129>/T-normal2'
                                        */
  real_T CompressorPressureFeedback_Mode;/* Mask Parameter: CompressorPressureFeedback_Mode
                                          * Referenced by:
                                          *   '<S78>/Constant4'
                                          *   '<S78>/Constant8'
                                          */
  real_T HPGasTurbine_Mode;            /* Mask Parameter: HPGasTurbine_Mode
                                        * Referenced by:
                                        *   '<S105>/T-normal1'
                                        *   '<S105>/T-normal2'
                                        */
  real_T CompressorPressureFeedback_Pres[12];/* Mask Parameter: CompressorPressureFeedback_Pres
                                              * Referenced by: '<S88>/Lookup Table (2-D)1'
                                              */
  real_T CompressorPressureFeedback_RPM[3];/* Mask Parameter: CompressorPressureFeedback_RPM
                                            * Referenced by:
                                            *   '<S78>/Lookup Table (2-D)2'
                                            *   '<S88>/Lookup Table (2-D)1'
                                            */
  real_T CombustionChamber_T_env;      /* Mask Parameter: CombustionChamber_T_env
                                        * Referenced by: '<S63>/S-Function'
                                        */
  real_T CombustionChamber1_T_env;     /* Mask Parameter: CombustionChamber1_T_env
                                        * Referenced by: '<S71>/S-Function'
                                        */
  real_T HpStatewithHeatExchange_T_env;/* Mask Parameter: HpStatewithHeatExchange_T_env
                                        * Referenced by: '<S81>/S-Function'
                                        */
  real_T HPCTAH_T_env;                 /* Mask Parameter: HPCTAH_T_env
                                        * Referenced by: '<S102>/S-Function'
                                        */
  real_T HpStatewithHeatExchange_T_env_e;/* Mask Parameter: HpStatewithHeatExchange_T_env_e
                                          * Referenced by: '<S107>/S-Function'
                                          */
  real_T LPCTAH_T_env;                 /* Mask Parameter: LPCTAH_T_env
                                        * Referenced by: '<S126>/S-Function'
                                        */
  real_T HpStatewithHeatExchange_T_en_ei;/* Mask Parameter: HpStatewithHeatExchange_T_en_ei
                                          * Referenced by: '<S131>/S-Function'
                                          */
  real_T HpStatewithHeatLoss_T_env;    /* Mask Parameter: HpStatewithHeatLoss_T_env
                                        * Referenced by: '<S150>/S-Function'
                                        */
  real_T HpStatewithHeatExchange_T_initi;/* Mask Parameter: HpStatewithHeatExchange_T_initi
                                          * Referenced by: '<S63>/S-Function'
                                          */
  real_T HpStatewithHeatExchange_T_ini_h;/* Mask Parameter: HpStatewithHeatExchange_T_ini_h
                                          * Referenced by: '<S71>/S-Function'
                                          */
  real_T HpStatewithHeatExchange_T_ini_e;/* Mask Parameter: HpStatewithHeatExchange_T_ini_e
                                          * Referenced by: '<S81>/S-Function'
                                          */
  real_T SpState_T_initial;            /* Mask Parameter: SpState_T_initial
                                        * Referenced by: '<S84>/S-Function'
                                        */
  real_T HpStatewithHeatLoss_T_initial;/* Mask Parameter: HpStatewithHeatLoss_T_initial
                                        * Referenced by: '<S102>/S-Function'
                                        */
  real_T HpStatewithHeatExchange_T_ini_p;/* Mask Parameter: HpStatewithHeatExchange_T_ini_p
                                          * Referenced by: '<S107>/S-Function'
                                          */
  real_T SpState_T_initial_i;          /* Mask Parameter: SpState_T_initial_i
                                        * Referenced by: '<S112>/S-Function'
                                        */
  real_T HpStatewithHeatLoss_T_initial_d;/* Mask Parameter: HpStatewithHeatLoss_T_initial_d
                                          * Referenced by: '<S126>/S-Function'
                                          */
  real_T HpStatewithHeatExchange_T_ini_m;/* Mask Parameter: HpStatewithHeatExchange_T_ini_m
                                          * Referenced by: '<S131>/S-Function'
                                          */
  real_T SpState_T_initial_n;          /* Mask Parameter: SpState_T_initial_n
                                        * Referenced by: '<S136>/S-Function'
                                        */
  real_T HpStatewithHeatLoss_T_initial_b;/* Mask Parameter: HpStatewithHeatLoss_T_initial_b
                                          * Referenced by: '<S150>/S-Function'
                                          */
  real_T CompareToConstant5_const;     /* Mask Parameter: CompareToConstant5_const
                                        * Referenced by: '<S142>/Constant'
                                        */
  real_T CompareToConstant6_const;     /* Mask Parameter: CompareToConstant6_const
                                        * Referenced by: '<S143>/Constant'
                                        */
  real_T CompareToConstant1_const;     /* Mask Parameter: CompareToConstant1_const
                                        * Referenced by: '<S140>/Constant'
                                        */
  real_T CompareToConstant2_const;     /* Mask Parameter: CompareToConstant2_const
                                        * Referenced by: '<S141>/Constant'
                                        */
  real_T CompareToConstant3_const;     /* Mask Parameter: CompareToConstant3_const
                                        * Referenced by: '<S97>/Constant'
                                        */
  real_T CompareToConstant4_const;     /* Mask Parameter: CompareToConstant4_const
                                        * Referenced by: '<S98>/Constant'
                                        */
  real_T CompareToConstant1_const_m;   /* Mask Parameter: CompareToConstant1_const_m
                                        * Referenced by: '<S95>/Constant'
                                        */
  real_T CompareToConstant2_const_l;   /* Mask Parameter: CompareToConstant2_const_l
                                        * Referenced by: '<S96>/Constant'
                                        */
  real_T CompareToConstant5_const_m;   /* Mask Parameter: CompareToConstant5_const_m
                                        * Referenced by: '<S118>/Constant'
                                        */
  real_T CompareToConstant6_const_f;   /* Mask Parameter: CompareToConstant6_const_f
                                        * Referenced by: '<S119>/Constant'
                                        */
  real_T CompareToConstant1_const_h;   /* Mask Parameter: CompareToConstant1_const_h
                                        * Referenced by: '<S116>/Constant'
                                        */
  real_T CompareToConstant2_const_f;   /* Mask Parameter: CompareToConstant2_const_f
                                        * Referenced by: '<S117>/Constant'
                                        */
  real_T HPGasTurbine_efficiency[5];   /* Mask Parameter: HPGasTurbine_efficiency
                                        * Referenced by: '<S105>/Efficiency Lookup Table'
                                        */
  real_T LPGasTurbine_efficiency[5];   /* Mask Parameter: LPGasTurbine_efficiency
                                        * Referenced by: '<S129>/Efficiency Lookup Table'
                                        */
  real_T CompressorPressureFeedback_effi[12];/* Mask Parameter: CompressorPressureFeedback_effi
                                              * Referenced by: '<S78>/Lookup Table (2-D)2'
                                              */
  real_T HpStatewithHeatExchange_k;    /* Mask Parameter: HpStatewithHeatExchange_k
                                        * Referenced by: '<S81>/S-Function'
                                        */
  real_T HpStatewithHeatExchange_k_f;  /* Mask Parameter: HpStatewithHeatExchange_k_f
                                        * Referenced by: '<S107>/S-Function'
                                        */
  real_T HpStatewithHeatExchange_k_c;  /* Mask Parameter: HpStatewithHeatExchange_k_c
                                        * Referenced by: '<S131>/S-Function'
                                        */
  real_T HpStatewithHeatLoss_k;        /* Mask Parameter: HpStatewithHeatLoss_k
                                        * Referenced by: '<S150>/S-Function'
                                        */
  real_T HPCTAH_k_loss;                /* Mask Parameter: HPCTAH_k_loss
                                        * Referenced by: '<S102>/S-Function'
                                        */
  real_T LPCTAH_k_loss;                /* Mask Parameter: LPCTAH_k_loss
                                        * Referenced by: '<S126>/S-Function'
                                        */
  real_T CompressorPressureFeedback_mdot[4];/* Mask Parameter: CompressorPressureFeedback_mdot
                                             * Referenced by:
                                             *   '<S78>/Lookup Table (2-D)2'
                                             *   '<S88>/Lookup Table (2-D)1'
                                             */
  real_T HPGasTurbine_mdot2[5];        /* Mask Parameter: HPGasTurbine_mdot2
                                        * Referenced by: '<S105>/Efficiency Lookup Table'
                                        */
  real_T LPGasTurbine_mdot2[5];        /* Mask Parameter: LPGasTurbine_mdot2
                                        * Referenced by: '<S129>/Efficiency Lookup Table'
                                        */
  real_T InitialCondition7_ndot;       /* Mask Parameter: InitialCondition7_ndot
                                        * Referenced by: '<S13>/Memory9'
                                        */
  real_T InitialCondition3_ndot;       /* Mask Parameter: InitialCondition3_ndot
                                        * Referenced by: '<S9>/Memory9'
                                        */
  real_T InitialCondition6_ndot;       /* Mask Parameter: InitialCondition6_ndot
                                        * Referenced by: '<S12>/Memory9'
                                        */
  real_T InitialCondition2_ndot;       /* Mask Parameter: InitialCondition2_ndot
                                        * Referenced by: '<S8>/Memory9'
                                        */
  real_T InitialCondition1_ndot;       /* Mask Parameter: InitialCondition1_ndot
                                        * Referenced by: '<S7>/Memory9'
                                        */
  real_T InitialCondition5_ndot;       /* Mask Parameter: InitialCondition5_ndot
                                        * Referenced by: '<S11>/Memory9'
                                        */
  real_T InitialCondition4_ndot;       /* Mask Parameter: InitialCondition4_ndot
                                        * Referenced by: '<S10>/Memory9'
                                        */
  real_T Mixer_p_out_method;           /* Mask Parameter: Mixer_p_out_method
                                        * Referenced by: '<S147>/Constant'
                                        */
  real_T Ambientair_psi[7];            /* Mask Parameter: Ambientair_psi
                                        * Referenced by: '<S1>/psi'
                                        */
  real_T InitialCondition7_psi[7];     /* Mask Parameter: InitialCondition7_psi
                                        * Referenced by: '<S13>/Memory4'
                                        */
  real_T InitialCondition3_psi[7];     /* Mask Parameter: InitialCondition3_psi
                                        * Referenced by: '<S9>/Memory4'
                                        */
  real_T InitialCondition6_psi[7];     /* Mask Parameter: InitialCondition6_psi
                                        * Referenced by: '<S12>/Memory4'
                                        */
  real_T InitialCondition2_psi[7];     /* Mask Parameter: InitialCondition2_psi
                                        * Referenced by: '<S8>/Memory4'
                                        */
  real_T InitialCondition1_psi[7];     /* Mask Parameter: InitialCondition1_psi
                                        * Referenced by: '<S7>/Memory4'
                                        */
  real_T InitialCondition5_psi[7];     /* Mask Parameter: InitialCondition5_psi
                                        * Referenced by: '<S11>/Memory4'
                                        */
  real_T InitialCondition4_psi[7];     /* Mask Parameter: InitialCondition4_psi
                                        * Referenced by: '<S10>/Memory4'
                                        */
  real_T NaturalGas_psi[7];            /* Mask Parameter: NaturalGas_psi
                                        * Referenced by: '<S17>/psi'
                                        */
  real_T CombustionChamber_reaction[7];/* Mask Parameter: CombustionChamber_reaction
                                        * Referenced by: '<S62>/Reaction Coefficients'
                                        */
  real_T CombustionChamber1_reaction[7];/* Mask Parameter: CombustionChamber1_reaction
                                         * Referenced by: '<S70>/Reaction Coefficients'
                                         */
  real_T Divide2_value;                /* Mask Parameter: Divide2_value
                                        * Referenced by: '<S80>/Constant1'
                                        */
  real_T InitialCondition1_x[7];       /* Mask Parameter: InitialCondition1_x
                                        * Referenced by: '<S7>/Memory8'
                                        */
  real_T InitialCondition3_x[7];       /* Mask Parameter: InitialCondition3_x
                                        * Referenced by: '<S9>/Memory8'
                                        */
  real_T InitialCondition2_x[7];       /* Mask Parameter: InitialCondition2_x
                                        * Referenced by: '<S8>/Memory8'
                                        */
  real_T SFunction1_P9;                /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S57>/S-Function1'
                                        */
  real_T SFunction1_P10;               /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S57>/S-Function1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T SFunction_P17;                /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S59>/S-Function'
                                        */
  real_T nan_Y0;                       /* Expression: 0
                                        * Referenced by: '<S48>/nan'
                                        */
  real_T Sonstiges1_Value;             /* Expression: 0
                                        * Referenced by: '<S48>/Sonstiges1'
                                        */
  real_T SFunction1_P9_n;              /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S55>/S-Function1'
                                        */
  real_T SFunction1_P10_n;             /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S55>/S-Function1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1
                                        * Referenced by: '<S56>/Gain'
                                        */
  real_T Gain1_Gain;                   /* Expression: 1
                                        * Referenced by: '<S56>/Gain1'
                                        */
  real_T Gain2_Gain;                   /* Expression: 1
                                        * Referenced by: '<S56>/Gain2'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1
                                        * Referenced by: '<S56>/Gain3'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1
                                        * Referenced by: '<S56>/Gain4'
                                        */
  real_T SFunction1_P1[49];            /* Expression: nasa_1000_6000
                                        * Referenced by: '<S56>/S-Function1'
                                        */
  real_T SFunction1_P2[49];            /* Expression: nasa_200_1000
                                        * Referenced by: '<S56>/S-Function1'
                                        */
  real_T SFunction1_P12[24];           /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S56>/S-Function1'
                                        */
  real_T SFunction1_P13[21];           /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S56>/S-Function1'
                                        */
  real_T SFunction1_P14[504];          /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S56>/S-Function1'
                                        */
  real_T SFunction1_P15;               /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S56>/S-Function1'
                                        */
  real_T SFunction1_P21;               /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S56>/S-Function1'
                                        */
  real_T SFunction_P4[49];             /* Expression: [th_NASA_A1_g; th_NASA_B1_g; th_NASA_C1_g; th_NASA_D1_g; th_NASA_E1_g; th_NASA_F1_g; th_NASA_G1_g]'
                                        * Referenced by: '<S63>/S-Function'
                                        */
  real_T SFunction_P5[49];             /* Expression: [th_NASA_A2_g; th_NASA_B2_g; th_NASA_C2_g; th_NASA_D2_g; th_NASA_E2_g; th_NASA_F2_g; th_NASA_G2_g]'
                                        * Referenced by: '<S63>/S-Function'
                                        */
  real_T SFunction_P12[28];            /* Expression: [th_Cp_liq_A; th_Cp_liq_B; th_Cp_liq_C; th_Cp_liq_D]'
                                        * Referenced by: '<S63>/S-Function'
                                        */
  real_T SFunction_P17_g[24];          /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S63>/S-Function'
                                        */
  real_T SFunction_P18[21];            /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S63>/S-Function'
                                        */
  real_T SFunction_P19[504];           /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S63>/S-Function'
                                        */
  real_T SFunction_P20;                /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S63>/S-Function'
                                        */
  real_T SFunction_P28;                /* Expression: derivative_neighbor_factor
                                        * Referenced by: '<S63>/S-Function'
                                        */
  real_T SFunction_P33;                /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S63>/S-Function'
                                        */
  real_T SFunction_P4_h[49];           /* Expression: [th_NASA_A1_g; th_NASA_B1_g; th_NASA_C1_g; th_NASA_D1_g; th_NASA_E1_g; th_NASA_F1_g; th_NASA_G1_g]'
                                        * Referenced by: '<S71>/S-Function'
                                        */
  real_T SFunction_P5_a[49];           /* Expression: [th_NASA_A2_g; th_NASA_B2_g; th_NASA_C2_g; th_NASA_D2_g; th_NASA_E2_g; th_NASA_F2_g; th_NASA_G2_g]'
                                        * Referenced by: '<S71>/S-Function'
                                        */
  real_T SFunction_P12_a[28];          /* Expression: [th_Cp_liq_A; th_Cp_liq_B; th_Cp_liq_C; th_Cp_liq_D]'
                                        * Referenced by: '<S71>/S-Function'
                                        */
  real_T SFunction_P17_g3[24];         /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S71>/S-Function'
                                        */
  real_T SFunction_P18_p[21];          /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S71>/S-Function'
                                        */
  real_T SFunction_P19_k[504];         /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S71>/S-Function'
                                        */
  real_T SFunction_P20_h;              /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S71>/S-Function'
                                        */
  real_T SFunction_P28_j;              /* Expression: derivative_neighbor_factor
                                        * Referenced by: '<S71>/S-Function'
                                        */
  real_T SFunction_P33_m;              /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S71>/S-Function'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: max_mdot
                                        * Referenced by: '<S86>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S86>/Saturation1'
                                        */
  real_T Constant3_Value;              /* Expression: 1
                                        * Referenced by: '<S86>/Constant3'
                                        */
  real_T Constant6_Value;              /* Expression: p_refrence
                                        * Referenced by: '<S78>/Constant6'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S80>/Constant'
                                        */
  real_T SFunction_P4_p[49];           /* Expression: [th_NASA_A1_g; th_NASA_B1_g; th_NASA_C1_g; th_NASA_D1_g; th_NASA_E1_g; th_NASA_F1_g; th_NASA_G1_g]'
                                        * Referenced by: '<S81>/S-Function'
                                        */
  real_T SFunction_P5_k[49];           /* Expression: [th_NASA_A2_g; th_NASA_B2_g; th_NASA_C2_g; th_NASA_D2_g; th_NASA_E2_g; th_NASA_F2_g; th_NASA_G2_g]'
                                        * Referenced by: '<S81>/S-Function'
                                        */
  real_T SFunction_P12_d[28];          /* Expression: [th_Cp_liq_A; th_Cp_liq_B; th_Cp_liq_C; th_Cp_liq_D]'
                                        * Referenced by: '<S81>/S-Function'
                                        */
  real_T SFunction_P17_p[24];          /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S81>/S-Function'
                                        */
  real_T SFunction_P18_m[21];          /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S81>/S-Function'
                                        */
  real_T SFunction_P19_i[504];         /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S81>/S-Function'
                                        */
  real_T SFunction_P20_l;              /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S81>/S-Function'
                                        */
  real_T SFunction_P28_k;              /* Expression: derivative_neighbor_factor
                                        * Referenced by: '<S81>/S-Function'
                                        */
  real_T SFunction_P33_f;              /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S81>/S-Function'
                                        */
  real_T SFunction_P4_n[49];           /* Expression: [th_NASA_A1_g; th_NASA_B1_g; th_NASA_C1_g; th_NASA_D1_g; th_NASA_E1_g; th_NASA_F1_g; th_NASA_G1_g]'
                                        * Referenced by: '<S84>/S-Function'
                                        */
  real_T SFunction_P5_aq[49];          /* Expression: [th_NASA_A2_g; th_NASA_B2_g; th_NASA_C2_g; th_NASA_D2_g; th_NASA_E2_g; th_NASA_F2_g; th_NASA_G2_g]'
                                        * Referenced by: '<S84>/S-Function'
                                        */
  real_T SFunction_P12_h[28];          /* Expression: [th_Cp_liq_A; th_Cp_liq_B; th_Cp_liq_C; th_Cp_liq_D]'
                                        * Referenced by: '<S84>/S-Function'
                                        */
  real_T SFunction_P17_d[24];          /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S84>/S-Function'
                                        */
  real_T SFunction_P18_h[21];          /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S84>/S-Function'
                                        */
  real_T SFunction_P19_c[504];         /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S84>/S-Function'
                                        */
  real_T SFunction_P20_h3;             /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S84>/S-Function'
                                        */
  real_T SFunction_P25;                /* Expression: derivative_neighbor_factor
                                        * Referenced by: '<S84>/S-Function'
                                        */
  real_T SFunction_P30;                /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S84>/S-Function'
                                        */
  real_T SFunction1_P9_e;              /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S91>/S-Function1'
                                        */
  real_T SFunction1_P10_j;             /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S91>/S-Function1'
                                        */
  real_T Gain_Gain_j;                  /* Expression: 1
                                        * Referenced by: '<S92>/Gain'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S92>/Gain1'
                                        */
  real_T Gain2_Gain_m;                 /* Expression: 1
                                        * Referenced by: '<S92>/Gain2'
                                        */
  real_T Gain3_Gain_m;                 /* Expression: 1
                                        * Referenced by: '<S92>/Gain3'
                                        */
  real_T Gain4_Gain_i;                 /* Expression: 1
                                        * Referenced by: '<S92>/Gain4'
                                        */
  real_T SFunction1_P1_l[49];          /* Expression: nasa_1000_6000
                                        * Referenced by: '<S92>/S-Function1'
                                        */
  real_T SFunction1_P2_o[49];          /* Expression: nasa_200_1000
                                        * Referenced by: '<S92>/S-Function1'
                                        */
  real_T SFunction1_P12_f[24];         /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S92>/S-Function1'
                                        */
  real_T SFunction1_P13_f[21];         /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S92>/S-Function1'
                                        */
  real_T SFunction1_P14_o[504];        /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S92>/S-Function1'
                                        */
  real_T SFunction1_P15_a;             /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S92>/S-Function1'
                                        */
  real_T SFunction1_P21_k;             /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S92>/S-Function1'
                                        */
  real_T SFunction_P4_a[49];           /* Expression: [th_NASA_A1_g; th_NASA_B1_g; th_NASA_C1_g; th_NASA_D1_g; th_NASA_E1_g; th_NASA_F1_g; th_NASA_G1_g]'
                                        * Referenced by: '<S102>/S-Function'
                                        */
  real_T SFunction_P5_l[49];           /* Expression: [th_NASA_A2_g; th_NASA_B2_g; th_NASA_C2_g; th_NASA_D2_g; th_NASA_E2_g; th_NASA_F2_g; th_NASA_G2_g]'
                                        * Referenced by: '<S102>/S-Function'
                                        */
  real_T SFunction_P12_e[28];          /* Expression: [th_Cp_liq_A; th_Cp_liq_B; th_Cp_liq_C; th_Cp_liq_D]'
                                        * Referenced by: '<S102>/S-Function'
                                        */
  real_T SFunction_P17_pk[24];         /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S102>/S-Function'
                                        */
  real_T SFunction_P18_b[21];          /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S102>/S-Function'
                                        */
  real_T SFunction_P19_g[504];         /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S102>/S-Function'
                                        */
  real_T SFunction_P20_lh;             /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S102>/S-Function'
                                        */
  real_T SFunction_P28_a;              /* Expression: derivative_neighbor_factor
                                        * Referenced by: '<S102>/S-Function'
                                        */
  real_T SFunction_P33_n;              /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S102>/S-Function'
                                        */
  real_T LookupTable2D2_RowIdx[6];     /* Expression: RPM
                                        * Referenced by: '<S108>/Lookup Table (2-D)2'
                                        */
  real_T LookupTable2D2_ColIdx[21];    /* Expression: PR_break
                                        * Referenced by: '<S108>/Lookup Table (2-D)2'
                                        */
  real_T LookupTable2D2_Table[126];    /* Expression: eta_table
                                        * Referenced by: '<S108>/Lookup Table (2-D)2'
                                        */
  real_T Saturation1_UpperSat_k;       /* Expression: 100
                                        * Referenced by: '<S108>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_d;       /* Expression: 1
                                        * Referenced by: '<S108>/Saturation1'
                                        */
  real_T LookupTable2D_RowIdx[6];      /* Expression: RPM
                                        * Referenced by: '<S108>/Lookup Table (2-D)'
                                        */
  real_T LookupTable2D_ColIdx[21];     /* Expression: PR_break
                                        * Referenced by: '<S108>/Lookup Table (2-D)'
                                        */
  real_T LookupTable2D_Table[126];     /* Expression: mdot_table
                                        * Referenced by: '<S108>/Lookup Table (2-D)'
                                        */
  real_T Constant2_Value;              /* Expression: min(RPM)
                                        * Referenced by: '<S108>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: max(RPM)
                                        * Referenced by: '<S108>/Constant1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: inf
                                        * Referenced by: '<S108>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<S108>/Saturation'
                                        */
  real_T pnormal_Value;                /* Expression: Ref_Cond(2)
                                        * Referenced by: '<S105>/p-normal'
                                        */
  real_T SFunction_P4_aj[49];          /* Expression: [th_NASA_A1_g; th_NASA_B1_g; th_NASA_C1_g; th_NASA_D1_g; th_NASA_E1_g; th_NASA_F1_g; th_NASA_G1_g]'
                                        * Referenced by: '<S107>/S-Function'
                                        */
  real_T SFunction_P5_j[49];           /* Expression: [th_NASA_A2_g; th_NASA_B2_g; th_NASA_C2_g; th_NASA_D2_g; th_NASA_E2_g; th_NASA_F2_g; th_NASA_G2_g]'
                                        * Referenced by: '<S107>/S-Function'
                                        */
  real_T SFunction_P12_j[28];          /* Expression: [th_Cp_liq_A; th_Cp_liq_B; th_Cp_liq_C; th_Cp_liq_D]'
                                        * Referenced by: '<S107>/S-Function'
                                        */
  real_T SFunction_P17_i[24];          /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S107>/S-Function'
                                        */
  real_T SFunction_P18_pk[21];         /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S107>/S-Function'
                                        */
  real_T SFunction_P19_h[504];         /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S107>/S-Function'
                                        */
  real_T SFunction_P20_m;              /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S107>/S-Function'
                                        */
  real_T SFunction_P28_m;              /* Expression: derivative_neighbor_factor
                                        * Referenced by: '<S107>/S-Function'
                                        */
  real_T SFunction_P33_e;              /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S107>/S-Function'
                                        */
  real_T Constant4_Value;              /* Expression: min(RPM)
                                        * Referenced by: '<S108>/Constant4'
                                        */
  real_T SFunction_P4_hl[49];          /* Expression: [th_NASA_A1_g; th_NASA_B1_g; th_NASA_C1_g; th_NASA_D1_g; th_NASA_E1_g; th_NASA_F1_g; th_NASA_G1_g]'
                                        * Referenced by: '<S112>/S-Function'
                                        */
  real_T SFunction_P5_m[49];           /* Expression: [th_NASA_A2_g; th_NASA_B2_g; th_NASA_C2_g; th_NASA_D2_g; th_NASA_E2_g; th_NASA_F2_g; th_NASA_G2_g]'
                                        * Referenced by: '<S112>/S-Function'
                                        */
  real_T SFunction_P12_o[28];          /* Expression: [th_Cp_liq_A; th_Cp_liq_B; th_Cp_liq_C; th_Cp_liq_D]'
                                        * Referenced by: '<S112>/S-Function'
                                        */
  real_T SFunction_P17_o[24];          /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S112>/S-Function'
                                        */
  real_T SFunction_P18_c[21];          /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S112>/S-Function'
                                        */
  real_T SFunction_P19_e[504];         /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S112>/S-Function'
                                        */
  real_T SFunction_P20_b;              /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S112>/S-Function'
                                        */
  real_T SFunction_P25_k;              /* Expression: derivative_neighbor_factor
                                        * Referenced by: '<S112>/S-Function'
                                        */
  real_T SFunction_P30_e;              /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S112>/S-Function'
                                        */
  real_T Constant1_Value_g;            /* Expression: 1
                                        * Referenced by: '<S105>/Constant1'
                                        */
  real_T SFunction_P4_nq[49];          /* Expression: [th_NASA_A1_g; th_NASA_B1_g; th_NASA_C1_g; th_NASA_D1_g; th_NASA_E1_g; th_NASA_F1_g; th_NASA_G1_g]'
                                        * Referenced by: '<S126>/S-Function'
                                        */
  real_T SFunction_P5_c[49];           /* Expression: [th_NASA_A2_g; th_NASA_B2_g; th_NASA_C2_g; th_NASA_D2_g; th_NASA_E2_g; th_NASA_F2_g; th_NASA_G2_g]'
                                        * Referenced by: '<S126>/S-Function'
                                        */
  real_T SFunction_P12_e5[28];         /* Expression: [th_Cp_liq_A; th_Cp_liq_B; th_Cp_liq_C; th_Cp_liq_D]'
                                        * Referenced by: '<S126>/S-Function'
                                        */
  real_T SFunction_P17_dx[24];         /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S126>/S-Function'
                                        */
  real_T SFunction_P18_j[21];          /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S126>/S-Function'
                                        */
  real_T SFunction_P19_d[504];         /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S126>/S-Function'
                                        */
  real_T SFunction_P20_bp;             /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S126>/S-Function'
                                        */
  real_T SFunction_P28_d;              /* Expression: derivative_neighbor_factor
                                        * Referenced by: '<S126>/S-Function'
                                        */
  real_T SFunction_P33_a;              /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S126>/S-Function'
                                        */
  real_T LookupTable2D2_RowIdx_d[6];   /* Expression: RPM
                                        * Referenced by: '<S132>/Lookup Table (2-D)2'
                                        */
  real_T LookupTable2D2_ColIdx_g[21];  /* Expression: PR_break
                                        * Referenced by: '<S132>/Lookup Table (2-D)2'
                                        */
  real_T LookupTable2D2_Table_l[126];  /* Expression: eta_table
                                        * Referenced by: '<S132>/Lookup Table (2-D)2'
                                        */
  real_T Saturation1_UpperSat_m;       /* Expression: 100
                                        * Referenced by: '<S132>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: 1
                                        * Referenced by: '<S132>/Saturation1'
                                        */
  real_T LookupTable2D_RowIdx_i[6];    /* Expression: RPM
                                        * Referenced by: '<S132>/Lookup Table (2-D)'
                                        */
  real_T LookupTable2D_ColIdx_h[21];   /* Expression: PR_break
                                        * Referenced by: '<S132>/Lookup Table (2-D)'
                                        */
  real_T LookupTable2D_Table_l[126];   /* Expression: mdot_table
                                        * Referenced by: '<S132>/Lookup Table (2-D)'
                                        */
  real_T Constant2_Value_e;            /* Expression: min(RPM)
                                        * Referenced by: '<S132>/Constant2'
                                        */
  real_T Constant1_Value_h;            /* Expression: max(RPM)
                                        * Referenced by: '<S132>/Constant1'
                                        */
  real_T Saturation_UpperSat_e;        /* Expression: inf
                                        * Referenced by: '<S132>/Saturation'
                                        */
  real_T Saturation_LowerSat_i;        /* Expression: 0
                                        * Referenced by: '<S132>/Saturation'
                                        */
  real_T pnormal_Value_k;              /* Expression: Ref_Cond(2)
                                        * Referenced by: '<S129>/p-normal'
                                        */
  real_T SFunction_P4_hi[49];          /* Expression: [th_NASA_A1_g; th_NASA_B1_g; th_NASA_C1_g; th_NASA_D1_g; th_NASA_E1_g; th_NASA_F1_g; th_NASA_G1_g]'
                                        * Referenced by: '<S131>/S-Function'
                                        */
  real_T SFunction_P5_b[49];           /* Expression: [th_NASA_A2_g; th_NASA_B2_g; th_NASA_C2_g; th_NASA_D2_g; th_NASA_E2_g; th_NASA_F2_g; th_NASA_G2_g]'
                                        * Referenced by: '<S131>/S-Function'
                                        */
  real_T SFunction_P12_b[28];          /* Expression: [th_Cp_liq_A; th_Cp_liq_B; th_Cp_liq_C; th_Cp_liq_D]'
                                        * Referenced by: '<S131>/S-Function'
                                        */
  real_T SFunction_P17_n[24];          /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S131>/S-Function'
                                        */
  real_T SFunction_P18_cy[21];         /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S131>/S-Function'
                                        */
  real_T SFunction_P19_go[504];        /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S131>/S-Function'
                                        */
  real_T SFunction_P20_k;              /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S131>/S-Function'
                                        */
  real_T SFunction_P28_mt;             /* Expression: derivative_neighbor_factor
                                        * Referenced by: '<S131>/S-Function'
                                        */
  real_T SFunction_P33_l;              /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S131>/S-Function'
                                        */
  real_T Constant4_Value_d;            /* Expression: min(RPM)
                                        * Referenced by: '<S132>/Constant4'
                                        */
  real_T SFunction_P4_g[49];           /* Expression: [th_NASA_A1_g; th_NASA_B1_g; th_NASA_C1_g; th_NASA_D1_g; th_NASA_E1_g; th_NASA_F1_g; th_NASA_G1_g]'
                                        * Referenced by: '<S136>/S-Function'
                                        */
  real_T SFunction_P5_n[49];           /* Expression: [th_NASA_A2_g; th_NASA_B2_g; th_NASA_C2_g; th_NASA_D2_g; th_NASA_E2_g; th_NASA_F2_g; th_NASA_G2_g]'
                                        * Referenced by: '<S136>/S-Function'
                                        */
  real_T SFunction_P12_i[28];          /* Expression: [th_Cp_liq_A; th_Cp_liq_B; th_Cp_liq_C; th_Cp_liq_D]'
                                        * Referenced by: '<S136>/S-Function'
                                        */
  real_T SFunction_P17_k[24];          /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S136>/S-Function'
                                        */
  real_T SFunction_P18_n[21];          /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S136>/S-Function'
                                        */
  real_T SFunction_P19_j[504];         /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S136>/S-Function'
                                        */
  real_T SFunction_P20_e;              /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S136>/S-Function'
                                        */
  real_T SFunction_P25_p;              /* Expression: derivative_neighbor_factor
                                        * Referenced by: '<S136>/S-Function'
                                        */
  real_T SFunction_P30_a;              /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S136>/S-Function'
                                        */
  real_T Constant1_Value_e;            /* Expression: 1
                                        * Referenced by: '<S129>/Constant1'
                                        */
  real_T meanifndot1and2arezero_Gain;  /* Expression: 0.5
                                        * Referenced by: '<S147>/mean if ndot1 and 2 are zero'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: inf
                                        * Referenced by: '<S147>/Saturation'
                                        */
  real_T Saturation_LowerSat_m;        /* Expression: 1e-19
                                        * Referenced by: '<S147>/Saturation'
                                        */
  real_T meanifndot1and20_Gain;        /* Expression: 0.5
                                        * Referenced by: '<S147>/mean if ndot1 and 2=0'
                                        */
  real_T Constant_Value_b;             /* Expression: 1
                                        * Referenced by: '<S149>/Constant'
                                        */
  real_T ratio_Value;                  /* Expression: 1
                                        * Referenced by: '<S16>/ratio'
                                        */
  real_T SFunction_P4_o[49];           /* Expression: [th_NASA_A1_g; th_NASA_B1_g; th_NASA_C1_g; th_NASA_D1_g; th_NASA_E1_g; th_NASA_F1_g; th_NASA_G1_g]'
                                        * Referenced by: '<S150>/S-Function'
                                        */
  real_T SFunction_P5_o[49];           /* Expression: [th_NASA_A2_g; th_NASA_B2_g; th_NASA_C2_g; th_NASA_D2_g; th_NASA_E2_g; th_NASA_F2_g; th_NASA_G2_g]'
                                        * Referenced by: '<S150>/S-Function'
                                        */
  real_T SFunction_P12_p[28];          /* Expression: [th_Cp_liq_A; th_Cp_liq_B; th_Cp_liq_C; th_Cp_liq_D]'
                                        * Referenced by: '<S150>/S-Function'
                                        */
  real_T SFunction_P17_po[24];         /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S150>/S-Function'
                                        */
  real_T SFunction_P18_f[21];          /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S150>/S-Function'
                                        */
  real_T SFunction_P19_goy[504];       /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S150>/S-Function'
                                        */
  real_T SFunction_P20_e4;             /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S150>/S-Function'
                                        */
  real_T SFunction_P28_h;              /* Expression: derivative_neighbor_factor
                                        * Referenced by: '<S150>/S-Function'
                                        */
  real_T SFunction_P33_no;             /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S150>/S-Function'
                                        */
  real_T Gain2_Gain_a;                 /* Expression: 1
                                        * Referenced by: '<S152>/Gain2'
                                        */
  real_T Gain_Gain_o;                  /* Expression: 1
                                        * Referenced by: '<S152>/Gain'
                                        */
  real_T Gain4_Gain_o;                 /* Expression: 1
                                        * Referenced by: '<S152>/Gain4'
                                        */
  real_T Constant_Value_i;             /* Expression: 0
                                        * Referenced by: '<S148>/Constant'
                                        */
  real_T Constant_Value_f;             /* Expression: 0
                                        * Referenced by: '<S153>/Constant'
                                        */
  real_T Gain_Gain_a;                  /* Expression: P_Loss(1)
                                        * Referenced by: '<S151>/Gain'
                                        */
  real_T p_downstrem_min_Value;        /* Expression: P_Loss(2)
                                        * Referenced by: '<S151>/p_downstrem_min'
                                        */
  real_T Saturation_UpperSat_i;        /* Expression: inf
                                        * Referenced by: '<S151>/Saturation'
                                        */
  real_T Saturation_LowerSat_mf;       /* Expression: 0
                                        * Referenced by: '<S151>/Saturation'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S152>/Gain1'
                                        */
  real_T Gain3_Gain_d;                 /* Expression: 1
                                        * Referenced by: '<S152>/Gain3'
                                        */
  real_T SFunction1_P1_p[49];          /* Expression: nasa_1000_6000
                                        * Referenced by: '<S152>/S-Function1'
                                        */
  real_T SFunction1_P2_d[49];          /* Expression: nasa_200_1000
                                        * Referenced by: '<S152>/S-Function1'
                                        */
  real_T SFunction1_P12_j[24];         /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S152>/S-Function1'
                                        */
  real_T SFunction1_P13_g[21];         /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S152>/S-Function1'
                                        */
  real_T SFunction1_P14_m[504];        /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S152>/S-Function1'
                                        */
  real_T SFunction1_P15_g;             /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S152>/S-Function1'
                                        */
  real_T SFunction1_P21_ke;            /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S152>/S-Function1'
                                        */
  real_T SFunction1_P9_p;              /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S167>/S-Function1'
                                        */
  real_T SFunction1_P10_c;             /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S167>/S-Function1'
                                        */
  real_T Constant_Value_bv;            /* Expression: 1
                                        * Referenced by: '<S168>/Constant'
                                        */
  real_T SFunction_P17_p5;             /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S169>/S-Function'
                                        */
  real_T nan_Y0_f;                     /* Expression: 0
                                        * Referenced by: '<S158>/nan'
                                        */
  real_T Sonstiges1_Value_l;           /* Expression: 0
                                        * Referenced by: '<S158>/Sonstiges1'
                                        */
  real_T SFunction1_P9_nq;             /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S165>/S-Function1'
                                        */
  real_T SFunction1_P10_i;             /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S165>/S-Function1'
                                        */
  real_T Gain_Gain_b;                  /* Expression: 1
                                        * Referenced by: '<S166>/Gain'
                                        */
  real_T Gain1_Gain_l;                 /* Expression: 1
                                        * Referenced by: '<S166>/Gain1'
                                        */
  real_T Gain2_Gain_j;                 /* Expression: 1
                                        * Referenced by: '<S166>/Gain2'
                                        */
  real_T Gain3_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S166>/Gain3'
                                        */
  real_T Gain4_Gain_iu;                /* Expression: 1
                                        * Referenced by: '<S166>/Gain4'
                                        */
  real_T SFunction1_P1_l5[49];         /* Expression: nasa_1000_6000
                                        * Referenced by: '<S166>/S-Function1'
                                        */
  real_T SFunction1_P2_k[49];          /* Expression: nasa_200_1000
                                        * Referenced by: '<S166>/S-Function1'
                                        */
  real_T SFunction1_P12_e[24];         /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S166>/S-Function1'
                                        */
  real_T SFunction1_P13_b[21];         /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S166>/S-Function1'
                                        */
  real_T SFunction1_P14_me[504];       /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S166>/S-Function1'
                                        */
  real_T SFunction1_P15_l;             /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S166>/S-Function1'
                                        */
  real_T SFunction1_P21_kg;            /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S166>/S-Function1'
                                        */
  real_T additionfactor1_Value;        /* Expression: add_fac
                                        * Referenced by: '<S32>/addition factor1'
                                        */
  real_T Constant1_Value_d;            /* Expression: flow_type
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T UnitScale_Gain;               /* Expression: unit_scale
                                        * Referenced by: '<S50>/UnitScale'
                                        */
  real_T UnitOffset_Bias;              /* Expression: unit_offset
                                        * Referenced by: '<S50>/UnitOffset'
                                        */
  real_T UnitScale_Gain_i;             /* Expression: unit_scale
                                        * Referenced by: '<S51>/UnitScale'
                                        */
  real_T UnitOffset_Bias_c;            /* Expression: unit_offset
                                        * Referenced by: '<S51>/UnitOffset'
                                        */
  real_T UnitScale_Gain_o;             /* Expression: unit_scale
                                        * Referenced by: '<S52>/UnitScale'
                                        */
  real_T UnitOffset_Bias_m;            /* Expression: unit_offset
                                        * Referenced by: '<S52>/UnitOffset'
                                        */
  real_T Gain2_Gain_a3;                /* Expression: 0.001
                                        * Referenced by: '<S32>/Gain2'
                                        */
  real_T Gain1_Gain_g;                 /* Expression: mult_fac
                                        * Referenced by: '<S32>/Gain1'
                                        */
  real_T additionfactor1_Value_m;      /* Expression: add_fac
                                        * Referenced by: '<S31>/addition factor1'
                                        */
  real_T Gain1_Gain_l3;                /* Expression: mult_fac
                                        * Referenced by: '<S31>/Gain1'
                                        */
  real_T additionfactor1_Value_o;      /* Expression: add_fac
                                        * Referenced by: '<S33>/addition factor1'
                                        */
  real_T Gain1_Gain_c;                 /* Expression: mult_fac
                                        * Referenced by: '<S33>/Gain1'
                                        */
  real_T additionfactor1_Value_p;      /* Expression: add_fac
                                        * Referenced by: '<S34>/addition factor1'
                                        */
  real_T Gain1_Gain_ln;                /* Expression: mult_fac
                                        * Referenced by: '<S34>/Gain1'
                                        */
  real_T Constant2_Value_c;            /* Expression: 10^-6
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T additionfactor1_Value_f;      /* Expression: add_fac
                                        * Referenced by: '<S19>/addition factor1'
                                        */
  real_T Gain2_Gain_mh;                /* Expression: 0.001
                                        * Referenced by: '<S19>/Gain2'
                                        */
  real_T Gain1_Gain_p;                 /* Expression: mult_fac
                                        * Referenced by: '<S19>/Gain1'
                                        */
  real_T additionfactor1_Value_k;      /* Expression: add_fac
                                        * Referenced by: '<S18>/addition factor1'
                                        */
  real_T Memory1_X0;                   /* Expression: T
                                        * Referenced by: '<S13>/Memory1'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: mult_fac
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real_T additionfactor1_Value_mr;     /* Expression: add_fac
                                        * Referenced by: '<S30>/addition factor1'
                                        */
  real_T Memory2_X0;                   /* Expression: p
                                        * Referenced by: '<S13>/Memory2'
                                        */
  real_T Gain1_Gain_lj;                /* Expression: mult_fac
                                        * Referenced by: '<S30>/Gain1'
                                        */
  real_T additionfactor1_Value_d;      /* Expression: add_fac
                                        * Referenced by: '<S39>/addition factor1'
                                        */
  real_T Gain1_Gain_m;                 /* Expression: mult_fac
                                        * Referenced by: '<S39>/Gain1'
                                        */
  real_T Constant3_Value_d;            /* Expression: 10^-6
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T additionfactor1_Value_h;      /* Expression: add_fac
                                        * Referenced by: '<S41>/addition factor1'
                                        */
  real_T Gain2_Gain_g;                 /* Expression: 0.001
                                        * Referenced by: '<S41>/Gain2'
                                        */
  real_T Gain1_Gain_g2;                /* Expression: mult_fac
                                        * Referenced by: '<S41>/Gain1'
                                        */
  real_T additionfactor1_Value_md;     /* Expression: add_fac
                                        * Referenced by: '<S40>/addition factor1'
                                        */
  real_T Memory1_X0_n;                 /* Expression: T
                                        * Referenced by: '<S9>/Memory1'
                                        */
  real_T Gain1_Gain_lr;                /* Expression: mult_fac
                                        * Referenced by: '<S40>/Gain1'
                                        */
  real_T additionfactor1_Value_c;      /* Expression: add_fac
                                        * Referenced by: '<S42>/addition factor1'
                                        */
  real_T Memory2_X0_d;                 /* Expression: p
                                        * Referenced by: '<S9>/Memory2'
                                        */
  real_T Gain1_Gain_mv;                /* Expression: mult_fac
                                        * Referenced by: '<S42>/Gain1'
                                        */
  real_T additionfactor1_Value_b;      /* Expression: add_fac
                                        * Referenced by: '<S43>/addition factor1'
                                        */
  real_T Gain1_Gain_e;                 /* Expression: mult_fac
                                        * Referenced by: '<S43>/Gain1'
                                        */
  real_T Constant5_Value;              /* Expression: 10^-6
                                        * Referenced by: '<Root>/Constant5'
                                        */
  real_T additionfactor1_Value_kh;     /* Expression: add_fac
                                        * Referenced by: '<S45>/addition factor1'
                                        */
  real_T Gain2_Gain_o;                 /* Expression: 0.001
                                        * Referenced by: '<S45>/Gain2'
                                        */
  real_T Gain1_Gain_n0;                /* Expression: mult_fac
                                        * Referenced by: '<S45>/Gain1'
                                        */
  real_T additionfactor1_Value_ok;     /* Expression: add_fac
                                        * Referenced by: '<S44>/addition factor1'
                                        */
  real_T Memory1_X0_i;                 /* Expression: T
                                        * Referenced by: '<S12>/Memory1'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: mult_fac
                                        * Referenced by: '<S44>/Gain1'
                                        */
  real_T additionfactor1_Value_f1;     /* Expression: add_fac
                                        * Referenced by: '<S20>/addition factor1'
                                        */
  real_T Memory2_X0_j;                 /* Expression: p
                                        * Referenced by: '<S12>/Memory2'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: mult_fac
                                        * Referenced by: '<S20>/Gain1'
                                        */
  real_T additionfactor1_Value_kx;     /* Expression: add_fac
                                        * Referenced by: '<S21>/addition factor1'
                                        */
  real_T Gain1_Gain_k3;                /* Expression: mult_fac
                                        * Referenced by: '<S21>/Gain1'
                                        */
  real_T Constant6_Value_l;            /* Expression: 10^-6
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T additionfactor1_Value_b5;     /* Expression: add_fac
                                        * Referenced by: '<S25>/addition factor1'
                                        */
  real_T Gain2_Gain_as;                /* Expression: 0.001
                                        * Referenced by: '<S25>/Gain2'
                                        */
  real_T Gain1_Gain_k0;                /* Expression: mult_fac
                                        * Referenced by: '<S25>/Gain1'
                                        */
  real_T additionfactor1_Value_d1;     /* Expression: add_fac
                                        * Referenced by: '<S24>/addition factor1'
                                        */
  real_T Memory1_X0_o;                 /* Expression: T
                                        * Referenced by: '<S8>/Memory1'
                                        */
  real_T Gain1_Gain_ea;                /* Expression: mult_fac
                                        * Referenced by: '<S24>/Gain1'
                                        */
  real_T additionfactor1_Value_g;      /* Expression: add_fac
                                        * Referenced by: '<S22>/addition factor1'
                                        */
  real_T Memory2_X0_p;                 /* Expression: p
                                        * Referenced by: '<S8>/Memory2'
                                        */
  real_T Gain1_Gain_b;                 /* Expression: mult_fac
                                        * Referenced by: '<S22>/Gain1'
                                        */
  real_T additionfactor1_Value_l;      /* Expression: add_fac
                                        * Referenced by: '<S23>/addition factor1'
                                        */
  real_T Gain1_Gain_fe;                /* Expression: mult_fac
                                        * Referenced by: '<S23>/Gain1'
                                        */
  real_T Constant7_Value;              /* Expression: 10^-6
                                        * Referenced by: '<Root>/Constant7'
                                        */
  real_T additionfactor1_Value_fu;     /* Expression: add_fac
                                        * Referenced by: '<S29>/addition factor1'
                                        */
  real_T Gain2_Gain_e;                 /* Expression: 0.001
                                        * Referenced by: '<S29>/Gain2'
                                        */
  real_T Gain1_Gain_nb;                /* Expression: mult_fac
                                        * Referenced by: '<S29>/Gain1'
                                        */
  real_T additionfactor1_Value_e;      /* Expression: add_fac
                                        * Referenced by: '<S28>/addition factor1'
                                        */
  real_T Memory1_X0_l;                 /* Expression: T
                                        * Referenced by: '<S7>/Memory1'
                                        */
  real_T Gain1_Gain_ck;                /* Expression: mult_fac
                                        * Referenced by: '<S28>/Gain1'
                                        */
  real_T additionfactor1_Value_hp;     /* Expression: add_fac
                                        * Referenced by: '<S26>/addition factor1'
                                        */
  real_T Memory2_X0_l;                 /* Expression: p
                                        * Referenced by: '<S7>/Memory2'
                                        */
  real_T Gain1_Gain_is;                /* Expression: mult_fac
                                        * Referenced by: '<S26>/Gain1'
                                        */
  real_T additionfactor1_Value_dv;     /* Expression: add_fac
                                        * Referenced by: '<S27>/addition factor1'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: mult_fac
                                        * Referenced by: '<S27>/Gain1'
                                        */
  real_T Constant8_Value;              /* Expression: 10^-6
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T additionfactor1_Value_hc;     /* Expression: add_fac
                                        * Referenced by: '<S38>/addition factor1'
                                        */
  real_T Tnormal_Value;                /* Expression: Ref_Cond(1)
                                        * Referenced by: '<S129>/T-normal'
                                        */
  real_T RPM_Value;                    /* Expression: 0
                                        * Referenced by: '<S15>/RPM'
                                        */
  real_T Constant_Value_j;             /* Expression: max(RPM)
                                        * Referenced by: '<S132>/Constant'
                                        */
  real_T Constant11_Value;             /* Expression: 100000
                                        * Referenced by: '<Root>/Constant11'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 1
                                        * Referenced by: '<S138>/Gain'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: 1
                                        * Referenced by: '<S138>/Gain1'
                                        */
  real_T Gain2_Gain_oa;                /* Expression: 1
                                        * Referenced by: '<S138>/Gain2'
                                        */
  real_T Gain3_Gain_p;                 /* Expression: 1
                                        * Referenced by: '<S138>/Gain3'
                                        */
  real_T Gain4_Gain_l;                 /* Expression: 1
                                        * Referenced by: '<S138>/Gain4'
                                        */
  real_T SFunction1_P1_h[49];          /* Expression: nasa_1000_6000
                                        * Referenced by: '<S138>/S-Function1'
                                        */
  real_T SFunction1_P2_m[49];          /* Expression: nasa_200_1000
                                        * Referenced by: '<S138>/S-Function1'
                                        */
  real_T SFunction1_P12_m[24];         /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S138>/S-Function1'
                                        */
  real_T SFunction1_P13_br[21];        /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S138>/S-Function1'
                                        */
  real_T SFunction1_P14_g[504];        /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S138>/S-Function1'
                                        */
  real_T SFunction1_P15_k;             /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S138>/S-Function1'
                                        */
  real_T SFunction1_P21_j;             /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S138>/S-Function1'
                                        */
  real_T Gain1_Gain_fh;                /* Expression: .01
                                        * Referenced by: '<S129>/Gain1'
                                        */
  real_T Saturation1_UpperSat_a;       /* Expression: 0
                                        * Referenced by: '<S129>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_l;       /* Expression: -inf
                                        * Referenced by: '<S129>/Saturation1'
                                        */
  real_T Gain2_Gain_h;                 /* Expression: 0.001
                                        * Referenced by: '<S38>/Gain2'
                                        */
  real_T Gain1_Gain_gr;                /* Expression: mult_fac
                                        * Referenced by: '<S38>/Gain1'
                                        */
  real_T additionfactor1_Value_cl;     /* Expression: add_fac
                                        * Referenced by: '<S37>/addition factor1'
                                        */
  real_T Gain1_Gain_kz;                /* Expression: mult_fac
                                        * Referenced by: '<S37>/Gain1'
                                        */
  real_T additionfactor1_Value_el;     /* Expression: add_fac
                                        * Referenced by: '<S35>/addition factor1'
                                        */
  real_T Gain1_Gain_dv;                /* Expression: mult_fac
                                        * Referenced by: '<S35>/Gain1'
                                        */
  real_T additionfactor1_Value_gl;     /* Expression: add_fac
                                        * Referenced by: '<S36>/addition factor1'
                                        */
  real_T Gain1_Gain_py;                /* Expression: mult_fac
                                        * Referenced by: '<S36>/Gain1'
                                        */
  real_T Constant9_Value;              /* Expression: 10^-6
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Constant1_Value_em;           /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Memory2_X0_c;                 /* Expression: p
                                        * Referenced by: '<S11>/Memory2'
                                        */
  real_T Gain_Gain_lp;                 /* Expression: P_Loss(1)
                                        * Referenced by: '<S64>/Gain'
                                        */
  real_T p_downstrem_min_Value_h;      /* Expression: P_Loss(2)
                                        * Referenced by: '<S64>/p_downstrem_min'
                                        */
  real_T Saturation_UpperSat_g;        /* Expression: inf
                                        * Referenced by: '<S64>/Saturation'
                                        */
  real_T Saturation_LowerSat_d;        /* Expression: 0
                                        * Referenced by: '<S64>/Saturation'
                                        */
  real_T Constant4_Value_b;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Memory2_X0_c5;                /* Expression: p
                                        * Referenced by: '<S10>/Memory2'
                                        */
  real_T Gain_Gain_m;                  /* Expression: P_Loss(1)
                                        * Referenced by: '<S72>/Gain'
                                        */
  real_T p_downstrem_min_Value_b;      /* Expression: P_Loss(2)
                                        * Referenced by: '<S72>/p_downstrem_min'
                                        */
  real_T Saturation_UpperSat_k;        /* Expression: inf
                                        * Referenced by: '<S72>/Saturation'
                                        */
  real_T Saturation_LowerSat_c;        /* Expression: 0
                                        * Referenced by: '<S72>/Saturation'
                                        */
  real_T Memory1_X0_a[4];              /* Expression: [1e5 1e5 1 0]
                                        * Referenced by: '<S78>/Memory1'
                                        */
  real_T Constant4_Value_p;            /* Expression: p_refrence
                                        * Referenced by: '<S86>/Constant4'
                                        */
  real_T Gain_Gain_f;                  /* Expression: 1e-5
                                        * Referenced by: '<S86>/Gain'
                                        */
  real_T p_Relaxation_Gain;            /* Expression: p_Relaxation
                                        * Referenced by: '<S86>/p_Relaxation'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S86>/Constant'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 1.2
                                        * Referenced by: '<S86>/Saturation'
                                        */
  real_T Saturation_LowerSat_k;        /* Expression: 0.8
                                        * Referenced by: '<S86>/Saturation'
                                        */
  real_T Memory_X0;                    /* Expression: max_mdot/2
                                        * Referenced by: '<S86>/Memory'
                                        */
  real_T Constant_Value_k;             /* Expression: 0
                                        * Referenced by: '<S89>/Constant'
                                        */
  real_T Tnormal_Value_o;              /* Expression: 298
                                        * Referenced by: '<S78>/T-normal'
                                        */
  real_T Constant1_Value_d2;           /* Expression: max(RPM)
                                        * Referenced by: '<S88>/Constant1'
                                        */
  real_T Constant3_Value_b;            /* Expression: min(RPM)
                                        * Referenced by: '<S88>/Constant3'
                                        */
  real_T pnormal_Value_l;              /* Expression: 1.013e5
                                        * Referenced by: '<S78>/p-normal'
                                        */
  real_T RefrenceRJgK_Value;           /* Expression: 0.287
                                        * Referenced by: '<S78>/Refrence R [J//g//K]'
                                        */
  real_T p_ratio1_UpperSat;            /* Expression: inf
                                        * Referenced by: '<S88>/p_ratio >= 1'
                                        */
  real_T p_ratio1_LowerSat;            /* Expression: 1
                                        * Referenced by: '<S88>/p_ratio >= 1'
                                        */
  real_T PFin_Value;                   /* Expression: 0
                                        * Referenced by: '<S4>/PFin'
                                        */
  real_T Constant10_Value;             /* Expression: 500000
                                        * Referenced by: '<Root>/Constant10'
                                        */
  real_T Gain_Gain_d;                  /* Expression: P_Loss(1)
                                        * Referenced by: '<S100>/Gain'
                                        */
  real_T p_downstrem_min_Value_e;      /* Expression: P_Loss(2)
                                        * Referenced by: '<S100>/p_downstrem_min'
                                        */
  real_T Saturation_UpperSat_f;        /* Expression: inf
                                        * Referenced by: '<S100>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: 0
                                        * Referenced by: '<S100>/Saturation'
                                        */
  real_T RPM_Value_n;                  /* Expression: 0
                                        * Referenced by: '<S6>/RPM'
                                        */
  real_T Tnormal_Value_j;              /* Expression: Ref_Cond(1)
                                        * Referenced by: '<S105>/T-normal'
                                        */
  real_T Constant_Value_d;             /* Expression: max(RPM)
                                        * Referenced by: '<S108>/Constant'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: .01
                                        * Referenced by: '<S105>/Gain1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: 1
                                        * Referenced by: '<S114>/Gain'
                                        */
  real_T Gain1_Gain_oi;                /* Expression: 1
                                        * Referenced by: '<S114>/Gain1'
                                        */
  real_T Gain2_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S114>/Gain2'
                                        */
  real_T Gain3_Gain_e;                 /* Expression: 1
                                        * Referenced by: '<S114>/Gain3'
                                        */
  real_T Gain4_Gain_g;                 /* Expression: 1
                                        * Referenced by: '<S114>/Gain4'
                                        */
  real_T SFunction1_P1_o[49];          /* Expression: nasa_1000_6000
                                        * Referenced by: '<S114>/S-Function1'
                                        */
  real_T SFunction1_P2_h[49];          /* Expression: nasa_200_1000
                                        * Referenced by: '<S114>/S-Function1'
                                        */
  real_T SFunction1_P12_mj[24];        /* Expression: th_SteamTable_dh_IG(2:end,1)
                                        * Referenced by: '<S114>/S-Function1'
                                        */
  real_T SFunction1_P13_h[21];         /* Expression: th_SteamTable_dh_IG(1,2:end)
                                        * Referenced by: '<S114>/S-Function1'
                                        */
  real_T SFunction1_P14_n[504];        /* Expression: th_SteamTable_dh_IG(2:end,2:end)
                                        * Referenced by: '<S114>/S-Function1'
                                        */
  real_T SFunction1_P15_j;             /* Expression: th_GetSpeciesTypeIndex('steamtable')
                                        * Referenced by: '<S114>/S-Function1'
                                        */
  real_T SFunction1_P21_m;             /* Expression: th_GetSpeciesTypeIndex('IF97')
                                        * Referenced by: '<S114>/S-Function1'
                                        */
  real_T Saturation1_UpperSat_d;       /* Expression: 0
                                        * Referenced by: '<S105>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_ds;      /* Expression: -inf
                                        * Referenced by: '<S105>/Saturation1'
                                        */
  real_T Gain_Gain_cj;                 /* Expression: P_Loss(1)
                                        * Referenced by: '<S124>/Gain'
                                        */
  real_T p_downstrem_min_Value_n;      /* Expression: P_Loss(2)
                                        * Referenced by: '<S124>/p_downstrem_min'
                                        */
  real_T Saturation_UpperSat_l;        /* Expression: inf
                                        * Referenced by: '<S124>/Saturation'
                                        */
  real_T Saturation_LowerSat_a;        /* Expression: 0
                                        * Referenced by: '<S124>/Saturation'
                                        */
  real_T Constant1_Value_k;            /* Expression: flow_type
                                        * Referenced by: '<S17>/Constant1'
                                        */
  real_T UnitScale_Gain_e;             /* Expression: unit_scale
                                        * Referenced by: '<S160>/UnitScale'
                                        */
  real_T UnitOffset_Bias_f;            /* Expression: unit_offset
                                        * Referenced by: '<S160>/UnitOffset'
                                        */
  real_T UnitScale_Gain_g;             /* Expression: unit_scale
                                        * Referenced by: '<S161>/UnitScale'
                                        */
  real_T UnitOffset_Bias_h;            /* Expression: unit_offset
                                        * Referenced by: '<S161>/UnitOffset'
                                        */
  real_T UnitScale_Gain_n;             /* Expression: unit_scale
                                        * Referenced by: '<S162>/UnitScale'
                                        */
  real_T UnitOffset_Bias_mp;           /* Expression: unit_offset
                                        * Referenced by: '<S162>/UnitOffset'
                                        */
  P_MassFlow_NACCBraytonCycle20_T MassFlow_m;/* '<S17>/MassFlow' */
  P_calculateconversion_NACCBra_T calculateconversion_b;/* '<S70>/calculate  conversion' */
  P_calculateconversion_NACCBra_T calculateconversion;/* '<S62>/calculate  conversion' */
  P_MassFlow_NACCBraytonCycle20_T MassFlow;/* '<S1>/MassFlow' */
};

/* Real-time Model Data Structure */
struct tag_RTM_NACCBraytonCycle2017a_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T blkStateChange;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_NACCBraytonCycle2017a_T NACCBraytonCycle2017a_P;

/* Block signals (auto storage) */
extern B_NACCBraytonCycle2017a_T NACCBraytonCycle2017a_B;

/* Block states (auto storage) */
extern DW_NACCBraytonCycle2017a_T NACCBraytonCycle2017a_DW;

/* External inputs (root inport signals with auto storage) */
extern ExtU_NACCBraytonCycle2017a_T NACCBraytonCycle2017a_U;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_NACCBraytonCycle2017a_T NACCBraytonCycle2017a_Y;

/*====================*
 * External functions *
 *====================*/
extern NACCBraytonCycle2017a_rtModel *NACCBraytonCycle2017a(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_NACCBraytonCycle2017_T *const NACCBraytonCycle2017a_M;

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
 * '<Root>' : 'NACCBraytonCycle2017a'
 * '<S1>'   : 'NACCBraytonCycle2017a/Ambient air'
 * '<S2>'   : 'NACCBraytonCycle2017a/Combustion Chamber'
 * '<S3>'   : 'NACCBraytonCycle2017a/Combustion Chamber1'
 * '<S4>'   : 'NACCBraytonCycle2017a/Compressor Pressure Feedback'
 * '<S5>'   : 'NACCBraytonCycle2017a/HP CTAH'
 * '<S6>'   : 'NACCBraytonCycle2017a/HP Gas Turbine'
 * '<S7>'   : 'NACCBraytonCycle2017a/Initial Condition1'
 * '<S8>'   : 'NACCBraytonCycle2017a/Initial Condition2'
 * '<S9>'   : 'NACCBraytonCycle2017a/Initial Condition3'
 * '<S10>'  : 'NACCBraytonCycle2017a/Initial Condition4'
 * '<S11>'  : 'NACCBraytonCycle2017a/Initial Condition5'
 * '<S12>'  : 'NACCBraytonCycle2017a/Initial Condition6'
 * '<S13>'  : 'NACCBraytonCycle2017a/Initial Condition7'
 * '<S14>'  : 'NACCBraytonCycle2017a/LP CTAH'
 * '<S15>'  : 'NACCBraytonCycle2017a/LP Gas Turbine'
 * '<S16>'  : 'NACCBraytonCycle2017a/Mixer'
 * '<S17>'  : 'NACCBraytonCycle2017a/Natural Gas'
 * '<S18>'  : 'NACCBraytonCycle2017a/Sensor'
 * '<S19>'  : 'NACCBraytonCycle2017a/Sensor1'
 * '<S20>'  : 'NACCBraytonCycle2017a/Sensor10'
 * '<S21>'  : 'NACCBraytonCycle2017a/Sensor11'
 * '<S22>'  : 'NACCBraytonCycle2017a/Sensor12'
 * '<S23>'  : 'NACCBraytonCycle2017a/Sensor13'
 * '<S24>'  : 'NACCBraytonCycle2017a/Sensor14'
 * '<S25>'  : 'NACCBraytonCycle2017a/Sensor15'
 * '<S26>'  : 'NACCBraytonCycle2017a/Sensor16'
 * '<S27>'  : 'NACCBraytonCycle2017a/Sensor17'
 * '<S28>'  : 'NACCBraytonCycle2017a/Sensor18'
 * '<S29>'  : 'NACCBraytonCycle2017a/Sensor19'
 * '<S30>'  : 'NACCBraytonCycle2017a/Sensor2'
 * '<S31>'  : 'NACCBraytonCycle2017a/Sensor20'
 * '<S32>'  : 'NACCBraytonCycle2017a/Sensor21'
 * '<S33>'  : 'NACCBraytonCycle2017a/Sensor22'
 * '<S34>'  : 'NACCBraytonCycle2017a/Sensor23'
 * '<S35>'  : 'NACCBraytonCycle2017a/Sensor24'
 * '<S36>'  : 'NACCBraytonCycle2017a/Sensor25'
 * '<S37>'  : 'NACCBraytonCycle2017a/Sensor26'
 * '<S38>'  : 'NACCBraytonCycle2017a/Sensor27'
 * '<S39>'  : 'NACCBraytonCycle2017a/Sensor3'
 * '<S40>'  : 'NACCBraytonCycle2017a/Sensor4'
 * '<S41>'  : 'NACCBraytonCycle2017a/Sensor5'
 * '<S42>'  : 'NACCBraytonCycle2017a/Sensor6'
 * '<S43>'  : 'NACCBraytonCycle2017a/Sensor7'
 * '<S44>'  : 'NACCBraytonCycle2017a/Sensor8'
 * '<S45>'  : 'NACCBraytonCycle2017a/Sensor9'
 * '<S46>'  : 'NACCBraytonCycle2017a/Ambient air/MassFlow'
 * '<S47>'  : 'NACCBraytonCycle2017a/Ambient air/MolarFlow'
 * '<S48>'  : 'NACCBraytonCycle2017a/Ambient air/Reservoir'
 * '<S49>'  : 'NACCBraytonCycle2017a/Ambient air/T-p-State'
 * '<S50>'  : 'NACCBraytonCycle2017a/Ambient air/Unit Conversion'
 * '<S51>'  : 'NACCBraytonCycle2017a/Ambient air/Unit Conversion1'
 * '<S52>'  : 'NACCBraytonCycle2017a/Ambient air/Unit Conversion2'
 * '<S53>'  : 'NACCBraytonCycle2017a/Ambient air/VolumeFlow'
 * '<S54>'  : 'NACCBraytonCycle2017a/Ambient air/MassFlow/Molar Weight'
 * '<S55>'  : 'NACCBraytonCycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions'
 * '<S56>'  : 'NACCBraytonCycle2017a/Ambient air/T-p-State/T-p-x-State'
 * '<S57>'  : 'NACCBraytonCycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions'
 * '<S58>'  : 'NACCBraytonCycle2017a/Ambient air/VolumeFlow/VolumeFlow'
 * '<S59>'  : 'NACCBraytonCycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density'
 * '<S60>'  : 'NACCBraytonCycle2017a/Ambient air/VolumeFlow/VolumeFlow/Mass Flow Rate'
 * '<S61>'  : 'NACCBraytonCycle2017a/Ambient air/VolumeFlow/VolumeFlow/Mass Flow Rate/Molar Weight'
 * '<S62>'  : 'NACCBraytonCycle2017a/Combustion Chamber/Reactor'
 * '<S63>'  : 'NACCBraytonCycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange'
 * '<S64>'  : 'NACCBraytonCycle2017a/Combustion Chamber/Reactor/Pressure loss'
 * '<S65>'  : 'NACCBraytonCycle2017a/Combustion Chamber/Reactor/calculate  conversion'
 * '<S66>'  : 'NACCBraytonCycle2017a/Combustion Chamber/Reactor/Pressure loss/Mass Flow Rate'
 * '<S67>'  : 'NACCBraytonCycle2017a/Combustion Chamber/Reactor/Pressure loss/Mass Flow Rate/Molar Weight'
 * '<S68>'  : 'NACCBraytonCycle2017a/Combustion Chamber/Reactor/calculate  conversion/Compare To Constant1'
 * '<S69>'  : 'NACCBraytonCycle2017a/Combustion Chamber/Reactor/calculate  conversion/Subsystem1'
 * '<S70>'  : 'NACCBraytonCycle2017a/Combustion Chamber1/Reactor'
 * '<S71>'  : 'NACCBraytonCycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange'
 * '<S72>'  : 'NACCBraytonCycle2017a/Combustion Chamber1/Reactor/Pressure loss'
 * '<S73>'  : 'NACCBraytonCycle2017a/Combustion Chamber1/Reactor/calculate  conversion'
 * '<S74>'  : 'NACCBraytonCycle2017a/Combustion Chamber1/Reactor/Pressure loss/Mass Flow Rate'
 * '<S75>'  : 'NACCBraytonCycle2017a/Combustion Chamber1/Reactor/Pressure loss/Mass Flow Rate/Molar Weight'
 * '<S76>'  : 'NACCBraytonCycle2017a/Combustion Chamber1/Reactor/calculate  conversion/Compare To Constant1'
 * '<S77>'  : 'NACCBraytonCycle2017a/Combustion Chamber1/Reactor/calculate  conversion/Subsystem1'
 * '<S78>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor'
 * '<S79>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/Compare To Constant'
 * '<S80>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/Divide2'
 * '<S81>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange'
 * '<S82>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/Mass Flow Rate'
 * '<S83>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/Molar Weight'
 * '<S84>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State'
 * '<S85>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State'
 * '<S86>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/Upstream to calculate mass flow'
 * '<S87>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/error_selector'
 * '<S88>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/p-ratio'
 * '<S89>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/Divide2/Compare To Zero'
 * '<S90>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/Mass Flow Rate/Molar Weight'
 * '<S91>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions'
 * '<S92>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State'
 * '<S93>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/Upstream to calculate mass flow/Mass Flow Rate2'
 * '<S94>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/Upstream to calculate mass flow/Mass Flow Rate2/Molar Weight'
 * '<S95>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/p-ratio/Compare To Constant1'
 * '<S96>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/p-ratio/Compare To Constant2'
 * '<S97>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/p-ratio/Compare To Constant3'
 * '<S98>'  : 'NACCBraytonCycle2017a/Compressor Pressure Feedback/PF compressor/p-ratio/Compare To Constant4'
 * '<S99>'  : 'NACCBraytonCycle2017a/HP CTAH/Heat-Addition'
 * '<S100>' : 'NACCBraytonCycle2017a/HP CTAH/Pressure Loss'
 * '<S101>' : 'NACCBraytonCycle2017a/HP CTAH/Heat-Addition/subsystem'
 * '<S102>' : 'NACCBraytonCycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss'
 * '<S103>' : 'NACCBraytonCycle2017a/HP CTAH/Pressure Loss/Mass Flow Rate'
 * '<S104>' : 'NACCBraytonCycle2017a/HP CTAH/Pressure Loss/Mass Flow Rate/Molar Weight'
 * '<S105>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine'
 * '<S106>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/Compare To Constant'
 * '<S107>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange'
 * '<S108>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/LUTs'
 * '<S109>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/Mass Flow Rate'
 * '<S110>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/Mass Flow Rate1'
 * '<S111>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/Molar Weight'
 * '<S112>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/S-p-State'
 * '<S113>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/Saturation Dynamic'
 * '<S114>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/T-p-x-State'
 * '<S115>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/error_selector'
 * '<S116>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/LUTs/Compare To Constant1'
 * '<S117>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/LUTs/Compare To Constant2'
 * '<S118>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/LUTs/Compare To Constant5'
 * '<S119>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/LUTs/Compare To Constant6'
 * '<S120>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/LUTs/Saturation Dynamic1'
 * '<S121>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/Mass Flow Rate/Molar Weight'
 * '<S122>' : 'NACCBraytonCycle2017a/HP Gas Turbine/Turbine/Mass Flow Rate1/Molar Weight'
 * '<S123>' : 'NACCBraytonCycle2017a/LP CTAH/Heat-Addition'
 * '<S124>' : 'NACCBraytonCycle2017a/LP CTAH/Pressure Loss'
 * '<S125>' : 'NACCBraytonCycle2017a/LP CTAH/Heat-Addition/subsystem'
 * '<S126>' : 'NACCBraytonCycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss'
 * '<S127>' : 'NACCBraytonCycle2017a/LP CTAH/Pressure Loss/Mass Flow Rate'
 * '<S128>' : 'NACCBraytonCycle2017a/LP CTAH/Pressure Loss/Mass Flow Rate/Molar Weight'
 * '<S129>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine'
 * '<S130>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/Compare To Constant'
 * '<S131>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange'
 * '<S132>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/LUTs'
 * '<S133>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/Mass Flow Rate'
 * '<S134>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/Mass Flow Rate1'
 * '<S135>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/Molar Weight'
 * '<S136>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/S-p-State'
 * '<S137>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/Saturation Dynamic'
 * '<S138>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/T-p-x-State'
 * '<S139>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/error_selector'
 * '<S140>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/LUTs/Compare To Constant1'
 * '<S141>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/LUTs/Compare To Constant2'
 * '<S142>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/LUTs/Compare To Constant5'
 * '<S143>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/LUTs/Compare To Constant6'
 * '<S144>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/LUTs/Saturation Dynamic1'
 * '<S145>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/Mass Flow Rate/Molar Weight'
 * '<S146>' : 'NACCBraytonCycle2017a/LP Gas Turbine/Turbine/Mass Flow Rate1/Molar Weight'
 * '<S147>' : 'NACCBraytonCycle2017a/Mixer/Mixer'
 * '<S148>' : 'NACCBraytonCycle2017a/Mixer/Mixer/Compare To Zero'
 * '<S149>' : 'NACCBraytonCycle2017a/Mixer/Mixer/Divide'
 * '<S150>' : 'NACCBraytonCycle2017a/Mixer/Mixer/H-p-State with HeatLoss'
 * '<S151>' : 'NACCBraytonCycle2017a/Mixer/Mixer/Pressure_loss'
 * '<S152>' : 'NACCBraytonCycle2017a/Mixer/Mixer/T-p-x-State1'
 * '<S153>' : 'NACCBraytonCycle2017a/Mixer/Mixer/Divide/Compare To Zero'
 * '<S154>' : 'NACCBraytonCycle2017a/Mixer/Mixer/Pressure_loss/Mass Flow Rate'
 * '<S155>' : 'NACCBraytonCycle2017a/Mixer/Mixer/Pressure_loss/Mass Flow Rate/Molar Weight'
 * '<S156>' : 'NACCBraytonCycle2017a/Natural Gas/MassFlow'
 * '<S157>' : 'NACCBraytonCycle2017a/Natural Gas/MolarFlow'
 * '<S158>' : 'NACCBraytonCycle2017a/Natural Gas/Reservoir'
 * '<S159>' : 'NACCBraytonCycle2017a/Natural Gas/T-p-State'
 * '<S160>' : 'NACCBraytonCycle2017a/Natural Gas/Unit Conversion'
 * '<S161>' : 'NACCBraytonCycle2017a/Natural Gas/Unit Conversion1'
 * '<S162>' : 'NACCBraytonCycle2017a/Natural Gas/Unit Conversion2'
 * '<S163>' : 'NACCBraytonCycle2017a/Natural Gas/VolumeFlow'
 * '<S164>' : 'NACCBraytonCycle2017a/Natural Gas/MassFlow/Molar Weight'
 * '<S165>' : 'NACCBraytonCycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions'
 * '<S166>' : 'NACCBraytonCycle2017a/Natural Gas/T-p-State/T-p-x-State'
 * '<S167>' : 'NACCBraytonCycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions'
 * '<S168>' : 'NACCBraytonCycle2017a/Natural Gas/VolumeFlow/VolumeFlow'
 * '<S169>' : 'NACCBraytonCycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density'
 * '<S170>' : 'NACCBraytonCycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Mass Flow Rate'
 * '<S171>' : 'NACCBraytonCycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Mass Flow Rate/Molar Weight'
 * '<S172>' : 'NACCBraytonCycle2017a/Sensor/Calculate phi'
 * '<S173>' : 'NACCBraytonCycle2017a/Sensor/MassFlowRate'
 * '<S174>' : 'NACCBraytonCycle2017a/Sensor/Vdot'
 * '<S175>' : 'NACCBraytonCycle2017a/Sensor/Calculate phi/Relative Humidity'
 * '<S176>' : 'NACCBraytonCycle2017a/Sensor/Calculate phi/Relative Humidity/SatPressures1'
 * '<S177>' : 'NACCBraytonCycle2017a/Sensor/MassFlowRate/Molar Weight'
 * '<S178>' : 'NACCBraytonCycle2017a/Sensor/Vdot/Density'
 * '<S179>' : 'NACCBraytonCycle2017a/Sensor/Vdot/MassFlowRate'
 * '<S180>' : 'NACCBraytonCycle2017a/Sensor/Vdot/MolarWeight'
 * '<S181>' : 'NACCBraytonCycle2017a/Sensor/Vdot/MolarWeight1'
 * '<S182>' : 'NACCBraytonCycle2017a/Sensor/Vdot/MassFlowRate/Molar Weight'
 * '<S183>' : 'NACCBraytonCycle2017a/Sensor1/Calculate phi'
 * '<S184>' : 'NACCBraytonCycle2017a/Sensor1/MassFlowRate'
 * '<S185>' : 'NACCBraytonCycle2017a/Sensor1/Vdot'
 * '<S186>' : 'NACCBraytonCycle2017a/Sensor1/Calculate phi/Relative Humidity'
 * '<S187>' : 'NACCBraytonCycle2017a/Sensor1/Calculate phi/Relative Humidity/SatPressures1'
 * '<S188>' : 'NACCBraytonCycle2017a/Sensor1/MassFlowRate/Molar Weight'
 * '<S189>' : 'NACCBraytonCycle2017a/Sensor1/Vdot/Density'
 * '<S190>' : 'NACCBraytonCycle2017a/Sensor1/Vdot/MassFlowRate'
 * '<S191>' : 'NACCBraytonCycle2017a/Sensor1/Vdot/MolarWeight'
 * '<S192>' : 'NACCBraytonCycle2017a/Sensor1/Vdot/MolarWeight1'
 * '<S193>' : 'NACCBraytonCycle2017a/Sensor1/Vdot/MassFlowRate/Molar Weight'
 * '<S194>' : 'NACCBraytonCycle2017a/Sensor10/Calculate phi'
 * '<S195>' : 'NACCBraytonCycle2017a/Sensor10/MassFlowRate'
 * '<S196>' : 'NACCBraytonCycle2017a/Sensor10/Vdot'
 * '<S197>' : 'NACCBraytonCycle2017a/Sensor10/Calculate phi/Relative Humidity'
 * '<S198>' : 'NACCBraytonCycle2017a/Sensor10/Calculate phi/Relative Humidity/SatPressures1'
 * '<S199>' : 'NACCBraytonCycle2017a/Sensor10/MassFlowRate/Molar Weight'
 * '<S200>' : 'NACCBraytonCycle2017a/Sensor10/Vdot/Density'
 * '<S201>' : 'NACCBraytonCycle2017a/Sensor10/Vdot/MassFlowRate'
 * '<S202>' : 'NACCBraytonCycle2017a/Sensor10/Vdot/MolarWeight'
 * '<S203>' : 'NACCBraytonCycle2017a/Sensor10/Vdot/MolarWeight1'
 * '<S204>' : 'NACCBraytonCycle2017a/Sensor10/Vdot/MassFlowRate/Molar Weight'
 * '<S205>' : 'NACCBraytonCycle2017a/Sensor11/Calculate phi'
 * '<S206>' : 'NACCBraytonCycle2017a/Sensor11/MassFlowRate'
 * '<S207>' : 'NACCBraytonCycle2017a/Sensor11/Vdot'
 * '<S208>' : 'NACCBraytonCycle2017a/Sensor11/Calculate phi/Relative Humidity'
 * '<S209>' : 'NACCBraytonCycle2017a/Sensor11/Calculate phi/Relative Humidity/SatPressures1'
 * '<S210>' : 'NACCBraytonCycle2017a/Sensor11/MassFlowRate/Molar Weight'
 * '<S211>' : 'NACCBraytonCycle2017a/Sensor11/Vdot/Density'
 * '<S212>' : 'NACCBraytonCycle2017a/Sensor11/Vdot/MassFlowRate'
 * '<S213>' : 'NACCBraytonCycle2017a/Sensor11/Vdot/MolarWeight'
 * '<S214>' : 'NACCBraytonCycle2017a/Sensor11/Vdot/MolarWeight1'
 * '<S215>' : 'NACCBraytonCycle2017a/Sensor11/Vdot/MassFlowRate/Molar Weight'
 * '<S216>' : 'NACCBraytonCycle2017a/Sensor12/Calculate phi'
 * '<S217>' : 'NACCBraytonCycle2017a/Sensor12/MassFlowRate'
 * '<S218>' : 'NACCBraytonCycle2017a/Sensor12/Vdot'
 * '<S219>' : 'NACCBraytonCycle2017a/Sensor12/Calculate phi/Relative Humidity'
 * '<S220>' : 'NACCBraytonCycle2017a/Sensor12/Calculate phi/Relative Humidity/SatPressures1'
 * '<S221>' : 'NACCBraytonCycle2017a/Sensor12/MassFlowRate/Molar Weight'
 * '<S222>' : 'NACCBraytonCycle2017a/Sensor12/Vdot/Density'
 * '<S223>' : 'NACCBraytonCycle2017a/Sensor12/Vdot/MassFlowRate'
 * '<S224>' : 'NACCBraytonCycle2017a/Sensor12/Vdot/MolarWeight'
 * '<S225>' : 'NACCBraytonCycle2017a/Sensor12/Vdot/MolarWeight1'
 * '<S226>' : 'NACCBraytonCycle2017a/Sensor12/Vdot/MassFlowRate/Molar Weight'
 * '<S227>' : 'NACCBraytonCycle2017a/Sensor13/Calculate phi'
 * '<S228>' : 'NACCBraytonCycle2017a/Sensor13/MassFlowRate'
 * '<S229>' : 'NACCBraytonCycle2017a/Sensor13/Vdot'
 * '<S230>' : 'NACCBraytonCycle2017a/Sensor13/Calculate phi/Relative Humidity'
 * '<S231>' : 'NACCBraytonCycle2017a/Sensor13/Calculate phi/Relative Humidity/SatPressures1'
 * '<S232>' : 'NACCBraytonCycle2017a/Sensor13/MassFlowRate/Molar Weight'
 * '<S233>' : 'NACCBraytonCycle2017a/Sensor13/Vdot/Density'
 * '<S234>' : 'NACCBraytonCycle2017a/Sensor13/Vdot/MassFlowRate'
 * '<S235>' : 'NACCBraytonCycle2017a/Sensor13/Vdot/MolarWeight'
 * '<S236>' : 'NACCBraytonCycle2017a/Sensor13/Vdot/MolarWeight1'
 * '<S237>' : 'NACCBraytonCycle2017a/Sensor13/Vdot/MassFlowRate/Molar Weight'
 * '<S238>' : 'NACCBraytonCycle2017a/Sensor14/Calculate phi'
 * '<S239>' : 'NACCBraytonCycle2017a/Sensor14/MassFlowRate'
 * '<S240>' : 'NACCBraytonCycle2017a/Sensor14/Vdot'
 * '<S241>' : 'NACCBraytonCycle2017a/Sensor14/Calculate phi/Relative Humidity'
 * '<S242>' : 'NACCBraytonCycle2017a/Sensor14/Calculate phi/Relative Humidity/SatPressures1'
 * '<S243>' : 'NACCBraytonCycle2017a/Sensor14/MassFlowRate/Molar Weight'
 * '<S244>' : 'NACCBraytonCycle2017a/Sensor14/Vdot/Density'
 * '<S245>' : 'NACCBraytonCycle2017a/Sensor14/Vdot/MassFlowRate'
 * '<S246>' : 'NACCBraytonCycle2017a/Sensor14/Vdot/MolarWeight'
 * '<S247>' : 'NACCBraytonCycle2017a/Sensor14/Vdot/MolarWeight1'
 * '<S248>' : 'NACCBraytonCycle2017a/Sensor14/Vdot/MassFlowRate/Molar Weight'
 * '<S249>' : 'NACCBraytonCycle2017a/Sensor15/Calculate phi'
 * '<S250>' : 'NACCBraytonCycle2017a/Sensor15/MassFlowRate'
 * '<S251>' : 'NACCBraytonCycle2017a/Sensor15/Vdot'
 * '<S252>' : 'NACCBraytonCycle2017a/Sensor15/Calculate phi/Relative Humidity'
 * '<S253>' : 'NACCBraytonCycle2017a/Sensor15/Calculate phi/Relative Humidity/SatPressures1'
 * '<S254>' : 'NACCBraytonCycle2017a/Sensor15/MassFlowRate/Molar Weight'
 * '<S255>' : 'NACCBraytonCycle2017a/Sensor15/Vdot/Density'
 * '<S256>' : 'NACCBraytonCycle2017a/Sensor15/Vdot/MassFlowRate'
 * '<S257>' : 'NACCBraytonCycle2017a/Sensor15/Vdot/MolarWeight'
 * '<S258>' : 'NACCBraytonCycle2017a/Sensor15/Vdot/MolarWeight1'
 * '<S259>' : 'NACCBraytonCycle2017a/Sensor15/Vdot/MassFlowRate/Molar Weight'
 * '<S260>' : 'NACCBraytonCycle2017a/Sensor16/Calculate phi'
 * '<S261>' : 'NACCBraytonCycle2017a/Sensor16/MassFlowRate'
 * '<S262>' : 'NACCBraytonCycle2017a/Sensor16/Vdot'
 * '<S263>' : 'NACCBraytonCycle2017a/Sensor16/Calculate phi/Relative Humidity'
 * '<S264>' : 'NACCBraytonCycle2017a/Sensor16/Calculate phi/Relative Humidity/SatPressures1'
 * '<S265>' : 'NACCBraytonCycle2017a/Sensor16/MassFlowRate/Molar Weight'
 * '<S266>' : 'NACCBraytonCycle2017a/Sensor16/Vdot/Density'
 * '<S267>' : 'NACCBraytonCycle2017a/Sensor16/Vdot/MassFlowRate'
 * '<S268>' : 'NACCBraytonCycle2017a/Sensor16/Vdot/MolarWeight'
 * '<S269>' : 'NACCBraytonCycle2017a/Sensor16/Vdot/MolarWeight1'
 * '<S270>' : 'NACCBraytonCycle2017a/Sensor16/Vdot/MassFlowRate/Molar Weight'
 * '<S271>' : 'NACCBraytonCycle2017a/Sensor17/Calculate phi'
 * '<S272>' : 'NACCBraytonCycle2017a/Sensor17/MassFlowRate'
 * '<S273>' : 'NACCBraytonCycle2017a/Sensor17/Vdot'
 * '<S274>' : 'NACCBraytonCycle2017a/Sensor17/Calculate phi/Relative Humidity'
 * '<S275>' : 'NACCBraytonCycle2017a/Sensor17/Calculate phi/Relative Humidity/SatPressures1'
 * '<S276>' : 'NACCBraytonCycle2017a/Sensor17/MassFlowRate/Molar Weight'
 * '<S277>' : 'NACCBraytonCycle2017a/Sensor17/Vdot/Density'
 * '<S278>' : 'NACCBraytonCycle2017a/Sensor17/Vdot/MassFlowRate'
 * '<S279>' : 'NACCBraytonCycle2017a/Sensor17/Vdot/MolarWeight'
 * '<S280>' : 'NACCBraytonCycle2017a/Sensor17/Vdot/MolarWeight1'
 * '<S281>' : 'NACCBraytonCycle2017a/Sensor17/Vdot/MassFlowRate/Molar Weight'
 * '<S282>' : 'NACCBraytonCycle2017a/Sensor18/Calculate phi'
 * '<S283>' : 'NACCBraytonCycle2017a/Sensor18/MassFlowRate'
 * '<S284>' : 'NACCBraytonCycle2017a/Sensor18/Vdot'
 * '<S285>' : 'NACCBraytonCycle2017a/Sensor18/Calculate phi/Relative Humidity'
 * '<S286>' : 'NACCBraytonCycle2017a/Sensor18/Calculate phi/Relative Humidity/SatPressures1'
 * '<S287>' : 'NACCBraytonCycle2017a/Sensor18/MassFlowRate/Molar Weight'
 * '<S288>' : 'NACCBraytonCycle2017a/Sensor18/Vdot/Density'
 * '<S289>' : 'NACCBraytonCycle2017a/Sensor18/Vdot/MassFlowRate'
 * '<S290>' : 'NACCBraytonCycle2017a/Sensor18/Vdot/MolarWeight'
 * '<S291>' : 'NACCBraytonCycle2017a/Sensor18/Vdot/MolarWeight1'
 * '<S292>' : 'NACCBraytonCycle2017a/Sensor18/Vdot/MassFlowRate/Molar Weight'
 * '<S293>' : 'NACCBraytonCycle2017a/Sensor19/Calculate phi'
 * '<S294>' : 'NACCBraytonCycle2017a/Sensor19/MassFlowRate'
 * '<S295>' : 'NACCBraytonCycle2017a/Sensor19/Vdot'
 * '<S296>' : 'NACCBraytonCycle2017a/Sensor19/Calculate phi/Relative Humidity'
 * '<S297>' : 'NACCBraytonCycle2017a/Sensor19/Calculate phi/Relative Humidity/SatPressures1'
 * '<S298>' : 'NACCBraytonCycle2017a/Sensor19/MassFlowRate/Molar Weight'
 * '<S299>' : 'NACCBraytonCycle2017a/Sensor19/Vdot/Density'
 * '<S300>' : 'NACCBraytonCycle2017a/Sensor19/Vdot/MassFlowRate'
 * '<S301>' : 'NACCBraytonCycle2017a/Sensor19/Vdot/MolarWeight'
 * '<S302>' : 'NACCBraytonCycle2017a/Sensor19/Vdot/MolarWeight1'
 * '<S303>' : 'NACCBraytonCycle2017a/Sensor19/Vdot/MassFlowRate/Molar Weight'
 * '<S304>' : 'NACCBraytonCycle2017a/Sensor2/Calculate phi'
 * '<S305>' : 'NACCBraytonCycle2017a/Sensor2/MassFlowRate'
 * '<S306>' : 'NACCBraytonCycle2017a/Sensor2/Vdot'
 * '<S307>' : 'NACCBraytonCycle2017a/Sensor2/Calculate phi/Relative Humidity'
 * '<S308>' : 'NACCBraytonCycle2017a/Sensor2/Calculate phi/Relative Humidity/SatPressures1'
 * '<S309>' : 'NACCBraytonCycle2017a/Sensor2/MassFlowRate/Molar Weight'
 * '<S310>' : 'NACCBraytonCycle2017a/Sensor2/Vdot/Density'
 * '<S311>' : 'NACCBraytonCycle2017a/Sensor2/Vdot/MassFlowRate'
 * '<S312>' : 'NACCBraytonCycle2017a/Sensor2/Vdot/MolarWeight'
 * '<S313>' : 'NACCBraytonCycle2017a/Sensor2/Vdot/MolarWeight1'
 * '<S314>' : 'NACCBraytonCycle2017a/Sensor2/Vdot/MassFlowRate/Molar Weight'
 * '<S315>' : 'NACCBraytonCycle2017a/Sensor20/Calculate phi'
 * '<S316>' : 'NACCBraytonCycle2017a/Sensor20/MassFlowRate'
 * '<S317>' : 'NACCBraytonCycle2017a/Sensor20/Vdot'
 * '<S318>' : 'NACCBraytonCycle2017a/Sensor20/Calculate phi/Relative Humidity'
 * '<S319>' : 'NACCBraytonCycle2017a/Sensor20/Calculate phi/Relative Humidity/SatPressures1'
 * '<S320>' : 'NACCBraytonCycle2017a/Sensor20/MassFlowRate/Molar Weight'
 * '<S321>' : 'NACCBraytonCycle2017a/Sensor20/Vdot/Density'
 * '<S322>' : 'NACCBraytonCycle2017a/Sensor20/Vdot/MassFlowRate'
 * '<S323>' : 'NACCBraytonCycle2017a/Sensor20/Vdot/MolarWeight'
 * '<S324>' : 'NACCBraytonCycle2017a/Sensor20/Vdot/MolarWeight1'
 * '<S325>' : 'NACCBraytonCycle2017a/Sensor20/Vdot/MassFlowRate/Molar Weight'
 * '<S326>' : 'NACCBraytonCycle2017a/Sensor21/Calculate phi'
 * '<S327>' : 'NACCBraytonCycle2017a/Sensor21/MassFlowRate'
 * '<S328>' : 'NACCBraytonCycle2017a/Sensor21/Vdot'
 * '<S329>' : 'NACCBraytonCycle2017a/Sensor21/Calculate phi/Relative Humidity'
 * '<S330>' : 'NACCBraytonCycle2017a/Sensor21/Calculate phi/Relative Humidity/SatPressures1'
 * '<S331>' : 'NACCBraytonCycle2017a/Sensor21/MassFlowRate/Molar Weight'
 * '<S332>' : 'NACCBraytonCycle2017a/Sensor21/Vdot/Density'
 * '<S333>' : 'NACCBraytonCycle2017a/Sensor21/Vdot/MassFlowRate'
 * '<S334>' : 'NACCBraytonCycle2017a/Sensor21/Vdot/MolarWeight'
 * '<S335>' : 'NACCBraytonCycle2017a/Sensor21/Vdot/MolarWeight1'
 * '<S336>' : 'NACCBraytonCycle2017a/Sensor21/Vdot/MassFlowRate/Molar Weight'
 * '<S337>' : 'NACCBraytonCycle2017a/Sensor22/Calculate phi'
 * '<S338>' : 'NACCBraytonCycle2017a/Sensor22/MassFlowRate'
 * '<S339>' : 'NACCBraytonCycle2017a/Sensor22/Vdot'
 * '<S340>' : 'NACCBraytonCycle2017a/Sensor22/Calculate phi/Relative Humidity'
 * '<S341>' : 'NACCBraytonCycle2017a/Sensor22/Calculate phi/Relative Humidity/SatPressures1'
 * '<S342>' : 'NACCBraytonCycle2017a/Sensor22/MassFlowRate/Molar Weight'
 * '<S343>' : 'NACCBraytonCycle2017a/Sensor22/Vdot/Density'
 * '<S344>' : 'NACCBraytonCycle2017a/Sensor22/Vdot/MassFlowRate'
 * '<S345>' : 'NACCBraytonCycle2017a/Sensor22/Vdot/MolarWeight'
 * '<S346>' : 'NACCBraytonCycle2017a/Sensor22/Vdot/MolarWeight1'
 * '<S347>' : 'NACCBraytonCycle2017a/Sensor22/Vdot/MassFlowRate/Molar Weight'
 * '<S348>' : 'NACCBraytonCycle2017a/Sensor23/Calculate phi'
 * '<S349>' : 'NACCBraytonCycle2017a/Sensor23/MassFlowRate'
 * '<S350>' : 'NACCBraytonCycle2017a/Sensor23/Vdot'
 * '<S351>' : 'NACCBraytonCycle2017a/Sensor23/Calculate phi/Relative Humidity'
 * '<S352>' : 'NACCBraytonCycle2017a/Sensor23/Calculate phi/Relative Humidity/SatPressures1'
 * '<S353>' : 'NACCBraytonCycle2017a/Sensor23/MassFlowRate/Molar Weight'
 * '<S354>' : 'NACCBraytonCycle2017a/Sensor23/Vdot/Density'
 * '<S355>' : 'NACCBraytonCycle2017a/Sensor23/Vdot/MassFlowRate'
 * '<S356>' : 'NACCBraytonCycle2017a/Sensor23/Vdot/MolarWeight'
 * '<S357>' : 'NACCBraytonCycle2017a/Sensor23/Vdot/MolarWeight1'
 * '<S358>' : 'NACCBraytonCycle2017a/Sensor23/Vdot/MassFlowRate/Molar Weight'
 * '<S359>' : 'NACCBraytonCycle2017a/Sensor24/Calculate phi'
 * '<S360>' : 'NACCBraytonCycle2017a/Sensor24/MassFlowRate'
 * '<S361>' : 'NACCBraytonCycle2017a/Sensor24/Vdot'
 * '<S362>' : 'NACCBraytonCycle2017a/Sensor24/Calculate phi/Relative Humidity'
 * '<S363>' : 'NACCBraytonCycle2017a/Sensor24/Calculate phi/Relative Humidity/SatPressures1'
 * '<S364>' : 'NACCBraytonCycle2017a/Sensor24/MassFlowRate/Molar Weight'
 * '<S365>' : 'NACCBraytonCycle2017a/Sensor24/Vdot/Density'
 * '<S366>' : 'NACCBraytonCycle2017a/Sensor24/Vdot/MassFlowRate'
 * '<S367>' : 'NACCBraytonCycle2017a/Sensor24/Vdot/MolarWeight'
 * '<S368>' : 'NACCBraytonCycle2017a/Sensor24/Vdot/MolarWeight1'
 * '<S369>' : 'NACCBraytonCycle2017a/Sensor24/Vdot/MassFlowRate/Molar Weight'
 * '<S370>' : 'NACCBraytonCycle2017a/Sensor25/Calculate phi'
 * '<S371>' : 'NACCBraytonCycle2017a/Sensor25/MassFlowRate'
 * '<S372>' : 'NACCBraytonCycle2017a/Sensor25/Vdot'
 * '<S373>' : 'NACCBraytonCycle2017a/Sensor25/Calculate phi/Relative Humidity'
 * '<S374>' : 'NACCBraytonCycle2017a/Sensor25/Calculate phi/Relative Humidity/SatPressures1'
 * '<S375>' : 'NACCBraytonCycle2017a/Sensor25/MassFlowRate/Molar Weight'
 * '<S376>' : 'NACCBraytonCycle2017a/Sensor25/Vdot/Density'
 * '<S377>' : 'NACCBraytonCycle2017a/Sensor25/Vdot/MassFlowRate'
 * '<S378>' : 'NACCBraytonCycle2017a/Sensor25/Vdot/MolarWeight'
 * '<S379>' : 'NACCBraytonCycle2017a/Sensor25/Vdot/MolarWeight1'
 * '<S380>' : 'NACCBraytonCycle2017a/Sensor25/Vdot/MassFlowRate/Molar Weight'
 * '<S381>' : 'NACCBraytonCycle2017a/Sensor26/Calculate phi'
 * '<S382>' : 'NACCBraytonCycle2017a/Sensor26/MassFlowRate'
 * '<S383>' : 'NACCBraytonCycle2017a/Sensor26/Vdot'
 * '<S384>' : 'NACCBraytonCycle2017a/Sensor26/Calculate phi/Relative Humidity'
 * '<S385>' : 'NACCBraytonCycle2017a/Sensor26/Calculate phi/Relative Humidity/SatPressures1'
 * '<S386>' : 'NACCBraytonCycle2017a/Sensor26/MassFlowRate/Molar Weight'
 * '<S387>' : 'NACCBraytonCycle2017a/Sensor26/Vdot/Density'
 * '<S388>' : 'NACCBraytonCycle2017a/Sensor26/Vdot/MassFlowRate'
 * '<S389>' : 'NACCBraytonCycle2017a/Sensor26/Vdot/MolarWeight'
 * '<S390>' : 'NACCBraytonCycle2017a/Sensor26/Vdot/MolarWeight1'
 * '<S391>' : 'NACCBraytonCycle2017a/Sensor26/Vdot/MassFlowRate/Molar Weight'
 * '<S392>' : 'NACCBraytonCycle2017a/Sensor27/Calculate phi'
 * '<S393>' : 'NACCBraytonCycle2017a/Sensor27/MassFlowRate'
 * '<S394>' : 'NACCBraytonCycle2017a/Sensor27/Vdot'
 * '<S395>' : 'NACCBraytonCycle2017a/Sensor27/Calculate phi/Relative Humidity'
 * '<S396>' : 'NACCBraytonCycle2017a/Sensor27/Calculate phi/Relative Humidity/SatPressures1'
 * '<S397>' : 'NACCBraytonCycle2017a/Sensor27/MassFlowRate/Molar Weight'
 * '<S398>' : 'NACCBraytonCycle2017a/Sensor27/Vdot/Density'
 * '<S399>' : 'NACCBraytonCycle2017a/Sensor27/Vdot/MassFlowRate'
 * '<S400>' : 'NACCBraytonCycle2017a/Sensor27/Vdot/MolarWeight'
 * '<S401>' : 'NACCBraytonCycle2017a/Sensor27/Vdot/MolarWeight1'
 * '<S402>' : 'NACCBraytonCycle2017a/Sensor27/Vdot/MassFlowRate/Molar Weight'
 * '<S403>' : 'NACCBraytonCycle2017a/Sensor3/Calculate phi'
 * '<S404>' : 'NACCBraytonCycle2017a/Sensor3/MassFlowRate'
 * '<S405>' : 'NACCBraytonCycle2017a/Sensor3/Vdot'
 * '<S406>' : 'NACCBraytonCycle2017a/Sensor3/Calculate phi/Relative Humidity'
 * '<S407>' : 'NACCBraytonCycle2017a/Sensor3/Calculate phi/Relative Humidity/SatPressures1'
 * '<S408>' : 'NACCBraytonCycle2017a/Sensor3/MassFlowRate/Molar Weight'
 * '<S409>' : 'NACCBraytonCycle2017a/Sensor3/Vdot/Density'
 * '<S410>' : 'NACCBraytonCycle2017a/Sensor3/Vdot/MassFlowRate'
 * '<S411>' : 'NACCBraytonCycle2017a/Sensor3/Vdot/MolarWeight'
 * '<S412>' : 'NACCBraytonCycle2017a/Sensor3/Vdot/MolarWeight1'
 * '<S413>' : 'NACCBraytonCycle2017a/Sensor3/Vdot/MassFlowRate/Molar Weight'
 * '<S414>' : 'NACCBraytonCycle2017a/Sensor4/Calculate phi'
 * '<S415>' : 'NACCBraytonCycle2017a/Sensor4/MassFlowRate'
 * '<S416>' : 'NACCBraytonCycle2017a/Sensor4/Vdot'
 * '<S417>' : 'NACCBraytonCycle2017a/Sensor4/Calculate phi/Relative Humidity'
 * '<S418>' : 'NACCBraytonCycle2017a/Sensor4/Calculate phi/Relative Humidity/SatPressures1'
 * '<S419>' : 'NACCBraytonCycle2017a/Sensor4/MassFlowRate/Molar Weight'
 * '<S420>' : 'NACCBraytonCycle2017a/Sensor4/Vdot/Density'
 * '<S421>' : 'NACCBraytonCycle2017a/Sensor4/Vdot/MassFlowRate'
 * '<S422>' : 'NACCBraytonCycle2017a/Sensor4/Vdot/MolarWeight'
 * '<S423>' : 'NACCBraytonCycle2017a/Sensor4/Vdot/MolarWeight1'
 * '<S424>' : 'NACCBraytonCycle2017a/Sensor4/Vdot/MassFlowRate/Molar Weight'
 * '<S425>' : 'NACCBraytonCycle2017a/Sensor5/Calculate phi'
 * '<S426>' : 'NACCBraytonCycle2017a/Sensor5/MassFlowRate'
 * '<S427>' : 'NACCBraytonCycle2017a/Sensor5/Vdot'
 * '<S428>' : 'NACCBraytonCycle2017a/Sensor5/Calculate phi/Relative Humidity'
 * '<S429>' : 'NACCBraytonCycle2017a/Sensor5/Calculate phi/Relative Humidity/SatPressures1'
 * '<S430>' : 'NACCBraytonCycle2017a/Sensor5/MassFlowRate/Molar Weight'
 * '<S431>' : 'NACCBraytonCycle2017a/Sensor5/Vdot/Density'
 * '<S432>' : 'NACCBraytonCycle2017a/Sensor5/Vdot/MassFlowRate'
 * '<S433>' : 'NACCBraytonCycle2017a/Sensor5/Vdot/MolarWeight'
 * '<S434>' : 'NACCBraytonCycle2017a/Sensor5/Vdot/MolarWeight1'
 * '<S435>' : 'NACCBraytonCycle2017a/Sensor5/Vdot/MassFlowRate/Molar Weight'
 * '<S436>' : 'NACCBraytonCycle2017a/Sensor6/Calculate phi'
 * '<S437>' : 'NACCBraytonCycle2017a/Sensor6/MassFlowRate'
 * '<S438>' : 'NACCBraytonCycle2017a/Sensor6/Vdot'
 * '<S439>' : 'NACCBraytonCycle2017a/Sensor6/Calculate phi/Relative Humidity'
 * '<S440>' : 'NACCBraytonCycle2017a/Sensor6/Calculate phi/Relative Humidity/SatPressures1'
 * '<S441>' : 'NACCBraytonCycle2017a/Sensor6/MassFlowRate/Molar Weight'
 * '<S442>' : 'NACCBraytonCycle2017a/Sensor6/Vdot/Density'
 * '<S443>' : 'NACCBraytonCycle2017a/Sensor6/Vdot/MassFlowRate'
 * '<S444>' : 'NACCBraytonCycle2017a/Sensor6/Vdot/MolarWeight'
 * '<S445>' : 'NACCBraytonCycle2017a/Sensor6/Vdot/MolarWeight1'
 * '<S446>' : 'NACCBraytonCycle2017a/Sensor6/Vdot/MassFlowRate/Molar Weight'
 * '<S447>' : 'NACCBraytonCycle2017a/Sensor7/Calculate phi'
 * '<S448>' : 'NACCBraytonCycle2017a/Sensor7/MassFlowRate'
 * '<S449>' : 'NACCBraytonCycle2017a/Sensor7/Vdot'
 * '<S450>' : 'NACCBraytonCycle2017a/Sensor7/Calculate phi/Relative Humidity'
 * '<S451>' : 'NACCBraytonCycle2017a/Sensor7/Calculate phi/Relative Humidity/SatPressures1'
 * '<S452>' : 'NACCBraytonCycle2017a/Sensor7/MassFlowRate/Molar Weight'
 * '<S453>' : 'NACCBraytonCycle2017a/Sensor7/Vdot/Density'
 * '<S454>' : 'NACCBraytonCycle2017a/Sensor7/Vdot/MassFlowRate'
 * '<S455>' : 'NACCBraytonCycle2017a/Sensor7/Vdot/MolarWeight'
 * '<S456>' : 'NACCBraytonCycle2017a/Sensor7/Vdot/MolarWeight1'
 * '<S457>' : 'NACCBraytonCycle2017a/Sensor7/Vdot/MassFlowRate/Molar Weight'
 * '<S458>' : 'NACCBraytonCycle2017a/Sensor8/Calculate phi'
 * '<S459>' : 'NACCBraytonCycle2017a/Sensor8/MassFlowRate'
 * '<S460>' : 'NACCBraytonCycle2017a/Sensor8/Vdot'
 * '<S461>' : 'NACCBraytonCycle2017a/Sensor8/Calculate phi/Relative Humidity'
 * '<S462>' : 'NACCBraytonCycle2017a/Sensor8/Calculate phi/Relative Humidity/SatPressures1'
 * '<S463>' : 'NACCBraytonCycle2017a/Sensor8/MassFlowRate/Molar Weight'
 * '<S464>' : 'NACCBraytonCycle2017a/Sensor8/Vdot/Density'
 * '<S465>' : 'NACCBraytonCycle2017a/Sensor8/Vdot/MassFlowRate'
 * '<S466>' : 'NACCBraytonCycle2017a/Sensor8/Vdot/MolarWeight'
 * '<S467>' : 'NACCBraytonCycle2017a/Sensor8/Vdot/MolarWeight1'
 * '<S468>' : 'NACCBraytonCycle2017a/Sensor8/Vdot/MassFlowRate/Molar Weight'
 * '<S469>' : 'NACCBraytonCycle2017a/Sensor9/Calculate phi'
 * '<S470>' : 'NACCBraytonCycle2017a/Sensor9/MassFlowRate'
 * '<S471>' : 'NACCBraytonCycle2017a/Sensor9/Vdot'
 * '<S472>' : 'NACCBraytonCycle2017a/Sensor9/Calculate phi/Relative Humidity'
 * '<S473>' : 'NACCBraytonCycle2017a/Sensor9/Calculate phi/Relative Humidity/SatPressures1'
 * '<S474>' : 'NACCBraytonCycle2017a/Sensor9/MassFlowRate/Molar Weight'
 * '<S475>' : 'NACCBraytonCycle2017a/Sensor9/Vdot/Density'
 * '<S476>' : 'NACCBraytonCycle2017a/Sensor9/Vdot/MassFlowRate'
 * '<S477>' : 'NACCBraytonCycle2017a/Sensor9/Vdot/MolarWeight'
 * '<S478>' : 'NACCBraytonCycle2017a/Sensor9/Vdot/MolarWeight1'
 * '<S479>' : 'NACCBraytonCycle2017a/Sensor9/Vdot/MassFlowRate/Molar Weight'
 */
#endif                                 /* RTW_HEADER_NACCBraytonCycle2017a_h_ */

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : NACCBraytonCycle2017a
 * Model version : 1.151
 * VeriStand Model Framework version : 2017.0.1.0 (2017 f1)
 * Source generated on : Wed Mar 06 17:30:56 2019
 *========================================================================*/
#if !defined(NI_HEADER_NACCBraytonCycle2017a_h_)
#define NI_HEADER_NACCBraytonCycle2017a_h_
#ifdef NI_ROOTMODEL_NACCBraytonCycle2017a

/* main model definitions enabled by makefile */
#include "ni_pglobals.h"
#ifndef NI_VERISTAND_MODELDATAFILE
#ifdef NI_VERISTAND_MAINMODELFILE

/* NACCBraytonCycle2017a.c definitions */
int READSIDE = 0;
int tid = 0;

#ifdef MULTITASKING

/* multi-rate model */
P_NACCBraytonCycle2017a_T rtParameter[NUMST+!TID01EQ];
P_NACCBraytonCycle2017a_T *param_lookup[NUMST][2] = {
  { &rtParameter[0], &rtParameter[1] },
};

#else

/* single-rate model */
P_NACCBraytonCycle2017a_T rtParameter[2];

#endif

#else

extern int READSIDE;

#ifdef MULTITASKING

/* multi-rate model */
extern int tid;
extern P_NACCBraytonCycle2017a_T* param_lookup[NUMST][2];

#else

/* single-rate model */
extern P_NACCBraytonCycle2017a_T rtParameter[];

#endif
#endif

/* Declare parameter macros */
#define _NI_DEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"
#endif
#endif
#endif                                 /* NI_HEADER_NACCBraytonCycle2017a_h_ */
