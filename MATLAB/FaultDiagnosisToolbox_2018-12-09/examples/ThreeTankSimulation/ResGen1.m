function [r, state] = ResGen1(z,state,params,Ts)
% RESGEN1 Sequential residual generator for model 'Three tank system'
% Causality: der
%
% Structurally sensitive to faults: fV1, fT1, fT2
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = ResGen1( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: p1, p2

% File generated 24-Apr-2019 20:17:20

  % Parameters
  Rv1 = params.Rv1;
  CT1 = params.CT1;
  CT2 = params.CT2;

  % Known variables
  y1 = z(1);
  y2 = z(2);
  y3 = z(3);

  % Initialize state variables
  p1 = state.p1;
  p2 = state.p2;

  % Residual generator body
  q2 = y2; % e8
  q0 = y3; % e9
  p1 = y1; % e7
  dp1 = ApproxDiff(p1,state.p1,Ts);  % e10
  q1 = q0-CT1*dp1; % e4
  p2 = p1-Rv1*q1; % e1
  dp2 = ApproxDiff(p2,state.p2,Ts);  % e11
   
  r=dp2-(q1-q2)/CT2; % e5

  % Update state variables
  state.p1 = p1;
  state.p2 = p2;
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
