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

% File generated 15-May-2019 10:30:43

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

  % Initialize state variables
  TFC = state.TFC;
  TSC = state.TSC;

  % Residual generator body
  omegaC = uC; % e6
  AT01 = y5; % e5
  TinftyC = AT01; % e11
  BT41 = y2; % e2
  WT40 = y1; % e1
  TFC = BT41*(1.0/2.0)+WT40*(1.0/2.0); % e9
  dTFC = ApproxDiff(TFC,state.TFC,Ts);  % e16
  TSC = (MFC*cpFC*(dTFC+(AFC*TFC*hFC)/(MFC*cpFC)))/(AFC*hFC); % e12
  dTSC = ApproxDiff(TSC,state.TSC,Ts);  % e17
  hinftyC = -(MSC*cpSC*(dTSC-(AFC*hFC*(TFC-TSC))/(MSC*cpSC)))/(AinftyC*(TSC-TinftyC)); % e13
   
  r=hinftyC-omegaC*omegaCfxn; % e7

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
