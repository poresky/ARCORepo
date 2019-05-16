function [r, state] = ResGenTCHXIn_2_1(z,state,params,Ts)
% RESGENTCHXIN_2_1 Sequential residual generator for model 'DRACS TC'
% Causality: int
%
% Structurally sensitive to faults: fT1
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = ResGenTCHXIn_2_1( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: T1

% File generated 15-May-2019 11:19:32

  % Parameters
  R = params.R;
  cp = params.cp;
  M = params.M;
  Ltc = params.Ltc;

  % Known variables
  y1 = z(1);
  y2 = z(2);
  y5 = z(5);

  % Initialize state variables
  T1 = state.T1;

  % Residual generator body
  AT02 = y5; % e5
  Tinfty = AT02; % e7
  dT1 = -(T1-Tinfty)/(Ltc*M*R*cp); % e9
  WT62 = y2; % e2
  BT63 = T1*2.0-WT62; % e6
   
  r=-BT63+y1; % e1

  % Update integrator variables
  T1 = ApproxInt(dT1,state.T1,Ts); % e11

  % Update state variables
  state.T1 = T1;
end

function x1=ApproxInt(dx,x0,Ts)
  x1 = x0 + Ts*dx;
end
