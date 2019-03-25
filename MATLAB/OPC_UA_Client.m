% Define client and connect to the Main Server
uaClient = opcua('192.168.1.3',49581);
connect(uaClient)

% Obtain a list of available nodes on the server
uaClient.Namespace

% Define nodes in MATLAB
ChatNode = findNodeByName(uaClient.Namespace,'Chat');
BoPDataNode = findNodeByName(uaClient.Namespace,'BoP Data');
DAQDataNode = findNodeByName(uaClient.Namespace,'DAQ Data');
CIETDataNode = findNodeByName(uaClient.Namespace,'CIET Data');
BoPInputsNode = findNodeByName(uaClient.Namespace,'BoP Inputs');
SpoofDataNode = findNodeByName(uaClient.Namespace,'Spoof Data');
BoPOutputsNode = findNodeByName(uaClient.Namespace,'BoP Outputs');
ResultDataNode = findNodeByName(uaClient.Namespace,'Result Data');
ResultCIETDataNode = findNodeByName(uaClient.Namespace,'Result CIET Data');
SpoofedCIETDataNode = findNodeByName(uaClient.Namespace,'Spoofed CIET Data');
BooleanControlNode = findNodeByName(uaClient.Namespace,'Boolean Control Actions');
NumericControlNode = findNodeByName(uaClient.Namespace,'Numeric Control Actions');
ResultBooleanControlNode = findNodeByName(uaClient.Namespace,'Result Boolean Controls');
ResultNumericControlNode = findNodeByName(uaClient.Namespace,'Result Numeric Controls');
SpoofedBooleanControlNode = findNodeByName(uaClient.Namespace,'Spoofed Boolean Controls');
SpoofedNumericControlNode = findNodeByName(uaClient.Namespace,'Spoofed Numeric Controls');

% Read node values
readValue(uaClient,CIETDataNode)

% Write node values
writeValue(uaClient,CIETDataNode,[])

tic;
Log = {};
last = '';
for i = 1:10
    value = readValue(uaClient, chatNode);
    if strcmp(value,last) == false
        Log = [Log, value];
    end
    last = value;
    pause(1-(toc-tic));
end
        

serverNodes = browseNamespace(uaClient)
[val,ts,qual] = readValue(uaClient,serverNodes);
sampleNode = findNodeByName(uaClient.Namespace,'CIET Data')
uaClient.Namespace
chatNode = findNodeByName(uaClient.Namespace, 'Chat')
readValue(uaClient, chatNode)
value = readValue(uaClient, chatNode)

figure(1)
ResultCIETData = [];
for i = 1:10
    ResultCIETData(:,i) = readValue(uaClient,DataNode)';
    pause(1);
    for j = 2:length(ResultCIETData(:,i))
        plot(ResultCIETData(1,:),ResultCIETData(j,:));
        hold on
    end
end
%% Live data collection and plotting example

% Begin plotting live data for each temperature
figure
h = cell(1,52);
for i = 1:52
    h{i} = animatedline;
end
ax = gca;
ax.YGrid = 'on';
ax.YLim = [21.3 21.9];

% Initialize CIETTemps array to collect 10 data points
CIETTemps = zeros(10,52);

elap = 0;

% Begin timer
tic;
% For loop to collect data for 10 seconds
for i = 1:100
    tic
    % Read current values
    CurrentValues = readValue(uaClient,CIETDataNode);
    % Pull out temperatures and assign to CIETTemps
    CIETTemps(i,:) = CurrentValues(2:53)';
    % Add points to animation
    for j = 1:52
        addpoints(h{j},i*0.1,CIETTemps(i,j));
    end
    % Update axes
    ax.XLim = [i*0.1-1 i*0.1];
    drawnow
    % Pause until next second
    pause(0.1-toc);
    % Store elapsed time for testing
    elap = elap + toc;
end
elap

%% On-line statistics example
 
% Initialize TempStats array to collect 10 data points
CIETTemps = zeros(100,52);
TempStats = cell(10,52);
Outliers = cell(10,52);
Rates = cell(10,52);

% For loop to collect data for 10 seconds at 1 Hz
for i = 1:10
    tic
    for j = 1:10
        % Read current values
        CurrentValues = readValue(uaClient,CIETDataNode);
        % Pull out temperatures and assign to CIETTemps
        CIETTemps(j+10*(i-1),:) = CurrentValues(2:53)';
        % Pause until next time step
        pause(0.1 - toc);
    end
    % Calculate basic statistics on the last 10 time steps
    for k = 1:52
        [TempStats{i,k},Outliers{i},Rates{i}] = ...
            BasicStatsAnalysis(CIETTemps((1+10*(i-1)):(10*i),k), 10);
    end
    pause(1 - toc);
end