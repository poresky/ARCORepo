function [DRACSStates,DRACSOutState1,TCHXInState1] = DRACSStates(CIETData)
DRACSStates(1) = CIETData.BT63;
DRACSStates(2) = CIETData.WT62;
DRACSStates(3) = CIETData.BT65;
DRACSStates(4) = CIETData.WT64;
DRACSStates(5) = CIETData.AT02;
DRACSOutState1.T2 = mean(DRACSStates(3:4));
TCHXInState1.T1 = mean(DRACSStates(1:2));

