%% Start
clear
close all

%% Heater parameter values
% Define specific heat capacities
cpS = 500; %J/kgK 304 SS
cpF = 1800; %J/kgK 1518 + 2.82*T [deg C] Dowtherm A taking rough average
            % temp of 100 degrees Celsius
% Define fluid density
rho = 994.9; %kg/m3 (Dowtherm A) taking rough average temp of 100 degrees
             % Celsius and saturated liquid properties(from Dowtherm A Heat
             % Transfer Fluid Product Technical Data, Dow Chemical Company)

% Heater mass and geometry
mS = 5.9832; %kg, Outer shell mass multiplied by fraction in control
                  % volume
mT = (2.047 + 0.430)*0.741; %kg, Inner tube mass (new) + tape, multiplied
                            % by effective fraction in control volume
A = 2*pi*(1.5/2)*62.992*0.0254^2; % m2, Outer shell (inside) SA, 2 * pi * r * 
                              % L, then convert from inches to meters

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
         
%% Heater model
modelDef.type = 'Symbolic';
modelDef.x = {'CX101','CX102','CX103','CX104','CX111',...
    'CX112','CX113','CX114','WT10','BT11','ST14E','ST14W','ST14N','PH',...
    'FM40','dTFH','tauH','TinH','TFH','TSH','dTSH','TFHbar','dTFHbar'};
modelDef.f = {'fH','fFM40'};
modelDef.z = {'uH','y1','y2','y3','y4','y5','y6','y7','y8','y9','y10',...
    'y11','y12','y13','y14'};
modelDef.parameters = {'hSH','ASH','MFH','cpFH','MSH','cpSH','VFH'};

% Define parameter values
params.hSH = h;
params.ASH = A;
params.MFH = mF;
params.cpFH = cpF;
params.MSH = mS;
params.cpSH = cpS;
params.VFH = V_S - V_T;
modelDef.parameter_values = params;

syms(modelDef.x{:})
syms(modelDef.f{:})
syms(modelDef.z{:})
syms(modelDef.parameters{:})

modelDef.rels = {y1==CX101,y2==CX102,y3==CX103,y4==CX104,... % e1,e2,e3,e4
    y5==CX111,y6==CX112,y7==CX113,y8==CX114,... %e5,e6,e7,e8
    y9==WT10,y10==BT11,y11==ST14E,y12==ST14W,... %e9,e10,e11,e12
    y13==ST14N, y14==FM40 + fFM40,uH==PH,... %e13,e14,e15
    dTFH==(hSH*ASH)/(MFH*cpFH)*(TSH-TFH),... %e16
    dTSH==(hSH*ASH)/(MSH*cpSH)*(TFH-TSH) + PH/(MSH*cpSH) + fH,... %e17
    tauH==VFH/FM40,... %e18
    DiffConstraint('dTFH','TFH'),... %e19
    DiffConstraint('dTSH','TSH'),... %e20
    TFH==(CX101+CX102+CX103+CX104+CX111+CX112+CX113+CX114)/8,... %e21
    TSH==(ST14E+ST14W+ST14N)/3,... %e22
    TinH==(WT10+BT11)/2,... %e23
    dTFHbar==(1/tauH)*(TinH - TFH),... %e24
    TFHbar==(TinH + TFH)/2,... %e25
    DiffConstraint('dTFHbar','TFHbar')... %e26
    };
HeaterModel = DiagnosisModel(modelDef);
HeaterModel.name = 'CIETheater';

% clear temporary variables from workspace
clear( modelDef.x{:} )
clear( modelDef.f{:} )
clear( modelDef.z{:} )
clear( modelDef.parameters{:} )

clear modelDef params
%% CTAH parameter values
% Define specific heat capacities
cpS = 390; %J/kgK Copper
cpF = 1771.8; %J/kgK 1518 + 2.82*T [deg C] Dowtherm A taking rough
                      % average temp of 90 degrees Celsius 
                      % (100 inlet, 80 outlet);
% Define fluid density
rho = 994.9; %kg/m3 (Dowtherm A) taking rough average temp of 100 degrees
             % Celsius and saturated liquid properties(from Dowtherm A Heat
             % Transfer Fluid Product Technical Data, Dow Chemical Company)
rho_S = 8960; %kg/m3 (Copper) 

% CTAH mass and geometry
iD = 0.466*0.0254; % inner diameter of piping, meters
oD = 0.5*0.0254; % outer diameter of piping, meters
iA = 0.17055*0.0254^2; % flow area, square meters
iL = 373.8*0.0254; % flow length, meters
iV = iA*iA; % area*length, cubic meters
iC = 2*pi*(iD/2); % inner circumference, 2*pi*d/2, meters
iSA = iC*iL; % inner surface area
sV = pi*((oD - iD)/2)^2*iL; % solid volume, pi*r^2*L
oC = 2*pi*(oD/2); % outer circumferece, 2*pi*od/s, meters
oSA = oC*iL; % outer surface area

% Heat transfer coefficient (guess)
hF = 292.15; % W/m2K, from Dane's notes and studies, calibrated at
             % 8kW power from 80-100 deg C

%% CTAH model
modelDef.type = 'Symbolic';
modelDef.x = {'WT40','BT41','WT42','BT43','AT01',...
    'dTFC','TinC','TFC','TSC','TFC','dTSC','TSC','TinftyC',...
    'FM40','hinftyC','tauC','omegaC','dTFCbar','TFCbar'};
modelDef.f = {'fC'};
modelDef.z = {'uC','y1','y2','y3','y4','y5'};
modelDef.parameters = {'hFC','AFC','MFC','cpFC','MSC','cpSC','AinftyC',...
    'VFC','omegaCfxn'};

% Define parameter values
params.hFC = hF;
params.AFC = iSA;
params.MFC = iV*rho;
params.cpFC = cpF;
params.MSC = sV*rho_S;
params.cpSC = cpS; 
params.AinftyC = oSA;
params.VFC = iV + 0.003; % Corrected for pipe elbows (transit time) 
params.omegaCfxn = 1122.3*(0.006295784*1.225); % from Jason's paper on
                                               % Model-based Non-Linear 
                                               % PID Control of a Heat 
                                               % Exchanger
modelDef.parameter_values = params;

syms(modelDef.x{:})
syms(modelDef.f{:})
syms(modelDef.z{:})
syms(modelDef.parameters{:})

modelDef.rels = {y1==WT40,y2==BT41,y3==WT42,y4==BT43,... % e1,e2,e3,e4
    y5==AT01,uC==omegaC,hinftyC==omegaCfxn*omegaC + fC,... %e5,e6,e7
    tauC==VFC/FM40,TFC==(BT41+WT40)/2,TinC==(BT43+WT42)/2,... %e8,e9,e10
    TinftyC==AT01,... %e11
    dTFC==(hFC*AFC)/(MFC*cpFC)*(TSC-TFC),... %e12
    dTSC==(hFC*AFC)/(MSC*cpSC)*(TFC-TSC)+(hinftyC*AinftyC)/(MSC*cpSC)*(TinftyC-TSC),... %e13
    dTFCbar==(1/tauC)*(TinC-TFC),... %e14
    TFCbar==(TinC+TFC)/2,... %e15
    DiffConstraint('dTFC','TFC'),... %e16
    DiffConstraint('dTSC','TSC'),... %e17
    DiffConstraint('dTFCbar','TFCbar')... %e18
    };
CTAHModel = DiagnosisModel(modelDef);
CTAHModel.name = 'CTAH';

% clear temporary variables from workspace
clear( modelDef.x{:} )
clear( modelDef.f{:} )
clear( modelDef.z{:} )
clear( modelDef.parameters{:} )

clear modelDef params

%% DRACS parameter values
cp = 1630.8; % [J/kgK] Specific heat capacity of Dowtherm A 1518 + 2.82*T [deg C] Dowtherm A taking rough average
           % temp of 40 degrees Celsius
rho = 1043.8; %kg/m3 (Dowtherm A) taking rough average temp of 40 degrees
             % Celsius and saturated liquid properties(from Dowtherm A Heat
             % Transfer Fluid Product Technical Data, Dow Chemical Company)
h = 3.66*16.2/(0.0139319*2); % [W/m2K] convection heat transfer coefficient DowA-to-pipe for circular tube, const. surf. temp, laminar, fully developed (4.36*k/D) for 304L SS 1" schedule 10
h_infty = 45; % [W/m2K] convection heat transfer coefficient air-to-pipe (from Dane's calculations in UCBTH-CIET-Nodalization - Dane de Wet Model - Final_20190311)
A1 = 2*pi*0.0139319; % [m2] inside pipe surf area (2*pi*r_i for 1" schedule 10 SS pipe)
A2 = 2*pi*0.0167005; % [m2] outside pipe surf area (2*pi*r_o for 1" schedule 10 SS pipe)
M = pi*0.0139319^2*1043.8; % [kg] mass per unit pipe length between WT and BT thermocouples of Dowtherm A - pi*r^2*rho
L = 3.800475; % [m] length of pipe between DHX outlet static mixer and TCHX inlet (RELAP nodalization (CIET_Model_Parameters_Structural_Mass_Dowtherm_Inertia))
Ltc = 0.0762; %[m] length between TC points

R = 1/(h*A1) + 1/(h_infty*A2); % [K/W] effective thermal resistance DowA to air (neglecting insulation)

%% DRACS model
modelDef.type = 'Symbolic';
modelDef.x = {'BT63','WT62','WT64','AT02',...
    'BT65','dT1','T1','dT2','T2','Tav',...
    'Tinfty'};
modelDef.f = {'fT1','fT2'};
modelDef.z = {'y1','y2','y3','y4','y5'};
modelDef.parameters = {'R','h','A','cp','M','Ltc'};

% Define parameter values
params.R = R;
params.M = M;
params.h = h;
params.A = A1*L;
params.cp = cp;
params.Ltc = Ltc;
modelDef.parameter_values = params;

syms(modelDef.x{:})
syms(modelDef.f{:})
syms(modelDef.z{:})
syms(modelDef.parameters{:})

modelDef.rels = {y1==BT63,y2==WT62,... % e1,e2
    y3==BT65,y4==WT64,y5==AT02,... %e3,e4,e5
    T1==(WT62+BT63)/2,... %e6
    Tinfty==AT02,... %e7
    T2==(WT64+BT65)/2,... %e8
    dT1==1/(R*cp*M*Ltc)*(Tinfty-T1)+fT1,... %e9
    dT2==1/(R*cp*M*Ltc)*(Tinfty-T2)+fT2,... %e10
    DiffConstraint('dT1','T1'),... %e11
    DiffConstraint('dT2','T2'),... %e12
    T2==T1+(h*A*R)*(Tinfty-Tav),... %e13
    };
DRACSModel = DiagnosisModel(modelDef);
DRACSModel.name = 'DRACS TC';

%% Hot Leg parameter values
cp = 1771.8; %J/kgK 1518 + 2.82*T [deg C] Dowtherm A taking rough
                      % average temp of 90 degrees Celsius 
                      % (100 inlet, 80 outlet);
rho = 1003.2; %kg/m3 (Dowtherm A) taking rough average temp of 90 degrees
             % Celsius and saturated liquid properties(from Dowtherm A Heat
             % Transfer Fluid Product Technical Data, Dow Chemical Company)
h = 3.66*16.2/(0.0139319*2); % [W/m2K] convection heat transfer coefficient DowA-to-pipe for circular tube, const. surf. temp, laminar, fully developed (4.36*k/D) for 304L SS 1" schedule 10
h_infty = 45; % [W/m2K] convection heat transfer coefficient air-to-pipe (from Dane's calculations in UCBTH-CIET-Nodalization - Dane de Wet Model - Final_20190311)
A1 = 2*pi*0.0139319; % [m2] inside pipe surf area (2*pi*r_i for 1" schedule 10 SS pipe)
A2 = 2*pi*0.0167005; % [m2] outside pipe surf area (2*pi*r_o for 1" schedule 10 SS pipe)
M = pi*0.0139319^2*1043.8; % [kg] mass for 3" pipe length between WT and BT thermocouples of Dowtherm A - pi*r^2*rho
L = 2.0217892; % [m] length of pipe between thermocouples (heater outlet to CTAH inlet, Dane's CIET nodalization (UCBTH-CIET-Nodalization - Dane de Wet Model - Final_20190311))
Ltc = 0.0762; %[m] length between TC points

R = 1/(h*A1) + 1/(h_infty*A2); % [K/W] effective thermal resistance DowA to air (neglecting insulation)

%% Hot Leg model
modelDef.type = 'Symbolic';
modelDef.x = {'BT12','WT13','BT43','WT42','AT02',...
    'dT1','T1','dT2','T2','Tav',...
    'Tinfty'};
modelDef.f = {'fT1','fT2'};
modelDef.z = {'y1','y2','y3','y4','y5'};
modelDef.parameters = {'R','h','A','cp','M','Ltc'};

% Define parameter values
params.R = R;
params.M = M;
params.h = h;
params.A = A1*L;
params.cp = cp;
params.Ltc = Ltc;
modelDef.parameter_values = params;

syms(modelDef.x{:})
syms(modelDef.f{:})
syms(modelDef.z{:})
syms(modelDef.parameters{:})

modelDef.rels = {y1==BT12,y2==WT13,... % e1,e2
    y3==BT43,y4==WT42,y5==AT02,... %e3,e4,e5
    T1==(WT13+BT12)/2,... %e6
    Tinfty==AT02,... %e7
    T2==(WT42+BT43)/2,... %e8
    dT1==1/(R*cp*M*Ltc)*(Tinfty-T1)+fT1,... %e9
    dT2==1/(R*cp*M*Ltc)*(Tinfty-T2)+fT2,... %e10
    DiffConstraint('dT1','T1'),... %e11
    DiffConstraint('dT2','T2'),... %e12
    T2==T1+(h*A*R)*(Tinfty-Tav),... %e13
    };
HotLegModel = DiagnosisModel(modelDef);
HotLegModel.name = 'HotLeg';
%% Define client and connect to the Main Server.
uaClient = opcua('192.168.1.3',49581);
connect(uaClient)

%% Define nodes from LabVIEW in MATLAB.
MATLABBooleansNode = findNodeByName(uaClient.Namespace,'MATLAB Booleans');
NumericControlNode = findNodeByName(uaClient.Namespace,'Numeric Control Actions');
CIETDataNode = findNodeByName(uaClient.Namespace,'Result CIET Data');

%% Define residual generator nodes in MATLAB
% The output of this is  eventually written to this node to be displayed 
% in LabVIEW.
HeaterResGenNode = findNodeByName(uaClient.Namespace,'Heater Res Gen');
CTAHResGenNode = findNodeByName(uaClient.Namespace,'CTAH Res Gen');
CTAHInResGenNode = findNodeByName(uaClient.Namespace,'CTAH Temp In Res Gen');
HeaterOutResGenNode = findNodeByName(uaClient.Namespace,'Heater Temp Out Res Gen');
DRACSOutResGenNode = findNodeByName(uaClient.Namespace,'DHX Temp Out Res Gen');
TCHXInResGenNode = findNodeByName(uaClient.Namespace,'TCHX Temp In Res Gen');

%% Run Residual Generators
[matlab_booleans, date_time_matlab] = readValue(uaClient,MATLABBooleansNode);
matlab_active = matlab_booleans(1); 
operator_actions = matlab_booleans(2);
resgen = matlab_booleans(3);
if matlab_active == true
    while matlab_active == true
    if resgen == true
        t = 10; % 10 timesteps
        for i = 1:10
            % Read values from nodes and define as variables
            [numeric_control_actions, date_time_numeric] = readValue(uaClient, NumericControlNode); 
            [ciet_data, date_time_ciet] = readValue(uaClient, CIETDataNode);
            CIETDataVals = CIETData(ciet_data);
            NumericControlsVals = NumericControls(numeric_control_actions);
            % Assign states
            [CIETHeaterStatesVals.z,HeaterState1] = CIETHeaterStates(NumericControlsVals,CIETDataVals);
            [CTAHStatesVals.z,CTAHState1] = CTAHStates(NumericControlsVals,CIETDataVals);
            [HotLegStatesVals.z,HeaterOutState1,CTAHInState1] = HotLegStates(CIETDataVals);
            [DRACSStatesVals.z,DRACSOutState1,TCHXInState1] = DRACSStates(CIETDataVals);
            % Calculate residuals
            rHeater = ResGenCIETHeater_1_4(CIETHeaterStatesVals.z, HeaterState1, HeaterModel.parameter_values, 0.1);
            rCTAH = ResGenCTAH_1_5(CTAHStatesVals.z, CTAHState1, CTAHModel.parameter_values, 0.1);
            rCTAHIn = ResGenCTAHIn_1_1(HotLegStatesVals.z, CTAHInState1, HotLegModel.parameter_values, 0.1);
            rHeaterOut = ResGenHeaterOut_2_1(HotLegStatesVals.z, HeaterOutState1, HotLegModel.parameter_values, 0.1);
            rTCHXIn = ResGenTCHXIn_2_1(DRACSStatesVals.z, TCHXInState1, DRACSModel.parameter_values, 0.1);
            rDRACSOut = ResGenDRACSOut_1_1(DRACSStatesVals.z, DRACSOutState1, DRACSModel.parameter_values, 0.1);
            % Write values to server
            writeValue(uaClient,HeaterResGenNode,rHeater)
            writeValue(uaClient,CTAHResGenNode,rCTAH)
            writeValue(uaClient,CTAHInResGenNode,rCTAHIn)
            writeValue(uaClient,HeaterOutResGenNode,rHeaterOut)
            writeValue(uaClient,TCHXInResGenNode,rTCHXIn)
            writeValue(uaClient,DRACSOutResGenNode,rDRACSOut)
            pause(.1)
        end
        % Run residual generator
    else
        disp('Fault diagnostics not active')
    end
    [matlab_booleans, date_time_matlab] = readValue(uaClient,MATLABBooleansNode);
    matlab_active = matlab_booleans(1); 
    operator_actions = matlab_booleans(2);
    resgen = matlab_booleans(3);
    end
else
    disp('MATLAB is not active')
end
disp('MATLAB is no longer active')