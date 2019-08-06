function params = DRACSParams()

%% Define params
cp = 1602.6; % [J/kgK] Specific heat capacity of Dowtherm A 1518 + 2.82*T [deg C] Dowtherm A taking rough average
           % temp of 30 degrees Celsius
rho = 1051.7; %kg/m3 (Dowtherm A) taking rough average temp of 30 degrees
             % Celsius and saturated liquid properties(from Dowtherm A Heat
             % Transfer Fluid Product Technical Data, Dow Chemical Company)
k_Dow = 0.1371; %W\mk thermal conductivity for Dowtherm A at avg temp of 30C from Dowtherm A Heat
             % Transfer Fluid Product Technical Data, Dow Chemical Company
h = 3.66*k_Dow/(0.0139319*2); % [W/m2K] convection heat transfer coefficient DowA-to-pipe for circular tube, const. surf. temp, laminar, fully developed (4.36*k/D) for 304L SS 1" schedule 10
h_infty = 45; % [W/m2K] convection heat transfer coefficient air-to-pipe (from Dane's calculations in UCBTH-CIET-Nodalization - Dane de Wet Model - Final_20190311)
k_p = 16.2; % [W\mK] conduction heat transfer coefficient pipe 304 SS
d_p = 0.0167995 - 0.0139319; % [m] pipe wall thickness (r_o - r_i for 1" schedule 10 SS pipe)
k_i = 0.04; % [W\mK] conduction heat transfer coefficient insulation (from product sheet for fiberglass insulation, Dane email)
d_i = 0.0762/2; % [m] 1.5" to cm insulation wall thickness (Dane measurement 6-26-19)
A1 = 2*pi*0.0139319; % [m2] inside pipe surf area (2*pi*r_i for 1" schedule 10 SS pipe)
A2 = 2*pi*0.0167005; % [m2] outside pipe surf area (2*pi*r_o for 1" schedule 10 SS pipe)
A3 = 2*pi*(d_i + 0.0167005); % [m2] outside insulation surf. area
Ltc = 0.0762; %[m] length between TC points
M = pi*0.0139319^2*rho*Ltc; % [kg/m] mass for 3" pipe length between WT and BT thermocouples of Dowtherm A - pi*r^2*rho

R = 1/(h*A1) + d_p/(k_p*A1) + d_i/(k_i*A2) + 1/(h_infty*A3); % [K/W] effective thermal resistance DowA to air (neglecting insulation)

% Define parameter values
params.R = R;
params.M = M;
params.cp = cp;