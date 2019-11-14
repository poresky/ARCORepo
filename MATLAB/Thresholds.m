%% Define client and connect to the Main Server.
uaClient = opcua('192.168.1.3',49581);
connect(uaClient)

%% Define nodes from LabVIEW in MATLAB.
CIETDataNode = findNodeByName(uaClient.Namespace,'Result CIET Data');
%BooleanControlNode = findNodeByName(uaClient.Namespace,'Boolean Control Actions');
%NumericControlNode = findNodeByName(uaClient.Namespace,'Numeric Control Actions');
%CIETDataNode = findNodeByName(uaClient.Namespace,'CIET Data');
[matlab_booleans, date_time_matlab] = readValue(uaClient,MATLABBooleansNode);
matlab_active = matlab_booleans(1);
OperatorActionsNode = findNodeByName(uaClient.Namespace,'Operator Actions');

%% Define string node in MATLAB. The output of this script is eventually written to this node to be displayed in LabVIEW.
StringNode = findNodeByName(uaClient.Namespace,'Chat');

%% For each line of data, check to see if previous value equals new value. If not, print a report of the change.
% If want this script to output a comprehensive report of all operator actions, concatenate table with each new report and write to file on computer. 
% Variables desired_power, power_bool, pump_freq, pump_bool, tchx_freq, tchx_bool, ctah_bool
old_data = [0,0,0,0,0,0,0,0,0,0];
displayed_report = [];
if matlab_active == true

