function [r, state] = ResGenCTAHDyn_1_8(z,state,params,Ts)
% RESGENCTAHDYN_1_8 Sequential residual generator for model 'CTAH'
% Causality: der
%
% Structurally sensitive to faults: fC
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = ResGenCTAHDyn_1_8( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: TIC, TFC

% File generated 02-Jul-2019 09:26:11

  % Parameters
  omegaCfxn = params.omegaCfxn;
  cpFC = params.cpFC;
  cpIC = params.cpIC;
  MFC = params.MFC;

  % Known variables
  uC = z(1);
  y1 = z(2);
  y2 = z(3);
  y3 = z(4);
  y4 = z(5);
  y5 = z(6);
  y6 = z(7);
  y7 = z(8);

  % Initialize state variables
  TIC = state.TIC;
  TFC = state.TFC;

  % Residual generator body
  FM40 = y7; % e7
  mdotFC = FM40; % e10
  AT02 = y6; % e6
  TInIC = AT02; % e14
  AT01 = y5; % e5
  TOutIC = AT01; % e13
  TIC = TInIC*(1.0/2.0)+TOutIC*(1.0/2.0); % e15
  dTIC = ApproxDiff(TIC,state.TIC,Ts);  % e20
  BT43 = y4; % e4
  WT42 = y3; % e3
  TInFC = BT43*(1.0/2.0)+WT42*(1.0/2.0); % e12
  BT41 = y2; % e2
  WT40 = y1; % e1
  TOutFC = BT41*(1.0/2.0)+WT40*(1.0/2.0); % e11
  TFC = TInFC*(1.0/2.0)+TOutFC*(1.0/2.0); % e16
  dTFC = ApproxDiff(TFC,state.TFC,Ts);  % e19
  PC = MFC*cpFC*dTFC+cpFC*mdotFC*(TInFC-TOutFC); % e17
  mdotIC = PC/(-TInIC*cpIC+TOutIC*cpIC+cpIC*dTIC); % e18
  omegaC = mdotIC/omegaCfxn; % e9
   
  r=-omegaC+uC; % e8

  % Update state variables
  state.TIC = TIC;
  state.TFC = TFC;
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
