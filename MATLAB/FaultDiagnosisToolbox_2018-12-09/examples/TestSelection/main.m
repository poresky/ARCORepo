% This script produces the results shown in:
%
% Code corresponds to the paper "Residual Selection for Consistency Based 
% Diagnosis Using Machine Learning Models" published at 
% IFAC Safeprocess 2018 in Warszaw, Poland. Note that the plots are not 
% identical to the results in the paper where anotherimplementation of the
% machine learning algorithms were used. However, the methodology is the 
% same and the results are similar.
%

clc
clear
close all

%% Load residual data

% The data contains 42 residuals sampled at 10 Hz collected from nominal
% operation and 7 fault modes of a gasoline engine. 

load data.mat
no_residuals = size(data.res, 2);

% data is a struct with fields:
%
% modes: {'NF', 'fp_af', 'fw_af', 'fw_th', 'fyw_af', 'fyp_im', 'fyp_ic',
%        'fyT_ic'} 
%
% res:   a matrix of 2456 samples x 42 residuals 
%
% mode:  The mode for each of the 2456 samples specified by index into 
%        the cell array data.modes - 1, e.g., 'NF' corresponds to 0
%        and 'fp_af' to 1.
%
% fsm:   A 42 x 8 fault signature matrix. Rows corresponds to the 42
%        residuals and columns to the 8 modes.

% Preprocess data and create thresholded residuals
% all residuals are normalised to use threshold 1
thdata = data;
thdata.res = abs(data.res) >= 1;

%% Plot Fig 4: Absolute values of first seven residuals
absdata = data;
absdata.res = abs(data.res);

nf = numel(data.modes);
DS = 1;
figure(10)
for ri = 1:7 % Plot first 7 residuals
  for ii = 1:nf
    subplot(7, 8, ii + (ri-1)*nf)
    idx = find(data.mode == ii-1);
    res = data.res(idx(1:DS:end), ri);
    if data.fsm(ri, ii) == 1
      plot(res, 'r');
    else
      plot(res);
    end
    axis([0, length(res), 0, 3]);
    box off
    if ii == 1
       ylabel(sprintf('res-%d', ri));
    end
    if ri == 7
      xlabel(data.modes{ii}, 'Interpreter', 'none');
    end
  end
end
clear absdata

%% Plot Fig. 5: Probability of residual alarm given a given mode
figure(11)
PlotAlarmProbability(data, 1:no_residuals);

%% Sytructural isolability matrix when using all tests
figure(16);
IsolabilityMatrix(data.fsm(:, 2:end), data.modes(2:end));
title('Structural isolability matrix using all available tests');
ylabel('Injected fault', 'FontWeight', 'bold');
xlabel('Diagnosed fault', 'FontWeight', 'bold');

%% Plot Fig 7: Confusion matrix obtained by consistency-based diagnosis (CBD) using all thresholded residuals
[~, C] = DiagnosesAndConfusionMatrix(thdata);
figure(17);
PlotConfusionMatrix(C, thdata.modes);
title('Fault isolation performance matrix, all 42 residuals');

%% Select residuals using random forest with 200 trees
[result, ~, rf, Crf, oobErr] = RandomForestTestSelection(thdata, 200);

%% Plot Fig 8: Random forest classification performance using all tests on out-of-bag data.
figure(18);
PlotConfusionMatrix(Crf, thdata.modes);
title('OOB classification performance of the random forest classifier');

%% Plot Fig 9: Random forest out-of-bag classification error as a 
%  function of the number of trees.
figure(19);
plot(oobErr, 'LineWidth', 2)
xlabel('Number of grown trees', 'FontWeight', 'bold');
ylabel('Out-of-bag classification error', 'FontWeight', 'bold');
box off

%% Plot Fig 10: Residual importance
figure(20);
plot(result.residualimportance(result.sortidx), 'LineWidth', 2)
xticks(1:length(result.sortidx))
axis([0 43 -0.4 1.6])
set(gca, 'XTickLabel', result.sortidx, 'TickLabelInterpreter', 'none', ...
    'FontSize', 8)
title('Out-of-Bag Permuted Predictor Importance Estimates');
ylabel('Estimates','FontWeight', 'bold');
xlabel('Predictors','FontWeight', 'bold');
box off

%% Plot Fig 11: False alarm probability, mean missed detection probability,
% and aggregated isolation error as a function of selected tests.
figure(21);
plot([result.pmd, result.pfa, result.pfi], 'LineWidth', 2)
hold on
selected_no_of_residuals = [12 14 26 27];
plot(selected_no_of_residuals,result.pfi(selected_no_of_residuals), ...
     'x', 'LineWidth', 2, 'MarkerSize', 8, 'Color', 'k')
hold off
legend('Missed detection probability', 'False alarm probability', ...
       'Fault isolation errors')
xlabel('Number of selected residuals','FontWeight', 'bold')
ylabel('Probability', 'FontWeight', 'bold')
box off

%% Plot Fig 12: Consistency based isolation performance per mode as a 
% function of number of selected residuals.

figure(22);
plot([1-result.pfa, result.pmfi], 'LineWidth', 2)
l = legend(data.modes{1:end});
set(l, 'Interpreter', 'none')
xlabel('Number of selected residuals', 'FontWeight', 'bold')
ylabel('Probability of maximum isolation performance', 'FontWeight', 'bold')
box off

%% Plot Fig 13: Consistency-based diagnosis results for 12 and all residuals
figure(23);
subplot(1, 2, 1)
[~, C12] = DiagnosesAndConfusionMatrix(data, result.sortidx(1:12));
PlotConfusionMatrix(C12, thdata.modes);
title('No of tests: 12'); 

subplot(1, 2, 2)
PlotConfusionMatrix(C, thdata.modes);
title('No of tests: 42'); 
