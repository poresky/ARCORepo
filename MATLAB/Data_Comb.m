%% Writes data from ARCO/CIET into record of user actions.
clear all
clc
prompt = 'file name?';
filename = input(prompt);
%filename = strcat(file, '.lvm');
data = csvread(filename, 2);