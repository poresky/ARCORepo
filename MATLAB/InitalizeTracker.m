state = 1;
time = 0;
controlVars = 7:9;
measureVars = 10:22;
load("Steady-State Operation Headers.mat");
stateScheme = GenProcedure("Steady-State Operation.csv",Headers)
controlVars = controlVars - 1;
measureVars = measureVars - 1;
tic