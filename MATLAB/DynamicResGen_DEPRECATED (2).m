%% Start
clear
close all

%% Settings
measurementInterval = 1;                % Number of timesteps over which the measurement readings will not be updated and the residual generator must predict.
deltat = measurementInterval*0.1;       % Size of timestep between readings (in seconds)
feedbackInterval = 10;                  % Number of timesteps before feedback values are reset with measurement data

normalize = "true";     % Only enabled if [normalize = "true";]
feedback  = "true";     % Only enabled if [feedback  = "true";]
LPfilter  = "true";     % Used to enable or disable the Low Pass Filter
LPfilter_Alpha = [0.25, 0.25, 0.25, 0.25, 0.25, 0.25];     % This is a multiplicative constant used for tuning the Low Pass Filter

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

normalize = "true";

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
                    [CTAHInState,           CTAHInState_fb]     = HotLegStates(     CIETDataVals);  %CTAHInState_fb = HotLegStates1.T2
                    [HotLegState,           heaterOutState_fb]  = HotLegStates(     CIETDataVals);  %heaterOutState_fb = HotLegStates1.T1
                    [TCHXInState,           TCHXInState_fb]     = DRACSStates(      CIETDATAVals);  %TCHXInState_fb = DRACSStates1.T1
                    [DRACSState,            DRACSOutState_fb]   = DRACSStates(      CIETDataVals);  %DRACSOutState_fb = DRACSStates.T2
                    
                    %CTAHState and CTAHInState are identical and are a
                    %structure which describes the entire hot leg. It is
                    %easier to think about how to work with them if they
                    %are treated like seperate objects though. The same
                    %thing applies for TCHXInState and DRACSState.
                    
                    %CTAHInState_fb and heaterOutState_fb also contain
                    %identical information when they are returned from the
                    %HotLegStates function. They take on different values
                    %as time progresses though as they are used differently
                    %in the residual generator. The same concept applies
                    %for TCHXInState_fb and DRACSOutState_fb.
                    
                else
                    [CIETHeaterState,       ~]                  = CIETHeaterStates( NumericControlsVals, CIETDataVals);
                    [CTAHState,             ~]                  = CTAHStates(       NumericControlsVals, CIETDataVals);
                    [CTAHInState,           ~]                  = HotLegStates(     CIETDataVals);
                    [HotLegState,           ~]                  = HotLegStates(     CIETDataVals);
                    [TCHXInState,           ~]                  = DRACSStates(      CIETDATAVals);
                    [DRACSState,            ~]                  = DRACSStates(      CIETDataVals);
                end
                
                % Calculate residuals
                [rHeater,                   heaterState_fb]     = ResGenCIETHeater( CIETHeaterState, heaterState_fb,       heaterParams,   deltat);
                [rCTAH,                     CTAHState_fb]       = ResGenCTAH(       CTAHState,       CTAHState_fb,         CTAHparams,     deltat);
                [rCTAHIn,                   CTAHInState_fb]     = ResGenT2(         CTAHInState,     CTAHInState_fb,       HotLegParams,   deltat);
                [rHeaterOut,                heaterOutState_fb]  = ResGenT1(         HotLegState,     heaterOutState_fb,    HotLegParams,   deltat);
                [rTCHXIn,                   TCHXInState_fb]     = ResGenT1(         TCHXInState,     TCHXInState_fb,       DRACSparams,    deltat);
                [rDRACSOut,                 DRACSOutState_fb]   = ResGenT2(         DRACSState,      DRACSOutState_fb,     DRACSparams,    deltat);

                % Normalize the residual values
                if (normalize == "true")
                    
                    if (feedback == "true" && i > 1) || (feedback ~= "true")
                        res.rHeater(i)      = res.rHeater(i)      / CIETHeaterState(1);
                        res.rCTAH(i)        = res.rCTAH(i)        / CTAHState(1);
                        res.rCTAHIn(i)      = res.rCTAHIn(i)      / HotLegState(3);
                        res.rHeaterOut(i)   = res.rHeaterOut(i)   / HotLegState(3);                   
                        res.rTCHXIn(i)      = res.rTCHXIn(i)      / DRACSState(3);
                        res.rDRACSOut(i)    = res.rDRACSOut(i)    / DRACSState(3);
                    end
                end
                
                % Low Pass Filter on output
                if (LPfilter == "true" && i > 1)                    
                    res.rHeater(i)      = (1-LPfilter_Alpha(1))*res.rHeater(i-1)       + LPfilter_Alpha(1)*res.rHeater(i);
                    res.rCTAH(i)        = (1-LPfilter_Alpha(2))*res.rCTAH(i-1)         + LPfilter_Alpha(2)*res.rCTAH(i);
                    res.rCTAHIn(i)      = (1-LPfilter_Alpha(3))*res.rCTAHIn(i-1)       + LPfilter_Alpha(3)*res.rCTAHIn(i);
                    res.rHeaterOut(i)   = (1-LPfilter_Alpha(4))*res.rHeaterOut(i-1)    + LPfilter_Alpha(4)*res.rHeaterOut(i);
                    res.rTCHXIn(i)      = (1-LPfilter_Alpha(5))*res.rTCHXIn(i-1)       + LPfilter_Alpha(5)*res.rTCHXIn(i);
                    res.rDRACSOut(i)    = (1-LPfilter_Alpha(6))*res.rDRACSOut(i-1)     + LPfilter_Alpha(6)*res.rDRACSOut(i);   
                end
                
                
                
                % Write values to server
                writeValue(uaClient,HeaterResGenNode,rHeater)
                writeValue(uaClient,CTAHResGenNode,rCTAH)
                writeValue(uaClient,CTAHInResGenNode,rCTAHIn)
                writeValue(uaClient,HeaterOutResGenNode,rHeaterOut)
                writeValue(uaClient,TCHXInResGenNode,rTCHXIn)
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