function [k] = control_rod_drop(hard_drop,medium_drop,soft_drop, control_rod_worth_constant, control_rod_worth_coeffecient)

amt_rod_in=hard_drop/100+medium_drop/10000+soft_drop/1000000;
k=control_rod_worth_constant+control_rod_worth_coeffecient*amt_rod_in;
