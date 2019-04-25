function [dx, C] = DiagnosesAndConfusionMatrix(data, residuals)
% DIAGNOSESANDCONFUSIONMATRIX - Compute consistency based diagnoses and 
%                               corresponding confusion matrix based on 
%                               a dataset.
%
%     [dx, C] = DiagnosesAndConfusionMatrix(data [, resIdx])
%
%  Inputs:
%      data:  a struct with fields:
%             - modes Cell-array with names of fault modes, no-fault mode
%                     is always the first
%             - res   a matrix of N x nf samples of residuals
%             - mode  The mode for each of the N samples specified by index 
%                     into the cell array data.modes - 1, e.g., 'NF' 
%                     corresponds to 0.
%             - fsm   A nr x nf fault signature matrix. Rows corresponds 
%                     to the nr residuals and columns to the nf modes.
%     resIdx: Index to which residuals to consider, defaults to all.
%
%  Outputs:
%    dx        - representation of all diagnoses
%    C         - Confusion matrix
%

  if nargin < 2
    residuals = 1:size(data.res, 2);
  end
  dx = SingleFaultIsolation(data.res(:, residuals), ...
                            data.fsm(residuals, :));

  % Confusion matrix computation
  % C(i,j) = P(fj diagnos|fi injected fault)
  nf = numel(data.modes);
  C = zeros(nf,nf);
  for fi = 1:nf
    for fj = 1:nf
      fjIdx = (data.mode==fj-1);    
      C(fj,fi) = sum(dx(fjIdx,fi))/sum(fjIdx);
    end
  end
end
