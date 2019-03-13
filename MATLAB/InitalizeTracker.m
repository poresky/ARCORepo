state = 1;
time = 0;
controlVars = 7:8;
measureVars = 9;
load("CTAH Control Headers.mat");
stateScheme = GenProcedure("CTAH Control.csv",Headers)
controlVars = controlVars - 1;
measureVars = measureVars - 1;
tic