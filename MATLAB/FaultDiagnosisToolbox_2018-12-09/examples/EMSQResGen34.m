function [r, state] = EMSQResGen34(z,state,params,Ts)
% EMSQRESGEN34 Sequential residual generator for model 'Electric motor'
% Causality: der
%
% Structurally sensitive to faults: fR, fi, fD
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = EMSQResGen34( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: I, w

% File generated 18-Apr-2019 15:42:20

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
  I = state.I;
  w = state.w;

  % Residual generator body
  DT = yd; % e9
  I = yi; % e7
  dI = ApproxDiff(I,state.I,Ts);  % e10
  w = -(-V+L*dI+I*R)/(I*Ka); % e1
  dw = ApproxDiff(w,state.w,Ts);  % e11
   
  r=-DT+J*dw+b*w; % e3

  % Update state variables
  state.I = I;
  state.w = w;
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
