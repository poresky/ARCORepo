function im = IsolabilityMatrix(fsm, f)
% IsolabilityMatrix  Compute single fault isolability analysis of a Fault Signature Matrix (FSM)
%
%    im = IsolabilityMatrix(fsm[, f])  
%
%  With no output arguments, then the command plots the isolability
%  analysis results.
%
%  Inputs:
%    fsm     - Fault signature matrix
%    f       - Cell array with fault names (only needed for plotting)
%  
%  Outputs:
%    im       - Isolability matrix, im(i,j)=1 if fault i can be isolated
%               from fault j, 0 otherwise
%
  % Compute isolability matrix
  if nargin < 2
    f = [];
  end
  
  nf = size(fsm,2);
  nr = size(fsm,1);
  im = ones(nf, nf);
  
  for k=1:nr
    im(fsm(k,:)>0,fsm(k,:)==0)=0;
  end

  % Plot
  if nargout==0
    p = 1:nf;
    q = p;
    
    spy(im(p,q), 40)
    set(gca,'XTick', 1:nf);
    set(gca,'YTick', 1:nf);
    if verLessThan('matlab', '8.4') && numel(f) > 0
      set(gca,'XTickLabel', f(p));
      set(gca,'YTickLabel', f(p));
    elseif numel(f) > 0
      set(gca,'XTickLabel', f(p), 'TickLabelInterpreter','none');
      set(gca,'YTickLabel', f(p), 'TickLabelInterpreter','none');
    end
    xlabel('')
  end
end
