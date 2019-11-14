function [P,P_short] = power_function(P0,prev_P_short,dt,rho0,prev_rho0,s1,s2,beta)

if prev_rho0*rho0<0
    prev_rho0=0;
elseif (rho0-prev_rho0)<0 && rho0>=0
    prev_rho0=rho0;
elseif (prev_rho0-rho0)<0 && rho0<=0
    prev_rho0=rho0;
end

drho = rho0-prev_rho0;

%prev_P = P0;
P = long_term_power(P0,beta,rho0,prev_rho0,s1,dt);

prev_P_short(length(prev_P_short)+1)=0;
temp_P_short = short_term_power(P0,beta,rho0,prev_rho0,s2,dt);
P_short = prev_P_short(2:length(prev_P_short))+temp_P_short;