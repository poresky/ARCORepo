function [P,prev_rho,k_rod,k_test] = reactor_power(P0,rho0,dt,rodout,rodouttest,Tf,Tc)

%Neutronics%
lambda = .0785; %[s^-1] 
Lambda = 5.02*10^(-4); %[s] Prompt Neutron Generation Time
beta = .0065; %Delayed neutron fraction

%Control Rod Worth%
%%%%%%%EDIT LATER%%%%%%%
control_rod_worth_constant = .49495;
control_rod_worth_coeffecient = 1;
%k = control_rod_worth_constant + control_rod_worth_coeffecient * amt_rod_out

%Temperature Feedback%
Fuel_Feedback = -6.7;
Coolant_Feedback = -2.1;
Tf_eq = 100; %get from CIET
Tc_eq = 100; %get from CIETs

%k value & reactivity%
amt_rod_out_test = rodouttest;
k1 = control_rod_worth_constant+control_rod_worth_coeffecient*amt_rod_out_test;
k_test = k1;
amt_rod_out = rodout;
k = control_rod_worth_constant+control_rod_worth_coeffecient*amt_rod_out;
k_rod = k;
rho_T = (Fuel_Feedback*(Tf-Tf_eq)+Coolant_Feedback*(Tc-Tc_eq))/1e6;
rho = (k-1)/k+rho_T;
prev_rho=rho;

s1 = (lambda*rho)/(beta-rho);
s2 = (beta - rho)/(Lambda);
[P] = power_function(P0,dt,rho,rho0,s1,s2,beta);
if P<100
    P = 100;
elseif P>10100
    P = 10100;
end