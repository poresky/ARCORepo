filename = 'my_text2.txt';
old_data = [0,0,0,0,0,0,0,0,0,0];
concatenated_report = [0,{''},0,{''}];
j = 1;
displayed_report = [0,0,0,0,0];
while true
    data = csvread(filename, 0);
    timestamp = data(1,1);
    desired_power = data(2,1);
    power_bool = data(3,1);
    pump_freq = data(4,1);
    pump_bool = data(5,1);
    tchx_freq = data(6,1);
    tchx_bool = data(7,1);
    ctah_bool = data(8,1);
    text_log_stop = data(9,1);
    interface_stop = data(10,1);
    new_data = [timestamp,desired_power,power_bool, pump_freq, pump_bool, tchx_freq, tchx_bool, ctah_bool, text_log_stop, interface_stop];
    if new_data(1,2) ~= old_data(1,2)
        concatenated_report(j,1) = {timestamp}; concatenated_report(j,2) = {'Desired power output changed'}; concatenated_report(j,3) = {desired_power}; concatenated_report(j,4) = {'W'};
        displayed_report = ['Reactor operator changed desired power to ' num2str(desired_power) ' at ' num2str(timestamp) ' seconds'];
        b = concatenated_report(j,:); old_data(1,2) = new_data(1,2); j = j + 1;
        disp(displayed_report)
    end
    if new_data(1,3) ~= old_data(1,3)
        if new_data(1,3) == 1
            concatenated_report(j,1) = {timestamp}; concatenated_report(j,2) = {'Power output on'}; concatenated_report(j,3) = {'True'}; concatenated_report(j,4) = {'--'};
            displayed_report = ['Reactor operator turned power output on at ' num2str(timestamp) ' seconds'];
        else
            concatenated_report(j,1) = {timestamp}; concatenated_report(j,2) = {'Power output on'}; concatenated_report(j,3) = {'False'}; concatenated_report(j,4) = {'--'};
            displayed_report = ['Reactor operator turned power output off at ' num2str(timestamp) ' seconds'];
        end
        b = concatenated_report(j,:); old_data(1,3) = new_data(1,3); j = j + 1;
        disp(displayed_report)
    end
    if new_data(1,4) ~= old_data(1,4)
        concatenated_report(j,1) = {timestamp}; concatenated_report(j,2) = {'Pump frequency changed'}; concatenated_report(j,3) = {pump_freq}; concatenated_report(j,4) = {'W'};
        displayed_report = ['Reactor operator changed pump frequency to ' num2str(pump_freq) ' at ' num2str(timestamp) ' seconds'];
        b = concatenated_report(j,:); old_data(1,4) = new_data(1,4); j = j + 1;
        disp(displayed_report)
    end
    if new_data(1,5) ~= old_data(1,5)
        if new_data(1,5) == 1
            concatenated_report(j,1) = {timestamp}; concatenated_report(j,2) = {'Activate pump'}; concatenated_report(j,3) = {'True'}; concatenated_report(j,4) = {'--'};
            displayed_report = ['Reactor operator activated pump at ' num2str(timestamp) ' seconds'];
        else
            concatenated_report(j,1) = {timestamp}; concatenated_report(j,2) = {'Activate pump'}; concatenated_report(j,3) = {'False'}; concatenated_report(j,4) = {'--'};
            displayed_report = ['Reactor operator deactivated pump at ' num2str(timestamp) ' seconds'];
        end
        b = concatenated_report(j,:); old_data(1,5) = new_data(1,5); j = j + 1;
        disp(displayed_report)
    end
    if new_data(1,6) ~= old_data(1,6)
        concatenated_report(j,1) = {timestamp}; concatenated_report(j,2) = {'TCHX frequency changed'}; concatenated_report(j,3) = {tchx_freq}; concatenated_report(j,4) = {'W'};
        b = concatenated_report(j,:); old_data(1,6) = new_data(1,6); j = j + 1;
        displayed_report = ['Reactor operator changed TCHX frequency to ' num2str(tchx_freq) ' at ' num2str(timestamp) ' seconds'];
        disp(displayed_report)
    end
    if new_data(1,7) ~= old_data(1,7)
        if new_data(1,7) == 1
            concatenated_report(j,1) = {timestamp}; concatenated_report(j,2) = {'Activate TCHX'}; concatenated_report(j,3) = {'True'}; concatenated_report(j,4) = {'--'};
            displayed_report = ['Reactor operator activated TCHX at ' num2str(timestamp) ' seconds'];
        else
            concatenated_report(j,1) = {timestamp}; concatenated_report(j,2) = {'Activate TCHX'}; concatenated_report(j,3) = {'False'}; concatenated_report(j,4) = {'--'};
            displayed_report = ['Reactor operator deactivated TCHX at ' num2str(timestamp) ' seconds'];
        end
        b = concatenated_report(j,:); old_data(1,7) = new_data(1,7); j = j + 1;
        disp(displayed_report)
    end
    if new_data(1,8) ~= old_data(1,8)
        if new_data(1,8) == 1
            concatenated_report(j,1) = {timestamp}; concatenated_report(j,2) = {'Activate CTAH'}; concatenated_report(j,3) = {'True'}; concatenated_report(j,4) = {'--'};
            displayed_report = ['Reactor operator activated CTAH at ' num2str(timestamp) ' seconds'];
        else
            concatenated_report(j,1) = {timestamp}; concatenated_report(j,2) = {'Activate CTAH'}; concatenated_report(j,3) = {'False'}; concatenated_report(j,4) = {'--'};
            displayed_report = ['Reactor operator deactivated CTAH at ' num2str(timestamp) ' seconds'];
        end
        b = concatenated_report(j,:); old_data(1,8) = new_data(1,8); j = j + 1;
        disp(displayed_report)
    end
    if new_data(1,9) ~= old_data(1,9)
        if new_data(1,9) == 1
            concatenated_report(j,1) = {timestamp}; concatenated_report(j,2) = {'Text log stop'}; concatenated_report(j,3) = {'True'}; concatenated_report(j,4) = {'--'};
            displayed_report = ['Reactor operator stopped text log at ' num2str(timestamp) ' seconds'];
        else
            concatenated_report(j,1) = {timestamp}; concatenated_report(j,2) = {'Text log stop'}; concatenated_report(j,3) = {'False'}; concatenated_report(j,4) = {'--'};
            displayed_report = ['Reactor operator restarted text log at ' num2str(timestamp) ' seconds'];
        end
        b = concatenated_report(j,:); old_data(1,9) = new_data(1,9); j = j + 1;
        disp(displayed_report)
    end
    if new_data(1,10) ~= old_data(1,10)
        if new_data(1,10) == 1
            concatenated_report(j,1) = {timestamp}; concatenated_report(j,2) = {'Interface stop'}; concatenated_report(j,3) = {'True'}; concatenated_report(j,4) = {'--'};
            displayed_report = ['Reactor operator stopped interface at ' num2str(timestamp) ' seconds'];
        else
            concatenated_report(j,1) = {timestamp}; concatenated_report(j,2) = {'Interface stop'}; concatenated_report(j,3) = {'False'}; concatenated_report(j,4) = {'--'};
            displayed_report = ['Reactor operator restarted interface at ' num2str(timestamp) ' seconds'];
        end
        b = concatenated_report(j,:); old_data(1,1) = new_data(1,1); old_data(1,10) = new_data(1,10); j = j + 1;
        disp(displayed_report)
    end
    pause(1)
end
%% Write to file
report = cell2table(concatenated_report,'VariableNames', {'Time','Action','Value','Units'})
writetable(report, strcat(filename))