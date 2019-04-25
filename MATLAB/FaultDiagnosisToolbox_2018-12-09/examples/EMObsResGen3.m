function dx = EMObsResGen3(x,z,K,params)
% EMOBSRESGEN3 Observer based residual generatorfor model 'Electric motor'
%
% Structurally sensitive to faults: fR, fi, fD
%
% Example of basic usage:
%   Let z and t be the observations and corresponding timestamps. Let K be the observer gain,
%   then the residual generator can be simulated by:
%
%     [~,x] = ode15s(@(ts,x) EMObsResGen3( x, interp1(t,z,ts), K, params ), t, x0, odeset('Mass',M));
%
%   where the mass matrix M is [eye(2) zeros(2,2);zeros(2,4)]
%   The residual after integration is then r=x(:,4)

% File generated 18-Apr-2019 15:42:51


  % Parameters
  Ka = params.Ka;
  b = params.b;
  R = params.R;
  J = params.J;
  L = params.L;

  % Known variables
  V = z(1);
  yi = z(2);
  yw = z(3);
  yd = z(4);

  % Model variables
  I = x(1);
  w = x(2);
  DT = x(3);
  r1 = x(4);

  % Algebraic equations
  g21 = -DT+yd;

  % Residual equations
  gr1 = I+r1-yi;

  % Dynamics, with feedback
  dI = -(-V+I*R+I*Ka*w)/L + K(1,:)*r1;
  dw = (DT-b*w)/J + K(2,:)*r1;

  % Return value
  dx = [dI; dw; g21; gr1];
end
