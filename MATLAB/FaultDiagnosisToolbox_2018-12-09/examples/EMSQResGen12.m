function [r, state] = EMSQResGen12(z,state,params,Ts)
% EMSQRESGEN12 Sequential residual generator for model 'Electric motor'
% Causality: int
%
% Structurally sensitive to faults: fw, fD
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = EMSQResGen12( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: w

% File generated 18-Apr-2019 15:42:07

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
  dw = (DT-b*w)/J; % e3
   
  r=-w+yw; % e8

  % Update integrator variables
  w = ApproxInt(dw,state.w,Ts); % e11

  % Update state variables
  state.w = w;
end

function x1=ApproxInt(dx,x0,Ts)
  x1 = x0 + Ts*dx;
end
