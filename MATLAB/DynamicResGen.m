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
    'AT02','dTFC','TinC','TFC','TSC','TFC','dTSC','TSC','TinftyC',...
    'FM40','hinftyC','tauC','omegaC','dTFCbar','TFCbar'};
modelDef.f = {'fC'};
modelDef.z = {'uC','y1','y2','y3','y4','y5','y6'};
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
    y5==AT01,y6==AT02,uC==omegaC,hinftyC==omegaCfxn*omegaC + 97.4174 + fC,... %e5,e6,e7,e8
    tauC==VFC/FM40,TFC==(BT41+WT40)/2,TinC==(BT43+WT42)/2,... %e9,e10,e11
    TinftyC==(AT01+AT02)/2,... %e12
    dTFC==(hFC*AFC)/(MFC*cpFC)*(TSC-TFC),... %e13
    dTSC==(hFC*AFC)/(MSC*cpSC)*(TFC-TSC)+(hinftyC*AinftyC)/(MSC*cpSC)*(TinftyC-TSC),... %e14
    dTFCbar==(1/tauC)*(TinC-TFC),... %e15
    TFCbar==(TinC+TFC)/2,... %e16
    DiffConstraint('dTFC','TFC'),... %e17
    DiffConstraint('dTSC','TSC'),... %e18
    DiffConstraint('dTFCbar','TFCbar')...
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
modelDef.x = {'BT63','WT62','WT64','AT01','AT02',...
    'BT65','dT1','T1','dT2','T2','Tav',...
    'Tinfty'};
modelDef.f = {'fT1','fT2'};
modelDef.z = {'y1','y2','y3','y4','y5','y6'};
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
    y3==BT65,y4==WT64,y5==AT01,y6==AT02,... %e3,e4,e5,e6
    T1==(WT62+BT63)/2,... %e7
    Tinfty==(AT01+AT02)/2,... %e8
    T2==(WT64+BT65)/2,... %e9
    dT1==1/(R*cp*M*Ltc)*(Tinfty-T1)+fT1,... %e10
    dT2==1/(R*cp*M*Ltc)*(Tinfty-T2)+fT2,... %e14
    DiffConstraint('dT1','T1'),... %e12
    DiffConstraint('dT2','T2'),... %e13
    T2==T1+(h*A*R)*(Tinfty-Tav),... %e14
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
modelDef.x = {'BT12','WT13','BT43','WT42','AT01','AT02',...
    'dT1','T1','dT2','T2','Tav',...
    'Tinfty'};
modelDef.f = {'fT1','fT2'};
modelDef.z = {'y1','y2','y3','y4','y5','y6'};
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
    y3==BT43,y4==WT42,y5==AT01,y6==AT02,... %e3,e4,e5,e6
    T1==(WT13+BT12)/2,... %e7
    Tinfty==(AT01+AT02)/2,... %e8
    T2==(WT42+BT43)/2,... %e9
    dT1==1/(R*cp*M*Ltc)*(Tinfty-T1)+fT1,... %e10
    dT2==1/(R*cp*M*Ltc)*(Tinfty-T2)+fT2,... %e11
    DiffConstraint('dT1','T1'),... %e12
    DiffConstraint('dT2','T2'),... %e13
    T2==T1+(h*A*R)*(Tinfty-Tav),... %e14
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
CTAHTInResGenNode = findNodeByName(uaClient.Namespace,'CTAH Temp In Res Gen');
HeaterTOutResGenNode = findNodeByName(uaClient.Namespace,'Heater Temp Out Res Gen');
DRACSTOutResGenNode = findNodeByName(uaClient.Namespace,'DHX Temp Out Res Gen');
TCHXTInResGenNode = findNodeByName(uaClient.Namespace,'TCHX Temp In Res Gen');

%% Run Residual Generators
[matlab_booleans, date_time_matlab] = readValue(uaClient,MATLABBooleansNode);
matlab_active = matlab_booleans(1); 
operator_actions = matlab_booleans(2);
resgen = matlab_booleans(3);
if matlab_active == true
    while matlab_active == true
    if resgen == true
        t = 10; % 10 timesteps
        HeaterStates.z = zeros(length(HeaterModel.z),1);
        CTAHStates.z = zeros(length(CTAHModel.z),1);
        HotLegStates.z = zeros(length(HotLegModel.z),1);
        DRACSStates.z = zeros(length(DRACSModel.z),1);
        for i = 1:10
            % Read values from nodes and define as variables
            [numeric_control_actions, date_time_numeric] = readValue(uaClient, NumericControlNode); 
            ctah_freq = numeric_control_actions(5);
            desired_power = numeric_control_actions(8);
            [ciet_data, date_time_ciet] = readValue(uaClient, CIETDataNode);
            CX101 = ciet_data(4);
            CX102 = ciet_data(5);
            CX103 = ciet_data(6);
            CX104 = ciet_data(7);
            CX111 = ciet_data(8);
            CX112 = ciet_data(9);
            CX113 = ciet_data(10);
            CX114 = ciet_data(11);
            WT10 = ciet_data(2);
            BT11 = ciet_data(3);
            BT12 = ciet_data(12);
            WT13 = ciet_data(13);
            FM40 = ciet_data(56);
            ST14E = ciet_data(49);
            ST14W = ciet_data(51);
            ST14N = ciet_data(48);
            WT40 = ciet_data(30);
            BT41 = ciet_data(31);
            WT42 = ciet_data(32);
            BT43 = ciet_data(33);
            WT62 = ciet_data(36);
            BT63 = ciet_data(37);
            WT64 = ciet_data(38);
            BT65 = ciet_data(39);
            AT01 = ciet_data(52);
            AT02 = ciet_data(53);
            HeaterStates.z(1) = desired_power;
            HeaterStates.z(2) = CX101;
            HeaterStates.z(3) = CX103;
            HeaterStates.z(4) = CX104;
            HeaterStates.z(5) = CX111;
            HeaterStates.z(6) = CX112;
            HeaterStates.z(7) = CX113;
            HeaterStates.z(8) = CX114;
            HeaterStates.z(9) = CX114;
            HeaterStates.z(10) = WT10;
            HeaterStates.z(11) = BT11;
            HeaterStates.z(12) = ST14E;
            HeaterStates.z(13) = ST14W;
            HeaterStates.z(14) = ST14N;
            HeaterStates.z(15) = FM40;
            CTAHStates.z(1) = ctah_freq;
            CTAHStates.z(2) = WT40;
            CTAHStates.z(3) = BT41;
            CTAHStates.z(4) = WT42;
            CTAHStates.z(5) = BT43;
            CTAHStates.z(6) = AT01;
            CTAHStates.z(7) = AT02;
            HotLegStates.z(1) = BT12;
            HotLegStates.z(2) = WT13;
            HotLegStates.z(3) = BT43;
            HotLegStates.z(4) = WT42;
            HotLegStates.z(5) = AT01;
            HotLegStates.z(6) = AT02;
            DRACSStates.z(1) = BT63;
            DRACSStates.z(2) = WT62;
            DRACSStates.z(3) = BT65;
            DRACSStates.z(4) = WT64;
            DRACSStates.z(5) = AT01;
            DRACSStates.z(6) = AT02;
            % Create empty states
%             if i==1
%                 HeaterState1.TFH = (CX101+CX102+CX103+CX104+CX111+CX112+CX113+CX114)/8;
%                 HeaterState1.TSH = (ST14E+ST14W+ST14N)/3;
%                 CTAHState1.TFC = (BT41+WT40)/2;
%                 CTAHState1.TSC = (WT42+WT40)/2;
%                 TCHXTInState1.T2 = (WT64+BT65)/2;
%                 DRACSTOutState1.T1 = (WT62+BT63)/2;
%                 HeaterTOutState1.T2 = (WT42+BT43)/2;
%                 CTAHInState1.T1 = (BT12+WT13)/2;
%             else
%             end
%             [rHeater,HeaterState1] = ResGenCIETHeater_1_6(HeaterStates.z, HeaterState1, HeaterModel.parameter_values, 0.1);
%             [rCTAH,CTAHState1] = ResGenCTAH_1_5(CTAHStates.z, CTAHState1, CTAHModel.parameter_values, 0.1);
%             [rCTAHTIn,CTAHTInState1] = ResGenCTAHIn_2_1(HotLegStates.z, CTAHInState1, HotLegModel.parameter_values, 0.1);
%             [rTCHXTIn,TCHXTInState1] = ResGenTCHXIn_1_1(HotLegStates.z, TCHXTInState1, HotLegModel.parameter_values, 0.1);
%             [rDRACSTOut,DRACSTOutState1] = ResGenDRACSOut_2_1(DRACSStates.z, DRACSTOutState1, DRACSModel.parameter_values, 0.1);
%             [rHeaterTOut,HeaterTOutState1] = ResGenHeaterOut_1_1(DRACSStates.z, HeaterTOutState1, DRACSModel.parameter_values, 0.1);
            HeaterState1.TFH = (CX101+CX102+CX103+CX104+CX111+CX112+CX113+CX114)/8;
            HeaterState1.TSH = (ST14E+ST14W+ST14N)/3;
            CTAHState1.TFC = (BT41+WT40)/2;
            CTAHState1.TSC = (WT42+WT40)/2;
            TCHXTInState1.T2 = (WT64+BT65)/2;
            DRACSTOutState1.T1 = (WT62+BT63)/2;
            HeaterTOutState1.T2 = (WT42+BT43)/2;
            CTAHInState1.T1 = (BT12+WT13)/2;
            rHeater = ResGenCIETHeater_1_6(HeaterStates.z, HeaterState1, HeaterModel.parameter_values, 0.1);
            rCTAH = ResGenCTAH_1_5(CTAHStates.z, CTAHState1, CTAHModel.parameter_values, 0.1);
            rCTAHTIn = ResGenCTAHIn_2_1(HotLegStates.z, CTAHInState1, HotLegModel.parameter_values, 0.1);
            rTCHXTIn = ResGenTCHXIn_1_1(HotLegStates.z, TCHXTInState1, HotLegModel.parameter_values, 0.1);
            rDRACSTOut = ResGenDRACSOut_2_1(DRACSStates.z, DRACSTOutState1, DRACSModel.parameter_values, 0.1);
            rHeaterTOut = ResGenHeaterOut_1_1(DRACSStates.z, HeaterTOutState1, DRACSModel.parameter_values, 0.1);
            writeValue(uaClient,HeaterResGenNode,rHeater)
            writeValue(uaClient,CTAHResGenNode,rCTAH)
            writeValue(uaClient,CTAHTInResGenNode,rCTAHTIn)
            writeValue(uaClient,TCHXTInResGenNode,rTCHXTIn)
            writeValue(uaClient,DRACSTOutResGenNode,rDRACSTOut)
            writeValue(uaClient,HeaterTOutResGenNode,rHeaterTOut)
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
        