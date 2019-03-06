/*
 * NACCBraytonCycle2017a_types.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "NACCBraytonCycle2017a".
 *
 * Model version              : 1.138
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Mar 06 14:28:17 2019
 *
 * Target selection: NIVeriStand.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_NACCBraytonCycle2017a_types_h_
#define RTW_HEADER_NACCBraytonCycle2017a_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#ifndef DEFINED_TYPEDEF_FOR_FlowBus_
#define DEFINED_TYPEDEF_FOR_FlowBus_

typedef struct {
  real_T ndot;
  real_T T;
  real_T p;
  real_T Hdot;
  real_T Sdot;
  real_T Gdot;
  real_T Cpdot;
  real_T x[7];
  real_T psi[7];
} FlowBus;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SensorBus_
#define DEFINED_TYPEDEF_FOR_SensorBus_

typedef struct {
  real_T ndot;
  real_T T;
  real_T p;
  real_T Hdot;
  real_T Sdot;
  real_T Gdot;
  real_T Cpdot;
  real_T phi;
  real_T x[7];
  real_T psi[7];
  real_T mdot;
  real_T Vdot_gas;
  real_T Vdot;
  real_T Vdot_liquid;
} SensorBus;

#endif

/* Parameters for system: '<S1>/MassFlow' */
typedef struct P_MassFlow_NACCBraytonCycle20_T_ P_MassFlow_NACCBraytonCycle20_T;

/* Parameters for system: '<S57>/calculate  conversion' */
typedef struct P_calculateconversion_NACCBra_T_ P_calculateconversion_NACCBra_T;

/* Parameters (auto storage) */
typedef struct P_NACCBraytonCycle2017a_T_ P_NACCBraytonCycle2017a_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_NACCBraytonCycle2017a_T RT_MODEL_NACCBraytonCycle2017_T;

#endif                                 /* RTW_HEADER_NACCBraytonCycle2017a_types_h_ */
