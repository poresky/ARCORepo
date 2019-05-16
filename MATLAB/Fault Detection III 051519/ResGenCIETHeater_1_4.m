function [r, state] = ResGenCIETHeater_1_4(z,state,params,Ts)
% RESGENCIETHEATER_1_4 Sequential residual generator for model 'CIETheater'
% Causality: mixed
%
% Structurally sensitive to faults: fH
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = ResGenCIETHeater_1_4( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: TFH, TSH

% File generated 15-May-2019 10:21:13

  % Parameters
  hSH = params.hSH;
  ASH = params.ASH;
  MFH = params.MFH;
  cpFH = params.cpFH;
  MSH = params.MSH;
  cpSH = params.cpSH;

  % Known variables
  uH = z(1);
  y11 = z(12);
  y12 = z(13);
  y13 = z(14);

  % Initialize state variables
  TFH = state.TFH;
  TSH = state.TSH;

  % Residual generator body
  ST14N = y13; % e13
  ST14W = y12; % e12
  ST14E = y11; % e11
  TSH = ST14E*(1.0/3.0)+ST14N*(1.0/3.0)+ST14W*(1.0/3.0); % e22
  dTSH = ApproxDiff(TSH,state.TSH,Ts);  % e20
  dTFH = -(ASH*hSH*(TFH-TSH))/(MFH*cpFH); % e16
  PH = MSH*cpSH*(dTSH-(ASH*hSH*(TFH-TSH))/(MSH*cpSH)); % e17
   
  r=-PH+uH; % e15

  % Update integrator variables
  TFH = ApproxInt(dTFH,state.TFH,Ts); % e19

  % Update state variables
  state.TFH = TFH;
  state.TSH = TSH;
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
