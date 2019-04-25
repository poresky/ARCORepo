function [r, state] = EMSQResGen23(z,state,params,Ts)
% EMSQRESGEN23 Sequential residual generator for model 'Electric motor'
% Causality: der
%
% Structurally sensitive to faults: fR, fi, fw
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = EMSQResGen23( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: I

% File generated 18-Apr-2019 15:42:17

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
  I = yi; % e7
  dI = ApproxDiff(I,state.I,Ts);  % e10
  w = -(-V+L*dI+I*R)/(I*Ka); % e1
   
  r=-w+yw; % e8

  % Update state variables
  state.I = I;
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
