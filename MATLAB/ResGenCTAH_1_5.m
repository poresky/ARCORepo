function [r, state] = ResGenCTAH_1_5(z,state,params,Ts)
% RESGENCTAH_1_5 Sequential residual generator for model 'CTAH'
% Causality: der
%
% Structurally sensitive to faults: fC
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = ResGenCTAH_1_5( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: TFC, TSC

% File generated 06-May-2019 14:32:15

  % Parameters
  hFC = params.hFC;
  AFC = params.AFC;
  MFC = params.MFC;
  cpFC = params.cpFC;
  MSC = params.MSC;
  cpSC = params.cpSC;
  AinftyC = params.AinftyC;
  omegaCfxn = params.omegaCfxn;

  % Known variables
  uC = z(1);
  y1 = z(2);
  y2 = z(3);
  y5 = z(6);
  y6 = z(7);

  % Initialize state variables
  TFC = state.TFC;
  TSC = state.TSC;

  % Residual generator body
  AT02 = y6; % e6
  AT01 = y5; % e5
  TinftyC = AT01*(1.0/2.0)+AT02*(1.0/2.0); % e12
  BT41 = y2; % e2
  WT40 = y1; % e1
  TFC = BT41*(1.0/2.0)+WT40*(1.0/2.0); % e10
  dTFC = ApproxDiff(TFC,state.TFC,Ts);  % e17
  TSC = (MFC*cpFC*(dTFC+(AFC*TFC*hFC)/(MFC*cpFC)))/(AFC*hFC); % e13
  dTSC = ApproxDiff(TSC,state.TSC,Ts);  % e18
  hinftyC = -(MSC*cpSC*(dTSC-(AFC*hFC*(TFC-TSC))/(MSC*cpSC)))/(AinftyC*(TSC-TinftyC)); % e14
  omegaC = hinftyC/omegaCfxn; % e8
   
  r=-omegaC+uC; % e7

  % Update state variables
  state.TFC = TFC;
  state.TSC = TSC;
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
