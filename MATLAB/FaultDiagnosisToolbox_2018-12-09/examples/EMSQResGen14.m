function [r, state] = EMSQResGen14(z,state,params,Ts)
% EMSQRESGEN14 Sequential residual generator for model 'Electric motor'
% Causality: der
%
% Structurally sensitive to faults: fw, fD
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = EMSQResGen14( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: w

% File generated 18-Apr-2019 15:42:08

  % Parameters
  b = params.b;
  J = params.J;

  % Known variables
  yw = z(3);
  yd = z(4);

  % Initialize state variables
  w = state.w;

  % Residual generator body
  DT = yd; % e9
  w = yw; % e8
  dw = (DT-b*w)/J; % e3
   
  r = w-state.w; % e11

  % Update integrator variables
  w = ApproxInt(dw,state.w,Ts); % e11

  % Update state variables
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