function [CTAHStates,CTAHStates1] = CTAHStates(NumericControls,CIETData)
CTAHStates(1) = NumericControls.CTAHFreq;
CTAHStates(2) = CIETData.WT40;
CTAHStates(3) = CIETData.BT41;
CTAHStates(4) = CIETData.WT42;
CTAHStates(5) = CIETData.BT43;
CTAHStates(6) = CIETData.AT01;
CTAHStates1.TFC = mean(CTAHStates(2:3));
CTAHStates1.TSC = (CTAHStates(2)+CTAHStates(4))/2;
