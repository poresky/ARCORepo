filename = 'my_text2.txt';
c = [0,0,0,0,0,0,0,0,0,0,0];
e = [0,{''},0,{''}];
j = 1;
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
    d = [timestamp,desired_power,power_bool, pump_freq, pump_bool, tchx_freq, tchx_bool, ctah_bool, text_log_stop, interface_stop];
    if d(1,2) ~= c(1,2)
        e(j,1) = {timestamp}; e(j,2) = {'Desired power output changed'}; e(j,3) = {desired_power}; e(j,4) = {'W'};
        b = e(j,:); c(1,2) = d(1,2); j = j + 1;
        disp(b)
    end
    if d(1,3) ~= c(1,3)
        if d(1,3) == 1
            e(j,1) = {timestamp}; e(j,2) = {'Power output on'}; e(j,3) = {'True'}; e(j,4) = {'--'};
        else
            e(j,1) = {timestamp}; e(j,2) = {'Power output on'}; e(j,3) = {'False'}; e(j,4) = {'--'};
        end
        b = e(j,:); c(1,3) = d(1,3); j = j + 1;
        disp(b)
    end
    if d(1,4) ~= c(1,4)
        e(j,1) = {timestamp}; e(j,2) = {'Pump frequency changed'}; e(j,3) = {pump_freq}; e(j,4) = {'W'};
        b = e(j,:); c(1,4) = d(1,4); j = j + 1;
        disp(b)
    end
    if d(1,5) ~= c(1,5)
        if d(1,5) == 1
            e(j,1) = {timestamp}; e(j,2) = {'Activate pump'}; e(j,3) = {'True'}; e(j,4) = {'--'};
        else
            e(j,1) = {timestamp}; e(j,2) = {'Activate pump'}; e(j,3) = {'False'}; e(j,4) = {'--'};
        end
        b = e(j,:); c(1,5) = d(1,5); j = j + 1;
        disp(b)
    end
    if d(1,6) ~= c(1,6)
        e(j,1) = {timestamp}; e(j,2) = {'TCHX frequency changed'}; e(j,3) = {tchx_freq}; e(j,4) = {'W'};
        b = e(j,:); c(1,6) = d(1,6); j = j + 1;
        disp(b)
    end
    if d(1,7) ~= c(1,7)
        if d(1,7) == 1
            e(j,1) = {timestamp}; e(j,2) = {'Activate TCHX'}; e(j,3) = {'True'}; e(j,4) = {'--'};
        else
            e(j,1) = {timestamp}; e(j,2) = {'Activate TCHX'}; e(j,3) = {'False'}; e(j,4) = {'--'};
        end
        b = e(j,:); c(1,7) = d(1,7); j = j + 1;
        disp(b)
    end
    if d(1,8) ~= c(1,8)
        if d(1,8) == 1
            e(j,1) = {timestamp}; e(j,2) = {'Activate CTAH'}; e(j,3) = {'True'}; e(j,4) = {'--'};
        else
            e(j,1) = {timestamp}; e(j,2) = {'Activate CTAH'}; e(j,3) = {'False'}; e(j,4) = {'--'};
        end
        b = e(j,:); c(1,8) = d(1,8); j = j + 1;
        disp(b)
    end
    if d(1,9) ~= c(1,9)
        if d(1,9) == 1
            e(j,1) = {timestamp}; e(j,2) = {'Text log stop'}; e(j,3) = {'True'}; e(j,4) = {'--'};
        else
            e(j,1) = {timestamp}; e(j,2) = {'Text log stop'}; e(j,3) = {'False'}; e(j,4) = {'--'};
        end
        b = e(j,:); c(1,9) = d(1,9); j = j + 1;
        disp(b)
    end
    if d(1,10) ~= c(1,10)
        if d(1,10) == 1
            e(j,1) = {timestamp}; e(j,2) = {'Interface stop'}; e(j,3) = {'True'}; e(j,4) = {'--'};
        else
            e(j,1) = {timestamp}; e(j,2) = {'Interface stop'}; e(j,3) = {'False'}; e(j,4) = {'--'};
        end
        b = e(j,:); c(1,10) = d(1,10); j = j + 1;
        disp(b)
    end
    pause(1)
end

% T = cell2table(e,'VariableNames', {'Time','Action','Value','Units'})
% writetable(T, strcat(file))