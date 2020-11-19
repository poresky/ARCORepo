function [Vrod,Vscram,delta,on,reset,rodouttest,rodout] = read2(V,time,scram,fraction)

%draft2
%%%%%%%%%%Scram mechanism%%%%%%%%%
Vscram = [V(1,1);V(2,1)];
reset = V(4,1);
% Movers have to wait for initiators
if Vscram(1,1) == 0 || time == false
    Vscram(2,1) = 0;
end
% Accuracy
delta = abs(Vscram(1,1)-Vscram(2,1));
if delta >= 0.1 || time == false
    Vscram = zeros(2,1);
end
% Scram on
on = Vscram(2,1) == 1;
%%%%%%%%%%%Control rods%%%%%%%%%%%
if scram == false
    Vrod = [zeros(1,3);V(1:3,6:8)];  
else
    Vrod = zeros(4,3);
end
% Hard
hd_rod1 = Vrod(2,1);
hd_rod2 = Vrod(3,1);
hd_rod3 = Vrod(4,1);
Vrod(1,1) = mean([hd_rod1,hd_rod2,hd_rod3]);
hd_drop = Vrod(1,1)*100;
% Medium
md_rod1 = Vrod(2,2);
md_rod2 = Vrod(3,2);
md_rod3 = Vrod(4,2);
Vrod(1,2) = mean([md_rod1,md_rod2,md_rod3]);
md_drop = Vrod(1,2)*100;
% Soft
sf_rod1 = Vrod(2,3);
sf_rod2 = Vrod(3,3);
sf_rod3 = Vrod(4,3);
Vrod(1,3) = mean([sf_rod1,sf_rod2,sf_rod3]);
sf_drop = Vrod(1,3)*100;
%%%%%%%Amount Rod Out%%%%%%%
rodouttest = hd_drop/1e2+md_drop/1e4+sf_drop/1e6;
if fraction > rodouttest
    rodout = rodouttest;
else
    rodout = fraction;
end