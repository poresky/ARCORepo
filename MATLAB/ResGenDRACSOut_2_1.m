function [r, state] = ResGenDRACSOut_2_1(z,state,params,Ts)
% RESGENDRACSOUT_2_1 Sequential residual generator for model 'DRACS TC'
% Causality: int
%
% Structurally sensitive to faults: fT1
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = ResGenDRACSOut_2_1( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: T1

% File generated 07-May-2019 13:14:37

  % Parameters
  R = params.R;
  cp = params.cp;
  M = params.M;
  Ltc = params.Ltc;

  % Known variables
  y1 = z(1);
  y2 = z(2);
  y5 = z(5);
  y6 = z(6);

  % Initialize state variables
  T1 = state.T1;

  % Residual generator body
  AT02 = y6; % e6
  AT01 = y5; % e5
  Tinfty = AT01*(1.0/2.0)+AT02*(1.0/2.0); % e8
  dT1 = -(T1-Tinfty)/(Ltc*M*R*cp); % e10
  WT62 = y2; % e2
  BT63 = T1*2.0-WT62; % e7
   
  r=-BT63+y1; % e1

  % Update integrator variables
  T1 = ApproxInt(dT1,state.T1,Ts); % e12

  % Update state variables
  state.T1 = T1;
end

function x1=ApproxInt(dx,x0,Ts)
  x1 = x0 + Ts*dx;
end
