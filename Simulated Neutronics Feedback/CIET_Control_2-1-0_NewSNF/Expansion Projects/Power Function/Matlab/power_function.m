function [P] = power_function(P0,dt,rho0,prev_rho0,s1,s2,beta)


drho = rho0-prev_rho0;

%prev_P = P0;
P_long = long_term_power(P0,beta,rho0,prev_rho0,s1,dt);

P_short = 0;%short_term_power(P0,beta,rho0,drho,s2,dt);

P=P_long+P_short;