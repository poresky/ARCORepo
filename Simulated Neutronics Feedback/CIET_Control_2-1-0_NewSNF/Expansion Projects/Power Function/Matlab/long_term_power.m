 function [P] = long_term_power(P0,beta,rho,rho0,s1,dt)
if rho0*rho<0
    rho0=0;
elseif (rho-rho0)<0 && rho>=0
    rho0=rho;
elseif (rho0-rho)<0 && rho<=0
    rho0=rho;
end
P = P0*((beta-rho0)/(beta-rho)*exp(s1*dt));