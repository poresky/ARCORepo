uaClient = opcua('192.168.1.3',49581);
connect(uaClient)
TempNode = findNodeByName(uaClient.Namespace,'Message');
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