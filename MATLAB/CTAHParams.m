function params = CTAHParamsNew()

%% CTAH parameter values
% Define specific heat capacities
cpFC = 1771.8; %J/kgK 1518 + 2.82*T [deg C] Dowtherm A taking rough
                      % average temp of 90 degrees Celsius 
                      % (100 inlet, 80 outlet);
cpIC = 1006; %J/kgK air taken at a rough average of 40 degrees Celsius

% Relationship between fan frequency and air mass flow rate
CFMfxn = 0.464; % ft3/rev for FanEx heat exchanger, data from
                % CIET-MES-TS-003-01
cmsfxn = CFMfxn*0.0283168; % m3/rev
omegaCfxn = cmsfxn*1.127; %kg/rev (density of air at 30C)

MFC = 3.67*0.001*994.9; % kg (Liters to m3, kg/m3 DowA at 100C), 
                        % tube volume from data from CIET-MES-TS-003-01
             
params.omegaCfxn = omegaCfxn;
params.cpFC = cpFC;
params.cpIC = cpIC;
params.MFC = MFC;