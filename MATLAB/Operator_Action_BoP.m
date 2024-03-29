%% Define client and connect to the Main Server.
uaClient = opcua('192.168.1.3',49581);
connect(uaClient)

%% Define nodes from LabVIEW in MATLAB.
MATLABBooleansNode = findNodeByName(uaClient.Namespace,'MATLAB Booleans');
BoPInputsNode = findNodeByName(uaClient.Namespace,'BoP Inputs');
CIETDataNode = findNodeByName(uaClient.Namespace,'CIET Data');
[matlab_booleans, date_time_matlab] = readValue(uaClient,MATLABBooleansNode);
matlab_active = matlab_booleans(1); operator_actions = matlab_booleans(2);

%% Define string node in MATLAB. The output of this script is eventually written to this node to be displayed in LabVIEW.
StringNode = findNodeByName(uaClient.Namespace,'Chat');

%% For each line of data, check to see if previous value equals new value. If not, print a report of the change.
% If want this script to output a comprehensive report of all operator actions, concatenate table with each new report and write to file on computer. 
% variables air_flow_rate, shaft_rpm, hpt_pr, lpt_pr, ng_flow_rate, ng_temp, ng_press, stop_bop
[ciet_data, date_time_ciet] = readValue(uaClient, CIETDataNode);
[bop_inputs, date_time_numeric] = readValue(uaClient,BoPInputsNode);
old_data = [ciet_data(1), bop_inputs(3), bop_inputs(4), bop_inputs(5), bop_inputs(9), bop_inputs(8), bop_inputs(6), bop_inputs(7)];
if matlab_active == true
    while matlab_active == true
        [ciet_data, date_time_ciet] = readValue(uaClient, CIETDataNode);
        [matlab_booleans, date_time_matlab] = readValue(uaClient,MATLABBooleansNode);
        matlab_active = matlab_booleans(1); 
        operator_actions = matlab_booleans(2);
        [bop_inputs, date_time_numeric] = readValue(uaClient,BoPInputsNode);
        timestamp = ciet_data(1);
        air_flow_rate = bop_inputs(3);
        shaft_rpm = bop_inputs(4);
        hpt_pr = bop_inputs(5);
        lpt_pr = bop_inputs(9);
        ng_flow_rate = bop_inputs(8);
        ng_temp = bop_inputs(6);
        ng_press = bop_inputs(7);
        %stop_bop = bop_actions(?); 
        %new_data(9) is stop_bop when find node 
        new_data = [timestamp, air_flow_rate, shaft_rpm, hpt_pr, lpt_pr, ng_flow_rate, ng_temp, ng_press];
        if operator_actions == true
                if new_data(1,2) ~= old_data(1,2)
                    displayed_report = ['BoP operator changed air flow rate to ' num2str(air_flow_rate), ' kg/s at ' num2str(timestamp) ' seconds'];
                    old_data(1,2) = new_data(1,2); 
                    disp(displayed_report)
                end
                if new_data(1,3) ~= old_data(1,3)
                    displayed_report = ['BoP operator changed shaft RPM to ' num2str(shaft_rpm) ' RPM at ' num2str(timestamp) ' seconds'];
                    old_data(1,3) = new_data(1,3); 
                    disp(displayed_report)
                end
                if new_data(1,4) ~= old_data(1,4)
                    displayed_report = ['BoP operator changed HPT pressure to ' num2str(hpt_pr) ' bar at ' num2str(timestamp) ' seconds'];
                    old_data(1,4) = new_data(1,4); 
                    disp(displayed_report)
                end
                if new_data(1,5) ~= old_data(1,5)
                    displayed_report = ['BoP operator changed LPT pressure to ' num2str(lpt_pr) ' bar at ' num2str(timestamp) ' seconds'];
                    old_data(1,5) = new_data(1,5); 
                    disp(displayed_report)
                end
                if new_data(1,6) ~= old_data(1,6)
                    displayed_report = ['BoP operator changed natural gas flow rate to ' num2str(ng_flow_rate) ' kg/s at ' num2str(timestamp) ' seconds'];
                    old_data(1,6) = new_data(1,6); 
                    disp(displayed_report)
                end
                if new_data(1,7) ~= old_data(1,7)
                    displayed_report = ['BoP operator changed natural gas temperature to ' num2str(ng_temp) ' C at ' num2str(timestamp) ' seconds'];
                    old_data(1,7) = new_data(1,7); 
                    disp(displayed_report)
                end
                if new_data(1,8) ~= old_data(1,8)
                    displayed_report = ['Bop operator changed natural gas pressure to ' num2str(ng_press) ' bar 
                        at ' num2str(timestamp) ' seconds'];
                    old_data(1,8) = new_data(1,8); 
                    disp(displayed_report)
                end
                %if new_data(1,9) ~= old_data(1,9)
                %    if new_data(1,9) == 1
                %        displayed_report = ['BoP operator stopped Balance of Plant at ' num2str(timestamp) ' seconds'];
                %    else
                %        displayed_report = ['BoP operator restarted Balance of Plant at ' num2str(timestamp) ' seconds'];
                %    end
                %    old_data(1,9) = new_data(1,9); disp(displayed_report)
                %end  
                writeValue(uaClient,StringNode,[displayed_report])
        end
        pause(.1)
    end
else
    disp('MATLAB is not active')
end
disp('MATLAB is no longer active')

%% Write to local file on computer

