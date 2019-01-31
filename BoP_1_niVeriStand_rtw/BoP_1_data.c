#include "ni_modelframework.h"
#if defined VXWORKS || defined kNIOSLinux
#define BoP_1_P                        BoP_1_P DataSection(".NIVS.defaultparams")
#endif

/*
 * BoP_1_data.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "BoP_1".
 *
 * Model version              : 1.7
 * Simulink Coder version : 8.12 (R2017a) 16-Feb-2017
 * C source code generated on : Tue Dec 04 13:28:27 2018
 *
 * Target selection: NIVeriStand.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "BoP_1.h"
#include "BoP_1_private.h"

/* Block parameters (auto storage) */
P_BoP_1_T BoP_1_P = {
  0.10944444444444444,                 /* Expression: (419-25)/3600
                                        * Referenced by: '<Root>/Constant'
                                        */
  0.00488888888888889,                 /* Expression: (18.6-1)/3600
                                        * Referenced by: '<Root>/Constant1'
                                        */
  0.27777777777777779,                 /* Expression: (1000)/3600
                                        * Referenced by: '<Root>/Constant2'
                                        */
  2.1271186440677967,                  /* Expression: (670-419)/118
                                        * Referenced by: '<Root>/Constant3'
                                        */
  2.1271186440677967,                  /* Expression: (670-419)/118
                                        * Referenced by: '<Root>/Constant6'
                                        */
  79.0,                                /* Expression: (1065-670)/5
                                        * Referenced by: '<Root>/Constant9'
                                        */
  63.6,                                /* Expression: (702-384)/5
                                        * Referenced by: '<Root>/Constant11'
                                        */
  384.0,                               /* Expression: 384
                                        * Referenced by: '<Root>/Constant10'
                                        */
  18.2,                                /* Expression: (141-50)/5
                                        * Referenced by: '<Root>/Constant13'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<Root>/Constant12'
                                        */
  419.0,                               /* Expression: 419
                                        * Referenced by: '<Root>/Constant4'
                                        */
  5.0,                                 /* Expression: 5
                                        * Referenced by: '<Root>/Constant5'
                                        */
  50.0,                                /* Expression: 50
                                        * Referenced by: '<Root>/Constant7'
                                        */
  1.0                                  /* Expression: 1
                                        * Referenced by: '<Root>/Constant8'
                                        */
};

/*========================================================================*
 * NI VeriStand Model Framework code generation
 *
 * Model : BoP_1
 * Model version : 1.7
 * VeriStand Model Framework version : 2017.0.1.0 (2017 f1)
 * Source generated on : Tue Dec 04 13:28:27 2018
 *========================================================================*/
#if defined VXWORKS || defined kNIOSLinux

typedef struct {
  int32_t size;
  int32_t width;
  int32_t basetype;
} NI_ParamSizeWidth;

NI_ParamSizeWidth P_BoP_1_T_sizes[] DataSection(".NIVS.defaultparamsizes") = {
  { sizeof(P_BoP_1_T), 1 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },

  { sizeof(real_T), 1, 0 },
};

#endif
