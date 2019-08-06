function [r, state] = ResGenT1Dyn_2_2(z,state,params,Ts)
% RESGENT1DYN_2_2 Sequential residual generator for model 'ThermoNet'
% Causality: mixed
%
% Structurally sensitive to faults: fT1
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = ResGenT1Dyn_2_2( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: T2, T1, Tav

% File generated 02-Jul-2019 14:27:20

  % Parameters
  R = params.R;
  cp = params.cp;

  % Known variables
  y1 = z(1);
  y2 = z(2);
  y6 = z(6);

  % Initialize state variables
  T2 = state.T2;
  T1 = state.T1;
  Tav = state.Tav;

  % Residual generator body
  mdot = y6; % e6
  QTC = cp*mdot*(T1-T2); % e12
  Tav = T1*(1.0/2.0)+T2*(1.0/2.0); % e10
  dTav = ApproxDiff(Tav,state.Tav,Ts); % e13
  Tinfty = Tav-QTC*R; % e11
  dT2 = (dTav*(T2-Tinfty))/(Tav-Tinfty); % e16
  dT1 = (dTav*(T1-Tinfty))/(Tav-Tinfty); % e14
  WT1 = y2; % e2
  BT1 = y1; % e1
   
  r=BT1*(-1.0/2.0)+T1-WT1*(1.0/2.0); % e8

  % Update integrator variables
  T2 = ApproxInt(dT2,state.T2,Ts); % e17
  T1 = ApproxInt(dT1,state.T1,Ts); % e15

  % Update state variables
  state.T2 = T2;
  state.T1 = T1;
  state.Tav = Tav;
end

function dx=ApproxDiff(x,xold,Ts)
  if length(xold)==1
    dx = (x-xold)/Ts;
  elseif length(xold)==2
    dx = (3*x-4*xold(1)+xold(2))/2/Ts;
  else
    error('Differentiation of order higher than 2 not supported');
  end
end

function x1=ApproxInt(dx,x0,Ts)
  x1 = x0 + Ts*dx;
end
