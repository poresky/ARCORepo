function [HotLegStates,HotLegStates1] = HotLegStatesNew(CIETData)
HotLegStates(1) = CIETData.BT12;
HotLegStates(2) = CIETData.WT13;
HotLegStates(3) = CIETData.BT43;
HotLegStates(4) = CIETData.WT42;
HotLegStates(5) = CIETData.AT02;
HotLegStates(6) = CIETData.FM40;
HotLegStates1.T1 = mean(HotLegStates(1:2));
HotLegStates1.T2 = mean(HotLegStates(3:4));
HotLegStates1.Tav = mean([HotLegStates1.T1,HotLegStates1.T2]);

