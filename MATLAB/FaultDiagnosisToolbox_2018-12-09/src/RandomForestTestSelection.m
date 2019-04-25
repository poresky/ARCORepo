function [result, C, rf, Crf, oobErr] = RandomForestTestSelection(data, n_estimators)
% RANDOMFORESTTESTSELECTION   Select residuals for fault isolation using 
%                             Random Forests.
% 
%    [result, C, rf, Crf, oobErr] = RandomForestTestSelection(data, n_estimators)
%       
%     Implementation of the residual selection approach described in the
%     paper
% 
%       Frisk, Erik, and Mattias Krysander. "Residual Selection for
%       Consistency Based Diagnosis Using Machine Learning Models."
%       IFAC Safeprocess, Warszaw, Poland (2018)
%       (https://doi.org/10.1016/j.ifacol.2018.09.547)
% 
%     The method computes a sorted list of residuals, where the most important
%     residuals are first in the list. The method also computes performance
%     indices that can be used to determine how many in the sorted list of
%     residuals that should be selected.
% 
%     Parameters
%     ----------
%     data : Struct with data and supporting information needed by the
%            algorithm. The data dictionary must have the following fields:
% 
%            - modes : an array of size m with names of no-fault and fault modes.
%                      The no-fault mode is assumed the first element in the list
%            - res : an (N x n) numpy array with N samples of the n residuals
%            - mode : an integer vector of size N indicating which fault that is
%                     active at each sample. A Value 0 corresponds to fault
%                     free operation.
%            - fsm : a fault signature matrix of size (n x m)
% 
% 
%     n_estimators : Number of decision trees in the ensemble model.
%                    Defaults to 100
%     Returns
%     -------
%     result : A struct containing the resulting test selection.
%              The struct contains the fields
%              - sortidx : A sorted list of indices to residuals with the most
%                          important residuals first.
%              - pfa  : Performance curve for the false alarm probability
%              - pmd  : Performace curve for missed detection
%              - pfi  : Performance curve for fault isolation
%              - pmfi : Maximal isolation performance per fault mode
%              - residualimportance : List of relative residual importance.
%                                     The list is not sorted.
%     C : A confusion matrix when computing consistency based diagnoses using
%         all residuals.
%     rf : The random forest object
%     Crf : The confusion matrix for the random forest classifier.
%     oobErr: Out-of-bag error rate
% 
%     See test selection in the example suite for typical usage.
             
  if nargin < 2
    n_estimators = 100;
  end
  
  [~, C] = DiagnosesAndConfusionMatrix(data);
  
  t = templateTree('PredictorSelection', 'interaction-curvature');

  rf = fitcensemble(single(data.res), data.mode, 'Method', 'bag',...
                     'NumLearningCycles', n_estimators, 'Learners', t);
  
  Y = oobPredict(rf);
  Ival = confusionmat(categorical(data.mode), categorical(Y));
  nf = numel(data.modes);
  Crf = Ival./(sum(Ival, 2)*ones(1, nf));

  importance = oobPermutedPredictorImportance(rf);
  [~, residualRanking] = sort(importance, 'descend');

  isolationerror = zeros(length(residualRanking), 1);
  mean_md = zeros(length(residualRanking), 1);
  fa = zeros(length(residualRanking), 1);
  probabilityMaximumIsolation = zeros(42, numel(data.modes)-1);

  for i = 1:length(residualRanking)
    selected_residuals = residualRanking(1:i); % select the i best residuals
    [mean_md(i), fa(i), isolationerror(i), probabilityMaximumIsolation(i, :)] = ...
      PerformanceEval(data, selected_residuals);
  end

  oobErr = oobLoss(rf, 'mode', 'cumulative');  
  
  result.sortidx = residualRanking;
  result.pfa = fa;
  result.pmd = mean_md;
  result.pfi = isolationerror;
  result.pmfi = probabilityMaximumIsolation;
  result.residualimportance = importance;
end

function [mean_md, fa, fi, pma] = PerformanceEval(data, residuals)
  no_samples = size(data.res, 1); % n 
  no_modes = numel(data.modes);  % m 
  no_of_samples_per_mode = no_samples/no_modes; % k

  structuralIsolationMatrix = ...
    IsolabilityMatrix(data.fsm(:, 2:8), data.modes(2:8));

  stim2 =  sum(((2.^(0:6)).*structuralIsolationMatrix), 2); 
  pma = zeros(1, no_modes-1);


  dx = SingleFaultIsolation(data.res(:, residuals),...
      data.fsm(residuals, :)); % apply CBD.
    
  % Compute for each mode the probability of maximum isolation
  dx2 = sum(((2.^(0:6)).*dx(:, (2:end))), 2);
  for j = 1:no_modes-1 % not NF
      pma(j) = sum(dx2((1:no_of_samples_per_mode)+...
          j*no_of_samples_per_mode)==stim2(j))/no_of_samples_per_mode; 
  end
  % Compute confusion matrix of CBD using the i best residuals
  [~, C] = DiagnosesAndConfusionMatrix(data, residuals);
  
  % Compute performance indicators
  fi = sum(sum(abs(structuralIsolationMatrix-C(2:8,2:8)./((1-C(2:end,1))*ones(1,7)))))/7^2;
  mean_md = mean(C(2:end, 1));
  fa = 1-C(1);
end
