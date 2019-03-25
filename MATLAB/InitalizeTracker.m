state = 1;
time = 0;
controlVars = 7:15;
measureVars = 16:17;
load("Plant Operation.mat");
stateScheme = GenProcedure("Plant Operation.csv",Headers)
controlVars = controlVars - 1;
measureVars = measureVars - 1;
tic