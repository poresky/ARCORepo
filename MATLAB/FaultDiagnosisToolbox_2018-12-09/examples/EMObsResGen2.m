function dx = EMObsResGen2(x,z,K,params)
% EMOBSRESGEN2 Observer based residual generatorfor model 'Electric motor'
%
% Structurally sensitive to faults: fR, fi, fw
%
% Example of basic usage:
%   Let z and t be the observations and corresponding timestamps. Let K be the observer gain,
%   then the residual generator can be simulated by:
%
%     [~,x] = ode15s(@(ts,x) EMObsResGen2( x, interp1(t,z,ts), K, params ), t, x0, odeset('Mass',M));
%
%   where the mass matrix M is [eye(1) zeros(1,2);zeros(2,3)]
%   The residual after integration is then r=x(:,3)

% File generated 18-Apr-2019 15:42:51


  % Parameters
  Ka = params.Ka;
  R = params.R;
  L = params.L;

  % Known variables
  V = z(1);
  yi = z(2);
  yw = z(3);
  yd = z(4);

  % Model variables
  I = x(1);
  w = x(2);
  r1 = x(3);

  % Algebraic equations
  g21 = -w+yw;

  % Residual equations
  gr1 = I+r1-yi;

  % Dynamics, with feedback
  dI = -(-V+I*R+I*Ka*w)/L + K(1,:)*r1;

  % Return value
  dx = [dI; g21; gr1];
end
