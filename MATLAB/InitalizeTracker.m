state = 1;
time = 0;
controlVars = 7:11;
measureVars = 12:13;
load("Fault Mitigation 2 Headers.mat");
stateScheme = GenProcedure("faultmitigation2.csv",Headers)
controlVars = controlVars - 1;
measureVars = measureVars - 1;
tic