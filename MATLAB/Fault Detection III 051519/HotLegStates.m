function [HotLegStates,HeaterOutState1,CTAHInState1] = HotLegStates(CIETData)
HotLegStates(1) = CIETData.BT12;
HotLegStates(2) = CIETData.WT13;
HotLegStates(3) = CIETData.BT43;
HotLegStates(4) = CIETData.WT42;
HotLegStates(5) = CIETData.AT02;
HeaterOutState1.T1 = mean(HotLegStates(1:2));
CTAHInState1.T2 = mean(HotLegStates(3:4));

