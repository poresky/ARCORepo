function PlotAlarmProbability(data, resIdx)

  nf = numel(data.modes);

  ts = zeros(length(resIdx), nf);
  for m = 1:nf
    for r=1:length(resIdx)        
      ts(r, m) = sum(abs(data.res(data.mode == m-1,resIdx(r)))>=1)/...
                 sum(data.mode == m-1);
    end
  end

  b = bar3(ts);
  for k = 1:length(b)
    zdata = b(k).ZData;
    b(k).CData = zdata;
    b(k).FaceColor = 'interp';
  end
  colormap('Summer')
  set(gca, 'XTickLabel', data.modes, 'TickLabelInterpreter', 'none')
  xlabel('modes')
  ylabel('residuals')
  zlabel('alarm probability')
  view(-65,45)
end

