function [P] = short_term_power(P0,beta,rho,rho0,s2,dt)

drho = rho-rho0;
t = 0:dt:2;
P = P0*(-drho/(beta-rho)*exp(s2*t)); 
