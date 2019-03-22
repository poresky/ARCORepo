/*
 * NACCBraytonCycle2017a.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "NACCBraytonCycle2017a".
 *
 * Model version              : 1.139
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Thu Mar 14 16:45:14 2019
 *
 * Target selection: NIVeriStand.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "NACCBraytonCycle2017a.h"
#include "NACCBraytonCycle2017a_private.h"

/* Block signals (auto storage) */
B_NACCBraytonCycle2017a_T NACCBraytonCycle2017a_B;

/* Block states (auto storage) */
DW_NACCBraytonCycle2017a_T NACCBraytonCycle2017a_DW;

/* External inputs (root inport signals with auto storage) */
ExtU_NACCBraytonCycle2017a_T NACCBraytonCycle2017a_U;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_NACCBraytonCycle2017a_T NACCBraytonCycle2017a_Y;

/* Real-time model */
RT_MODEL_NACCBraytonCycle2017_T NACCBraytonCycle2017a_M_;
RT_MODEL_NACCBraytonCycle2017_T *const NACCBraytonCycle2017a_M =
  &NACCBraytonCycle2017a_M_;

/* Lookup Binary Search Utility BINARYSEARCH_real_T */
void BINARYSEARCH_real_T(uint32_T *piLeft, uint32_T *piRght, real_T u, const
  real_T *pData, uint32_T iHi)
{
  /* Find the location of current input value in the data table. */
  *piLeft = 0U;
  *piRght = iHi;
  if (u <= pData[0] ) {
    /* Less than or equal to the smallest point in the table. */
    *piRght = 0U;
  } else if (u >= pData[iHi] ) {
    /* Greater than or equal to the largest point in the table. */
    *piLeft = iHi;
  } else {
    uint32_T i;

    /* Do a binary search. */
    while (( *piRght - *piLeft ) > 1U ) {
      /* Get the average of the left and right indices using to Floor rounding. */
      i = (*piLeft + *piRght) >> 1;

      /* Move either the right index or the left index so that */
      /*  LeftDataPoint <= CurrentValue < RightDataPoint */
      if (u < pData[i] ) {
        *piRght = i;
      } else {
        *piLeft = i;
      }
    }
  }
}

/* Lookup 2D Lookup Utility Look2D_real_T_real_T_real_T */
void Look2D_real_T_real_T_real_T(real_T *pY, const real_T *pYData, real_T u0,
  const real_T *pU0Data, uint32_T iHiU0, real_T u1, const real_T *pU1Data,
  uint32_T iHiU1)
{
  uint32_T iLeftU0, iRghtU0, iLeftU1, iRghtU1;
  BINARYSEARCH_real_T( &(iLeftU0), &(iRghtU0), u0, pU0Data, iHiU0);
  BINARYSEARCH_real_T( &(iLeftU1), &(iRghtU1), u1, pU1Data, iHiU1);

  {
    real_T u0Left = pU0Data[iLeftU0];
    real_T u0Rght = pU0Data[iRghtU0];
    real_T u1Left = pU1Data[iLeftU1];
    real_T u1Rght = pU1Data[iRghtU1];
    real_T yTemp;
    real_T yLeftLeft;
    real_T yLeftRght;
    real_T yRghtLeft;
    real_T yRghtRght;
    real_T u1Lambda;
    real_T u0Lambda;
    if (u1Rght > u1Left ) {
      real_T num;
      real_T den;
      den = u1Rght;
      den -= u1Left;
      num = u1;
      num -= u1Left;
      u1Lambda = num / den;
    } else {
      u1Lambda = 0.0;
    }

    if (u0Rght > u0Left ) {
      real_T num;
      real_T den;
      den = u0Rght;
      den -= u0Left;
      num = u0;
      num -= u0Left;
      u0Lambda = num / den;
    } else {
      u0Lambda = 0.0;
    }

    iHiU0++;
    iLeftU1 *= iHiU0;
    iRghtU1 *= iHiU0;
    yRghtLeft = pYData[(iRghtU0+iLeftU1)];
    yRghtRght = pYData[(iRghtU0+iRghtU1)];
    yLeftLeft = pYData[(iLeftU0+iLeftU1)];
    yLeftRght = pYData[(iLeftU0+iRghtU1)];

    /* Interpolate along U1 variable
     *    with the u0 variable locked on the left u0
     */
    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = yLeftLeft;
      yRghtCast = yLeftRght;
      yLeftCast += u1Lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }

    /* Interpolate along U1 variable
     *    with the u0 variable locked on the right u0
     */
    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = yRghtLeft;
      yRghtCast = yRghtRght;
      yLeftCast += u1Lambda * ( yRghtCast - yLeftCast );
      yTemp = yLeftCast;
    }

    /*
     * Interpolate along u0 variable
     *    with the u1 variable locked on its interpolated value
     */
    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = (*pY);
      yRghtCast = yTemp;
      yLeftCast += u0Lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }
  }
}

/* Lookup Utility LookUp_real_T_real_T */
void LookUp_real_T_real_T(real_T *pY, const real_T *pYData, real_T u, const
  real_T *pUData, uint32_T iHi)
{
  uint32_T iLeft;
  uint32_T iRght;
  BINARYSEARCH_real_T( &(iLeft), &(iRght), u, pUData, iHi);

  {
    real_T lambda;
    if (pUData[iRght] > pUData[iLeft] ) {
      real_T num;
      real_T den;
      den = pUData[iRght];
      den -= pUData[iLeft];
      num = u;
      num -= pUData[iLeft];
      lambda = num / den;
    } else {
      lambda = 0.0;
    }

    {
      real_T yLeftCast;
      real_T yRghtCast;
      yLeftCast = pYData[iLeft];
      yRghtCast = pYData[iRght];
      yLeftCast += lambda * ( yRghtCast - yLeftCast );
      (*pY) = yLeftCast;
    }
  }
}

/*
 * Output and update for action system:
 *    '<S1>/MolarFlow'
 *    '<S12>/MolarFlow'
 */
void NACCBraytonCycle2017a_MolarFlow(real_T rtu_ndotmoles, real_T *rty_moles)
{
  /* Inport: '<S42>/ndot[mole//s]' */
  *rty_moles = rtu_ndotmoles;
}

/*
 * Output and update for action system:
 *    '<S1>/MassFlow'
 *    '<S12>/MassFlow'
 */
void NACCBraytonCycle2017a_MassFlow(real_T rtu_mdotkgs, const real_T rtu_psi[7],
  real_T *rty_ndotmols, P_MassFlow_NACCBraytonCycle20_T *localP)
{
  real_T tmp;
  int32_T i;

  /* Product: '<S41>/Product' incorporates:
   *  Constant: '<S49>/M1'
   *  Math: '<S41>/Math Function'
   */
  tmp = 0.0;
  for (i = 0; i < 7; i++) {
    tmp += rtu_psi[i] * NACCBraytonCycle2017a_P.th_M[i];
  }

  /* Product: '<S41>/Divide' incorporates:
   *  Gain: '<S41>/Gain'
   *  Product: '<S41>/Product'
   */
  *rty_ndotmols = localP->Gain_Gain * rtu_mdotkgs / tmp;
}

/* Start for atomic system: '<S48>/T-p-Vapor Fractions' */
void NACCBray_TpVaporFractions_Start(void)
{
  /* Start for S-Function (th_TpVaporFractions_PR_S): '<S52>/S-Function1' incorporates:
   *  Constant: '<S1>/psi'
   */
  {
    th_ThermolibInitialize();
  }
}

/* Output and update for atomic system: '<S48>/T-p-Vapor Fractions' */
void NACCBraytonCyc_TpVaporFractions(void)
{
  /* S-Function (th_TpVaporFractions_PR_S): '<S52>/S-Function1' incorporates:
   *  Constant: '<S1>/psi'
   */
  /*Block <S52>/S-Function1*/
  {
    int* error;
    Par param;
    flow pflow;
    th_InitParameters(&param);
    th_InitFlow(&pflow);
    param.nr_species = 7;
    param.water_index= (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);

    /* Map inputs */
    pflow.T_ = (double *)&NACCBraytonCycle2017a_B.UnitOffset;
    pflow.p_ = (double *)&NACCBraytonCycle2017a_B.UnitOffset_h;
    pflow.psi= (double *)&NACCBraytonCycle2017a_P.Ambientair_psi[0];
    pflow.nr_flows = 1;

    /* Map outputs */
    pflow.x = (double *) &NACCBraytonCycle2017a_B.SFunction1_o1_o[0];
    error = (int *) &NACCBraytonCycle2017a_B.SFunction1_o2_p;
    error[0]= th_T_p_VaporFractions(&pflow, &param);
  }
}

/* Start for atomic system: '<S44>/T-p-Vapor Fractions' */
void NACCBr_TpVaporFractions_h_Start(void)
{
  /* Start for S-Function (th_TpVaporFractions_PR_S): '<S50>/S-Function1' incorporates:
   *  Constant: '<S1>/psi'
   */
  {
    th_ThermolibInitialize();
  }
}

/* Output and update for atomic system: '<S44>/T-p-Vapor Fractions' */
void NACCBraytonC_TpVaporFractions_i(void)
{
  /* S-Function (th_TpVaporFractions_PR_S): '<S50>/S-Function1' incorporates:
   *  Constant: '<S1>/psi'
   */
  /*Block <S50>/S-Function1*/
  {
    int* error;
    Par param;
    flow pflow;
    th_InitParameters(&param);
    th_InitFlow(&pflow);
    param.nr_species = 7;
    param.water_index= (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);

    /* Map inputs */
    pflow.T_ = (double *)&NACCBraytonCycle2017a_B.UnitOffset;
    pflow.p_ = (double *)&NACCBraytonCycle2017a_B.UnitOffset_h;
    pflow.psi= (double *)&NACCBraytonCycle2017a_P.Ambientair_psi[0];
    pflow.nr_flows = 1;

    /* Map outputs */
    pflow.x = (double *) &NACCBraytonCycle2017a_B.SFunction1_o1_n[0];
    error = (int *) &NACCBraytonCycle2017a_B.SFunction1_o2_gm;
    error[0]= th_T_p_VaporFractions(&pflow, &param);
  }
}

/* Start for atomic system: '<S1>/T-p-State' */
void NACCBraytonCycle2_TpState_Start(void)
{
  /* Start for Atomic SubSystem: '<S44>/T-p-Vapor Fractions' */
  NACCBr_TpVaporFractions_h_Start();

  /* End of Start for SubSystem: '<S44>/T-p-Vapor Fractions' */

  /* Start for S-Function (th_TpxState_S): '<S51>/S-Function1' */
  {
    th_ThermolibInitialize();
  }
}

/* Output and update for atomic system: '<S1>/T-p-State' */
void NACCBraytonCycle2017a_TpState(void)
{
  int32_T i;

  /* Outputs for Atomic SubSystem: '<S44>/T-p-Vapor Fractions' */
  NACCBraytonC_TpVaporFractions_i();

  /* End of Outputs for SubSystem: '<S44>/T-p-Vapor Fractions' */

  /* Gain: '<S51>/Gain' */
  NACCBraytonCycle2017a_B.ndot_lp = NACCBraytonCycle2017a_P.Gain_Gain *
    NACCBraytonCycle2017a_B.ndot;

  /* Gain: '<S51>/Gain1' */
  NACCBraytonCycle2017a_B.T_gw = NACCBraytonCycle2017a_P.Gain1_Gain *
    NACCBraytonCycle2017a_B.UnitOffset;

  /* Gain: '<S51>/Gain2' */
  NACCBraytonCycle2017a_B.p_d = NACCBraytonCycle2017a_P.Gain2_Gain *
    NACCBraytonCycle2017a_B.UnitOffset_h;
  for (i = 0; i < 7; i++) {
    /* Gain: '<S51>/Gain3' */
    NACCBraytonCycle2017a_B.x_g[i] = NACCBraytonCycle2017a_P.Gain3_Gain *
      NACCBraytonCycle2017a_B.SFunction1_o1_n[i];

    /* Gain: '<S51>/Gain4' incorporates:
     *  Constant: '<S1>/psi'
     */
    NACCBraytonCycle2017a_B.psi_eg[i] = NACCBraytonCycle2017a_P.Gain4_Gain *
      NACCBraytonCycle2017a_P.Ambientair_psi[i];
  }

  /* S-Function (th_TpxState_S): '<S51>/S-Function1' */
  /*Block <S51>/S-Function1*/
  {
    Par param;
    flow pflow;
    int* error;
    nasa *pNASA = (nasa*)EUallocate(sizeof(nasa));
    nasa *pNASA1 = (nasa*)EUallocate(sizeof(nasa));
    th_SPoly3 *pCp_liq = (th_SPoly3*)EUallocate(sizeof(th_SPoly3));
    th_InitParameters(&param);
    th_InitFlow(&pflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1[7] - pNASA->len
                          * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1[7] + pNASA->len
                          * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1[7] + pNASA->len
                          * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1[7] + pNASA->len
                          * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1[7] + pNASA->len
                          * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1[7] + pNASA->len
                          * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1[7] + pNASA->len
                          * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq[7] +
      pCp_liq->len * 2);
    param.nr_species = (int)7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.water_index = (int)0.0;
    param.if97_index = (int)-1.0;
    param.gas_eos_method = (int)1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.pCp_liq = pCp_liq;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction1_P12;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P13[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P14[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);

    /* Map inputs */
    pflow.nr_flows = 1;
    pflow.ndot_ = (double *)&NACCBraytonCycle2017a_B.ndot_lp;
    pflow.T_ = (double *)&NACCBraytonCycle2017a_B.T_gw;
    pflow.p_ = (double *)&NACCBraytonCycle2017a_B.p_d;
    pflow.x = (double *)&NACCBraytonCycle2017a_B.x_g[0];
    pflow.psi = (double *)&NACCBraytonCycle2017a_B.psi_eg[0];

    /* Map outputs */
    pflow.Hdot_ = (double *)&NACCBraytonCycle2017a_B.Hdot_a;
    pflow.Sdot_ = (double *)&NACCBraytonCycle2017a_B.Sdot_c0;
    pflow.Gdot_ = (double *)&NACCBraytonCycle2017a_B.Gdot_ny;
    pflow.Cpdot_= (double *)&NACCBraytonCycle2017a_B.Cpdot_f;
    error = (int *) &NACCBraytonCycle2017a_B.SFunction1_o5_o;
    error[0] = th_T_p_x_State_new (&pflow, &param);
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }
}

/*
 * Output and update for atomic system:
 *    '<S57>/calculate  conversion'
 *    '<S65>/calculate  conversion'
 */
void NACCBrayton_calculateconversion(const real_T rtu_reaction[7], const real_T
  rtu_psi[7], real_T rtu_conversionrate, B_calculateconversion_NACCBra_T *localB,
  P_calculateconversion_NACCBra_T *localP)
{
  int8_T rtb_Compare_j2[7];
  real_T rtb_Subtract2[7];
  real_T rtb_Product1_e;
  int32_T i;
  uint8_T rtb_Compare_k;
  for (i = 0; i < 7; i++) {
    /* RelationalOperator: '<S63>/Compare' incorporates:
     *  Constant: '<S63>/Constant'
     */
    rtb_Compare_k = (uint8_T)(rtu_reaction[i] < localP->CompareToConstant1_const);

    /* Gain: '<S60>/Gain1' */
    rtb_Product1_e = localP->Gain1_Gain * rtu_reaction[i];

    /* Saturate: '<S60>/Saturation2' */
    if (rtb_Product1_e > localP->Saturation2_UpperSat) {
      rtb_Product1_e = localP->Saturation2_UpperSat;
    } else {
      if (rtb_Product1_e < localP->Saturation2_LowerSat) {
        rtb_Product1_e = localP->Saturation2_LowerSat;
      }
    }

    /* End of Saturate: '<S60>/Saturation2' */

    /* Product: '<S60>/Product3' */
    rtb_Subtract2[i] = rtu_psi[i] / rtb_Product1_e * (real_T)rtb_Compare_k;

    /* RelationalOperator: '<S63>/Compare' */
    rtb_Compare_j2[i] = (int8_T)rtb_Compare_k;
  }

  /* MinMax: '<S60>/MinMax2' */
  rtb_Product1_e = rtb_Subtract2[0];
  for (i = 0; i < 6; i++) {
    if (!((rtb_Product1_e > rtb_Subtract2[i + 1]) || rtIsNaN(rtb_Subtract2[i + 1])))
    {
      rtb_Product1_e = rtb_Subtract2[i + 1];
    }
  }

  /* Sum: '<S60>/Subtract2' incorporates:
   *  Logic: '<S60>/Logical Operator'
   *  MinMax: '<S60>/MinMax2'
   *  Product: '<S60>/Product2'
   */
  for (i = 0; i < 7; i++) {
    rtb_Subtract2[i] += (real_T)!(rtb_Compare_j2[i] != 0) * rtb_Product1_e;
  }

  /* End of Sum: '<S60>/Subtract2' */

  /* MinMax: '<S60>/MinMax1' */
  rtb_Product1_e = rtb_Subtract2[0];
  for (i = 0; i < 6; i++) {
    if (!((rtb_Product1_e < rtb_Subtract2[i + 1]) || rtIsNaN(rtb_Subtract2[i + 1])))
    {
      rtb_Product1_e = rtb_Subtract2[i + 1];
    }
  }

  /* Product: '<S60>/Product1' incorporates:
   *  MinMax: '<S60>/MinMax1'
   */
  rtb_Product1_e *= rtu_conversionrate;

  /* Sum: '<S64>/Subtract2' incorporates:
   *  Product: '<S64>/Product3'
   */
  for (i = 0; i < 7; i++) {
    rtb_Subtract2[i] = rtb_Product1_e * rtu_reaction[i] + rtu_psi[i];
  }

  /* End of Sum: '<S64>/Subtract2' */

  /* Sum: '<S64>/Subtract5' */
  rtb_Product1_e = rtb_Subtract2[0];
  for (i = 0; i < 6; i++) {
    rtb_Product1_e += rtb_Subtract2[i + 1];
  }

  localB->Subtract5 = rtb_Product1_e;

  /* End of Sum: '<S64>/Subtract5' */

  /* Saturate: '<S64>/Saturation2' */
  if (localB->Subtract5 > localP->Saturation2_UpperSat_l) {
    rtb_Product1_e = localP->Saturation2_UpperSat_l;
  } else if (localB->Subtract5 < localP->Saturation2_LowerSat_h) {
    rtb_Product1_e = localP->Saturation2_LowerSat_h;
  } else {
    rtb_Product1_e = localB->Subtract5;
  }

  /* End of Saturate: '<S64>/Saturation2' */

  /* Product: '<S64>/Product6' */
  for (i = 0; i < 7; i++) {
    localB->Product6[i] = rtb_Subtract2[i] / rtb_Product1_e;
  }

  /* End of Product: '<S64>/Product6' */
}

/* Start for atomic system: '<S80>/T-p-Vapor Fractions' */
void NACCBr_TpVaporFractions_o_Start(void)
{
  /* Start for S-Function (th_TpVaporFractions_PR_S): '<S86>/S-Function1' */
  {
    th_ThermolibInitialize();
  }
}

/* Output and update for atomic system: '<S80>/T-p-Vapor Fractions' */
void NACCBraytonC_TpVaporFractions_f(void)
{
  /* S-Function (th_TpVaporFractions_PR_S): '<S86>/S-Function1' */
  /*Block <S86>/S-Function1*/
  {
    int* error;
    Par param;
    flow pflow;
    th_InitParameters(&param);
    th_InitFlow(&pflow);
    param.nr_species = 7;
    param.water_index= (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);

    /* Map inputs */
    pflow.T_ = (double *)&NACCBraytonCycle2017a_B.T_gw;
    pflow.p_ = (double *)&NACCBraytonCycle2017a_B.p_d;
    pflow.psi= (double *)&NACCBraytonCycle2017a_B.psi_eg[0];
    pflow.nr_flows = 1;

    /* Map outputs */
    pflow.x = (double *) &NACCBraytonCycle2017a_B.SFunction1_o1_c[0];
    error = (int *) &NACCBraytonCycle2017a_B.SFunction1_o2_b;
    error[0]= th_T_p_VaporFractions(&pflow, &param);
  }
}

/* Start for atomic system: '<S73>/T-p-State' */
void NACCBraytonCycl_TpState_j_Start(void)
{
  /* Start for Atomic SubSystem: '<S80>/T-p-Vapor Fractions' */
  NACCBr_TpVaporFractions_o_Start();

  /* End of Start for SubSystem: '<S80>/T-p-Vapor Fractions' */

  /* Start for S-Function (th_TpxState_S): '<S87>/S-Function1' */
  {
    th_ThermolibInitialize();
  }
}

/* Output and update for atomic system: '<S73>/T-p-State' */
void NACCBraytonCycle2017a_TpState_f(void)
{
  int32_T i;

  /* Outputs for Atomic SubSystem: '<S80>/T-p-Vapor Fractions' */
  NACCBraytonC_TpVaporFractions_f();

  /* End of Outputs for SubSystem: '<S80>/T-p-Vapor Fractions' */

  /* Gain: '<S87>/Gain' */
  NACCBraytonCycle2017a_B.ndot_c0 = NACCBraytonCycle2017a_P.Gain_Gain_j *
    NACCBraytonCycle2017a_B.ndot_nc;

  /* Gain: '<S87>/Gain1' */
  NACCBraytonCycle2017a_B.p_pg = NACCBraytonCycle2017a_P.Gain1_Gain_n *
    NACCBraytonCycle2017a_B.T_gw;

  /* Gain: '<S87>/Gain2' */
  NACCBraytonCycle2017a_B.p_f = NACCBraytonCycle2017a_P.Gain2_Gain_m *
    NACCBraytonCycle2017a_B.p_d;
  for (i = 0; i < 7; i++) {
    /* Gain: '<S87>/Gain3' */
    NACCBraytonCycle2017a_B.x_da[i] = NACCBraytonCycle2017a_P.Gain3_Gain_m *
      NACCBraytonCycle2017a_B.SFunction1_o1_c[i];

    /* Gain: '<S87>/Gain4' */
    NACCBraytonCycle2017a_B.psi_ip[i] = NACCBraytonCycle2017a_P.Gain4_Gain_i *
      NACCBraytonCycle2017a_B.psi_eg[i];
  }

  /* S-Function (th_TpxState_S): '<S87>/S-Function1' */
  /*Block <S87>/S-Function1*/
  {
    Par param;
    flow pflow;
    int* error;
    nasa *pNASA = (nasa*)EUallocate(sizeof(nasa));
    nasa *pNASA1 = (nasa*)EUallocate(sizeof(nasa));
    th_SPoly3 *pCp_liq = (th_SPoly3*)EUallocate(sizeof(th_SPoly3));
    th_InitParameters(&param);
    th_InitFlow(&pflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_l[7] -
                          pNASA->len * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_l[7] +
                          pNASA->len * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_l[7] +
                          pNASA->len * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_l[7] +
                          pNASA->len * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_l[7] +
                          pNASA->len * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_l[7] +
                          pNASA->len * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_l[7] +
                          pNASA->len * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_o[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_o[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_o[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_o[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_o[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_o[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_o[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_n[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_n[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_n[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_n[7] +
      pCp_liq->len * 2);
    param.nr_species = (int)7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.water_index = (int)0.0;
    param.if97_index = (int)-1.0;
    param.gas_eos_method = (int)1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.pCp_liq = pCp_liq;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction1_P12_f;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P13_f[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P14_o[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);

    /* Map inputs */
    pflow.nr_flows = 1;
    pflow.ndot_ = (double *)&NACCBraytonCycle2017a_B.ndot_c0;
    pflow.T_ = (double *)&NACCBraytonCycle2017a_B.p_pg;
    pflow.p_ = (double *)&NACCBraytonCycle2017a_B.p_f;
    pflow.x = (double *)&NACCBraytonCycle2017a_B.x_da[0];
    pflow.psi = (double *)&NACCBraytonCycle2017a_B.psi_ip[0];

    /* Map outputs */
    pflow.Hdot_ = (double *)&NACCBraytonCycle2017a_B.Hdot_du;
    pflow.Sdot_ = (double *)&NACCBraytonCycle2017a_B.Sdot_d;
    pflow.Gdot_ = (double *)&NACCBraytonCycle2017a_B.Gdot_fo;
    pflow.Cpdot_= (double *)&NACCBraytonCycle2017a_B.Cpdot_i4;
    error = (int *) &NACCBraytonCycle2017a_B.SFunction1_o5_mw;
    error[0] = th_T_p_x_State_new (&pflow, &param);
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }
}

/* Start for atomic system: '<S158>/T-p-Vapor Fractions' */
void NACCBr_TpVaporFractions_f_Start(void)
{
  /* Start for S-Function (th_TpVaporFractions_PR_S): '<S162>/S-Function1' incorporates:
   *  Constant: '<S12>/psi'
   */
  {
    th_ThermolibInitialize();
  }
}

/* Output and update for atomic system: '<S158>/T-p-Vapor Fractions' */
void NACCBraytonC_TpVaporFractions_p(void)
{
  /* S-Function (th_TpVaporFractions_PR_S): '<S162>/S-Function1' incorporates:
   *  Constant: '<S12>/psi'
   */
  /*Block <S162>/S-Function1*/
  {
    int* error;
    Par param;
    flow pflow;
    th_InitParameters(&param);
    th_InitFlow(&pflow);
    param.nr_species = 7;
    param.water_index= (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);

    /* Map inputs */
    pflow.T_ = (double *)&NACCBraytonCycle2017a_B.UnitOffset_l;
    pflow.p_ = (double *)&NACCBraytonCycle2017a_B.UnitOffset_f;
    pflow.psi= (double *)&NACCBraytonCycle2017a_P.NaturalGas_psi[0];
    pflow.nr_flows = 1;

    /* Map outputs */
    pflow.x = (double *) &NACCBraytonCycle2017a_B.SFunction1_o1_i[0];
    error = (int *) &NACCBraytonCycle2017a_B.SFunction1_o2_g;
    error[0]= th_T_p_VaporFractions(&pflow, &param);
  }
}

/* Start for atomic system: '<S154>/T-p-Vapor Fractions' */
void NACCBr_TpVaporFractions_b_Start(void)
{
  /* Start for S-Function (th_TpVaporFractions_PR_S): '<S160>/S-Function1' incorporates:
   *  Constant: '<S12>/psi'
   */
  {
    th_ThermolibInitialize();
  }
}

/* Output and update for atomic system: '<S154>/T-p-Vapor Fractions' */
void NACCBraytonC_TpVaporFractions_m(void)
{
  /* S-Function (th_TpVaporFractions_PR_S): '<S160>/S-Function1' incorporates:
   *  Constant: '<S12>/psi'
   */
  /*Block <S160>/S-Function1*/
  {
    int* error;
    Par param;
    flow pflow;
    th_InitParameters(&param);
    th_InitFlow(&pflow);
    param.nr_species = 7;
    param.water_index= (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);

    /* Map inputs */
    pflow.T_ = (double *)&NACCBraytonCycle2017a_B.UnitOffset_l;
    pflow.p_ = (double *)&NACCBraytonCycle2017a_B.UnitOffset_f;
    pflow.psi= (double *)&NACCBraytonCycle2017a_P.NaturalGas_psi[0];
    pflow.nr_flows = 1;

    /* Map outputs */
    pflow.x = (double *) &NACCBraytonCycle2017a_B.SFunction1_o1[0];
    error = (int *) &NACCBraytonCycle2017a_B.SFunction1_o2;
    error[0]= th_T_p_VaporFractions(&pflow, &param);
  }
}

/* Start for atomic system: '<S12>/T-p-State' */
void NACCBraytonCycl_TpState_d_Start(void)
{
  /* Start for Atomic SubSystem: '<S154>/T-p-Vapor Fractions' */
  NACCBr_TpVaporFractions_b_Start();

  /* End of Start for SubSystem: '<S154>/T-p-Vapor Fractions' */

  /* Start for S-Function (th_TpxState_S): '<S161>/S-Function1' */
  {
    th_ThermolibInitialize();
  }
}

/* Output and update for atomic system: '<S12>/T-p-State' */
void NACCBraytonCycle2017a_TpState_a(void)
{
  int32_T i;

  /* Outputs for Atomic SubSystem: '<S154>/T-p-Vapor Fractions' */
  NACCBraytonC_TpVaporFractions_m();

  /* End of Outputs for SubSystem: '<S154>/T-p-Vapor Fractions' */

  /* Gain: '<S161>/Gain' */
  NACCBraytonCycle2017a_B.ndot_nc = NACCBraytonCycle2017a_P.Gain_Gain_b *
    NACCBraytonCycle2017a_B.ndot_ka;

  /* Gain: '<S161>/Gain1' */
  NACCBraytonCycle2017a_B.T_c = NACCBraytonCycle2017a_P.Gain1_Gain_l *
    NACCBraytonCycle2017a_B.UnitOffset_l;

  /* Gain: '<S161>/Gain2' */
  NACCBraytonCycle2017a_B.p_pg = NACCBraytonCycle2017a_P.Gain2_Gain_j *
    NACCBraytonCycle2017a_B.UnitOffset_f;
  for (i = 0; i < 7; i++) {
    /* Gain: '<S161>/Gain3' */
    NACCBraytonCycle2017a_B.x_a[i] = NACCBraytonCycle2017a_P.Gain3_Gain_n *
      NACCBraytonCycle2017a_B.SFunction1_o1[i];

    /* Gain: '<S161>/Gain4' incorporates:
     *  Constant: '<S12>/psi'
     */
    NACCBraytonCycle2017a_B.psi_c[i] = NACCBraytonCycle2017a_P.Gain4_Gain_iu *
      NACCBraytonCycle2017a_P.NaturalGas_psi[i];
  }

  /* S-Function (th_TpxState_S): '<S161>/S-Function1' */
  /*Block <S161>/S-Function1*/
  {
    Par param;
    flow pflow;
    int* error;
    nasa *pNASA = (nasa*)EUallocate(sizeof(nasa));
    nasa *pNASA1 = (nasa*)EUallocate(sizeof(nasa));
    th_SPoly3 *pCp_liq = (th_SPoly3*)EUallocate(sizeof(th_SPoly3));
    th_InitParameters(&param);
    th_InitFlow(&pflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_l5[7] -
                          pNASA->len * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_l5[7] +
                          pNASA->len * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_l5[7] +
                          pNASA->len * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_l5[7] +
                          pNASA->len * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_l5[7] +
                          pNASA->len * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_l5[7] +
                          pNASA->len * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_l5[7] +
                          pNASA->len * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_k[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_k[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_k[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_k[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_k[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_k[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_k[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_d[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_d[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_d[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_d[7] +
      pCp_liq->len * 2);
    param.nr_species = (int)7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.water_index = (int)0.0;
    param.if97_index = (int)-1.0;
    param.gas_eos_method = (int)1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.pCp_liq = pCp_liq;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction1_P12_e;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P13_b[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P14_me[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);

    /* Map inputs */
    pflow.nr_flows = 1;
    pflow.ndot_ = (double *)&NACCBraytonCycle2017a_B.ndot_nc;
    pflow.T_ = (double *)&NACCBraytonCycle2017a_B.T_c;
    pflow.p_ = (double *)&NACCBraytonCycle2017a_B.p_pg;
    pflow.x = (double *)&NACCBraytonCycle2017a_B.x_a[0];
    pflow.psi = (double *)&NACCBraytonCycle2017a_B.psi_c[0];

    /* Map outputs */
    pflow.Hdot_ = (double *)&NACCBraytonCycle2017a_B.Hdot_c;
    pflow.Sdot_ = (double *)&NACCBraytonCycle2017a_B.Sdot_k;
    pflow.Gdot_ = (double *)&NACCBraytonCycle2017a_B.Gdot_j;
    pflow.Cpdot_= (double *)&NACCBraytonCycle2017a_B.Cpdot_j;
    error = (int *) &NACCBraytonCycle2017a_B.SFunction1_o5_d;
    error[0] = th_T_p_x_State_new (&pflow, &param);
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  real_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

/* Model output function */
static void NACCBraytonCycle2017a_output(void)
{
  /* local block i/o variables */
  real_T rtb_Product7;
  real_T rtb_Product4;
  real_T rtb_PRatio;
  real_T rtb_eta;
  real_T rtb_Switch2;
  real_T rtb_PR;
  real_T rtb_Switch2_f;
  real_T rtb_PR_l;
  real_T rtb_mdotequivalent;
  real_T rtb_Product11_d;
  real_T rtb_EfficiencyLookupTable;
  real_T rtb_mdotequivalent_k;
  real_T rtb_Product11_mh;
  real_T rtb_EfficiencyLookupTable_e;
  real_T rtb_u;
  real_T rtb_u_j;
  real_T rtb_ModeSwitch2;
  real_T rtb_UnitOffset;
  real_T rtb_Product8_m[7];
  real_T rtb_Sum2_p5;
  real_T rtb_Sum2_g;
  int32_T i;

  /* Bias: '<S45>/UnitOffset' incorporates:
   *  Gain: '<S45>/UnitScale'
   *  Inport: '<Root>/In3'
   */
  rtb_UnitOffset = NACCBraytonCycle2017a_P.UnitScale_Gain *
    NACCBraytonCycle2017a_U.In3 + NACCBraytonCycle2017a_P.UnitOffset_Bias;

  /* Bias: '<S46>/UnitOffset' incorporates:
   *  Gain: '<S46>/UnitScale'
   *  Inport: '<Root>/In1'
   */
  NACCBraytonCycle2017a_B.UnitOffset = NACCBraytonCycle2017a_P.UnitScale_Gain_i *
    NACCBraytonCycle2017a_U.In1 + NACCBraytonCycle2017a_P.UnitOffset_Bias_c;

  /* Bias: '<S47>/UnitOffset' incorporates:
   *  Gain: '<S47>/UnitScale'
   *  Inport: '<Root>/In2'
   */
  NACCBraytonCycle2017a_B.UnitOffset_h =
    NACCBraytonCycle2017a_P.UnitScale_Gain_o * NACCBraytonCycle2017a_U.In2 +
    NACCBraytonCycle2017a_P.UnitOffset_Bias_m;

  /* If: '<S1>/If1' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/psi'
   *  Constant: '<S43>/Sonstiges1'
   */
  if (NACCBraytonCycle2017a_P.Constant1_Value_d == 1.0) {
    /* Outputs for IfAction SubSystem: '<S1>/MolarFlow' incorporates:
     *  ActionPort: '<S42>/Action Port'
     */
    NACCBraytonCycle2017a_MolarFlow(rtb_UnitOffset,
      &NACCBraytonCycle2017a_B.ndot);

    /* End of Outputs for SubSystem: '<S1>/MolarFlow' */
  } else if (NACCBraytonCycle2017a_P.Constant1_Value_d == 2.0) {
    /* Outputs for IfAction SubSystem: '<S1>/MassFlow' incorporates:
     *  ActionPort: '<S41>/Action Port'
     */
    NACCBraytonCycle2017a_MassFlow(rtb_UnitOffset,
      NACCBraytonCycle2017a_P.Ambientair_psi, &NACCBraytonCycle2017a_B.ndot,
      (P_MassFlow_NACCBraytonCycle20_T *)&NACCBraytonCycle2017a_P.MassFlow);

    /* End of Outputs for SubSystem: '<S1>/MassFlow' */
  } else if (NACCBraytonCycle2017a_P.Constant1_Value_d == 3.0) {
    /* Outputs for IfAction SubSystem: '<S1>/VolumeFlow' incorporates:
     *  ActionPort: '<S48>/Action Port'
     */

    /* Outputs for Atomic SubSystem: '<S48>/T-p-Vapor Fractions' */
    NACCBraytonCyc_TpVaporFractions();

    /* End of Outputs for SubSystem: '<S48>/T-p-Vapor Fractions' */

    /* S-Function (th_Density_S): '<S54>/S-Function' incorporates:
     *  Constant: '<S1>/psi'
     */
    /*Block <S54>/S-Function*/
    {
      Par param;
      flow pflow;
      double calculated_density[3];
      th_InitParameters(&param);
      th_InitFlow(&pflow);
      param.T_cr = NACCBraytonCycle2017a_P.th_T_c;
      param.P_cr = NACCBraytonCycle2017a_P.th_p_c;
      param.T_triple = NACCBraytonCycle2017a_P.th_T_triple;
      param.acentric_factor = NACCBraytonCycle2017a_P.th_omega;
      param.molar_weights = NACCBraytonCycle2017a_P.th_M;
      param.species_density_liquid = NACCBraytonCycle2017a_P.th_rho_liq;
      param.nr_species = 7;
      param.gas_eos_method = (int) 1.0;
      param.if97_index = (int) -1.0;
      param.vm_c = NACCBraytonCycle2017a_P.th_vm_c;
      param.rho_liq_A = NACCBraytonCycle2017a_P.th_rho_liq_A;
      param.rho_liq_B = NACCBraytonCycle2017a_P.th_rho_liq_B;
      param.rho_liq_C = NACCBraytonCycle2017a_P.th_rho_liq_C;
      param.rho_liq_D = NACCBraytonCycle2017a_P.th_rho_liq_D;
      param.E_liq = NACCBraytonCycle2017a_P.th_E_liq;
      param.antoine_A = NACCBraytonCycle2017a_P.th_Antoine_A;
      param.antoine_B = NACCBraytonCycle2017a_P.th_Antoine_B;
      param.antoine_C = NACCBraytonCycle2017a_P.th_Antoine_C;
      param.T_v_ref = NACCBraytonCycle2017a_P.th_T_v_ref;
      param.density_calculation_mode = (int) 0.0;
      pflow.T_ = (double *)&NACCBraytonCycle2017a_B.UnitOffset;
      pflow.p_ = (double *)&NACCBraytonCycle2017a_B.UnitOffset_h;
      pflow.x = &NACCBraytonCycle2017a_B.SFunction1_o1_o[0];
      pflow.psi = &NACCBraytonCycle2017a_P.Ambientair_psi[0];
      pflow.nr_flows = 1;
      (&NACCBraytonCycle2017a_B.SFunction_o4_a)[0] = th_density(&pflow, &param,
        calculated_density);
      (&NACCBraytonCycle2017a_B.SFunction_o1_j)[0] = calculated_density[0];
      (&NACCBraytonCycle2017a_B.SFunction_o2_f)[0] = calculated_density[1];
      (&NACCBraytonCycle2017a_B.SFunction_o3_o)[0] = calculated_density[2];
    }

    /* Product: '<S55>/Product8' incorporates:
     *  Constant: '<S1>/psi'
     *  Constant: '<S56>/M1'
     */
    rtb_Product8_m[0] = NACCBraytonCycle2017a_P.Ambientair_psi[0] *
      NACCBraytonCycle2017a_P.th_M[0];

    /* Sum: '<S55>/Sum2' */
    rtb_Sum2_p5 = rtb_Product8_m[0];
    for (i = 0; i < 6; i++) {
      /* Product: '<S55>/Product8' incorporates:
       *  Constant: '<S1>/psi'
       *  Constant: '<S56>/M1'
       */
      rtb_Product8_m[i + 1] = NACCBraytonCycle2017a_P.Ambientair_psi[i + 1] *
        NACCBraytonCycle2017a_P.th_M[i + 1];

      /* Sum: '<S55>/Sum2' incorporates:
       *  Product: '<S55>/Product8'
       */
      rtb_Sum2_p5 += rtb_Product8_m[i + 1];
    }

    /* Product: '<S53>/Product1' incorporates:
     *  Constant: '<S53>/Constant'
     *  Product: '<S53>/Product'
     *  Product: '<S55>/Product11'
     */
    NACCBraytonCycle2017a_B.ndot = rtb_UnitOffset *
      NACCBraytonCycle2017a_B.SFunction_o2_f /
      (NACCBraytonCycle2017a_P.Constant_Value * rtb_Sum2_p5);

    /* End of Outputs for SubSystem: '<S1>/VolumeFlow' */
  } else {
    if (NACCBraytonCycle2017a_P.Constant1_Value_d == 4.0) {
      /* Outputs for IfAction SubSystem: '<S1>/Reservoir' incorporates:
       *  ActionPort: '<S43>/Action Port'
       */
      NACCBraytonCycle2017a_B.ndot = NACCBraytonCycle2017a_P.Sonstiges1_Value;

      /* End of Outputs for SubSystem: '<S1>/Reservoir' */
    }
  }

  /* End of If: '<S1>/If1' */

  /* Outputs for Atomic SubSystem: '<S1>/T-p-State' */
  NACCBraytonCycle2017a_TpState();

  /* End of Outputs for SubSystem: '<S1>/T-p-State' */

  /* Product: '<S322>/Product8' incorporates:
   *  Constant: '<S326>/M1'
   */
  rtb_Product8_m[0] = NACCBraytonCycle2017a_B.psi_eg[0] *
    NACCBraytonCycle2017a_P.th_M[0];

  /* Sum: '<S322>/Sum2' */
  rtb_ModeSwitch2 = rtb_Product8_m[0];
  for (i = 0; i < 6; i++) {
    /* Product: '<S322>/Product8' incorporates:
     *  Constant: '<S326>/M1'
     */
    rtb_Product8_m[i + 1] = NACCBraytonCycle2017a_B.psi_eg[i + 1] *
      NACCBraytonCycle2017a_P.th_M[i + 1];

    /* Sum: '<S322>/Sum2' incorporates:
     *  Product: '<S322>/Product8'
     */
    rtb_ModeSwitch2 += rtb_Product8_m[i + 1];
  }

  /* Outport: '<Root>/Out1' incorporates:
   *  Constant: '<S27>/addition factor1'
   *  Gain: '<S27>/Gain1'
   *  Gain: '<S27>/Gain2'
   *  Product: '<S322>/Product11'
   *  Sum: '<S27>/Add'
   */
  NACCBraytonCycle2017a_Y.Out1 = NACCBraytonCycle2017a_B.ndot_lp *
    rtb_ModeSwitch2 * NACCBraytonCycle2017a_P.Gain2_Gain_a3 *
    NACCBraytonCycle2017a_P.Gain1_Gain_g +
    NACCBraytonCycle2017a_P.additionfactor1_Value;

  /* Outport: '<Root>/Out2' incorporates:
   *  Constant: '<S26>/addition factor1'
   *  Gain: '<S26>/Gain1'
   *  Sum: '<S26>/Add'
   */
  NACCBraytonCycle2017a_Y.Out2 = NACCBraytonCycle2017a_P.Gain1_Gain_l3 *
    NACCBraytonCycle2017a_B.T_gw +
    NACCBraytonCycle2017a_P.additionfactor1_Value_m;

  /* Outport: '<Root>/Out3' incorporates:
   *  Constant: '<S28>/addition factor1'
   *  Gain: '<S28>/Gain1'
   *  Sum: '<S28>/Add'
   */
  NACCBraytonCycle2017a_Y.Out3 = NACCBraytonCycle2017a_P.Gain1_Gain_c *
    NACCBraytonCycle2017a_B.p_d +
    NACCBraytonCycle2017a_P.additionfactor1_Value_o;

  /* Outport: '<Root>/Out4' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Constant: '<S29>/addition factor1'
   *  Gain: '<S29>/Gain1'
   *  Product: '<Root>/Product'
   *  Sum: '<S29>/Add'
   */
  NACCBraytonCycle2017a_Y.Out4 = (NACCBraytonCycle2017a_P.Gain1_Gain_ln *
    NACCBraytonCycle2017a_B.Hdot_a +
    NACCBraytonCycle2017a_P.additionfactor1_Value_p) *
    NACCBraytonCycle2017a_P.Constant2_Value_c;

  /* Gain: '<S81>/Gain' incorporates:
   *  Constant: '<S81>/Constant4'
   *  Memory: '<S73>/Memory1'
   *  Sum: '<S81>/Subtract'
   */
  rtb_ModeSwitch2 = (NACCBraytonCycle2017a_DW.Memory1_PreviousInput[0] -
                     NACCBraytonCycle2017a_P.Constant4_Value_p) *
    NACCBraytonCycle2017a_P.Gain_Gain_f;

  /* Sum: '<S81>/Subtract1' incorporates:
   *  Constant: '<S81>/Constant'
   *  Fcn: '<S81>/Fcn [-2 2]'
   *  Gain: '<S81>/p_Relaxation'
   */
  rtb_Sum2_g = ((((0.0116 * rt_powd_snf(rtb_ModeSwitch2, 5.0) - 6.0e-16 *
                   rt_powd_snf(rtb_ModeSwitch2, 4.0)) + 0.0148 * rt_powd_snf
                  (rtb_ModeSwitch2, 3.0)) + 7.0e-16 * rt_powd_snf
                 (rtb_ModeSwitch2, 2.0)) + 0.0064 * rtb_ModeSwitch2) *
    NACCBraytonCycle2017a_P.p_Relaxation_Gain +
    NACCBraytonCycle2017a_P.Constant_Value_l;

  /* Saturate: '<S81>/Saturation' */
  if (rtb_Sum2_g > NACCBraytonCycle2017a_P.Saturation_UpperSat_p) {
    rtb_Sum2_g = NACCBraytonCycle2017a_P.Saturation_UpperSat_p;
  } else {
    if (rtb_Sum2_g < NACCBraytonCycle2017a_P.Saturation_LowerSat_k) {
      rtb_Sum2_g = NACCBraytonCycle2017a_P.Saturation_LowerSat_k;
    }
  }

  /* End of Saturate: '<S81>/Saturation' */

  /* Product: '<S81>/Product1' incorporates:
   *  Memory: '<S81>/Memory'
   */
  NACCBraytonCycle2017a_B.Product1 = rtb_Sum2_g *
    NACCBraytonCycle2017a_DW.Memory_PreviousInput;

  /* MultiPortSwitch: '<S73>/Mode Switch3' incorporates:
   *  Constant: '<S73>/Constant8'
   *  Constant: '<S81>/Constant3'
   *  Memory: '<S73>/Memory1'
   *  Product: '<S81>/Product'
   *  Product: '<S88>/Product11'
   */
  if ((int32_T)NACCBraytonCycle2017a_P.CompressorPressureFeedback_Mode == 1) {
    NACCBraytonCycle2017a_B.ndot_nc = NACCBraytonCycle2017a_B.ndot_lp;
  } else {
    /* Product: '<S88>/Product8' incorporates:
     *  Constant: '<S89>/M1'
     */
    rtb_Product8_m[0] = NACCBraytonCycle2017a_B.psi_eg[0] *
      NACCBraytonCycle2017a_P.th_M[0];

    /* Sum: '<S88>/Sum2' */
    rtb_Sum2_g = rtb_Product8_m[0];
    for (i = 0; i < 6; i++) {
      /* Product: '<S88>/Product8' incorporates:
       *  Constant: '<S89>/M1'
       */
      rtb_Product8_m[i + 1] = NACCBraytonCycle2017a_B.psi_eg[i + 1] *
        NACCBraytonCycle2017a_P.th_M[i + 1];

      /* Sum: '<S88>/Sum2' incorporates:
       *  Product: '<S88>/Product8'
       */
      rtb_Sum2_g += rtb_Product8_m[i + 1];
    }

    /* Saturate: '<S81>/Saturation1' */
    if (NACCBraytonCycle2017a_B.Product1 >
        NACCBraytonCycle2017a_P.Saturation1_UpperSat) {
      rtb_Sum2_p5 = NACCBraytonCycle2017a_P.Saturation1_UpperSat;
    } else if (NACCBraytonCycle2017a_B.Product1 <
               NACCBraytonCycle2017a_P.Saturation1_LowerSat) {
      rtb_Sum2_p5 = NACCBraytonCycle2017a_P.Saturation1_LowerSat;
    } else {
      rtb_Sum2_p5 = NACCBraytonCycle2017a_B.Product1;
    }

    /* End of Saturate: '<S81>/Saturation1' */
    NACCBraytonCycle2017a_B.ndot_nc = 1.0 /
      (NACCBraytonCycle2017a_P.Constant3_Value * rtb_Sum2_g) *
      NACCBraytonCycle2017a_DW.Memory1_PreviousInput[2] * rtb_Sum2_p5;
  }

  /* End of MultiPortSwitch: '<S73>/Mode Switch3' */

  /* Outputs for Atomic SubSystem: '<S73>/T-p-State' */
  NACCBraytonCycle2017a_TpState_f();

  /* End of Outputs for SubSystem: '<S73>/T-p-State' */

  /* MultiPortSwitch: '<S73>/Mode Switch2' incorporates:
   *  Constant: '<S73>/Constant4'
   *  Constant: '<S73>/Constant6'
   */
  if ((int32_T)NACCBraytonCycle2017a_P.CompressorPressureFeedback_Mode == 1) {
    rtb_ModeSwitch2 = NACCBraytonCycle2017a_B.p_d;
  } else {
    rtb_ModeSwitch2 = NACCBraytonCycle2017a_P.Constant6_Value;
  }

  /* End of MultiPortSwitch: '<S73>/Mode Switch2' */

  /* Product: '<S73>/Product2' incorporates:
   *  Constant: '<S73>/T-normal'
   */
  rtb_Sum2_p5 = NACCBraytonCycle2017a_B.p_pg /
    NACCBraytonCycle2017a_P.Tnormal_Value;

  /* Math: '<S73>/Math Function'
   *
   * About '<S73>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_Sum2_p5 < 0.0) {
    rtb_Sum2_p5 = -sqrt(fabs(rtb_Sum2_p5));
  } else {
    rtb_Sum2_p5 = sqrt(rtb_Sum2_p5);
  }

  /* End of Math: '<S73>/Math Function' */

  /* Product: '<S73>/Product7' incorporates:
   *  Inport: '<Root>/In4'
   */
  rtb_Product7 = NACCBraytonCycle2017a_U.In4 / rtb_Sum2_p5;

  /* Sum: '<S77>/Sum2' */
  rtb_UnitOffset = -0.0;
  for (i = 0; i < 7; i++) {
    /* Sum: '<S77>/Sum2' incorporates:
     *  Constant: '<S85>/M1'
     *  Product: '<S77>/Product8'
     */
    rtb_UnitOffset += NACCBraytonCycle2017a_B.psi_ip[i] *
      NACCBraytonCycle2017a_P.th_M[i];

    /* Product: '<S77>/Product8' incorporates:
     *  Constant: '<S78>/M1'
     *  Product: '<S73>/Product5'
     */
    rtb_Product8_m[i] = NACCBraytonCycle2017a_B.psi_ip[i] *
      NACCBraytonCycle2017a_P.th_M[i];
  }

  /* Product: '<S77>/Product11' */
  rtb_Sum2_g = NACCBraytonCycle2017a_B.ndot_c0 * rtb_UnitOffset;

  /* Sum: '<S73>/Sum' incorporates:
   *  Sum: '<S100>/Sum'
   *  Sum: '<S105>/Sum2'
   *  Sum: '<S122>/Sum2'
   *  Sum: '<S124>/Sum'
   *  Sum: '<S129>/Sum2'
   *  Sum: '<S142>/Sum2'
   *  Sum: '<S149>/Sum2'
   *  Sum: '<S165>/Sum2'
   *  Sum: '<S179>/Sum2'
   *  Sum: '<S245>/Sum2'
   *  Sum: '<S289>/Sum2'
   *  Sum: '<S322>/Sum2'
   *  Sum: '<S388>/Sum2'
   *  Sum: '<S421>/Sum2'
   *  Sum: '<S465>/Sum2'
   *  Sum: '<S55>/Sum2'
   *  Sum: '<S61>/Sum2'
   *  Sum: '<S69>/Sum2'
   *  Sum: '<S77>/Sum2'
   *  Sum: '<S88>/Sum2'
   *  Sum: '<S98>/Sum2'
   */
  rtb_UnitOffset = rtb_Product8_m[0];
  for (i = 0; i < 6; i++) {
    rtb_UnitOffset += rtb_Product8_m[i + 1];
  }

  /* MultiPortSwitch: '<S75>/Multiport Switch1' incorporates:
   *  Constant: '<S73>/Gas Konstant'
   *  Constant: '<S75>/Constant1'
   *  Constant: '<S84>/Constant'
   *  Product: '<S75>/Divide'
   *  RelationalOperator: '<S84>/Compare'
   */
  if (!(rtb_UnitOffset == NACCBraytonCycle2017a_P.Constant_Value_k)) {
    rtb_UnitOffset = NACCBraytonCycle2017a_P.th_const_R / rtb_UnitOffset;
  } else {
    rtb_UnitOffset = NACCBraytonCycle2017a_P.Divide2_value;
  }

  /* End of MultiPortSwitch: '<S75>/Multiport Switch1' */

  /* Product: '<S73>/Product4' incorporates:
   *  Constant: '<S73>/Refrence R [J//g//K]'
   *  Constant: '<S73>/p-normal'
   *  Product: '<S73>/Product3'
   *  Product: '<S73>/Product6'
   */
  rtb_Product4 = 1.0 / rtb_ModeSwitch2 * NACCBraytonCycle2017a_P.pnormal_Value_l
    * (rtb_Sum2_g * rtb_Sum2_p5) * (rtb_UnitOffset /
    NACCBraytonCycle2017a_P.RefrenceRJgK_Value);

  /* Lookup2D: '<S83>/Lookup Table (2-D)1' */
  /*
   * About '<S83>/Lookup Table (2-D)1':
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_real_T_real_T_real_T( &(rtb_PRatio),
    NACCBraytonCycle2017a_P.CompressorPressureFeedback_Pres, rtb_Product7,
    NACCBraytonCycle2017a_P.CompressorPressureFeedback_RPM, 2U, rtb_Product4,
    NACCBraytonCycle2017a_P.CompressorPressureFeedback_mdot, 3U);

  /* Product: '<S83>/Divide2' incorporates:
   *  Constant: '<S83>/Constant1'
   *  Constant: '<S83>/Constant3'
   *  Constant: '<S90>/Constant'
   *  Constant: '<S91>/Constant'
   *  Constant: '<S92>/Constant'
   *  Constant: '<S93>/Constant'
   *  DataTypeConversion: '<S83>/Data Type Conversion'
   *  DataTypeConversion: '<S83>/Data Type Conversion1'
   *  DataTypeConversion: '<S83>/Data Type Conversion2'
   *  Logic: '<S83>/Logical Operator'
   *  Lookup2D: '<S83>/Lookup Table (2-D)1'
   *  Product: '<S83>/Divide'
   *  Product: '<S83>/Divide1'
   *  RelationalOperator: '<S90>/Compare'
   *  RelationalOperator: '<S91>/Compare'
   *  RelationalOperator: '<S92>/Compare'
   *  RelationalOperator: '<S93>/Compare'
   *  Sum: '<S83>/Add1'
   */
  rtb_UnitOffset = (((real_T)(rtb_Product7 >
    NACCBraytonCycle2017a_P.CompareToConstant1_const) * rtb_Product7 /
                     NACCBraytonCycle2017a_P.Constant1_Value_d2 + (real_T)
                     ((rtb_Product7 >=
                       NACCBraytonCycle2017a_P.CompareToConstant3_const) &&
                      (rtb_Product7 <=
                       NACCBraytonCycle2017a_P.CompareToConstant4_const))) +
                    (real_T)(rtb_Product7 <
    NACCBraytonCycle2017a_P.CompareToConstant2_const) * rtb_Product7 /
                    NACCBraytonCycle2017a_P.Constant3_Value_b) * rtb_PRatio;

  /* Saturate: '<S83>/p_ratio >= 1' */
  if (rtb_UnitOffset > NACCBraytonCycle2017a_P.p_ratio1_UpperSat) {
    rtb_UnitOffset = NACCBraytonCycle2017a_P.p_ratio1_UpperSat;
  } else {
    if (rtb_UnitOffset < NACCBraytonCycle2017a_P.p_ratio1_LowerSat) {
      rtb_UnitOffset = NACCBraytonCycle2017a_P.p_ratio1_LowerSat;
    }
  }

  /* End of Saturate: '<S83>/p_ratio >= 1' */

  /* Product: '<S73>/Product14' */
  NACCBraytonCycle2017a_B.p2 = rtb_ModeSwitch2 * rtb_UnitOffset;

  /* Outputs for Atomic SubSystem: '<S73>/S-p-State' */

  /* S-Function (th_SpState_S): '<S79>/S-Function' */
  /* Block <S79>/S-Function */
  {
    Par param;
    flow inflow;
    flow outflow;
    Trace SpTrace;
    Options SpOpt;

    // Wird in Simulink nur einmal gemacht, hier jedes mal!
    th_SPoly3 *pCp_liq = (th_SPoly3*) EUallocate(sizeof(th_SPoly3));
    nasa *pNASA = (nasa *) EUallocate(sizeof(nasa));
    nasa *pNASA1= (nasa *) EUallocate(sizeof(nasa));
    th_InitParameters(&param);
    th_InitFlow(&inflow);
    th_InitFlow(&outflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_n[7] -
                          pNASA->len * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_n[7] +
                          pNASA->len * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_n[7] +
                          pNASA->len * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_n[7] +
                          pNASA->len * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_n[7] +
                          pNASA->len * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_n[7] +
                          pNASA->len * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_n[7] +
                          pNASA->len * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_a[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_a[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_a[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_a[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_a[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_a[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_a[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_h[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_h[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_h[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_h[7] +
      pCp_liq->len * 2);
    param.nr_species = 7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.ndot_limit = 1.0E-9;
    param.T_cal = &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_mu;
    param.water_index = (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.pCp_liq = pCp_liq;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction_P17_dj;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction_P18_h[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction_P19_c[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);
    SpOpt.derivative_neighbor_factor = 0.02;
    SpOpt.x_conv_limit = 0.0001;
    SpOpt.y_conv_limit = 1.0E-9;
    SpOpt.max_iterations = (int) 100.0;

    /* Map inputs */
    inflow.nr_flows = 1;
    inflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_c0;
    inflow.p_ = &NACCBraytonCycle2017a_B.p2;
    inflow.psi = &NACCBraytonCycle2017a_B.psi_ip[0];
    inflow.Sdot_ = &NACCBraytonCycle2017a_B.Sdot_d;

    /* Map outputs */
    outflow.nr_flows = 1;
    outflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_f;
    outflow.T_ = &NACCBraytonCycle2017a_B.T_d;
    outflow.p_ = &NACCBraytonCycle2017a_B.p_gc;
    outflow.Hdot_ = &NACCBraytonCycle2017a_B.Hdot_e;
    outflow.Sdot_ = &NACCBraytonCycle2017a_B.Sdot_a;
    outflow.Gdot_ = &NACCBraytonCycle2017a_B.Gdot_c;
    outflow.Cpdot_ = &NACCBraytonCycle2017a_B.Cpdot_b;
    outflow.x = &NACCBraytonCycle2017a_B.x_p[0];
    outflow.psi = &NACCBraytonCycle2017a_B.psi_g[0];
    (&NACCBraytonCycle2017a_B.error_codes_do)[0] = th_S_p_State(&inflow,&param,
      &SpOpt,&outflow,&SpTrace);
    (&NACCBraytonCycle2017a_B.iter_j)[0] = SpTrace.iterations;
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }

  /* End of Outputs for SubSystem: '<S73>/S-p-State' */

  /* Lookup2D: '<S73>/Lookup Table (2-D)2' incorporates:
   *  Inport: '<Root>/In4'
   */
  /*
   * About '<S73>/Lookup Table (2-D)2':
   * Input0  Data Type:  Floating Point real_T
   * Input1  Data Type:  Floating Point real_T
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   * Row Data    parameter uses the same data type and scaling as Input0
   * Column Data parameter uses the same data type and scaling as Input1
   * Table Data  parameter uses the same data type and scaling as Output0
   */
  Look2D_real_T_real_T_real_T( &(rtb_eta),
    NACCBraytonCycle2017a_P.CompressorPressureFeedback_effi,
    NACCBraytonCycle2017a_U.In4,
    NACCBraytonCycle2017a_P.CompressorPressureFeedback_RPM, 2U, rtb_Product4,
    NACCBraytonCycle2017a_P.CompressorPressureFeedback_mdot, 3U);

  /* Sum: '<S73>/Sum2' incorporates:
   *  Inport: '<Root>/In4'
   *  Lookup2D: '<S73>/Lookup Table (2-D)2'
   *  Product: '<S73>/Product1'
   *  Sum: '<S73>/Sum1'
   */
  NACCBraytonCycle2017a_B.Sum2 = (NACCBraytonCycle2017a_B.Hdot_e -
    NACCBraytonCycle2017a_B.Hdot_du) / rtb_eta + NACCBraytonCycle2017a_B.Hdot_du;

  /* Outputs for Atomic SubSystem: '<S73>/H-p-State with Heat Exchange' */

  /* S-Function (th_HpStateHeatExchange_S): '<S76>/S-Function' */
  /* Block <S76>/S-Function*/
  {
    Par param;
    flow inflow;
    flow outflow;
    Trace HpTrace;
    Options HpOpt;

    // Wird in Simulink nur einmal gemacht, hier jedes mal!
    th_SPoly3 *pCp_liq = (th_SPoly3*) EUallocate(sizeof(th_SPoly3));
    nasa *pNASA = (nasa *) EUallocate(sizeof(nasa));
    nasa *pNASA1= (nasa *) EUallocate(sizeof(nasa));
    th_InitParameters(&param);
    th_InitFlow(&inflow);
    th_InitFlow(&outflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_p[7] -
                          pNASA->len * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_p[7] +
                          pNASA->len * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_p[7] +
                          pNASA->len * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_p[7] +
                          pNASA->len * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_p[7] +
                          pNASA->len * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_p[7] +
                          pNASA->len * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_p[7] +
                          pNASA->len * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_k[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_k[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_k[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_k[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_k[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_k[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_k[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_d[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_d[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_d[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_d[7] +
      pCp_liq->len * 2);
    param.nr_species = 7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.T_env = 300.0;
    param.k_loss = 0.0;
    param.A_total = 0.0;
    param.ndot_limit = 1.0E-9;
    param.T_cal = &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_p;
    param.water_index = (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.pCp_liq = pCp_liq;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction_P17_p;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction_P18_m[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction_P19_i[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);
    HpOpt.derivative_neighbor_factor = 0.02;
    HpOpt.x_conv_limit = 0.0001;
    HpOpt.y_conv_limit = 1.0E-6;
    HpOpt.max_iterations = (int)100.0;

    /* Map inputs */
    inflow.nr_flows = 1;
    inflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_f;
    inflow.p_ = &NACCBraytonCycle2017a_B.p_gc;
    inflow.psi = &NACCBraytonCycle2017a_B.psi_g[0];
    inflow.Hdot_ = &NACCBraytonCycle2017a_B.Sum2;

    /* Map outputs */
    outflow.nr_flows = 1;
    outflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_l;
    outflow.T_ = &NACCBraytonCycle2017a_B.T_j;
    outflow.p_ = &NACCBraytonCycle2017a_B.p_b;
    outflow.Hdot_ = &NACCBraytonCycle2017a_B.Hdot_jv;
    outflow.Sdot_ = &NACCBraytonCycle2017a_B.Sdot_p;
    outflow.Gdot_ = &NACCBraytonCycle2017a_B.Gdot_l1;
    outflow.Cpdot_ = &NACCBraytonCycle2017a_B.Cpdot_h;
    outflow.x = &NACCBraytonCycle2017a_B.x_ju[0];
    outflow.psi = &NACCBraytonCycle2017a_B.psi_al[0];
    outflow.Qenv = &NACCBraytonCycle2017a_B.Qenv_b;
    (&NACCBraytonCycle2017a_B.error_codes_p)[0] = th_H_p_State_heat_Exchange
      (&inflow,&param,&HpOpt,&outflow,&HpTrace);
    (&NACCBraytonCycle2017a_B.num_iterations_n)[0] = HpTrace.iterations;
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }

  /* End of Outputs for SubSystem: '<S73>/H-p-State with Heat Exchange' */

  /* Sum: '<S179>/Sum2' */
  rtb_UnitOffset = -0.0;
  for (i = 0; i < 7; i++) {
    /* Sum: '<S179>/Sum2' incorporates:
     *  Constant: '<S183>/M1'
     *  Product: '<S179>/Product8'
     */
    rtb_UnitOffset += NACCBraytonCycle2017a_B.psi_al[i] *
      NACCBraytonCycle2017a_P.th_M[i];

    /* Memory: '<S8>/Memory4' */
    NACCBraytonCycle2017a_B.psi[i] =
      NACCBraytonCycle2017a_DW.Memory4_PreviousInput[i];

    /* Product: '<S179>/Product8' incorporates:
     *  Constant: '<S425>/M1'
     *  Product: '<S421>/Product8'
     */
    rtb_Product8_m[i] = NACCBraytonCycle2017a_B.psi[i] *
      NACCBraytonCycle2017a_P.th_M[i];
  }

  /* Outport: '<Root>/Out5' incorporates:
   *  Constant: '<S14>/addition factor1'
   *  Gain: '<S14>/Gain1'
   *  Gain: '<S14>/Gain2'
   *  Product: '<S179>/Product11'
   *  Sum: '<S14>/Add'
   */
  NACCBraytonCycle2017a_Y.Out5 = NACCBraytonCycle2017a_B.ndot_l * rtb_UnitOffset
    * NACCBraytonCycle2017a_P.Gain2_Gain_mh *
    NACCBraytonCycle2017a_P.Gain1_Gain_p +
    NACCBraytonCycle2017a_P.additionfactor1_Value_f;

  /* Outport: '<Root>/Out6' incorporates:
   *  Constant: '<S13>/addition factor1'
   *  Gain: '<S13>/Gain1'
   *  Sum: '<S13>/Add'
   */
  NACCBraytonCycle2017a_Y.Out6 = NACCBraytonCycle2017a_P.Gain1_Gain_k *
    NACCBraytonCycle2017a_B.T_j +
    NACCBraytonCycle2017a_P.additionfactor1_Value_k;

  /* Outport: '<Root>/Out7' incorporates:
   *  Constant: '<S25>/addition factor1'
   *  Gain: '<S25>/Gain1'
   *  Sum: '<S25>/Add'
   */
  NACCBraytonCycle2017a_Y.Out7 = NACCBraytonCycle2017a_P.Gain1_Gain_lj *
    NACCBraytonCycle2017a_B.p_b +
    NACCBraytonCycle2017a_P.additionfactor1_Value_mr;

  /* Outport: '<Root>/Out8' incorporates:
   *  Constant: '<Root>/Constant3'
   *  Constant: '<S34>/addition factor1'
   *  Gain: '<S34>/Gain1'
   *  Product: '<Root>/Product1'
   *  Sum: '<S34>/Add'
   */
  NACCBraytonCycle2017a_Y.Out8 = (NACCBraytonCycle2017a_P.Gain1_Gain_m *
    NACCBraytonCycle2017a_B.Hdot_jv +
    NACCBraytonCycle2017a_P.additionfactor1_Value_d) *
    NACCBraytonCycle2017a_P.Constant3_Value_d;

  /* Sum: '<S421>/Sum2' incorporates:
   *  Sum: '<S100>/Sum'
   *  Sum: '<S105>/Sum2'
   *  Sum: '<S122>/Sum2'
   *  Sum: '<S124>/Sum'
   *  Sum: '<S129>/Sum2'
   *  Sum: '<S142>/Sum2'
   *  Sum: '<S149>/Sum2'
   *  Sum: '<S165>/Sum2'
   *  Sum: '<S179>/Sum2'
   *  Sum: '<S245>/Sum2'
   *  Sum: '<S289>/Sum2'
   *  Sum: '<S322>/Sum2'
   *  Sum: '<S388>/Sum2'
   *  Sum: '<S465>/Sum2'
   *  Sum: '<S55>/Sum2'
   *  Sum: '<S61>/Sum2'
   *  Sum: '<S69>/Sum2'
   *  Sum: '<S73>/Sum'
   *  Sum: '<S77>/Sum2'
   *  Sum: '<S88>/Sum2'
   *  Sum: '<S98>/Sum2'
   */
  rtb_UnitOffset = rtb_Product8_m[0];
  for (i = 0; i < 6; i++) {
    rtb_UnitOffset += rtb_Product8_m[i + 1];
  }

  /* Outport: '<Root>/Out9' incorporates:
   *  Constant: '<S36>/addition factor1'
   *  Gain: '<S36>/Gain1'
   *  Gain: '<S36>/Gain2'
   *  Memory: '<S8>/Memory9'
   *  Product: '<S421>/Product11'
   *  Sum: '<S36>/Add'
   */
  NACCBraytonCycle2017a_Y.Out9 = NACCBraytonCycle2017a_DW.Memory9_PreviousInput *
    rtb_UnitOffset * NACCBraytonCycle2017a_P.Gain2_Gain_g *
    NACCBraytonCycle2017a_P.Gain1_Gain_g2 +
    NACCBraytonCycle2017a_P.additionfactor1_Value_h;

  /* Outport: '<Root>/Out10' incorporates:
   *  Constant: '<S35>/addition factor1'
   *  Gain: '<S35>/Gain1'
   *  Memory: '<S8>/Memory1'
   *  Sum: '<S35>/Add'
   */
  NACCBraytonCycle2017a_Y.Out10 = NACCBraytonCycle2017a_P.Gain1_Gain_lr *
    NACCBraytonCycle2017a_DW.Memory1_PreviousInput_b +
    NACCBraytonCycle2017a_P.additionfactor1_Value_md;

  /* Outport: '<Root>/Out11' incorporates:
   *  Constant: '<S37>/addition factor1'
   *  Gain: '<S37>/Gain1'
   *  Memory: '<S8>/Memory2'
   *  Sum: '<S37>/Add'
   */
  NACCBraytonCycle2017a_Y.Out11 = NACCBraytonCycle2017a_P.Gain1_Gain_mv *
    NACCBraytonCycle2017a_DW.Memory2_PreviousInput +
    NACCBraytonCycle2017a_P.additionfactor1_Value_c;

  /* Outport: '<Root>/Out12' incorporates:
   *  Constant: '<Root>/Constant5'
   *  Constant: '<S38>/addition factor1'
   *  Gain: '<S38>/Gain1'
   *  Memory: '<S8>/Memory3'
   *  Product: '<Root>/Product2'
   *  Sum: '<S38>/Add'
   */
  NACCBraytonCycle2017a_Y.Out12 = (NACCBraytonCycle2017a_P.Gain1_Gain_e *
    NACCBraytonCycle2017a_DW.Memory3_PreviousInput +
    NACCBraytonCycle2017a_P.additionfactor1_Value_b) *
    NACCBraytonCycle2017a_P.Constant5_Value;

  /* Product: '<S100>/Product2' incorporates:
   *  Constant: '<S100>/T-normal'
   *  Memory: '<S8>/Memory1'
   */
  rtb_UnitOffset = NACCBraytonCycle2017a_DW.Memory1_PreviousInput_b /
    NACCBraytonCycle2017a_P.Tnormal_Value_j;

  /* Math: '<S100>/Math Function'
   *
   * About '<S100>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_UnitOffset < 0.0) {
    rtb_UnitOffset = -sqrt(fabs(rtb_UnitOffset));
  } else {
    rtb_UnitOffset = sqrt(rtb_UnitOffset);
  }

  /* End of Math: '<S100>/Math Function' */

  /* Product: '<S100>/Product7' incorporates:
   *  Constant: '<S6>/RPM'
   */
  rtb_ModeSwitch2 = NACCBraytonCycle2017a_P.RPM_Value / rtb_UnitOffset;

  /* Switch: '<S115>/Switch2' incorporates:
   *  Constant: '<S103>/Constant'
   *  Constant: '<S103>/Constant4'
   *  RelationalOperator: '<S115>/LowerRelop1'
   *  RelationalOperator: '<S115>/UpperRelop'
   *  Switch: '<S115>/Switch'
   */
  if (rtb_ModeSwitch2 > NACCBraytonCycle2017a_P.Constant_Value_d) {
    rtb_Switch2 = NACCBraytonCycle2017a_P.Constant_Value_d;
  } else if (rtb_ModeSwitch2 < NACCBraytonCycle2017a_P.Constant4_Value) {
    /* Switch: '<S115>/Switch' incorporates:
     *  Constant: '<S103>/Constant4'
     */
    rtb_Switch2 = NACCBraytonCycle2017a_P.Constant4_Value;
  } else {
    rtb_Switch2 = rtb_ModeSwitch2;
  }

  /* End of Switch: '<S115>/Switch2' */

  /* Switch: '<S108>/Switch2' incorporates:
   *  Constant: '<S100>/Constant1'
   *  Inport: '<Root>/In6'
   *  Memory: '<S8>/Memory2'
   *  RelationalOperator: '<S108>/LowerRelop1'
   *  RelationalOperator: '<S108>/UpperRelop'
   *  Switch: '<S108>/Switch'
   */
  if (NACCBraytonCycle2017a_U.In6 >
      NACCBraytonCycle2017a_DW.Memory2_PreviousInput) {
    NACCBraytonCycle2017a_B.Switch2 =
      NACCBraytonCycle2017a_DW.Memory2_PreviousInput;
  } else if (NACCBraytonCycle2017a_U.In6 <
             NACCBraytonCycle2017a_P.Constant1_Value_g) {
    /* Switch: '<S108>/Switch' incorporates:
     *  Constant: '<S100>/Constant1'
     */
    NACCBraytonCycle2017a_B.Switch2 = NACCBraytonCycle2017a_P.Constant1_Value_g;
  } else {
    NACCBraytonCycle2017a_B.Switch2 = NACCBraytonCycle2017a_U.In6;
  }

  /* End of Switch: '<S108>/Switch2' */

  /* Product: '<S100>/Product8' incorporates:
   *  Memory: '<S8>/Memory2'
   */
  rtb_PR = 1.0 / NACCBraytonCycle2017a_B.Switch2 *
    NACCBraytonCycle2017a_DW.Memory2_PreviousInput;

  /* MultiPortSwitch: '<S100>/Multiport Switch' incorporates:
   *  Constant: '<S100>/T-normal1'
   *  Memory: '<S8>/Memory9'
   *  Product: '<S100>/Product9'
   */
  if ((int32_T)NACCBraytonCycle2017a_P.HPGasTurbine_Mode == 1) {
    NACCBraytonCycle2017a_B.MultiportSwitch =
      NACCBraytonCycle2017a_DW.Memory9_PreviousInput;
  } else {
    /* Lookup2D: '<S103>/Lookup Table (2-D)' */
    /*
     * About '<S103>/Lookup Table (2-D)':
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real_T_real_T_real_T( &(rtb_mdotequivalent_k),
      NACCBraytonCycle2017a_P.LookupTable2D_Table, rtb_Switch2,
      NACCBraytonCycle2017a_P.LookupTable2D_RowIdx, 5U, rtb_PR,
      NACCBraytonCycle2017a_P.LookupTable2D_ColIdx, 20U);

    /* Product: '<S103>/Divide1' incorporates:
     *  Constant: '<S103>/Constant1'
     *  Constant: '<S103>/Constant2'
     *  Constant: '<S111>/Constant'
     *  Constant: '<S112>/Constant'
     *  Constant: '<S113>/Constant'
     *  Constant: '<S114>/Constant'
     *  DataTypeConversion: '<S103>/Data Type Conversion1'
     *  DataTypeConversion: '<S103>/Data Type Conversion2'
     *  DataTypeConversion: '<S103>/Data Type Conversion3'
     *  Logic: '<S103>/Logical Operator2'
     *  Lookup2D: '<S103>/Lookup Table (2-D)'
     *  Product: '<S103>/Divide'
     *  Product: '<S103>/Divide3'
     *  RelationalOperator: '<S111>/Compare'
     *  RelationalOperator: '<S112>/Compare'
     *  RelationalOperator: '<S113>/Compare'
     *  RelationalOperator: '<S114>/Compare'
     *  Sum: '<S103>/Add2'
     */
    rtb_ModeSwitch2 = (((real_T)(rtb_ModeSwitch2 >
      NACCBraytonCycle2017a_P.CompareToConstant1_const_h) * rtb_ModeSwitch2 /
                        NACCBraytonCycle2017a_P.Constant1_Value + (real_T)
                        ((rtb_ModeSwitch2 >=
                          NACCBraytonCycle2017a_P.CompareToConstant5_const) &&
                         (rtb_ModeSwitch2 <=
                          NACCBraytonCycle2017a_P.CompareToConstant6_const))) +
                       (real_T)(rtb_ModeSwitch2 <
      NACCBraytonCycle2017a_P.CompareToConstant2_const_f) * rtb_ModeSwitch2 /
                       NACCBraytonCycle2017a_P.Constant2_Value) *
      rtb_mdotequivalent_k;

    /* Saturate: '<S103>/Saturation' */
    if (rtb_ModeSwitch2 > NACCBraytonCycle2017a_P.Saturation_UpperSat) {
      rtb_ModeSwitch2 = NACCBraytonCycle2017a_P.Saturation_UpperSat;
    } else {
      if (rtb_ModeSwitch2 < NACCBraytonCycle2017a_P.Saturation_LowerSat) {
        rtb_ModeSwitch2 = NACCBraytonCycle2017a_P.Saturation_LowerSat;
      }
    }

    /* End of Saturate: '<S103>/Saturation' */

    /* Product: '<S100>/Product1' incorporates:
     *  Constant: '<S100>/p-normal'
     *  Memory: '<S8>/Memory2'
     *  Product: '<S100>/Product3'
     */
    rtb_UnitOffset = NACCBraytonCycle2017a_DW.Memory2_PreviousInput /
      NACCBraytonCycle2017a_P.pnormal_Value / rtb_UnitOffset * rtb_ModeSwitch2;

    /* Product: '<S100>/Product5' incorporates:
     *  Constant: '<S106>/M1'
     */
    rtb_Product8_m[0] = NACCBraytonCycle2017a_B.psi[0] *
      NACCBraytonCycle2017a_P.th_M[0];

    /* Sum: '<S100>/Sum' */
    rtb_ModeSwitch2 = rtb_Product8_m[0];
    for (i = 0; i < 6; i++) {
      /* Product: '<S100>/Product5' incorporates:
       *  Constant: '<S106>/M1'
       */
      rtb_Product8_m[i + 1] = NACCBraytonCycle2017a_B.psi[i + 1] *
        NACCBraytonCycle2017a_P.th_M[i + 1];

      /* Sum: '<S100>/Sum' incorporates:
       *  Product: '<S100>/Product5'
       */
      rtb_ModeSwitch2 += rtb_Product8_m[i + 1];
    }

    NACCBraytonCycle2017a_B.MultiportSwitch = 1.0 / rtb_ModeSwitch2 *
      rtb_UnitOffset;
  }

  /* End of MultiPortSwitch: '<S100>/Multiport Switch' */

  /* Gain: '<S109>/Gain' */
  NACCBraytonCycle2017a_B.ndot_k = NACCBraytonCycle2017a_P.Gain_Gain_c *
    NACCBraytonCycle2017a_B.MultiportSwitch;

  /* Gain: '<S109>/Gain1' incorporates:
   *  Memory: '<S8>/Memory1'
   */
  NACCBraytonCycle2017a_B.T = NACCBraytonCycle2017a_P.Gain1_Gain_o *
    NACCBraytonCycle2017a_DW.Memory1_PreviousInput_b;

  /* Gain: '<S109>/Gain2' incorporates:
   *  Memory: '<S8>/Memory2'
   */
  NACCBraytonCycle2017a_B.p = NACCBraytonCycle2017a_P.Gain2_Gain_n *
    NACCBraytonCycle2017a_DW.Memory2_PreviousInput;
  for (i = 0; i < 7; i++) {
    /* Gain: '<S109>/Gain3' incorporates:
     *  Memory: '<S8>/Memory8'
     */
    NACCBraytonCycle2017a_B.x[i] = NACCBraytonCycle2017a_P.Gain3_Gain_e *
      NACCBraytonCycle2017a_DW.Memory8_PreviousInput[i];

    /* Gain: '<S109>/Gain4' */
    NACCBraytonCycle2017a_B.psi_e[i] = NACCBraytonCycle2017a_P.Gain4_Gain_g *
      NACCBraytonCycle2017a_B.psi[i];
  }

  /* S-Function (th_TpxState_S): '<S109>/S-Function1' */
  /*Block <S109>/S-Function1*/
  {
    Par param;
    flow pflow;
    int* error;
    nasa *pNASA = (nasa*)EUallocate(sizeof(nasa));
    nasa *pNASA1 = (nasa*)EUallocate(sizeof(nasa));
    th_SPoly3 *pCp_liq = (th_SPoly3*)EUallocate(sizeof(th_SPoly3));
    th_InitParameters(&param);
    th_InitFlow(&pflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_o[7] -
                          pNASA->len * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_o[7] +
                          pNASA->len * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_o[7] +
                          pNASA->len * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_o[7] +
                          pNASA->len * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_o[7] +
                          pNASA->len * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_o[7] +
                          pNASA->len * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_o[7] +
                          pNASA->len * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_h[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_h[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_h[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_h[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_h[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_h[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_h[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_l[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_l[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_l[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_l[7] +
      pCp_liq->len * 2);
    param.nr_species = (int)7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.water_index = (int)0.0;
    param.if97_index = (int)-1.0;
    param.gas_eos_method = (int)1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.pCp_liq = pCp_liq;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction1_P12_m;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P13_h[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P14_n[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);

    /* Map inputs */
    pflow.nr_flows = 1;
    pflow.ndot_ = (double *)&NACCBraytonCycle2017a_B.ndot_k;
    pflow.T_ = (double *)&NACCBraytonCycle2017a_B.T;
    pflow.p_ = (double *)&NACCBraytonCycle2017a_B.p;
    pflow.x = (double *)&NACCBraytonCycle2017a_B.x[0];
    pflow.psi = (double *)&NACCBraytonCycle2017a_B.psi_e[0];

    /* Map outputs */
    pflow.Hdot_ = (double *)&NACCBraytonCycle2017a_B.Hdot;
    pflow.Sdot_ = (double *)&NACCBraytonCycle2017a_B.Sdot;
    pflow.Gdot_ = (double *)&NACCBraytonCycle2017a_B.Gdot;
    pflow.Cpdot_= (double *)&NACCBraytonCycle2017a_B.Cpdot;
    error = (int *) &NACCBraytonCycle2017a_B.SFunction1_o5;
    error[0] = th_T_p_x_State_new (&pflow, &param);
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }

  /* Outputs for Atomic SubSystem: '<S100>/S-p-State' */

  /* S-Function (th_SpState_S): '<S107>/S-Function' */
  /* Block <S107>/S-Function */
  {
    Par param;
    flow inflow;
    flow outflow;
    Trace SpTrace;
    Options SpOpt;

    // Wird in Simulink nur einmal gemacht, hier jedes mal!
    th_SPoly3 *pCp_liq = (th_SPoly3*) EUallocate(sizeof(th_SPoly3));
    nasa *pNASA = (nasa *) EUallocate(sizeof(nasa));
    nasa *pNASA1= (nasa *) EUallocate(sizeof(nasa));
    th_InitParameters(&param);
    th_InitFlow(&inflow);
    th_InitFlow(&outflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_h[7] -
                          pNASA->len * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_h[7] +
                          pNASA->len * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_h[7] +
                          pNASA->len * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_h[7] +
                          pNASA->len * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_h[7] +
                          pNASA->len * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_h[7] +
                          pNASA->len * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_h[7] +
                          pNASA->len * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_m[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_m[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_m[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_m[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_m[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_m[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_m[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_o[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_o[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_o[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_o[7] +
      pCp_liq->len * 2);
    param.nr_species = 7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.ndot_limit = 1.0E-9;
    param.T_cal = &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_f;
    param.water_index = (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.pCp_liq = pCp_liq;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction_P17_o;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction_P18_c[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction_P19_e[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);
    SpOpt.derivative_neighbor_factor = 0.02;
    SpOpt.x_conv_limit = 0.0001;
    SpOpt.y_conv_limit = 1.0E-9;
    SpOpt.max_iterations = (int) 100.0;

    /* Map inputs */
    inflow.nr_flows = 1;
    inflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_k;
    inflow.p_ = &NACCBraytonCycle2017a_B.Switch2;
    inflow.psi = &NACCBraytonCycle2017a_B.psi_e[0];
    inflow.Sdot_ = &NACCBraytonCycle2017a_B.Sdot;

    /* Map outputs */
    outflow.nr_flows = 1;
    outflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_n;
    outflow.T_ = &NACCBraytonCycle2017a_B.T_m;
    outflow.p_ = &NACCBraytonCycle2017a_B.p_n;
    outflow.Hdot_ = &NACCBraytonCycle2017a_B.Hdot_j;
    outflow.Sdot_ = &NACCBraytonCycle2017a_B.Sdot_kk;
    outflow.Gdot_ = &NACCBraytonCycle2017a_B.Gdot_hm;
    outflow.Cpdot_ = &NACCBraytonCycle2017a_B.Cpdot_c;
    outflow.x = &NACCBraytonCycle2017a_B.x_d[0];
    outflow.psi = &NACCBraytonCycle2017a_B.psi_l[0];
    (&NACCBraytonCycle2017a_B.error_codes_o)[0] = th_S_p_State(&inflow,&param,
      &SpOpt,&outflow,&SpTrace);
    (&NACCBraytonCycle2017a_B.iter_n)[0] = SpTrace.iterations;
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }

  /* End of Outputs for SubSystem: '<S100>/S-p-State' */

  /* MultiPortSwitch: '<S100>/Multiport Switch1' incorporates:
   *  Constant: '<S100>/T-normal2'
   *  Lookup: '<S100>/Efficiency Lookup Table'
   *  Product: '<S105>/Product11'
   */
  if ((int32_T)NACCBraytonCycle2017a_P.HPGasTurbine_Mode == 1) {
    /* Product: '<S105>/Product8' incorporates:
     *  Constant: '<S117>/M1'
     */
    rtb_Product8_m[0] = NACCBraytonCycle2017a_B.psi[0] *
      NACCBraytonCycle2017a_P.th_M[0];

    /* Sum: '<S105>/Sum2' */
    rtb_ModeSwitch2 = rtb_Product8_m[0];
    for (i = 0; i < 6; i++) {
      /* Product: '<S105>/Product8' incorporates:
       *  Constant: '<S117>/M1'
       */
      rtb_Product8_m[i + 1] = NACCBraytonCycle2017a_B.psi[i + 1] *
        NACCBraytonCycle2017a_P.th_M[i + 1];

      /* Sum: '<S105>/Sum2' incorporates:
       *  Product: '<S105>/Product8'
       */
      rtb_ModeSwitch2 += rtb_Product8_m[i + 1];
    }

    /* Product: '<S105>/Product11' */
    rtb_Product11_mh = NACCBraytonCycle2017a_B.MultiportSwitch * rtb_ModeSwitch2;

    /* Lookup: '<S100>/Efficiency Lookup Table' incorporates:
     *  Product: '<S105>/Product11'
     */
    /*
     * About '<S100>/Efficiency Lookup Table':
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real_T_real_T( &(rtb_EfficiencyLookupTable_e),
                         NACCBraytonCycle2017a_P.HPGasTurbine_efficiency,
                         rtb_Product11_mh,
                         NACCBraytonCycle2017a_P.HPGasTurbine_mdot2, 4U);
    rtb_UnitOffset = rtb_EfficiencyLookupTable_e;
  } else {
    /* Lookup2D: '<S103>/Lookup Table (2-D)2' */
    /*
     * About '<S103>/Lookup Table (2-D)2':
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real_T_real_T_real_T( &(rtb_u_j),
      NACCBraytonCycle2017a_P.LookupTable2D2_Table, rtb_Switch2,
      NACCBraytonCycle2017a_P.LookupTable2D2_RowIdx, 5U, rtb_PR,
      NACCBraytonCycle2017a_P.LookupTable2D2_ColIdx, 20U);

    /* Saturate: '<S103>/Saturation1' */
    if (rtb_u_j > NACCBraytonCycle2017a_P.Saturation1_UpperSat_k) {
      rtb_UnitOffset = NACCBraytonCycle2017a_P.Saturation1_UpperSat_k;
    } else if (rtb_u_j < NACCBraytonCycle2017a_P.Saturation1_LowerSat_d) {
      rtb_UnitOffset = NACCBraytonCycle2017a_P.Saturation1_LowerSat_d;
    } else {
      rtb_UnitOffset = rtb_u_j;
    }

    /* End of Saturate: '<S103>/Saturation1' */
  }

  /* End of MultiPortSwitch: '<S100>/Multiport Switch1' */

  /* Product: '<S100>/Product10' incorporates:
   *  Gain: '<S100>/Gain1'
   *  Sum: '<S100>/Sum3'
   */
  rtb_UnitOffset = (NACCBraytonCycle2017a_B.Hdot_j -
                    NACCBraytonCycle2017a_B.Hdot) *
    (NACCBraytonCycle2017a_P.Gain1_Gain_h * rtb_UnitOffset);

  /* Saturate: '<S100>/Saturation1' */
  if (rtb_UnitOffset > NACCBraytonCycle2017a_P.Saturation1_UpperSat_d) {
    rtb_UnitOffset = NACCBraytonCycle2017a_P.Saturation1_UpperSat_d;
  } else {
    if (rtb_UnitOffset < NACCBraytonCycle2017a_P.Saturation1_LowerSat_ds) {
      rtb_UnitOffset = NACCBraytonCycle2017a_P.Saturation1_LowerSat_ds;
    }
  }

  /* End of Saturate: '<S100>/Saturation1' */

  /* Sum: '<S100>/Subtract2' */
  NACCBraytonCycle2017a_B.Subtract2 = rtb_UnitOffset +
    NACCBraytonCycle2017a_B.Hdot;

  /* Outputs for Atomic SubSystem: '<S100>/H-p-State with Heat Exchange' */

  /* S-Function (th_HpStateHeatExchange_S): '<S102>/S-Function' */
  /* Block <S102>/S-Function*/
  {
    Par param;
    flow inflow;
    flow outflow;
    Trace HpTrace;
    Options HpOpt;

    // Wird in Simulink nur einmal gemacht, hier jedes mal!
    th_SPoly3 *pCp_liq = (th_SPoly3*) EUallocate(sizeof(th_SPoly3));
    nasa *pNASA = (nasa *) EUallocate(sizeof(nasa));
    nasa *pNASA1= (nasa *) EUallocate(sizeof(nasa));
    th_InitParameters(&param);
    th_InitFlow(&inflow);
    th_InitFlow(&outflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_aj[7] -
                          pNASA->len * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_aj[7] +
                          pNASA->len * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_aj[7] +
                          pNASA->len * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_aj[7] +
                          pNASA->len * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_aj[7] +
                          pNASA->len * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_aj[7] +
                          pNASA->len * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_aj[7] +
                          pNASA->len * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_j[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_j[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_j[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_j[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_j[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_j[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_j[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_jo[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_jo[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_jo[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_jo[7] +
      pCp_liq->len * 2);
    param.nr_species = 7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.T_env = 300.0;
    param.k_loss = 0.0;
    param.A_total = 0.0;
    param.ndot_limit = 1.0E-9;
    param.T_cal = &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_o;
    param.water_index = (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.pCp_liq = pCp_liq;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction_P17_i;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction_P18_p[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction_P19_h[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);
    HpOpt.derivative_neighbor_factor = 0.02;
    HpOpt.x_conv_limit = 0.0001;
    HpOpt.y_conv_limit = 1.0E-6;
    HpOpt.max_iterations = (int)100.0;

    /* Map inputs */
    inflow.nr_flows = 1;
    inflow.ndot_ = &NACCBraytonCycle2017a_B.MultiportSwitch;
    inflow.p_ = &NACCBraytonCycle2017a_B.Switch2;
    inflow.psi = &NACCBraytonCycle2017a_B.psi[0];
    inflow.Hdot_ = &NACCBraytonCycle2017a_B.Subtract2;

    /* Map outputs */
    outflow.nr_flows = 1;
    outflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_nq;
    outflow.T_ = &NACCBraytonCycle2017a_B.T_h;
    outflow.p_ = &NACCBraytonCycle2017a_B.p_g;
    outflow.Hdot_ = &NACCBraytonCycle2017a_B.Hdot_n;
    outflow.Sdot_ = &NACCBraytonCycle2017a_B.Sdot_f;
    outflow.Gdot_ = &NACCBraytonCycle2017a_B.Gdot_l;
    outflow.Cpdot_ = &NACCBraytonCycle2017a_B.Cpdot_a;
    outflow.x = &NACCBraytonCycle2017a_B.x_dg[0];
    outflow.psi = &NACCBraytonCycle2017a_B.psi_i[0];
    outflow.Qenv = &NACCBraytonCycle2017a_B.Qenv_n;
    (&NACCBraytonCycle2017a_B.error_codes_m)[0] = th_H_p_State_heat_Exchange
      (&inflow,&param,&HpOpt,&outflow,&HpTrace);
    (&NACCBraytonCycle2017a_B.num_iterations_d)[0] = HpTrace.iterations;
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }

  /* End of Outputs for SubSystem: '<S100>/H-p-State with Heat Exchange' */

  /* Sum: '<S465>/Sum2' */
  rtb_UnitOffset = -0.0;
  for (i = 0; i < 7; i++) {
    /* Sum: '<S465>/Sum2' incorporates:
     *  Constant: '<S469>/M1'
     *  Product: '<S465>/Product8'
     */
    rtb_UnitOffset += NACCBraytonCycle2017a_B.psi_i[i] *
      NACCBraytonCycle2017a_P.th_M[i];

    /* Product: '<S465>/Product8' incorporates:
     *  Constant: '<S249>/M1'
     *  Memory: '<S7>/Memory4'
     *  Product: '<S245>/Product8'
     */
    rtb_Product8_m[i] = NACCBraytonCycle2017a_DW.Memory4_PreviousInput_p[i] *
      NACCBraytonCycle2017a_P.th_M[i];
  }

  /* Outport: '<Root>/Out13' incorporates:
   *  Constant: '<S40>/addition factor1'
   *  Gain: '<S40>/Gain1'
   *  Gain: '<S40>/Gain2'
   *  Product: '<S465>/Product11'
   *  Sum: '<S40>/Add'
   */
  NACCBraytonCycle2017a_Y.Out13 = NACCBraytonCycle2017a_B.ndot_nq *
    rtb_UnitOffset * NACCBraytonCycle2017a_P.Gain2_Gain_o *
    NACCBraytonCycle2017a_P.Gain1_Gain_n0 +
    NACCBraytonCycle2017a_P.additionfactor1_Value_kh;

  /* Outport: '<Root>/Out14' incorporates:
   *  Constant: '<S39>/addition factor1'
   *  Gain: '<S39>/Gain1'
   *  Sum: '<S39>/Add'
   */
  NACCBraytonCycle2017a_Y.Out14 = NACCBraytonCycle2017a_P.Gain1_Gain_oq *
    NACCBraytonCycle2017a_B.T_h +
    NACCBraytonCycle2017a_P.additionfactor1_Value_ok;

  /* Outport: '<Root>/Out15' incorporates:
   *  Constant: '<S15>/addition factor1'
   *  Gain: '<S15>/Gain1'
   *  Sum: '<S15>/Add'
   */
  NACCBraytonCycle2017a_Y.Out15 = NACCBraytonCycle2017a_P.Gain1_Gain_i *
    NACCBraytonCycle2017a_B.p_g +
    NACCBraytonCycle2017a_P.additionfactor1_Value_f1;

  /* Outport: '<Root>/Out16' incorporates:
   *  Constant: '<Root>/Constant6'
   *  Constant: '<S16>/addition factor1'
   *  Gain: '<S16>/Gain1'
   *  Product: '<Root>/Product3'
   *  Sum: '<S16>/Add'
   */
  NACCBraytonCycle2017a_Y.Out16 = (NACCBraytonCycle2017a_P.Gain1_Gain_k3 *
    NACCBraytonCycle2017a_B.Hdot_n +
    NACCBraytonCycle2017a_P.additionfactor1_Value_kx) *
    NACCBraytonCycle2017a_P.Constant6_Value_l;

  /* Sum: '<S245>/Sum2' incorporates:
   *  Sum: '<S100>/Sum'
   *  Sum: '<S105>/Sum2'
   *  Sum: '<S122>/Sum2'
   *  Sum: '<S124>/Sum'
   *  Sum: '<S129>/Sum2'
   *  Sum: '<S142>/Sum2'
   *  Sum: '<S149>/Sum2'
   *  Sum: '<S165>/Sum2'
   *  Sum: '<S179>/Sum2'
   *  Sum: '<S289>/Sum2'
   *  Sum: '<S322>/Sum2'
   *  Sum: '<S388>/Sum2'
   *  Sum: '<S421>/Sum2'
   *  Sum: '<S465>/Sum2'
   *  Sum: '<S55>/Sum2'
   *  Sum: '<S61>/Sum2'
   *  Sum: '<S69>/Sum2'
   *  Sum: '<S73>/Sum'
   *  Sum: '<S77>/Sum2'
   *  Sum: '<S88>/Sum2'
   *  Sum: '<S98>/Sum2'
   */
  rtb_UnitOffset = rtb_Product8_m[0];
  for (i = 0; i < 6; i++) {
    rtb_UnitOffset += rtb_Product8_m[i + 1];
  }

  /* Outport: '<Root>/Out17' incorporates:
   *  Constant: '<S20>/addition factor1'
   *  Gain: '<S20>/Gain1'
   *  Gain: '<S20>/Gain2'
   *  Memory: '<S7>/Memory9'
   *  Product: '<S245>/Product11'
   *  Sum: '<S20>/Add'
   */
  NACCBraytonCycle2017a_Y.Out17 =
    NACCBraytonCycle2017a_DW.Memory9_PreviousInput_a * rtb_UnitOffset *
    NACCBraytonCycle2017a_P.Gain2_Gain_as *
    NACCBraytonCycle2017a_P.Gain1_Gain_k0 +
    NACCBraytonCycle2017a_P.additionfactor1_Value_b5;

  /* Outport: '<Root>/Out18' incorporates:
   *  Constant: '<S19>/addition factor1'
   *  Gain: '<S19>/Gain1'
   *  Memory: '<S7>/Memory1'
   *  Sum: '<S19>/Add'
   */
  NACCBraytonCycle2017a_Y.Out18 = NACCBraytonCycle2017a_P.Gain1_Gain_ea *
    NACCBraytonCycle2017a_DW.Memory1_PreviousInput_p +
    NACCBraytonCycle2017a_P.additionfactor1_Value_d1;

  /* Outport: '<Root>/Out19' incorporates:
   *  Constant: '<S17>/addition factor1'
   *  Gain: '<S17>/Gain1'
   *  Memory: '<S7>/Memory2'
   *  Sum: '<S17>/Add'
   */
  NACCBraytonCycle2017a_Y.Out19 = NACCBraytonCycle2017a_P.Gain1_Gain_b *
    NACCBraytonCycle2017a_DW.Memory2_PreviousInput_o +
    NACCBraytonCycle2017a_P.additionfactor1_Value_g;

  /* Outport: '<Root>/Out20' incorporates:
   *  Constant: '<Root>/Constant7'
   *  Constant: '<S18>/addition factor1'
   *  Gain: '<S18>/Gain1'
   *  Memory: '<S7>/Memory3'
   *  Product: '<Root>/Product4'
   *  Sum: '<S18>/Add'
   */
  NACCBraytonCycle2017a_Y.Out20 = (NACCBraytonCycle2017a_P.Gain1_Gain_fe *
    NACCBraytonCycle2017a_DW.Memory3_PreviousInput_d +
    NACCBraytonCycle2017a_P.additionfactor1_Value_l) *
    NACCBraytonCycle2017a_P.Constant7_Value;

  /* Bias: '<S155>/UnitOffset' incorporates:
   *  Gain: '<S155>/UnitScale'
   *  Inport: '<Root>/In10'
   */
  rtb_ModeSwitch2 = NACCBraytonCycle2017a_P.UnitScale_Gain_e *
    NACCBraytonCycle2017a_U.In10 + NACCBraytonCycle2017a_P.UnitOffset_Bias_f;

  /* Bias: '<S156>/UnitOffset' incorporates:
   *  Gain: '<S156>/UnitScale'
   *  Inport: '<Root>/In8'
   */
  NACCBraytonCycle2017a_B.UnitOffset_l =
    NACCBraytonCycle2017a_P.UnitScale_Gain_g * NACCBraytonCycle2017a_U.In8 +
    NACCBraytonCycle2017a_P.UnitOffset_Bias_h;

  /* Bias: '<S157>/UnitOffset' incorporates:
   *  Gain: '<S157>/UnitScale'
   *  Inport: '<Root>/In9'
   */
  NACCBraytonCycle2017a_B.UnitOffset_f =
    NACCBraytonCycle2017a_P.UnitScale_Gain_n * NACCBraytonCycle2017a_U.In9 +
    NACCBraytonCycle2017a_P.UnitOffset_Bias_mp;

  /* If: '<S12>/If1' incorporates:
   *  Constant: '<S12>/Constant1'
   *  Constant: '<S12>/psi'
   *  Constant: '<S153>/Sonstiges1'
   */
  if (NACCBraytonCycle2017a_P.Constant1_Value_k == 1.0) {
    /* Outputs for IfAction SubSystem: '<S12>/MolarFlow' incorporates:
     *  ActionPort: '<S152>/Action Port'
     */
    NACCBraytonCycle2017a_MolarFlow(rtb_ModeSwitch2,
      &NACCBraytonCycle2017a_B.ndot_ka);

    /* End of Outputs for SubSystem: '<S12>/MolarFlow' */
  } else if (NACCBraytonCycle2017a_P.Constant1_Value_k == 2.0) {
    /* Outputs for IfAction SubSystem: '<S12>/MassFlow' incorporates:
     *  ActionPort: '<S151>/Action Port'
     */
    NACCBraytonCycle2017a_MassFlow(rtb_ModeSwitch2,
      NACCBraytonCycle2017a_P.NaturalGas_psi, &NACCBraytonCycle2017a_B.ndot_ka,
      (P_MassFlow_NACCBraytonCycle20_T *)&NACCBraytonCycle2017a_P.MassFlow_m);

    /* End of Outputs for SubSystem: '<S12>/MassFlow' */
  } else if (NACCBraytonCycle2017a_P.Constant1_Value_k == 3.0) {
    /* Outputs for IfAction SubSystem: '<S12>/VolumeFlow' incorporates:
     *  ActionPort: '<S158>/Action Port'
     */

    /* Outputs for Atomic SubSystem: '<S158>/T-p-Vapor Fractions' */
    NACCBraytonC_TpVaporFractions_p();

    /* End of Outputs for SubSystem: '<S158>/T-p-Vapor Fractions' */

    /* S-Function (th_Density_S): '<S164>/S-Function' incorporates:
     *  Constant: '<S12>/psi'
     */
    /*Block <S164>/S-Function*/
    {
      Par param;
      flow pflow;
      double calculated_density[3];
      th_InitParameters(&param);
      th_InitFlow(&pflow);
      param.T_cr = NACCBraytonCycle2017a_P.th_T_c;
      param.P_cr = NACCBraytonCycle2017a_P.th_p_c;
      param.T_triple = NACCBraytonCycle2017a_P.th_T_triple;
      param.acentric_factor = NACCBraytonCycle2017a_P.th_omega;
      param.molar_weights = NACCBraytonCycle2017a_P.th_M;
      param.species_density_liquid = NACCBraytonCycle2017a_P.th_rho_liq;
      param.nr_species = 7;
      param.gas_eos_method = (int) 1.0;
      param.if97_index = (int) -1.0;
      param.vm_c = NACCBraytonCycle2017a_P.th_vm_c;
      param.rho_liq_A = NACCBraytonCycle2017a_P.th_rho_liq_A;
      param.rho_liq_B = NACCBraytonCycle2017a_P.th_rho_liq_B;
      param.rho_liq_C = NACCBraytonCycle2017a_P.th_rho_liq_C;
      param.rho_liq_D = NACCBraytonCycle2017a_P.th_rho_liq_D;
      param.E_liq = NACCBraytonCycle2017a_P.th_E_liq;
      param.antoine_A = NACCBraytonCycle2017a_P.th_Antoine_A;
      param.antoine_B = NACCBraytonCycle2017a_P.th_Antoine_B;
      param.antoine_C = NACCBraytonCycle2017a_P.th_Antoine_C;
      param.T_v_ref = NACCBraytonCycle2017a_P.th_T_v_ref;
      param.density_calculation_mode = (int) 0.0;
      pflow.T_ = (double *)&NACCBraytonCycle2017a_B.UnitOffset_l;
      pflow.p_ = (double *)&NACCBraytonCycle2017a_B.UnitOffset_f;
      pflow.x = &NACCBraytonCycle2017a_B.SFunction1_o1_i[0];
      pflow.psi = &NACCBraytonCycle2017a_P.NaturalGas_psi[0];
      pflow.nr_flows = 1;
      (&NACCBraytonCycle2017a_B.SFunction_o4)[0] = th_density(&pflow, &param,
        calculated_density);
      (&NACCBraytonCycle2017a_B.SFunction_o1)[0] = calculated_density[0];
      (&NACCBraytonCycle2017a_B.SFunction_o2)[0] = calculated_density[1];
      (&NACCBraytonCycle2017a_B.SFunction_o3)[0] = calculated_density[2];
    }

    /* Product: '<S165>/Product8' incorporates:
     *  Constant: '<S12>/psi'
     *  Constant: '<S166>/M1'
     */
    rtb_Product8_m[0] = NACCBraytonCycle2017a_P.NaturalGas_psi[0] *
      NACCBraytonCycle2017a_P.th_M[0];

    /* Sum: '<S165>/Sum2' */
    rtb_Sum2_g = rtb_Product8_m[0];
    for (i = 0; i < 6; i++) {
      /* Product: '<S165>/Product8' incorporates:
       *  Constant: '<S12>/psi'
       *  Constant: '<S166>/M1'
       */
      rtb_Product8_m[i + 1] = NACCBraytonCycle2017a_P.NaturalGas_psi[i + 1] *
        NACCBraytonCycle2017a_P.th_M[i + 1];

      /* Sum: '<S165>/Sum2' incorporates:
       *  Product: '<S165>/Product8'
       */
      rtb_Sum2_g += rtb_Product8_m[i + 1];
    }

    /* Product: '<S163>/Product1' incorporates:
     *  Constant: '<S163>/Constant'
     *  Product: '<S163>/Product'
     *  Product: '<S165>/Product11'
     */
    NACCBraytonCycle2017a_B.ndot_ka = rtb_ModeSwitch2 *
      NACCBraytonCycle2017a_B.SFunction_o2 /
      (NACCBraytonCycle2017a_P.Constant_Value_bv * rtb_Sum2_g);

    /* End of Outputs for SubSystem: '<S12>/VolumeFlow' */
  } else {
    if (NACCBraytonCycle2017a_P.Constant1_Value_k == 4.0) {
      /* Outputs for IfAction SubSystem: '<S12>/Reservoir' incorporates:
       *  ActionPort: '<S153>/Action Port'
       */
      NACCBraytonCycle2017a_B.ndot_ka =
        NACCBraytonCycle2017a_P.Sonstiges1_Value_l;

      /* End of Outputs for SubSystem: '<S12>/Reservoir' */
    }
  }

  /* End of If: '<S12>/If1' */

  /* Outputs for Atomic SubSystem: '<S12>/T-p-State' */
  NACCBraytonCycle2017a_TpState_a();

  /* End of Outputs for SubSystem: '<S12>/T-p-State' */

  /* Outputs for Atomic SubSystem: '<S11>/Mixer' */
  /* Gain: '<S147>/Gain2' incorporates:
   *  Memory: '<S7>/Memory2'
   */
  NACCBraytonCycle2017a_B.p_h = NACCBraytonCycle2017a_P.Gain2_Gain_a *
    NACCBraytonCycle2017a_DW.Memory2_PreviousInput_o;

  /* MultiPortSwitch: '<S142>/Mode Switch' incorporates:
   *  Constant: '<S11>/ratio'
   *  Constant: '<S142>/Constan'
   *  Memory: '<S7>/Memory9'
   *  Product: '<S142>/Product5'
   */
  if ((int32_T)NACCBraytonCycle2017a_P.Mixer_Mode == 1) {
    rtb_Sum2_g = NACCBraytonCycle2017a_DW.Memory9_PreviousInput_a;
  } else {
    rtb_Sum2_g = NACCBraytonCycle2017a_B.ndot_nc *
      NACCBraytonCycle2017a_P.ratio_Value;
  }

  /* End of MultiPortSwitch: '<S142>/Mode Switch' */

  /* Sum: '<S142>/Add3' */
  NACCBraytonCycle2017a_B.Add3 = NACCBraytonCycle2017a_B.ndot_nc + rtb_Sum2_g;

  /* Gain: '<S147>/Gain' */
  NACCBraytonCycle2017a_B.ndot_o = NACCBraytonCycle2017a_P.Gain_Gain_o *
    rtb_Sum2_g;

  /* Sum: '<S142>/Sum2' */
  rtb_Sum2_p5 = -0.0;
  for (i = 0; i < 7; i++) {
    /* Gain: '<S147>/Gain4' incorporates:
     *  Memory: '<S7>/Memory4'
     */
    NACCBraytonCycle2017a_B.psi_cv[i] = NACCBraytonCycle2017a_P.Gain4_Gain_o *
      NACCBraytonCycle2017a_DW.Memory4_PreviousInput_p[i];

    /* Sum: '<S142>/Sum1' incorporates:
     *  Product: '<S142>/Product1'
     *  Product: '<S142>/Product8'
     */
    rtb_ModeSwitch2 = NACCBraytonCycle2017a_B.ndot_nc *
      NACCBraytonCycle2017a_B.psi_c[i] + NACCBraytonCycle2017a_B.ndot_o *
      NACCBraytonCycle2017a_B.psi_cv[i];

    /* Sum: '<S142>/Sum2' */
    rtb_Sum2_p5 += rtb_ModeSwitch2;

    /* Sum: '<S142>/Sum1' */
    rtb_Product8_m[i] = rtb_ModeSwitch2;
  }

  /* MultiPortSwitch: '<S142>/Multiport Switch' incorporates:
   *  Constant: '<S142>/Constant'
   */
  if ((int32_T)NACCBraytonCycle2017a_P.Mixer_p_out_method == 1) {
    /* MinMax: '<S142>/MinMax' */
    if ((NACCBraytonCycle2017a_B.p_pg < NACCBraytonCycle2017a_B.p_h) || rtIsNaN
        (NACCBraytonCycle2017a_B.p_h)) {
      rtb_Sum2_g = NACCBraytonCycle2017a_B.p_pg;
    } else {
      rtb_Sum2_g = NACCBraytonCycle2017a_B.p_h;
    }

    /* End of MinMax: '<S142>/MinMax' */
  } else {
    /* Sum: '<S142>/Add1' */
    rtb_ModeSwitch2 = NACCBraytonCycle2017a_B.ndot_nc + rtb_Sum2_g;

    /* MultiPortSwitch: '<S144>/Multiport Switch1' incorporates:
     *  Constant: '<S148>/Constant'
     *  Gain: '<S142>/mean if ndot1 and 2=0'
     *  Product: '<S142>/Product3'
     *  Product: '<S142>/Product4'
     *  Product: '<S144>/Divide'
     *  RelationalOperator: '<S148>/Compare'
     *  Sum: '<S142>/Add'
     *  Sum: '<S142>/Add2'
     */
    if (!(rtb_ModeSwitch2 == NACCBraytonCycle2017a_P.Constant_Value_f)) {
      rtb_Sum2_g = (NACCBraytonCycle2017a_B.p_pg *
                    NACCBraytonCycle2017a_B.ndot_nc +
                    NACCBraytonCycle2017a_B.p_h * rtb_Sum2_g) / rtb_ModeSwitch2;
    } else {
      rtb_Sum2_g = (NACCBraytonCycle2017a_B.p_pg + NACCBraytonCycle2017a_B.p_h) *
        NACCBraytonCycle2017a_P.meanifndot1and20_Gain;
    }

    /* End of MultiPortSwitch: '<S144>/Multiport Switch1' */
  }

  /* End of MultiPortSwitch: '<S142>/Multiport Switch' */

  /* MultiPortSwitch: '<S142>/Multiport Switch1' incorporates:
   *  Constant: '<S143>/Constant'
   *  Gain: '<S142>/mean if ndot1 and 2 are zero'
   *  Product: '<S142>/Product2'
   *  RelationalOperator: '<S143>/Compare'
   *  Sum: '<S142>/Sum5'
   */
  if (!(rtb_Sum2_p5 == NACCBraytonCycle2017a_P.Constant_Value_i)) {
    /* Saturate: '<S142>/Saturation' */
    if (rtb_Sum2_p5 > NACCBraytonCycle2017a_P.Saturation_UpperSat_o) {
      rtb_Sum2_p5 = NACCBraytonCycle2017a_P.Saturation_UpperSat_o;
    } else {
      if (rtb_Sum2_p5 < NACCBraytonCycle2017a_P.Saturation_LowerSat_m) {
        rtb_Sum2_p5 = NACCBraytonCycle2017a_P.Saturation_LowerSat_m;
      }
    }

    /* End of Saturate: '<S142>/Saturation' */
    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.MultiportSwitch1[i] = rtb_Product8_m[i] /
        rtb_Sum2_p5;
    }
  } else {
    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.MultiportSwitch1[i] =
        (NACCBraytonCycle2017a_B.psi_c[i] + NACCBraytonCycle2017a_B.psi_cv[i]) *
        NACCBraytonCycle2017a_P.meanifndot1and2arezero_Gain;
    }
  }

  /* End of MultiPortSwitch: '<S142>/Multiport Switch1' */

  /* Sum: '<S149>/Sum2' */
  rtb_ModeSwitch2 = -0.0;
  for (i = 0; i < 7; i++) {
    /* Sum: '<S149>/Sum2' incorporates:
     *  Constant: '<S150>/M1'
     *  Product: '<S149>/Product8'
     */
    rtb_ModeSwitch2 += NACCBraytonCycle2017a_B.MultiportSwitch1[i] *
      NACCBraytonCycle2017a_P.th_M[i];

    /* Gain: '<S147>/Gain3' incorporates:
     *  Memory: '<S7>/Memory8'
     */
    NACCBraytonCycle2017a_B.x_b[i] = NACCBraytonCycle2017a_P.Gain3_Gain_d *
      NACCBraytonCycle2017a_DW.Memory8_PreviousInput_p[i];
  }

  /* Product: '<S149>/Product11' */
  rtb_ModeSwitch2 *= NACCBraytonCycle2017a_B.Add3;

  /* Sum: '<S146>/Sum' incorporates:
   *  Gain: '<S146>/Gain'
   *  Math: '<S146>/Math Function'
   */
  rtb_Sum2_g -= rtb_ModeSwitch2 * rtb_ModeSwitch2 *
    NACCBraytonCycle2017a_P.Gain_Gain_a;

  /* MinMax: '<S146>/MinMax' incorporates:
   *  Constant: '<S146>/p_downstrem_min'
   */
  if (!((rtb_Sum2_g > NACCBraytonCycle2017a_P.p_downstrem_min_Value) || rtIsNaN
        (NACCBraytonCycle2017a_P.p_downstrem_min_Value))) {
    rtb_Sum2_g = NACCBraytonCycle2017a_P.p_downstrem_min_Value;
  }

  /* End of MinMax: '<S146>/MinMax' */

  /* Saturate: '<S146>/Saturation' */
  if (rtb_Sum2_g > NACCBraytonCycle2017a_P.Saturation_UpperSat_i) {
    NACCBraytonCycle2017a_B.Saturation_f =
      NACCBraytonCycle2017a_P.Saturation_UpperSat_i;
  } else if (rtb_Sum2_g < NACCBraytonCycle2017a_P.Saturation_LowerSat_mf) {
    NACCBraytonCycle2017a_B.Saturation_f =
      NACCBraytonCycle2017a_P.Saturation_LowerSat_mf;
  } else {
    NACCBraytonCycle2017a_B.Saturation_f = rtb_Sum2_g;
  }

  /* End of Saturate: '<S146>/Saturation' */

  /* Gain: '<S147>/Gain1' incorporates:
   *  Memory: '<S7>/Memory1'
   */
  NACCBraytonCycle2017a_B.T_g = NACCBraytonCycle2017a_P.Gain1_Gain_f *
    NACCBraytonCycle2017a_DW.Memory1_PreviousInput_p;

  /* S-Function (th_TpxState_S): '<S147>/S-Function1' */
  /*Block <S147>/S-Function1*/
  {
    Par param;
    flow pflow;
    int* error;
    nasa *pNASA = (nasa*)EUallocate(sizeof(nasa));
    nasa *pNASA1 = (nasa*)EUallocate(sizeof(nasa));
    th_SPoly3 *pCp_liq = (th_SPoly3*)EUallocate(sizeof(th_SPoly3));
    th_InitParameters(&param);
    th_InitFlow(&pflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_p[7] -
                          pNASA->len * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_p[7] +
                          pNASA->len * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_p[7] +
                          pNASA->len * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_p[7] +
                          pNASA->len * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_p[7] +
                          pNASA->len * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_p[7] +
                          pNASA->len * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_p[7] +
                          pNASA->len * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_d[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_d[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_d[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_d[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_d[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_d[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_d[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.TpxState1_Cp_liq[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.TpxState1_Cp_liq[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.TpxState1_Cp_liq[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.TpxState1_Cp_liq[7] +
      pCp_liq->len * 2);
    param.nr_species = (int)7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.water_index = (int)0.0;
    param.if97_index = (int)-1.0;
    param.gas_eos_method = (int)1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.pCp_liq = pCp_liq;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction1_P12_j;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P13_g[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P14_m[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);

    /* Map inputs */
    pflow.nr_flows = 1;
    pflow.ndot_ = (double *)&NACCBraytonCycle2017a_B.ndot_o;
    pflow.T_ = (double *)&NACCBraytonCycle2017a_B.T_g;
    pflow.p_ = (double *)&NACCBraytonCycle2017a_B.p_h;
    pflow.x = (double *)&NACCBraytonCycle2017a_B.x_b[0];
    pflow.psi = (double *)&NACCBraytonCycle2017a_B.psi_cv[0];

    /* Map outputs */
    pflow.Hdot_ = (double *)&NACCBraytonCycle2017a_B.Hdot_h5;
    pflow.Sdot_ = (double *)&NACCBraytonCycle2017a_B.Sdot_l;
    pflow.Gdot_ = (double *)&NACCBraytonCycle2017a_B.Gdot_n;
    pflow.Cpdot_= (double *)&NACCBraytonCycle2017a_B.Cpdot_i;
    error = (int *) &NACCBraytonCycle2017a_B.SFunction1_o5_m;
    error[0] = th_T_p_x_State_new (&pflow, &param);
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }

  /* Sum: '<S142>/Sum6' */
  NACCBraytonCycle2017a_B.Sum6 = NACCBraytonCycle2017a_B.Hdot_c +
    NACCBraytonCycle2017a_B.Hdot_h5;

  /* Outputs for Atomic SubSystem: '<S142>/H-p-State with HeatLoss' */

  /* S-Function (th_HpStateHeatExchange_S): '<S145>/S-Function' */
  /* Block <S145>/S-Function*/
  {
    Par param;
    flow inflow;
    flow outflow;
    Trace HpTrace;
    Options HpOpt;

    // Wird in Simulink nur einmal gemacht, hier jedes mal!
    th_SPoly3 *pCp_liq = (th_SPoly3*) EUallocate(sizeof(th_SPoly3));
    nasa *pNASA = (nasa *) EUallocate(sizeof(nasa));
    nasa *pNASA1= (nasa *) EUallocate(sizeof(nasa));
    th_InitParameters(&param);
    th_InitFlow(&inflow);
    th_InitFlow(&outflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_o[7] -
                          pNASA->len * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_o[7] +
                          pNASA->len * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_o[7] +
                          pNASA->len * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_o[7] +
                          pNASA->len * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_o[7] +
                          pNASA->len * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_o[7] +
                          pNASA->len * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_o[7] +
                          pNASA->len * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_o[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_o[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_o[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_o[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_o[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_o[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_o[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_p[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_p[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_p[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_p[7] +
      pCp_liq->len * 2);
    param.nr_species = 7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.T_env = 300.0;
    param.k_loss = 0.0;
    param.A_total = 0.0;
    param.ndot_limit = 1.0E-9;
    param.T_cal = &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK;
    param.water_index = (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.pCp_liq = pCp_liq;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction_P17_po;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction_P18_f[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction_P19_goy[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);
    HpOpt.derivative_neighbor_factor = 0.02;
    HpOpt.x_conv_limit = 0.0001;
    HpOpt.y_conv_limit = 1.0E-6;
    HpOpt.max_iterations = (int)100.0;

    /* Map inputs */
    inflow.nr_flows = 1;
    inflow.ndot_ = &NACCBraytonCycle2017a_B.Add3;
    inflow.p_ = &NACCBraytonCycle2017a_B.Saturation_f;
    inflow.psi = &NACCBraytonCycle2017a_B.MultiportSwitch1[0];
    inflow.Hdot_ = &NACCBraytonCycle2017a_B.Sum6;

    /* Map outputs */
    outflow.nr_flows = 1;
    outflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_m;
    outflow.T_ = &NACCBraytonCycle2017a_B.T_go;
    outflow.p_ = &NACCBraytonCycle2017a_B.p_p;
    outflow.Hdot_ = &NACCBraytonCycle2017a_B.Hdot_cl;
    outflow.Sdot_ = &NACCBraytonCycle2017a_B.Sdot_ex;
    outflow.Gdot_ = &NACCBraytonCycle2017a_B.Gdot_k;
    outflow.Cpdot_ = &NACCBraytonCycle2017a_B.Cpdot_l;
    outflow.x = &NACCBraytonCycle2017a_B.x_j[0];
    outflow.psi = &NACCBraytonCycle2017a_B.psi_h[0];
    outflow.Qenv = &NACCBraytonCycle2017a_B.Qenv;
    (&NACCBraytonCycle2017a_B.error_codes)[0] = th_H_p_State_heat_Exchange
      (&inflow,&param,&HpOpt,&outflow,&HpTrace);
    (&NACCBraytonCycle2017a_B.num_iterations)[0] = HpTrace.iterations;
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }

  /* End of Outputs for SubSystem: '<S142>/H-p-State with HeatLoss' */

  /* End of Outputs for SubSystem: '<S11>/Mixer' */

  /* Outputs for Atomic SubSystem: '<S57>/calculate  conversion' */

  /* Constant: '<S57>/Reaction Coefficients' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  NACCBrayton_calculateconversion
    (NACCBraytonCycle2017a_P.CombustionChamber_reaction,
     NACCBraytonCycle2017a_B.psi_h, NACCBraytonCycle2017a_P.Constant1_Value_f,
     &NACCBraytonCycle2017a_B.calculateconversion,
     (P_calculateconversion_NACCBra_T *)
     &NACCBraytonCycle2017a_P.calculateconversion);

  /* End of Outputs for SubSystem: '<S57>/calculate  conversion' */

  /* Product: '<S57>/Product' */
  NACCBraytonCycle2017a_B.Product =
    NACCBraytonCycle2017a_B.calculateconversion.Subtract5 *
    NACCBraytonCycle2017a_B.ndot_m;

  /* Product: '<S61>/Product8' incorporates:
   *  Constant: '<S62>/M1'
   */
  rtb_Product8_m[0] = NACCBraytonCycle2017a_B.psi_h[0] *
    NACCBraytonCycle2017a_P.th_M[0];

  /* Sum: '<S61>/Sum2' */
  rtb_UnitOffset = rtb_Product8_m[0];
  for (i = 0; i < 6; i++) {
    /* Product: '<S61>/Product8' incorporates:
     *  Constant: '<S62>/M1'
     */
    rtb_Product8_m[i + 1] = NACCBraytonCycle2017a_B.psi_h[i + 1] *
      NACCBraytonCycle2017a_P.th_M[i + 1];

    /* Sum: '<S61>/Sum2' incorporates:
     *  Product: '<S61>/Product8'
     */
    rtb_UnitOffset += rtb_Product8_m[i + 1];
  }

  /* Product: '<S61>/Product11' */
  rtb_UnitOffset *= NACCBraytonCycle2017a_B.ndot_m;

  /* Sum: '<S59>/Sum' incorporates:
   *  Gain: '<S59>/Gain'
   *  Math: '<S59>/Math Function'
   */
  rtb_UnitOffset = NACCBraytonCycle2017a_B.p_p - rtb_UnitOffset * rtb_UnitOffset
    * NACCBraytonCycle2017a_P.Gain_Gain_m;

  /* MinMax: '<S59>/MinMax' incorporates:
   *  Constant: '<S59>/p_downstrem_min'
   */
  if (!((rtb_UnitOffset > NACCBraytonCycle2017a_P.p_downstrem_min_Value_b) ||
        rtIsNaN(NACCBraytonCycle2017a_P.p_downstrem_min_Value_b))) {
    rtb_UnitOffset = NACCBraytonCycle2017a_P.p_downstrem_min_Value_b;
  }

  /* End of MinMax: '<S59>/MinMax' */

  /* Saturate: '<S59>/Saturation' */
  if (rtb_UnitOffset > NACCBraytonCycle2017a_P.Saturation_UpperSat_a) {
    NACCBraytonCycle2017a_B.Saturation =
      NACCBraytonCycle2017a_P.Saturation_UpperSat_a;
  } else if (rtb_UnitOffset < NACCBraytonCycle2017a_P.Saturation_LowerSat_l) {
    NACCBraytonCycle2017a_B.Saturation =
      NACCBraytonCycle2017a_P.Saturation_LowerSat_l;
  } else {
    NACCBraytonCycle2017a_B.Saturation = rtb_UnitOffset;
  }

  /* End of Saturate: '<S59>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S57>/H-p-State with Heat Exchange' */

  /* S-Function (th_HpStateHeatExchange_S): '<S58>/S-Function' */
  /* Block <S58>/S-Function*/
  {
    Par param;
    flow inflow;
    flow outflow;
    Trace HpTrace;
    Options HpOpt;

    // Wird in Simulink nur einmal gemacht, hier jedes mal!
    th_SPoly3 *pCp_liq = (th_SPoly3*) EUallocate(sizeof(th_SPoly3));
    nasa *pNASA = (nasa *) EUallocate(sizeof(nasa));
    nasa *pNASA1= (nasa *) EUallocate(sizeof(nasa));
    th_InitParameters(&param);
    th_InitFlow(&inflow);
    th_InitFlow(&outflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4[7] - pNASA->len *
                          1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4[7] + pNASA->len *
                          0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4[7] + pNASA->len *
                          1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4[7] + pNASA->len *
                          2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4[7] + pNASA->len *
                          3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4[7] + pNASA->len *
                          4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4[7] + pNASA->len *
                          5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12[7] +
      pCp_liq->len * 2);
    param.nr_species = 7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.T_env = 288.15;
    param.k_loss = 0.0;
    param.A_total = 10.0;
    param.ndot_limit = 1.0E-9;
    param.T_cal = &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_j;
    param.water_index = (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.pCp_liq = pCp_liq;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction_P17_d;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction_P18[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction_P19[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);
    HpOpt.derivative_neighbor_factor = 0.02;
    HpOpt.x_conv_limit = 0.0001;
    HpOpt.y_conv_limit = 1.0E-6;
    HpOpt.max_iterations = (int)100.0;

    /* Map inputs */
    inflow.nr_flows = 1;
    inflow.ndot_ = &NACCBraytonCycle2017a_B.Product;
    inflow.p_ = &NACCBraytonCycle2017a_B.Saturation;
    inflow.psi = &NACCBraytonCycle2017a_B.calculateconversion.Product6[0];
    inflow.Hdot_ = &NACCBraytonCycle2017a_B.Hdot_cl;

    /* Map outputs */
    outflow.nr_flows = 1;
    outflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_f2;
    outflow.T_ = &NACCBraytonCycle2017a_B.T_h3;
    outflow.p_ = &NACCBraytonCycle2017a_B.p_nt;
    outflow.Hdot_ = &NACCBraytonCycle2017a_B.Hdot_ig;
    outflow.Sdot_ = &NACCBraytonCycle2017a_B.Sdot_fv;
    outflow.Gdot_ = &NACCBraytonCycle2017a_B.Gdot_mk;
    outflow.Cpdot_ = &NACCBraytonCycle2017a_B.Cpdot_eg;
    outflow.x = &NACCBraytonCycle2017a_B.x_il[0];
    outflow.psi = &NACCBraytonCycle2017a_B.psi_j[0];
    outflow.Qenv = &NACCBraytonCycle2017a_B.Qenv_f;
    (&NACCBraytonCycle2017a_B.error_codes_or)[0] = th_H_p_State_heat_Exchange
      (&inflow,&param,&HpOpt,&outflow,&HpTrace);
    (&NACCBraytonCycle2017a_B.num_iterations_h)[0] = HpTrace.iterations;
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }

  /* End of Outputs for SubSystem: '<S57>/H-p-State with Heat Exchange' */

  /* Outputs for Atomic SubSystem: '<S65>/calculate  conversion' */

  /* Constant: '<S65>/Reaction Coefficients' incorporates:
   *  Constant: '<Root>/Constant4'
   */
  NACCBrayton_calculateconversion
    (NACCBraytonCycle2017a_P.CombustionChamber1_reaction,
     NACCBraytonCycle2017a_B.psi_j, NACCBraytonCycle2017a_P.Constant4_Value_e,
     &NACCBraytonCycle2017a_B.calculateconversion_n,
     (P_calculateconversion_NACCBra_T *)
     &NACCBraytonCycle2017a_P.calculateconversion_n);

  /* End of Outputs for SubSystem: '<S65>/calculate  conversion' */

  /* Product: '<S65>/Product' */
  NACCBraytonCycle2017a_B.Product_a =
    NACCBraytonCycle2017a_B.calculateconversion_n.Subtract5 *
    NACCBraytonCycle2017a_B.ndot_f2;

  /* Product: '<S69>/Product8' incorporates:
   *  Constant: '<S70>/M1'
   */
  rtb_Product8_m[0] = NACCBraytonCycle2017a_B.psi_j[0] *
    NACCBraytonCycle2017a_P.th_M[0];

  /* Sum: '<S69>/Sum2' */
  rtb_UnitOffset = rtb_Product8_m[0];
  for (i = 0; i < 6; i++) {
    /* Product: '<S69>/Product8' incorporates:
     *  Constant: '<S70>/M1'
     */
    rtb_Product8_m[i + 1] = NACCBraytonCycle2017a_B.psi_j[i + 1] *
      NACCBraytonCycle2017a_P.th_M[i + 1];

    /* Sum: '<S69>/Sum2' incorporates:
     *  Product: '<S69>/Product8'
     */
    rtb_UnitOffset += rtb_Product8_m[i + 1];
  }

  /* Product: '<S69>/Product11' */
  rtb_UnitOffset *= NACCBraytonCycle2017a_B.ndot_f2;

  /* Sum: '<S67>/Sum' incorporates:
   *  Gain: '<S67>/Gain'
   *  Math: '<S67>/Math Function'
   */
  rtb_UnitOffset = NACCBraytonCycle2017a_B.p_nt - rtb_UnitOffset *
    rtb_UnitOffset * NACCBraytonCycle2017a_P.Gain_Gain_g;

  /* MinMax: '<S67>/MinMax' incorporates:
   *  Constant: '<S67>/p_downstrem_min'
   */
  if (!((rtb_UnitOffset > NACCBraytonCycle2017a_P.p_downstrem_min_Value_p) ||
        rtIsNaN(NACCBraytonCycle2017a_P.p_downstrem_min_Value_p))) {
    rtb_UnitOffset = NACCBraytonCycle2017a_P.p_downstrem_min_Value_p;
  }

  /* End of MinMax: '<S67>/MinMax' */

  /* Saturate: '<S67>/Saturation' */
  if (rtb_UnitOffset > NACCBraytonCycle2017a_P.Saturation_UpperSat_j) {
    NACCBraytonCycle2017a_B.Saturation_l =
      NACCBraytonCycle2017a_P.Saturation_UpperSat_j;
  } else if (rtb_UnitOffset < NACCBraytonCycle2017a_P.Saturation_LowerSat_kc) {
    NACCBraytonCycle2017a_B.Saturation_l =
      NACCBraytonCycle2017a_P.Saturation_LowerSat_kc;
  } else {
    NACCBraytonCycle2017a_B.Saturation_l = rtb_UnitOffset;
  }

  /* End of Saturate: '<S67>/Saturation' */

  /* Outputs for Atomic SubSystem: '<S65>/H-p-State with Heat Exchange' */

  /* S-Function (th_HpStateHeatExchange_S): '<S66>/S-Function' */
  /* Block <S66>/S-Function*/
  {
    Par param;
    flow inflow;
    flow outflow;
    Trace HpTrace;
    Options HpOpt;

    // Wird in Simulink nur einmal gemacht, hier jedes mal!
    th_SPoly3 *pCp_liq = (th_SPoly3*) EUallocate(sizeof(th_SPoly3));
    nasa *pNASA = (nasa *) EUallocate(sizeof(nasa));
    nasa *pNASA1= (nasa *) EUallocate(sizeof(nasa));
    th_InitParameters(&param);
    th_InitFlow(&inflow);
    th_InitFlow(&outflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_e[7] -
                          pNASA->len * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_e[7] +
                          pNASA->len * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_e[7] +
                          pNASA->len * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_e[7] +
                          pNASA->len * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_e[7] +
                          pNASA->len * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_e[7] +
                          pNASA->len * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_e[7] +
                          pNASA->len * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_g[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_g[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_g[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_g[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_g[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_g[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_g[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_j[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_j[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_j[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_j[7] +
      pCp_liq->len * 2);
    param.nr_species = 7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.T_env = 288.15;
    param.k_loss = 45.0;
    param.A_total = 10.0;
    param.ndot_limit = 1.0E-9;
    param.T_cal = &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_l;
    param.water_index = (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.pCp_liq = pCp_liq;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction_P17_j;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction_P18_o[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction_P19_b[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);
    HpOpt.derivative_neighbor_factor = 0.02;
    HpOpt.x_conv_limit = 0.0001;
    HpOpt.y_conv_limit = 1.0E-6;
    HpOpt.max_iterations = (int)100.0;

    /* Map inputs */
    inflow.nr_flows = 1;
    inflow.ndot_ = &NACCBraytonCycle2017a_B.Product_a;
    inflow.p_ = &NACCBraytonCycle2017a_B.Saturation_l;
    inflow.psi = &NACCBraytonCycle2017a_B.calculateconversion_n.Product6[0];
    inflow.Hdot_ = &NACCBraytonCycle2017a_B.Hdot_ig;

    /* Map outputs */
    outflow.nr_flows = 1;
    outflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_oo;
    outflow.T_ = &NACCBraytonCycle2017a_B.T_mo;
    outflow.p_ = &NACCBraytonCycle2017a_B.p_k;
    outflow.Hdot_ = &NACCBraytonCycle2017a_B.Hdot_jo;
    outflow.Sdot_ = &NACCBraytonCycle2017a_B.Sdot_o;
    outflow.Gdot_ = &NACCBraytonCycle2017a_B.Gdot_g;
    outflow.Cpdot_ = &NACCBraytonCycle2017a_B.Cpdot_az;
    outflow.x = &NACCBraytonCycle2017a_B.x_i[0];
    outflow.psi = &NACCBraytonCycle2017a_B.psi_p[0];
    outflow.Qenv = &NACCBraytonCycle2017a_B.Qenv_pj;
    (&NACCBraytonCycle2017a_B.error_codes_h)[0] = th_H_p_State_heat_Exchange
      (&inflow,&param,&HpOpt,&outflow,&HpTrace);
    (&NACCBraytonCycle2017a_B.num_iterations_fx)[0] = HpTrace.iterations;
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }

  /* End of Outputs for SubSystem: '<S65>/H-p-State with Heat Exchange' */

  /* Product: '<S289>/Product8' incorporates:
   *  Constant: '<S293>/M1'
   */
  rtb_Product8_m[0] = NACCBraytonCycle2017a_B.psi_p[0] *
    NACCBraytonCycle2017a_P.th_M[0];

  /* Sum: '<S289>/Sum2' */
  rtb_UnitOffset = rtb_Product8_m[0];
  for (i = 0; i < 6; i++) {
    /* Product: '<S289>/Product8' incorporates:
     *  Constant: '<S293>/M1'
     */
    rtb_Product8_m[i + 1] = NACCBraytonCycle2017a_B.psi_p[i + 1] *
      NACCBraytonCycle2017a_P.th_M[i + 1];

    /* Sum: '<S289>/Sum2' incorporates:
     *  Product: '<S289>/Product8'
     */
    rtb_UnitOffset += rtb_Product8_m[i + 1];
  }

  /* Outport: '<Root>/Out21' incorporates:
   *  Constant: '<S24>/addition factor1'
   *  Gain: '<S24>/Gain1'
   *  Gain: '<S24>/Gain2'
   *  Product: '<S289>/Product11'
   *  Sum: '<S24>/Add'
   */
  NACCBraytonCycle2017a_Y.Out21 = NACCBraytonCycle2017a_B.ndot_oo *
    rtb_UnitOffset * NACCBraytonCycle2017a_P.Gain2_Gain_e *
    NACCBraytonCycle2017a_P.Gain1_Gain_nb +
    NACCBraytonCycle2017a_P.additionfactor1_Value_fu;

  /* Outport: '<Root>/Out22' incorporates:
   *  Constant: '<S23>/addition factor1'
   *  Gain: '<S23>/Gain1'
   *  Sum: '<S23>/Add'
   */
  NACCBraytonCycle2017a_Y.Out22 = NACCBraytonCycle2017a_P.Gain1_Gain_ck *
    NACCBraytonCycle2017a_B.T_mo +
    NACCBraytonCycle2017a_P.additionfactor1_Value_e;

  /* Outport: '<Root>/Out23' incorporates:
   *  Constant: '<S21>/addition factor1'
   *  Gain: '<S21>/Gain1'
   *  Sum: '<S21>/Add'
   */
  NACCBraytonCycle2017a_Y.Out23 = NACCBraytonCycle2017a_P.Gain1_Gain_is *
    NACCBraytonCycle2017a_B.p_k +
    NACCBraytonCycle2017a_P.additionfactor1_Value_hp;

  /* Outport: '<Root>/Out24' incorporates:
   *  Constant: '<Root>/Constant8'
   *  Constant: '<S22>/addition factor1'
   *  Gain: '<S22>/Gain1'
   *  Product: '<Root>/Product5'
   *  Sum: '<S22>/Add'
   */
  NACCBraytonCycle2017a_Y.Out24 = (NACCBraytonCycle2017a_P.Gain1_Gain_j *
    NACCBraytonCycle2017a_B.Hdot_jo +
    NACCBraytonCycle2017a_P.additionfactor1_Value_dv) *
    NACCBraytonCycle2017a_P.Constant8_Value;

  /* Product: '<S124>/Product2' incorporates:
   *  Constant: '<S124>/T-normal'
   */
  rtb_UnitOffset = NACCBraytonCycle2017a_B.T_mo /
    NACCBraytonCycle2017a_P.Tnormal_Value_n;

  /* Math: '<S124>/Math Function'
   *
   * About '<S124>/Math Function':
   *  Operator: sqrt
   */
  if (rtb_UnitOffset < 0.0) {
    rtb_ModeSwitch2 = -sqrt(fabs(rtb_UnitOffset));
  } else {
    rtb_ModeSwitch2 = sqrt(rtb_UnitOffset);
  }

  /* End of Math: '<S124>/Math Function' */

  /* Product: '<S124>/Product7' incorporates:
   *  Constant: '<S10>/RPM'
   */
  rtb_Sum2_p5 = NACCBraytonCycle2017a_P.RPM_Value_f / rtb_ModeSwitch2;

  /* Switch: '<S139>/Switch2' incorporates:
   *  Constant: '<S127>/Constant'
   *  Constant: '<S127>/Constant4'
   *  RelationalOperator: '<S139>/LowerRelop1'
   *  RelationalOperator: '<S139>/UpperRelop'
   *  Switch: '<S139>/Switch'
   */
  if (rtb_Sum2_p5 > NACCBraytonCycle2017a_P.Constant_Value_j) {
    rtb_Switch2_f = NACCBraytonCycle2017a_P.Constant_Value_j;
  } else if (rtb_Sum2_p5 < NACCBraytonCycle2017a_P.Constant4_Value_d) {
    /* Switch: '<S139>/Switch' incorporates:
     *  Constant: '<S127>/Constant4'
     */
    rtb_Switch2_f = NACCBraytonCycle2017a_P.Constant4_Value_d;
  } else {
    rtb_Switch2_f = rtb_Sum2_p5;
  }

  /* End of Switch: '<S139>/Switch2' */

  /* Switch: '<S132>/Switch2' incorporates:
   *  Constant: '<S124>/Constant1'
   *  Inport: '<Root>/In11'
   *  RelationalOperator: '<S132>/LowerRelop1'
   *  RelationalOperator: '<S132>/UpperRelop'
   *  Switch: '<S132>/Switch'
   */
  if (NACCBraytonCycle2017a_U.In11 > NACCBraytonCycle2017a_B.p_k) {
    NACCBraytonCycle2017a_B.Switch2_n = NACCBraytonCycle2017a_B.p_k;
  } else if (NACCBraytonCycle2017a_U.In11 <
             NACCBraytonCycle2017a_P.Constant1_Value_e) {
    /* Switch: '<S132>/Switch' incorporates:
     *  Constant: '<S124>/Constant1'
     */
    NACCBraytonCycle2017a_B.Switch2_n =
      NACCBraytonCycle2017a_P.Constant1_Value_e;
  } else {
    NACCBraytonCycle2017a_B.Switch2_n = NACCBraytonCycle2017a_U.In11;
  }

  /* End of Switch: '<S132>/Switch2' */

  /* Product: '<S124>/Product8' */
  rtb_PR_l = 1.0 / NACCBraytonCycle2017a_B.Switch2_n *
    NACCBraytonCycle2017a_B.p_k;

  /* MultiPortSwitch: '<S124>/Multiport Switch' incorporates:
   *  Constant: '<S124>/T-normal1'
   *  Product: '<S124>/Product9'
   */
  if ((int32_T)NACCBraytonCycle2017a_P.LPGasTurbine_Mode == 1) {
    NACCBraytonCycle2017a_B.MultiportSwitch_h = NACCBraytonCycle2017a_B.ndot_oo;
  } else {
    /* Lookup2D: '<S127>/Lookup Table (2-D)' */
    /*
     * About '<S127>/Lookup Table (2-D)':
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real_T_real_T_real_T( &(rtb_mdotequivalent),
      NACCBraytonCycle2017a_P.LookupTable2D_Table_l, rtb_Switch2_f,
      NACCBraytonCycle2017a_P.LookupTable2D_RowIdx_i, 5U, rtb_PR_l,
      NACCBraytonCycle2017a_P.LookupTable2D_ColIdx_h, 20U);

    /* Product: '<S127>/Divide1' incorporates:
     *  Constant: '<S127>/Constant1'
     *  Constant: '<S127>/Constant2'
     *  Constant: '<S135>/Constant'
     *  Constant: '<S136>/Constant'
     *  Constant: '<S137>/Constant'
     *  Constant: '<S138>/Constant'
     *  DataTypeConversion: '<S127>/Data Type Conversion1'
     *  DataTypeConversion: '<S127>/Data Type Conversion2'
     *  DataTypeConversion: '<S127>/Data Type Conversion3'
     *  Logic: '<S127>/Logical Operator2'
     *  Lookup2D: '<S127>/Lookup Table (2-D)'
     *  Product: '<S127>/Divide'
     *  Product: '<S127>/Divide3'
     *  RelationalOperator: '<S135>/Compare'
     *  RelationalOperator: '<S136>/Compare'
     *  RelationalOperator: '<S137>/Compare'
     *  RelationalOperator: '<S138>/Compare'
     *  Sum: '<S127>/Add2'
     */
    rtb_Sum2_p5 = (((real_T)(rtb_Sum2_p5 >
      NACCBraytonCycle2017a_P.CompareToConstant1_const_k) * rtb_Sum2_p5 /
                    NACCBraytonCycle2017a_P.Constant1_Value_h + (real_T)
                    ((rtb_Sum2_p5 >=
                      NACCBraytonCycle2017a_P.CompareToConstant5_const_n) &&
                     (rtb_Sum2_p5 <=
                      NACCBraytonCycle2017a_P.CompareToConstant6_const_i))) +
                   (real_T)(rtb_Sum2_p5 <
      NACCBraytonCycle2017a_P.CompareToConstant2_const_d) * rtb_Sum2_p5 /
                   NACCBraytonCycle2017a_P.Constant2_Value_e) *
      rtb_mdotequivalent;

    /* Saturate: '<S127>/Saturation' */
    if (rtb_Sum2_p5 > NACCBraytonCycle2017a_P.Saturation_UpperSat_e) {
      rtb_Sum2_p5 = NACCBraytonCycle2017a_P.Saturation_UpperSat_e;
    } else {
      if (rtb_Sum2_p5 < NACCBraytonCycle2017a_P.Saturation_LowerSat_i) {
        rtb_Sum2_p5 = NACCBraytonCycle2017a_P.Saturation_LowerSat_i;
      }
    }

    /* End of Saturate: '<S127>/Saturation' */

    /* Product: '<S124>/Product1' incorporates:
     *  Constant: '<S124>/p-normal'
     *  Product: '<S124>/Product3'
     */
    rtb_ModeSwitch2 = NACCBraytonCycle2017a_B.p_k /
      NACCBraytonCycle2017a_P.pnormal_Value_k / rtb_ModeSwitch2 * rtb_Sum2_p5;

    /* Product: '<S124>/Product5' incorporates:
     *  Constant: '<S130>/M1'
     */
    rtb_Product8_m[0] = NACCBraytonCycle2017a_B.psi_p[0] *
      NACCBraytonCycle2017a_P.th_M[0];

    /* Sum: '<S124>/Sum' */
    rtb_Sum2_p5 = rtb_Product8_m[0];
    for (i = 0; i < 6; i++) {
      /* Product: '<S124>/Product5' incorporates:
       *  Constant: '<S130>/M1'
       */
      rtb_Product8_m[i + 1] = NACCBraytonCycle2017a_B.psi_p[i + 1] *
        NACCBraytonCycle2017a_P.th_M[i + 1];

      /* Sum: '<S124>/Sum' incorporates:
       *  Product: '<S124>/Product5'
       */
      rtb_Sum2_p5 += rtb_Product8_m[i + 1];
    }

    NACCBraytonCycle2017a_B.MultiportSwitch_h = 1.0 / rtb_Sum2_p5 *
      rtb_ModeSwitch2;
  }

  /* End of MultiPortSwitch: '<S124>/Multiport Switch' */

  /* Gain: '<S133>/Gain' */
  NACCBraytonCycle2017a_B.ndot_i = NACCBraytonCycle2017a_P.Gain_Gain_l *
    NACCBraytonCycle2017a_B.MultiportSwitch_h;

  /* Gain: '<S133>/Gain1' */
  NACCBraytonCycle2017a_B.T_e = NACCBraytonCycle2017a_P.Gain1_Gain_d *
    NACCBraytonCycle2017a_B.T_mo;

  /* Gain: '<S133>/Gain2' */
  NACCBraytonCycle2017a_B.p_c = NACCBraytonCycle2017a_P.Gain2_Gain_oa *
    NACCBraytonCycle2017a_B.p_k;
  for (i = 0; i < 7; i++) {
    /* Gain: '<S133>/Gain3' */
    NACCBraytonCycle2017a_B.x_h[i] = NACCBraytonCycle2017a_P.Gain3_Gain_p *
      NACCBraytonCycle2017a_B.x_i[i];

    /* Gain: '<S133>/Gain4' */
    NACCBraytonCycle2017a_B.psi_o[i] = NACCBraytonCycle2017a_P.Gain4_Gain_l *
      NACCBraytonCycle2017a_B.psi_p[i];
  }

  /* S-Function (th_TpxState_S): '<S133>/S-Function1' */
  /*Block <S133>/S-Function1*/
  {
    Par param;
    flow pflow;
    int* error;
    nasa *pNASA = (nasa*)EUallocate(sizeof(nasa));
    nasa *pNASA1 = (nasa*)EUallocate(sizeof(nasa));
    th_SPoly3 *pCp_liq = (th_SPoly3*)EUallocate(sizeof(th_SPoly3));
    th_InitParameters(&param);
    th_InitFlow(&pflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_h[7] -
                          pNASA->len * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_h[7] +
                          pNASA->len * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_h[7] +
                          pNASA->len * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_h[7] +
                          pNASA->len * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_h[7] +
                          pNASA->len * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_h[7] +
                          pNASA->len * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P1_h[7] +
                          pNASA->len * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_m[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_m[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_m[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_m[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_m[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_m[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P2_m[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_k[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_k[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_k[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.TpxState_Cp_liq_k[7] +
      pCp_liq->len * 2);
    param.nr_species = (int)7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.water_index = (int)0.0;
    param.if97_index = (int)-1.0;
    param.gas_eos_method = (int)1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.pCp_liq = pCp_liq;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction1_P12_mf;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P13_br[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction1_P14_g[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);

    /* Map inputs */
    pflow.nr_flows = 1;
    pflow.ndot_ = (double *)&NACCBraytonCycle2017a_B.ndot_i;
    pflow.T_ = (double *)&NACCBraytonCycle2017a_B.T_e;
    pflow.p_ = (double *)&NACCBraytonCycle2017a_B.p_c;
    pflow.x = (double *)&NACCBraytonCycle2017a_B.x_h[0];
    pflow.psi = (double *)&NACCBraytonCycle2017a_B.psi_o[0];

    /* Map outputs */
    pflow.Hdot_ = (double *)&NACCBraytonCycle2017a_B.Hdot_h;
    pflow.Sdot_ = (double *)&NACCBraytonCycle2017a_B.Sdot_e;
    pflow.Gdot_ = (double *)&NACCBraytonCycle2017a_B.Gdot_h;
    pflow.Cpdot_= (double *)&NACCBraytonCycle2017a_B.Cpdot_d;
    error = (int *) &NACCBraytonCycle2017a_B.SFunction1_o5_j;
    error[0] = th_T_p_x_State_new (&pflow, &param);
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }

  /* Outputs for Atomic SubSystem: '<S124>/S-p-State' */

  /* S-Function (th_SpState_S): '<S131>/S-Function' */
  /* Block <S131>/S-Function */
  {
    Par param;
    flow inflow;
    flow outflow;
    Trace SpTrace;
    Options SpOpt;

    // Wird in Simulink nur einmal gemacht, hier jedes mal!
    th_SPoly3 *pCp_liq = (th_SPoly3*) EUallocate(sizeof(th_SPoly3));
    nasa *pNASA = (nasa *) EUallocate(sizeof(nasa));
    nasa *pNASA1= (nasa *) EUallocate(sizeof(nasa));
    th_InitParameters(&param);
    th_InitFlow(&inflow);
    th_InitFlow(&outflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_g[7] -
                          pNASA->len * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_g[7] +
                          pNASA->len * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_g[7] +
                          pNASA->len * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_g[7] +
                          pNASA->len * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_g[7] +
                          pNASA->len * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_g[7] +
                          pNASA->len * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_g[7] +
                          pNASA->len * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_n[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_n[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_n[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_n[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_n[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_n[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_n[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_i[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_i[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_i[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_i[7] +
      pCp_liq->len * 2);
    param.nr_species = 7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.ndot_limit = 1.0E-9;
    param.T_cal = &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_m;
    param.water_index = (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.pCp_liq = pCp_liq;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction_P17_k;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction_P18_n[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction_P19_j[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);
    SpOpt.derivative_neighbor_factor = 0.02;
    SpOpt.x_conv_limit = 0.0001;
    SpOpt.y_conv_limit = 1.0E-9;
    SpOpt.max_iterations = (int) 100.0;

    /* Map inputs */
    inflow.nr_flows = 1;
    inflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_i;
    inflow.p_ = &NACCBraytonCycle2017a_B.Switch2_n;
    inflow.psi = &NACCBraytonCycle2017a_B.psi_o[0];
    inflow.Sdot_ = &NACCBraytonCycle2017a_B.Sdot_e;

    /* Map outputs */
    outflow.nr_flows = 1;
    outflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_b;
    outflow.T_ = &NACCBraytonCycle2017a_B.T_n;
    outflow.p_ = &NACCBraytonCycle2017a_B.p_pc;
    outflow.Hdot_ = &NACCBraytonCycle2017a_B.Hdot_d;
    outflow.Sdot_ = &NACCBraytonCycle2017a_B.Sdot_k0;
    outflow.Gdot_ = &NACCBraytonCycle2017a_B.Gdot_km;
    outflow.Cpdot_ = &NACCBraytonCycle2017a_B.Cpdot_e;
    outflow.x = &NACCBraytonCycle2017a_B.x_o[0];
    outflow.psi = &NACCBraytonCycle2017a_B.psi_cu[0];
    (&NACCBraytonCycle2017a_B.error_codes_i)[0] = th_S_p_State(&inflow,&param,
      &SpOpt,&outflow,&SpTrace);
    (&NACCBraytonCycle2017a_B.iter)[0] = SpTrace.iterations;
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }

  /* End of Outputs for SubSystem: '<S124>/S-p-State' */

  /* MultiPortSwitch: '<S124>/Multiport Switch1' incorporates:
   *  Constant: '<S124>/T-normal2'
   *  Lookup: '<S124>/Efficiency Lookup Table'
   *  Product: '<S129>/Product11'
   */
  if ((int32_T)NACCBraytonCycle2017a_P.LPGasTurbine_Mode == 1) {
    /* Product: '<S129>/Product8' incorporates:
     *  Constant: '<S141>/M1'
     */
    rtb_Product8_m[0] = NACCBraytonCycle2017a_B.psi_p[0] *
      NACCBraytonCycle2017a_P.th_M[0];

    /* Sum: '<S129>/Sum2' */
    rtb_Sum2_g = rtb_Product8_m[0];
    for (i = 0; i < 6; i++) {
      /* Product: '<S129>/Product8' incorporates:
       *  Constant: '<S141>/M1'
       */
      rtb_Product8_m[i + 1] = NACCBraytonCycle2017a_B.psi_p[i + 1] *
        NACCBraytonCycle2017a_P.th_M[i + 1];

      /* Sum: '<S129>/Sum2' incorporates:
       *  Product: '<S129>/Product8'
       */
      rtb_Sum2_g += rtb_Product8_m[i + 1];
    }

    /* Product: '<S129>/Product11' */
    rtb_Product11_d = NACCBraytonCycle2017a_B.MultiportSwitch_h * rtb_Sum2_g;

    /* Lookup: '<S124>/Efficiency Lookup Table' incorporates:
     *  Product: '<S129>/Product11'
     */
    /*
     * About '<S124>/Efficiency Lookup Table':
     * Input0  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * XData parameter uses the same data type and scaling as Input0
     * YData parameter uses the same data type and scaling as Output0
     */
    LookUp_real_T_real_T( &(rtb_EfficiencyLookupTable),
                         NACCBraytonCycle2017a_P.LPGasTurbine_efficiency,
                         rtb_Product11_d,
                         NACCBraytonCycle2017a_P.LPGasTurbine_mdot2, 4U);
    rtb_UnitOffset = rtb_EfficiencyLookupTable;
  } else {
    /* Lookup2D: '<S127>/Lookup Table (2-D)2' */
    /*
     * About '<S127>/Lookup Table (2-D)2':
     * Input0  Data Type:  Floating Point real_T
     * Input1  Data Type:  Floating Point real_T
     * Output0 Data Type:  Floating Point real_T
     * Lookup Method: Linear_Endpoint
     *
     * Row Data    parameter uses the same data type and scaling as Input0
     * Column Data parameter uses the same data type and scaling as Input1
     * Table Data  parameter uses the same data type and scaling as Output0
     */
    Look2D_real_T_real_T_real_T( &(rtb_u),
      NACCBraytonCycle2017a_P.LookupTable2D2_Table_l, rtb_Switch2_f,
      NACCBraytonCycle2017a_P.LookupTable2D2_RowIdx_d, 5U, rtb_PR_l,
      NACCBraytonCycle2017a_P.LookupTable2D2_ColIdx_g, 20U);

    /* Saturate: '<S127>/Saturation1' */
    if (rtb_u > NACCBraytonCycle2017a_P.Saturation1_UpperSat_m) {
      rtb_UnitOffset = NACCBraytonCycle2017a_P.Saturation1_UpperSat_m;
    } else if (rtb_u < NACCBraytonCycle2017a_P.Saturation1_LowerSat_n) {
      rtb_UnitOffset = NACCBraytonCycle2017a_P.Saturation1_LowerSat_n;
    } else {
      rtb_UnitOffset = rtb_u;
    }

    /* End of Saturate: '<S127>/Saturation1' */
  }

  /* End of MultiPortSwitch: '<S124>/Multiport Switch1' */

  /* Product: '<S124>/Product10' incorporates:
   *  Gain: '<S124>/Gain1'
   *  Sum: '<S124>/Sum3'
   */
  rtb_UnitOffset = (NACCBraytonCycle2017a_B.Hdot_d -
                    NACCBraytonCycle2017a_B.Hdot_h) *
    (NACCBraytonCycle2017a_P.Gain1_Gain_fh * rtb_UnitOffset);

  /* Saturate: '<S124>/Saturation1' */
  if (rtb_UnitOffset > NACCBraytonCycle2017a_P.Saturation1_UpperSat_a) {
    rtb_UnitOffset = NACCBraytonCycle2017a_P.Saturation1_UpperSat_a;
  } else {
    if (rtb_UnitOffset < NACCBraytonCycle2017a_P.Saturation1_LowerSat_l) {
      rtb_UnitOffset = NACCBraytonCycle2017a_P.Saturation1_LowerSat_l;
    }
  }

  /* End of Saturate: '<S124>/Saturation1' */

  /* Sum: '<S124>/Subtract2' */
  NACCBraytonCycle2017a_B.Subtract2_o = rtb_UnitOffset +
    NACCBraytonCycle2017a_B.Hdot_h;

  /* Outputs for Atomic SubSystem: '<S124>/H-p-State with Heat Exchange' */

  /* S-Function (th_HpStateHeatExchange_S): '<S126>/S-Function' */
  /* Block <S126>/S-Function*/
  {
    Par param;
    flow inflow;
    flow outflow;
    Trace HpTrace;
    Options HpOpt;

    // Wird in Simulink nur einmal gemacht, hier jedes mal!
    th_SPoly3 *pCp_liq = (th_SPoly3*) EUallocate(sizeof(th_SPoly3));
    nasa *pNASA = (nasa *) EUallocate(sizeof(nasa));
    nasa *pNASA1= (nasa *) EUallocate(sizeof(nasa));
    th_InitParameters(&param);
    th_InitFlow(&inflow);
    th_InitFlow(&outflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_hi[7] -
                          pNASA->len * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_hi[7] +
                          pNASA->len * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_hi[7] +
                          pNASA->len * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_hi[7] +
                          pNASA->len * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_hi[7] +
                          pNASA->len * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_hi[7] +
                          pNASA->len * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_hi[7] +
                          pNASA->len * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_b[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_b[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_b[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_b[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_b[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_b[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_b[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_b[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_b[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_b[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_b[7] +
      pCp_liq->len * 2);
    param.nr_species = 7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.T_env = 300.0;
    param.k_loss = 0.0;
    param.A_total = 0.0;
    param.ndot_limit = 1.0E-9;
    param.T_cal = &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_a;
    param.water_index = (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.pCp_liq = pCp_liq;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction_P17_n;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction_P18_cy[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction_P19_go[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);
    HpOpt.derivative_neighbor_factor = 0.02;
    HpOpt.x_conv_limit = 0.0001;
    HpOpt.y_conv_limit = 1.0E-6;
    HpOpt.max_iterations = (int)100.0;

    /* Map inputs */
    inflow.nr_flows = 1;
    inflow.ndot_ = &NACCBraytonCycle2017a_B.MultiportSwitch_h;
    inflow.p_ = &NACCBraytonCycle2017a_B.Switch2_n;
    inflow.psi = &NACCBraytonCycle2017a_B.psi_p[0];
    inflow.Hdot_ = &NACCBraytonCycle2017a_B.Subtract2_o;

    /* Map outputs */
    outflow.nr_flows = 1;
    outflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_c;
    outflow.T_ = &NACCBraytonCycle2017a_B.T_p;
    outflow.p_ = &NACCBraytonCycle2017a_B.p_a;
    outflow.Hdot_ = &NACCBraytonCycle2017a_B.Hdot_o;
    outflow.Sdot_ = &NACCBraytonCycle2017a_B.Sdot_m;
    outflow.Gdot_ = &NACCBraytonCycle2017a_B.Gdot_b;
    outflow.Cpdot_ = &NACCBraytonCycle2017a_B.Cpdot_g;
    outflow.x = &NACCBraytonCycle2017a_B.x_k[0];
    outflow.psi = &NACCBraytonCycle2017a_B.psi_m[0];
    outflow.Qenv = &NACCBraytonCycle2017a_B.Qenv_p;
    (&NACCBraytonCycle2017a_B.error_codes_j)[0] = th_H_p_State_heat_Exchange
      (&inflow,&param,&HpOpt,&outflow,&HpTrace);
    (&NACCBraytonCycle2017a_B.num_iterations_a)[0] = HpTrace.iterations;
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }

  /* End of Outputs for SubSystem: '<S124>/H-p-State with Heat Exchange' */

  /* Sum: '<S388>/Sum2' */
  rtb_UnitOffset = -0.0;
  for (i = 0; i < 7; i++) {
    /* Sum: '<S388>/Sum2' incorporates:
     *  Constant: '<S392>/M1'
     *  Product: '<S388>/Product8'
     */
    rtb_UnitOffset += NACCBraytonCycle2017a_B.psi_m[i] *
      NACCBraytonCycle2017a_P.th_M[i];

    /* Product: '<S388>/Product8' incorporates:
     *  Constant: '<S99>/M1'
     *  Product: '<S98>/Product8'
     */
    rtb_Product8_m[i] = NACCBraytonCycle2017a_B.psi_al[i] *
      NACCBraytonCycle2017a_P.th_M[i];
  }

  /* Outport: '<Root>/Out25' incorporates:
   *  Constant: '<S33>/addition factor1'
   *  Gain: '<S33>/Gain1'
   *  Gain: '<S33>/Gain2'
   *  Product: '<S388>/Product11'
   *  Sum: '<S33>/Add'
   */
  NACCBraytonCycle2017a_Y.Out25 = NACCBraytonCycle2017a_B.ndot_c *
    rtb_UnitOffset * NACCBraytonCycle2017a_P.Gain2_Gain_h *
    NACCBraytonCycle2017a_P.Gain1_Gain_gr +
    NACCBraytonCycle2017a_P.additionfactor1_Value_hc;

  /* Outport: '<Root>/Out26' incorporates:
   *  Constant: '<S32>/addition factor1'
   *  Gain: '<S32>/Gain1'
   *  Sum: '<S32>/Add'
   */
  NACCBraytonCycle2017a_Y.Out26 = NACCBraytonCycle2017a_P.Gain1_Gain_kz *
    NACCBraytonCycle2017a_B.T_p +
    NACCBraytonCycle2017a_P.additionfactor1_Value_cl;

  /* Outport: '<Root>/Out27' incorporates:
   *  Constant: '<S30>/addition factor1'
   *  Gain: '<S30>/Gain1'
   *  Sum: '<S30>/Add'
   */
  NACCBraytonCycle2017a_Y.Out27 = NACCBraytonCycle2017a_P.Gain1_Gain_dv *
    NACCBraytonCycle2017a_B.p_a +
    NACCBraytonCycle2017a_P.additionfactor1_Value_el;

  /* Outport: '<Root>/Out28' incorporates:
   *  Constant: '<Root>/Constant9'
   *  Constant: '<S31>/addition factor1'
   *  Gain: '<S31>/Gain1'
   *  Product: '<Root>/Product6'
   *  Sum: '<S31>/Add'
   */
  NACCBraytonCycle2017a_Y.Out28 = (NACCBraytonCycle2017a_P.Gain1_Gain_py *
    NACCBraytonCycle2017a_B.Hdot_o +
    NACCBraytonCycle2017a_P.additionfactor1_Value_gl) *
    NACCBraytonCycle2017a_P.Constant9_Value;

  /* Sum: '<S98>/Sum2' incorporates:
   *  Sum: '<S100>/Sum'
   *  Sum: '<S105>/Sum2'
   *  Sum: '<S122>/Sum2'
   *  Sum: '<S124>/Sum'
   *  Sum: '<S129>/Sum2'
   *  Sum: '<S142>/Sum2'
   *  Sum: '<S149>/Sum2'
   *  Sum: '<S165>/Sum2'
   *  Sum: '<S179>/Sum2'
   *  Sum: '<S245>/Sum2'
   *  Sum: '<S289>/Sum2'
   *  Sum: '<S322>/Sum2'
   *  Sum: '<S388>/Sum2'
   *  Sum: '<S421>/Sum2'
   *  Sum: '<S465>/Sum2'
   *  Sum: '<S55>/Sum2'
   *  Sum: '<S61>/Sum2'
   *  Sum: '<S69>/Sum2'
   *  Sum: '<S73>/Sum'
   *  Sum: '<S77>/Sum2'
   *  Sum: '<S88>/Sum2'
   */
  rtb_UnitOffset = rtb_Product8_m[0];
  for (i = 0; i < 6; i++) {
    rtb_UnitOffset += rtb_Product8_m[i + 1];
  }

  /* Product: '<S98>/Product11' */
  rtb_UnitOffset *= NACCBraytonCycle2017a_B.ndot_l;

  /* Sum: '<S95>/Sum' incorporates:
   *  Gain: '<S95>/Gain'
   *  Math: '<S95>/Math Function'
   */
  rtb_UnitOffset = NACCBraytonCycle2017a_B.p_b - rtb_UnitOffset * rtb_UnitOffset
    * NACCBraytonCycle2017a_P.Gain_Gain_d;

  /* MinMax: '<S95>/MinMax' incorporates:
   *  Constant: '<S95>/p_downstrem_min'
   */
  if (!((rtb_UnitOffset > NACCBraytonCycle2017a_P.p_downstrem_min_Value_e) ||
        rtIsNaN(NACCBraytonCycle2017a_P.p_downstrem_min_Value_e))) {
    rtb_UnitOffset = NACCBraytonCycle2017a_P.p_downstrem_min_Value_e;
  }

  /* End of MinMax: '<S95>/MinMax' */

  /* Saturate: '<S95>/Saturation' */
  if (rtb_UnitOffset > NACCBraytonCycle2017a_P.Saturation_UpperSat_f) {
    NACCBraytonCycle2017a_B.Saturation_p =
      NACCBraytonCycle2017a_P.Saturation_UpperSat_f;
  } else if (rtb_UnitOffset < NACCBraytonCycle2017a_P.Saturation_LowerSat_p) {
    NACCBraytonCycle2017a_B.Saturation_p =
      NACCBraytonCycle2017a_P.Saturation_LowerSat_p;
  } else {
    NACCBraytonCycle2017a_B.Saturation_p = rtb_UnitOffset;
  }

  /* End of Saturate: '<S95>/Saturation' */

  /* Sum: '<S96>/Sum7' incorporates:
   *  Inport: '<Root>/In5'
   */
  NACCBraytonCycle2017a_B.Sum7 = NACCBraytonCycle2017a_B.Hdot_jv +
    NACCBraytonCycle2017a_U.In5;

  /* Outputs for Atomic SubSystem: '<S96>/H-p-State with HeatLoss' */

  /* S-Function (th_HpStateHeatExchange_S): '<S97>/S-Function' */
  /* Block <S97>/S-Function*/
  {
    Par param;
    flow inflow;
    flow outflow;
    Trace HpTrace;
    Options HpOpt;

    // Wird in Simulink nur einmal gemacht, hier jedes mal!
    th_SPoly3 *pCp_liq = (th_SPoly3*) EUallocate(sizeof(th_SPoly3));
    nasa *pNASA = (nasa *) EUallocate(sizeof(nasa));
    nasa *pNASA1= (nasa *) EUallocate(sizeof(nasa));
    th_InitParameters(&param);
    th_InitFlow(&inflow);
    th_InitFlow(&outflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_a[7] -
                          pNASA->len * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_a[7] +
                          pNASA->len * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_a[7] +
                          pNASA->len * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_a[7] +
                          pNASA->len * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_a[7] +
                          pNASA->len * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_a[7] +
                          pNASA->len * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_a[7] +
                          pNASA->len * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_l[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_l[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_l[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_l[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_l[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_l[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_l[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_e[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_e[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_e[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_e[7] +
      pCp_liq->len * 2);
    param.nr_species = 7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.T_env = 288.15;
    param.k_loss = 0.0;
    param.A_total = 1.0;
    param.ndot_limit = 1.0E-9;
    param.T_cal = &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_h;
    param.water_index = (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.pCp_liq = pCp_liq;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction_P17_pk;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction_P18_b[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction_P19_g[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);
    HpOpt.derivative_neighbor_factor = 0.02;
    HpOpt.x_conv_limit = 0.0001;
    HpOpt.y_conv_limit = 1.0E-6;
    HpOpt.max_iterations = (int)100.0;

    /* Map inputs */
    inflow.nr_flows = 1;
    inflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_l;
    inflow.p_ = &NACCBraytonCycle2017a_B.Saturation_p;
    inflow.psi = &NACCBraytonCycle2017a_B.psi_al[0];
    inflow.Hdot_ = &NACCBraytonCycle2017a_B.Sum7;

    /* Map outputs */
    outflow.nr_flows = 1;
    outflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_bl;
    outflow.T_ = &NACCBraytonCycle2017a_B.T_gf;
    outflow.p_ = &NACCBraytonCycle2017a_B.p_a1;
    outflow.Hdot_ = &NACCBraytonCycle2017a_B.Hdot_b;
    outflow.Sdot_ = &NACCBraytonCycle2017a_B.Sdot_n;
    outflow.Gdot_ = &NACCBraytonCycle2017a_B.Gdot_f;
    outflow.Cpdot_ = &NACCBraytonCycle2017a_B.Cpdot_aq;
    outflow.x = &NACCBraytonCycle2017a_B.x_f[0];
    outflow.psi = &NACCBraytonCycle2017a_B.psi_f[0];
    outflow.Qenv = &NACCBraytonCycle2017a_B.Qenv_d;
    (&NACCBraytonCycle2017a_B.error_codes_d)[0] = th_H_p_State_heat_Exchange
      (&inflow,&param,&HpOpt,&outflow,&HpTrace);
    (&NACCBraytonCycle2017a_B.num_iterations_j)[0] = HpTrace.iterations;
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }

  /* End of Outputs for SubSystem: '<S96>/H-p-State with HeatLoss' */

  /* Product: '<S122>/Product8' incorporates:
   *  Constant: '<S123>/M1'
   */
  rtb_Product8_m[0] = NACCBraytonCycle2017a_B.psi_i[0] *
    NACCBraytonCycle2017a_P.th_M[0];

  /* Sum: '<S122>/Sum2' */
  rtb_UnitOffset = rtb_Product8_m[0];
  for (i = 0; i < 6; i++) {
    /* Product: '<S122>/Product8' incorporates:
     *  Constant: '<S123>/M1'
     */
    rtb_Product8_m[i + 1] = NACCBraytonCycle2017a_B.psi_i[i + 1] *
      NACCBraytonCycle2017a_P.th_M[i + 1];

    /* Sum: '<S122>/Sum2' incorporates:
     *  Product: '<S122>/Product8'
     */
    rtb_UnitOffset += rtb_Product8_m[i + 1];
  }

  /* Product: '<S122>/Product11' */
  rtb_UnitOffset *= NACCBraytonCycle2017a_B.ndot_nq;

  /* Sum: '<S119>/Sum' incorporates:
   *  Gain: '<S119>/Gain'
   *  Math: '<S119>/Math Function'
   */
  rtb_Sum2_g = NACCBraytonCycle2017a_B.p_g - rtb_UnitOffset * rtb_UnitOffset *
    NACCBraytonCycle2017a_P.Gain_Gain_cj;

  /* MinMax: '<S119>/MinMax' incorporates:
   *  Constant: '<S119>/p_downstrem_min'
   */
  if (!((rtb_Sum2_g > NACCBraytonCycle2017a_P.p_downstrem_min_Value_n) ||
        rtIsNaN(NACCBraytonCycle2017a_P.p_downstrem_min_Value_n))) {
    rtb_Sum2_g = NACCBraytonCycle2017a_P.p_downstrem_min_Value_n;
  }

  /* End of MinMax: '<S119>/MinMax' */

  /* Saturate: '<S119>/Saturation' */
  if (rtb_Sum2_g > NACCBraytonCycle2017a_P.Saturation_UpperSat_l) {
    NACCBraytonCycle2017a_B.Saturation_lg =
      NACCBraytonCycle2017a_P.Saturation_UpperSat_l;
  } else if (rtb_Sum2_g < NACCBraytonCycle2017a_P.Saturation_LowerSat_a) {
    NACCBraytonCycle2017a_B.Saturation_lg =
      NACCBraytonCycle2017a_P.Saturation_LowerSat_a;
  } else {
    NACCBraytonCycle2017a_B.Saturation_lg = rtb_Sum2_g;
  }

  /* End of Saturate: '<S119>/Saturation' */

  /* Sum: '<S120>/Sum7' incorporates:
   *  Inport: '<Root>/In7'
   */
  NACCBraytonCycle2017a_B.Sum7_h = NACCBraytonCycle2017a_B.Hdot_n +
    NACCBraytonCycle2017a_U.In7;

  /* Outputs for Atomic SubSystem: '<S120>/H-p-State with HeatLoss' */

  /* S-Function (th_HpStateHeatExchange_S): '<S121>/S-Function' */
  /* Block <S121>/S-Function*/
  {
    Par param;
    flow inflow;
    flow outflow;
    Trace HpTrace;
    Options HpOpt;

    // Wird in Simulink nur einmal gemacht, hier jedes mal!
    th_SPoly3 *pCp_liq = (th_SPoly3*) EUallocate(sizeof(th_SPoly3));
    nasa *pNASA = (nasa *) EUallocate(sizeof(nasa));
    nasa *pNASA1= (nasa *) EUallocate(sizeof(nasa));
    th_InitParameters(&param);
    th_InitFlow(&inflow);
    th_InitFlow(&outflow);

    // pNASA: nasa coefficients for the temperature range 1000 - 6000 K
    /* Achtung: Index fuer den Pointer wird automatisch auf Anzahl Spalten
       angehaengt. Dies muss hier wieder abgezogen werden.) */
    pNASA->len = (int) 7 ;
    pNASA->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_nq[7] -
                          pNASA->len * 1);
    pNASA->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_nq[7] +
                          pNASA->len * 0);
    pNASA->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_nq[7] +
                          pNASA->len * 1);
    pNASA->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_nq[7] +
                          pNASA->len * 2);
    pNASA->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_nq[7] +
                          pNASA->len * 3);
    pNASA->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_nq[7] +
                          pNASA->len * 4);
    pNASA->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P4_nq[7] +
                          pNASA->len * 5);

    // pNASA1: nasa coefficients for the temperature range 200 - 1000 K
    pNASA1->len = (int) 7;
    pNASA1->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_c[7] -
      pNASA1->len * 1);
    pNASA1->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_c[7] +
      pNASA1->len * 0);
    pNASA1->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_c[7] +
      pNASA1->len * 1);
    pNASA1->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_c[7] +
      pNASA1->len * 2);
    pNASA1->E = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_c[7] +
      pNASA1->len * 3);
    pNASA1->F = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_c[7] +
      pNASA1->len * 4);
    pNASA1->G = (double*) (&NACCBraytonCycle2017a_P.SFunction_P5_c[7] +
      pNASA1->len * 5);

    // coefficients for the polynomial representing the liquid cp
    pCp_liq->len = (int) 7;
    pCp_liq->A = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_e5[7] -
      pCp_liq->len * 1);
    pCp_liq->B = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_e5[7] +
      pCp_liq->len * 0);
    pCp_liq->C = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_e5[7] +
      pCp_liq->len * 1);
    pCp_liq->D = (double*) (&NACCBraytonCycle2017a_P.SFunction_P12_e5[7] +
      pCp_liq->len * 2);
    param.nr_species = 7;
    param.T_low = (double*) NACCBraytonCycle2017a_P.th_NASA_T_min;
    param.T_mid = (double*) NACCBraytonCycle2017a_P.th_NASA_T_mid;
    param.T_hi = (double*) NACCBraytonCycle2017a_P.th_NASA_T_max;
    param.T_env = 298.0;
    param.k_loss = 0.0;
    param.A_total = 1.0;
    param.ndot_limit = 1.0E-9;
    param.T_cal = &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_n;
    param.water_index = (int) 0.0;
    param.if97_index = (int) -1.0;
    param.gas_eos_method = (int) 1.0;
    param.T_fg_ref = (double*) NACCBraytonCycle2017a_P.th_T_fg_ref;
    param.HM_ref = (double*) NACCBraytonCycle2017a_P.th_hm_fg;
    param.SM_ref = (double*) NACCBraytonCycle2017a_P.th_sm_fg;
    param.Cp_liq_min = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_min;
    param.Cp_liq_max = (double*) NACCBraytonCycle2017a_P.th_Cp_liq_T_max;
    param.pCp_liq = pCp_liq;
    param.T_triple = (double*) NACCBraytonCycle2017a_P.th_T_triple;
    param.T_cr = (double*) NACCBraytonCycle2017a_P.th_T_c;
    param.P_cr = (double*) NACCBraytonCycle2017a_P.th_p_c;
    param.acentric_factor= (double*) NACCBraytonCycle2017a_P.th_omega;
    param.molar_weights = (double*) NACCBraytonCycle2017a_P.th_M;
    param.antoine_A = (double*) NACCBraytonCycle2017a_P.th_Antoine_A;
    param.antoine_B = (double*) NACCBraytonCycle2017a_P.th_Antoine_B;
    param.antoine_C = (double*) NACCBraytonCycle2017a_P.th_Antoine_C;
    param.pNASA = pNASA;
    param.pNASA1 = pNASA1;
    param.x_index_len = (int) 24;
    param.x_index = (double*) NACCBraytonCycle2017a_P.SFunction_P17_dx;
    param.y_index_len = (int) 21;
    param.y_index = (double*) (&NACCBraytonCycle2017a_P.SFunction_P18_j[1] - 1);
    param.table = (double*) (&NACCBraytonCycle2017a_P.SFunction_P19_d[24] - 24);
    param.liquid_eos_method = (int) (1.0);
    param.evap_enth_A = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_A);
    param.evap_enth_B = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_B);
    param.evap_enth_C = (double*) (NACCBraytonCycle2017a_P.th_evap_enth_C);
    param.evap_enth_T_min = (double*)
      (NACCBraytonCycle2017a_P.th_evap_enth_T_min);
    HpOpt.derivative_neighbor_factor = 0.02;
    HpOpt.x_conv_limit = 0.0001;
    HpOpt.y_conv_limit = 1.0E-6;
    HpOpt.max_iterations = (int)100.0;

    /* Map inputs */
    inflow.nr_flows = 1;
    inflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_nq;
    inflow.p_ = &NACCBraytonCycle2017a_B.Saturation_lg;
    inflow.psi = &NACCBraytonCycle2017a_B.psi_i[0];
    inflow.Hdot_ = &NACCBraytonCycle2017a_B.Sum7_h;

    /* Map outputs */
    outflow.nr_flows = 1;
    outflow.ndot_ = &NACCBraytonCycle2017a_B.ndot_ol;
    outflow.T_ = &NACCBraytonCycle2017a_B.T_ed;
    outflow.p_ = &NACCBraytonCycle2017a_B.p_a5;
    outflow.Hdot_ = &NACCBraytonCycle2017a_B.Hdot_i;
    outflow.Sdot_ = &NACCBraytonCycle2017a_B.Sdot_c;
    outflow.Gdot_ = &NACCBraytonCycle2017a_B.Gdot_m;
    outflow.Cpdot_ = &NACCBraytonCycle2017a_B.Cpdot_p;
    outflow.x = &NACCBraytonCycle2017a_B.x_ac[0];
    outflow.psi = &NACCBraytonCycle2017a_B.psi_a[0];
    outflow.Qenv = &NACCBraytonCycle2017a_B.Qenv_k;
    (&NACCBraytonCycle2017a_B.error_codes_i0)[0] = th_H_p_State_heat_Exchange
      (&inflow,&param,&HpOpt,&outflow,&HpTrace);
    (&NACCBraytonCycle2017a_B.num_iterations_f)[0] = HpTrace.iterations;
    EUfree(pNASA);
    EUfree(pNASA1);
    EUfree(pCp_liq);
  }

  /* End of Outputs for SubSystem: '<S120>/H-p-State with HeatLoss' */
}

/* Model update function */
static void NACCBraytonCycle2017a_update(void)
{
  int32_T i;

  /* Update for Memory: '<S73>/Memory1' incorporates:
   *  Constant: '<S4>/PFin'
   */
  NACCBraytonCycle2017a_DW.Memory1_PreviousInput[0] =
    NACCBraytonCycle2017a_P.PFin_Value;
  NACCBraytonCycle2017a_DW.Memory1_PreviousInput[1] =
    NACCBraytonCycle2017a_P.PFin_Value;
  NACCBraytonCycle2017a_DW.Memory1_PreviousInput[2] =
    NACCBraytonCycle2017a_P.PFin_Value;
  NACCBraytonCycle2017a_DW.Memory1_PreviousInput[3] =
    NACCBraytonCycle2017a_P.PFin_Value;

  /* Update for Memory: '<S81>/Memory' */
  NACCBraytonCycle2017a_DW.Memory_PreviousInput =
    NACCBraytonCycle2017a_B.Product1;

  /* Update for Atomic SubSystem: '<S73>/S-p-State' */

  /* Update for S-Function (th_SpState_S): '<S79>/S-Function' */

  /* Block: <S79>/S-Function */
  {
    int i;
    real_T *T_cal = (real_T*) &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_mu;
    double *T_out = &NACCBraytonCycle2017a_B.T_d;
    for (i=0;i<1;i++) {
      T_cal [i] = T_out[i];
    }
  }

  /* End of Update for SubSystem: '<S73>/S-p-State' */

  /* Update for Atomic SubSystem: '<S73>/H-p-State with Heat Exchange' */

  /* Update for S-Function (th_HpStateHeatExchange_S): '<S76>/S-Function' */

  /* Block: <S76>/S-Function */
  {
    int i;
    real_T *T_cal = (real_T*) &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_p;
    double *T_out = &NACCBraytonCycle2017a_B.T_j;
    for (i=0;i<1;i++) {
      T_cal [i] = T_out[i];
    }
  }

  /* End of Update for SubSystem: '<S73>/H-p-State with Heat Exchange' */

  /* Update for Memory: '<S8>/Memory9' */
  NACCBraytonCycle2017a_DW.Memory9_PreviousInput =
    NACCBraytonCycle2017a_B.ndot_bl;

  /* Update for Memory: '<S8>/Memory1' */
  NACCBraytonCycle2017a_DW.Memory1_PreviousInput_b =
    NACCBraytonCycle2017a_B.T_gf;

  /* Update for Memory: '<S8>/Memory2' */
  NACCBraytonCycle2017a_DW.Memory2_PreviousInput = NACCBraytonCycle2017a_B.p_a1;

  /* Update for Memory: '<S8>/Memory3' */
  NACCBraytonCycle2017a_DW.Memory3_PreviousInput =
    NACCBraytonCycle2017a_B.Hdot_b;
  for (i = 0; i < 7; i++) {
    /* Update for Memory: '<S8>/Memory4' */
    NACCBraytonCycle2017a_DW.Memory4_PreviousInput[i] =
      NACCBraytonCycle2017a_B.psi_f[i];

    /* Update for Memory: '<S8>/Memory8' */
    NACCBraytonCycle2017a_DW.Memory8_PreviousInput[i] =
      NACCBraytonCycle2017a_B.x_f[i];
  }

  /* Update for Atomic SubSystem: '<S100>/S-p-State' */

  /* Update for S-Function (th_SpState_S): '<S107>/S-Function' */

  /* Block: <S107>/S-Function */
  {
    int i;
    real_T *T_cal = (real_T*) &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_f;
    double *T_out = &NACCBraytonCycle2017a_B.T_m;
    for (i=0;i<1;i++) {
      T_cal [i] = T_out[i];
    }
  }

  /* End of Update for SubSystem: '<S100>/S-p-State' */

  /* Update for Atomic SubSystem: '<S100>/H-p-State with Heat Exchange' */

  /* Update for S-Function (th_HpStateHeatExchange_S): '<S102>/S-Function' */

  /* Block: <S102>/S-Function */
  {
    int i;
    real_T *T_cal = (real_T*) &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_o;
    double *T_out = &NACCBraytonCycle2017a_B.T_h;
    for (i=0;i<1;i++) {
      T_cal [i] = T_out[i];
    }
  }

  /* End of Update for SubSystem: '<S100>/H-p-State with Heat Exchange' */

  /* Update for Memory: '<S7>/Memory9' */
  NACCBraytonCycle2017a_DW.Memory9_PreviousInput_a =
    NACCBraytonCycle2017a_B.ndot_ol;

  /* Update for Memory: '<S7>/Memory1' */
  NACCBraytonCycle2017a_DW.Memory1_PreviousInput_p =
    NACCBraytonCycle2017a_B.T_ed;

  /* Update for Memory: '<S7>/Memory2' */
  NACCBraytonCycle2017a_DW.Memory2_PreviousInput_o =
    NACCBraytonCycle2017a_B.p_a5;

  /* Update for Memory: '<S7>/Memory3' */
  NACCBraytonCycle2017a_DW.Memory3_PreviousInput_d =
    NACCBraytonCycle2017a_B.Hdot_i;
  for (i = 0; i < 7; i++) {
    /* Update for Memory: '<S7>/Memory4' */
    NACCBraytonCycle2017a_DW.Memory4_PreviousInput_p[i] =
      NACCBraytonCycle2017a_B.psi_a[i];

    /* Update for Memory: '<S7>/Memory8' */
    NACCBraytonCycle2017a_DW.Memory8_PreviousInput_p[i] =
      NACCBraytonCycle2017a_B.x_ac[i];
  }

  /* Update for Atomic SubSystem: '<S11>/Mixer' */

  /* Update for Atomic SubSystem: '<S142>/H-p-State with HeatLoss' */

  /* Update for S-Function (th_HpStateHeatExchange_S): '<S145>/S-Function' */

  /* Block: <S145>/S-Function */
  {
    int i;
    real_T *T_cal = (real_T*) &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK;
    double *T_out = &NACCBraytonCycle2017a_B.T_go;
    for (i=0;i<1;i++) {
      T_cal [i] = T_out[i];
    }
  }

  /* End of Update for SubSystem: '<S142>/H-p-State with HeatLoss' */

  /* End of Update for SubSystem: '<S11>/Mixer' */

  /* Update for Atomic SubSystem: '<S57>/H-p-State with Heat Exchange' */

  /* Update for S-Function (th_HpStateHeatExchange_S): '<S58>/S-Function' */

  /* Block: <S58>/S-Function */
  {
    int i;
    real_T *T_cal = (real_T*) &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_j;
    double *T_out = &NACCBraytonCycle2017a_B.T_h3;
    for (i=0;i<1;i++) {
      T_cal [i] = T_out[i];
    }
  }

  /* End of Update for SubSystem: '<S57>/H-p-State with Heat Exchange' */

  /* Update for Atomic SubSystem: '<S65>/H-p-State with Heat Exchange' */

  /* Update for S-Function (th_HpStateHeatExchange_S): '<S66>/S-Function' */

  /* Block: <S66>/S-Function */
  {
    int i;
    real_T *T_cal = (real_T*) &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_l;
    double *T_out = &NACCBraytonCycle2017a_B.T_mo;
    for (i=0;i<1;i++) {
      T_cal [i] = T_out[i];
    }
  }

  /* End of Update for SubSystem: '<S65>/H-p-State with Heat Exchange' */

  /* Update for Atomic SubSystem: '<S124>/S-p-State' */

  /* Update for S-Function (th_SpState_S): '<S131>/S-Function' */

  /* Block: <S131>/S-Function */
  {
    int i;
    real_T *T_cal = (real_T*) &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_m;
    double *T_out = &NACCBraytonCycle2017a_B.T_n;
    for (i=0;i<1;i++) {
      T_cal [i] = T_out[i];
    }
  }

  /* End of Update for SubSystem: '<S124>/S-p-State' */

  /* Update for Atomic SubSystem: '<S124>/H-p-State with Heat Exchange' */

  /* Update for S-Function (th_HpStateHeatExchange_S): '<S126>/S-Function' */

  /* Block: <S126>/S-Function */
  {
    int i;
    real_T *T_cal = (real_T*) &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_a;
    double *T_out = &NACCBraytonCycle2017a_B.T_p;
    for (i=0;i<1;i++) {
      T_cal [i] = T_out[i];
    }
  }

  /* End of Update for SubSystem: '<S124>/H-p-State with Heat Exchange' */

  /* Update for Atomic SubSystem: '<S96>/H-p-State with HeatLoss' */

  /* Update for S-Function (th_HpStateHeatExchange_S): '<S97>/S-Function' */

  /* Block: <S97>/S-Function */
  {
    int i;
    real_T *T_cal = (real_T*) &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_h;
    double *T_out = &NACCBraytonCycle2017a_B.T_gf;
    for (i=0;i<1;i++) {
      T_cal [i] = T_out[i];
    }
  }

  /* End of Update for SubSystem: '<S96>/H-p-State with HeatLoss' */

  /* Update for Atomic SubSystem: '<S120>/H-p-State with HeatLoss' */

  /* Update for S-Function (th_HpStateHeatExchange_S): '<S121>/S-Function' */

  /* Block: <S121>/S-Function */
  {
    int i;
    real_T *T_cal = (real_T*) &NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_n;
    double *T_out = &NACCBraytonCycle2017a_B.T_ed;
    for (i=0;i<1;i++) {
      T_cal [i] = T_out[i];
    }
  }

  /* End of Update for SubSystem: '<S120>/H-p-State with HeatLoss' */

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++NACCBraytonCycle2017a_M->Timing.clockTick0)) {
    ++NACCBraytonCycle2017a_M->Timing.clockTickH0;
  }

  NACCBraytonCycle2017a_M->Timing.t[0] =
    NACCBraytonCycle2017a_M->Timing.clockTick0 *
    NACCBraytonCycle2017a_M->Timing.stepSize0 +
    NACCBraytonCycle2017a_M->Timing.clockTickH0 *
    NACCBraytonCycle2017a_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void NACCBraytonCycle2017a_initialize(void)
{
  /* Start for IfAction SubSystem: '<S1>/VolumeFlow' */

  /* Start for Atomic SubSystem: '<S48>/T-p-Vapor Fractions' */
  NACCBray_TpVaporFractions_Start();

  /* End of Start for SubSystem: '<S48>/T-p-Vapor Fractions' */

  /* Start for S-Function (th_Density_S): '<S54>/S-Function' incorporates:
   *  Constant: '<S1>/psi'
   */
  {
    th_ThermolibInitialize();
  }

  /* End of Start for SubSystem: '<S1>/VolumeFlow' */

  /* Start for Atomic SubSystem: '<S1>/T-p-State' */
  NACCBraytonCycle2_TpState_Start();

  /* End of Start for SubSystem: '<S1>/T-p-State' */

  /* Start for Atomic SubSystem: '<S73>/T-p-State' */
  NACCBraytonCycl_TpState_j_Start();

  /* End of Start for SubSystem: '<S73>/T-p-State' */

  /* Start for Atomic SubSystem: '<S73>/S-p-State' */

  /* Start for S-Function (th_SpState_S): '<S79>/S-Function' */
  {
    th_ThermolibInitialize();
  }

  /* End of Start for SubSystem: '<S73>/S-p-State' */

  /* Start for Atomic SubSystem: '<S73>/H-p-State with Heat Exchange' */

  /* Start for S-Function (th_HpStateHeatExchange_S): '<S76>/S-Function' */
  {
    th_ThermolibInitialize();
  }

  /* End of Start for SubSystem: '<S73>/H-p-State with Heat Exchange' */

  /* Start for S-Function (th_TpxState_S): '<S109>/S-Function1' */
  {
    th_ThermolibInitialize();
  }

  /* Start for Atomic SubSystem: '<S100>/S-p-State' */

  /* Start for S-Function (th_SpState_S): '<S107>/S-Function' */
  {
    th_ThermolibInitialize();
  }

  /* End of Start for SubSystem: '<S100>/S-p-State' */

  /* Start for Atomic SubSystem: '<S100>/H-p-State with Heat Exchange' */

  /* Start for S-Function (th_HpStateHeatExchange_S): '<S102>/S-Function' */
  {
    th_ThermolibInitialize();
  }

  /* End of Start for SubSystem: '<S100>/H-p-State with Heat Exchange' */

  /* Start for IfAction SubSystem: '<S12>/VolumeFlow' */

  /* Start for Atomic SubSystem: '<S158>/T-p-Vapor Fractions' */
  NACCBr_TpVaporFractions_f_Start();

  /* End of Start for SubSystem: '<S158>/T-p-Vapor Fractions' */

  /* Start for S-Function (th_Density_S): '<S164>/S-Function' incorporates:
   *  Constant: '<S12>/psi'
   */
  {
    th_ThermolibInitialize();
  }

  /* End of Start for SubSystem: '<S12>/VolumeFlow' */

  /* Start for Atomic SubSystem: '<S12>/T-p-State' */
  NACCBraytonCycl_TpState_d_Start();

  /* End of Start for SubSystem: '<S12>/T-p-State' */

  /* Start for Atomic SubSystem: '<S11>/Mixer' */

  /* Start for S-Function (th_TpxState_S): '<S147>/S-Function1' */
  {
    th_ThermolibInitialize();
  }

  /* Start for Atomic SubSystem: '<S142>/H-p-State with HeatLoss' */

  /* Start for S-Function (th_HpStateHeatExchange_S): '<S145>/S-Function' */
  {
    th_ThermolibInitialize();
  }

  /* End of Start for SubSystem: '<S142>/H-p-State with HeatLoss' */

  /* End of Start for SubSystem: '<S11>/Mixer' */

  /* Start for Atomic SubSystem: '<S57>/H-p-State with Heat Exchange' */

  /* Start for S-Function (th_HpStateHeatExchange_S): '<S58>/S-Function' */
  {
    th_ThermolibInitialize();
  }

  /* End of Start for SubSystem: '<S57>/H-p-State with Heat Exchange' */

  /* Start for Atomic SubSystem: '<S65>/H-p-State with Heat Exchange' */

  /* Start for S-Function (th_HpStateHeatExchange_S): '<S66>/S-Function' */
  {
    th_ThermolibInitialize();
  }

  /* End of Start for SubSystem: '<S65>/H-p-State with Heat Exchange' */

  /* Start for S-Function (th_TpxState_S): '<S133>/S-Function1' */
  {
    th_ThermolibInitialize();
  }

  /* Start for Atomic SubSystem: '<S124>/S-p-State' */

  /* Start for S-Function (th_SpState_S): '<S131>/S-Function' */
  {
    th_ThermolibInitialize();
  }

  /* End of Start for SubSystem: '<S124>/S-p-State' */

  /* Start for Atomic SubSystem: '<S124>/H-p-State with Heat Exchange' */

  /* Start for S-Function (th_HpStateHeatExchange_S): '<S126>/S-Function' */
  {
    th_ThermolibInitialize();
  }

  /* End of Start for SubSystem: '<S124>/H-p-State with Heat Exchange' */

  /* Start for Atomic SubSystem: '<S96>/H-p-State with HeatLoss' */

  /* Start for S-Function (th_HpStateHeatExchange_S): '<S97>/S-Function' */
  {
    th_ThermolibInitialize();
  }

  /* End of Start for SubSystem: '<S96>/H-p-State with HeatLoss' */

  /* Start for Atomic SubSystem: '<S120>/H-p-State with HeatLoss' */

  /* Start for S-Function (th_HpStateHeatExchange_S): '<S121>/S-Function' */
  {
    th_ThermolibInitialize();
  }

  /* End of Start for SubSystem: '<S120>/H-p-State with HeatLoss' */
  {
    int32_T i;

    /* InitializeConditions for Memory: '<S73>/Memory1' */
    NACCBraytonCycle2017a_DW.Memory1_PreviousInput[0] =
      NACCBraytonCycle2017a_P.Memory1_X0[0];
    NACCBraytonCycle2017a_DW.Memory1_PreviousInput[1] =
      NACCBraytonCycle2017a_P.Memory1_X0[1];
    NACCBraytonCycle2017a_DW.Memory1_PreviousInput[2] =
      NACCBraytonCycle2017a_P.Memory1_X0[2];
    NACCBraytonCycle2017a_DW.Memory1_PreviousInput[3] =
      NACCBraytonCycle2017a_P.Memory1_X0[3];

    /* InitializeConditions for Memory: '<S81>/Memory' */
    NACCBraytonCycle2017a_DW.Memory_PreviousInput =
      NACCBraytonCycle2017a_P.Memory_X0;

    /* InitializeConditions for Memory: '<S8>/Memory9' */
    NACCBraytonCycle2017a_DW.Memory9_PreviousInput =
      NACCBraytonCycle2017a_P.InitialCondition3_ndot;

    /* InitializeConditions for Memory: '<S8>/Memory1' */
    NACCBraytonCycle2017a_DW.Memory1_PreviousInput_b =
      NACCBraytonCycle2017a_P.Memory1_X0_n;

    /* InitializeConditions for Memory: '<S8>/Memory2' */
    NACCBraytonCycle2017a_DW.Memory2_PreviousInput =
      NACCBraytonCycle2017a_P.Memory2_X0;

    /* InitializeConditions for Memory: '<S8>/Memory3' */
    NACCBraytonCycle2017a_DW.Memory3_PreviousInput =
      NACCBraytonCycle2017a_P.InitialCondition3_Hdot;

    /* InitializeConditions for Memory: '<S7>/Memory9' */
    NACCBraytonCycle2017a_DW.Memory9_PreviousInput_a =
      NACCBraytonCycle2017a_P.InitialCondition2_ndot;

    /* InitializeConditions for Memory: '<S7>/Memory1' */
    NACCBraytonCycle2017a_DW.Memory1_PreviousInput_p =
      NACCBraytonCycle2017a_P.Memory1_X0_o;

    /* InitializeConditions for Memory: '<S7>/Memory2' */
    NACCBraytonCycle2017a_DW.Memory2_PreviousInput_o =
      NACCBraytonCycle2017a_P.Memory2_X0_p;

    /* InitializeConditions for Memory: '<S7>/Memory3' */
    NACCBraytonCycle2017a_DW.Memory3_PreviousInput_d =
      NACCBraytonCycle2017a_P.InitialCondition2_Hdot;
    for (i = 0; i < 7; i++) {
      /* InitializeConditions for Memory: '<S8>/Memory4' */
      NACCBraytonCycle2017a_DW.Memory4_PreviousInput[i] =
        NACCBraytonCycle2017a_P.InitialCondition3_psi[i];

      /* InitializeConditions for Memory: '<S8>/Memory8' */
      NACCBraytonCycle2017a_DW.Memory8_PreviousInput[i] =
        NACCBraytonCycle2017a_P.InitialCondition3_x[i];

      /* InitializeConditions for Memory: '<S7>/Memory4' */
      NACCBraytonCycle2017a_DW.Memory4_PreviousInput_p[i] =
        NACCBraytonCycle2017a_P.InitialCondition2_psi[i];

      /* InitializeConditions for Memory: '<S7>/Memory8' */
      NACCBraytonCycle2017a_DW.Memory8_PreviousInput_p[i] =
        NACCBraytonCycle2017a_P.InitialCondition2_x[i];
    }

    /* SystemInitialize for IfAction SubSystem: '<S1>/Reservoir' */
    /* SystemInitialize for Outport: '<S43>/nan' */
    NACCBraytonCycle2017a_B.ndot = NACCBraytonCycle2017a_P.nan_Y0;

    /* End of SystemInitialize for SubSystem: '<S1>/Reservoir' */

    /* SystemInitialize for Atomic SubSystem: '<S73>/S-p-State' */

    /* InitializeConditions for Atomic SubSystem: '<S73>/S-p-State' */

    /* InitializeConditions for S-Function (th_SpState_S): '<S79>/S-Function' */

    /* Block: <S79>/S-Function */
    {
      const double *T_initial = (const double*)
        &NACCBraytonCycle2017a_P.SpState_T_initial;

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_mu = T_initial[0];
        }
      }
    }

    /* End of InitializeConditions for SubSystem: '<S73>/S-p-State' */

    /* End of SystemInitialize for SubSystem: '<S73>/S-p-State' */

    /* SystemInitialize for Atomic SubSystem: '<S73>/H-p-State with Heat Exchange' */

    /* InitializeConditions for Atomic SubSystem: '<S73>/H-p-State with Heat Exchange' */

    /* InitializeConditions for S-Function (th_HpStateHeatExchange_S): '<S76>/S-Function' */

    /* Block: <S76>/S-Function */
    {
      const double *T_initial = (const double*)
        &NACCBraytonCycle2017a_P.HpStatewithHeatExchange_T_ini_e;

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_p = T_initial[0];
        }
      }
    }

    /* End of InitializeConditions for SubSystem: '<S73>/H-p-State with Heat Exchange' */

    /* End of SystemInitialize for SubSystem: '<S73>/H-p-State with Heat Exchange' */

    /* SystemInitialize for Atomic SubSystem: '<S100>/S-p-State' */

    /* InitializeConditions for Atomic SubSystem: '<S100>/S-p-State' */

    /* InitializeConditions for S-Function (th_SpState_S): '<S107>/S-Function' */

    /* Block: <S107>/S-Function */
    {
      const double *T_initial = (const double*)
        &NACCBraytonCycle2017a_P.SpState_T_initial_i;

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_f = T_initial[0];
        }
      }
    }

    /* End of InitializeConditions for SubSystem: '<S100>/S-p-State' */

    /* End of SystemInitialize for SubSystem: '<S100>/S-p-State' */

    /* SystemInitialize for Atomic SubSystem: '<S100>/H-p-State with Heat Exchange' */

    /* InitializeConditions for Atomic SubSystem: '<S100>/H-p-State with Heat Exchange' */

    /* InitializeConditions for S-Function (th_HpStateHeatExchange_S): '<S102>/S-Function' */

    /* Block: <S102>/S-Function */
    {
      const double *T_initial = (const double*)
        &NACCBraytonCycle2017a_P.HpStatewithHeatExchange_T_ini_p;

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_o = T_initial[0];
        }
      }
    }

    /* End of InitializeConditions for SubSystem: '<S100>/H-p-State with Heat Exchange' */

    /* End of SystemInitialize for SubSystem: '<S100>/H-p-State with Heat Exchange' */

    /* SystemInitialize for IfAction SubSystem: '<S12>/Reservoir' */
    /* SystemInitialize for Outport: '<S153>/nan' */
    NACCBraytonCycle2017a_B.ndot_ka = NACCBraytonCycle2017a_P.nan_Y0_f;

    /* End of SystemInitialize for SubSystem: '<S12>/Reservoir' */

    /* SystemInitialize for Atomic SubSystem: '<S11>/Mixer' */

    /* SystemInitialize for Atomic SubSystem: '<S142>/H-p-State with HeatLoss' */

    /* InitializeConditions for Atomic SubSystem: '<S142>/H-p-State with HeatLoss' */

    /* InitializeConditions for S-Function (th_HpStateHeatExchange_S): '<S145>/S-Function' */

    /* Block: <S145>/S-Function */
    {
      const double *T_initial = (const double*)
        &NACCBraytonCycle2017a_P.HpStatewithHeatLoss_T_initial_b;

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK = T_initial[0];
        }
      }
    }

    /* End of InitializeConditions for SubSystem: '<S142>/H-p-State with HeatLoss' */

    /* End of SystemInitialize for SubSystem: '<S142>/H-p-State with HeatLoss' */

    /* End of SystemInitialize for SubSystem: '<S11>/Mixer' */

    /* SystemInitialize for Atomic SubSystem: '<S57>/H-p-State with Heat Exchange' */

    /* InitializeConditions for Atomic SubSystem: '<S57>/H-p-State with Heat Exchange' */

    /* InitializeConditions for S-Function (th_HpStateHeatExchange_S): '<S58>/S-Function' */

    /* Block: <S58>/S-Function */
    {
      const double *T_initial = (const double*)
        &NACCBraytonCycle2017a_P.HpStatewithHeatExchange_T_initi;

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_j = T_initial[0];
        }
      }
    }

    /* End of InitializeConditions for SubSystem: '<S57>/H-p-State with Heat Exchange' */

    /* End of SystemInitialize for SubSystem: '<S57>/H-p-State with Heat Exchange' */

    /* SystemInitialize for Atomic SubSystem: '<S65>/H-p-State with Heat Exchange' */

    /* InitializeConditions for Atomic SubSystem: '<S65>/H-p-State with Heat Exchange' */

    /* InitializeConditions for S-Function (th_HpStateHeatExchange_S): '<S66>/S-Function' */

    /* Block: <S66>/S-Function */
    {
      const double *T_initial = (const double*)
        &NACCBraytonCycle2017a_P.HpStatewithHeatExchange_T_ini_g;

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_l = T_initial[0];
        }
      }
    }

    /* End of InitializeConditions for SubSystem: '<S65>/H-p-State with Heat Exchange' */

    /* End of SystemInitialize for SubSystem: '<S65>/H-p-State with Heat Exchange' */

    /* SystemInitialize for Atomic SubSystem: '<S124>/S-p-State' */

    /* InitializeConditions for Atomic SubSystem: '<S124>/S-p-State' */

    /* InitializeConditions for S-Function (th_SpState_S): '<S131>/S-Function' */

    /* Block: <S131>/S-Function */
    {
      const double *T_initial = (const double*)
        &NACCBraytonCycle2017a_P.SpState_T_initial_n;

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_m = T_initial[0];
        }
      }
    }

    /* End of InitializeConditions for SubSystem: '<S124>/S-p-State' */

    /* End of SystemInitialize for SubSystem: '<S124>/S-p-State' */

    /* SystemInitialize for Atomic SubSystem: '<S124>/H-p-State with Heat Exchange' */

    /* InitializeConditions for Atomic SubSystem: '<S124>/H-p-State with Heat Exchange' */

    /* InitializeConditions for S-Function (th_HpStateHeatExchange_S): '<S126>/S-Function' */

    /* Block: <S126>/S-Function */
    {
      const double *T_initial = (const double*)
        &NACCBraytonCycle2017a_P.HpStatewithHeatExchange_T_ini_m;

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_a = T_initial[0];
        }
      }
    }

    /* End of InitializeConditions for SubSystem: '<S124>/H-p-State with Heat Exchange' */

    /* End of SystemInitialize for SubSystem: '<S124>/H-p-State with Heat Exchange' */

    /* SystemInitialize for Atomic SubSystem: '<S96>/H-p-State with HeatLoss' */

    /* InitializeConditions for Atomic SubSystem: '<S96>/H-p-State with HeatLoss' */

    /* InitializeConditions for S-Function (th_HpStateHeatExchange_S): '<S97>/S-Function' */

    /* Block: <S97>/S-Function */
    {
      const double *T_initial = (const double*)
        &NACCBraytonCycle2017a_P.HpStatewithHeatLoss_T_initial;

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_h = T_initial[0];
        }
      }
    }

    /* End of InitializeConditions for SubSystem: '<S96>/H-p-State with HeatLoss' */

    /* End of SystemInitialize for SubSystem: '<S96>/H-p-State with HeatLoss' */

    /* SystemInitialize for Atomic SubSystem: '<S120>/H-p-State with HeatLoss' */

    /* InitializeConditions for Atomic SubSystem: '<S120>/H-p-State with HeatLoss' */

    /* InitializeConditions for S-Function (th_HpStateHeatExchange_S): '<S121>/S-Function' */

    /* Block: <S121>/S-Function */
    {
      const double *T_initial = (const double*)
        &NACCBraytonCycle2017a_P.HpStatewithHeatLoss_T_initial_d;

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_n = T_initial[0];
        }
      }
    }

    /* End of InitializeConditions for SubSystem: '<S120>/H-p-State with HeatLoss' */

    /* End of SystemInitialize for SubSystem: '<S120>/H-p-State with HeatLoss' */
  }
}

/* Model terminate function */
static void NACCBraytonCycle2017a_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  NACCBraytonCycle2017a_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  NACCBraytonCycle2017a_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  NACCBraytonCycle2017a_initialize();
}

void MdlTerminate(void)
{
  NACCBraytonCycle2017a_terminate();
}

/* Registration function */
RT_MODEL_NACCBraytonCycle2017_T *NACCBraytonCycle2017a(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  NACCBraytonCycle2017a_P.Saturation_UpperSat = rtInf;
  NACCBraytonCycle2017a_P.Saturation_UpperSat_e = rtInf;
  NACCBraytonCycle2017a_P.Saturation_UpperSat_o = rtInf;
  NACCBraytonCycle2017a_P.Saturation_UpperSat_i = rtInf;
  NACCBraytonCycle2017a_P.p_ratio1_UpperSat = rtInf;
  NACCBraytonCycle2017a_P.Saturation1_LowerSat_ds = rtMinusInf;
  NACCBraytonCycle2017a_P.Saturation_UpperSat_a = rtInf;
  NACCBraytonCycle2017a_P.Saturation_UpperSat_j = rtInf;
  NACCBraytonCycle2017a_P.Saturation1_LowerSat_l = rtMinusInf;
  NACCBraytonCycle2017a_P.Saturation_UpperSat_f = rtInf;
  NACCBraytonCycle2017a_P.Saturation_UpperSat_l = rtInf;
  NACCBraytonCycle2017a_P.calculateconversion_n.Saturation2_UpperSat = rtInf;
  NACCBraytonCycle2017a_P.calculateconversion_n.Saturation2_UpperSat_l = rtInf;
  NACCBraytonCycle2017a_P.calculateconversion.Saturation2_UpperSat = rtInf;
  NACCBraytonCycle2017a_P.calculateconversion.Saturation2_UpperSat_l = rtInf;

  /* initialize real-time model */
  (void) memset((void *)NACCBraytonCycle2017a_M, 0,
                sizeof(RT_MODEL_NACCBraytonCycle2017_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = NACCBraytonCycle2017a_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    NACCBraytonCycle2017a_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    NACCBraytonCycle2017a_M->Timing.sampleTimes =
      (&NACCBraytonCycle2017a_M->Timing.sampleTimesArray[0]);
    NACCBraytonCycle2017a_M->Timing.offsetTimes =
      (&NACCBraytonCycle2017a_M->Timing.offsetTimesArray[0]);

    /* task periods */
    NACCBraytonCycle2017a_M->Timing.sampleTimes[0] = (1.0);

    /* task offsets */
    NACCBraytonCycle2017a_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(NACCBraytonCycle2017a_M, &NACCBraytonCycle2017a_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = NACCBraytonCycle2017a_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    NACCBraytonCycle2017a_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(NACCBraytonCycle2017a_M, -1);
  NACCBraytonCycle2017a_M->Timing.stepSize0 = 1.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    NACCBraytonCycle2017a_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(NACCBraytonCycle2017a_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(NACCBraytonCycle2017a_M->rtwLogInfo, (NULL));
    rtliSetLogT(NACCBraytonCycle2017a_M->rtwLogInfo, "tout");
    rtliSetLogX(NACCBraytonCycle2017a_M->rtwLogInfo, "");
    rtliSetLogXFinal(NACCBraytonCycle2017a_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(NACCBraytonCycle2017a_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(NACCBraytonCycle2017a_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(NACCBraytonCycle2017a_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(NACCBraytonCycle2017a_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &NACCBraytonCycle2017a_Y.Out1,
        &NACCBraytonCycle2017a_Y.Out2,
        &NACCBraytonCycle2017a_Y.Out3,
        &NACCBraytonCycle2017a_Y.Out4,
        &NACCBraytonCycle2017a_Y.Out5,
        &NACCBraytonCycle2017a_Y.Out6,
        &NACCBraytonCycle2017a_Y.Out7,
        &NACCBraytonCycle2017a_Y.Out8,
        &NACCBraytonCycle2017a_Y.Out9,
        &NACCBraytonCycle2017a_Y.Out10,
        &NACCBraytonCycle2017a_Y.Out11,
        &NACCBraytonCycle2017a_Y.Out12,
        &NACCBraytonCycle2017a_Y.Out13,
        &NACCBraytonCycle2017a_Y.Out14,
        &NACCBraytonCycle2017a_Y.Out15,
        &NACCBraytonCycle2017a_Y.Out16,
        &NACCBraytonCycle2017a_Y.Out17,
        &NACCBraytonCycle2017a_Y.Out18,
        &NACCBraytonCycle2017a_Y.Out19,
        &NACCBraytonCycle2017a_Y.Out20,
        &NACCBraytonCycle2017a_Y.Out21,
        &NACCBraytonCycle2017a_Y.Out22,
        &NACCBraytonCycle2017a_Y.Out23,
        &NACCBraytonCycle2017a_Y.Out24,
        &NACCBraytonCycle2017a_Y.Out25,
        &NACCBraytonCycle2017a_Y.Out26,
        &NACCBraytonCycle2017a_Y.Out27,
        &NACCBraytonCycle2017a_Y.Out28
      };

      rtliSetLogYSignalPtrs(NACCBraytonCycle2017a_M->rtwLogInfo,
                            ((LogSignalPtrsType)rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1,
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "NACCBraytonCycle2017a/Out1",
        "NACCBraytonCycle2017a/Out2",
        "NACCBraytonCycle2017a/Out3",
        "NACCBraytonCycle2017a/Out4",
        "NACCBraytonCycle2017a/Out5",
        "NACCBraytonCycle2017a/Out6",
        "NACCBraytonCycle2017a/Out7",
        "NACCBraytonCycle2017a/Out8",
        "NACCBraytonCycle2017a/Out9",
        "NACCBraytonCycle2017a/Out10",
        "NACCBraytonCycle2017a/Out11",
        "NACCBraytonCycle2017a/Out12",
        "NACCBraytonCycle2017a/Out13",
        "NACCBraytonCycle2017a/Out14",
        "NACCBraytonCycle2017a/Out15",
        "NACCBraytonCycle2017a/Out16",
        "NACCBraytonCycle2017a/Out17",
        "NACCBraytonCycle2017a/Out18",
        "NACCBraytonCycle2017a/Out19",
        "NACCBraytonCycle2017a/Out20",
        "NACCBraytonCycle2017a/Out21",
        "NACCBraytonCycle2017a/Out22",
        "NACCBraytonCycle2017a/Out23",
        "NACCBraytonCycle2017a/Out24",
        "NACCBraytonCycle2017a/Out25",
        "NACCBraytonCycle2017a/Out26",
        "NACCBraytonCycle2017a/Out27",
        "NACCBraytonCycle2017a/Out28" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          28,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(NACCBraytonCycle2017a_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
      rt_LoggedCurrentSignalDimensions[2] = &rt_LoggedOutputWidths[2];
      rt_LoggedCurrentSignalDimensions[3] = &rt_LoggedOutputWidths[3];
      rt_LoggedCurrentSignalDimensions[4] = &rt_LoggedOutputWidths[4];
      rt_LoggedCurrentSignalDimensions[5] = &rt_LoggedOutputWidths[5];
      rt_LoggedCurrentSignalDimensions[6] = &rt_LoggedOutputWidths[6];
      rt_LoggedCurrentSignalDimensions[7] = &rt_LoggedOutputWidths[7];
      rt_LoggedCurrentSignalDimensions[8] = &rt_LoggedOutputWidths[8];
      rt_LoggedCurrentSignalDimensions[9] = &rt_LoggedOutputWidths[9];
      rt_LoggedCurrentSignalDimensions[10] = &rt_LoggedOutputWidths[10];
      rt_LoggedCurrentSignalDimensions[11] = &rt_LoggedOutputWidths[11];
      rt_LoggedCurrentSignalDimensions[12] = &rt_LoggedOutputWidths[12];
      rt_LoggedCurrentSignalDimensions[13] = &rt_LoggedOutputWidths[13];
      rt_LoggedCurrentSignalDimensions[14] = &rt_LoggedOutputWidths[14];
      rt_LoggedCurrentSignalDimensions[15] = &rt_LoggedOutputWidths[15];
      rt_LoggedCurrentSignalDimensions[16] = &rt_LoggedOutputWidths[16];
      rt_LoggedCurrentSignalDimensions[17] = &rt_LoggedOutputWidths[17];
      rt_LoggedCurrentSignalDimensions[18] = &rt_LoggedOutputWidths[18];
      rt_LoggedCurrentSignalDimensions[19] = &rt_LoggedOutputWidths[19];
      rt_LoggedCurrentSignalDimensions[20] = &rt_LoggedOutputWidths[20];
      rt_LoggedCurrentSignalDimensions[21] = &rt_LoggedOutputWidths[21];
      rt_LoggedCurrentSignalDimensions[22] = &rt_LoggedOutputWidths[22];
      rt_LoggedCurrentSignalDimensions[23] = &rt_LoggedOutputWidths[23];
      rt_LoggedCurrentSignalDimensions[24] = &rt_LoggedOutputWidths[24];
      rt_LoggedCurrentSignalDimensions[25] = &rt_LoggedOutputWidths[25];
      rt_LoggedCurrentSignalDimensions[26] = &rt_LoggedOutputWidths[26];
      rt_LoggedCurrentSignalDimensions[27] = &rt_LoggedOutputWidths[27];
    }

    rtliSetLogY(NACCBraytonCycle2017a_M->rtwLogInfo, "yout");
  }

  NACCBraytonCycle2017a_M->solverInfoPtr = (&NACCBraytonCycle2017a_M->solverInfo);
  NACCBraytonCycle2017a_M->Timing.stepSize = (1.0);
  rtsiSetFixedStepSize(&NACCBraytonCycle2017a_M->solverInfo, 1.0);
  rtsiSetSolverMode(&NACCBraytonCycle2017a_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  NACCBraytonCycle2017a_M->blockIO = ((void *) &NACCBraytonCycle2017a_B);
  (void) memset(((void *) &NACCBraytonCycle2017a_B), 0,
                sizeof(B_NACCBraytonCycle2017a_T));

  {
    int32_T i;
    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_e[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_h[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_o[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_a[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_c[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.SFunction1_o1[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.SFunction1_o1_i[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_cv[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.MultiportSwitch1[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_b[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_j[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_h[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_o[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_cu[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_k[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_m[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_ac[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_a[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_d[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_l[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_dg[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_i[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_f[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_f[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_da[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_ip[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.SFunction1_o1_c[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_p[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_g[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_ju[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_al[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_i[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_p[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_il[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_j[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.x_g[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.psi_eg[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.SFunction1_o1_n[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.SFunction1_o1_o[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.calculateconversion_n.Product6[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_B.calculateconversion.Product6[i] = 0.0;
    }

    NACCBraytonCycle2017a_B.UnitOffset = 0.0;
    NACCBraytonCycle2017a_B.UnitOffset_h = 0.0;
    NACCBraytonCycle2017a_B.ndot = 0.0;
    NACCBraytonCycle2017a_B.Product1 = 0.0;
    NACCBraytonCycle2017a_B.p2 = 0.0;
    NACCBraytonCycle2017a_B.Sum2 = 0.0;
    NACCBraytonCycle2017a_B.Switch2 = 0.0;
    NACCBraytonCycle2017a_B.MultiportSwitch = 0.0;
    NACCBraytonCycle2017a_B.ndot_k = 0.0;
    NACCBraytonCycle2017a_B.T = 0.0;
    NACCBraytonCycle2017a_B.p = 0.0;
    NACCBraytonCycle2017a_B.Hdot = 0.0;
    NACCBraytonCycle2017a_B.Sdot = 0.0;
    NACCBraytonCycle2017a_B.Gdot = 0.0;
    NACCBraytonCycle2017a_B.Cpdot = 0.0;
    NACCBraytonCycle2017a_B.Subtract2 = 0.0;
    NACCBraytonCycle2017a_B.UnitOffset_l = 0.0;
    NACCBraytonCycle2017a_B.UnitOffset_f = 0.0;
    NACCBraytonCycle2017a_B.ndot_ka = 0.0;
    NACCBraytonCycle2017a_B.Product = 0.0;
    NACCBraytonCycle2017a_B.Saturation = 0.0;
    NACCBraytonCycle2017a_B.Product_a = 0.0;
    NACCBraytonCycle2017a_B.Saturation_l = 0.0;
    NACCBraytonCycle2017a_B.Switch2_n = 0.0;
    NACCBraytonCycle2017a_B.MultiportSwitch_h = 0.0;
    NACCBraytonCycle2017a_B.ndot_i = 0.0;
    NACCBraytonCycle2017a_B.T_e = 0.0;
    NACCBraytonCycle2017a_B.p_c = 0.0;
    NACCBraytonCycle2017a_B.Hdot_h = 0.0;
    NACCBraytonCycle2017a_B.Sdot_e = 0.0;
    NACCBraytonCycle2017a_B.Gdot_h = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_d = 0.0;
    NACCBraytonCycle2017a_B.Subtract2_o = 0.0;
    NACCBraytonCycle2017a_B.Saturation_p = 0.0;
    NACCBraytonCycle2017a_B.Sum7 = 0.0;
    NACCBraytonCycle2017a_B.Saturation_lg = 0.0;
    NACCBraytonCycle2017a_B.Sum7_h = 0.0;
    NACCBraytonCycle2017a_B.T_c = 0.0;
    NACCBraytonCycle2017a_B.Hdot_c = 0.0;
    NACCBraytonCycle2017a_B.Sdot_k = 0.0;
    NACCBraytonCycle2017a_B.Gdot_j = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_j = 0.0;
    NACCBraytonCycle2017a_B.SFunction_o1 = 0.0;
    NACCBraytonCycle2017a_B.SFunction_o2 = 0.0;
    NACCBraytonCycle2017a_B.SFunction_o3 = 0.0;
    NACCBraytonCycle2017a_B.p_h = 0.0;
    NACCBraytonCycle2017a_B.Add3 = 0.0;
    NACCBraytonCycle2017a_B.ndot_o = 0.0;
    NACCBraytonCycle2017a_B.Saturation_f = 0.0;
    NACCBraytonCycle2017a_B.T_g = 0.0;
    NACCBraytonCycle2017a_B.Hdot_h5 = 0.0;
    NACCBraytonCycle2017a_B.Sdot_l = 0.0;
    NACCBraytonCycle2017a_B.Gdot_n = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_i = 0.0;
    NACCBraytonCycle2017a_B.Sum6 = 0.0;
    NACCBraytonCycle2017a_B.ndot_m = 0.0;
    NACCBraytonCycle2017a_B.T_go = 0.0;
    NACCBraytonCycle2017a_B.p_p = 0.0;
    NACCBraytonCycle2017a_B.Hdot_cl = 0.0;
    NACCBraytonCycle2017a_B.Sdot_ex = 0.0;
    NACCBraytonCycle2017a_B.Gdot_k = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_l = 0.0;
    NACCBraytonCycle2017a_B.Qenv = 0.0;
    NACCBraytonCycle2017a_B.num_iterations = 0.0;
    NACCBraytonCycle2017a_B.ndot_b = 0.0;
    NACCBraytonCycle2017a_B.T_n = 0.0;
    NACCBraytonCycle2017a_B.p_pc = 0.0;
    NACCBraytonCycle2017a_B.Hdot_d = 0.0;
    NACCBraytonCycle2017a_B.Sdot_k0 = 0.0;
    NACCBraytonCycle2017a_B.Gdot_km = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_e = 0.0;
    NACCBraytonCycle2017a_B.iter = 0.0;
    NACCBraytonCycle2017a_B.ndot_c = 0.0;
    NACCBraytonCycle2017a_B.T_p = 0.0;
    NACCBraytonCycle2017a_B.p_a = 0.0;
    NACCBraytonCycle2017a_B.Hdot_o = 0.0;
    NACCBraytonCycle2017a_B.Sdot_m = 0.0;
    NACCBraytonCycle2017a_B.Gdot_b = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_g = 0.0;
    NACCBraytonCycle2017a_B.Qenv_p = 0.0;
    NACCBraytonCycle2017a_B.num_iterations_a = 0.0;
    NACCBraytonCycle2017a_B.ndot_ol = 0.0;
    NACCBraytonCycle2017a_B.T_ed = 0.0;
    NACCBraytonCycle2017a_B.p_a5 = 0.0;
    NACCBraytonCycle2017a_B.Hdot_i = 0.0;
    NACCBraytonCycle2017a_B.Sdot_c = 0.0;
    NACCBraytonCycle2017a_B.Gdot_m = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_p = 0.0;
    NACCBraytonCycle2017a_B.Qenv_k = 0.0;
    NACCBraytonCycle2017a_B.num_iterations_f = 0.0;
    NACCBraytonCycle2017a_B.ndot_n = 0.0;
    NACCBraytonCycle2017a_B.T_m = 0.0;
    NACCBraytonCycle2017a_B.p_n = 0.0;
    NACCBraytonCycle2017a_B.Hdot_j = 0.0;
    NACCBraytonCycle2017a_B.Sdot_kk = 0.0;
    NACCBraytonCycle2017a_B.Gdot_hm = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_c = 0.0;
    NACCBraytonCycle2017a_B.iter_n = 0.0;
    NACCBraytonCycle2017a_B.ndot_nq = 0.0;
    NACCBraytonCycle2017a_B.T_h = 0.0;
    NACCBraytonCycle2017a_B.p_g = 0.0;
    NACCBraytonCycle2017a_B.Hdot_n = 0.0;
    NACCBraytonCycle2017a_B.Sdot_f = 0.0;
    NACCBraytonCycle2017a_B.Gdot_l = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_a = 0.0;
    NACCBraytonCycle2017a_B.Qenv_n = 0.0;
    NACCBraytonCycle2017a_B.num_iterations_d = 0.0;
    NACCBraytonCycle2017a_B.ndot_bl = 0.0;
    NACCBraytonCycle2017a_B.T_gf = 0.0;
    NACCBraytonCycle2017a_B.p_a1 = 0.0;
    NACCBraytonCycle2017a_B.Hdot_b = 0.0;
    NACCBraytonCycle2017a_B.Sdot_n = 0.0;
    NACCBraytonCycle2017a_B.Gdot_f = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_aq = 0.0;
    NACCBraytonCycle2017a_B.Qenv_d = 0.0;
    NACCBraytonCycle2017a_B.num_iterations_j = 0.0;
    NACCBraytonCycle2017a_B.ndot_c0 = 0.0;
    NACCBraytonCycle2017a_B.p_f = 0.0;
    NACCBraytonCycle2017a_B.Hdot_du = 0.0;
    NACCBraytonCycle2017a_B.Sdot_d = 0.0;
    NACCBraytonCycle2017a_B.Gdot_fo = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_i4 = 0.0;
    NACCBraytonCycle2017a_B.ndot_f = 0.0;
    NACCBraytonCycle2017a_B.T_d = 0.0;
    NACCBraytonCycle2017a_B.p_gc = 0.0;
    NACCBraytonCycle2017a_B.Hdot_e = 0.0;
    NACCBraytonCycle2017a_B.Sdot_a = 0.0;
    NACCBraytonCycle2017a_B.Gdot_c = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_b = 0.0;
    NACCBraytonCycle2017a_B.iter_j = 0.0;
    NACCBraytonCycle2017a_B.ndot_l = 0.0;
    NACCBraytonCycle2017a_B.T_j = 0.0;
    NACCBraytonCycle2017a_B.p_b = 0.0;
    NACCBraytonCycle2017a_B.Hdot_jv = 0.0;
    NACCBraytonCycle2017a_B.Sdot_p = 0.0;
    NACCBraytonCycle2017a_B.Gdot_l1 = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_h = 0.0;
    NACCBraytonCycle2017a_B.Qenv_b = 0.0;
    NACCBraytonCycle2017a_B.num_iterations_n = 0.0;
    NACCBraytonCycle2017a_B.ndot_oo = 0.0;
    NACCBraytonCycle2017a_B.T_mo = 0.0;
    NACCBraytonCycle2017a_B.p_k = 0.0;
    NACCBraytonCycle2017a_B.Hdot_jo = 0.0;
    NACCBraytonCycle2017a_B.Sdot_o = 0.0;
    NACCBraytonCycle2017a_B.Gdot_g = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_az = 0.0;
    NACCBraytonCycle2017a_B.Qenv_pj = 0.0;
    NACCBraytonCycle2017a_B.num_iterations_fx = 0.0;
    NACCBraytonCycle2017a_B.ndot_f2 = 0.0;
    NACCBraytonCycle2017a_B.T_h3 = 0.0;
    NACCBraytonCycle2017a_B.p_nt = 0.0;
    NACCBraytonCycle2017a_B.Hdot_ig = 0.0;
    NACCBraytonCycle2017a_B.Sdot_fv = 0.0;
    NACCBraytonCycle2017a_B.Gdot_mk = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_eg = 0.0;
    NACCBraytonCycle2017a_B.Qenv_f = 0.0;
    NACCBraytonCycle2017a_B.num_iterations_h = 0.0;
    NACCBraytonCycle2017a_B.ndot_lp = 0.0;
    NACCBraytonCycle2017a_B.T_gw = 0.0;
    NACCBraytonCycle2017a_B.p_d = 0.0;
    NACCBraytonCycle2017a_B.Hdot_a = 0.0;
    NACCBraytonCycle2017a_B.Sdot_c0 = 0.0;
    NACCBraytonCycle2017a_B.Gdot_ny = 0.0;
    NACCBraytonCycle2017a_B.Cpdot_f = 0.0;
    NACCBraytonCycle2017a_B.SFunction_o1_j = 0.0;
    NACCBraytonCycle2017a_B.SFunction_o2_f = 0.0;
    NACCBraytonCycle2017a_B.SFunction_o3_o = 0.0;
    NACCBraytonCycle2017a_B.ndot_nc = 0.0;
    NACCBraytonCycle2017a_B.p_pg = 0.0;
    NACCBraytonCycle2017a_B.calculateconversion_n.Subtract5 = 0.0;
    NACCBraytonCycle2017a_B.calculateconversion.Subtract5 = 0.0;
  }

  /* parameters */
  NACCBraytonCycle2017a_M->defaultParam = ((real_T *)&NACCBraytonCycle2017a_P);

  /* states (dwork) */
  NACCBraytonCycle2017a_M->dwork = ((void *) &NACCBraytonCycle2017a_DW);
  (void) memset((void *)&NACCBraytonCycle2017a_DW, 0,
                sizeof(DW_NACCBraytonCycle2017a_T));
  NACCBraytonCycle2017a_DW.Memory1_PreviousInput[0] = 0.0;
  NACCBraytonCycle2017a_DW.Memory1_PreviousInput[1] = 0.0;
  NACCBraytonCycle2017a_DW.Memory1_PreviousInput[2] = 0.0;
  NACCBraytonCycle2017a_DW.Memory1_PreviousInput[3] = 0.0;
  NACCBraytonCycle2017a_DW.Memory_PreviousInput = 0.0;
  NACCBraytonCycle2017a_DW.Memory9_PreviousInput = 0.0;

  {
    int32_T i;
    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_DW.Memory4_PreviousInput[i] = 0.0;
    }
  }

  NACCBraytonCycle2017a_DW.Memory1_PreviousInput_b = 0.0;
  NACCBraytonCycle2017a_DW.Memory2_PreviousInput = 0.0;
  NACCBraytonCycle2017a_DW.Memory3_PreviousInput = 0.0;

  {
    int32_T i;
    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_DW.Memory8_PreviousInput[i] = 0.0;
    }
  }

  NACCBraytonCycle2017a_DW.Memory9_PreviousInput_a = 0.0;

  {
    int32_T i;
    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_DW.Memory4_PreviousInput_p[i] = 0.0;
    }
  }

  NACCBraytonCycle2017a_DW.Memory1_PreviousInput_p = 0.0;
  NACCBraytonCycle2017a_DW.Memory2_PreviousInput_o = 0.0;
  NACCBraytonCycle2017a_DW.Memory3_PreviousInput_d = 0.0;

  {
    int32_T i;
    for (i = 0; i < 7; i++) {
      NACCBraytonCycle2017a_DW.Memory8_PreviousInput_p[i] = 0.0;
    }
  }

  NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK = 0.0;
  NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_m = 0.0;
  NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_a = 0.0;
  NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_n = 0.0;
  NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_f = 0.0;
  NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_o = 0.0;
  NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_h = 0.0;
  NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_mu = 0.0;
  NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_p = 0.0;
  NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_l = 0.0;
  NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_j = 0.0;

  /* external inputs */
  NACCBraytonCycle2017a_M->inputs = (((void*)&NACCBraytonCycle2017a_U));
  NACCBraytonCycle2017a_U.In1 = 0.0;
  NACCBraytonCycle2017a_U.In2 = 0.0;
  NACCBraytonCycle2017a_U.In3 = 0.0;
  NACCBraytonCycle2017a_U.In4 = 0.0;
  NACCBraytonCycle2017a_U.In5 = 0.0;
  NACCBraytonCycle2017a_U.In6 = 0.0;
  NACCBraytonCycle2017a_U.In7 = 0.0;
  NACCBraytonCycle2017a_U.In8 = 0.0;
  NACCBraytonCycle2017a_U.In9 = 0.0;
  NACCBraytonCycle2017a_U.In10 = 0.0;
  NACCBraytonCycle2017a_U.In11 = 0.0;

  /* external outputs */
  NACCBraytonCycle2017a_M->outputs = (&NACCBraytonCycle2017a_Y);
  NACCBraytonCycle2017a_Y.Out1 = 0.0;
  NACCBraytonCycle2017a_Y.Out2 = 0.0;
  NACCBraytonCycle2017a_Y.Out3 = 0.0;
  NACCBraytonCycle2017a_Y.Out4 = 0.0;
  NACCBraytonCycle2017a_Y.Out5 = 0.0;
  NACCBraytonCycle2017a_Y.Out6 = 0.0;
  NACCBraytonCycle2017a_Y.Out7 = 0.0;
  NACCBraytonCycle2017a_Y.Out8 = 0.0;
  NACCBraytonCycle2017a_Y.Out9 = 0.0;
  NACCBraytonCycle2017a_Y.Out10 = 0.0;
  NACCBraytonCycle2017a_Y.Out11 = 0.0;
  NACCBraytonCycle2017a_Y.Out12 = 0.0;
  NACCBraytonCycle2017a_Y.Out13 = 0.0;
  NACCBraytonCycle2017a_Y.Out14 = 0.0;
  NACCBraytonCycle2017a_Y.Out15 = 0.0;
  NACCBraytonCycle2017a_Y.Out16 = 0.0;
  NACCBraytonCycle2017a_Y.Out17 = 0.0;
  NACCBraytonCycle2017a_Y.Out18 = 0.0;
  NACCBraytonCycle2017a_Y.Out19 = 0.0;
  NACCBraytonCycle2017a_Y.Out20 = 0.0;
  NACCBraytonCycle2017a_Y.Out21 = 0.0;
  NACCBraytonCycle2017a_Y.Out22 = 0.0;
  NACCBraytonCycle2017a_Y.Out23 = 0.0;
  NACCBraytonCycle2017a_Y.Out24 = 0.0;
  NACCBraytonCycle2017a_Y.Out25 = 0.0;
  NACCBraytonCycle2017a_Y.Out26 = 0.0;
  NACCBraytonCycle2017a_Y.Out27 = 0.0;
  NACCBraytonCycle2017a_Y.Out28 = 0.0;

  /* Initialize Sizes */
  NACCBraytonCycle2017a_M->Sizes.numContStates = (0);/* Number of continuous states */
  NACCBraytonCycle2017a_M->Sizes.numY = (28);/* Number of model outputs */
  NACCBraytonCycle2017a_M->Sizes.numU = (11);/* Number of model inputs */
  NACCBraytonCycle2017a_M->Sizes.sysDirFeedThru = (1);/* The model is direct feedthrough */
  NACCBraytonCycle2017a_M->Sizes.numSampTimes = (1);/* Number of sample times */
  NACCBraytonCycle2017a_M->Sizes.numBlocks = (621);/* Number of blocks */
  NACCBraytonCycle2017a_M->Sizes.numBlockIO = (238);/* Number of block outputs */
  NACCBraytonCycle2017a_M->Sizes.numBlockPrms = (12738);/* Sum of parameter "widths" */
  return NACCBraytonCycle2017a_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : NACCBraytonCycle2017a
 * Model version : 1.139
 * VeriStand Model Framework version : 2018.0.0.81 (2018)
 * Source generated on : Thu Mar 14 16:45:13 2019
 *========================================================================*/

/* This file contains automatically generated code for functions
 * to update the inports and outports of a Simulink/Realtime Workshop
 * model. Calls to these functions should be made before each step is taken
 * (inports, call SetExternalInputs) and after each step is taken
 * (outports, call SetExternalOutputs.)
 */
#ifdef NI_ROOTMODEL_NACCBraytonCycle2017a
#include "ni_modelframework_ex.h"
#include <stddef.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

unsigned char ReadSideDirtyFlag = 0, WriteSideDirtyFlag = 0;

/*========================================================================*
 * Function: NIRT_GetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the source
 *      subindex : index value if vector
 *      type   : the source's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
double NIRT_GetValueByDataType(void* ptr, int32_t subindex, int32_t type,
  int32_t Complex)
{
  switch (type)
  {
   case 0:
    return (double)(((real_T*)ptr)[subindex]);

   case 1:
    return (double)(((real32_T*)ptr)[subindex]);

   case 2:
    return (double)(((int8_T*)ptr)[subindex]);

   case 3:
    return (double)(((uint8_T*)ptr)[subindex]);

   case 4:
    return (double)(((int16_T*)ptr)[subindex]);

   case 5:
    return (double)(((uint16_T*)ptr)[subindex]);

   case 6:
    return (double)(((int32_T*)ptr)[subindex]);

   case 7:
    return (double)(((uint32_T*)ptr)[subindex]);

   case 8:
    return (double)(((boolean_T*)ptr)[subindex]);

   case 10:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 13:
    return NIRT_GetValueByDataType(ptr,subindex,7,Complex);

   case 14:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 15:
    return (( double *)ptr)[subindex];

   case 16:
    return (( double *)ptr)[subindex];

   case 18:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 19:
    return NIRT_GetValueByDataType(ptr,subindex,6,Complex);

   case 20:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 21:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 22:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 23:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 24:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 25:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 26:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 27:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 28:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 29:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 30:
    return NIRT_GetValueByDataType(ptr,subindex,11,Complex);

   case 31:
    return NIRT_GetValueByDataType(ptr,subindex,3,Complex);

   case 32:
    return NIRT_GetValueByDataType(ptr,subindex,8,Complex);

   case 33:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 34:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 37:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 38:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 39:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 40:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 41:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 42:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 43:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 44:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 45:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 46:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 47:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 48:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 49:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 50:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 51:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 52:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 53:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 54:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 55:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 56:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 58:
    return (( double *)ptr)[subindex];

   case 59:
    return (( double *)ptr)[subindex];

   case 60:
    return (( double *)ptr)[subindex];

   case 61:
    return (( double *)ptr)[subindex];

   case 62:
    return (( double *)ptr)[subindex];

   case 63:
    return (( double *)ptr)[subindex];

   case 64:
    return (( double *)ptr)[subindex];

   case 65:
    return (( double *)ptr)[subindex];

   case 66:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);

   case 67:
    return NIRT_GetValueByDataType(ptr,subindex,0,Complex);
  }

  // return ((double *)ptr)[subindex];
  return rtNaN;
}

/*========================================================================*
 * Function: NIRT_SetValueByDataType
 *
 * Abstract:
 *		Converting to and from double and datatypes used in the model
 *
 * Output Parameters
 *      ptr : address to the destination
 *      subindex : index value if vector
 *      value : value to set on the destination
 *      type   : the destination's data type
 *      Complex : true if a complex data type
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NIRT_SetValueByDataType(void* ptr, int32_t subindex, double value,
  int32_t type, int32_t Complex)
{
  //Complex is only used for R14.3 and down
  switch (type)
  {
   case 0:
    ((real_T *)ptr)[subindex] = (real_T)value;
    return NI_OK;

   case 1:
    ((real32_T *)ptr)[subindex] = (real32_T)value;
    return NI_OK;

   case 2:
    ((int8_T *)ptr)[subindex] = (int8_T)value;
    return NI_OK;

   case 3:
    ((uint8_T *)ptr)[subindex] = (uint8_T)value;
    return NI_OK;

   case 4:
    ((int16_T *)ptr)[subindex] = (int16_T)value;
    return NI_OK;

   case 5:
    ((uint16_T *)ptr)[subindex] = (uint16_T)value;
    return NI_OK;

   case 6:
    ((int32_T *)ptr)[subindex] = (int32_T)value;
    return NI_OK;

   case 7:
    ((uint32_T *)ptr)[subindex] = (uint32_T)value;
    return NI_OK;

   case 8:
    ((boolean_T *)ptr)[subindex] = (boolean_T)value;
    return NI_OK;

   case 10:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 13:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 7, Complex);

   case 14:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 18:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 19:
    //Type is enum. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 6, Complex);

   case 20:
    //Type is renamed. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 21:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 22:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 23:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 24:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 25:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 26:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 27:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 28:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 29:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 30:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 11, Complex);

   case 31:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 3, Complex);

   case 32:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 8, Complex);

   case 33:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 34:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 37:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 38:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 39:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 40:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 41:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 42:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 43:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 44:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 45:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 46:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 47:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 48:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 49:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 50:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 51:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 52:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 53:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 54:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 55:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 56:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 66:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);

   case 67:
    //Type is matrix. Call SetValueByDataType on its contained type
    return NIRT_SetValueByDataType(ptr, subindex, value, 0, Complex);
  }

  //No matching datatype conversion
  return NI_ERROR;
}

extern NACCBraytonCycle2017a_rtModel *S;
extern _SITexportglobals SITexportglobals;

/*========================================================================*
 * Function: SetExternalInputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalInputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;
  ExtU_NACCBraytonCycle2017a_T *rtIN = (ExtU_NACCBraytonCycle2017a_T*) S->inputs;
  if (TaskSampleHit[0]) {              // sample and hold
    /* rtIN->In1 Type real_T -> 0 Width [1, 1] */
    NIRT_SetValueByDataType(&rtIN->In1, 0, data[index++], 0, 0);
  } else {                             // hold this input--skip over it in the input buffer
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtIN->In2 Type real_T -> 0 Width [1, 1] */
    NIRT_SetValueByDataType(&rtIN->In2, 0, data[index++], 0, 0);
  } else {                             // hold this input--skip over it in the input buffer
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtIN->In3 Type real_T -> 0 Width [1, 1] */
    NIRT_SetValueByDataType(&rtIN->In3, 0, data[index++], 0, 0);
  } else {                             // hold this input--skip over it in the input buffer
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtIN->In4 Type real_T -> 0 Width [1, 1] */
    NIRT_SetValueByDataType(&rtIN->In4, 0, data[index++], 0, 0);
  } else {                             // hold this input--skip over it in the input buffer
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtIN->In5 Type real_T -> 0 Width [1, 1] */
    NIRT_SetValueByDataType(&rtIN->In5, 0, data[index++], 0, 0);
  } else {                             // hold this input--skip over it in the input buffer
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtIN->In6 Type real_T -> 0 Width [1, 1] */
    NIRT_SetValueByDataType(&rtIN->In6, 0, data[index++], 0, 0);
  } else {                             // hold this input--skip over it in the input buffer
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtIN->In7 Type real_T -> 0 Width [1, 1] */
    NIRT_SetValueByDataType(&rtIN->In7, 0, data[index++], 0, 0);
  } else {                             // hold this input--skip over it in the input buffer
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtIN->In8 Type real_T -> 0 Width [1, 1] */
    NIRT_SetValueByDataType(&rtIN->In8, 0, data[index++], 0, 0);
  } else {                             // hold this input--skip over it in the input buffer
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtIN->In9 Type real_T -> 0 Width [1, 1] */
    NIRT_SetValueByDataType(&rtIN->In9, 0, data[index++], 0, 0);
  } else {                             // hold this input--skip over it in the input buffer
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtIN->In10 Type real_T -> 0 Width [1, 1] */
    NIRT_SetValueByDataType(&rtIN->In10, 0, data[index++], 0, 0);
  } else {                             // hold this input--skip over it in the input buffer
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtIN->In11 Type real_T -> 0 Width [1, 1] */
    NIRT_SetValueByDataType(&rtIN->In11, 0, data[index++], 0, 0);
  } else {                             // hold this input--skip over it in the input buffer
    index += 1;
  }

  UNUSED_PARAMETER(count);
}                                      /* of SetExternalInputs */

int32_t NumInputPorts(void)
{
  return 11;
}

int32_t NumOutputPorts(void)
{
  return 28;
}

double ni_extout[28];

/*========================================================================*
 * Function: SetExternalOutputs
 *
 * Abstract:
 *		Set data to model ports on the specified task
 *
 * Input Parameters
 *      data : data to set
 *      TaskSampleHit : task id
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
void SetExternalOutputs(double* data, int_T* TaskSampleHit)
{
  int index = 0, count = 0;
  ExtY_NACCBraytonCycle2017a_T* rtOUT = (ExtY_NACCBraytonCycle2017a_T*)
    S->outputs;
  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out1 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out1), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out2 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out2), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out3 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out3), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out4 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out4), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out5 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out5), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out6 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out6), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out7 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out7), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out8 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out8), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out9 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out9), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out10 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out10), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out11 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out11), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out12 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out12), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out13 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out13), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out14 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out14), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out15 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out15), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out16 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out16), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out17 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out17), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out18 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out18), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out19 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out19), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out20 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out20), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out21 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out21), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out22 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out22), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out23 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out23), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out24 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out24), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out25 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out25), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out26 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out26), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out27 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out27), 0, 0, 0);
  } else {
    index += 1;
  }

  if (TaskSampleHit[0]) {              // sample and hold
    /* rtOUT->Out28 has width [1, 1] type real_T -> 0 */
    ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out28), 0, 0, 0);
  } else {
    index += 1;
  }

  if (data != NULL) {
    memcpy(&data[0], &ni_extout[0], sizeof(ni_extout));
  }

  UNUSED_PARAMETER(count);
}

/*========================================================================*
 * Function: NI_InitExternalOutputs
 *
 * Abstract:
 *		Initialize model ports
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: 0 if no error
 *========================================================================*/
int32_t NI_InitExternalOutputs()
{
  int index = 0, count = 0;
  ExtY_NACCBraytonCycle2017a_T* rtOUT = (ExtY_NACCBraytonCycle2017a_T*)
    S->outputs;

  /* rtOUT->Out1 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out1), 0, 0, 0);

  /* rtOUT->Out2 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out2), 0, 0, 0);

  /* rtOUT->Out3 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out3), 0, 0, 0);

  /* rtOUT->Out4 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out4), 0, 0, 0);

  /* rtOUT->Out5 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out5), 0, 0, 0);

  /* rtOUT->Out6 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out6), 0, 0, 0);

  /* rtOUT->Out7 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out7), 0, 0, 0);

  /* rtOUT->Out8 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out8), 0, 0, 0);

  /* rtOUT->Out9 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out9), 0, 0, 0);

  /* rtOUT->Out10 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out10), 0, 0, 0);

  /* rtOUT->Out11 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out11), 0, 0, 0);

  /* rtOUT->Out12 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out12), 0, 0, 0);

  /* rtOUT->Out13 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out13), 0, 0, 0);

  /* rtOUT->Out14 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out14), 0, 0, 0);

  /* rtOUT->Out15 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out15), 0, 0, 0);

  /* rtOUT->Out16 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out16), 0, 0, 0);

  /* rtOUT->Out17 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out17), 0, 0, 0);

  /* rtOUT->Out18 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out18), 0, 0, 0);

  /* rtOUT->Out19 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out19), 0, 0, 0);

  /* rtOUT->Out20 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out20), 0, 0, 0);

  /* rtOUT->Out21 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out21), 0, 0, 0);

  /* rtOUT->Out22 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out22), 0, 0, 0);

  /* rtOUT->Out23 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out23), 0, 0, 0);

  /* rtOUT->Out24 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out24), 0, 0, 0);

  /* rtOUT->Out25 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out25), 0, 0, 0);

  /* rtOUT->Out26 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out26), 0, 0, 0);

  /* rtOUT->Out27 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out27), 0, 0, 0);

  /* rtOUT->Out28 has width 1 -> [1, 1] type 0 -> 0 */
  ni_extout[index++] = NIRT_GetValueByDataType(&(rtOUT->Out28), 0, 0, 0);
  UNUSED_PARAMETER(count);
  return NI_OK;
}

/* Undefine parameter macros. The undef allows us to access the real declarations.
   In the Simulink(R) generated code, the parameters are redefined to be the read-side of rtParameter.*/
#define _NI_UNDEFINE_PARAMS_DBL_BUFFER_
#include "ni_pglobals.h"

/* All elements by default (including scalars) have 2 dimensions [1,1] */
static NI_Parameter NI_ParamList[] DataSection(".NIVS.paramlist") =
{
  { 0,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P25",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_HM_CONV_LIMIT), 0, 1,
    2, 0, 0 },

  { 1,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P25",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_HM_CONV_LIMIT), 0, 1,
    2, 2, 0 },

  { 2,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P25",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_HM_CONV_LIMIT), 0, 1,
    2, 4, 0 },

  { 3,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P25",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_HM_CONV_LIMIT), 0, 1,
    2, 6, 0 },

  { 4,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P25",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_HM_CONV_LIMIT), 0, 1,
    2, 8, 0 },

  { 5,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P25",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_HM_CONV_LIMIT), 0, 1,
    2, 10, 0 },

  { 6,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P25",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_HM_CONV_LIMIT), 0, 1,
    2, 12, 0 },

  { 7,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P25",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_HM_CONV_LIMIT), 0, 1,
    2, 14, 0 },

  { 8,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P26",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_NUM_ITER_MAX), 0, 1,
    2, 16, 0 },

  { 9,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P26",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_NUM_ITER_MAX), 0, 1,
    2, 18, 0 },

  { 10,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P26",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_NUM_ITER_MAX), 0, 1,
    2, 20, 0 },

  { 11,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P26",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_NUM_ITER_MAX), 0, 1,
    2, 22, 0 },

  { 12,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P26",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_NUM_ITER_MAX), 0, 1,
    2, 24, 0 },

  { 13,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P26",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_NUM_ITER_MAX), 0, 1,
    2, 26, 0 },

  { 14,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P26",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_NUM_ITER_MAX), 0, 1,
    2, 28, 0 },

  { 15,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P26",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_NUM_ITER_MAX), 0, 1,
    2, 30, 0 },

  { 16,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P24",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_T_CONV_LIMIT), 0, 1,
    2, 32, 0 },

  { 17,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P24",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_T_CONV_LIMIT), 0, 1,
    2, 34, 0 },

  { 18,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P24",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_T_CONV_LIMIT), 0, 1,
    2, 36, 0 },

  { 19,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P24",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_T_CONV_LIMIT), 0, 1,
    2, 38, 0 },

  { 20,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P24",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_T_CONV_LIMIT), 0, 1,
    2, 40, 0 },

  { 21,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P24",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_T_CONV_LIMIT), 0, 1,
    2, 42, 0 },

  { 22,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P24",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_T_CONV_LIMIT), 0, 1,
    2, 44, 0 },

  { 23,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P24",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_H_P_STATE_T_CONV_LIMIT), 0, 1,
    2, 46, 0 },

  { 24,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P27",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_NDOT_MIN), 0, 1, 2, 48, 0 },

  { 25,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P27",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_NDOT_MIN), 0, 1, 2, 50, 0 },

  { 26,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P27",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_NDOT_MIN), 0, 1, 2, 52, 0 },

  { 27,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P24",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_NDOT_MIN), 0, 1, 2, 54, 0 },

  { 28,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P27",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_NDOT_MIN), 0, 1, 2, 56, 0 },

  { 29, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P24",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_NDOT_MIN), 0, 1, 2, 58, 0 },

  { 30,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P27",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_NDOT_MIN), 0, 1, 2, 60, 0 },

  { 31, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P24",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_NDOT_MIN), 0, 1, 2, 62, 0 },

  { 32,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P27",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_NDOT_MIN), 0, 1, 2, 64, 0 },

  { 33,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P27",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_NDOT_MIN), 0, 1, 2, 66, 0 },

  { 34,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P27",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_NDOT_MIN), 0, 1, 2, 68, 0 },

  { 35,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P23",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_S_P_STATE_NUM_ITER_MAX), 0, 1,
    2, 70, 0 },

  { 36, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P23",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_S_P_STATE_NUM_ITER_MAX), 0, 1,
    2, 72, 0 },

  { 37, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P23",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_S_P_STATE_NUM_ITER_MAX), 0, 1,
    2, 74, 0 },

  { 38,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P22",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_S_P_STATE_SM_CONV_LIMIT), 0, 1,
    2, 76, 0 },

  { 39, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P22",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_S_P_STATE_SM_CONV_LIMIT), 0, 1,
    2, 78, 0 },

  { 40, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P22",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_S_P_STATE_SM_CONV_LIMIT), 0, 1,
    2, 80, 0 },

  { 41,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P21",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_S_P_STATE_T_CONV_LIMIT), 0, 1,
    2, 82, 0 },

  { 42, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P21",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_S_P_STATE_T_CONV_LIMIT), 0, 1,
    2, 84, 0 },

  { 43, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P21",
    offsetof(P_NACCBraytonCycle2017a_T, TH_THERM_S_P_STATE_T_CONV_LIMIT), 0, 1,
    2, 86, 0 },

  { 44,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 88, 0 },

  { 45,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P23",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 90, 0 },

  { 46,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 92, 0 },

  { 47,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 94, 0 },

  { 48,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 96, 0 },

  { 49,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 98, 0 },

  { 50,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 100, 0 },

  { 51,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 102, 0 },

  { 52, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 104, 0 },

  { 53,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P23",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 106, 0 },

  { 54,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 108, 0 },

  { 55, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 110, 0 },

  { 56,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P23",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 112, 0 },

  { 57,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 114, 0 },

  { 58, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P23",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 116, 0 },

  { 59,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 118, 0 },

  { 60,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P23",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 120, 0 },

  { 61,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 122, 0 },

  { 62,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 124, 0 },

  { 63,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 126, 0 },

  { 64,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P23",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 128, 0 },

  { 65,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 130, 0 },

  { 66,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 132, 0 },

  { 67,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_A[0]), 0, 7, 2, 134, 0 },

  { 68,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 136, 0 },

  { 69,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P24",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 138, 0 },

  { 70,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 140, 0 },

  { 71,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 142, 0 },

  { 72,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 144, 0 },

  { 73,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 146, 0 },

  { 74,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 148, 0 },

  { 75,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 150, 0 },

  { 76, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 152, 0 },

  { 77,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P24",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 154, 0 },

  { 78,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 156, 0 },

  { 79, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 158, 0 },

  { 80,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P24",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 160, 0 },

  { 81,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 162, 0 },

  { 82, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P24",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 164, 0 },

  { 83,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 166, 0 },

  { 84,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P24",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 168, 0 },

  { 85,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 170, 0 },

  { 86,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 172, 0 },

  { 87,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 174, 0 },

  { 88,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P24",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 176, 0 },

  { 89,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 178, 0 },

  { 90,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 180, 0 },

  { 91,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_B[0]), 0, 7, 2, 182, 0 },

  { 92,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 184, 0 },

  { 93,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P25",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 186, 0 },

  { 94,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 188, 0 },

  { 95,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 190, 0 },

  { 96,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 192, 0 },

  { 97,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 194, 0 },

  { 98,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 196, 0 },

  { 99,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 198, 0 },

  { 100, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 200, 0 },

  { 101,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P25",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 202, 0 },

  { 102,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 204, 0 },

  { 103, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 206, 0 },

  { 104,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P25",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 208, 0 },

  { 105,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 210, 0 },

  { 106, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P25",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 212, 0 },

  { 107,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 214, 0 },

  { 108,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P25",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 216, 0 },

  { 109,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 218, 0 },

  { 110,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 220, 0 },

  { 111,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 222, 0 },

  { 112,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P25",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 224, 0 },

  { 113,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 226, 0 },

  { 114,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 228, 0 },

  { 115,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_Antoine_C[0]), 0, 7, 2, 230, 0 },

  { 116,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 232, 0 },

  { 117,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 234, 0 },

  { 118,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 236, 0 },

  { 119,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 238, 0 },

  { 120,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 240, 0 },

  { 121,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 242, 0 },

  { 122, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 244, 0 },

  { 123,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 246, 0 },

  { 124,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 248, 0 },

  { 125, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 250, 0 },

  { 126,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 252, 0 },

  { 127,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 254, 0 },

  { 128, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 256, 0 },

  { 129,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 258, 0 },

  { 130,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 260, 0 },

  { 131,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 262, 0 },

  { 132,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_max[0]), 0, 7, 2, 264, 0 },

  { 133,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 266, 0 },

  { 134,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 268, 0 },

  { 135,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 270, 0 },

  { 136,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 272, 0 },

  { 137,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 274, 0 },

  { 138,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 276, 0 },

  { 139, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 278, 0 },

  { 140,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 280, 0 },

  { 141,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 282, 0 },

  { 142, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 284, 0 },

  { 143,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 286, 0 },

  { 144,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 288, 0 },

  { 145, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 290, 0 },

  { 146,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 292, 0 },

  { 147,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 294, 0 },

  { 148,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 296, 0 },

  { 149,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_Cp_liq_T_min[0]), 0, 7, 2, 298, 0 },

  { 150,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P12",
    offsetof(P_NACCBraytonCycle2017a_T, th_E_liq[0]), 0, 7, 2, 300, 0 },

  { 151,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P12",
    offsetof(P_NACCBraytonCycle2017a_T, th_E_liq[0]), 0, 7, 2, 302, 0 },

  { 152, "naccbraytoncycle2017a/Ambient air/MassFlow/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 304, 0 },

  { 153,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P22",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 306, 0 },

  { 154,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P34",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 308, 0 },

  { 155,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P34",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 310, 0 },

  { 156,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P34",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 312, 0 },

  { 157,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 314, 0 },

  { 158,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P31",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 316, 0 },

  { 159,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P34",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 318, 0 },

  { 160, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 320, 0 },

  { 161, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P31",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 322, 0 },

  { 162,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P22",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 324, 0 },

  { 163,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P34",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 326, 0 },

  { 164, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 328, 0 },

  { 165, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P31",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 330, 0 },

  { 166,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P22",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 332, 0 },

  { 167,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P34",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 334, 0 },

  { 168, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P22",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 336, 0 },

  { 169, "naccbraytoncycle2017a/Natural Gas/MassFlow/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 338, 0 },

  { 170,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P22",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 340, 0 },

  { 171, "naccbraytoncycle2017a/Sensor1/MassFlowRate/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 342, 0 },

  { 172, "naccbraytoncycle2017a/Sensor15/MassFlowRate/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 344, 0 },

  { 173, "naccbraytoncycle2017a/Sensor19/MassFlowRate/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 346, 0 },

  { 174, "naccbraytoncycle2017a/Sensor21/MassFlowRate/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 348, 0 },

  { 175, "naccbraytoncycle2017a/Sensor27/MassFlowRate/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 350, 0 },

  { 176, "naccbraytoncycle2017a/Sensor5/MassFlowRate/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 352, 0 },

  { 177, "naccbraytoncycle2017a/Sensor9/MassFlowRate/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 354, 0 },

  { 178,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 356, 0 },

  { 179,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Mass Flow Rate/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 358, 0 },

  { 180,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P22",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 360, 0 },

  { 181,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P34",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 362, 0 },

  { 182,
    "naccbraytoncycle2017a/HP CTAH/Pressure Loss/Mass Flow Rate/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 364, 0 },

  { 183,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/Mass Flow Rate1/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 366, 0 },

  { 184,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P34",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 368, 0 },

  { 185,
    "naccbraytoncycle2017a/LP CTAH/Pressure Loss/Mass Flow Rate/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 370, 0 },

  { 186,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/Mass Flow Rate1/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 372, 0 },

  { 187,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P2",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 374, 0 },

  { 188,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Mass Flow Rate/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 376, 0 },

  { 189,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/Pressure loss/Mass Flow Rate/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 378, 0 },

  { 190,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/Pressure loss/Mass Flow Rate/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 380, 0 },

  { 191,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Upstream to calculate mass flow/Mass Flow Rate2/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 382, 0 },

  { 192,
    "naccbraytoncycle2017a/Mixer/Mixer/Pressure_loss/Mass Flow Rate/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 384, 0 },

  { 193,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Mass Flow Rate/Molar Weight/M1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_M[0]), 0, 7, 2, 386, 0 },

  { 194,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P5",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 388, 0 },

  { 195,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 390, 0 },

  { 196,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 392, 0 },

  { 197,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 394, 0 },

  { 198,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 396, 0 },

  { 199,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 398, 0 },

  { 200, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 400, 0 },

  { 201,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P5",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 402, 0 },

  { 202,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 404, 0 },

  { 203, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 406, 0 },

  { 204,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P5",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 408, 0 },

  { 205,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 410, 0 },

  { 206, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P5",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 412, 0 },

  { 207,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P5",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 414, 0 },

  { 208,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P5",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 416, 0 },

  { 209,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 418, 0 },

  { 210,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_max[0]), 0, 7, 2, 420, 0 },

  { 211,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P4",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 422, 0 },

  { 212,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 424, 0 },

  { 213,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 426, 0 },

  { 214,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 428, 0 },

  { 215,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 430, 0 },

  { 216,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 432, 0 },

  { 217, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 434, 0 },

  { 218,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P4",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 436, 0 },

  { 219,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 438, 0 },

  { 220, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 440, 0 },

  { 221,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P4",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 442, 0 },

  { 222,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 444, 0 },

  { 223, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P4",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 446, 0 },

  { 224,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P4",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 448, 0 },

  { 225,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P4",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 450, 0 },

  { 226,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 452, 0 },

  { 227,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_mid[0]), 0, 7, 2, 454, 0 },

  { 228,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 456, 0 },

  { 229,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 458, 0 },

  { 230,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 460, 0 },

  { 231,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 462, 0 },

  { 232,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 464, 0 },

  { 233,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 466, 0 },

  { 234, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 468, 0 },

  { 235,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 470, 0 },

  { 236,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 472, 0 },

  { 237, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 474, 0 },

  { 238,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 476, 0 },

  { 239,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 478, 0 },

  { 240, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 480, 0 },

  { 241,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 482, 0 },

  { 242,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 484, 0 },

  { 243,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 486, 0 },

  { 244,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_NASA_T_min[0]), 0, 7, 2, 488, 0 },

  { 245,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/P5",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 490, 0 },

  { 246,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P17",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 492, 0 },

  { 247,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/P5",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 494, 0 },

  { 248,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 496, 0 },

  { 249,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 498, 0 },

  { 250,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 500, 0 },

  { 251,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 502, 0 },

  { 252,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 504, 0 },

  { 253, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 506, 0 },

  { 254,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P17",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 508, 0 },

  { 255,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 510, 0 },

  { 256, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 512, 0 },

  { 257,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P17",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 514, 0 },

  { 258,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 516, 0 },

  { 259, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P17",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 518, 0 },

  { 260,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/P5",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 520, 0 },

  { 261,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P17",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 522, 0 },

  { 262,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/P5",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 524, 0 },

  { 263,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P4",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 526, 0 },

  { 264,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/P5",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 528, 0 },

  { 265,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P17",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 530, 0 },

  { 266,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 532, 0 },

  { 267,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 534, 0 },

  { 268,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P4",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_c[0]), 0, 7, 2, 536, 0 },

  { 269,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 538, 0 },

  { 270,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P9",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 540, 0 },

  { 271,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P9",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 542, 0 },

  { 272,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P9",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 544, 0 },

  { 273,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P9",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 546, 0 },

  { 274,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P9",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 548, 0 },

  { 275, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P9",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 550, 0 },

  { 276,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 552, 0 },

  { 277,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P9",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 554, 0 },

  { 278, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P9",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 556, 0 },

  { 279,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 558, 0 },

  { 280,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P9",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 560, 0 },

  { 281, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 562, 0 },

  { 282,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 564, 0 },

  { 283,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 566, 0 },

  { 284,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P9",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 568, 0 },

  { 285,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P9",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_fg_ref[0]), 0, 7, 2, 570, 0 },

  { 286,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/P4",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 572, 0 },

  { 287,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 574, 0 },

  { 288,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/P4",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 576, 0 },

  { 289,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 578, 0 },

  { 290,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 580, 0 },

  { 291,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 582, 0 },

  { 292,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 584, 0 },

  { 293,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 586, 0 },

  { 294, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 588, 0 },

  { 295,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 590, 0 },

  { 296,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 592, 0 },

  { 297, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 594, 0 },

  { 298,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 596, 0 },

  { 299,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 598, 0 },

  { 300, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 600, 0 },

  { 301,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/P4",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 602, 0 },

  { 302,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 604, 0 },

  { 303,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/P4",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 606, 0 },

  { 304,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 608, 0 },

  { 305,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/P4",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 610, 0 },

  { 306,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 612, 0 },

  { 307,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 614, 0 },

  { 308,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 616, 0 },

  { 309,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P3",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_triple[0]), 0, 7, 2, 618, 0 },

  { 310,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P18",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_v_ref[0]), 0, 7, 2, 620, 0 },

  { 311,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P18",
    offsetof(P_NACCBraytonCycle2017a_T, th_T_v_ref[0]), 0, 7, 2, 622, 0 },

  { 312,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Gas Konstant/Value",
    offsetof(P_NACCBraytonCycle2017a_T, th_const_R), 0, 1, 2, 624, 0 },

  { 313,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P19",
    offsetof(P_NACCBraytonCycle2017a_T, th_density_calculation_mode), 0, 1, 2,
    626, 0 },

  { 314,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P19",
    offsetof(P_NACCBraytonCycle2017a_T, th_density_calculation_mode), 0, 1, 2,
    628, 0 },

  { 315,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/P12",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 630, 0 },

  { 316,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P27",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 632, 0 },

  { 317,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/P12",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 634, 0 },

  { 318,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P36",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 636, 0 },

  { 319,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P36",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 638, 0 },

  { 320,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P36",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 640, 0 },

  { 321,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P33",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 642, 0 },

  { 322,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P36",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 644, 0 },

  { 323, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P33",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 646, 0 },

  { 324,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P27",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 648, 0 },

  { 325,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P36",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 650, 0 },

  { 326, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P33",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 652, 0 },

  { 327,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P27",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 654, 0 },

  { 328,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P36",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 656, 0 },

  { 329, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P27",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 658, 0 },

  { 330,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/P12",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 660, 0 },

  { 331,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P27",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 662, 0 },

  { 332,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/P12",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 664, 0 },

  { 333,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/P12",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 666, 0 },

  { 334,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P27",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 668, 0 },

  { 335,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P36",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 670, 0 },

  { 336,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P36",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_A[0]), 0, 7, 2, 672, 0 },

  { 337,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 674, 0 },

  { 338,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P28",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 676, 0 },

  { 339,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 678, 0 },

  { 340,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P37",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 680, 0 },

  { 341,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P37",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 682, 0 },

  { 342,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P37",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 684, 0 },

  { 343,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P34",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 686, 0 },

  { 344,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P37",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 688, 0 },

  { 345, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P34",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 690, 0 },

  { 346,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P28",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 692, 0 },

  { 347,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P37",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 694, 0 },

  { 348, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P34",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 696, 0 },

  { 349,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P28",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 698, 0 },

  { 350,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P37",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 700, 0 },

  { 351, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P28",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 702, 0 },

  { 352,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 704, 0 },

  { 353,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P28",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 706, 0 },

  { 354,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 708, 0 },

  { 355,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/P13",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 710, 0 },

  { 356,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P28",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 712, 0 },

  { 357,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P37",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 714, 0 },

  { 358,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P37",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_B[0]), 0, 7, 2, 716, 0 },

  { 359,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 718, 0 },

  { 360,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P29",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 720, 0 },

  { 361,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 722, 0 },

  { 362,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P38",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 724, 0 },

  { 363,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P38",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 726, 0 },

  { 364,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P38",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 728, 0 },

  { 365,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P35",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 730, 0 },

  { 366,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P38",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 732, 0 },

  { 367, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P35",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 734, 0 },

  { 368,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P29",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 736, 0 },

  { 369,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P38",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 738, 0 },

  { 370, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P35",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 740, 0 },

  { 371,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P29",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 742, 0 },

  { 372,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P38",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 744, 0 },

  { 373, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P29",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 746, 0 },

  { 374,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 748, 0 },

  { 375,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P29",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 750, 0 },

  { 376,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 752, 0 },

  { 377,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/P14",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 754, 0 },

  { 378,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P29",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 756, 0 },

  { 379,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P38",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 758, 0 },

  { 380,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P38",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_C[0]), 0, 7, 2, 760, 0 },

  { 381,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 762, 0
  },

  { 382,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P30",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 764, 0
  },

  { 383,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 766, 0
  },

  { 384,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P39",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 768, 0
  },

  { 385,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P39",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 770, 0
  },

  { 386,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P39",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 772, 0
  },

  { 387,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P36",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 774, 0
  },

  { 388,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P39",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 776, 0
  },

  { 389, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P36",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 778, 0
  },

  { 390,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P30",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 780, 0
  },

  { 391,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P39",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 782, 0
  },

  { 392, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P36",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 784, 0
  },

  { 393,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P30",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 786, 0
  },

  { 394,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P39",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 788, 0
  },

  { 395, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P30",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 790, 0
  },

  { 396,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 792, 0
  },

  { 397,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P30",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 794, 0
  },

  { 398,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 796, 0
  },

  { 399,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/P15",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 798, 0
  },

  { 400,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P30",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 800, 0
  },

  { 401,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P39",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 802, 0
  },

  { 402,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P39",
    offsetof(P_NACCBraytonCycle2017a_T, th_evap_enth_T_min[0]), 0, 7, 2, 804, 0
  },

  { 403,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 806, 0 },

  { 404,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P20",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 808, 0 },

  { 405,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 810, 0 },

  { 406,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P32",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 812, 0 },

  { 407,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P32",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 814, 0 },

  { 408,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P32",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 816, 0 },

  { 409,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P29",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 818, 0 },

  { 410,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P32",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 820, 0 },

  { 411, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P29",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 822, 0 },

  { 412,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P20",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 824, 0 },

  { 413,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P32",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 826, 0 },

  { 414, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P29",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 828, 0 },

  { 415,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P20",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 830, 0 },

  { 416,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P32",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 832, 0 },

  { 417, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P20",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 834, 0 },

  { 418,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 836, 0 },

  { 419,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P20",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 838, 0 },

  { 420,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 840, 0 },

  { 421,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 842, 0 },

  { 422,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 844, 0 },

  { 423,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P20",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 846, 0 },

  { 424,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P32",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 848, 0 },

  { 425,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P32",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 850, 0 },

  { 426,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P16",
    offsetof(P_NACCBraytonCycle2017a_T, th_gas_eos_method), 0, 1, 2, 852, 0 },

  { 427,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 854, 0 },

  { 428,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 856, 0 },

  { 429,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 858, 0 },

  { 430,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 860, 0 },

  { 431,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 862, 0 },

  { 432,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 864, 0 },

  { 433, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 866, 0 },

  { 434,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 868, 0 },

  { 435,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 870, 0 },

  { 436, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 872, 0 },

  { 437,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 874, 0 },

  { 438,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 876, 0 },

  { 439, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 878, 0 },

  { 440,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 880, 0 },

  { 441,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 882, 0 },

  { 442,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 884, 0 },

  { 443,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_hm_fg[0]), 0, 7, 2, 886, 0 },

  { 444,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 888, 0 },

  { 445,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P26",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 890, 0 },

  { 446,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 892, 0 },

  { 447,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P35",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 894, 0 },

  { 448,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P35",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 896, 0 },

  { 449,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P35",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 898, 0 },

  { 450,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P32",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 900, 0 },

  { 451,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P35",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 902, 0 },

  { 452, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P32",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 904, 0 },

  { 453,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P26",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 906, 0 },

  { 454,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P35",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 908, 0 },

  { 455, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P32",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 910, 0 },

  { 456,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P26",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 912, 0 },

  { 457,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P35",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 914, 0 },

  { 458, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P26",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 916, 0 },

  { 459,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 918, 0 },

  { 460,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P26",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 920, 0 },

  { 461,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 922, 0 },

  { 462,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 924, 0 },

  { 463,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P26",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 926, 0 },

  { 464,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P35",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 928, 0 },

  { 465,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P35",
    offsetof(P_NACCBraytonCycle2017a_T, th_liquid_eos_method), 0, 1, 2, 930, 0 },

  { 466,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 932, 0 },

  { 467,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P19",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 934, 0 },

  { 468,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 936, 0 },

  { 469,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P30",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 938, 0 },

  { 470,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P30",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 940, 0 },

  { 471,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P30",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 942, 0 },

  { 472,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P27",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 944, 0 },

  { 473,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P30",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 946, 0 },

  { 474, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P27",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 948, 0 },

  { 475,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P19",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 950, 0 },

  { 476,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P30",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 952, 0 },

  { 477, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P27",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 954, 0 },

  { 478,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P19",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 956, 0 },

  { 479,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P30",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 958, 0 },

  { 480, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P19",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 960, 0 },

  { 481,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 962, 0 },

  { 482,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P19",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 964, 0 },

  { 483,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 966, 0 },

  { 484,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 968, 0 },

  { 485,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 970, 0 },

  { 486,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P19",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 972, 0 },

  { 487,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P30",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 974, 0 },

  { 488,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P30",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 976, 0 },

  { 489,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_omega[0]), 0, 7, 2, 978, 0 },

  { 490,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 980, 0 },

  { 491,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P18",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 982, 0 },

  { 492,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 984, 0 },

  { 493,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P31",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 986, 0 },

  { 494,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P31",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 988, 0 },

  { 495,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P31",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 990, 0 },

  { 496,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P28",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 992, 0 },

  { 497,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P31",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 994, 0 },

  { 498, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P28",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 996, 0 },

  { 499,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P18",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 998, 0 },

  { 500,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P31",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 1000, 0 },

  { 501, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P28",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 1002, 0 },

  { 502,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P18",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 1004, 0 },

  { 503,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P31",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 1006, 0 },

  { 504, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P18",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 1008, 0 },

  { 505,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 1010, 0 },

  { 506,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P18",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 1012, 0 },

  { 507,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 1014, 0 },

  { 508,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P5",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 1016, 0 },

  { 509,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/P6",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 1018, 0 },

  { 510,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P18",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 1020, 0 },

  { 511,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P31",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 1022, 0 },

  { 512,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P31",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 1024, 0 },

  { 513,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P5",
    offsetof(P_NACCBraytonCycle2017a_T, th_p_c[0]), 0, 7, 2, 1026, 0 },

  { 514,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_rho_liq[0]), 0, 7, 2, 1028, 0 },

  { 515,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P1",
    offsetof(P_NACCBraytonCycle2017a_T, th_rho_liq[0]), 0, 7, 2, 1030, 0 },

  { 516,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_rho_liq_A[0]), 0, 7, 2, 1032, 0 },

  { 517,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_rho_liq_A[0]), 0, 7, 2, 1034, 0 },

  { 518,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P9",
    offsetof(P_NACCBraytonCycle2017a_T, th_rho_liq_B[0]), 0, 7, 2, 1036, 0 },

  { 519,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P9",
    offsetof(P_NACCBraytonCycle2017a_T, th_rho_liq_B[0]), 0, 7, 2, 1038, 0 },

  { 520,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_rho_liq_C[0]), 0, 7, 2, 1040, 0 },

  { 521,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P10",
    offsetof(P_NACCBraytonCycle2017a_T, th_rho_liq_C[0]), 0, 7, 2, 1042, 0 },

  { 522,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_rho_liq_D[0]), 0, 7, 2, 1044, 0 },

  { 523,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_rho_liq_D[0]), 0, 7, 2, 1046, 0 },

  { 524,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1048, 0 },

  { 525,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1050, 0 },

  { 526,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1052, 0 },

  { 527,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1054, 0 },

  { 528,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1056, 0 },

  { 529,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1058, 0 },

  { 530, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1060, 0 },

  { 531,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1062, 0 },

  { 532,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1064, 0 },

  { 533, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1066, 0 },

  { 534,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1068, 0 },

  { 535,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1070, 0 },

  { 536, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1072, 0 },

  { 537,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1074, 0 },

  { 538,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P8",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1076, 0 },

  { 539,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1078, 0 },

  { 540,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P11",
    offsetof(P_NACCBraytonCycle2017a_T, th_sm_fg[0]), 0, 7, 2, 1080, 0 },

  { 541,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_vm_c[0]), 0, 7, 2, 1082, 0 },

  { 542,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P7",
    offsetof(P_NACCBraytonCycle2017a_T, th_vm_c[0]), 0, 7, 2, 1084, 0 },

  { 543,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/P9",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P9), 0, 1, 2, 1086, 0 },

  { 544,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/P10",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P10), 0, 1, 2, 1088, 0 },

  { 545,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Constant/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant_Value), 0, 1, 2, 1090, 0 },

  { 546,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function/P17",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P17), 0, 1, 2, 1092, 0 },

  { 547, "naccbraytoncycle2017a/Ambient air/Reservoir/nan/InitialOutput",
    offsetof(P_NACCBraytonCycle2017a_T, nan_Y0), 0, 1, 2, 1094, 0 },

  { 548, "naccbraytoncycle2017a/Ambient air/Reservoir/Sonstiges1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Sonstiges1_Value), 0, 1, 2, 1096, 0 },

  { 549,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/P9",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P9_n), 0, 1, 2, 1098, 0 },

  { 550,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/P10",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P10_n), 0, 1, 2, 1100, 0 },

  { 551, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain_Gain), 0, 1, 2, 1102, 0 },

  { 552, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain1/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain1_Gain), 0, 1, 2, 1104, 0 },

  { 553, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain2/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain2_Gain), 0, 1, 2, 1106, 0 },

  { 554, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain3/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain3_Gain), 0, 1, 2, 1108, 0 },

  { 555, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain4/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain4_Gain), 0, 1, 2, 1110, 0 },

  { 556,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P1",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P1[0]), 0, 49, 2, 1112, 0 },

  { 557,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P2",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P2[0]), 0, 49, 2, 1114, 0 },

  { 558,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P12), 0, 24, 2, 1116, 0 },

  { 559,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P13",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P13[0]), 0, 21, 2, 1118, 0 },

  { 560,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P14",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P14[0]), 0, 504, 2, 1120, 0 },

  { 561,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P15",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P15), 0, 1, 2, 1122, 0 },

  { 562,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1/P21",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P21), 0, 1, 2, 1124, 0 },

  { 563,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P4",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P4[0]), 0, 49, 2, 1126, 0 },

  { 564,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P5",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P5[0]), 0, 49, 2, 1128, 0 },

  { 565,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P12[0]), 0, 28, 2, 1130, 0 },

  { 566,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P17",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P17_d), 0, 24, 2, 1132, 0 },

  { 567,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P18",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P18[0]), 0, 21, 2, 1134, 0 },

  { 568,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P19",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P19[0]), 0, 504, 2, 1136, 0 },

  { 569,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P20",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P20), 0, 1, 2, 1138, 0 },

  { 570,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P28",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P28), 0, 1, 2, 1140, 0 },

  { 571,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function/P33",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P33), 0, 1, 2, 1142, 0 },

  { 572,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P4",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P4_e[0]), 0, 49, 2, 1144, 0 },

  { 573,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P5",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P5_g[0]), 0, 49, 2, 1146, 0 },

  { 574,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P12_j[0]), 0, 28, 2, 1148, 0 },

  { 575,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P17",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P17_j), 0, 24, 2, 1150, 0 },

  { 576,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P18",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P18_o[0]), 0, 21, 2, 1152, 0 },

  { 577,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P19",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P19_b[0]), 0, 504, 2, 1154, 0
  },

  { 578,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P20",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P20_e), 0, 1, 2, 1156, 0 },

  { 579,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P28",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P28_d), 0, 1, 2, 1158, 0 },

  { 580,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function/P33",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P33_p), 0, 1, 2, 1160, 0 },

  { 581,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Upstream to calculate mass flow/Saturation1/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation1_UpperSat), 0, 1, 2, 1162, 0
  },

  { 582,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Upstream to calculate mass flow/Saturation1/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation1_LowerSat), 0, 1, 2, 1164, 0
  },

  { 583,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Upstream to calculate mass flow/Constant3/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant3_Value), 0, 1, 2, 1166, 0 },

  { 584,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Constant6/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant6_Value), 0, 1, 2, 1168, 0 },

  { 585,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Divide2/Constant/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant_Value_o), 0, 1, 2, 1170, 0 },

  { 586,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P4",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P4_p[0]), 0, 49, 2, 1172, 0 },

  { 587,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P5",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P5_k[0]), 0, 49, 2, 1174, 0 },

  { 588,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P12_d[0]), 0, 28, 2, 1176, 0 },

  { 589,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P17",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P17_p), 0, 24, 2, 1178, 0 },

  { 590,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P18",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P18_m[0]), 0, 21, 2, 1180, 0 },

  { 591,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P19",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P19_i[0]), 0, 504, 2, 1182, 0
  },

  { 592,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P20",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P20_l), 0, 1, 2, 1184, 0 },

  { 593,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P28",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P28_k), 0, 1, 2, 1186, 0 },

  { 594,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function/P33",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P33_f), 0, 1, 2, 1188, 0 },

  { 595,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P4",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P4_n[0]), 0, 49, 2, 1190, 0 },

  { 596,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P5",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P5_a[0]), 0, 49, 2, 1192, 0 },

  { 597,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P12_h[0]), 0, 28, 2, 1194, 0 },

  { 598,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P17",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P17_dj), 0, 24, 2, 1196, 0 },

  { 599,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P18",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P18_h[0]), 0, 21, 2, 1198, 0 },

  { 600,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P19",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P19_c[0]), 0, 504, 2, 1200, 0
  },

  { 601,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P20",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P20_h), 0, 1, 2, 1202, 0 },

  { 602,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P25",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P25), 0, 1, 2, 1204, 0 },

  { 603,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function/P30",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P30), 0, 1, 2, 1206, 0 },

  { 604,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/P9",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P9_e), 0, 1, 2, 1208, 0 },

  { 605,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/P10",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P10_j), 0, 1, 2, 1210, 0 },

  { 606,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain_Gain_j), 0, 1, 2, 1212, 0 },

  { 607,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain1/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain1_Gain_n), 0, 1, 2, 1214, 0 },

  { 608,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain2/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain2_Gain_m), 0, 1, 2, 1216, 0 },

  { 609,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain3/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain3_Gain_m), 0, 1, 2, 1218, 0 },

  { 610,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain4/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain4_Gain_i), 0, 1, 2, 1220, 0 },

  { 611,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P1",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P1_l[0]), 0, 49, 2, 1222, 0 },

  { 612,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P2",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P2_o[0]), 0, 49, 2, 1224, 0 },

  { 613,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P12_f), 0, 24, 2, 1226, 0 },

  { 614,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P13",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P13_f[0]), 0, 21, 2, 1228, 0
  },

  { 615,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P14",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P14_o[0]), 0, 504, 2, 1230, 0
  },

  { 616,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P15",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P15_a), 0, 1, 2, 1232, 0 },

  { 617,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1/P21",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P21_k), 0, 1, 2, 1234, 0 },

  { 618,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P4",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P4_a[0]), 0, 49, 2, 1236, 0 },

  { 619,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P5",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P5_l[0]), 0, 49, 2, 1238, 0 },

  { 620,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P12_e[0]), 0, 28, 2, 1240, 0 },

  { 621,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P17",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P17_pk), 0, 24, 2, 1242, 0 },

  { 622,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P18",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P18_b[0]), 0, 21, 2, 1244, 0 },

  { 623,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P19",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P19_g[0]), 0, 504, 2, 1246, 0
  },

  { 624,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P20",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P20_lh), 0, 1, 2, 1248, 0 },

  { 625,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P28",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P28_a), 0, 1, 2, 1250, 0 },

  { 626,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P33",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P33_n), 0, 1, 2, 1252, 0 },

  { 627,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/LUTs/Lookup Table (2-D)2/RowIndex",
    offsetof(P_NACCBraytonCycle2017a_T, LookupTable2D2_RowIdx[0]), 0, 6, 2, 1254,
    0 },

  { 628,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/LUTs/Lookup Table (2-D)2/ColumnIndex",
    offsetof(P_NACCBraytonCycle2017a_T, LookupTable2D2_ColIdx[0]), 0, 21, 2,
    1256, 0 },

  { 629,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/LUTs/Lookup Table (2-D)2/Table",
    offsetof(P_NACCBraytonCycle2017a_T, LookupTable2D2_Table[0]), 0, 126, 2,
    1258, 0 },

  { 630,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/LUTs/Saturation1/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation1_UpperSat_k), 0, 1, 2, 1260,
    0 },

  { 631,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/LUTs/Saturation1/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation1_LowerSat_d), 0, 1, 2, 1262,
    0 },

  { 632,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/LUTs/Lookup Table (2-D)/RowIndex",
    offsetof(P_NACCBraytonCycle2017a_T, LookupTable2D_RowIdx[0]), 0, 6, 2, 1264,
    0 },

  { 633,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/LUTs/Lookup Table (2-D)/ColumnIndex",
    offsetof(P_NACCBraytonCycle2017a_T, LookupTable2D_ColIdx[0]), 0, 21, 2, 1266,
    0 },

  { 634,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/LUTs/Lookup Table (2-D)/Table",
    offsetof(P_NACCBraytonCycle2017a_T, LookupTable2D_Table[0]), 0, 126, 2, 1268,
    0 },

  { 635, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/LUTs/Constant2/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant2_Value), 0, 1, 2, 1270, 0 },

  { 636, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/LUTs/Constant1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant1_Value), 0, 1, 2, 1272, 0 },

  { 637,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/LUTs/Saturation/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_UpperSat), 0, 1, 2, 1274, 0 },

  { 638,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/LUTs/Saturation/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_LowerSat), 0, 1, 2, 1276, 0 },

  { 639, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/p-normal/Value", offsetof
    (P_NACCBraytonCycle2017a_T, pnormal_Value), 0, 1, 2, 1278, 0 },

  { 640,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P4",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P4_aj[0]), 0, 49, 2, 1280, 0 },

  { 641,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P5",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P5_j[0]), 0, 49, 2, 1282, 0 },

  { 642,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P12_jo[0]), 0, 28, 2, 1284, 0
  },

  { 643,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P17",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P17_i), 0, 24, 2, 1286, 0 },

  { 644,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P18",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P18_p[0]), 0, 21, 2, 1288, 0 },

  { 645,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P19",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P19_h[0]), 0, 504, 2, 1290, 0
  },

  { 646,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P20",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P20_m), 0, 1, 2, 1292, 0 },

  { 647,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P28",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P28_m), 0, 1, 2, 1294, 0 },

  { 648,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P33",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P33_e), 0, 1, 2, 1296, 0 },

  { 649, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/LUTs/Constant4/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant4_Value), 0, 1, 2, 1298, 0 },

  { 650, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P4",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P4_h[0]), 0, 49, 2, 1300, 0 },

  { 651, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P5",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P5_m[0]), 0, 49, 2, 1302, 0 },

  { 652, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P12_o[0]), 0, 28, 2, 1304, 0 },

  { 653, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P17",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P17_o), 0, 24, 2, 1306, 0 },

  { 654, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P18",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P18_c[0]), 0, 21, 2, 1308, 0 },

  { 655, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P19",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P19_e[0]), 0, 504, 2, 1310, 0
  },

  { 656, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P20",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P20_b), 0, 1, 2, 1312, 0 },

  { 657, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P25",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P25_k), 0, 1, 2, 1314, 0 },

  { 658, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function/P30",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P30_e), 0, 1, 2, 1316, 0 },

  { 659, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/Constant1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant1_Value_g), 0, 1, 2, 1318, 0 },

  { 660,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P4",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P4_nq[0]), 0, 49, 2, 1320, 0 },

  { 661,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P5",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P5_c[0]), 0, 49, 2, 1322, 0 },

  { 662,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P12_e5[0]), 0, 28, 2, 1324, 0
  },

  { 663,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P17",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P17_dx), 0, 24, 2, 1326, 0 },

  { 664,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P18",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P18_j[0]), 0, 21, 2, 1328, 0 },

  { 665,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P19",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P19_d[0]), 0, 504, 2, 1330, 0
  },

  { 666,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P20",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P20_bp), 0, 1, 2, 1332, 0 },

  { 667,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P28",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P28_dr), 0, 1, 2, 1334, 0 },

  { 668,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function/P33",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P33_a), 0, 1, 2, 1336, 0 },

  { 669,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/LUTs/Lookup Table (2-D)2/RowIndex",
    offsetof(P_NACCBraytonCycle2017a_T, LookupTable2D2_RowIdx_d[0]), 0, 6, 2,
    1338, 0 },

  { 670,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/LUTs/Lookup Table (2-D)2/ColumnIndex",
    offsetof(P_NACCBraytonCycle2017a_T, LookupTable2D2_ColIdx_g[0]), 0, 21, 2,
    1340, 0 },

  { 671,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/LUTs/Lookup Table (2-D)2/Table",
    offsetof(P_NACCBraytonCycle2017a_T, LookupTable2D2_Table_l[0]), 0, 126, 2,
    1342, 0 },

  { 672,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/LUTs/Saturation1/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation1_UpperSat_m), 0, 1, 2, 1344,
    0 },

  { 673,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/LUTs/Saturation1/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation1_LowerSat_n), 0, 1, 2, 1346,
    0 },

  { 674,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/LUTs/Lookup Table (2-D)/RowIndex",
    offsetof(P_NACCBraytonCycle2017a_T, LookupTable2D_RowIdx_i[0]), 0, 6, 2,
    1348, 0 },

  { 675,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/LUTs/Lookup Table (2-D)/ColumnIndex",
    offsetof(P_NACCBraytonCycle2017a_T, LookupTable2D_ColIdx_h[0]), 0, 21, 2,
    1350, 0 },

  { 676,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/LUTs/Lookup Table (2-D)/Table",
    offsetof(P_NACCBraytonCycle2017a_T, LookupTable2D_Table_l[0]), 0, 126, 2,
    1352, 0 },

  { 677, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/LUTs/Constant2/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant2_Value_e), 0, 1, 2, 1354, 0 },

  { 678, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/LUTs/Constant1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant1_Value_h), 0, 1, 2, 1356, 0 },

  { 679,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/LUTs/Saturation/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_UpperSat_e), 0, 1, 2, 1358, 0
  },

  { 680,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/LUTs/Saturation/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_LowerSat_i), 0, 1, 2, 1360, 0
  },

  { 681, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/p-normal/Value", offsetof
    (P_NACCBraytonCycle2017a_T, pnormal_Value_k), 0, 1, 2, 1362, 0 },

  { 682,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P4",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P4_hi[0]), 0, 49, 2, 1364, 0 },

  { 683,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P5",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P5_b[0]), 0, 49, 2, 1366, 0 },

  { 684,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P12_b[0]), 0, 28, 2, 1368, 0 },

  { 685,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P17",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P17_n), 0, 24, 2, 1370, 0 },

  { 686,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P18",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P18_cy[0]), 0, 21, 2, 1372, 0
  },

  { 687,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P19",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P19_go[0]), 0, 504, 2, 1374, 0
  },

  { 688,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P20",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P20_k), 0, 1, 2, 1376, 0 },

  { 689,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P28",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P28_mt), 0, 1, 2, 1378, 0 },

  { 690,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function/P33",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P33_l), 0, 1, 2, 1380, 0 },

  { 691, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/LUTs/Constant4/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant4_Value_d), 0, 1, 2, 1382, 0 },

  { 692, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P4",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P4_g[0]), 0, 49, 2, 1384, 0 },

  { 693, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P5",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P5_n[0]), 0, 49, 2, 1386, 0 },

  { 694, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P12_i[0]), 0, 28, 2, 1388, 0 },

  { 695, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P17",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P17_k), 0, 24, 2, 1390, 0 },

  { 696, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P18",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P18_n[0]), 0, 21, 2, 1392, 0 },

  { 697, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P19",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P19_j[0]), 0, 504, 2, 1394, 0
  },

  { 698, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P20",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P20_ew), 0, 1, 2, 1396, 0 },

  { 699, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P25",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P25_p), 0, 1, 2, 1398, 0 },

  { 700, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function/P30",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P30_a), 0, 1, 2, 1400, 0 },

  { 701, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/Constant1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant1_Value_e), 0, 1, 2, 1402, 0 },

  { 702, "naccbraytoncycle2017a/Mixer/Mixer/mean if ndot1 and 2 are zero/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, meanifndot1and2arezero_Gain), 0, 1, 2,
    1404, 0 },

  { 703, "naccbraytoncycle2017a/Mixer/Mixer/Saturation/UpperLimit", offsetof
    (P_NACCBraytonCycle2017a_T, Saturation_UpperSat_o), 0, 1, 2, 1406, 0 },

  { 704, "naccbraytoncycle2017a/Mixer/Mixer/Saturation/LowerLimit", offsetof
    (P_NACCBraytonCycle2017a_T, Saturation_LowerSat_m), 0, 1, 2, 1408, 0 },

  { 705, "naccbraytoncycle2017a/Mixer/Mixer/mean if ndot1 and 2=0/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, meanifndot1and20_Gain), 0, 1, 2, 1410, 0
  },

  { 706, "naccbraytoncycle2017a/Mixer/Mixer/Divide/Constant/Value", offsetof
    (P_NACCBraytonCycle2017a_T, Constant_Value_b), 0, 1, 2, 1412, 0 },

  { 707, "naccbraytoncycle2017a/Mixer/ratio/Value", offsetof
    (P_NACCBraytonCycle2017a_T, ratio_Value), 0, 1, 2, 1414, 0 },

  { 708,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P4",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P4_o[0]), 0, 49, 2, 1416, 0 },

  { 709,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P5",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P5_o[0]), 0, 49, 2, 1418, 0 },

  { 710,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P12_p[0]), 0, 28, 2, 1420, 0 },

  { 711,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P17",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P17_po), 0, 24, 2, 1422, 0 },

  { 712,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P18",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P18_f[0]), 0, 21, 2, 1424, 0 },

  { 713,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P19",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P19_goy[0]), 0, 504, 2, 1426,
    0 },

  { 714,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P20",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P20_e4), 0, 1, 2, 1428, 0 },

  { 715,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P28",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P28_h), 0, 1, 2, 1430, 0 },

  { 716,
    "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function/P33",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P33_no), 0, 1, 2, 1432, 0 },

  { 717, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain2/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain2_Gain_a), 0, 1, 2, 1434, 0 },

  { 718, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain_Gain_o), 0, 1, 2, 1436, 0 },

  { 719, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain4/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain4_Gain_o), 0, 1, 2, 1438, 0 },

  { 720, "naccbraytoncycle2017a/Mixer/Mixer/Compare To Zero/Constant/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant_Value_i), 0, 1, 2, 1440, 0 },

  { 721,
    "naccbraytoncycle2017a/Mixer/Mixer/Divide/Compare To Zero/Constant/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant_Value_f), 0, 1, 2, 1442, 0 },

  { 722, "naccbraytoncycle2017a/Mixer/Mixer/Pressure_loss/Gain/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain_Gain_a), 0, 1, 2, 1444, 0 },

  { 723, "naccbraytoncycle2017a/Mixer/Mixer/Pressure_loss/p_downstrem_min/Value",
    offsetof(P_NACCBraytonCycle2017a_T, p_downstrem_min_Value), 0, 1, 2, 1446, 0
  },

  { 724, "naccbraytoncycle2017a/Mixer/Mixer/Pressure_loss/Saturation/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_UpperSat_i), 0, 1, 2, 1448, 0
  },

  { 725, "naccbraytoncycle2017a/Mixer/Mixer/Pressure_loss/Saturation/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_LowerSat_mf), 0, 1, 2, 1450,
    0 },

  { 726, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_f), 0, 1, 2, 1452, 0 },

  { 727, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain3/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain3_Gain_d), 0, 1, 2, 1454, 0 },

  { 728, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P1",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P1_p[0]), 0, 49, 2, 1456, 0 },

  { 729, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P2",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P2_d[0]), 0, 49, 2, 1458, 0 },

  { 730, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P12_j), 0, 24, 2, 1460, 0 },

  { 731, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P13",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P13_g[0]), 0, 21, 2, 1462, 0
  },

  { 732, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P14",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P14_m[0]), 0, 504, 2, 1464, 0
  },

  { 733, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P15",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P15_g), 0, 1, 2, 1466, 0 },

  { 734, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1/P21",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P21_ke), 0, 1, 2, 1468, 0 },

  { 735,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/P9",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P9_p), 0, 1, 2, 1470, 0 },

  { 736,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/P10",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P10_c), 0, 1, 2, 1472, 0 },

  { 737,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Constant/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant_Value_bv), 0, 1, 2, 1474, 0 },

  { 738,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function/P17",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction_P17_p5), 0, 1, 2, 1476, 0 },

  { 739, "naccbraytoncycle2017a/Natural Gas/Reservoir/nan/InitialOutput",
    offsetof(P_NACCBraytonCycle2017a_T, nan_Y0_f), 0, 1, 2, 1478, 0 },

  { 740, "naccbraytoncycle2017a/Natural Gas/Reservoir/Sonstiges1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Sonstiges1_Value_l), 0, 1, 2, 1480, 0 },

  { 741,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/P9",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P9_nq), 0, 1, 2, 1482, 0 },

  { 742,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/P10",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P10_i), 0, 1, 2, 1484, 0 },

  { 743, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain_Gain_b), 0, 1, 2, 1486, 0 },

  { 744, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain1/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain1_Gain_l), 0, 1, 2, 1488, 0 },

  { 745, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain2/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain2_Gain_j), 0, 1, 2, 1490, 0 },

  { 746, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain3/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain3_Gain_n), 0, 1, 2, 1492, 0 },

  { 747, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain4/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain4_Gain_iu), 0, 1, 2, 1494, 0 },

  { 748,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P1",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P1_l5[0]), 0, 49, 2, 1496, 0
  },

  { 749,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P2",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P2_k[0]), 0, 49, 2, 1498, 0 },

  { 750,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P12_e), 0, 24, 2, 1500, 0 },

  { 751,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P13",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P13_b[0]), 0, 21, 2, 1502, 0
  },

  { 752,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P14",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P14_me[0]), 0, 504, 2, 1504,
    0 },

  { 753,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P15",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P15_l), 0, 1, 2, 1506, 0 },

  { 754,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1/P21",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P21_kg), 0, 1, 2, 1508, 0 },

  { 755, "naccbraytoncycle2017a/Sensor21/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value), 0, 1, 2, 1510, 0 },

  { 756, "naccbraytoncycle2017a/Ambient air/Constant1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, Constant1_Value_d), 0, 1, 2, 1512, 0 },

  { 757, "naccbraytoncycle2017a/Ambient air/Unit Conversion/UnitScale/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, UnitScale_Gain), 0, 1, 2, 1514, 0 },

  { 758, "naccbraytoncycle2017a/Ambient air/Unit Conversion/UnitOffset/Bias",
    offsetof(P_NACCBraytonCycle2017a_T, UnitOffset_Bias), 0, 1, 2, 1516, 0 },

  { 759, "naccbraytoncycle2017a/Ambient air/Unit Conversion1/UnitScale/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, UnitScale_Gain_i), 0, 1, 2, 1518, 0 },

  { 760, "naccbraytoncycle2017a/Ambient air/Unit Conversion1/UnitOffset/Bias",
    offsetof(P_NACCBraytonCycle2017a_T, UnitOffset_Bias_c), 0, 1, 2, 1520, 0 },

  { 761, "naccbraytoncycle2017a/Ambient air/Unit Conversion2/UnitScale/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, UnitScale_Gain_o), 0, 1, 2, 1522, 0 },

  { 762, "naccbraytoncycle2017a/Ambient air/Unit Conversion2/UnitOffset/Bias",
    offsetof(P_NACCBraytonCycle2017a_T, UnitOffset_Bias_m), 0, 1, 2, 1524, 0 },

  { 763, "naccbraytoncycle2017a/Sensor21/Gain2/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain2_Gain_a3), 0, 1, 2, 1526, 0 },

  { 764, "naccbraytoncycle2017a/Sensor21/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_g), 0, 1, 2, 1528, 0 },

  { 765, "naccbraytoncycle2017a/Sensor20/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_m), 0, 1, 2, 1530, 0 },

  { 766, "naccbraytoncycle2017a/Sensor20/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_l3), 0, 1, 2, 1532, 0 },

  { 767, "naccbraytoncycle2017a/Sensor22/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_o), 0, 1, 2, 1534, 0 },

  { 768, "naccbraytoncycle2017a/Sensor22/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_c), 0, 1, 2, 1536, 0 },

  { 769, "naccbraytoncycle2017a/Sensor23/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_p), 0, 1, 2, 1538, 0 },

  { 770, "naccbraytoncycle2017a/Sensor23/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_ln), 0, 1, 2, 1540, 0 },

  { 771, "naccbraytoncycle2017a/Constant2/Value", offsetof
    (P_NACCBraytonCycle2017a_T, Constant2_Value_c), 0, 1, 2, 1542, 0 },

  { 772, "naccbraytoncycle2017a/Sensor1/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_f), 0, 1, 2, 1544, 0 },

  { 773,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Memory1/X0",
    offsetof(P_NACCBraytonCycle2017a_T, Memory1_X0), 0, 4, 2, 1546, 0 },

  { 774,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Upstream to calculate mass flow/Constant4/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant4_Value_p), 0, 1, 2, 1548, 0 },

  { 775,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Upstream to calculate mass flow/Gain/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain_Gain_f), 0, 1, 2, 1550, 0 },

  { 776,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Upstream to calculate mass flow/p_Relaxation/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, p_Relaxation_Gain), 0, 1, 2, 1552, 0 },

  { 777,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Upstream to calculate mass flow/Constant/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant_Value_l), 0, 1, 2, 1554, 0 },

  { 778,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Upstream to calculate mass flow/Saturation/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_UpperSat_p), 0, 1, 2, 1556, 0
  },

  { 779,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Upstream to calculate mass flow/Saturation/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_LowerSat_k), 0, 1, 2, 1558, 0
  },

  { 780,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Upstream to calculate mass flow/Memory/X0",
    offsetof(P_NACCBraytonCycle2017a_T, Memory_X0), 0, 1, 2, 1560, 0 },

  { 781,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-normal/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Tnormal_Value), 0, 1, 2, 1562, 0 },

  { 782,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/p-ratio/Constant1/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant1_Value_d2), 0, 1, 2, 1564, 0 },

  { 783,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/p-ratio/Constant3/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant3_Value_b), 0, 1, 2, 1566, 0 },

  { 784,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/p-normal/Value",
    offsetof(P_NACCBraytonCycle2017a_T, pnormal_Value_l), 0, 1, 2, 1568, 0 },

  { 785,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Divide2/Compare To Zero/Constant/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant_Value_k), 0, 1, 2, 1570, 0 },

  { 786,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Refrence R [J//g//K]/Value",
    offsetof(P_NACCBraytonCycle2017a_T, RefrenceRJgK_Value), 0, 1, 2, 1572, 0 },

  { 787,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/p-ratio/p_ratio >= 1/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T, p_ratio1_UpperSat), 0, 1, 2, 1574, 0 },

  { 788,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/p-ratio/p_ratio >= 1/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T, p_ratio1_LowerSat), 0, 1, 2, 1576, 0 },

  { 789, "naccbraytoncycle2017a/Sensor1/Gain2/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain2_Gain_mh), 0, 1, 2, 1578, 0 },

  { 790, "naccbraytoncycle2017a/Sensor1/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_p), 0, 1, 2, 1580, 0 },

  { 791, "naccbraytoncycle2017a/Sensor/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_k), 0, 1, 2, 1582, 0 },

  { 792, "naccbraytoncycle2017a/Sensor/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_k), 0, 1, 2, 1584, 0 },

  { 793, "naccbraytoncycle2017a/Sensor2/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_mr), 0, 1, 2, 1586, 0 },

  { 794, "naccbraytoncycle2017a/Sensor2/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_lj), 0, 1, 2, 1588, 0 },

  { 795, "naccbraytoncycle2017a/Sensor3/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_d), 0, 1, 2, 1590, 0 },

  { 796, "naccbraytoncycle2017a/Sensor3/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_m), 0, 1, 2, 1592, 0 },

  { 797, "naccbraytoncycle2017a/Constant3/Value", offsetof
    (P_NACCBraytonCycle2017a_T, Constant3_Value_d), 0, 1, 2, 1594, 0 },

  { 798, "naccbraytoncycle2017a/Sensor5/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_h), 0, 1, 2, 1596, 0 },

  { 799, "naccbraytoncycle2017a/Sensor5/Gain2/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain2_Gain_g), 0, 1, 2, 1598, 0 },

  { 800, "naccbraytoncycle2017a/Sensor5/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_g2), 0, 1, 2, 1600, 0 },

  { 801, "naccbraytoncycle2017a/Sensor4/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_md), 0, 1, 2, 1602, 0 },

  { 802, "naccbraytoncycle2017a/Initial Condition3/Memory1/X0", offsetof
    (P_NACCBraytonCycle2017a_T, Memory1_X0_n), 0, 1, 2, 1604, 0 },

  { 803, "naccbraytoncycle2017a/Sensor4/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_lr), 0, 1, 2, 1606, 0 },

  { 804, "naccbraytoncycle2017a/Sensor6/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_c), 0, 1, 2, 1608, 0 },

  { 805, "naccbraytoncycle2017a/Initial Condition3/Memory2/X0", offsetof
    (P_NACCBraytonCycle2017a_T, Memory2_X0), 0, 1, 2, 1610, 0 },

  { 806, "naccbraytoncycle2017a/Sensor6/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_mv), 0, 1, 2, 1612, 0 },

  { 807, "naccbraytoncycle2017a/Sensor7/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_b), 0, 1, 2, 1614, 0 },

  { 808, "naccbraytoncycle2017a/Sensor7/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_e), 0, 1, 2, 1616, 0 },

  { 809, "naccbraytoncycle2017a/Constant5/Value", offsetof
    (P_NACCBraytonCycle2017a_T, Constant5_Value), 0, 1, 2, 1618, 0 },

  { 810, "naccbraytoncycle2017a/Sensor9/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_kh), 0, 1, 2, 1620, 0 },

  { 811, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-normal/Value", offsetof
    (P_NACCBraytonCycle2017a_T, Tnormal_Value_j), 0, 1, 2, 1622, 0 },

  { 812, "naccbraytoncycle2017a/HP Gas Turbine/RPM/Value", offsetof
    (P_NACCBraytonCycle2017a_T, RPM_Value), 0, 1, 2, 1624, 0 },

  { 813, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/LUTs/Constant/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant_Value_d), 0, 1, 2, 1626, 0 },

  { 814, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain_Gain_c), 0, 1, 2, 1628, 0 },

  { 815, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain1/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain1_Gain_o), 0, 1, 2, 1630, 0 },

  { 816, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain2/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain2_Gain_n), 0, 1, 2, 1632, 0 },

  { 817, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain3/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain3_Gain_e), 0, 1, 2, 1634, 0 },

  { 818, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain4/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain4_Gain_g), 0, 1, 2, 1636, 0 },

  { 819,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P1",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P1_o[0]), 0, 49, 2, 1638, 0 },

  { 820,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P2",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P2_h[0]), 0, 49, 2, 1640, 0 },

  { 821,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P12_m), 0, 24, 2, 1642, 0 },

  { 822,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P13",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P13_h[0]), 0, 21, 2, 1644, 0
  },

  { 823,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P14",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P14_n[0]), 0, 504, 2, 1646, 0
  },

  { 824,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P15",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P15_j), 0, 1, 2, 1648, 0 },

  { 825,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1/P21",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P21_m), 0, 1, 2, 1650, 0 },

  { 826, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_h), 0, 1, 2, 1652, 0 },

  { 827, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/Saturation1/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation1_UpperSat_d), 0, 1, 2, 1654,
    0 },

  { 828, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/Saturation1/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation1_LowerSat_ds), 0, 1, 2, 1656,
    0 },

  { 829, "naccbraytoncycle2017a/Sensor9/Gain2/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain2_Gain_o), 0, 1, 2, 1658, 0 },

  { 830, "naccbraytoncycle2017a/Sensor9/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_n0), 0, 1, 2, 1660, 0 },

  { 831, "naccbraytoncycle2017a/Sensor8/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_ok), 0, 1, 2, 1662, 0 },

  { 832, "naccbraytoncycle2017a/Sensor8/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_oq), 0, 1, 2, 1664, 0 },

  { 833, "naccbraytoncycle2017a/Sensor10/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_f1), 0, 1, 2, 1666, 0 },

  { 834, "naccbraytoncycle2017a/Sensor10/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_i), 0, 1, 2, 1668, 0 },

  { 835, "naccbraytoncycle2017a/Sensor11/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_kx), 0, 1, 2, 1670, 0 },

  { 836, "naccbraytoncycle2017a/Sensor11/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_k3), 0, 1, 2, 1672, 0 },

  { 837, "naccbraytoncycle2017a/Constant6/Value", offsetof
    (P_NACCBraytonCycle2017a_T, Constant6_Value_l), 0, 1, 2, 1674, 0 },

  { 838, "naccbraytoncycle2017a/Sensor15/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_b5), 0, 1, 2, 1676, 0 },

  { 839, "naccbraytoncycle2017a/Sensor15/Gain2/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain2_Gain_as), 0, 1, 2, 1678, 0 },

  { 840, "naccbraytoncycle2017a/Sensor15/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_k0), 0, 1, 2, 1680, 0 },

  { 841, "naccbraytoncycle2017a/Sensor14/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_d1), 0, 1, 2, 1682, 0 },

  { 842, "naccbraytoncycle2017a/Initial Condition2/Memory1/X0", offsetof
    (P_NACCBraytonCycle2017a_T, Memory1_X0_o), 0, 1, 2, 1684, 0 },

  { 843, "naccbraytoncycle2017a/Sensor14/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_ea), 0, 1, 2, 1686, 0 },

  { 844, "naccbraytoncycle2017a/Sensor12/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_g), 0, 1, 2, 1688, 0 },

  { 845, "naccbraytoncycle2017a/Initial Condition2/Memory2/X0", offsetof
    (P_NACCBraytonCycle2017a_T, Memory2_X0_p), 0, 1, 2, 1690, 0 },

  { 846, "naccbraytoncycle2017a/Sensor12/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_b), 0, 1, 2, 1692, 0 },

  { 847, "naccbraytoncycle2017a/Sensor13/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_l), 0, 1, 2, 1694, 0 },

  { 848, "naccbraytoncycle2017a/Sensor13/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_fe), 0, 1, 2, 1696, 0 },

  { 849, "naccbraytoncycle2017a/Constant7/Value", offsetof
    (P_NACCBraytonCycle2017a_T, Constant7_Value), 0, 1, 2, 1698, 0 },

  { 850, "naccbraytoncycle2017a/Sensor19/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_fu), 0, 1, 2, 1700, 0 },

  { 851, "naccbraytoncycle2017a/Natural Gas/Constant1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, Constant1_Value_k), 0, 1, 2, 1702, 0 },

  { 852, "naccbraytoncycle2017a/Natural Gas/Unit Conversion/UnitScale/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, UnitScale_Gain_e), 0, 1, 2, 1704, 0 },

  { 853, "naccbraytoncycle2017a/Natural Gas/Unit Conversion/UnitOffset/Bias",
    offsetof(P_NACCBraytonCycle2017a_T, UnitOffset_Bias_f), 0, 1, 2, 1706, 0 },

  { 854, "naccbraytoncycle2017a/Natural Gas/Unit Conversion1/UnitScale/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, UnitScale_Gain_g), 0, 1, 2, 1708, 0 },

  { 855, "naccbraytoncycle2017a/Natural Gas/Unit Conversion1/UnitOffset/Bias",
    offsetof(P_NACCBraytonCycle2017a_T, UnitOffset_Bias_h), 0, 1, 2, 1710, 0 },

  { 856, "naccbraytoncycle2017a/Natural Gas/Unit Conversion2/UnitScale/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, UnitScale_Gain_n), 0, 1, 2, 1712, 0 },

  { 857, "naccbraytoncycle2017a/Natural Gas/Unit Conversion2/UnitOffset/Bias",
    offsetof(P_NACCBraytonCycle2017a_T, UnitOffset_Bias_mp), 0, 1, 2, 1714, 0 },

  { 858, "naccbraytoncycle2017a/Constant1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, Constant1_Value_f), 0, 1, 2, 1716, 0 },

  { 859,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/Pressure loss/Gain/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain_Gain_m), 0, 1, 2, 1718, 0 },

  { 860,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/Pressure loss/p_downstrem_min/Value",
    offsetof(P_NACCBraytonCycle2017a_T, p_downstrem_min_Value_b), 0, 1, 2, 1720,
    0 },

  { 861,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/Pressure loss/Saturation/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_UpperSat_a), 0, 1, 2, 1722, 0
  },

  { 862,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/Pressure loss/Saturation/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_LowerSat_l), 0, 1, 2, 1724, 0
  },

  { 863, "naccbraytoncycle2017a/Constant4/Value", offsetof
    (P_NACCBraytonCycle2017a_T, Constant4_Value_e), 0, 1, 2, 1726, 0 },

  { 864,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/Pressure loss/Gain/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain_Gain_g), 0, 1, 2, 1728, 0 },

  { 865,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/Pressure loss/p_downstrem_min/Value",
    offsetof(P_NACCBraytonCycle2017a_T, p_downstrem_min_Value_p), 0, 1, 2, 1730,
    0 },

  { 866,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/Pressure loss/Saturation/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_UpperSat_j), 0, 1, 2, 1732, 0
  },

  { 867,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/Pressure loss/Saturation/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_LowerSat_kc), 0, 1, 2, 1734,
    0 },

  { 868, "naccbraytoncycle2017a/Sensor19/Gain2/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain2_Gain_e), 0, 1, 2, 1736, 0 },

  { 869, "naccbraytoncycle2017a/Sensor19/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_nb), 0, 1, 2, 1738, 0 },

  { 870, "naccbraytoncycle2017a/Sensor18/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_e), 0, 1, 2, 1740, 0 },

  { 871, "naccbraytoncycle2017a/Sensor18/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_ck), 0, 1, 2, 1742, 0 },

  { 872, "naccbraytoncycle2017a/Sensor16/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_hp), 0, 1, 2, 1744, 0 },

  { 873, "naccbraytoncycle2017a/Sensor16/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_is), 0, 1, 2, 1746, 0 },

  { 874, "naccbraytoncycle2017a/Sensor17/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_dv), 0, 1, 2, 1748, 0 },

  { 875, "naccbraytoncycle2017a/Sensor17/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_j), 0, 1, 2, 1750, 0 },

  { 876, "naccbraytoncycle2017a/Constant8/Value", offsetof
    (P_NACCBraytonCycle2017a_T, Constant8_Value), 0, 1, 2, 1752, 0 },

  { 877, "naccbraytoncycle2017a/Sensor27/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_hc), 0, 1, 2, 1754, 0 },

  { 878, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-normal/Value", offsetof
    (P_NACCBraytonCycle2017a_T, Tnormal_Value_n), 0, 1, 2, 1756, 0 },

  { 879, "naccbraytoncycle2017a/LP Gas Turbine/RPM/Value", offsetof
    (P_NACCBraytonCycle2017a_T, RPM_Value_f), 0, 1, 2, 1758, 0 },

  { 880, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/LUTs/Constant/Value",
    offsetof(P_NACCBraytonCycle2017a_T, Constant_Value_j), 0, 1, 2, 1760, 0 },

  { 881, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain_Gain_l), 0, 1, 2, 1762, 0 },

  { 882, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain1/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain1_Gain_d), 0, 1, 2, 1764, 0 },

  { 883, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain2/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain2_Gain_oa), 0, 1, 2, 1766, 0 },

  { 884, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain3/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain3_Gain_p), 0, 1, 2, 1768, 0 },

  { 885, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain4/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, Gain4_Gain_l), 0, 1, 2, 1770, 0 },

  { 886,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P1",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P1_h[0]), 0, 49, 2, 1772, 0 },

  { 887,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P2",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P2_m[0]), 0, 49, 2, 1774, 0 },

  { 888,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P12",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P12_mf), 0, 24, 2, 1776, 0 },

  { 889,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P13",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P13_br[0]), 0, 21, 2, 1778, 0
  },

  { 890,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P14",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P14_g[0]), 0, 504, 2, 1780, 0
  },

  { 891,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P15",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P15_k), 0, 1, 2, 1782, 0 },

  { 892,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1/P21",
    offsetof(P_NACCBraytonCycle2017a_T, SFunction1_P21_j), 0, 1, 2, 1784, 0 },

  { 893, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_fh), 0, 1, 2, 1786, 0 },

  { 894, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/Saturation1/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation1_UpperSat_a), 0, 1, 2, 1788,
    0 },

  { 895, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/Saturation1/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation1_LowerSat_l), 0, 1, 2, 1790,
    0 },

  { 896, "naccbraytoncycle2017a/Sensor27/Gain2/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain2_Gain_h), 0, 1, 2, 1792, 0 },

  { 897, "naccbraytoncycle2017a/Sensor27/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_gr), 0, 1, 2, 1794, 0 },

  { 898, "naccbraytoncycle2017a/Sensor26/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_cl), 0, 1, 2, 1796, 0 },

  { 899, "naccbraytoncycle2017a/Sensor26/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_kz), 0, 1, 2, 1798, 0 },

  { 900, "naccbraytoncycle2017a/Sensor24/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_el), 0, 1, 2, 1800, 0 },

  { 901, "naccbraytoncycle2017a/Sensor24/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_dv), 0, 1, 2, 1802, 0 },

  { 902, "naccbraytoncycle2017a/Sensor25/addition factor1/Value", offsetof
    (P_NACCBraytonCycle2017a_T, additionfactor1_Value_gl), 0, 1, 2, 1804, 0 },

  { 903, "naccbraytoncycle2017a/Sensor25/Gain1/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain1_Gain_py), 0, 1, 2, 1806, 0 },

  { 904, "naccbraytoncycle2017a/Constant9/Value", offsetof
    (P_NACCBraytonCycle2017a_T, Constant9_Value), 0, 1, 2, 1808, 0 },

  { 905, "naccbraytoncycle2017a/Compressor Pressure Feedback/PFin/Value",
    offsetof(P_NACCBraytonCycle2017a_T, PFin_Value), 0, 1, 2, 1810, 0 },

  { 906, "naccbraytoncycle2017a/HP CTAH/Pressure Loss/Gain/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain_Gain_d), 0, 1, 2, 1812, 0 },

  { 907, "naccbraytoncycle2017a/HP CTAH/Pressure Loss/p_downstrem_min/Value",
    offsetof(P_NACCBraytonCycle2017a_T, p_downstrem_min_Value_e), 0, 1, 2, 1814,
    0 },

  { 908, "naccbraytoncycle2017a/HP CTAH/Pressure Loss/Saturation/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_UpperSat_f), 0, 1, 2, 1816, 0
  },

  { 909, "naccbraytoncycle2017a/HP CTAH/Pressure Loss/Saturation/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_LowerSat_p), 0, 1, 2, 1818, 0
  },

  { 910, "naccbraytoncycle2017a/LP CTAH/Pressure Loss/Gain/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, Gain_Gain_cj), 0, 1, 2, 1820, 0 },

  { 911, "naccbraytoncycle2017a/LP CTAH/Pressure Loss/p_downstrem_min/Value",
    offsetof(P_NACCBraytonCycle2017a_T, p_downstrem_min_Value_n), 0, 1, 2, 1822,
    0 },

  { 912, "naccbraytoncycle2017a/LP CTAH/Pressure Loss/Saturation/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_UpperSat_l), 0, 1, 2, 1824, 0
  },

  { 913, "naccbraytoncycle2017a/LP CTAH/Pressure Loss/Saturation/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T, Saturation_LowerSat_a), 0, 1, 2, 1826, 0
  },

  { 914, "naccbraytoncycle2017a/Natural Gas/MassFlow/Gain/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, MassFlow_m.Gain_Gain), 0, 1, 2, 1828, 0 },

  { 915,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/calculate  conversion/Gain1/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, calculateconversion_n.Gain1_Gain), 0, 1,
    2, 1830, 0 },

  { 916,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/calculate  conversion/Saturation2/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T,
             calculateconversion_n.Saturation2_UpperSat), 0, 1, 2, 1832, 0 },

  { 917,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/calculate  conversion/Saturation2/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T,
             calculateconversion_n.Saturation2_LowerSat), 0, 1, 2, 1834, 0 },

  { 918,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/calculate  conversion/Subsystem1/Saturation2/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T,
             calculateconversion_n.Saturation2_UpperSat_l), 0, 1, 2, 1836, 0 },

  { 919,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/calculate  conversion/Subsystem1/Saturation2/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T,
             calculateconversion_n.Saturation2_LowerSat_h), 0, 1, 2, 1838, 0 },

  { 920,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/calculate  conversion/Gain1/Gain",
    offsetof(P_NACCBraytonCycle2017a_T, calculateconversion.Gain1_Gain), 0, 1, 2,
    1840, 0 },

  { 921,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/calculate  conversion/Saturation2/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T, calculateconversion.Saturation2_UpperSat),
    0, 1, 2, 1842, 0 },

  { 922,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/calculate  conversion/Saturation2/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T, calculateconversion.Saturation2_LowerSat),
    0, 1, 2, 1844, 0 },

  { 923,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/calculate  conversion/Subsystem1/Saturation2/UpperLimit",
    offsetof(P_NACCBraytonCycle2017a_T,
             calculateconversion.Saturation2_UpperSat_l), 0, 1, 2, 1846, 0 },

  { 924,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/calculate  conversion/Subsystem1/Saturation2/LowerLimit",
    offsetof(P_NACCBraytonCycle2017a_T,
             calculateconversion.Saturation2_LowerSat_h), 0, 1, 2, 1848, 0 },

  { 925, "naccbraytoncycle2017a/Ambient air/MassFlow/Gain/Gain", offsetof
    (P_NACCBraytonCycle2017a_T, MassFlow.Gain_Gain), 0, 1, 2, 1850, 0 },
};

static int32_t NI_ParamListSize DataSection(".NIVS.paramlistsize") = 926;
static int32_t NI_ParamDimList[] DataSection(".NIVS.paramdimlist") =
{
  1, 1,                                /* Parameter at index 0 */
  1, 1,                                /* Parameter at index 1 */
  1, 1,                                /* Parameter at index 2 */
  1, 1,                                /* Parameter at index 3 */
  1, 1,                                /* Parameter at index 4 */
  1, 1,                                /* Parameter at index 5 */
  1, 1,                                /* Parameter at index 6 */
  1, 1,                                /* Parameter at index 7 */
  1, 1,                                /* Parameter at index 8 */
  1, 1,                                /* Parameter at index 9 */
  1, 1,                                /* Parameter at index 10 */
  1, 1,                                /* Parameter at index 11 */
  1, 1,                                /* Parameter at index 12 */
  1, 1,                                /* Parameter at index 13 */
  1, 1,                                /* Parameter at index 14 */
  1, 1,                                /* Parameter at index 15 */
  1, 1,                                /* Parameter at index 16 */
  1, 1,                                /* Parameter at index 17 */
  1, 1,                                /* Parameter at index 18 */
  1, 1,                                /* Parameter at index 19 */
  1, 1,                                /* Parameter at index 20 */
  1, 1,                                /* Parameter at index 21 */
  1, 1,                                /* Parameter at index 22 */
  1, 1,                                /* Parameter at index 23 */
  1, 1,                                /* Parameter at index 24 */
  1, 1,                                /* Parameter at index 25 */
  1, 1,                                /* Parameter at index 26 */
  1, 1,                                /* Parameter at index 27 */
  1, 1,                                /* Parameter at index 28 */
  1, 1,                                /* Parameter at index 29 */
  1, 1,                                /* Parameter at index 30 */
  1, 1,                                /* Parameter at index 31 */
  1, 1,                                /* Parameter at index 32 */
  1, 1,                                /* Parameter at index 33 */
  1, 1,                                /* Parameter at index 34 */
  1, 1,                                /* Parameter at index 35 */
  1, 1,                                /* Parameter at index 36 */
  1, 1,                                /* Parameter at index 37 */
  1, 1,                                /* Parameter at index 38 */
  1, 1,                                /* Parameter at index 39 */
  1, 1,                                /* Parameter at index 40 */
  1, 1,                                /* Parameter at index 41 */
  1, 1,                                /* Parameter at index 42 */
  1, 1,                                /* Parameter at index 43 */
  1, 7,                                /* Parameter at index 44 */
  1, 7,                                /* Parameter at index 45 */
  1, 7,                                /* Parameter at index 46 */
  1, 7,                                /* Parameter at index 47 */
  1, 7,                                /* Parameter at index 48 */
  1, 7,                                /* Parameter at index 49 */
  1, 7,                                /* Parameter at index 50 */
  1, 7,                                /* Parameter at index 51 */
  1, 7,                                /* Parameter at index 52 */
  1, 7,                                /* Parameter at index 53 */
  1, 7,                                /* Parameter at index 54 */
  1, 7,                                /* Parameter at index 55 */
  1, 7,                                /* Parameter at index 56 */
  1, 7,                                /* Parameter at index 57 */
  1, 7,                                /* Parameter at index 58 */
  1, 7,                                /* Parameter at index 59 */
  1, 7,                                /* Parameter at index 60 */
  1, 7,                                /* Parameter at index 61 */
  1, 7,                                /* Parameter at index 62 */
  1, 7,                                /* Parameter at index 63 */
  1, 7,                                /* Parameter at index 64 */
  1, 7,                                /* Parameter at index 65 */
  1, 7,                                /* Parameter at index 66 */
  1, 7,                                /* Parameter at index 67 */
  1, 7,                                /* Parameter at index 68 */
  1, 7,                                /* Parameter at index 69 */
  1, 7,                                /* Parameter at index 70 */
  1, 7,                                /* Parameter at index 71 */
  1, 7,                                /* Parameter at index 72 */
  1, 7,                                /* Parameter at index 73 */
  1, 7,                                /* Parameter at index 74 */
  1, 7,                                /* Parameter at index 75 */
  1, 7,                                /* Parameter at index 76 */
  1, 7,                                /* Parameter at index 77 */
  1, 7,                                /* Parameter at index 78 */
  1, 7,                                /* Parameter at index 79 */
  1, 7,                                /* Parameter at index 80 */
  1, 7,                                /* Parameter at index 81 */
  1, 7,                                /* Parameter at index 82 */
  1, 7,                                /* Parameter at index 83 */
  1, 7,                                /* Parameter at index 84 */
  1, 7,                                /* Parameter at index 85 */
  1, 7,                                /* Parameter at index 86 */
  1, 7,                                /* Parameter at index 87 */
  1, 7,                                /* Parameter at index 88 */
  1, 7,                                /* Parameter at index 89 */
  1, 7,                                /* Parameter at index 90 */
  1, 7,                                /* Parameter at index 91 */
  1, 7,                                /* Parameter at index 92 */
  1, 7,                                /* Parameter at index 93 */
  1, 7,                                /* Parameter at index 94 */
  1, 7,                                /* Parameter at index 95 */
  1, 7,                                /* Parameter at index 96 */
  1, 7,                                /* Parameter at index 97 */
  1, 7,                                /* Parameter at index 98 */
  1, 7,                                /* Parameter at index 99 */
  1, 7,                                /* Parameter at index 100 */
  1, 7,                                /* Parameter at index 101 */
  1, 7,                                /* Parameter at index 102 */
  1, 7,                                /* Parameter at index 103 */
  1, 7,                                /* Parameter at index 104 */
  1, 7,                                /* Parameter at index 105 */
  1, 7,                                /* Parameter at index 106 */
  1, 7,                                /* Parameter at index 107 */
  1, 7,                                /* Parameter at index 108 */
  1, 7,                                /* Parameter at index 109 */
  1, 7,                                /* Parameter at index 110 */
  1, 7,                                /* Parameter at index 111 */
  1, 7,                                /* Parameter at index 112 */
  1, 7,                                /* Parameter at index 113 */
  1, 7,                                /* Parameter at index 114 */
  1, 7,                                /* Parameter at index 115 */
  1, 7,                                /* Parameter at index 116 */
  1, 7,                                /* Parameter at index 117 */
  1, 7,                                /* Parameter at index 118 */
  1, 7,                                /* Parameter at index 119 */
  1, 7,                                /* Parameter at index 120 */
  1, 7,                                /* Parameter at index 121 */
  1, 7,                                /* Parameter at index 122 */
  1, 7,                                /* Parameter at index 123 */
  1, 7,                                /* Parameter at index 124 */
  1, 7,                                /* Parameter at index 125 */
  1, 7,                                /* Parameter at index 126 */
  1, 7,                                /* Parameter at index 127 */
  1, 7,                                /* Parameter at index 128 */
  1, 7,                                /* Parameter at index 129 */
  1, 7,                                /* Parameter at index 130 */
  1, 7,                                /* Parameter at index 131 */
  1, 7,                                /* Parameter at index 132 */
  1, 7,                                /* Parameter at index 133 */
  1, 7,                                /* Parameter at index 134 */
  1, 7,                                /* Parameter at index 135 */
  1, 7,                                /* Parameter at index 136 */
  1, 7,                                /* Parameter at index 137 */
  1, 7,                                /* Parameter at index 138 */
  1, 7,                                /* Parameter at index 139 */
  1, 7,                                /* Parameter at index 140 */
  1, 7,                                /* Parameter at index 141 */
  1, 7,                                /* Parameter at index 142 */
  1, 7,                                /* Parameter at index 143 */
  1, 7,                                /* Parameter at index 144 */
  1, 7,                                /* Parameter at index 145 */
  1, 7,                                /* Parameter at index 146 */
  1, 7,                                /* Parameter at index 147 */
  1, 7,                                /* Parameter at index 148 */
  1, 7,                                /* Parameter at index 149 */
  1, 7,                                /* Parameter at index 150 */
  1, 7,                                /* Parameter at index 151 */
  1, 7,                                /* Parameter at index 152 */
  1, 7,                                /* Parameter at index 153 */
  1, 7,                                /* Parameter at index 154 */
  1, 7,                                /* Parameter at index 155 */
  1, 7,                                /* Parameter at index 156 */
  1, 7,                                /* Parameter at index 157 */
  1, 7,                                /* Parameter at index 158 */
  1, 7,                                /* Parameter at index 159 */
  1, 7,                                /* Parameter at index 160 */
  1, 7,                                /* Parameter at index 161 */
  1, 7,                                /* Parameter at index 162 */
  1, 7,                                /* Parameter at index 163 */
  1, 7,                                /* Parameter at index 164 */
  1, 7,                                /* Parameter at index 165 */
  1, 7,                                /* Parameter at index 166 */
  1, 7,                                /* Parameter at index 167 */
  1, 7,                                /* Parameter at index 168 */
  1, 7,                                /* Parameter at index 169 */
  1, 7,                                /* Parameter at index 170 */
  1, 7,                                /* Parameter at index 171 */
  1, 7,                                /* Parameter at index 172 */
  1, 7,                                /* Parameter at index 173 */
  1, 7,                                /* Parameter at index 174 */
  1, 7,                                /* Parameter at index 175 */
  1, 7,                                /* Parameter at index 176 */
  1, 7,                                /* Parameter at index 177 */
  1, 7,                                /* Parameter at index 178 */
  1, 7,                                /* Parameter at index 179 */
  1, 7,                                /* Parameter at index 180 */
  1, 7,                                /* Parameter at index 181 */
  1, 7,                                /* Parameter at index 182 */
  1, 7,                                /* Parameter at index 183 */
  1, 7,                                /* Parameter at index 184 */
  1, 7,                                /* Parameter at index 185 */
  1, 7,                                /* Parameter at index 186 */
  1, 7,                                /* Parameter at index 187 */
  1, 7,                                /* Parameter at index 188 */
  1, 7,                                /* Parameter at index 189 */
  1, 7,                                /* Parameter at index 190 */
  1, 7,                                /* Parameter at index 191 */
  1, 7,                                /* Parameter at index 192 */
  1, 7,                                /* Parameter at index 193 */
  1, 7,                                /* Parameter at index 194 */
  1, 7,                                /* Parameter at index 195 */
  1, 7,                                /* Parameter at index 196 */
  1, 7,                                /* Parameter at index 197 */
  1, 7,                                /* Parameter at index 198 */
  1, 7,                                /* Parameter at index 199 */
  1, 7,                                /* Parameter at index 200 */
  1, 7,                                /* Parameter at index 201 */
  1, 7,                                /* Parameter at index 202 */
  1, 7,                                /* Parameter at index 203 */
  1, 7,                                /* Parameter at index 204 */
  1, 7,                                /* Parameter at index 205 */
  1, 7,                                /* Parameter at index 206 */
  1, 7,                                /* Parameter at index 207 */
  1, 7,                                /* Parameter at index 208 */
  1, 7,                                /* Parameter at index 209 */
  1, 7,                                /* Parameter at index 210 */
  1, 7,                                /* Parameter at index 211 */
  1, 7,                                /* Parameter at index 212 */
  1, 7,                                /* Parameter at index 213 */
  1, 7,                                /* Parameter at index 214 */
  1, 7,                                /* Parameter at index 215 */
  1, 7,                                /* Parameter at index 216 */
  1, 7,                                /* Parameter at index 217 */
  1, 7,                                /* Parameter at index 218 */
  1, 7,                                /* Parameter at index 219 */
  1, 7,                                /* Parameter at index 220 */
  1, 7,                                /* Parameter at index 221 */
  1, 7,                                /* Parameter at index 222 */
  1, 7,                                /* Parameter at index 223 */
  1, 7,                                /* Parameter at index 224 */
  1, 7,                                /* Parameter at index 225 */
  1, 7,                                /* Parameter at index 226 */
  1, 7,                                /* Parameter at index 227 */
  1, 7,                                /* Parameter at index 228 */
  1, 7,                                /* Parameter at index 229 */
  1, 7,                                /* Parameter at index 230 */
  1, 7,                                /* Parameter at index 231 */
  1, 7,                                /* Parameter at index 232 */
  1, 7,                                /* Parameter at index 233 */
  1, 7,                                /* Parameter at index 234 */
  1, 7,                                /* Parameter at index 235 */
  1, 7,                                /* Parameter at index 236 */
  1, 7,                                /* Parameter at index 237 */
  1, 7,                                /* Parameter at index 238 */
  1, 7,                                /* Parameter at index 239 */
  1, 7,                                /* Parameter at index 240 */
  1, 7,                                /* Parameter at index 241 */
  1, 7,                                /* Parameter at index 242 */
  1, 7,                                /* Parameter at index 243 */
  1, 7,                                /* Parameter at index 244 */
  1, 7,                                /* Parameter at index 245 */
  1, 7,                                /* Parameter at index 246 */
  1, 7,                                /* Parameter at index 247 */
  1, 7,                                /* Parameter at index 248 */
  1, 7,                                /* Parameter at index 249 */
  1, 7,                                /* Parameter at index 250 */
  1, 7,                                /* Parameter at index 251 */
  1, 7,                                /* Parameter at index 252 */
  1, 7,                                /* Parameter at index 253 */
  1, 7,                                /* Parameter at index 254 */
  1, 7,                                /* Parameter at index 255 */
  1, 7,                                /* Parameter at index 256 */
  1, 7,                                /* Parameter at index 257 */
  1, 7,                                /* Parameter at index 258 */
  1, 7,                                /* Parameter at index 259 */
  1, 7,                                /* Parameter at index 260 */
  1, 7,                                /* Parameter at index 261 */
  1, 7,                                /* Parameter at index 262 */
  1, 7,                                /* Parameter at index 263 */
  1, 7,                                /* Parameter at index 264 */
  1, 7,                                /* Parameter at index 265 */
  1, 7,                                /* Parameter at index 266 */
  1, 7,                                /* Parameter at index 267 */
  1, 7,                                /* Parameter at index 268 */
  1, 7,                                /* Parameter at index 269 */
  1, 7,                                /* Parameter at index 270 */
  1, 7,                                /* Parameter at index 271 */
  1, 7,                                /* Parameter at index 272 */
  1, 7,                                /* Parameter at index 273 */
  1, 7,                                /* Parameter at index 274 */
  1, 7,                                /* Parameter at index 275 */
  1, 7,                                /* Parameter at index 276 */
  1, 7,                                /* Parameter at index 277 */
  1, 7,                                /* Parameter at index 278 */
  1, 7,                                /* Parameter at index 279 */
  1, 7,                                /* Parameter at index 280 */
  1, 7,                                /* Parameter at index 281 */
  1, 7,                                /* Parameter at index 282 */
  1, 7,                                /* Parameter at index 283 */
  1, 7,                                /* Parameter at index 284 */
  1, 7,                                /* Parameter at index 285 */
  1, 7,                                /* Parameter at index 286 */
  1, 7,                                /* Parameter at index 287 */
  1, 7,                                /* Parameter at index 288 */
  1, 7,                                /* Parameter at index 289 */
  1, 7,                                /* Parameter at index 290 */
  1, 7,                                /* Parameter at index 291 */
  1, 7,                                /* Parameter at index 292 */
  1, 7,                                /* Parameter at index 293 */
  1, 7,                                /* Parameter at index 294 */
  1, 7,                                /* Parameter at index 295 */
  1, 7,                                /* Parameter at index 296 */
  1, 7,                                /* Parameter at index 297 */
  1, 7,                                /* Parameter at index 298 */
  1, 7,                                /* Parameter at index 299 */
  1, 7,                                /* Parameter at index 300 */
  1, 7,                                /* Parameter at index 301 */
  1, 7,                                /* Parameter at index 302 */
  1, 7,                                /* Parameter at index 303 */
  1, 7,                                /* Parameter at index 304 */
  1, 7,                                /* Parameter at index 305 */
  1, 7,                                /* Parameter at index 306 */
  1, 7,                                /* Parameter at index 307 */
  1, 7,                                /* Parameter at index 308 */
  1, 7,                                /* Parameter at index 309 */
  1, 7,                                /* Parameter at index 310 */
  1, 7,                                /* Parameter at index 311 */
  1, 1,                                /* Parameter at index 312 */
  1, 1,                                /* Parameter at index 313 */
  1, 1,                                /* Parameter at index 314 */
  1, 7,                                /* Parameter at index 315 */
  1, 7,                                /* Parameter at index 316 */
  1, 7,                                /* Parameter at index 317 */
  1, 7,                                /* Parameter at index 318 */
  1, 7,                                /* Parameter at index 319 */
  1, 7,                                /* Parameter at index 320 */
  1, 7,                                /* Parameter at index 321 */
  1, 7,                                /* Parameter at index 322 */
  1, 7,                                /* Parameter at index 323 */
  1, 7,                                /* Parameter at index 324 */
  1, 7,                                /* Parameter at index 325 */
  1, 7,                                /* Parameter at index 326 */
  1, 7,                                /* Parameter at index 327 */
  1, 7,                                /* Parameter at index 328 */
  1, 7,                                /* Parameter at index 329 */
  1, 7,                                /* Parameter at index 330 */
  1, 7,                                /* Parameter at index 331 */
  1, 7,                                /* Parameter at index 332 */
  1, 7,                                /* Parameter at index 333 */
  1, 7,                                /* Parameter at index 334 */
  1, 7,                                /* Parameter at index 335 */
  1, 7,                                /* Parameter at index 336 */
  1, 7,                                /* Parameter at index 337 */
  1, 7,                                /* Parameter at index 338 */
  1, 7,                                /* Parameter at index 339 */
  1, 7,                                /* Parameter at index 340 */
  1, 7,                                /* Parameter at index 341 */
  1, 7,                                /* Parameter at index 342 */
  1, 7,                                /* Parameter at index 343 */
  1, 7,                                /* Parameter at index 344 */
  1, 7,                                /* Parameter at index 345 */
  1, 7,                                /* Parameter at index 346 */
  1, 7,                                /* Parameter at index 347 */
  1, 7,                                /* Parameter at index 348 */
  1, 7,                                /* Parameter at index 349 */
  1, 7,                                /* Parameter at index 350 */
  1, 7,                                /* Parameter at index 351 */
  1, 7,                                /* Parameter at index 352 */
  1, 7,                                /* Parameter at index 353 */
  1, 7,                                /* Parameter at index 354 */
  1, 7,                                /* Parameter at index 355 */
  1, 7,                                /* Parameter at index 356 */
  1, 7,                                /* Parameter at index 357 */
  1, 7,                                /* Parameter at index 358 */
  1, 7,                                /* Parameter at index 359 */
  1, 7,                                /* Parameter at index 360 */
  1, 7,                                /* Parameter at index 361 */
  1, 7,                                /* Parameter at index 362 */
  1, 7,                                /* Parameter at index 363 */
  1, 7,                                /* Parameter at index 364 */
  1, 7,                                /* Parameter at index 365 */
  1, 7,                                /* Parameter at index 366 */
  1, 7,                                /* Parameter at index 367 */
  1, 7,                                /* Parameter at index 368 */
  1, 7,                                /* Parameter at index 369 */
  1, 7,                                /* Parameter at index 370 */
  1, 7,                                /* Parameter at index 371 */
  1, 7,                                /* Parameter at index 372 */
  1, 7,                                /* Parameter at index 373 */
  1, 7,                                /* Parameter at index 374 */
  1, 7,                                /* Parameter at index 375 */
  1, 7,                                /* Parameter at index 376 */
  1, 7,                                /* Parameter at index 377 */
  1, 7,                                /* Parameter at index 378 */
  1, 7,                                /* Parameter at index 379 */
  1, 7,                                /* Parameter at index 380 */
  1, 7,                                /* Parameter at index 381 */
  1, 7,                                /* Parameter at index 382 */
  1, 7,                                /* Parameter at index 383 */
  1, 7,                                /* Parameter at index 384 */
  1, 7,                                /* Parameter at index 385 */
  1, 7,                                /* Parameter at index 386 */
  1, 7,                                /* Parameter at index 387 */
  1, 7,                                /* Parameter at index 388 */
  1, 7,                                /* Parameter at index 389 */
  1, 7,                                /* Parameter at index 390 */
  1, 7,                                /* Parameter at index 391 */
  1, 7,                                /* Parameter at index 392 */
  1, 7,                                /* Parameter at index 393 */
  1, 7,                                /* Parameter at index 394 */
  1, 7,                                /* Parameter at index 395 */
  1, 7,                                /* Parameter at index 396 */
  1, 7,                                /* Parameter at index 397 */
  1, 7,                                /* Parameter at index 398 */
  1, 7,                                /* Parameter at index 399 */
  1, 7,                                /* Parameter at index 400 */
  1, 7,                                /* Parameter at index 401 */
  1, 7,                                /* Parameter at index 402 */
  1, 1,                                /* Parameter at index 403 */
  1, 1,                                /* Parameter at index 404 */
  1, 1,                                /* Parameter at index 405 */
  1, 1,                                /* Parameter at index 406 */
  1, 1,                                /* Parameter at index 407 */
  1, 1,                                /* Parameter at index 408 */
  1, 1,                                /* Parameter at index 409 */
  1, 1,                                /* Parameter at index 410 */
  1, 1,                                /* Parameter at index 411 */
  1, 1,                                /* Parameter at index 412 */
  1, 1,                                /* Parameter at index 413 */
  1, 1,                                /* Parameter at index 414 */
  1, 1,                                /* Parameter at index 415 */
  1, 1,                                /* Parameter at index 416 */
  1, 1,                                /* Parameter at index 417 */
  1, 1,                                /* Parameter at index 418 */
  1, 1,                                /* Parameter at index 419 */
  1, 1,                                /* Parameter at index 420 */
  1, 1,                                /* Parameter at index 421 */
  1, 1,                                /* Parameter at index 422 */
  1, 1,                                /* Parameter at index 423 */
  1, 1,                                /* Parameter at index 424 */
  1, 1,                                /* Parameter at index 425 */
  1, 1,                                /* Parameter at index 426 */
  1, 7,                                /* Parameter at index 427 */
  1, 7,                                /* Parameter at index 428 */
  1, 7,                                /* Parameter at index 429 */
  1, 7,                                /* Parameter at index 430 */
  1, 7,                                /* Parameter at index 431 */
  1, 7,                                /* Parameter at index 432 */
  1, 7,                                /* Parameter at index 433 */
  1, 7,                                /* Parameter at index 434 */
  1, 7,                                /* Parameter at index 435 */
  1, 7,                                /* Parameter at index 436 */
  1, 7,                                /* Parameter at index 437 */
  1, 7,                                /* Parameter at index 438 */
  1, 7,                                /* Parameter at index 439 */
  1, 7,                                /* Parameter at index 440 */
  1, 7,                                /* Parameter at index 441 */
  1, 7,                                /* Parameter at index 442 */
  1, 7,                                /* Parameter at index 443 */
  1, 1,                                /* Parameter at index 444 */
  1, 1,                                /* Parameter at index 445 */
  1, 1,                                /* Parameter at index 446 */
  1, 1,                                /* Parameter at index 447 */
  1, 1,                                /* Parameter at index 448 */
  1, 1,                                /* Parameter at index 449 */
  1, 1,                                /* Parameter at index 450 */
  1, 1,                                /* Parameter at index 451 */
  1, 1,                                /* Parameter at index 452 */
  1, 1,                                /* Parameter at index 453 */
  1, 1,                                /* Parameter at index 454 */
  1, 1,                                /* Parameter at index 455 */
  1, 1,                                /* Parameter at index 456 */
  1, 1,                                /* Parameter at index 457 */
  1, 1,                                /* Parameter at index 458 */
  1, 1,                                /* Parameter at index 459 */
  1, 1,                                /* Parameter at index 460 */
  1, 1,                                /* Parameter at index 461 */
  1, 1,                                /* Parameter at index 462 */
  1, 1,                                /* Parameter at index 463 */
  1, 1,                                /* Parameter at index 464 */
  1, 1,                                /* Parameter at index 465 */
  1, 7,                                /* Parameter at index 466 */
  1, 7,                                /* Parameter at index 467 */
  1, 7,                                /* Parameter at index 468 */
  1, 7,                                /* Parameter at index 469 */
  1, 7,                                /* Parameter at index 470 */
  1, 7,                                /* Parameter at index 471 */
  1, 7,                                /* Parameter at index 472 */
  1, 7,                                /* Parameter at index 473 */
  1, 7,                                /* Parameter at index 474 */
  1, 7,                                /* Parameter at index 475 */
  1, 7,                                /* Parameter at index 476 */
  1, 7,                                /* Parameter at index 477 */
  1, 7,                                /* Parameter at index 478 */
  1, 7,                                /* Parameter at index 479 */
  1, 7,                                /* Parameter at index 480 */
  1, 7,                                /* Parameter at index 481 */
  1, 7,                                /* Parameter at index 482 */
  1, 7,                                /* Parameter at index 483 */
  1, 7,                                /* Parameter at index 484 */
  1, 7,                                /* Parameter at index 485 */
  1, 7,                                /* Parameter at index 486 */
  1, 7,                                /* Parameter at index 487 */
  1, 7,                                /* Parameter at index 488 */
  1, 7,                                /* Parameter at index 489 */
  1, 7,                                /* Parameter at index 490 */
  1, 7,                                /* Parameter at index 491 */
  1, 7,                                /* Parameter at index 492 */
  1, 7,                                /* Parameter at index 493 */
  1, 7,                                /* Parameter at index 494 */
  1, 7,                                /* Parameter at index 495 */
  1, 7,                                /* Parameter at index 496 */
  1, 7,                                /* Parameter at index 497 */
  1, 7,                                /* Parameter at index 498 */
  1, 7,                                /* Parameter at index 499 */
  1, 7,                                /* Parameter at index 500 */
  1, 7,                                /* Parameter at index 501 */
  1, 7,                                /* Parameter at index 502 */
  1, 7,                                /* Parameter at index 503 */
  1, 7,                                /* Parameter at index 504 */
  1, 7,                                /* Parameter at index 505 */
  1, 7,                                /* Parameter at index 506 */
  1, 7,                                /* Parameter at index 507 */
  1, 7,                                /* Parameter at index 508 */
  1, 7,                                /* Parameter at index 509 */
  1, 7,                                /* Parameter at index 510 */
  1, 7,                                /* Parameter at index 511 */
  1, 7,                                /* Parameter at index 512 */
  1, 7,                                /* Parameter at index 513 */
  1, 7,                                /* Parameter at index 514 */
  1, 7,                                /* Parameter at index 515 */
  1, 7,                                /* Parameter at index 516 */
  1, 7,                                /* Parameter at index 517 */
  1, 7,                                /* Parameter at index 518 */
  1, 7,                                /* Parameter at index 519 */
  1, 7,                                /* Parameter at index 520 */
  1, 7,                                /* Parameter at index 521 */
  1, 7,                                /* Parameter at index 522 */
  1, 7,                                /* Parameter at index 523 */
  1, 7,                                /* Parameter at index 524 */
  1, 7,                                /* Parameter at index 525 */
  1, 7,                                /* Parameter at index 526 */
  1, 7,                                /* Parameter at index 527 */
  1, 7,                                /* Parameter at index 528 */
  1, 7,                                /* Parameter at index 529 */
  1, 7,                                /* Parameter at index 530 */
  1, 7,                                /* Parameter at index 531 */
  1, 7,                                /* Parameter at index 532 */
  1, 7,                                /* Parameter at index 533 */
  1, 7,                                /* Parameter at index 534 */
  1, 7,                                /* Parameter at index 535 */
  1, 7,                                /* Parameter at index 536 */
  1, 7,                                /* Parameter at index 537 */
  1, 7,                                /* Parameter at index 538 */
  1, 7,                                /* Parameter at index 539 */
  1, 7,                                /* Parameter at index 540 */
  1, 7,                                /* Parameter at index 541 */
  1, 7,                                /* Parameter at index 542 */
  1, 1,                                /* Parameter at index 543 */
  1, 1,                                /* Parameter at index 544 */
  1, 1,                                /* Parameter at index 545 */
  1, 1,                                /* Parameter at index 546 */
  1, 1,                                /* Parameter at index 547 */
  1, 1,                                /* Parameter at index 548 */
  1, 1,                                /* Parameter at index 549 */
  1, 1,                                /* Parameter at index 550 */
  1, 1,                                /* Parameter at index 551 */
  1, 1,                                /* Parameter at index 552 */
  1, 1,                                /* Parameter at index 553 */
  1, 1,                                /* Parameter at index 554 */
  1, 1,                                /* Parameter at index 555 */
  7, 7,                                /* Parameter at index 556 */
  7, 7,                                /* Parameter at index 557 */
  24, 1,                               /* Parameter at index 558 */
  1, 21,                               /* Parameter at index 559 */
  24, 21,                              /* Parameter at index 560 */
  1, 1,                                /* Parameter at index 561 */
  1, 1,                                /* Parameter at index 562 */
  7, 7,                                /* Parameter at index 563 */
  7, 7,                                /* Parameter at index 564 */
  7, 4,                                /* Parameter at index 565 */
  24, 1,                               /* Parameter at index 566 */
  1, 21,                               /* Parameter at index 567 */
  24, 21,                              /* Parameter at index 568 */
  1, 1,                                /* Parameter at index 569 */
  1, 1,                                /* Parameter at index 570 */
  1, 1,                                /* Parameter at index 571 */
  7, 7,                                /* Parameter at index 572 */
  7, 7,                                /* Parameter at index 573 */
  7, 4,                                /* Parameter at index 574 */
  24, 1,                               /* Parameter at index 575 */
  1, 21,                               /* Parameter at index 576 */
  24, 21,                              /* Parameter at index 577 */
  1, 1,                                /* Parameter at index 578 */
  1, 1,                                /* Parameter at index 579 */
  1, 1,                                /* Parameter at index 580 */
  1, 1,                                /* Parameter at index 581 */
  1, 1,                                /* Parameter at index 582 */
  1, 1,                                /* Parameter at index 583 */
  1, 1,                                /* Parameter at index 584 */
  1, 1,                                /* Parameter at index 585 */
  7, 7,                                /* Parameter at index 586 */
  7, 7,                                /* Parameter at index 587 */
  7, 4,                                /* Parameter at index 588 */
  24, 1,                               /* Parameter at index 589 */
  1, 21,                               /* Parameter at index 590 */
  24, 21,                              /* Parameter at index 591 */
  1, 1,                                /* Parameter at index 592 */
  1, 1,                                /* Parameter at index 593 */
  1, 1,                                /* Parameter at index 594 */
  7, 7,                                /* Parameter at index 595 */
  7, 7,                                /* Parameter at index 596 */
  7, 4,                                /* Parameter at index 597 */
  24, 1,                               /* Parameter at index 598 */
  1, 21,                               /* Parameter at index 599 */
  24, 21,                              /* Parameter at index 600 */
  1, 1,                                /* Parameter at index 601 */
  1, 1,                                /* Parameter at index 602 */
  1, 1,                                /* Parameter at index 603 */
  1, 1,                                /* Parameter at index 604 */
  1, 1,                                /* Parameter at index 605 */
  1, 1,                                /* Parameter at index 606 */
  1, 1,                                /* Parameter at index 607 */
  1, 1,                                /* Parameter at index 608 */
  1, 1,                                /* Parameter at index 609 */
  1, 1,                                /* Parameter at index 610 */
  7, 7,                                /* Parameter at index 611 */
  7, 7,                                /* Parameter at index 612 */
  24, 1,                               /* Parameter at index 613 */
  1, 21,                               /* Parameter at index 614 */
  24, 21,                              /* Parameter at index 615 */
  1, 1,                                /* Parameter at index 616 */
  1, 1,                                /* Parameter at index 617 */
  7, 7,                                /* Parameter at index 618 */
  7, 7,                                /* Parameter at index 619 */
  7, 4,                                /* Parameter at index 620 */
  24, 1,                               /* Parameter at index 621 */
  1, 21,                               /* Parameter at index 622 */
  24, 21,                              /* Parameter at index 623 */
  1, 1,                                /* Parameter at index 624 */
  1, 1,                                /* Parameter at index 625 */
  1, 1,                                /* Parameter at index 626 */
  1, 6,                                /* Parameter at index 627 */
  1, 21,                               /* Parameter at index 628 */
  1, 126,                              /* Parameter at index 629 */
  1, 1,                                /* Parameter at index 630 */
  1, 1,                                /* Parameter at index 631 */
  1, 6,                                /* Parameter at index 632 */
  1, 21,                               /* Parameter at index 633 */
  1, 126,                              /* Parameter at index 634 */
  1, 1,                                /* Parameter at index 635 */
  1, 1,                                /* Parameter at index 636 */
  1, 1,                                /* Parameter at index 637 */
  1, 1,                                /* Parameter at index 638 */
  1, 1,                                /* Parameter at index 639 */
  7, 7,                                /* Parameter at index 640 */
  7, 7,                                /* Parameter at index 641 */
  7, 4,                                /* Parameter at index 642 */
  24, 1,                               /* Parameter at index 643 */
  1, 21,                               /* Parameter at index 644 */
  24, 21,                              /* Parameter at index 645 */
  1, 1,                                /* Parameter at index 646 */
  1, 1,                                /* Parameter at index 647 */
  1, 1,                                /* Parameter at index 648 */
  1, 1,                                /* Parameter at index 649 */
  7, 7,                                /* Parameter at index 650 */
  7, 7,                                /* Parameter at index 651 */
  7, 4,                                /* Parameter at index 652 */
  24, 1,                               /* Parameter at index 653 */
  1, 21,                               /* Parameter at index 654 */
  24, 21,                              /* Parameter at index 655 */
  1, 1,                                /* Parameter at index 656 */
  1, 1,                                /* Parameter at index 657 */
  1, 1,                                /* Parameter at index 658 */
  1, 1,                                /* Parameter at index 659 */
  7, 7,                                /* Parameter at index 660 */
  7, 7,                                /* Parameter at index 661 */
  7, 4,                                /* Parameter at index 662 */
  24, 1,                               /* Parameter at index 663 */
  1, 21,                               /* Parameter at index 664 */
  24, 21,                              /* Parameter at index 665 */
  1, 1,                                /* Parameter at index 666 */
  1, 1,                                /* Parameter at index 667 */
  1, 1,                                /* Parameter at index 668 */
  1, 6,                                /* Parameter at index 669 */
  1, 21,                               /* Parameter at index 670 */
  1, 126,                              /* Parameter at index 671 */
  1, 1,                                /* Parameter at index 672 */
  1, 1,                                /* Parameter at index 673 */
  1, 6,                                /* Parameter at index 674 */
  1, 21,                               /* Parameter at index 675 */
  1, 126,                              /* Parameter at index 676 */
  1, 1,                                /* Parameter at index 677 */
  1, 1,                                /* Parameter at index 678 */
  1, 1,                                /* Parameter at index 679 */
  1, 1,                                /* Parameter at index 680 */
  1, 1,                                /* Parameter at index 681 */
  7, 7,                                /* Parameter at index 682 */
  7, 7,                                /* Parameter at index 683 */
  7, 4,                                /* Parameter at index 684 */
  24, 1,                               /* Parameter at index 685 */
  1, 21,                               /* Parameter at index 686 */
  24, 21,                              /* Parameter at index 687 */
  1, 1,                                /* Parameter at index 688 */
  1, 1,                                /* Parameter at index 689 */
  1, 1,                                /* Parameter at index 690 */
  1, 1,                                /* Parameter at index 691 */
  7, 7,                                /* Parameter at index 692 */
  7, 7,                                /* Parameter at index 693 */
  7, 4,                                /* Parameter at index 694 */
  24, 1,                               /* Parameter at index 695 */
  1, 21,                               /* Parameter at index 696 */
  24, 21,                              /* Parameter at index 697 */
  1, 1,                                /* Parameter at index 698 */
  1, 1,                                /* Parameter at index 699 */
  1, 1,                                /* Parameter at index 700 */
  1, 1,                                /* Parameter at index 701 */
  1, 1,                                /* Parameter at index 702 */
  1, 1,                                /* Parameter at index 703 */
  1, 1,                                /* Parameter at index 704 */
  1, 1,                                /* Parameter at index 705 */
  1, 1,                                /* Parameter at index 706 */
  1, 1,                                /* Parameter at index 707 */
  7, 7,                                /* Parameter at index 708 */
  7, 7,                                /* Parameter at index 709 */
  7, 4,                                /* Parameter at index 710 */
  24, 1,                               /* Parameter at index 711 */
  1, 21,                               /* Parameter at index 712 */
  24, 21,                              /* Parameter at index 713 */
  1, 1,                                /* Parameter at index 714 */
  1, 1,                                /* Parameter at index 715 */
  1, 1,                                /* Parameter at index 716 */
  1, 1,                                /* Parameter at index 717 */
  1, 1,                                /* Parameter at index 718 */
  1, 1,                                /* Parameter at index 719 */
  1, 1,                                /* Parameter at index 720 */
  1, 1,                                /* Parameter at index 721 */
  1, 1,                                /* Parameter at index 722 */
  1, 1,                                /* Parameter at index 723 */
  1, 1,                                /* Parameter at index 724 */
  1, 1,                                /* Parameter at index 725 */
  1, 1,                                /* Parameter at index 726 */
  1, 1,                                /* Parameter at index 727 */
  7, 7,                                /* Parameter at index 728 */
  7, 7,                                /* Parameter at index 729 */
  24, 1,                               /* Parameter at index 730 */
  1, 21,                               /* Parameter at index 731 */
  24, 21,                              /* Parameter at index 732 */
  1, 1,                                /* Parameter at index 733 */
  1, 1,                                /* Parameter at index 734 */
  1, 1,                                /* Parameter at index 735 */
  1, 1,                                /* Parameter at index 736 */
  1, 1,                                /* Parameter at index 737 */
  1, 1,                                /* Parameter at index 738 */
  1, 1,                                /* Parameter at index 739 */
  1, 1,                                /* Parameter at index 740 */
  1, 1,                                /* Parameter at index 741 */
  1, 1,                                /* Parameter at index 742 */
  1, 1,                                /* Parameter at index 743 */
  1, 1,                                /* Parameter at index 744 */
  1, 1,                                /* Parameter at index 745 */
  1, 1,                                /* Parameter at index 746 */
  1, 1,                                /* Parameter at index 747 */
  7, 7,                                /* Parameter at index 748 */
  7, 7,                                /* Parameter at index 749 */
  24, 1,                               /* Parameter at index 750 */
  1, 21,                               /* Parameter at index 751 */
  24, 21,                              /* Parameter at index 752 */
  1, 1,                                /* Parameter at index 753 */
  1, 1,                                /* Parameter at index 754 */
  1, 1,                                /* Parameter at index 755 */
  1, 1,                                /* Parameter at index 756 */
  1, 1,                                /* Parameter at index 757 */
  1, 1,                                /* Parameter at index 758 */
  1, 1,                                /* Parameter at index 759 */
  1, 1,                                /* Parameter at index 760 */
  1, 1,                                /* Parameter at index 761 */
  1, 1,                                /* Parameter at index 762 */
  1, 1,                                /* Parameter at index 763 */
  1, 1,                                /* Parameter at index 764 */
  1, 1,                                /* Parameter at index 765 */
  1, 1,                                /* Parameter at index 766 */
  1, 1,                                /* Parameter at index 767 */
  1, 1,                                /* Parameter at index 768 */
  1, 1,                                /* Parameter at index 769 */
  1, 1,                                /* Parameter at index 770 */
  1, 1,                                /* Parameter at index 771 */
  1, 1,                                /* Parameter at index 772 */
  1, 4,                                /* Parameter at index 773 */
  1, 1,                                /* Parameter at index 774 */
  1, 1,                                /* Parameter at index 775 */
  1, 1,                                /* Parameter at index 776 */
  1, 1,                                /* Parameter at index 777 */
  1, 1,                                /* Parameter at index 778 */
  1, 1,                                /* Parameter at index 779 */
  1, 1,                                /* Parameter at index 780 */
  1, 1,                                /* Parameter at index 781 */
  1, 1,                                /* Parameter at index 782 */
  1, 1,                                /* Parameter at index 783 */
  1, 1,                                /* Parameter at index 784 */
  1, 1,                                /* Parameter at index 785 */
  1, 1,                                /* Parameter at index 786 */
  1, 1,                                /* Parameter at index 787 */
  1, 1,                                /* Parameter at index 788 */
  1, 1,                                /* Parameter at index 789 */
  1, 1,                                /* Parameter at index 790 */
  1, 1,                                /* Parameter at index 791 */
  1, 1,                                /* Parameter at index 792 */
  1, 1,                                /* Parameter at index 793 */
  1, 1,                                /* Parameter at index 794 */
  1, 1,                                /* Parameter at index 795 */
  1, 1,                                /* Parameter at index 796 */
  1, 1,                                /* Parameter at index 797 */
  1, 1,                                /* Parameter at index 798 */
  1, 1,                                /* Parameter at index 799 */
  1, 1,                                /* Parameter at index 800 */
  1, 1,                                /* Parameter at index 801 */
  1, 1,                                /* Parameter at index 802 */
  1, 1,                                /* Parameter at index 803 */
  1, 1,                                /* Parameter at index 804 */
  1, 1,                                /* Parameter at index 805 */
  1, 1,                                /* Parameter at index 806 */
  1, 1,                                /* Parameter at index 807 */
  1, 1,                                /* Parameter at index 808 */
  1, 1,                                /* Parameter at index 809 */
  1, 1,                                /* Parameter at index 810 */
  1, 1,                                /* Parameter at index 811 */
  1, 1,                                /* Parameter at index 812 */
  1, 1,                                /* Parameter at index 813 */
  1, 1,                                /* Parameter at index 814 */
  1, 1,                                /* Parameter at index 815 */
  1, 1,                                /* Parameter at index 816 */
  1, 1,                                /* Parameter at index 817 */
  1, 1,                                /* Parameter at index 818 */
  7, 7,                                /* Parameter at index 819 */
  7, 7,                                /* Parameter at index 820 */
  24, 1,                               /* Parameter at index 821 */
  1, 21,                               /* Parameter at index 822 */
  24, 21,                              /* Parameter at index 823 */
  1, 1,                                /* Parameter at index 824 */
  1, 1,                                /* Parameter at index 825 */
  1, 1,                                /* Parameter at index 826 */
  1, 1,                                /* Parameter at index 827 */
  1, 1,                                /* Parameter at index 828 */
  1, 1,                                /* Parameter at index 829 */
  1, 1,                                /* Parameter at index 830 */
  1, 1,                                /* Parameter at index 831 */
  1, 1,                                /* Parameter at index 832 */
  1, 1,                                /* Parameter at index 833 */
  1, 1,                                /* Parameter at index 834 */
  1, 1,                                /* Parameter at index 835 */
  1, 1,                                /* Parameter at index 836 */
  1, 1,                                /* Parameter at index 837 */
  1, 1,                                /* Parameter at index 838 */
  1, 1,                                /* Parameter at index 839 */
  1, 1,                                /* Parameter at index 840 */
  1, 1,                                /* Parameter at index 841 */
  1, 1,                                /* Parameter at index 842 */
  1, 1,                                /* Parameter at index 843 */
  1, 1,                                /* Parameter at index 844 */
  1, 1,                                /* Parameter at index 845 */
  1, 1,                                /* Parameter at index 846 */
  1, 1,                                /* Parameter at index 847 */
  1, 1,                                /* Parameter at index 848 */
  1, 1,                                /* Parameter at index 849 */
  1, 1,                                /* Parameter at index 850 */
  1, 1,                                /* Parameter at index 851 */
  1, 1,                                /* Parameter at index 852 */
  1, 1,                                /* Parameter at index 853 */
  1, 1,                                /* Parameter at index 854 */
  1, 1,                                /* Parameter at index 855 */
  1, 1,                                /* Parameter at index 856 */
  1, 1,                                /* Parameter at index 857 */
  1, 1,                                /* Parameter at index 858 */
  1, 1,                                /* Parameter at index 859 */
  1, 1,                                /* Parameter at index 860 */
  1, 1,                                /* Parameter at index 861 */
  1, 1,                                /* Parameter at index 862 */
  1, 1,                                /* Parameter at index 863 */
  1, 1,                                /* Parameter at index 864 */
  1, 1,                                /* Parameter at index 865 */
  1, 1,                                /* Parameter at index 866 */
  1, 1,                                /* Parameter at index 867 */
  1, 1,                                /* Parameter at index 868 */
  1, 1,                                /* Parameter at index 869 */
  1, 1,                                /* Parameter at index 870 */
  1, 1,                                /* Parameter at index 871 */
  1, 1,                                /* Parameter at index 872 */
  1, 1,                                /* Parameter at index 873 */
  1, 1,                                /* Parameter at index 874 */
  1, 1,                                /* Parameter at index 875 */
  1, 1,                                /* Parameter at index 876 */
  1, 1,                                /* Parameter at index 877 */
  1, 1,                                /* Parameter at index 878 */
  1, 1,                                /* Parameter at index 879 */
  1, 1,                                /* Parameter at index 880 */
  1, 1,                                /* Parameter at index 881 */
  1, 1,                                /* Parameter at index 882 */
  1, 1,                                /* Parameter at index 883 */
  1, 1,                                /* Parameter at index 884 */
  1, 1,                                /* Parameter at index 885 */
  7, 7,                                /* Parameter at index 886 */
  7, 7,                                /* Parameter at index 887 */
  24, 1,                               /* Parameter at index 888 */
  1, 21,                               /* Parameter at index 889 */
  24, 21,                              /* Parameter at index 890 */
  1, 1,                                /* Parameter at index 891 */
  1, 1,                                /* Parameter at index 892 */
  1, 1,                                /* Parameter at index 893 */
  1, 1,                                /* Parameter at index 894 */
  1, 1,                                /* Parameter at index 895 */
  1, 1,                                /* Parameter at index 896 */
  1, 1,                                /* Parameter at index 897 */
  1, 1,                                /* Parameter at index 898 */
  1, 1,                                /* Parameter at index 899 */
  1, 1,                                /* Parameter at index 900 */
  1, 1,                                /* Parameter at index 901 */
  1, 1,                                /* Parameter at index 902 */
  1, 1,                                /* Parameter at index 903 */
  1, 1,                                /* Parameter at index 904 */
  1, 1,                                /* Parameter at index 905 */
  1, 1,                                /* Parameter at index 906 */
  1, 1,                                /* Parameter at index 907 */
  1, 1,                                /* Parameter at index 908 */
  1, 1,                                /* Parameter at index 909 */
  1, 1,                                /* Parameter at index 910 */
  1, 1,                                /* Parameter at index 911 */
  1, 1,                                /* Parameter at index 912 */
  1, 1,                                /* Parameter at index 913 */
  1, 1,                                /* Parameter at index 914 */
  1, 1,                                /* Parameter at index 915 */
  1, 1,                                /* Parameter at index 916 */
  1, 1,                                /* Parameter at index 917 */
  1, 1,                                /* Parameter at index 918 */
  1, 1,                                /* Parameter at index 919 */
  1, 1,                                /* Parameter at index 920 */
  1, 1,                                /* Parameter at index 921 */
  1, 1,                                /* Parameter at index 922 */
  1, 1,                                /* Parameter at index 923 */
  1, 1,                                /* Parameter at index 924 */
  1, 1,                                /* Parameter at index 925 */
};

static NI_Signal NI_SigList[] DataSection(".NIVS.siglist") =
{
  { 0, "naccbraytoncycle2017a/In1", 0, "", offsetof(ExtU_NACCBraytonCycle2017a_T,
    In1) + (0*sizeof(real_T)), EXTIO_SIG, 0, 1, 2, 0, 0 },

  { 1, "naccbraytoncycle2017a/In2", 0, "", offsetof(ExtU_NACCBraytonCycle2017a_T,
    In2) + (0*sizeof(real_T)), EXTIO_SIG, 0, 1, 2, 0, 0 },

  { 2, "naccbraytoncycle2017a/In3", 0, "", offsetof(ExtU_NACCBraytonCycle2017a_T,
    In3) + (0*sizeof(real_T)), EXTIO_SIG, 0, 1, 2, 0, 0 },

  { 3, "naccbraytoncycle2017a/In4", 0, "", offsetof(ExtU_NACCBraytonCycle2017a_T,
    In4) + (0*sizeof(real_T)), EXTIO_SIG, 0, 1, 2, 0, 0 },

  { 4, "naccbraytoncycle2017a/In5", 0, "", offsetof(ExtU_NACCBraytonCycle2017a_T,
    In5) + (0*sizeof(real_T)), EXTIO_SIG, 0, 1, 2, 0, 0 },

  { 5, "naccbraytoncycle2017a/In6", 0, "", offsetof(ExtU_NACCBraytonCycle2017a_T,
    In6) + (0*sizeof(real_T)), EXTIO_SIG, 0, 1, 2, 0, 0 },

  { 6, "naccbraytoncycle2017a/In7", 0, "", offsetof(ExtU_NACCBraytonCycle2017a_T,
    In7) + (0*sizeof(real_T)), EXTIO_SIG, 0, 1, 2, 0, 0 },

  { 7, "naccbraytoncycle2017a/In8", 0, "", offsetof(ExtU_NACCBraytonCycle2017a_T,
    In8) + (0*sizeof(real_T)), EXTIO_SIG, 0, 1, 2, 0, 0 },

  { 8, "naccbraytoncycle2017a/In9", 0, "", offsetof(ExtU_NACCBraytonCycle2017a_T,
    In9) + (0*sizeof(real_T)), EXTIO_SIG, 0, 1, 2, 0, 0 },

  { 9, "naccbraytoncycle2017a/In10", 0, "", offsetof
    (ExtU_NACCBraytonCycle2017a_T, In10) + (0*sizeof(real_T)), EXTIO_SIG, 0, 1,
    2, 0, 0 },

  { 10, "naccbraytoncycle2017a/In11", 0, "", offsetof
    (ExtU_NACCBraytonCycle2017a_T, In11) + (0*sizeof(real_T)), EXTIO_SIG, 0, 1,
    2, 0, 0 },

  { 11, "naccbraytoncycle2017a/Ambient air/Unit Conversion1/UnitOffset", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, UnitOffset) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 12, "naccbraytoncycle2017a/Ambient air/Unit Conversion2/UnitOffset", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, UnitOffset_h) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 13, "naccbraytoncycle2017a/Ambient air/Merge1", 0, "ndot", offsetof
    (B_NACCBraytonCycle2017a_T, ndot) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 14,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Upstream to calculate mass flow/Product1",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, Product1) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 15,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Product14",
    0, "p2", offsetof(B_NACCBraytonCycle2017a_T, p2) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 16, "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/Sum2",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, Sum2) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 17, "naccbraytoncycle2017a/Initial Condition3/Memory4", 0, "psi(1, 1)",
    offsetof(B_NACCBraytonCycle2017a_T, psi) + (0*sizeof(real_T)), BLOCKIO_SIG,
    14, 1, 2, 0, 0 },

  { 18, "naccbraytoncycle2017a/Initial Condition3/Memory4", 0, "psi(1, 2)",
    offsetof(B_NACCBraytonCycle2017a_T, psi) + (1*sizeof(real_T)), BLOCKIO_SIG,
    14, 1, 2, 0, 0 },

  { 19, "naccbraytoncycle2017a/Initial Condition3/Memory4", 0, "psi(1, 3)",
    offsetof(B_NACCBraytonCycle2017a_T, psi) + (2*sizeof(real_T)), BLOCKIO_SIG,
    14, 1, 2, 0, 0 },

  { 20, "naccbraytoncycle2017a/Initial Condition3/Memory4", 0, "psi(1, 4)",
    offsetof(B_NACCBraytonCycle2017a_T, psi) + (3*sizeof(real_T)), BLOCKIO_SIG,
    14, 1, 2, 0, 0 },

  { 21, "naccbraytoncycle2017a/Initial Condition3/Memory4", 0, "psi(1, 5)",
    offsetof(B_NACCBraytonCycle2017a_T, psi) + (4*sizeof(real_T)), BLOCKIO_SIG,
    14, 1, 2, 0, 0 },

  { 22, "naccbraytoncycle2017a/Initial Condition3/Memory4", 0, "psi(1, 6)",
    offsetof(B_NACCBraytonCycle2017a_T, psi) + (5*sizeof(real_T)), BLOCKIO_SIG,
    14, 1, 2, 0, 0 },

  { 23, "naccbraytoncycle2017a/Initial Condition3/Memory4", 0, "psi(1, 7)",
    offsetof(B_NACCBraytonCycle2017a_T, psi) + (6*sizeof(real_T)), BLOCKIO_SIG,
    14, 1, 2, 0, 0 },

  { 24,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/Saturation Dynamic/Switch2", 0,
    "", offsetof(B_NACCBraytonCycle2017a_T, Switch2) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 25, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/Multiport Switch", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, MultiportSwitch) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 26, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain", 0,
    "ndot", offsetof(B_NACCBraytonCycle2017a_T, ndot_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 27, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain1", 0, "T",
    offsetof(B_NACCBraytonCycle2017a_T, T) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 28, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain2", 0, "p",
    offsetof(B_NACCBraytonCycle2017a_T, p) + (0*sizeof(real_T)), BLOCKIO_SIG, 0,
    1, 2, 0, 0 },

  { 29, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain3", 0,
    "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 30, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain3", 0,
    "x(1, 2)", offsetof(B_NACCBraytonCycle2017a_T, x) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 31, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain3", 0,
    "x(1, 3)", offsetof(B_NACCBraytonCycle2017a_T, x) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 32, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain3", 0,
    "x(1, 4)", offsetof(B_NACCBraytonCycle2017a_T, x) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 33, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain3", 0,
    "x(1, 5)", offsetof(B_NACCBraytonCycle2017a_T, x) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 34, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain3", 0,
    "x(1, 6)", offsetof(B_NACCBraytonCycle2017a_T, x) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 35, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain3", 0,
    "x(1, 7)", offsetof(B_NACCBraytonCycle2017a_T, x) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 36, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain4", 0,
    "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 37, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain4", 0,
    "psi(1, 2)", offsetof(B_NACCBraytonCycle2017a_T, psi_e) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 38, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain4", 0,
    "psi(1, 3)", offsetof(B_NACCBraytonCycle2017a_T, psi_e) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 39, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain4", 0,
    "psi(1, 4)", offsetof(B_NACCBraytonCycle2017a_T, psi_e) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 40, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain4", 0,
    "psi(1, 5)", offsetof(B_NACCBraytonCycle2017a_T, psi_e) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 41, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain4", 0,
    "psi(1, 6)", offsetof(B_NACCBraytonCycle2017a_T, psi_e) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 42, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/Gain4", 0,
    "psi(1, 7)", offsetof(B_NACCBraytonCycle2017a_T, psi_e) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 43, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1",
    0, "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 44, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1",
    1, "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 45, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1",
    2, "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 46, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1",
    3, "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 47, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/Subtract2", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, Subtract2) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 48, "naccbraytoncycle2017a/Natural Gas/Unit Conversion1/UnitOffset", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, UnitOffset_l) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 49, "naccbraytoncycle2017a/Natural Gas/Unit Conversion2/UnitOffset", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, UnitOffset_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 50, "naccbraytoncycle2017a/Natural Gas/Merge1", 0, "ndot", offsetof
    (B_NACCBraytonCycle2017a_T, ndot_ka) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1,
    2, 0, 0 },

  { 51, "naccbraytoncycle2017a/Combustion Chamber/Reactor/Product", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, Product) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 52,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/Pressure loss/Saturation",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, Saturation) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 53, "naccbraytoncycle2017a/Combustion Chamber1/Reactor/Product", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, Product_a) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 54,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/Pressure loss/Saturation",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, Saturation_l) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 55,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/Saturation Dynamic/Switch2", 0,
    "", offsetof(B_NACCBraytonCycle2017a_T, Switch2_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 56, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/Multiport Switch", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, MultiportSwitch_h) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 57, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain", 0,
    "ndot", offsetof(B_NACCBraytonCycle2017a_T, ndot_i) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 58, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain1", 0, "T",
    offsetof(B_NACCBraytonCycle2017a_T, T_e) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 59, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain2", 0, "p",
    offsetof(B_NACCBraytonCycle2017a_T, p_c) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 60, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain3", 0,
    "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_h) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 61, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain3", 0,
    "x(1, 2)", offsetof(B_NACCBraytonCycle2017a_T, x_h) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 62, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain3", 0,
    "x(1, 3)", offsetof(B_NACCBraytonCycle2017a_T, x_h) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 63, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain3", 0,
    "x(1, 4)", offsetof(B_NACCBraytonCycle2017a_T, x_h) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 64, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain3", 0,
    "x(1, 5)", offsetof(B_NACCBraytonCycle2017a_T, x_h) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 65, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain3", 0,
    "x(1, 6)", offsetof(B_NACCBraytonCycle2017a_T, x_h) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 66, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain3", 0,
    "x(1, 7)", offsetof(B_NACCBraytonCycle2017a_T, x_h) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 67, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain4", 0,
    "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 68, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain4", 0,
    "psi(1, 2)", offsetof(B_NACCBraytonCycle2017a_T, psi_o) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 69, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain4", 0,
    "psi(1, 3)", offsetof(B_NACCBraytonCycle2017a_T, psi_o) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 70, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain4", 0,
    "psi(1, 4)", offsetof(B_NACCBraytonCycle2017a_T, psi_o) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 71, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain4", 0,
    "psi(1, 5)", offsetof(B_NACCBraytonCycle2017a_T, psi_o) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 72, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain4", 0,
    "psi(1, 6)", offsetof(B_NACCBraytonCycle2017a_T, psi_o) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 73, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/Gain4", 0,
    "psi(1, 7)", offsetof(B_NACCBraytonCycle2017a_T, psi_o) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 74, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1",
    0, "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot_h) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 75, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1",
    1, "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 76, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1",
    2, "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot_h) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 77, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1",
    3, "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 78, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/Subtract2", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, Subtract2_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 79, "naccbraytoncycle2017a/HP CTAH/Pressure Loss/Saturation", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, Saturation_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 80, "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/Sum7", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, Sum7) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 81, "naccbraytoncycle2017a/LP CTAH/Pressure Loss/Saturation", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, Saturation_lg) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 82, "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/Sum7", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, Sum7_h) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 83, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain1", 0, "T",
    offsetof(B_NACCBraytonCycle2017a_T, T_c) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 84, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain3", 0,
    "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_a) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 85, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain3", 0,
    "x(1, 2)", offsetof(B_NACCBraytonCycle2017a_T, x_a) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 86, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain3", 0,
    "x(1, 3)", offsetof(B_NACCBraytonCycle2017a_T, x_a) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 87, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain3", 0,
    "x(1, 4)", offsetof(B_NACCBraytonCycle2017a_T, x_a) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 88, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain3", 0,
    "x(1, 5)", offsetof(B_NACCBraytonCycle2017a_T, x_a) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 89, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain3", 0,
    "x(1, 6)", offsetof(B_NACCBraytonCycle2017a_T, x_a) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 90, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain3", 0,
    "x(1, 7)", offsetof(B_NACCBraytonCycle2017a_T, x_a) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 91, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain4", 0,
    "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 92, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain4", 0,
    "psi(1, 2)", offsetof(B_NACCBraytonCycle2017a_T, psi_c) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 93, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain4", 0,
    "psi(1, 3)", offsetof(B_NACCBraytonCycle2017a_T, psi_c) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 94, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain4", 0,
    "psi(1, 4)", offsetof(B_NACCBraytonCycle2017a_T, psi_c) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 95, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain4", 0,
    "psi(1, 5)", offsetof(B_NACCBraytonCycle2017a_T, psi_c) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 96, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain4", 0,
    "psi(1, 6)", offsetof(B_NACCBraytonCycle2017a_T, psi_c) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 97, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/Gain4", 0,
    "psi(1, 7)", offsetof(B_NACCBraytonCycle2017a_T, psi_c) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 98, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1", 0,
    "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 99, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1", 1,
    "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 100, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1",
    2, "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 101, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1",
    3, "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 102,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/(1, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 103,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/(2, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 104,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/(3, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 105,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/(4, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 106,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/(5, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 107,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/(6, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 108,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1/(7, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 109,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction_o1) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 110,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function",
    1, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction_o2) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 111,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function",
    2, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction_o3) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 112,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/(1, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_i) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 113,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/(2, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_i) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 114,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/(3, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_i) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 115,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/(4, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_i) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 116,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/(5, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_i) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 117,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/(6, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_i) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 118,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1/(7, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_i) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 119, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain2", 0, "p",
    offsetof(B_NACCBraytonCycle2017a_T, p_h) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 120, "naccbraytoncycle2017a/Mixer/Mixer/Add3", 0, "", offsetof
    (B_NACCBraytonCycle2017a_T, Add3) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 121, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain", 0, "ndot",
    offsetof(B_NACCBraytonCycle2017a_T, ndot_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 122, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain4", 0, "psi(1, 1)",
    offsetof(B_NACCBraytonCycle2017a_T, psi_cv) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 123, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain4", 0, "psi(1, 2)",
    offsetof(B_NACCBraytonCycle2017a_T, psi_cv) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 124, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain4", 0, "psi(1, 3)",
    offsetof(B_NACCBraytonCycle2017a_T, psi_cv) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 125, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain4", 0, "psi(1, 4)",
    offsetof(B_NACCBraytonCycle2017a_T, psi_cv) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 126, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain4", 0, "psi(1, 5)",
    offsetof(B_NACCBraytonCycle2017a_T, psi_cv) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 127, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain4", 0, "psi(1, 6)",
    offsetof(B_NACCBraytonCycle2017a_T, psi_cv) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 128, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain4", 0, "psi(1, 7)",
    offsetof(B_NACCBraytonCycle2017a_T, psi_cv) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 129, "naccbraytoncycle2017a/Mixer/Mixer/Multiport Switch1/(1, 1)", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, MultiportSwitch1) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 130, "naccbraytoncycle2017a/Mixer/Mixer/Multiport Switch1/(1, 2)", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, MultiportSwitch1) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 131, "naccbraytoncycle2017a/Mixer/Mixer/Multiport Switch1/(1, 3)", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, MultiportSwitch1) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 132, "naccbraytoncycle2017a/Mixer/Mixer/Multiport Switch1/(1, 4)", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, MultiportSwitch1) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 133, "naccbraytoncycle2017a/Mixer/Mixer/Multiport Switch1/(1, 5)", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, MultiportSwitch1) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 134, "naccbraytoncycle2017a/Mixer/Mixer/Multiport Switch1/(1, 6)", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, MultiportSwitch1) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 135, "naccbraytoncycle2017a/Mixer/Mixer/Multiport Switch1/(1, 7)", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, MultiportSwitch1) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 136, "naccbraytoncycle2017a/Mixer/Mixer/Pressure_loss/Saturation", 0, "",
    offsetof(B_NACCBraytonCycle2017a_T, Saturation_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 137, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain1", 0, "T",
    offsetof(B_NACCBraytonCycle2017a_T, T_g) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 138, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain3", 0, "x(1, 1)",
    offsetof(B_NACCBraytonCycle2017a_T, x_b) + (0*sizeof(real_T)), BLOCKIO_SIG,
    14, 1, 2, 0, 0 },

  { 139, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain3", 0, "x(1, 2)",
    offsetof(B_NACCBraytonCycle2017a_T, x_b) + (1*sizeof(real_T)), BLOCKIO_SIG,
    14, 1, 2, 0, 0 },

  { 140, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain3", 0, "x(1, 3)",
    offsetof(B_NACCBraytonCycle2017a_T, x_b) + (2*sizeof(real_T)), BLOCKIO_SIG,
    14, 1, 2, 0, 0 },

  { 141, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain3", 0, "x(1, 4)",
    offsetof(B_NACCBraytonCycle2017a_T, x_b) + (3*sizeof(real_T)), BLOCKIO_SIG,
    14, 1, 2, 0, 0 },

  { 142, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain3", 0, "x(1, 5)",
    offsetof(B_NACCBraytonCycle2017a_T, x_b) + (4*sizeof(real_T)), BLOCKIO_SIG,
    14, 1, 2, 0, 0 },

  { 143, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain3", 0, "x(1, 6)",
    offsetof(B_NACCBraytonCycle2017a_T, x_b) + (5*sizeof(real_T)), BLOCKIO_SIG,
    14, 1, 2, 0, 0 },

  { 144, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/Gain3", 0, "x(1, 7)",
    offsetof(B_NACCBraytonCycle2017a_T, x_b) + (6*sizeof(real_T)), BLOCKIO_SIG,
    14, 1, 2, 0, 0 },

  { 145, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1", 0, "Hdot",
    offsetof(B_NACCBraytonCycle2017a_T, Hdot_h5) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 146, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1", 1, "Sdot",
    offsetof(B_NACCBraytonCycle2017a_T, Sdot_l) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 147, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1", 2, "Gdot",
    offsetof(B_NACCBraytonCycle2017a_T, Gdot_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 148, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1", 3,
    "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_i) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 149, "naccbraytoncycle2017a/Mixer/Mixer/Sum6", 0, "", offsetof
    (B_NACCBraytonCycle2017a_T, Sum6) + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2,
    0, 0 },

  { 150, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    0, "ndot", offsetof(B_NACCBraytonCycle2017a_T, ndot_m) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 151, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    1, "T", offsetof(B_NACCBraytonCycle2017a_T, T_go) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 152, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    2, "p", offsetof(B_NACCBraytonCycle2017a_T, p_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 153, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    3, "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot_cl) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 154, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    4, "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot_ex) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 155, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    5, "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 156, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    6, "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_l) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 157, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    7, "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 158, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    7, "x(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_j) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 159, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    7, "x(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_j) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 160, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    7, "x(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_j) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 161, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    7, "x(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_j) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 162, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    7, "x(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_j) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 163, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    7, "x(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_j) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 164, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    8, "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_h) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 165, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    8, "psi(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_h) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 166, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    8, "psi(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_h) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 167, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    8, "psi(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_h) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 168, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    8, "psi(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_h) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 169, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    8, "psi(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_h) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 170, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    8, "psi(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_h) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 171, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    9, "Qenv", offsetof(B_NACCBraytonCycle2017a_T, Qenv) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 172, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    10, "num_iterations", offsetof(B_NACCBraytonCycle2017a_T, num_iterations) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 173, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 0,
    "ndot", offsetof(B_NACCBraytonCycle2017a_T, ndot_b) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 174, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 1,
    "T", offsetof(B_NACCBraytonCycle2017a_T, T_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 175, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 2,
    "p", offsetof(B_NACCBraytonCycle2017a_T, p_pc) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 176, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 3,
    "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 177, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 4,
    "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot_k0) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 178, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 5,
    "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot_km) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 179, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 6,
    "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 180, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 7,
    "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 181, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 7,
    "x(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_o) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 182, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 7,
    "x(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_o) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 183, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 7,
    "x(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_o) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 184, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 7,
    "x(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_o) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 185, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 7,
    "x(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_o) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 186, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 7,
    "x(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_o) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 187, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 8,
    "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_cu) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 188, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 8,
    "psi(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_cu) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 189, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 8,
    "psi(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_cu) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 190, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 8,
    "psi(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_cu) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 191, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 8,
    "psi(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_cu) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 192, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 8,
    "psi(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_cu) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 193, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 8,
    "psi(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_cu) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 194, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 9,
    "iter", offsetof(B_NACCBraytonCycle2017a_T, iter) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 195,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    0, "ndot", offsetof(B_NACCBraytonCycle2017a_T, ndot_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 196,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    1, "T", offsetof(B_NACCBraytonCycle2017a_T, T_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 197,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    2, "p", offsetof(B_NACCBraytonCycle2017a_T, p_a) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 198,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    3, "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 199,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    4, "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot_m) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 200,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    5, "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot_b) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 201,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    6, "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_g) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 202,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    7, "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 203,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    7, "x(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_k) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 204,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    7, "x(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_k) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 205,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    7, "x(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_k) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 206,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    7, "x(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_k) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 207,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    7, "x(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_k) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 208,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    7, "x(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_k) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 209,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    8, "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_m) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 210,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    8, "psi(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_m) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 211,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    8, "psi(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_m) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 212,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    8, "psi(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_m) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 213,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    8, "psi(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_m) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 214,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    8, "psi(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_m) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 215,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    8, "psi(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_m) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 216,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    9, "Qenv", offsetof(B_NACCBraytonCycle2017a_T, Qenv_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 217,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    10, "num_iterations", offsetof(B_NACCBraytonCycle2017a_T, num_iterations_a)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 218,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    0, "ndot", offsetof(B_NACCBraytonCycle2017a_T, ndot_ol) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 219,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    1, "T", offsetof(B_NACCBraytonCycle2017a_T, T_ed) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 220,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    2, "p", offsetof(B_NACCBraytonCycle2017a_T, p_a5) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 221,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    3, "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot_i) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 222,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    4, "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 223,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    5, "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot_m) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 224,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    6, "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 225,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    7, "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_ac) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 226,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    7, "x(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_ac) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 227,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    7, "x(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_ac) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 228,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    7, "x(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_ac) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 229,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    7, "x(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_ac) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 230,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    7, "x(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_ac) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 231,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    7, "x(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_ac) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 232,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    8, "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_a) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 233,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    8, "psi(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_a) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 234,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    8, "psi(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_a) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 235,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    8, "psi(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_a) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 236,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    8, "psi(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_a) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 237,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    8, "psi(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_a) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 238,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    8, "psi(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_a) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 239,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    9, "Qenv", offsetof(B_NACCBraytonCycle2017a_T, Qenv_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 240,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    10, "num_iterations", offsetof(B_NACCBraytonCycle2017a_T, num_iterations_f)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 241, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 0,
    "ndot", offsetof(B_NACCBraytonCycle2017a_T, ndot_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 242, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 1,
    "T", offsetof(B_NACCBraytonCycle2017a_T, T_m) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 243, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 2,
    "p", offsetof(B_NACCBraytonCycle2017a_T, p_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 244, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 3,
    "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 245, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 4,
    "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot_kk) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 246, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 5,
    "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot_hm) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 247, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 6,
    "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 248, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 7,
    "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 249, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 7,
    "x(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_d) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 250, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 7,
    "x(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_d) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 251, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 7,
    "x(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_d) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 252, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 7,
    "x(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_d) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 253, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 7,
    "x(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_d) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 254, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 7,
    "x(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_d) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 255, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 8,
    "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_l) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 256, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 8,
    "psi(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_l) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 257, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 8,
    "psi(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_l) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 258, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 8,
    "psi(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_l) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 259, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 8,
    "psi(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_l) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 260, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 8,
    "psi(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_l) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 261, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 8,
    "psi(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_l) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 262, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 9,
    "iter", offsetof(B_NACCBraytonCycle2017a_T, iter_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 263,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    0, "ndot", offsetof(B_NACCBraytonCycle2017a_T, ndot_nq) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 264,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    1, "T", offsetof(B_NACCBraytonCycle2017a_T, T_h) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 265,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    2, "p", offsetof(B_NACCBraytonCycle2017a_T, p_g) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 266,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    3, "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 267,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    4, "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 268,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    5, "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot_l) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 269,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    6, "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_a) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 270,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    7, "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_dg) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 271,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    7, "x(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_dg) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 272,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    7, "x(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_dg) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 273,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    7, "x(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_dg) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 274,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    7, "x(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_dg) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 275,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    7, "x(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_dg) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 276,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    7, "x(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_dg) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 277,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    8, "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_i) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 278,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    8, "psi(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_i) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 279,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    8, "psi(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_i) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 280,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    8, "psi(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_i) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 281,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    8, "psi(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_i) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 282,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    8, "psi(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_i) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 283,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    8, "psi(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_i) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 284,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    9, "Qenv", offsetof(B_NACCBraytonCycle2017a_T, Qenv_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 285,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    10, "num_iterations", offsetof(B_NACCBraytonCycle2017a_T, num_iterations_d)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 286,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    0, "ndot", offsetof(B_NACCBraytonCycle2017a_T, ndot_bl) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 287,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    1, "T", offsetof(B_NACCBraytonCycle2017a_T, T_gf) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 288,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    2, "p", offsetof(B_NACCBraytonCycle2017a_T, p_a1) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 289,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    3, "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot_b) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 290,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    4, "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot_n) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 291,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    5, "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 292,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    6, "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_aq) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 293,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    7, "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 294,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    7, "x(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_f) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 295,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    7, "x(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_f) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 296,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    7, "x(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_f) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 297,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    7, "x(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_f) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 298,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    7, "x(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_f) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 299,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    7, "x(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_f) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 300,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    8, "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_f) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 301,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    8, "psi(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_f) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 302,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    8, "psi(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_f) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 303,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    8, "psi(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_f) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 304,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    8, "psi(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_f) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 305,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    8, "psi(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_f) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 306,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    8, "psi(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_f) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 307,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    9, "Qenv", offsetof(B_NACCBraytonCycle2017a_T, Qenv_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 308,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    10, "num_iterations", offsetof(B_NACCBraytonCycle2017a_T, num_iterations_j)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 309,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain",
    0, "ndot", offsetof(B_NACCBraytonCycle2017a_T, ndot_c0) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 310,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain2",
    0, "p", offsetof(B_NACCBraytonCycle2017a_T, p_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 311,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain3",
    0, "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_da) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 312,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain3",
    0, "x(1, 2)", offsetof(B_NACCBraytonCycle2017a_T, x_da) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 313,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain3",
    0, "x(1, 3)", offsetof(B_NACCBraytonCycle2017a_T, x_da) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 314,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain3",
    0, "x(1, 4)", offsetof(B_NACCBraytonCycle2017a_T, x_da) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 315,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain3",
    0, "x(1, 5)", offsetof(B_NACCBraytonCycle2017a_T, x_da) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 316,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain3",
    0, "x(1, 6)", offsetof(B_NACCBraytonCycle2017a_T, x_da) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 317,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain3",
    0, "x(1, 7)", offsetof(B_NACCBraytonCycle2017a_T, x_da) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 318,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain4",
    0, "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_ip) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 319,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain4",
    0, "psi(1, 2)", offsetof(B_NACCBraytonCycle2017a_T, psi_ip) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 320,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain4",
    0, "psi(1, 3)", offsetof(B_NACCBraytonCycle2017a_T, psi_ip) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 321,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain4",
    0, "psi(1, 4)", offsetof(B_NACCBraytonCycle2017a_T, psi_ip) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 322,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain4",
    0, "psi(1, 5)", offsetof(B_NACCBraytonCycle2017a_T, psi_ip) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 323,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain4",
    0, "psi(1, 6)", offsetof(B_NACCBraytonCycle2017a_T, psi_ip) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 324,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/Gain4",
    0, "psi(1, 7)", offsetof(B_NACCBraytonCycle2017a_T, psi_ip) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 325,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1",
    0, "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot_du) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 326,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1",
    1, "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 327,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1",
    2, "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot_fo) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 328,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1",
    3, "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_i4) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 329,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/(1, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_c) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 330,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/(2, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_c) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 331,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/(3, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_c) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 332,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/(4, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_c) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 333,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/(5, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_c) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 334,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/(6, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_c) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 335,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1/(7, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_c) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 336,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    0, "ndot", offsetof(B_NACCBraytonCycle2017a_T, ndot_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 337,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    1, "T", offsetof(B_NACCBraytonCycle2017a_T, T_d) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 338,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    2, "p", offsetof(B_NACCBraytonCycle2017a_T, p_gc) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 339,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    3, "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot_e) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 340,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    4, "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot_a) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 341,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    5, "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot_c) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 342,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    6, "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_b) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 343,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    7, "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 344,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    7, "x(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_p) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 345,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    7, "x(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_p) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 346,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    7, "x(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_p) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 347,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    7, "x(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_p) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 348,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    7, "x(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_p) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 349,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    7, "x(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_p) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 350,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    8, "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_g) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 351,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    8, "psi(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_g) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 352,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    8, "psi(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_g) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 353,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    8, "psi(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_g) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 354,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    8, "psi(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_g) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 355,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    8, "psi(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_g) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 356,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    8, "psi(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_g) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 357,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    9, "iter", offsetof(B_NACCBraytonCycle2017a_T, iter_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 358,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    0, "ndot", offsetof(B_NACCBraytonCycle2017a_T, ndot_l) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 359,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    1, "T", offsetof(B_NACCBraytonCycle2017a_T, T_j) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 360,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    2, "p", offsetof(B_NACCBraytonCycle2017a_T, p_b) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 361,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    3, "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot_jv) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 362,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    4, "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot_p) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 363,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    5, "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot_l1) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 364,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    6, "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_h) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 365,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    7, "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_ju) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 366,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    7, "x(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_ju) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 367,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    7, "x(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_ju) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 368,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    7, "x(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_ju) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 369,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    7, "x(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_ju) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 370,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    7, "x(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_ju) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 371,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    7, "x(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_ju) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 372,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    8, "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_al) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 373,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    8, "psi(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_al) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 374,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    8, "psi(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_al) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 375,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    8, "psi(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_al) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 376,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    8, "psi(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_al) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 377,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    8, "psi(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_al) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 378,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    8, "psi(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_al) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 379,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    9, "Qenv", offsetof(B_NACCBraytonCycle2017a_T, Qenv_b) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 380,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    10, "num_iterations", offsetof(B_NACCBraytonCycle2017a_T, num_iterations_n)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 381,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    0, "ndot", offsetof(B_NACCBraytonCycle2017a_T, ndot_oo) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 382,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    1, "T", offsetof(B_NACCBraytonCycle2017a_T, T_mo) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 383,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    2, "p", offsetof(B_NACCBraytonCycle2017a_T, p_k) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 384,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    3, "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot_jo) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 385,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    4, "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot_o) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 386,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    5, "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot_g) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 387,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    6, "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_az) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 388,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    7, "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_i) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 389,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    7, "x(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_i) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 390,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    7, "x(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_i) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 391,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    7, "x(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_i) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 392,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    7, "x(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_i) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 393,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    7, "x(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_i) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 394,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    7, "x(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_i) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 395,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    8, "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_p) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 396,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    8, "psi(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_p) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 397,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    8, "psi(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_p) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 398,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    8, "psi(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_p) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 399,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    8, "psi(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_p) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 400,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    8, "psi(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_p) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 401,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    8, "psi(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_p) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 402,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    9, "Qenv", offsetof(B_NACCBraytonCycle2017a_T, Qenv_pj) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 403,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    10, "num_iterations", offsetof(B_NACCBraytonCycle2017a_T, num_iterations_fx)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 404,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    0, "ndot", offsetof(B_NACCBraytonCycle2017a_T, ndot_f2) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 405,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    1, "T", offsetof(B_NACCBraytonCycle2017a_T, T_h3) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 406,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    2, "p", offsetof(B_NACCBraytonCycle2017a_T, p_nt) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 407,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    3, "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot_ig) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 408,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    4, "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot_fv) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 409,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    5, "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot_mk) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 410,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    6, "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_eg) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 411,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    7, "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_il) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 412,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    7, "x(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_il) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 413,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    7, "x(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_il) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 414,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    7, "x(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_il) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 415,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    7, "x(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_il) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 416,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    7, "x(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_il) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 417,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    7, "x(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_il) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 418,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    8, "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_j) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 419,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    8, "psi(2, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_j) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 420,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    8, "psi(3, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_j) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 421,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    8, "psi(4, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_j) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 422,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    8, "psi(5, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_j) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 423,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    8, "psi(6, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_j) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 424,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    8, "psi(7, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_j) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 425,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    9, "Qenv", offsetof(B_NACCBraytonCycle2017a_T, Qenv_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 426,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    10, "num_iterations", offsetof(B_NACCBraytonCycle2017a_T, num_iterations_h)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 427, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain", 0,
    "ndot", offsetof(B_NACCBraytonCycle2017a_T, ndot_lp) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 428, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain1", 0, "T",
    offsetof(B_NACCBraytonCycle2017a_T, T_gw) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 429, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain2", 0, "p",
    offsetof(B_NACCBraytonCycle2017a_T, p_d) + (0*sizeof(real_T)), BLOCKIO_SIG,
    0, 1, 2, 0, 0 },

  { 430, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain3", 0,
    "x(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, x_g) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 431, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain3", 0,
    "x(1, 2)", offsetof(B_NACCBraytonCycle2017a_T, x_g) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 432, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain3", 0,
    "x(1, 3)", offsetof(B_NACCBraytonCycle2017a_T, x_g) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 433, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain3", 0,
    "x(1, 4)", offsetof(B_NACCBraytonCycle2017a_T, x_g) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 434, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain3", 0,
    "x(1, 5)", offsetof(B_NACCBraytonCycle2017a_T, x_g) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 435, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain3", 0,
    "x(1, 6)", offsetof(B_NACCBraytonCycle2017a_T, x_g) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 436, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain3", 0,
    "x(1, 7)", offsetof(B_NACCBraytonCycle2017a_T, x_g) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 437, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain4", 0,
    "psi(1, 1)", offsetof(B_NACCBraytonCycle2017a_T, psi_eg) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 438, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain4", 0,
    "psi(1, 2)", offsetof(B_NACCBraytonCycle2017a_T, psi_eg) + (1*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 439, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain4", 0,
    "psi(1, 3)", offsetof(B_NACCBraytonCycle2017a_T, psi_eg) + (2*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 440, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain4", 0,
    "psi(1, 4)", offsetof(B_NACCBraytonCycle2017a_T, psi_eg) + (3*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 441, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain4", 0,
    "psi(1, 5)", offsetof(B_NACCBraytonCycle2017a_T, psi_eg) + (4*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 442, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain4", 0,
    "psi(1, 6)", offsetof(B_NACCBraytonCycle2017a_T, psi_eg) + (5*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 443, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/Gain4", 0,
    "psi(1, 7)", offsetof(B_NACCBraytonCycle2017a_T, psi_eg) + (6*sizeof(real_T)),
    BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 444, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1",
    0, "Hdot", offsetof(B_NACCBraytonCycle2017a_T, Hdot_a) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 445, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1",
    1, "Sdot", offsetof(B_NACCBraytonCycle2017a_T, Sdot_c0) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 446, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1",
    2, "Gdot", offsetof(B_NACCBraytonCycle2017a_T, Gdot_ny) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 447, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1",
    3, "Cpdot", offsetof(B_NACCBraytonCycle2017a_T, Cpdot_f) + (0*sizeof(real_T)),
    BLOCKIO_SIG, 66, 1, 2, 0, 0 },

  { 448,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/(1, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_n) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 449,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/(2, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_n) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 450,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/(3, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_n) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 451,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/(4, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_n) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 452,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/(5, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_n) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 453,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/(6, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_n) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 454,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1/(7, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_n) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 455,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction_o1_j) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 456,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function",
    1, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction_o2_f) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 457,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function",
    2, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction_o3_o) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 458,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/(1, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_o) + (0*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 459,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/(2, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_o) + (1*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 460,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/(3, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_o) + (2*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 461,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/(4, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_o) + (3*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 462,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/(5, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_o) + (4*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 463,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/(6, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_o) + (5*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 464,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1/(7, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o1_o) + (6*sizeof
    (real_T)), BLOCKIO_SIG, 25, 1, 2, 0, 0 },

  { 465, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/T-p-x-State/S-Function1",
    4, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o5) + (0*sizeof
    (int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 466, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/T-p-x-State/S-Function1",
    4, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o5_j) + (0*sizeof
    (int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 467, "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-x-State/S-Function1",
    4, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o5_d) + (0*sizeof
    (int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 468,
    "naccbraytoncycle2017a/Natural Gas/T-p-State/T-p-Vapor Fractions/S-Function1",
    1, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o2) + (0*sizeof
    (int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 469,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/VolumeFlow/Density/S-Function",
    3, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction_o4) + (0*sizeof(int32_T)),
    BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 470,
    "naccbraytoncycle2017a/Natural Gas/VolumeFlow/T-p-Vapor Fractions/S-Function1",
    1, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o2_g) + (0*sizeof
    (int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 471, "naccbraytoncycle2017a/Mixer/Mixer/T-p-x-State1/S-Function1", 4, "",
    offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o5_m) + (0*sizeof(int32_T)),
    BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 472, "naccbraytoncycle2017a/Mixer/Mixer/H-p-State with HeatLoss/S-Function",
    11, "error_codes", offsetof(B_NACCBraytonCycle2017a_T, error_codes) + (0*
    sizeof(int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 473, "naccbraytoncycle2017a/LP Gas Turbine/Turbine/S-p-State/S-Function", 10,
    "error_codes", offsetof(B_NACCBraytonCycle2017a_T, error_codes_i) + (0*
    sizeof(int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 474,
    "naccbraytoncycle2017a/LP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    11, "error_codes", offsetof(B_NACCBraytonCycle2017a_T, error_codes_j) + (0*
    sizeof(int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 475,
    "naccbraytoncycle2017a/LP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    11, "error_codes", offsetof(B_NACCBraytonCycle2017a_T, error_codes_i0) + (0*
    sizeof(int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 476, "naccbraytoncycle2017a/HP Gas Turbine/Turbine/S-p-State/S-Function", 10,
    "error_codes", offsetof(B_NACCBraytonCycle2017a_T, error_codes_o) + (0*
    sizeof(int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 477,
    "naccbraytoncycle2017a/HP Gas Turbine/Turbine/H-p-State with Heat Exchange/S-Function",
    11, "error_codes", offsetof(B_NACCBraytonCycle2017a_T, error_codes_m) + (0*
    sizeof(int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 478,
    "naccbraytoncycle2017a/HP CTAH/Heat-Addition/subsystem/H-p-State with HeatLoss/S-Function",
    11, "error_codes", offsetof(B_NACCBraytonCycle2017a_T, error_codes_d) + (0*
    sizeof(int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 479,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-x-State/S-Function1",
    4, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o5_mw) + (0*sizeof
    (int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 480,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/T-p-State/T-p-Vapor Fractions/S-Function1",
    1, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o2_b) + (0*sizeof
    (int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 481,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/S-p-State/S-Function",
    10, "error_codes", offsetof(B_NACCBraytonCycle2017a_T, error_codes_do) + (0*
    sizeof(int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 482,
    "naccbraytoncycle2017a/Compressor Pressure Feedback/PF compressor/H-p-State with Heat Exchange/S-Function",
    11, "error_codes", offsetof(B_NACCBraytonCycle2017a_T, error_codes_p) + (0*
    sizeof(int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 483,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/H-p-State with Heat Exchange/S-Function",
    11, "error_codes", offsetof(B_NACCBraytonCycle2017a_T, error_codes_h) + (0*
    sizeof(int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 484,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/H-p-State with Heat Exchange/S-Function",
    11, "error_codes", offsetof(B_NACCBraytonCycle2017a_T, error_codes_or) + (0*
    sizeof(int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 485, "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-x-State/S-Function1",
    4, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o5_o) + (0*sizeof
    (int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 486,
    "naccbraytoncycle2017a/Ambient air/T-p-State/T-p-Vapor Fractions/S-Function1",
    1, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o2_gm) + (0*sizeof
    (int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 487,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/VolumeFlow/Density/S-Function",
    3, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction_o4_a) + (0*sizeof
    (int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 488,
    "naccbraytoncycle2017a/Ambient air/VolumeFlow/T-p-Vapor Fractions/S-Function1",
    1, "", offsetof(B_NACCBraytonCycle2017a_T, SFunction1_o2_p) + (0*sizeof
    (int32_T)), BLOCKIO_SIG, 6, 1, 2, 0, 0 },

  { 489,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/calculate  conversion/Subsystem1/Subtract5",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion_n.Subtract5)
    + (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 490,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/calculate  conversion/Subsystem1/Product6/(1, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion_n.Product6) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 491,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/calculate  conversion/Subsystem1/Product6/(1, 2)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion_n.Product6) +
    (1*sizeof(real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 492,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/calculate  conversion/Subsystem1/Product6/(1, 3)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion_n.Product6) +
    (2*sizeof(real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 493,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/calculate  conversion/Subsystem1/Product6/(1, 4)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion_n.Product6) +
    (3*sizeof(real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 494,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/calculate  conversion/Subsystem1/Product6/(1, 5)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion_n.Product6) +
    (4*sizeof(real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 495,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/calculate  conversion/Subsystem1/Product6/(1, 6)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion_n.Product6) +
    (5*sizeof(real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 496,
    "naccbraytoncycle2017a/Combustion Chamber1/Reactor/calculate  conversion/Subsystem1/Product6/(1, 7)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion_n.Product6) +
    (6*sizeof(real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 497,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/calculate  conversion/Subsystem1/Subtract5",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion.Subtract5) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 0, 1, 2, 0, 0 },

  { 498,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/calculate  conversion/Subsystem1/Product6/(1, 1)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion.Product6) +
    (0*sizeof(real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 499,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/calculate  conversion/Subsystem1/Product6/(1, 2)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion.Product6) +
    (1*sizeof(real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 500,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/calculate  conversion/Subsystem1/Product6/(1, 3)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion.Product6) +
    (2*sizeof(real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 501,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/calculate  conversion/Subsystem1/Product6/(1, 4)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion.Product6) +
    (3*sizeof(real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 502,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/calculate  conversion/Subsystem1/Product6/(1, 5)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion.Product6) +
    (4*sizeof(real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 503,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/calculate  conversion/Subsystem1/Product6/(1, 6)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion.Product6) +
    (5*sizeof(real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { 504,
    "naccbraytoncycle2017a/Combustion Chamber/Reactor/calculate  conversion/Subsystem1/Product6/(1, 7)",
    0, "", offsetof(B_NACCBraytonCycle2017a_T, calculateconversion.Product6) +
    (6*sizeof(real_T)), BLOCKIO_SIG, 14, 1, 2, 0, 0 },

  { -1, "", -1, "", 0, 0, 0 }
};

static int32_t NI_SigListSize DataSection(".NIVS.siglistsize") = 505;
static int32_t NI_VirtualBlockSources[1];
static int32_t NI_SigDimList[] DataSection(".NIVS.sigdimlist") =
{ 1, 1
};

static int32_t NI_ExtListSize DataSection(".NIVS.extlistsize") = 39;
static NI_ExternalIO NI_ExtList[] DataSection(".NIVS.extlist") =
{
  { 1, "In1", 0, EXT_IN, 1, 1, 1 },

  { 2, "In2", 0, EXT_IN, 1, 1, 1 },

  { 3, "In3", 0, EXT_IN, 1, 1, 1 },

  { 4, "In4", 0, EXT_IN, 1, 1, 1 },

  { 5, "In5", 0, EXT_IN, 1, 1, 1 },

  { 6, "In6", 0, EXT_IN, 1, 1, 1 },

  { 7, "In7", 0, EXT_IN, 1, 1, 1 },

  { 8, "In8", 0, EXT_IN, 1, 1, 1 },

  { 9, "In9", 0, EXT_IN, 1, 1, 1 },

  { 10, "In10", 0, EXT_IN, 1, 1, 1 },

  { 11, "In11", 0, EXT_IN, 1, 1, 1 },

  { 1, "Out1", 0, EXT_OUT, 1, 1, 1 },

  { 2, "Out2", 0, EXT_OUT, 1, 1, 1 },

  { 3, "Out3", 0, EXT_OUT, 1, 1, 1 },

  { 4, "Out4", 0, EXT_OUT, 1, 1, 1 },

  { 5, "Out5", 0, EXT_OUT, 1, 1, 1 },

  { 6, "Out6", 0, EXT_OUT, 1, 1, 1 },

  { 7, "Out7", 0, EXT_OUT, 1, 1, 1 },

  { 8, "Out8", 0, EXT_OUT, 1, 1, 1 },

  { 9, "Out9", 0, EXT_OUT, 1, 1, 1 },

  { 10, "Out10", 0, EXT_OUT, 1, 1, 1 },

  { 11, "Out11", 0, EXT_OUT, 1, 1, 1 },

  { 12, "Out12", 0, EXT_OUT, 1, 1, 1 },

  { 13, "Out13", 0, EXT_OUT, 1, 1, 1 },

  { 14, "Out14", 0, EXT_OUT, 1, 1, 1 },

  { 15, "Out15", 0, EXT_OUT, 1, 1, 1 },

  { 16, "Out16", 0, EXT_OUT, 1, 1, 1 },

  { 17, "Out17", 0, EXT_OUT, 1, 1, 1 },

  { 18, "Out18", 0, EXT_OUT, 1, 1, 1 },

  { 19, "Out19", 0, EXT_OUT, 1, 1, 1 },

  { 20, "Out20", 0, EXT_OUT, 1, 1, 1 },

  { 21, "Out21", 0, EXT_OUT, 1, 1, 1 },

  { 22, "Out22", 0, EXT_OUT, 1, 1, 1 },

  { 23, "Out23", 0, EXT_OUT, 1, 1, 1 },

  { 24, "Out24", 0, EXT_OUT, 1, 1, 1 },

  { 25, "Out25", 0, EXT_OUT, 1, 1, 1 },

  { 26, "Out26", 0, EXT_OUT, 1, 1, 1 },

  { 27, "Out27", 0, EXT_OUT, 1, 1, 1 },

  { 28, "Out28", 0, EXT_OUT, 1, 1, 1 },

  { -1, "", 0, 0, 0, 0, 0 }
};

/* This Task List is generated to allow access to the task specs without
 * initializing the model.
 * 0th entry is for scheduler (base rate)
 * rest for multirate model's tasks.
 */
NI_Task NI_TaskList[] DataSection(".NIVS.tasklist") =
{
  { 0, 1.0, 0 }
};

int32_t NI_NumTasks DataSection(".NIVS.numtasks") = 1;
static const char* NI_CompiledModelName DataSection(".NIVS.compiledmodelname") =
  "NACCBraytonCycle2017a";
static const char* NI_CompiledModelVersion = "1.139";
static const char* NI_CompiledModelDateTime = "Thu Mar 14 16:45:13 2019";
static const char* NI_builder DataSection(".NIVS.builder") =
  "NI Model Framework 2018.0.0.81 (2018) for Simulink Coder 8.12 (R2017a)";
static const char* NI_BuilderVersion DataSection(".NIVS.builderversion") =
  "2018.0.0.81";

/*========================================================================*
 * Function: NIRT_GetBuildInfo
 *
 * Abstract:
 *	Get the DLL versioning etc information.
 *
 * Output Parameters:
 *	detail	: String containing model build information.
 *	len		: the build info string length. If a value of "-1" is specified, the minimum buffer size of "detail" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetBuildInfo(char* detail, int32_t* len)
{
  int32_t msgLength = 0;
  char *msgBuffer = NULL;

  /* Message */
  const char msg[] =
    "%s\nModel Name: %s\nModel Version: %s\nVeriStand Model Framework Version: %s\nCompiled On: %s";

  /* There are no console properties to set for VxWorks, because the console is simply serial output data.
     Just do printf for VxWorks and ignore all console properties. */
#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hStdout, FOREGROUND_INTENSITY | FOREGROUND_BLUE |
    FOREGROUND_GREEN | FOREGROUND_RED);

#endif

  /* Print to screen */
  printf("\n*******************************************************************************\n");
  msgLength = printf(msg, NI_builder, NI_CompiledModelName,
                     NI_CompiledModelVersion, NI_BuilderVersion,
                     NI_CompiledModelDateTime);
  printf("\n*******************************************************************************\n");

#if ! defined (VXWORKS) && ! defined (kNIOSLinux)

  SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE | FOREGROUND_GREEN |
    FOREGROUND_RED);

#endif

  if (*len == -1) {
    /* Return the required minimum buffer size */
    *len = msgLength;
  } else {
    /* allocate the buffer */
    msgBuffer = (char*)calloc(msgLength + 1, sizeof(char));
    sprintf (msgBuffer, msg, NI_builder, NI_CompiledModelName,
             NI_CompiledModelVersion, NI_BuilderVersion,
             NI_CompiledModelDateTime);
    if (*len >= msgLength) {
      *len = msgLength + 1;
    }

    /* Copy into external buffer */
    strncpy(detail, msgBuffer, *len);

    /* Release memory */
    free(msgBuffer);
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSignalSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	index		: index of the signal (in/out)
 *	ID			: ID of signal to be looked up (in), ID of signal at index (out)
 *	ID_len		: length of input ID(in), length of ID (out)
 *	bnlen		: length of buffer blkname (in), length of output blkname (out)
 *	snlen		: length of buffer signame (in), length of output signame (out)
 *
 * Output Parameters:
 *	blkname		: Name of the source block for the signal
 *	portnum		: port number of the block that is the source of the signal (0 indexed)
 *	signame		: Name of the signal
 *	datatype	: same as with parameters. Currently assuming all data to be double.
 *	dims		: The port's dimension of length 'numdims'.
 *	numdims		: the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error(if sigidx == -1, number of signals)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSignalSpec(int32_t* sidx, char* ID, int32_t* ID_len,
  char* blkname, int32_t *bnlen,
  int32_t *portnum, char* signame, int32_t *snlen, int32_t *dattype, int32_t*
  dims, int32_t* numdim)
{
  int32_t sigidx = *sidx;
  int32_t i = 0;
  char *addr = NULL;
  char *IDblk = 0;
  int32_t IDport = 0;
  if (sigidx < 0) {
    /* check if ID has been specified. */
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0)) {
      /* parse ID into blkname and port */
      addr = strrchr(ID, ':');
      if (addr == NULL) {
        return NI_SigListSize;
      }

      /* Calculate the char offset into the string after the port */
      i = addr - ID;

      /* malformed ID */
      if (i<=0) {
        return NI_SigListSize;
      }

      IDblk = ID;
      IDport = atoi(ID+i+1);

      /* lookup the table for matching ID */
      for (i=0; i<NI_SigListSize; i++) {
        /* 11 to accomodate ':','/', port number and null character */
        char *tempID = (char *)calloc(strlen(NI_SigList[i].blockname)+strlen
          (NI_SigList[i].signalname) + 11, sizeof(char));
        if (strlen(NI_SigList[i].signalname)>0) {
          sprintf(tempID,"%s:%d%s%s",NI_SigList[i].blockname,NI_SigList[i].
                  portno+1,"/",NI_SigList[i].signalname);
        } else {
          sprintf(tempID,"%s:%d",NI_SigList[i].blockname,NI_SigList[i].portno+1);
        }

        if (!strcmp(IDblk,tempID) && IDport==(NI_SigList[i].portno+1)) {
          break;
        }

        free(tempID);
      }

      if (i < NI_SigListSize) {
        sigidx = *sidx = i;
      } else {
        return NI_SigListSize;
      }
    } else {
      // no index or ID specified.
      return NI_SigListSize;
    }
  }

  if (sigidx>=0 && sigidx<NI_SigListSize) {
    if (ID != NULL) {
      // no need for return string to be null terminated!
      /* 11 to accomodate ':','/', port number and null character */
      char *tempID = (char *)calloc(strlen(NI_SigList[sigidx].blockname)+strlen
        (NI_SigList[sigidx].signalname)+ 11, sizeof(char));
      if (strlen(NI_SigList[sigidx].signalname)>0) {
        sprintf(tempID,"%s:%d%s%s",NI_SigList[sigidx].blockname,
                NI_SigList[sigidx].portno+1,"/",NI_SigList[sigidx].signalname);
      } else {
        sprintf(tempID,"%s:%d",NI_SigList[sigidx].blockname,NI_SigList[sigidx].
                portno+1);
      }

      if ((int32_t)strlen(tempID)<*ID_len) {
        *ID_len = strlen(tempID);
      }

      strncpy(ID, tempID, *ID_len);
      free(tempID);
    }

    if (blkname != NULL) {
      // no need for return string to be null terminated!
      if ((int32_t)strlen(NI_SigList[sigidx].blockname)<*bnlen) {
        *bnlen = strlen(NI_SigList[sigidx].blockname);
      }

      strncpy(blkname, NI_SigList[sigidx].blockname, *bnlen);
    }

    if (signame != NULL) {
      // no need for return string to be null terminated!
      if ((int32_t)strlen(NI_SigList[sigidx].signalname)<*snlen) {
        *snlen = strlen(NI_SigList[sigidx].signalname);
      }

      strncpy(signame, NI_SigList[sigidx].signalname, *snlen);
    }

    if (portnum != NULL) {
      *portnum = NI_SigList[sigidx].portno;
    }

    if (dattype != NULL) {
      *dattype = NI_SigList[sigidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_SigList[sigidx].numofdims;
      } else if (dims != NULL) {
        for (i=0;i < *numdim; i++) {
          dims[i] = NI_SigDimList[NI_SigList[sigidx].dimListOffset +i];
        }
      }
    }

    return NI_OK;
  }

  return NI_SigListSize;
}

/*========================================================================*
 * Function: NIRT_GetParameterIndices
 *
 * Abstract:
 *	Returns an array of indices to tunable parameters
 *
 * Output Parameters:
 *	indices	: buffer to store the parameter indices of length "len"
 *	len		: returns the number of indices. If a value of "-1" is specified, the minimum buffer size of "indices" is returned as its value.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterIndices(int32_t* indices, int32_t* len)
{
  int32_t i;
  if ((len == NULL) || (indices == NULL)) {
    return NI_ERROR;
  }

  if (*len == -1) {
    *len = NI_ParamListSize;
  } else {
    for (i=0; (i < NI_ParamListSize) && (i < *len); i++) {
      indices[i] = NI_ParamList[i].idx;
    }

    *len = i;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetParameterSpec
 *
 * Abstract:
 *	If index == -1, lookup parameter by the ID.
 *	If ID_len == 0 or if ID == null, return number of parameters in model.
 *	Otherwise, lookup parameter by index, and return the information.
 *
 * Input/Output Parameters:
 *	paramidx	: index of the parameter(in/out). If a value of "-1" is specified, the parameter's ID is used instead
 *	ID			: ID of parameter to be looked up (in), ID of parameter at index (out)
 *	ID_len		: length of input ID (in), length of ID (out)
 *	pnlen		: length of buffer paramname(in), length of the returned paramname (out)
 *	numdim		: length of buffer dimension(in), length of output dimension (out). If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value
 *
 * Output Parameters:
 *	paramname	: Name of the parameter
 *	datatype	: datatype of the parameter (currently assuming 0: double, .. )
 *	dims		: array of dimensions with length 'numdim'
 *
 * Returns:
 *	NI_OK if no error (if paramidx == -1, number of tunable parameters)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameterSpec(int32_t* pidx, char* ID, int32_t*
  ID_len, char* paramname, int32_t *pnlen,
  int32_t *dattype, int32_t* dims, int32_t* numdim)
{
  int32_t i = 0;
  int32_t paramidx = *pidx;
  if (paramidx < 0) {
    // check if ID has been specified.
    if ((ID != NULL) && (ID_len != NULL) && (*ID_len > 0) ) {
      // lookup the table for matching ID
      for (i=0; i < NI_ParamListSize; i++) {
        if (strcmp(ID,NI_ParamList[i].paramname) == 0) {
          /* found matching string */
          break;
        }
      }

      if (i < NI_ParamListSize) {
        /* note the index into the rtParamAttribs */
        paramidx = *pidx = i;
      } else {
        return NI_ParamListSize;
      }
    } else {
      // no index or ID specified.
      return NI_ParamListSize;
    }
  }

  if ((paramidx >= 0) && (paramidx<NI_ParamListSize)) {
    if (ID != NULL) {
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *ID_len) {
        *ID_len = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(ID, NI_ParamList[paramidx].paramname, *ID_len);
    }

    if (paramname != NULL) {
      /* no need for return string to be null terminated! */
      if ((int32_t)strlen(NI_ParamList[paramidx].paramname) < *pnlen) {
        *pnlen = strlen(NI_ParamList[paramidx].paramname);
      }

      strncpy(paramname, NI_ParamList[paramidx].paramname, *pnlen);
    }

    if (dattype != NULL) {
      *dattype = NI_ParamList[paramidx].datatype;
    }

    if (numdim != NULL) {
      if (*numdim == -1) {
        *numdim = NI_ParamList[paramidx].numofdims;
      } else if (dims != NULL) {
        for (i = 0; i < *numdim; i++) {
          dims[i] = NI_ParamDimList[NI_ParamList[paramidx].dimListOffset + i];
        }
      }
    }

    return NI_OK;
  }

  return NI_ParamListSize;
}

/*========================================================================*
 * Function: NIRT_GetExtIOSpec
 *
 * Abstract:
 *	Returns the model's inport or outport specification
 *
 * Input Parameters:
 *	index	: index of the task
 *
 * Output Parameters:
 *	idx		: idx of the IO.
 *	name	: Name of the IO block
 *	tid		: task id
 *	type	: EXT_IN or EXT_OUT
 *	dims	: The port's dimension of length 'numdims'.
 *	numdims : the port's number of dimensions. If a value of "-1" is specified, the minimum buffer size of "dims" is returned as its value.
 *
 * Returns
 *	NI_OK if no error. (if index == -1, return number of tasks in the model)
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetExtIOSpec(int32_t index, int32_t *idx, char* name,
  int32_t* tid, int32_t *type, int32_t *dims, int32_t* numdims)
{
  if (index == -1) {
    return NI_ExtListSize;
  }

  if (idx != NULL) {
    *idx = NI_ExtList[index].idx;
  }

  if (name != NULL) {
    int32_t sz = strlen(name);
    strncpy(name, NI_ExtList[index].name, sz-1);
    name[sz-1]= 0;
  }

  if (tid != NULL) {
    *tid = NI_ExtList[index].TID;
  }

  if (type != NULL) {
    *type = NI_ExtList[index].type;
  }

  if (numdims != NULL) {
    if (*numdims == -1) {
      *numdims = 2;
    } else if (numdims != NULL) {
      /* Return port dimensions */
      dims[0] = NI_ExtList[index].dimX;
      dims[1] = NI_ExtList[index].dimY;
    }
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NI_ProbeOneSignal
 *
 * Abstract:
 *		Helper function to probe one signal. baseaddr must NOT be VIRTUAL_SIG
 *
 * Output Parameters
 *
 * Returns:
 *     Return value: Returns the last index value probed in a vector signal
 *========================================================================*/
static int32_t NI_ProbeOneSignal(int32_t idx, double *value, int32_t len,
  int32_t *count, int32_t vOffset, int32_t vLength)
{
  if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
    SetSITErrorMessage("NI_ProbeOneSignal: Received request to probe a virtual signal, but was expecting a ground source. Ignoring virtual signal probe. Report this behavior to National Instruments.",
                       0);
    return 0;
  } else {
    char *ptr = (char*)((NI_SigList[idx].baseaddr == BLOCKIO_SIG) ? S->blockIO :
                        S->inputs) + (uintptr_t)NI_SigList[idx].addr;
    int32_t subindex = (vLength == -1) ? 0 : vOffset;
    int32_t sublength = (vLength == -1) ? NI_SigList[idx].width : (vLength +
      vOffset);
    while ((subindex < sublength) && (*count < len))
      value[(*count)++] = NIRT_GetValueByDataType(ptr, subindex++,
        NI_SigList[idx].datatype, NI_SigList[idx].IsComplex);
    return *count;
  }
}

/*========================================================================*
 * Function: NIRT_ProbeSignals
 *
 * Abstract:
 *	returns the latest signal values.
 *
 * Input Parameters:
 *	sigindices	: list of signal indices to be probed.
 *	numsigs		: length of sigindices array.
 *
 *		NOTE: (Implementation detail) the sigindices array that is passed in is delimited by a value of -1.
 *		Thus the # of valid indices in the sigindices table is min(numsigs, index of value -1) - 1.
 *		Reason for subtracting 1, the first index in the array is used for bookkeeping and should be copied
 *		into the 0th index in the signal values buffer.
 *		Also, the 1st index in the signal values buffer should contain the current timestamp. Hence valid
 *		signal data should be filled in starting from index 2. Any non-scalar signals should be added to the
 *		buffer in row-order.
 *
 * Input/Output Parameters
 *	num			: (in) length of sigvalues buffer (out) number of values returned in the buffer
 *
 * Output Parameters:
 *	value		: array of signal values
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_ProbeSignals(int32_t* sigindices, int32_t numsigs,
  double* value, int32_t* len)
{
  int32_t i = 0;
  int32_t idx = 0;
  int32_t count = 0;
  if (!SITexportglobals.inCriticalSection) {
    SetSITErrorMessage("SignalProbe should only be called between ScheduleTasks and PostOutputs",
                       1);
  }

  /* Get the index to the first signal */
  if ((*len > 1) && (numsigs > 0)) {
    value[count++] = sigindices[0];
    value[count++] = 0;
  }

  /* Get the second and other signals */
  for (i = 1; (i < numsigs) && (count < *len); i++) {
    idx = sigindices[i];
    if (idx < 0) {
      break;
    }

    if (idx < NI_SigListSize) {
      if (NI_SigList[idx].baseaddr == VIRTUAL_SIG) {
        int32_t vidx = NI_VirtualBlockSources[NI_SigList[idx].addr];
        NI_ProbeOneSignal(vidx, value, *len, &count, 0, -1);
      } else {
        NI_ProbeOneSignal(idx, value, *len, &count, 0, -1);
      }
    }
  }

  *len = count;
  return count;
}

int32_t NI_InitializeParamStruct()
{
  memcpy(&rtParameter[0], &NACCBraytonCycle2017a_P, sizeof
         (P_NACCBraytonCycle2017a_T));
  return NI_OK;
}

/*  After the model has initialized and updated the parameters in
   rtParameter[0] (aka NACCBraytonCycle2017a_P) we make a copy to rtParameter[1] so
   that it is double buffered. We also do a memcpy to each task's copy.
 */
int32_t NI_InitParamDoubleBuf()
{
  int32_t idx = 1;

#ifdef MULTITASKING

  for (; idx <= NUMST - TID01EQ; idx++)
#endif

    memcpy(&rtParameter[idx], &rtParameter[0], sizeof(P_NACCBraytonCycle2017a_T));
  return NI_OK;
}

static int32_t NI_SetParamTxStatus = NI_OK;

/*========================================================================*
 * Function: NIRT_SetParameter
 *
 * Abstract:
 *	Set parameter value. Called either in scheduler loop or a background loop.
 *
 * Input Parameters:
 *	index	: index of the parameter (as specified in Parameter Information)
 *	subindex: index in the flattened array, if parameter is n-D array
 *	val		: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetParameter(int32_t index, int32_t subindex, double
  value)
{
  char* ptr = NULL;

  /* Check bounds */
  if (index >= NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus= NI_ERROR;
  }

  /* Commit parameter values */
  if (index < 0) {
    if (ReadSideDirtyFlag == 1) {
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_NACCBraytonCycle2017a_T));
      ReadSideDirtyFlag = 0;
      if (WriteSideDirtyFlag == 0) {
        /* No values to commit */
        return NI_OK;
      } else {
        SetSITErrorMessage("Parameters have been set inline and from the background loop at the same time. Parameters written from the background loop since the last commit have been lost.",
                           1);
        WriteSideDirtyFlag = 0;
        return NI_ERROR;
      }
    }

    /* If an error occurred and we have values to commit, then save to the write side and return error */
    if (NI_SetParamTxStatus == NI_ERROR) {
      // fail the transaction.
      // copy old list of parameters to the failed TX buffer
      if (WriteSideDirtyFlag == 1) {
        memcpy(&rtParameter[READSIDE], &rtParameter[1-READSIDE], sizeof
               (P_NACCBraytonCycle2017a_T));
      }

      // reset the status.
      NI_SetParamTxStatus = NI_OK;
      WriteSideDirtyFlag = 0;
      return NI_ERROR;
    }

    /* If we have values to commit, then save to the write-side */
    if (WriteSideDirtyFlag == 1) {
      S->defaultParam = (double *)&rtParameter[1-READSIDE];
      WaitForSingleObject(SITexportglobals.flipCriticalSection, INFINITE);
      READSIDE = 1 - READSIDE;
      SITexportglobals.copyTaskBitfield = 0xFFFFFFFF;
      ReleaseSemaphore(SITexportglobals.flipCriticalSection, 1, NULL);

      // Copy back the newly set parameters to the writeside.
      memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
             (P_NACCBraytonCycle2017a_T));
      WriteSideDirtyFlag = 0;
    }

    return NI_OK;
  }

  // verify that subindex is within bounds.
  if (subindex >= NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.",1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_NACCBraytonCycle2017a_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  WriteSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, value, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_SetVectorParameter
 *
 * Abstract:
 *	Sets the value to a parameter array.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	paramvalues	: array of values to set
 *	paramlength	: Length of parameter values.
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetVectorParameter( uint32_t index, const double
  * paramvalues, uint32_t paramlength)
{
  uint32_t i = 0;
  int32_t retval = NI_OK;
  char* ptr = NULL;

  /* verify that index is within bounds*/
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (paramlength != (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter length is incorrect.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* If we have pending modified parameters, then copy to write-side */
  if (ReadSideDirtyFlag == 1) {
    memcpy(&rtParameter[1-READSIDE], &rtParameter[READSIDE], sizeof
           (P_NACCBraytonCycle2017a_T));
    ReadSideDirtyFlag = 0;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char*)(&rtParameter[1-READSIDE]) + NI_ParamList[index].addr;
  while (i < paramlength) {
    /* Convert the incoming double datatype to the parameter's internal datatype and update value */
    retval = retval & NIRT_SetValueByDataType(ptr, i, paramvalues[i],
      NI_ParamList[index].datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  WriteSideDirtyFlag = 1;
  return retval;
}

/*========================================================================*
 * Function: NIRT_SetScalarParameterInline
 *
 * Abstract:
 *	Sets the value to a parameter immediately without the need of a commit request.
 *
 * Input Parameters:
 *	index		: index of the parameter as returned by NIRT_GetParameterSpec()
 *	subindex	: offset of the element within the parameter
 *	paramvalue	: Value to set the parameter to
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetScalarParameterInline( uint32_t index, uint32_t
  subindex, double paramvalue)
{
  char* ptr = NULL;
  if (index >= (uint32_t)NI_ParamListSize) {
    SetSITErrorMessage("Parameter index is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  // verify that subindex is within bounds.
  if (subindex >= (uint32_t)NI_ParamList[index].width) {
    SetSITErrorMessage("Parameter subindex is out of bounds.", 1);
    return NI_SetParamTxStatus = NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  ReadSideDirtyFlag = 1;

  /* Convert the incoming double datatype to the parameter's internal datatype and update value */
  return NIRT_SetValueByDataType(ptr, subindex, paramvalue, NI_ParamList[index].
    datatype, NI_ParamList[index].IsComplex);
}

/*========================================================================*
 * Function: NIRT_GetParameter
 *
 * Abstract:
 *	Get the current value of a parameter.
 *
 * Input Parameters:
 *	index	: index of the parameter
 *	subindex: element index into the flattened array if an array
 *
 * Output Parameters:
 *	val		: value of the parameter
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetParameter(int32_t index, int32_t subindex, double
  *value)
{
  char* ptr = NULL;

  /* Check index boundaries */
  if (index >= NI_ParamListSize || index < 0 || (subindex>=NI_ParamList[index].
       width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;

  /* Convert the parameter's internal datatype to double and return its value */
  *value = NIRT_GetValueByDataType(ptr, subindex, NI_ParamList[index].datatype,
    NI_ParamList[index].IsComplex);
  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetVectorParameter
 *
 * Abstract:
 *	Get the current value of a vector parameter.
 *
 * Input Parameters:
 *	index: index of the parameter
 *	paramLength: length of the parameter
 *
 * Output Parameters:
 *	paramValues: an array of the parameter's value
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetVectorParameter(uint32_t index, double* paramvalues,
  uint32_t paramlength)
{
  char* ptr = NULL;
  uint32_t i = 0;
  if (index >= (uint32_t)NI_ParamListSize || index < 0 || (paramlength !=
       (uint32_t)NI_ParamList[index].width)) {
    return NI_ERROR;
  }

  /* Get the parameter's address into the Parameter struct
     casting to char to perform pointer arithmetic using the byte offset */
  ptr = (char *)(&rtParameter[READSIDE]) + NI_ParamList[index].addr;
  while (i<paramlength) {
    /* Convert the parameter's internal datatype to double and return its value */
    paramvalues[i] = NIRT_GetValueByDataType(ptr, i, NI_ParamList[index].
      datatype, NI_ParamList[index].IsComplex);
    i++;
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_GetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_GetSimState(int32_t* numContStates, char
  * contStatesNames, double* contStates, int32_t* numDiscStates, char
  * discStatesNames, double* discStates, int32_t* numClockTicks, char
  * clockTicksNames, int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  if ((numContStates != NULL) && (numDiscStates != NULL) && (numClockTicks !=
       NULL)) {
    if (*numContStates < 0 || *numDiscStates < 0 || *numClockTicks < 0) {
      *numContStates = 0;
      *numDiscStates = 96;
      *numClockTicks = NUMST - TID01EQ;
      return NI_OK;
    }
  }

  if ((discStates != NULL) && (discStatesNames != NULL)) {
    idx = 0;
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.Memory1_PreviousInput, 0, 33, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.Memory1_PreviousInput, 1, 33, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.Memory1_PreviousInput, 2, 33, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.Memory1_PreviousInput, 3, 33, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.Memory1_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.Memory_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.Memory_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.Memory9_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.Memory9_PreviousInput");
    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&NACCBraytonCycle2017a_DW.Memory4_PreviousInput, count, 14, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&NACCBraytonCycle2017a_DW.Memory4_PreviousInput");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.Memory1_PreviousInput_b, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.Memory1_PreviousInput_b");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.Memory2_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.Memory2_PreviousInput");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.Memory3_PreviousInput, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.Memory3_PreviousInput");
    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&NACCBraytonCycle2017a_DW.Memory8_PreviousInput, count, 14, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&NACCBraytonCycle2017a_DW.Memory8_PreviousInput");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.Memory9_PreviousInput_a, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.Memory9_PreviousInput_a");
    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&NACCBraytonCycle2017a_DW.Memory4_PreviousInput_p, count, 14, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&NACCBraytonCycle2017a_DW.Memory4_PreviousInput_p");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.Memory1_PreviousInput_p, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.Memory1_PreviousInput_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.Memory2_PreviousInput_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.Memory2_PreviousInput_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.Memory3_PreviousInput_d, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.Memory3_PreviousInput_d");
    for (count = 0; count < 7; count++) {
      discStates[idx] = NIRT_GetValueByDataType
        (&NACCBraytonCycle2017a_DW.Memory8_PreviousInput_p, count, 14, 0);
      strcpy(discStatesNames + (idx++ * 100),
             "&NACCBraytonCycle2017a_DW.Memory8_PreviousInput_p");
    }

    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_m, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_a, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_n, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_n");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_f, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_f");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_o, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_h, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_mu, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_mu");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_p, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_p");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_l, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_j, 0, 0, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK, 2, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK, 3, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_l, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_l, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_l, 2, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_l, 3, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_l");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_a, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_a, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_a, 2, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_a, 3, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_a");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_le, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_le");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_le, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_le");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_le, 2, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_le");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_le, 3, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_le");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_i, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_i, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_i, 2, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_i, 3, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_i");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_m, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_m, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_m, 2, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_m, 3, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_m");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_h, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_h, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_h, 2, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_h, 3, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_h");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_c, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_c, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_c, 2, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_c, 3, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_c");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_mg, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_mg");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_mg, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_mg");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_mg, 2, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_mg");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_mg, 3, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_mg");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_j, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_j, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_j, 2, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_j, 3, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_j");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_o, 0, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_o, 1, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_o, 2, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_o");
    discStates[idx] = NIRT_GetValueByDataType
      (&NACCBraytonCycle2017a_DW.SFunction_PWORK_o, 3, 30, 0);
    strcpy(discStatesNames + (idx++ * 100),
           "&NACCBraytonCycle2017a_DW.SFunction_PWORK_o");
  }

  if ((clockTicks != NULL) && (clockTicksNames != NULL)) {
    clockTicks[0] = S->Timing.clockTick0;
    strcpy(clockTicksNames, "clockTick0");
  }

  return NI_OK;
}

/*========================================================================*
 * Function: NIRT_SetSimState
 *
 * Abstract:
 *
 * Returns:
 *	NI_OK if no error
 *========================================================================*/
DLL_EXPORT int32_t NIRT_SetSimState(double* contStates, double* discStates,
  int32_t* clockTicks)
{
  int32_t count = 0;
  int32_t idx = 0;
  if (discStates != NULL) {
    idx = 0;
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory1_PreviousInput, 0,
      discStates[idx++], 33, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory1_PreviousInput, 1,
      discStates[idx++], 33, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory1_PreviousInput, 2,
      discStates[idx++], 33, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory1_PreviousInput, 3,
      discStates[idx++], 33, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory9_PreviousInput, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory4_PreviousInput,
        count, discStates[idx++], 14, 0);
    }

    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory1_PreviousInput_b, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory2_PreviousInput, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory3_PreviousInput, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory8_PreviousInput,
        count, discStates[idx++], 14, 0);
    }

    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory9_PreviousInput_a, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory4_PreviousInput_p,
        count, discStates[idx++], 14, 0);
    }

    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory1_PreviousInput_p, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory2_PreviousInput_o, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory3_PreviousInput_d, 0,
      discStates[idx++], 0, 0);
    for (count = 0; count < 7; count++) {
      NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.Memory8_PreviousInput_p,
        count, discStates[idx++], 14, 0);
    }

    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_m, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_a, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_n, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_f, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_o, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_h, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_mu,
      0, discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_p, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_l, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_T_CAL_DWORK_j, 0,
      discStates[idx++], 0, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK, 2,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK, 3,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_l, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_l, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_l, 2,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_l, 3,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_a, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_a, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_a, 2,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_a, 3,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_le, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_le, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_le, 2,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_le, 3,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_i, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_i, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_i, 2,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_i, 3,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_m, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_m, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_m, 2,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_m, 3,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_h, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_h, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_h, 2,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_h, 3,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_c, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_c, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_c, 2,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_c, 3,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_mg, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_mg, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_mg, 2,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_mg, 3,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_j, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_j, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_j, 2,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_j, 3,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_o, 0,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_o, 1,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_o, 2,
      discStates[idx++], 30, 0);
    NIRT_SetValueByDataType(&NACCBraytonCycle2017a_DW.SFunction_PWORK_o, 3,
      discStates[idx++], 30, 0);
  }

  if (clockTicks != NULL) {
    S->Timing.clockTick0 = clockTicks[0];
  }

  return NI_OK;
}

#endif                                 // of NI_ROOTMODEL_NACCBraytonCycle2017a
