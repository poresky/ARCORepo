function [r, state] = EMSQResGen24(z,state,params,Ts)
% EMSQRESGEN24 Sequential residual generator for model 'Electric motor'
% Causality: int
%
% Structurally sensitive to faults: fR, fi, fw
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = EMSQResGen24( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: I

% File generated 18-Apr-2019 15:42:18

  % Parameters
  Ka = params.Ka;
  R = params.R;
  L = params.L;

  % Known variables
  V = z(1);
  yi = z(2);
  yw = z(3);

  % Initialize state variables
  I = state.I;

  % Residual generator body
  w = yw; % e8
  I = yi; % e7
  dI = -(-V+I*R+I*Ka*w)/L; % e1
   
  r = I-state.I; % e10

  % Update integrator variables
  I = ApproxInt(dI,state.I,Ts); % e10

  % Update state variables
  state.I = I;
end

function x1=ApproxInt(dx,x0,Ts)
  x1 = x0 + Ts*dx;
end
