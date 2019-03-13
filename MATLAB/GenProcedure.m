function States = GenProcedure(csvFileName,Headers)
% GENPROCEDURE GenProcedure.mlx
% 
% Uses a state scheme to generate a list of instructions.
%% 
% Configuration: Cassify the variable columns as controllable or measurable 
% variables.
    controlVars = 7:9;
    measureVars = 10:22;
%% 
% Read the scheme structure file and prepare the output.
    States = readtable(csvFileName);
    [numStates, ~] = size(States);
%% 
% Iterate through each state, and piece together the description and summary 
% for each step by using the change in variables between states as well as the 
% presence of exception fields such as the "record" variable.
    for s = 1:numStates
        
        descriptionOverride = States{s,2};
        summaryOverride = States{s,1};
        
        % Skip states where both description and summary are overriden.
        if summaryOverride ~= "" && descriptionOverride ~= ""
            descs(s) = descriptionOverride;
            sums(s) = summaryOverride;
            continue
        end 
        
        description = "";
        summary = "";    
        % Record data steps
        if States{s,5} ~= ""
            summary = "Record " + States{s,5};
            description = description + "Record " + States{s,5} + ". ";
        end     
        
        % Set a control steps
        steps = find(~isnan(States{s,controlVars}));
        for i = steps  + controlVars(1) - 1
            summary = "Set " + Headers(i);
            description = description + "Set " + Headers(i) + " to " + States{s,i} + ". ";   
        end 
        
        % Achieve a measurement steps
        steps = find(~isnan(States{s,measureVars}));
        for i = steps + measureVars(1) - 1
            if States{s-1,i} == States{s,i}
                description = description + "Hold " + Headers(i) + " of " + States{s,i} + ". ";            
            else 
                summary = "Achieve " + Headers(i);
                description = description + "Achieve " + Headers(i) + " of " + States{s,i} + ". ";   
            end 
        end     
        
        % Waiting steps
        if States{s,6} > 0
            summary = "Wait";
            description = description + "Wait for " + States{s,6} + " seconds. ";
        end 
        % Apply overrides
        if descriptionOverride ~= ""
            States{s,2} = {char(descriptionOverride)};
            States{s,1} = {char(summary)};
        elseif descriptionOverride ~= ""
            States{s,2} = {char(description + string(States{s,3}))};
            States{s,1} = {char(summaryOverride)};
        else
            States{s,2} = {char(description + string(States{s,3}))};
            States{s,1} = {char(summary)};
        end 
    end 
    States = removevars(States,{'Comment'});
    States.Properties.VariableNames{'SummaryOverride'} = 'Summary';
    States.Properties.VariableNames{'Desc_Override'} = 'Description';
end
%% 
%