function [r, state] = ResGen3(z,state,params,Ts)
% RESGEN3 Sequential residual generator for model 'Three tank system'
% Causality: mixed
%
% Structurally sensitive to faults: fV2, fV3, fT1, fT2, fT3
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = ResGen3( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: p3, p2, p1

% File generated 24-Apr-2019 20:17:23

  % Parameters
  Rv2 = params.Rv2;
  Rv3 = params.Rv3;
  CT1 = params.CT1;
  CT2 = params.CT2;
  CT3 = params.CT3;

  % Known variables
  y1 = z(1);
  y2 = z(2);
  y3 = z(3);

  % Initialize state variables
  p3 = state.p3;
  p2 = state.p2;
  p1 = state.p1;

  % Residual generator body
  q2 = y2; % e8
  q0 = y3; % e9
  q3 = p3/Rv3; % e3
  dp3 = (q2-q3)/CT3; % e6
  p1 = y1; % e7
  dp1 = ApproxDiff(p1,state.p1,Ts);  % e10
  q1 = q0-CT1*dp1; % e4
  dp2 = (q1-q2)/CT2; % e5
   
  r=q2-(p2-p3)/Rv2; % e2

  % Update integrator variables
  p3 = ApproxInt(dp3,state.p3,Ts); % e12
  p2 = ApproxInt(dp2,state.p2,Ts); % e11

  % Update state variables
  state.p3 = p3;
  state.p2 = p2;
  state.p1 = p1;
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
