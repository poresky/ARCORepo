function [r, state] = ResGen2(z,state,params,Ts)
% RESGEN2 Sequential residual generator for model 'Three tank system'
% Causality: int
%
% Structurally sensitive to faults: fV1, fT1, fT2
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = ResGen2( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: p2, p1

% File generated 24-Apr-2019 20:17:22

  % Parameters
  Rv1 = params.Rv1;
  CT1 = params.CT1;
  CT2 = params.CT2;

  % Known variables
  y1 = z(1);
  y2 = z(2);
  y3 = z(3);

  % Initialize state variables
  p2 = state.p2;
  p1 = state.p1;

  % Residual generator body
  q2 = y2; % e8
  q0 = y3; % e9
  q1 = (p1-p2)/Rv1; % e1
  dp2 = (q1-q2)/CT2; % e5
  dp1 = (q0-q1)/CT1; % e4
   
  r=-p1+y1; % e7

  % Update integrator variables
  p2 = ApproxInt(dp2,state.p2,Ts); % e11
  p1 = ApproxInt(dp1,state.p1,Ts); % e10

  % Update state variables
  state.p2 = p2;
  state.p1 = p1;
end

function x1=ApproxInt(dx,x0,Ts)
  x1 = x0 + Ts*dx;
end
