#include "mex.h"
#include <math.h>

// RESGEN_1_1 Sequential residual generator for model 'Reprocessing experiment'
// Causality: mixed
//
// Structurally sensitive to faults: fQ1, fQ2, fQ3, fH1, fH2, fH3, fH4
//
// Example of basic usage:
//   Let z be the observations and N the number of samples, then
//   the residual generator can be simulated by:
//
//   for k=1:N
//     [r(k), state] = ResGen_1_1( z(k,:), state, params, 1/fs );
//   end
//   where state is a structure with the state of the residual generator.
//   The state has fieldnames: h4, h3, h1, h2

// File generated 18-Apr-2019 16:50:26

typedef struct {
  double h4;
  double h3;
  double h1;
  double h2;
} ResState;

typedef struct {
  double R1;
  double R2;
  double R3;
  double A1;
  double A2;
  double A3;
  double A4;
  double rho;
  double g;
} Parameters;

// Simple Euler-forward integration
double ApproxInt(double dx, double x0, double Ts);

// Simple Euler-forward approximation of a derivative
double ApproxDiff(double dx, double x0, double Ts);

void ResGen_1_1( double* r, const double *z, ResState &state, const Parameters &params, double Ts );
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

  // Allocate output variables
  plhs[0] = mxCreateDoubleMatrix(1, 1, mxREAL); // Residual
  double *r = mxGetPr( plhs[0] ); // Pointer to output array

  // Create state output
  const char *stateNames[4] = {"h4", "h3", "h1", "h2"};
  plhs[1] = mxCreateStructMatrix(1, 1, 4, stateNames);

  mxArray *matVar;
  double  *matVarPr;

  // Known variables
  double *z = (double *)mxGetData( prhs[0] );
  
  // Parameters
  Parameters params;
  GetParameters( prhs[2], &params );

  // Initialize state variables
  ResState state;
  GetState( prhs[1], &state );

  // Sampling time
  double Ts = mxGetScalar(prhs[3]);

  // Call residual generator body function
  ResGen_1_1(r, z, state, params, Ts );

  // Update state variables
  mxSetFieldByNumber(plhs[1], 0, 0, mxCreateDoubleScalar(state.h4));
  mxSetFieldByNumber(plhs[1], 0, 1, mxCreateDoubleScalar(state.h3));
  mxSetFieldByNumber(plhs[1], 0, 2, mxCreateDoubleScalar(state.h1));
  mxSetFieldByNumber(plhs[1], 0, 3, mxCreateDoubleScalar(state.h2));
}

void
ResGen_1_1( double* r, const double *z, ResState &state, const Parameters &params, double Ts )
{
  // Parameters
  double R1 = params.R1;
  double R2 = params.R2;
  double R3 = params.R3;
  double A1 = params.A1;
  double A2 = params.A2;
  double A3 = params.A3;
  double A4 = params.A4;
  double rho = params.rho;
  double g = params.g;

  // Declare residual generator variables
  double h1;
  double h2;
  double h3;
  double h4;
  double q0;
  double q1;
  double q2;
  double q3;
  double q4;
  double dh1;
  double dh2;
  double dh3;
  double dh4;

  // Initialize integral state variables
  h4 = state.h4;
  h3 = state.h3;

  // Known variables
  double y1 = z[0];
  double y2 = z[1];
  double y3 = z[2];

  // Residual generator body
  q4 = y2; // e14
  q0 = y1; // e13
  h1 = y3; // e15
  dh1 = ApproxDiff(h1,state.h1,Ts);  // e9
  q1 = q0-A1*dh1; // e5
  h2 = -(R1*q1-g*h1*rho)/(g*rho); // e1
  dh2 = ApproxDiff(h2,state.h2,Ts);  // e10
  q3 = (g*rho*(h3-h4))/R3; // e3
  dh4 = (q3-q4)/A4; // e8
  q2 = (g*rho*(h2-h3))/R2; // e2
  dh3 = (q2-q3)/A3; // e7
   
  r[0]=dh2-(q1-q2)/A2; // e6

  // Update integrator variables
  h4 = ApproxInt(dh4,state.h4,Ts); // e12
  h3 = ApproxInt(dh3,state.h3,Ts); // e11

  // Update state variables
  state.h4 = h4;
  state.h3 = h3;
  state.h1 = h1;
  state.h2 = h2;
}

double
ApproxDiff(double x, double xold, double Ts)
{
  return (x-xold)/Ts;
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

  matVar = mxGetField( mxParams, 0, "R1"); matVarPr = mxGetPr( matVar );
  params->R1 = *matVarPr;
  matVar = mxGetField( mxParams, 0, "R2"); matVarPr = mxGetPr( matVar );
  params->R2 = *matVarPr;
  matVar = mxGetField( mxParams, 0, "R3"); matVarPr = mxGetPr( matVar );
  params->R3 = *matVarPr;
  matVar = mxGetField( mxParams, 0, "A1"); matVarPr = mxGetPr( matVar );
  params->A1 = *matVarPr;
  matVar = mxGetField( mxParams, 0, "A2"); matVarPr = mxGetPr( matVar );
  params->A2 = *matVarPr;
  matVar = mxGetField( mxParams, 0, "A3"); matVarPr = mxGetPr( matVar );
  params->A3 = *matVarPr;
  matVar = mxGetField( mxParams, 0, "A4"); matVarPr = mxGetPr( matVar );
  params->A4 = *matVarPr;
  matVar = mxGetField( mxParams, 0, "rho"); matVarPr = mxGetPr( matVar );
  params->rho = *matVarPr;
  matVar = mxGetField( mxParams, 0, "g"); matVarPr = mxGetPr( matVar );
  params->g = *matVarPr;
}

void
GetState( const mxArray *mxState, ResState* state )
{
  mxArray *matVar;
  double  *matVarPr;

  matVar = mxGetField( mxState, 0, "h4"); matVarPr = mxGetPr( matVar );
  state->h4 = *matVarPr;
  matVar = mxGetField( mxState, 0, "h3"); matVarPr = mxGetPr( matVar );
  state->h3 = *matVarPr;
  matVar = mxGetField( mxState, 0, "h1"); matVarPr = mxGetPr( matVar );
  state->h1 = *matVarPr;
  matVar = mxGetField( mxState, 0, "h2"); matVarPr = mxGetPr( matVar );
  state->h2 = *matVarPr;

}
