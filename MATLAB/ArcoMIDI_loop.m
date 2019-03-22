% Read control positions and scale slider reading to physical values.
sliderPos = midiread(sliderControl);
knobRow1Pos = midiread(knobRow1Control);
outputVals = sliderPos.*maxVals;
gaugeVals = sliderPos.*maxVals;

if ~all([sliderInit,knobRow1Init])
    for i = 1:8
        if ~sliderInit(i)
            if sliderPos(i) ~= 0
                sliderInit(i) = true; %#ok<SAGROW>
            else
                sliderPos(i) = -1;
                outputVals(i) = -1;
            end
        end
        if ~knobRow1Init(i)
            if knobRow1Pos(i) ~= 0
                knobRow1Init(i) = true; %#ok<SAGROW>
            else
                knobRow1Pos(i) = -1;
                outputVals(i) = -1;
            end
        end
    end
end 


for i = 1:8
        if ~sliderInit(i)
            if sliderPos(i) ~= 0
                sliderInit(i) = true;
            else
                sliderPos(i) = -1;
                outputVals(i) = -1;
        end
    end
end
for i = 1:8
    if knobRow1Pos(i) < 0.5
        outputVals(i) = -1;
    end
end



%lastSliderPos = sliderPos;
%lastKnobRow1Pos = knobRow1Pos;

pause(timeStep)