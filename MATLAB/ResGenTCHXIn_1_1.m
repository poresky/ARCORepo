function [r, state] = ResGenTCHXIn_1_1(z,state,params,Ts)
% RESGENTCHXIN_1_1 Sequential residual generator for model 'DRACS TC'
% Causality: int
%
% Structurally sensitive to faults: fT2
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = ResGenTCHXIn_1_1( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: T2

% File generated 07-May-2019 13:14:41

  % Parameters
  R = params.R;
  cp = params.cp;
  M = params.M;
  Ltc = params.Ltc;

  % Known variables
  y3 = z(3);
  y4 = z(4);
  y5 = z(5);
  y6 = z(6);

  % Initialize state variables
  T2 = state.T2;

  % Residual generator body
  AT02 = y6; % e6
  AT01 = y5; % e5
  Tinfty = AT01*(1.0/2.0)+AT02*(1.0/2.0); % e8
  dT2 = -(T2-Tinfty)/(Ltc*M*R*cp); % e11
  WT64 = y4; % e4
  BT65 = T2*2.0-WT64; % e9
   
  r=-BT65+y3; % e3

  % Update integrator variables
  T2 = ApproxInt(dT2,state.T2,Ts); % e13

  % Update state variables
  state.T2 = T2;
end

function x1=ApproxInt(dx,x0,Ts)
  x1 = x0 + Ts*dx;
end
