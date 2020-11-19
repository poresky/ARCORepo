function [P] = long_term_power(P0,beta,rho,rho0,s1,dt)

P = P0*((beta-rho0)/(beta-rho)*exp(s1*dt));