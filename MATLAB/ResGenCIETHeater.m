function [r, state] = ResGenCIETHeaterDyn_2_7(z,state,params,Ts)
% RESGENCIETHEATERDYN_2_7 Sequential residual generator for model 'CIETheater'
% Causality: der
%
% Structurally sensitive to faults: fH
%
% Example of basic usage:
%   Let z be the observations and N the number of samples, then
%   the residual generator can be simulated by:
%
%   for k=1:N
%     [r(k), state] = ResGenCIETHeaterDyn_2_7( z(k,:), state, params, 1/fs );
%   end
%   where state is a structure with the state of the residual generator.
%   The state has fieldnames: TSH, TFH

% File generated 01-Jul-2019 15:54:24

  % Parameters
  hSH = params.hSH;
  ASH = params.ASH;
  MFH = params.MFH;
  cpFH = params.cpFH;
  cpDow = params.cpDow;
  MSH = params.MSH;
  cpSH = params.cpSH;
  Ainfty = params.Ainfty;
  hinfty = params.hinfty;

  % Known variables
  uH = z(1);
  y9 = z(10);
  y10 = z(11);
  y11 = z(12);
  y12 = z(13);
  y13 = z(14);
  y14 = z(15);
  y15 = z(16);
  y16 = z(17);
  y17 = z(18);
  y18 = z(19);
  y19 = z(20);
  y20 = z(21);
  y21 = z(22);
  y22 = z(23);

  % Initialize state variables
  TSH = state.TSH;
  TFH = state.TFH;

  % Residual generator body
  FM40 = y22; % e23
  mdot = FM40; % e24
  AT02 = y21; % e22
  Tinfty = AT02; % e25
  ST10 = y20; % e21
  ST11 = y19; % e20
  ST13 = y18; % e19
  ST12SW = y17; % e18
  ST12SE = y16; % e17
  ST12N = y15; % e16
  ST14S = y14; % e15
  ST14N = y13; % e14
  ST14W = y12; % e13
  ST14E = y11; % e12
  TSH = ST10*(1.0/5.0)+ST11*(1.0/5.0)+ST13*(1.0/5.0)+ST14E*(1.0/2.0e1)+ST12N*(1.0/1.5e1)+ST14N*(1.0/2.0e1)+ST14S*(1.0/2.0e1)+ST14W*(1.0/2.0e1)+ST12SE*(1.0/1.5e1)+ST12SW*(1.0/1.5e1); % e28
  dTSH = ApproxDiff(TSH,state.TSH,Ts);  % e34
  Qinfty = Ainfty*hinfty*(TSH-Tinfty); % e32
  BT11 = y10; % e11
  WT10 = y9; % e10
  TinH = BT11*(1.0/2.0)+WT10*(1.0/2.0); % e26
  TFH = (ASH*TSH*hSH+TinH*cpDow*mdot*2.0)/(ASH*hSH+cpDow*mdot*2.0); % e29
  QH = (cpDow*mdot*(ASH*TSH*hSH-ASH*TinH*hSH)*2.0)/(ASH*hSH+cpDow*mdot*2.0); % e30
  ToutH = (ASH*TSH*hSH*2.0-ASH*TinH*hSH+TinH*cpDow*mdot*2.0)/(ASH*hSH+cpDow*mdot*2.0); % e31
  dTFH = ApproxDiff(TFH,state.TFH,Ts);  % e35
  PH = QH+Qinfty+MFH*cpFH*dTFH+MSH*cpSH*dTSH; % e33
   
  r=-PH+uH; % e1

  % Update state variables
  state.TSH = TSH;
  state.TFH = TFH;
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
