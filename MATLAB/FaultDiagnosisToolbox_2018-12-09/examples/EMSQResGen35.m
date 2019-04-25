function [r, state] = EMSQResGen35(z,state,params,Ts)
% EMSQRESGEN35 Sequential residual generator for model 'Electric motor'
% Causality: int
%
% Structurally sensitive to faults: fR, fi, fD
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = EMSQResGen35( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: w, I

% File generated 18-Apr-2019 15:42:21

  % Parameters
  Ka = params.Ka;
  b = params.b;
  R = params.R;
  J = params.J;
  L = params.L;

  % Known variables
  V = z(1);
  yi = z(2);
  yd = z(4);

  % Initialize state variables
  w = state.w;
  I = state.I;

  % Residual generator body
  DT = yd; % e9
  I = yi; % e7
  dw = (DT-b*w)/J; % e3
  dI = -(-V+I*R+I*Ka*w)/L; % e1
   
  r = I-state.I; % e10

  % Update integrator variables
  w = ApproxInt(dw,state.w,Ts); % e11
  I = ApproxInt(dI,state.I,Ts); % e10

  % Update state variables
  state.w = w;
  state.I = I;
end

function x1=ApproxInt(dx,x0,Ts)
  x1 = x0 + Ts*dx;
end
