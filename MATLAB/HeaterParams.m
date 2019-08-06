function params = HeaterParams()
%% Heater parameter values
% Define specific heat capacities
cpS = 500; %J/kgK 304 SS
cpF = 1785.9; %J/kgK 1518 + 2.82*T [deg C] Dowtherm A taking rough average
            % temp of 95 degrees Celsius
% Define fluid density
rho = 999.1; %kg/m3 (Dowtherm A) taking rough average temp of 95 degrees
             % Celsius and saturated liquid properties(from Dowtherm A Heat
             % Transfer Fluid Product Technical Data, Dow Chemical Company)

% Heater mass and geometry
mS = 5.9832; %kg, Outer shell mass multiplied by fraction in control
                  % volume
mT = (2.047 + 0.430)*0.741; %kg, Inner tube mass (new) + tape, multiplied
                            % by effective fraction in control volume
A = 2*pi*(1.5/2)*62.992*0.0254^2; % m2, Outer shell (inside) SA, 2 * pi * r * 
                              % L, then convert from inches to meters
Ainfty = 2*pi*(1.575/2)*62.992*0.0254^2; % m2, Outer shell (outside) SA, 2 * pi * r * 
                              % L, then convert from inches to meters (from
                              % CIET-ENGR-DRAW-042_Heater outer tube)

% Fluid volume, mass and geometry
%mdot = 0.18; %kg/s, mass flow rate
V_S = pi*(1.5/2)^2*62.992*0.0254^3; % m3, Outer shell volume (with no inner tube)
V_T = ((255.8 + 56.1)/100^3)*0.741; %m3, Inner tube volume (new) tube + tape,
                                    % multipled by effective fraction in 
                                    % control volume
mF = (V_S - V_T)*rho; % kg
mI = mT + mF; % kg, mass of tube plus mass of fluid to get total inner mass

% Compute weighted average specific heat capacity
cpFav = (cpS*mT + cpF*mF)/mI; % J/kgK

% Heat transfer coefficient (guess)
h = 469; % Improved Heat Transfer and Volume Scaling through Novel Heater 
         % Design (Lukas, Kendrick, and Peterson)
         
% Ambient losses
hinfty = 45; % [W/m2K] convection heat transfer coefficient air-to-pipe (from Dane's calculations in UCBTH-CIET-Nodalization - Dane de Wet Model - Final_20190311)
         
params.hSH = h;
params.ASH = A;
params.MFH = mI;
params.cpFH = cpFav;
params.MSH = mS;
params.cpSH = cpS;
params.Ainfty = Ainfty;
params.hinfty = hinfty;
params.cpDow = cpF;
params.MDow = (V_S - V_T)*rho;