function [r, state] = EMSQResGen22(z,state,params,Ts)
% EMSQRESGEN22 Sequential residual generator for model 'Electric motor'
% Causality: der
%
% Structurally sensitive to faults: fR, fi, fw
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = EMSQResGen22( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: I

% File generated 18-Apr-2019 15:42:16

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
  dI = ApproxDiff(I,state.I,Ts);  % e10
   
  r=V-L*dI-I*R-I*Ka*w; % e1

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
