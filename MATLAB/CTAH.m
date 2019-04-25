%% CTAH structural model
clear
clc

modelDef.type = 'Symbolic';
modelDef.x = {'WT40','BT41','WT42','BT43','AT01',...
    'AT02','dTFC','TinC','TFC','TSC','TFC','dTSC','TSC','TinftyC',...
    'FM40','hinftyC','tauC','omegaC','dTFCbar','TFCbar'};
modelDef.f = {'fC'};
modelDef.z = {'uC','y1','y2','y3','y4','y5','y6'};
modelDef.parameters = {'hFC','AFC','MFC','cpFC','MSC','cpSC','AinftyC',...
    'VFC','omegaCfxn'};

syms(modelDef.x{:})
syms(modelDef.f{:})
syms(modelDef.z{:})
syms(modelDef.parameters{:})

modelDef.rels = {y1==WT40,y2==BT41,y3==WT42,y4==BT43,... % e1,e2,e3,e4
    y5==AT01,y6==AT02,uC==omegaC,hinftyC==omegaCfxn*omegaC + fC,... %e5,e6,e7,e8
    tauC==VFC/FM40,TFC==(BT41+WT40)/2,TinC==(BT43+WT42)/2,... %e9,e10,e11
    TinftyC==(AT01+AT02)/2,... %e12
    dTFC==(hFC*AFC)/(MFC*cpFC)*(TSC-TFC),... %e13
    dTSC==(hFC*AFC)/(MSC*cpSC)*(TFC-TSC)+(hinftyC*AinftyC)/(MSC*cpSC)*(TinftyC-TSC),... %e14
    dTFCbar==(1/tauC)*(TinC-TFC),... %e15
    TFCbar==(TinC+TFC)/2,... %e16
    DiffConstraint('dTFC','TFC'),... %e17
    DiffConstraint('dTSC','TSC'),... %e18
    DiffConstraint('dTFCbar','TFCbar')...
    };
model = DiagnosisModel(modelDef);
model.name = 'CTAH';
%% To plot the model
figure(1)
model.PlotModel();
title('');
%% Detectability analysis
[df,ndf]=model.DetectabilityAnalysis();
%% Isolability analysis
figure(2)
model.IsolabilityAnalysis();
%% Dulmage-Mendelsohn decomposition
figure(3)
model.PlotDM('eqclass',true,'fault',true);
%% Find MTES sets and plot fault signature matrix
mtes=model.MTES();
fsm = model.FSM(mtes);
figure(4)
spy(fsm,30)
set(gca, 'YTick', 1:length(mtes), 'XTick', 1:length(model.f),...
    'YTickLabel', {'MTES1', 'MTES2', 'MTES3','MTES4','MTES5','MTES6',...
    'MTES7','MTES8'},'XTickLabel',model.f,...
    'box', 'off');
xlabel('')
title('')
%% Plot each MTES submodel
mtesModel = cell(1,length(mtes));
for i = 1:length(mtes)
    mtesModel{i} = model.SubModel(mtes{i},1:length(model.x));
    figure(4+i)
    mtesModel{i}.PlotDM('eqclass',true,'fault',true);
    title(['MTES ',num2str(i)])
    total = i;
end
%% Pick out low-index msos
mtesMSO = cell(1,length(mtes));
for i = 1:length(mtes)
    mtesMSOidx = mtesModel{i}.MSO();
    lowidx = cellfun( @(m) mtesModel{i}.IsLowIndex(m), mtesMSOidx);
    lowidxMSO = mtesMSOidx(lowidx);
    for j = 1:length(lowidxMSO)
        mtesMSO{i}{j} = mtes{i}(lowidxMSO{j});
    end
    % Perform isolability analysis for each
    figure(total + 2*i - 1)
    model.IsolabilityAnalysisArrs(mtesMSO{i});
    title(['Isolability for MTES ',num2str(i)])
    fsm = model.FSM(mtesMSO{i});
    figure(total + 2*i)
    spy(fsm,30)
    set(gca, 'YTick', 1:length(mtesMSO{i}), 'XTick', 1:length(model.f),...
    'YTickLabel', {'MSO1', 'MSO2', 'MSO3','MSO4','MSO5','MSO6'},'XTickLabel',model.f,...
    'box', 'off');
    xlabel('Fault')
    ylabel('MSO')
    title(['Fault Signature Matrix for MTES ',num2str(i)])
    total2 = total + 1;
end
%% Clean MSO sets to only include low-index
mtesMSO = mtesMSO(~cellfun('isempty',mtesMSO));
mtesMSOclean = cell(size(mtesMSO));
index = 0;
for i = 1:length(mtesMSO)
    if length(mtesMSO{i}) == 1
        mtesMSOclean(i + index) = mtesMSO{i};
    else
        for j = 1:length(mtesMSO{i})
            mtesMSOclean(i + j - 1) = mtesMSO{i}(j);
            index = index + 1;
        end
    end
end
mtesMSO = mtesMSOclean;
%% Fault signature matrix for low-index MSO sets
fsm = model.FSM(mtesMSO);
figure(total2)
spy(fsm,30)
set(gca, 'YTick', 1:length(mtesMSO), 'XTick', 1:length(model.f),...
    'YTickLabel', {'MSO1','MSO2','MSO3','MSO4'},'XTickLabel',model.f,...
    'box', 'off');
xlabel('')
title('')
%% Find redundant equations for each MSO
RedundEqs = cell(1,length(mtesMSO));
for i = 1:length(mtesMSO)
    for j = 1:length(mtesMSO{i})
        M = mtesMSO{i}{j}; % Set of equations
        PossRedund = zeros(1,length(M));
            for k = 1:length(M)
                M0 = setdiff(M,M(k));
                dm = GetDMParts(model.X(M0,:));
                    if length(dm.M0eqs) ~= length(M0)
                        PossRedund(k) = 0;
                    else
                        PossRedund(k) = 1;
                    end
            end
            if sum(PossRedund) ~= 0
                RedundEqs{i} = [RedundEqs{i} [j find(PossRedund == 1)]];
            end
    end
end
RedundEqs
%% Build residual generator for CTAH fault       
M = mtesMSO{1}; % Set of equations
r = M(6); % Redundant equation
M0 = setdiff(M,r); % Exactly determined part
Gamma = model.Matching(M0); % Compute matching
model.SeqResGen(Gamma,r,'ResGenCTAH_1_6'); % Generate code