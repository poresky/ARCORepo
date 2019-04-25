%% CIET Heater structural model
clear
clc

modelDef.type = 'Symbolic';
modelDef.x = {'CX101','CX102','CX103','CX104','CX111',...
    'CX112','CX113','CX114','WT10','BT11','ST14E','ST14W','ST14N','PH',...
    'FM40','dTFH','tauH','TinH','TFH','TSH','dTSH','TFHbar','dTFHbar'};
modelDef.f = {'fH','fFM40'};
modelDef.z = {'uH','y1','y2','y3','y4','y5','y6','y7','y8','y9','y10',...
    'y11','y12','y13','y14'};
modelDef.parameters = {'hSH','ASH','MFH','cpFH','MSH','cpSH','VFH'};

syms(modelDef.x{:})
syms(modelDef.f{:})
syms(modelDef.z{:})
syms(modelDef.parameters{:})

modelDef.rels = {y1==CX101,y2==CX102,y3==CX103,y4==CX104,... % e1,e2,e3,e4
    y5==CX111,y6==CX112,y7==CX113,y8==CX114,... %e5,e6,e7,e8
    y9==WT10,y10==BT11,y11==ST14E,y12==ST14W,... %e9,e10,e11,e12
    y13==ST14N, y14==FM40 + fFM40,uH==PH,... %e13,e14,e15
    dTFH==(hSH*ASH)/(MFH*cpFH)*(TSH-TFH),... %e16
    dTSH==(hSH*ASH)/(MSH*cpSH)*(TFH-TSH) + PH/(MSH*cpSH) + fH,... %e17
    tauH==VFH/FM40,... %e18
    DiffConstraint('dTFH','TFH'),... %e19
    DiffConstraint('dTSH','TSH'),... %e20
    TFH==(CX101+CX102+CX103+CX104+CX111+CX112+CX113+CX114)/8,... %e21
    TSH==(ST14E+ST14W+ST14N)/3,... %e22
    TinH==(WT10+BT11)/2,... %e23
    dTFHbar==(1/tauH)*(TinH - TFH),... %e24
    TFHbar==(TinH + TFH)/2,... %e25
    DiffConstraint('dTFHbar','TFHbar')... %e26
    };
model = DiagnosisModel(modelDef);
model.name = 'CIETheater';
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
xtickangle(45)
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
%% Find MTES sets
mtes=model.MTES();

% Extract submodels and find corresponding low-index msos for each MTES
mtesModel = cell(1,length(mtes));
mtesMSO = cell(1,length(mtes));
for i = 1:length(mtes)
    mtesModel{i} = model.SubModel(mtes{i},1:length(model.x));
    %mtesMSO{i} = mtesModel{i}.MSO();
    mtesMSOidx = mtesModel{i}.MSO();
    lowidx = cellfun( @(m) mtesModel{i}.IsLowIndex(m), mtesMSOidx);
    lowidxMSO = mtesMSOidx(lowidx);
    for j = 1:length(lowidxMSO)
        mtesMSO{i}{j} = mtes{i}(lowidxMSO{j});
    end    
    % Perform isolability analysis for each
    figure(2 + 2*i)
    model.IsolabilityAnalysisArrs(mtesMSO{i});
    title(['Isolability for MTES ',num2str(i)])
    fsm = model.FSM(mtesMSO{i});
    figure(3 + 2*i)
    spy(fsm,30)
    set(gca, 'YTick', 1:length(mtesMSO{i}), 'XTick', 1:length(model.f),...
    'YTickLabel', {'MSO1', 'MSO2', 'MSO3','MSO4','MSO5','MSO6'},'XTickLabel',model.f,...
    'box', 'off');
    xlabel('Fault')
    ylabel('MSO')
    title(['Fault Signature Matrix for MTES ',num2str(i)])
end
%% Find redundant equations for each MSO
RedundEqs = cell(size(mtesMSO));
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
                RedundEqs{i}{j} = find(PossRedund == 1);
            end
    end
end
RedundEqs
%% Build residual generator for heater fault       
M = mtesMSO{1}; % Set of equations
r = M(6); % Redundant equation
M0 = setdiff(M,r); % Exactly determined part
Gamma = model.Matching(M0); % Compute matching
model.SeqResGen(Gamma,r,'ResGenCIETHeater_1_6'); % Generate code
%% Build first residual generator for flow meter fault
M = mtesMSO{2}; % Set of equations
r = M(6); % Redundant equation
M0 = setdiff(M,r); % Exactly determined part
Gamma = model.Matching(M0); % Compute matching
model.SeqResGen(Gamma,r,'ResGenCIETFM40_1_6','language','C'); % Generate code
mex ResGenCIETFM40_1_6.cc % Compile
%% Build second residual generator for flow meter fault
M = mtesMSO{4}; % Set of equations
r = M(11); % Redundant equation
M0 = setdiff(M,r); % Exactly determined part
Gamma = model.Matching(M0); % Compute matching
model.SeqResGen(Gamma,r,'ResGenCIETFM40_4_11','language','C'); % Generate code
mex ResGenCIETFM40_4_11.cc % Compile
