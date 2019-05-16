function [r, state] = ResGenHeaterOut_2_3(z,state,params,Ts)
% RESGENHEATEROUT_2_3 Sequential residual generator for model 'HotLeg'
% Causality: der
%
% Structurally sensitive to faults: fT1
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = ResGenHeaterOut_2_3( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: T1

% File generated 15-May-2019 11:14:47

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
  WT13 = y2; % e2
  BT12 = y1; % e1
  T1 = BT12*(1.0/2.0)+WT13*(1.0/2.0); % e6
  dT1 = ApproxDiff(T1,state.T1,Ts);  % e11
  Tinfty = Ltc*M*R*cp*(dT1+T1/(Ltc*M*R*cp)); % e9
  AT02 = Tinfty; % e7
   
  r=-AT02+y5; % e5

  % Update state variables
  state.T1 = T1;
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
