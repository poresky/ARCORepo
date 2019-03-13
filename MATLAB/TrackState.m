function [state, description, summaries, bLights, time] = TrackState(systemVars,time,state,stateScheme)
% TRACKSTATE TrackState.mlx
% 
% Uses a state scheme output from GenProcedure and an array of variables 
% from LabView to dynamically create content to be read by the task manager VI.
%% 
% Configuration: Cassify the variable columns as controllable or measurable 
% variables.
    controlVars = 6:7;
    measureVars = 8;
    tolerance = 0.02; % Tolerance for state advancement criteria
%% 
%     
    time = time + toc;
    tic
    if CanAdvance(systemVars,stateScheme{state,[controlVars measureVars]},tolerance) && time >= stateScheme{state,5}
        state = state + 1
        time = 0;
    end
    % Assign the task summary text and whether or not a task is completed based
    % on the current state and those before and after it. Exceptions are made
    % to account for states at the beginning and end of the state scheme,
    % since they won't have two states before and after them.
    if state == 1
        summaries = [stateScheme{state,1} stateScheme{state+1,1} stateScheme{state+2,1} stateScheme{state+3,1} stateScheme{state+4,1}];
        bLights = [false false false false false];    
    elseif state == 2
        summaries = [stateScheme{state-1,1} stateScheme{state,1} stateScheme{state+1,1} stateScheme{state+2,1} stateScheme{state+3,1}];
        bLights = [true false false false false];  
    elseif state == size(stateScheme,1) - 1
        summaries = [stateScheme{state-3,1} stateScheme{state-2,1} stateScheme{state-1,1} stateScheme{state,1} stateScheme{state+1,1}];
        bLights = [true true true true false];  
    elseif state == size(stateScheme,1)
        summaries = [stateScheme{state-1,1} stateScheme{state,1} stateScheme{state+1,1} stateScheme{state+2,1} stateScheme{state+3,1}];
        bLights = [true true true true true];  
    else
        summaries = [stateScheme{state-2,1} stateScheme{state-1,1} stateScheme{state,1} stateScheme{state+1,1} stateScheme{state+2,1}];
        bLights = [true true false false false];
    end 
    % Assign the text in the description box for the Vi to the current state's
    % description
    description = stateScheme{state,2};
end
%% 
% CheckMatch
% 
% Checks to see whether the set of system variables matches the criteria 
% for 
function [bComplete]  =  CanAdvance(systemVars,stateVars,tolerance)
    for i = 1:length(stateVars)
        if isnan(stateVars(i))
            continue
        elseif abs((systemVars(i)-stateVars(i))/(stateVars(i)+eps)) < tolerance
            continue
        else 
            bComplete = false;
            return
        end
    end
    bComplete = true;
end
%% 
%