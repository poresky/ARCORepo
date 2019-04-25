function PlotConfusionMatrix(C, modes)
% PLOTCONFUSIONMATRIX  Plot confusion matrix
%
% Helper function to plot confusion matrix
%
%     PlotConfusionMatrix(C, modes)
% 
%  Inputs:
%    C      - Confusion matrix
%    modes  - Names of fault modes
%

  nf = numel(modes);
  b = bar3(C);
  set(gca, 'XTickLabel', modes, 'TickLabelInterpreter', 'none')
  set(gca, 'YTickLabel', modes, 'TickLabelInterpreter', 'none')
  xlabel('Diagnosed fault', 'FontWeight', 'bold');
  ylabel('Injected fault', 'FontWeight', 'bold');
  zlabel('P(fi diag|fj)');
  title('Fault Isolation Performance Matrix')

  for finjIdx=1:nf
    for fdiagIdx=1:nf
      text(fdiagIdx,finjIdx,C(finjIdx,fdiagIdx)+0.05,...
        sprintf('%.1f',C(finjIdx,fdiagIdx)*100),'HorizontalAlignment', 'center')
    end
  end
  for k = 1:length(b)
      zdata = b(k).ZData;
      b(k).CData = zdata;
      b(k).FaceColor = 'interp';
  end
  colormap('Summer')
  view(0,90)
end
