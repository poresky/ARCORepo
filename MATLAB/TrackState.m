function [state, description, summaries, bLights, time] = TrackState(systemVars,time,state,stateScheme)
% TRACKSTATE TrackState.mlx
% 
% Uses a state scheme output from GenProcedure and an array of variables 
% from LabView to dynamically create content to be read by the task manager VI.
%% 
% Configuration: Classify the variable columns as controllable or measurable 
% variables by index. 
    controlVars = 6:10;
    measureVars = 11:12;
    tolerance = 0.02; % Tolerance for state advancement criteria. 
%% 
%     
    time = time + toc;
    tic
	
	% Advances the state if the system conditions matches the provided state variables
	if state <= size(stateScheme,1)
		if CanAdvance(systemVars,stateScheme{state,[controlVars measureVars]},tolerance) && time >= stateScheme{state,5}
			state = state + 1
			time = 0;
	    end
    end
    % Assign the task summary text and whether or not a task is completed based
    % on the current state and those before and after it. Exceptions are made
    % to account for states at the beginning and end of the state scheme,
    % since they won't have two states before and after them.
    if state == 1
        summaries = [stateScheme{state,1} stateScheme{state+1,1} stateScheme{state+2,1}];
        bLights = [false false false]; 
    elseif state == size(stateScheme,1)
        summaries = [stateScheme{state-2,1} stateScheme{state-1,1} stateScheme{state,1}];
        bLights = [true true false];  
    elseif state > size(stateScheme,1)
        summaries = [stateScheme{size(stateScheme,1)-2,1} stateScheme{size(stateScheme,1)-1,1} stateScheme{size(stateScheme,1),1}];
        bLights = [true true true];  
    else
        summaries = [stateScheme{state-1,1} stateScheme{state,1} stateScheme{state+1,1}];
        bLights = [true false false];
    end 
    % Assign the text in the description box for the Vi to the current state's
    % description
    description = stateScheme{min([state,size(stateScheme,1)]),2};
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