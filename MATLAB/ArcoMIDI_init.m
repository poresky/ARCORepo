% Create MIDI Device object
try
	inputCh = mididevice('Input','MIDI Mix');
catch
    warning("Midi controller not found. Manually intialize it when plugged in.");
	bMIDISuccess = 0;
    return
end

% Name your max parameters here and define their max values.
ParamNames = ["Desired Power (W)", ...
              "Pump Freq (Hz)", ...
              "CTAH Freq (Hz)", ...
			  "TCHX Freq (Hz)", ...
			  "Unassigned", ...
			  "Unassigned", ...
			  "Unassigned", ...
			  "Unassigned" ];

maxVals = [8000, ...
           45, ...
           60, ...
		   60, ...
		   0, ...
		   0, ...
		   0, ...
		   0];
			  
maxVals1 = [7200, ...
           40.5, ...
           54, ...
		   54, ...
		   0, ...
		   0, ...
		   0, ...
		   0];

maxVals2 = [800, ...
           4.5, ...
           6, ...
		   6, ...
		   0, ...
		   0, ...
		   0, ...
		   0];
		   

% Check if MIDI control IDs are already loaded, otherwise loading them from
% ControlIDs.mat. If nothing is found, the user will be prompted to 
try
    slider_ids;
    knob_row1_ids;
    master_id;
catch
    disp('Attempting to load ControlIDs.mat')
    try
        load('ControlIDs.mat')
    catch
        warning('ControlIDs.mat not found.')
        disp('Please move your master control.')
        slider_ids = zeros(1,8);
        knob_row1_ids = zeros(1,8);
        master_id = midiid;
        pause(2)
        for i = 1:8
            disp('Please move slider number '+string(i))
            slider_ids(i) = midiid;
            pause(2.5)
            disp('Please move knob number '+string(i))
            knob_row1_ids(i) = midiid;
            pause(2.5)
        end 
        try
            disp('Attempting to save ControlIDs.mat')
            save('ControlIDs.mat','slider_ids','knob_row1_ids')
        catch 
            disp('Saving ControlIDs.mat failed. Check your permissions'+...
            ' so you do not have have to repeat set-up again!')
        end
    end
end 

% Load MIDI positions from last execution
%try
%    disp("Loading control positions from last session.")
%    load("LastVals.mat")
%    disp("Control positions from last session loaded.")
%catch
%    disp("LastVals.mat not found. Initializing as zeros.")
knobRow1LastValues = [0,0,0,0,0,0,0,0];
sliderLastValues = [0,0,0,0,0,0,0,0];
%end 

% Create MIDI Control objects to listen to changes in controls. Use values
% from last run as initial "guess" since control position cannot be read
% until it is changed while a MIDI Control object is listening to it.
%masterControl = midicontrols(master_id,0.5);
sliderControl = midicontrols(slider_ids,sliderLastValues);
knobRow1Control = midicontrols(knob_row1_ids,knobRow1LastValues);
outputVals = [-1,-1,-1,-1,-1,-1,-1,-1];
gaugeVals = [0,0,0,0,0,0,0,0];
sliderPos = [0,0,0,0,0,0,0,0];
knobRow1Pos = [0,0,0,0,0,0,0,0];
sliderInit = [false,false,false,false,false,false,false,false];
knobRow1Init = [false,false,false,false,false,false,false,false];

% How often to repeat the loop. Shorter times will give finer controls, but
% use more computing power.
timeStep = 0.016666;
bMIDISuccess = 1;

% Save controller positions for next time.
%sliderLastValues = midiread(sliderControl);
%knobRow1LastValues = midiread(knobRow1Control);
%save("LastVals.mat",'sliderLastValues','knobRow1LastValues')