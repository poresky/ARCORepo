%% Define client and connect to the Main Server.
uaClient = opcua('192.168.1.3',49581);
connect(uaClient)

%% Define nodes from LabVIEW in MATLAB.
MATLABBooleansNode = findNodeByName(uaClient.Namespace,'MATLAB Booleans');
BooleanControlNode = findNodeByName(uaClient.Namespace,'Boolean Control Actions');
NumericControlNode = findNodeByName(uaClient.Namespace,'Numeric Control Actions');
CIETDataNode = findNodeByName(uaClient.Namespace,'CIET Data');

%% Define string node in MATLAB. The output of this script is eventually written to this node to be displayed in LabVIEW.
StringNode = findNodeByName(uaClient.Namespace,'Chat');

% Read values from node and define them as variables
[matlab_booleans, date_time_matlab] = readValue(uaClient,MATLABBooleansNode);
matlab_active = matlab_booleans(1); operator_actions = matlab_booleans(2);

%% For each line of data, check to see if previous value equals new value. If not, print a report of the change.
% If want this script to output a comprehensive report of all operator actions, concatenate table with each new report and write to file on computer. 
% variables air_flow_rate, shaft_rpm, hpt_pr, lpt_pr, ng_flow_rate, ng_temp, ng_press, stop_bop
old_data = [0,0,0,0,0,0,0,0];
if matlab_active == true
    while matlab_active == true
        [matlab_booleans, date_time_matlab] = readValue(uaClient,MATLABBooleansNode);
        matlab_active = matlab_booleans(1); operator_actions = matlab_booleans(2);
        [numeric_control_actions, date_time_numeric] = readValue(uaClient, NumericControlNode);
        ctah_freq = numeric_control_actions(5); tchx_freq = numeric_control_actions(6); pump_freq = numeric_control_actions(7); desired_power = numeric_control_actions(8);
        [boolean_control_actions, date_time_boolean] = readValue(uaClient, BooleanControlNode);
        power_bool = boolean_control_actions(2); ctah_bool = boolean_control_actions(3); tchx_bool = boolean_control_actions(4); pump_bool = boolean_control_actions(5);
        [ciet_data, date_time_ciet] = readValue(uaClient, CIETDataNode);
        timestamp = ciet_data(1);
        new_data = [timestamp, air_flow_rate, shaft_rpm, hpt_pr, lpt_pr, ng_flow_rate, ng_temp, ng_press, stop_bop];
        if operator_actions == true
                if new_data(1,2) ~= old_data(1,2)
                    displayed_report = ['BoP operator changed air flow rate to ' num2str(air_flow_rate), ' at ' num2str(timestamp) ' seconds'];
                    old_data(1,2) = new_data(1,2); disp(displayed_report)
                end
                if new_data(1,3) ~= old_data(1,3)
                    displayed_report = ['BoP operator changed shaft RPM to ' num2str(shaft_rpm) ' at ' num2str(timestamp) ' seconds'];
                    old_data(1,3) = new_data(1,3); disp(displayed_report)
                end
                if new_data(1,4) ~= old_data(1,4)
                    displayed_report = ['BoP operator changed HPT PR to ' num2str(hpt_pr) ' at ' num2str(timestamp) ' seconds'];
                    old_data(1,4) = new_data(1,4); disp(displayed_report)
                end
                if new_data(1,5) ~= old_data(1,5)
                    displayed_report = ['BoP operator changed LPT PR to ' num2str(lpt_pr) ' at ' num2str(timestamp) ' seconds'];
                    old_data(1,5) = new_data(1,5); disp(displayed_report)
                end
                if new_data(1,7) ~= old_data(1,7)
                    displayed_report = ['BoP operator changed NG flow rate to ' num2str(ng_flow_rate) ' at ' num2str(timestamp) ' seconds'];
                    old_data(1,7) = new_data(1,7); disp(displayed_report)
                end
                writeValue(uaClient,StringNode,[displayed_report])
                if new_data(1,8) ~= old_data(1,8)
                    if new_data(1,8) == 1
                        displayed_report = ['Reactor operator activated CTAH at ' num2str(timestamp) ' seconds'];
                    else
                        displayed_report = ['Reactor operator deactivated CTAH at ' num2str(timestamp) ' seconds'];
                    end
                    old_data(1,8) = new_data(1,8); disp(displayed_report)
                end   
        end
        pause(.1)
    end
else
    disp('MATLAB is not active')
end
disp('MATLAB is no longer active')