%% Start
clear
close all

%% Settings
measurementInterval = 1;                % Number of timesteps over which the measurement readings will not be updated and the residual generator must predict.
deltat = measurementInterval*0.1;       % Size of timestep between readings (in seconds)
feedbackInterval = 5;                  % Number of timesteps before feedback values are reset with measurement data

normalize = "true";     % Only enabled if [normalize = "true";]
feedback  = "true";     % Only enabled if [feedback  = "true";]

%% Define Parameter Values
heaterParams = HeaterParams();
CTAHparams = CTAHParams();
hotLegParams = HotLegTCParams();
DRACSparams = DRACSParams();

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
            for i = 1:feedbackInterval
                % Read values from nodes and define as variables
                [numeric_control_actions,   date_time_numeric]  = readValue(        uaClient, NumericControlNode); 
                [ciet_data,                 date_time_ciet]     = readValue(        uaClient, CIETDataNode);
                 CIETDataVals                                   = CIETData(         ciet_data);
                 NumericControlsVals                            = NumericControls(  numeric_control_actions);

                % Assign States
                if i == 1
                    [CIETHeaterState,       heaterState_fb]     = CIETHeaterStates( NumericControlsVals, CIETDataVals);
                    [CTAHState,             CTAHState_fb]       = CTAHStates(       NumericControlsVals, CIETDataVals);
                    [HotLegState,           heaterOutState_fb]  = HotLegStates(     CIETDataVals);
                    [DRACSState,            DRACSOutState_fb]   = DRACSStates(      CIETDataVals); 
                else
                    [CIETHeaterState,       ~]                  = CIETHeaterStates( NumericControlsVals, CIETDataVals);
                    [CTAHState,             ~]                  = CTAHStates(       NumericControlsVals, CIETDataVals);
                    [HotLegState,           ~]                  = HotLegStates(     CIETDataVals);
                    [DRACSState,            ~]                  = DRACSStates(      CIETDataVals);
                end

                % Calculate residuals
                [rHeater,                   heaterState_fb]     = ResGenCIETHeater( CIETHeaterState, heaterState_fb,       heaterParams,   deltat);
                [rCTAH,                     CTAHState_fb]       = ResGenCTAH(       CTAHState,       CTAHState_fb,         CTAHparams,     deltat);
                %[rCTAHIn,                   CTAHState_fb]       = ResGenT1(         HotLegState,     CTAHState_fb,       hotLegParams,   deltat);
                [rHeaterOut,                heaterOutState_fb]  = ResGenT1(         HotLegState,     heaterOutState_fb,    hotLegParams,   deltat);
                %[rTCHXIn,                   TCHXInState_fb]     = ResGenT2(         DRACSState,      TCHXInState_fb,       DRACSparams,    deltat);
                [rDRACSOut,                 DRACSOutState_fb]   = ResGenT2(         DRACSState,      DRACSOutState_fb,     DRACSparams,    deltat);

                % Write values to server
                writeValue(uaClient,HeaterResGenNode,rHeater)
                writeValue(uaClient,CTAHResGenNode,rCTAH)
                %writeValue(uaClient,CTAHInResGenNode,rCTAHIn)
                writeValue(uaClient,HeaterOutResGenNode,rHeaterOut)
                %writeValue(uaClient,TCHXInResGenNode,rTCHXIn)
                writeValue(uaClient,DRACSOutResGenNode,rDRACSOut)
                pause(deltat)
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