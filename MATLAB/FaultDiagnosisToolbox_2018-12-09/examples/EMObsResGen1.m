function dx = EMObsResGen1(x,z,K,params)
% EMOBSRESGEN1 Observer based residual generatorfor model 'Electric motor'
%
% Structurally sensitive to faults: fw, fD
%
% Example of basic usage:
%   Let z and t be the observations and corresponding timestamps. Let K be the observer gain,
%   then the residual generator can be simulated by:
%
%     [~,x] = ode15s(@(ts,x) EMObsResGen1( x, interp1(t,z,ts), K, params ), t, x0, odeset('Mass',M));
%
%   where the mass matrix M is [eye(1) zeros(1,2);zeros(2,3)]
%   The residual after integration is then r=x(:,3)

% File generated 18-Apr-2019 15:42:50


  % Parameters
  b = params.b;
  J = params.J;

  % Known variables
  V = z(1);
  yi = z(2);
  yw = z(3);
  yd = z(4);

  % Model variables
  w = x(1);
  DT = x(2);
  r1 = x(3);

  % Algebraic equations
  g21 = -DT+yd;

  % Residual equations
  gr1 = r1+w-yw;

  % Dynamics, with feedback
  dw = (DT-b*w)/J + K(1,:)*r1;

  % Return value
  dx = [dw; g21; gr1];
end
