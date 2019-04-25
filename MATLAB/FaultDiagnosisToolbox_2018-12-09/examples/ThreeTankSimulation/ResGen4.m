function dx = ResGen4(x,z,K,params)
% RESGEN4 Observer based residual generatorfor model 'Three tank system'
%
% Structurally sensitive to faults: fV1, fT1, fT2
%
% Example of basic usage:
%   Let z and t be the observations and corresponding timestamps. Let K be the observer gain,
%   then the residual generator can be simulated by:
%
%     [~,x] = ode15s(@(ts,x) ResGen4( x, interp1(t,z,ts), K, params ), t, x0, odeset('Mass',M));
%
%   where the mass matrix M is [eye(2) zeros(2,4);zeros(4,6)]
%   The residual after integration is then r=x(:,6)

% File generated 25-Apr-2019 11:56:39


  % Parameters
  Rv1 = params.Rv1;
  CT1 = params.CT1;
  CT2 = params.CT2;

  % Known variables
  y1 = z(1);
  y2 = z(2);
  y3 = z(3);

  % Model variables
  p1 = x(1);
  p2 = x(2);
  q0 = x(3);
  q1 = x(4);
  q2 = x(5);
  r1 = x(6);

  % Algebraic equations
  g21 = -q0+y3;
  g22 = q1-(p1-p2)/Rv1;
  g23 = -q2+y2;

  % Residual equations
  gr1 = p1+r1-y1;

  % Dynamics, with feedback
  dp1 = (q0-q1)/CT1 + K(1,:)*r1;
  dp2 = (q1-q2)/CT2 + K(2,:)*r1;

  % Return value
  dx = [dp1; dp2; g21; g22; g23; gr1];
end
