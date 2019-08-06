function [DRACSStates,DRACSStates1] = DRACSStatesNew(CIETData)
DRACSStates(1) = CIETData.BT63;
DRACSStates(2) = CIETData.WT62;
DRACSStates(3) = CIETData.BT65;
DRACSStates(4) = CIETData.WT64;
DRACSStates(5) = CIETData.AT02;
DRACSStates(6) = CIETData.FM60;
DRACSStates1.T2 = mean(DRACSStates(3:4));
DRACSStates1.T1 = mean(DRACSStates(1:2));
DRACSStates1.Tav = mean([DRACSStates1.T2,DRACSStates1.T2]);

