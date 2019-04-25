#include "mex.h"
#include <math.h>

// RESGEN2CB Sequential residual generator for model 'Three tank system' (batch version)
// Causality: int
//
// Structurally sensitive to faults: fV1, fT1, fT2
//
// Example of basic usage:
//   Let z be the observations and N the number of samples, then
//   the residual generator can be simulated by:
//
//   r = ResGen2cb( z, state, params, 1/fs );
//
//   The observations z must be a MxN matrix where M is the number
//   of known signals and N the number of samples.
//
//   State is a structure with the state of the residual generator.
//   The state has fieldnames: p2, p1

// File generated 25-Apr-2019 11:56:37

typedef struct {
  double p2;
  double p1;
} ResState;

typedef struct {
  double Rv1;
  double CT1;
  double CT2;
} Parameters;

// Simple Euler-forward integration
double ApproxInt(double dx, double x0, double Ts);

void ResGen2cb( double* r, const double *z, ResState &state, const Parameters &params, double Ts );
void GetParameters( const mxArray *mxParams, Parameters* params );
void GetState( const mxArray *mxStates, ResState* state );

void
mexFunction( int nlhs, mxArray *plhs[], 
	     int nrhs, const mxArray*prhs[] )
{
  if( nrhs != 4 ) {
    mexErrMsgIdAndTxt( "MATLAB:WrongNumberofInputArguments", 
    "Incorrect number of input arguments");
  }

  if( !mxIsStruct(prhs[2]) ) {
    mexErrMsgIdAndTxt( "MATLAB:Parameters",
      "Parameters must be given by a struct");
  }
  
  mxArray *matVar;
  double  *matVarPr;

  // Determine size of dataset
  const mxArray *zMx = prhs[0];
  long N = mxGetN( zMx ); // Number of datapoints
  long M = mxGetM( zMx ); // Number of measurements


  // Allocate output variables
  plhs[0] = mxCreateDoubleMatrix(1, N, mxREAL); // Residual
  double *r = mxGetPr( plhs[0] ); // Pointer to output array
  
  // Parameters
  Parameters params;
  GetParameters( prhs[2], &params );

  // Known variables
  double *z = (double *)mxGetData( prhs[0] );

  // Initialize state variables
  ResState state;
  GetState( prhs[1], &state );

  // Sampling time
  double Ts = mxGetScalar(prhs[3]);

  // Main residual computation loop
  for( int k=0; k < N; k++ ) {
    ResGen2cb(r+k, z+M*k, state, params, Ts );
  }
}


void
ResGen2cb( double* r, const double *z, ResState &state, const Parameters &params, double Ts )
{
  mxArray *matVar;
  double  *matVarPr;

  // Parameters
  double Rv1 = params.Rv1;
  double CT1 = params.CT1;
  double CT2 = params.CT2;

  // Declare residual generator variables
  double p1;
  double p2;
  double q0;
  double q1;
  double q2;
  double dp1;
  double dp2;


  // Initialize integral state variables
  p2 = state.p2;
  p1 = state.p1;

  // Known variables
  double y1 = z[0];
  double y2 = z[1];
  double y3 = z[2];

  // Residual generator body
  q2 = y2; // e8
  q0 = y3; // e9
  q1 = (p1-p2)/Rv1; // e1
  dp2 = (q1-q2)/CT2; // e5
  dp1 = (q0-q1)/CT1; // e4
   
  r[0]=-p1+y1; // e7

  // Update integrator variables
  p2 = ApproxInt(dp2,state.p2,Ts); // e11
  p1 = ApproxInt(dp1,state.p1,Ts); // e10

  // Update state variables
  state.p2 = p2;
  state.p1 = p1;
}

double
ApproxInt(double dx, double x0, double Ts)
{
  return x0 + Ts*dx;
}

void
GetParameters( const mxArray *mxParams, Parameters* params )
{
  mxArray *matVar;
  double  *matVarPr;

  matVar = mxGetField( mxParams, 0, "Rv1"); matVarPr = mxGetPr( matVar );
  params->Rv1 = *matVarPr;
  matVar = mxGetField( mxParams, 0, "CT1"); matVarPr = mxGetPr( matVar );
  params->CT1 = *matVarPr;
  matVar = mxGetField( mxParams, 0, "CT2"); matVarPr = mxGetPr( matVar );
  params->CT2 = *matVarPr;
}

void
GetState( const mxArray *mxState, ResState* state )
{
  mxArray *matVar;
  double  *matVarPr;

  matVar = mxGetField( mxState, 0, "p2"); matVarPr = mxGetPr( matVar );
  state->p2 = *matVarPr;
  matVar = mxGetField( mxState, 0, "p1"); matVarPr = mxGetPr( matVar );
  state->p1 = *matVarPr;

}
