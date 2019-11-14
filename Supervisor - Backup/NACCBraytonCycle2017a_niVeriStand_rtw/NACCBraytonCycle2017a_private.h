/*
 * NACCBraytonCycle2017a_private.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "NACCBraytonCycle2017a".
 *
 * Model version              : 1.150
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Wed Mar 20 14:31:45 2019
 *
 * Target selection: NIVeriStand.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_NACCBraytonCycle2017a_private_h_
#define RTW_HEADER_NACCBraytonCycle2017a_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "NACCBraytonCycle2017a.h"

extern real_T rt_powd_snf(real_T u0, real_T u1);

#include <th_Functions.h>
#include <th_Functions.h>
#include <th_Functions.h>
#include <th_Functions.h>
#include <th_Functions.h>

void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi);
void Look2D_real_T_real_T_real_T(real_T *pY, const real_T *pYData, real_T u0,
  const real_T *pU0Data, uint32_T iHiU0, real_T u1, const real_T *pU1Data,
  uint32_T iHiU1);
void LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u, const
  real_T *pUData, uint32_T iHi);
extern void NACCBraytonCycle2017a_MolarFlow(real_T rtu_ndotmoles, real_T
  *rty_moles);
extern void NACCBraytonCycle2017a_MassFlow(real_T rtu_mdotkgs, const real_T
  rtu_psi[7], real_T *rty_ndotmols, P_MassFlow_NACCBraytonCycle20_T *localP);
extern void NACCBrayton_calculateconversion(const real_T rtu_reaction[7], const
  real_T rtu_psi[7], real_T rtu_conversionrate, B_calculateconversion_NACCBra_T *
  localB, P_calculateconversion_NACCBra_T *localP);
extern void NACCBray_TpVaporFractions_Start(void);
extern void NACCBraytonCyc_TpVaporFractions(void);
extern void NACCBr_TpVaporFractions_h_Start(void);
extern void NACCBraytonC_TpVaporFractions_i(void);
extern void NACCBraytonCycle2_TpState_Start(void);
extern void NACCBraytonCycle2017a_TpState(void);
extern void NACCBr_TpVaporFractions_o_Start(void);
extern void NACCBraytonC_TpVaporFractions_f(void);
extern void NACCBraytonCycl_TpState_j_Start(void);
extern void NACCBraytonCycle2017a_TpState_f(void);
extern void NACCBr_TpVaporFractions_f_Start(void);
extern void NACCBraytonC_TpVaporFractions_p(void);
extern void NACCBr_TpVaporFractions_b_Start(void);
extern void NACCBraytonC_TpVaporFractions_m(void);
extern void NACCBraytonCycl_TpState_d_Start(void);
extern void NACCBraytonCycle2017a_TpState_a(void);

#endif                                 /* RTW_HEADER_NACCBraytonCycle2017a_private_h_ */
