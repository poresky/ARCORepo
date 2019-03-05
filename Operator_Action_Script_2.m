%% Writes data from ARCO/CIET into record of user actions.
prompt = 'file name?';
file = input(prompt);
filename = strcat(file, '.lvm');
data = csvread(filename, 2);

% naming variables based on csv file column
time = data(:,2);
desired_power = data(:,3);
power_bool = data(:,4);
pump_freq = data(:,5);
pump_bool = data(:,6);
tchx_freq = data(:,7);
tchx_bool = data(:,8);
ctah_bool = data(:,9);
text_log_stop = data(:,10);
interface_stop = data(:,11);


% if lvm file, 2: time, 3: desired power, 4: power output on, 5: pump frequency, 6: activate pump, 7: TCHX frequency, 8: activate TCHX, 9: activate CTAH, 10: stop reading text log, 11: stop reactor interface
% iterates through data to find user actions

j = 0;
for i = 2:length(data)
    if desired_power(i) ~= desired_power(i-1) || power_bool(i) ~= power_bool(i-1) || pump_freq(i) ~= pump_freq(i-1) || pump_bool(i) ~= pump_bool(i-1) || tchx_freq(i) ~= tchx_freq(i-1) || tchx_bool(i) ~= tchx_bool(i-1)|| ctah_bool(i) ~= ctah_bool(i-1) || text_log_stop(i) ~= text_log_stop(i-1) || interface_stop(i)~= interface_stop(i-1)
        j = j + 1;
        timestamp = data(i,2);
        if desired_power(i) ~= desired_power(i-1)
            c(j,1) = {timestamp}; c(j,2) = {'Desired power output changed'}; c(j,3) = {desired_power(i)}; c(j,4) = {'W'};
        end
        if power_bool(i) == 1 && power_bool(i) ~= power_bool(i-1)
            c(j,1) = {timestamp}; c(j,2) = {'Power output on'}; c(j,3) = {'True'}; c(j,4) = {'--'};
        end
        if power_bool(i) == 0 && power_bool(i) ~= power_bool(i-1)
            c(j,1) = {timestamp}; c(j,2) = {'Power output on'}; c(j,3) = {'False'}; c(j,4) = {'--'};
        end
        if pump_freq(i) ~= pump_freq(i-1)
            c(j,1) = {timestamp}; c(j,2) = {'Pump frequency changed'}; c(j,3) = {pump_freq(i)}; c(j,4) = {'Hz'};
        end
        if pump_bool(i) == 1 && pump_bool(i) ~= pump_bool(i-1)
            c(j,1) = {timestamp}; c(j,2) = {'Activate pump'}; c(j,3) = {'True'}; c(j,4) = {'--'};
        end
        if pump_bool(i) == 0 && pump_bool(i) ~= pump_bool(i-1)
            c(j,1) = {timestamp}; c(j,2) = {'Activate pump'}; c(j,3) = {'False'}; c(j,4) = {'--'};
        end
        if tchx_freq(i) ~= tchx_freq(i-1)
            c(j,1) = {timestamp}; c(j,2) = {'TCHX frequency changed'}; c(j,3) = {tchx_freq(i)}; c(j,4) = {'Hz'};
        end
        if tchx_bool(i) == 1 && tchx_bool(i) ~= tchx_bool(i-1)
            c(j,1) = {timestamp}; c(j,2) = {'Activate TCHX'}; c(j,3) = {'True'}; c(j,4) = {'--'};
        end
        if tchx_bool(i) == 0 && tchx_bool(i) ~= tchx_bool(i-1)
            c(j,1) = {timestamp}; c(j,2) = {'Activate TCHX'}; c(j,3) = {'False'}; c(j,4) = {'--'};
        end
        if ctah_bool(i) == 1 && ctah_bool(i) ~= ctah_bool(i-1)
            c(j,1) = {timestamp}; c(j,2) = {'Activate CTAH'}; c(j,3) = {'True'}; c(j,4) = {'--'};
        end
        if ctah_bool(i) == 0 && ctah_bool(i) ~= ctah_bool(i-1)
            c(j,1) = {timestamp}; c(j,2) = {'Activate CTAH'}; c(j,3) = {'False'}; c(j,4) = {'--'};
        end
        if text_log_stop(i) == 1 && text_log_stop(i) ~= text_log_stop(i-1)
            c(j,1) = {timestamp}; c(j,2) = {'Text log stop'}; c(j,3) = {'True'}; c(j,4) = {'--'};
        end
        if interface_stop(i) == 1
            c(j,1) = {timestamp}; c(j,2) = {'Inteface stop'}; c(j,3) = {'True'}; c(j,4) = {'--'};
        end
    end
end

%write to table readable from MATLAB command window
T = cell2table(c, 'VariableNames',{'Time','Action', 'Value', 'Units'});
writetable(T, strcat(file))
disp(T)
