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

DataNode = findNodeByName(uaClient.Namespace,'Message');
readValue(uaClient,TempNode)
writeValue(uaClient,TempNode,55);
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

    