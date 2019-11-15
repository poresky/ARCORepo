%% Define client and connect to the Main Server.
uaClient = opcua('192.168.1.3',49581);
connect(uaClient)

%% Define nodes from LabVIEW in MATLAB.
%MATLABBooleansNode = findNodeByName(uaClient.Namespace,'MATLAB Booleans');
%BooleanControlNode = findNodeByName(uaClient.Namespace,'Boolean Control Actions');
NumericControlNode = findNodeByName(uaClient.Namespace,'Numeric Control Actions');
CIETDataNode = findNodeByName(uaClient.Namespace,'CIET Data');
%[matlab_booleans, date_time_matlab] = readValue(uaClient,MATLABBooleansNode);
%matlab_active = matlab_booleans(1);
%OperatorActionsNode = findNodeByName(uaClient.Namespace,'Operator Actions');

%% Define string node in MATLAB. The output of this script is eventually written to this node to be displayed in LabVIEW.
%StringNode = findNodeByName(uaClient.Namespace,'Chat');

%% For each line of data, check to see if previous value equals new value. If not, print a report of the change.
old_data = [0,0,0,0,0];
rgb = [188, 188, 188; 188, 188, 188; 188, 188, 188; 188, 188, 188];
displayed_report = [];
if matlab_active == true
    while matlab_active == true
        % Read values from nodes and define them a+s variables.
        %[matlab_booleans, date_time_matlab] = readValue(uaClient,MATLABBooleansNode);
        %matlab_active = matlab_booleans(1); 
        %operator_actions = matlab_booleans(2);
        [numeric_control_actions, date_time_numeric] = readValue(uaClient, NumericControlNode);
        ctah_freq = numeric_control_actions(5); 
        tchx_freq = numeric_control_actions(6); 
        pump_freq = numeric_control_actions(7); 
        desired_power = numeric_control_actions(8);
        %[boolean_control_actions, date_time_boolean] = readValue(uaClient, BooleanControlNode);
        %power_bool = boolean_control_actions(2); 
        %ctah_bool = boolean_control_actions(3); 
        %tchx_bool = boolean_control_actions(4); 
        %pump_bool = boolean_control_actions(5);
        [ciet_data, date_time_ciet] = readValue(uaClient, CIETDataNode);
        timestamp = ciet_data(1);
        new_data = [timestamp, desired_power, pump_freq, tchx_freq, ctah_freq];
        if operator_actions == true
                if new_data(1,2) ~= old_data(1,2)
                    rgb(1,:)=[145, 251, 254];
                    old_data(1,3) = new_data(1,3); 
                    disp(displayed_report)
                end
                if new_data(1,2) ~= old_data(1,2)
                    displayed_report = ['Reactor operator changed desired power to ' num2str(desired_power) ' W at ' num2str(timestamp) ' seconds'];
                    old_data(1,2) = new_data(1,2); 
                    disp(displayed_report)
                end
                if new_data(1,4) ~= old_data(1,4)
                    displayed_report = ['Reactor operator changed pump frequency to ' num2str(pump_freq) ' Hz at ' num2str(timestamp) ' seconds'];
                    old_data(1,4) = new_data(1,4); 
                    disp(displayed_report)
                end
                if new_data(1,5) ~= old_data(1,5)
                    if new_data(1,5) == 1
                        displayed_report = ['Reactor operator activated pump at ' num2str(timestamp) ' seconds'];
                    else
                        displayed_report = ['Reactor operator deactivated pump at ' num2str(timestamp) ' seconds'];
                    end
                    old_data(1,5) = new_data(1,5); 
                    disp(displayed_report)
                end
                %writeValue(uaClient,StringNode,[displayed_report])
                writeValue(uaClient,OperatorActionsNode,[displayed_report])
        end
        pause(.1)
    end
else
    disp('MATLAB is not active')
end
disp('MATLAB is no longer active')
