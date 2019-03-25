function [BasicStats, Outliers, Rates] = BasicStatsAnalysis(data, StepSize)

% This function serves to take in data as column vector
% and return basic statistics including mean, median,
% standard deviation, outliers, range, min, max, rates of change

% Check data length
points = length(data);
if points < 2
    BasicStats = [data,data,0,0,data,data];
    Outliers = NaN;
    Rates = NaN;
else
    % For every step in the data column
    for i = 1:(points/StepSize)
        % Define data step
        Step = data(1 + StepSize*(i-1):StepSize*i);
        % Calculate mean for data step
        BasicMean(i) = mean(Step);
        % Calculate median for data step
        BasicMedian(i) = median(Step);
        % Calculate standard deviation for data step
        BasicStandDev(i) = std(Step);
        % Calculate range for data step
        BasicRange(i) = range(Step);
        % Calculate min for data step
        BasicMin(i) = min(Step);
        % Calculate max for data step
        BasicMax(i) = max(Step);
        % Find outliers for data step
        Outliers(:,i) = Step.*isoutlier(Step);
        % Calculate rate of change for data step
        if points == 1
            Rates(:,i) = NaN;
        else
            Rates(:,i) = diff(Step);
        end
    end
    % Assemble BasicStats output
    BasicStats = [BasicMean',BasicMedian',BasicStandDev',BasicRange',...
        BasicMin',BasicMax'];
end

    



