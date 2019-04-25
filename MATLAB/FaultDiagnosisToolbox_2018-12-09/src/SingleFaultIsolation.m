function isol = SingleFaultIsolation(res, FSM)
  N = size(res, 1);
  nf = size(FSM, 2);
  
  isol = zeros(N, nf);
  for k=1:N
    alarms = abs(res(k, :)) >= 1;
    if any(alarms)
      isol(k, :) = all(FSM(alarms, :), 1);
    else
      isol(k, :) = [true boolean(zeros(1, nf-1))];
    end
  end
end
