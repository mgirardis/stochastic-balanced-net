import numpy
import random

#pythran export get_system_parameters(str:str dict,str:str dict)
def get_system_parameters(simParam_dict,paramType_dict):
    N                  = get_param(simParam_dict['N']                  , paramType_dict['N']                  )[0]
    tTrans             = get_param(simParam_dict['tTrans']             , paramType_dict['tTrans']             )[0]
    Tmax               = get_param(simParam_dict['Tmax']               , paramType_dict['Tmax']               )[0]
    VE0                = get_param(simParam_dict['VE0']                , paramType_dict['VE0']                )[1]
    VE0Std             = get_param(simParam_dict['VE0Std']             , paramType_dict['VE0Std']             )[1]
    VI0                = get_param(simParam_dict['VI0']                , paramType_dict['VI0']                )[1]
    VI0Std             = get_param(simParam_dict['VI0Std']             , paramType_dict['VI0Std']             )[1]
    XE0                = get_param(simParam_dict['XE0']                , paramType_dict['XE0']                )[1]
    fXE0               = get_param(simParam_dict['fXE0']               , paramType_dict['fXE0']               )[1]
    XE0Rand            = get_param(simParam_dict['XE0Rand']            , paramType_dict['XE0Rand']            )[3]
    XI0                = get_param(simParam_dict['XI0']                , paramType_dict['XI0']                )[1]
    fXI0               = get_param(simParam_dict['fXI0']               , paramType_dict['fXI0']               )[1]
    XI0Rand            = get_param(simParam_dict['XI0Rand']            , paramType_dict['XI0Rand']            )[3]
    mu                 = get_param(simParam_dict['mu']                 , paramType_dict['mu']                 )[1]
    theta              = get_param(simParam_dict['theta']              , paramType_dict['theta']              )[1]
    J                  = get_param(simParam_dict['J']                  , paramType_dict['J']                  )[1]
    Gamma              = get_param(simParam_dict['Gamma']              , paramType_dict['Gamma']              )[1]
    I                  = get_param(simParam_dict['I']                  , paramType_dict['I']                  )[1]
    Iext               = get_param(simParam_dict['Iext']               , paramType_dict['Iext']               )[1]
    g                  = get_param(simParam_dict['g']                  , paramType_dict['g']                  )[1]
    p                  = get_param(simParam_dict['p']                  , paramType_dict['p']                  )[1]
    q                  = get_param(simParam_dict['q']                  , paramType_dict['q']                  )[1]
    A                  = get_param(simParam_dict['A']                  , paramType_dict['A']                  )[1]
    tauW               = get_param(simParam_dict['tauW']               , paramType_dict['tauW']               )[1]
    uW                 = get_param(simParam_dict['uW']                 , paramType_dict['uW']                 )[1]
    tauT               = get_param(simParam_dict['tauT']               , paramType_dict['tauT']               )[1]
    uT                 = get_param(simParam_dict['uT']                 , paramType_dict['uT']                 )[1]
    saveSpikingData    = get_param(simParam_dict['saveSpikingData']    , paramType_dict['saveSpikingData']    )[3]
    nNeuronsSpk        = get_param(simParam_dict['nNeuronsSpk']        , paramType_dict['nNeuronsSpk']        )[0]
    weightDynType      = get_param(simParam_dict['weightDynType']      , paramType_dict['weightDynType']      )[2]
    rPoisson           = get_param(simParam_dict['rPoisson']           , paramType_dict['rPoisson']           )[1]
    paramCV            = get_param(simParam_dict['paramCV']            , paramType_dict['paramCV']            )[1]
    K                  = get_param(simParam_dict['K']                  , paramType_dict['K']                  )[0]
    writeOnRun         = get_param(simParam_dict['writeOnRun']         , paramType_dict['writeOnRun']         )[3]
    spkFileName        = get_param(simParam_dict['spkFileName']        , paramType_dict['spkFileName']        )[2]
    simType            = get_param(simParam_dict['simType']            , paramType_dict['simType']            )[2]
    exc_only_dynthresh = get_param(simParam_dict['exc_only_dynthresh'] , paramType_dict['exc_only_dynthresh'] )[3]
    paramCV = 0.0
    print(' ... forcing the CV of all parameters to be zero (homogeneous network), since parameter variability is not implemented yet')
    return N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,mu,theta,J,Gamma,I,Iext,\
           g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson,K,paramCV,writeOnRun,spkFileName,simType,\
           exc_only_dynthresh
    #return N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson,K,paramCV,writeOnRun,spkFileName

#pythran export get_param(str,str)
def get_param(v,vtype):
    a = -1
    b = numpy.nan
    c = ''
    d = False
    if 'int' in vtype:
        a = int(v)
    elif 'float' in vtype:
        b = float(v)
    elif 'str' in vtype:
        c = str(v)
    elif 'bool' in vtype:
        d = v.lower() == 'true'
    else:
        raise ValueError('unknown type for v in get_param function from GLNetEISimLib')
    return a,b,c,d

"""
####################################
#################################### 
####################################
#################################### STATIC RANDOM NETWORK SIMULATION
####################################
#################################### 
####################################
"""

#pythran export RunSimulation_GLNetEIRand(str:str dict,str:str dict)
def RunSimulation_GLNetEIRand(simParam_dict,paramType_dict):
    N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,\
        mu,theta,J,Gamma,I,Iext,g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,\
            weightDynType,rPoisson,K,paramCV,writeOnRun,spkFileName,simType,exc_only_dynthresh =  get_system_parameters(simParam_dict,paramType_dict)
    ############### I'll leave it here for later when I implement heterogeneous parameters
    if simType == 'adapt':
        raise ValueError('only adaptive threshold simulations are implemented for random networks, since adaptive weights require heterogeneous W matrix')
    
    ########## determining iterators for neuron states
    GLNetEIRand_E_iter, GLNetEIRand_I_iter = get_RandomNet_neuron_state_iter(simType,exc_only_dynthresh)

    # preparing external stimulus in case of avalanche simulation
    get_external_stimulus,get_stim_neuron_index = get_RandomNet_stimulus_func(simType)

    tauWinv = 1.0 / tauW
    tauTinv = 1.0 / tauT
    pN      = int(p*N)
    qN      = N - pN

    XE0   = float(XE0)
    XI0   = float(XI0)

    N_fl  = float(N)
    pN_fl = float(pN) if pN > 0 else 1.0 # avoids NaN and division by zero
    qN_fl = float(qN) if qN > 0 else 1.0 # avoids NaN and division by zero

    pN_s  = int(p*nNeuronsSpk) # record only pN_s neurons from the excitatory population for raster plot
    qN_s  = nNeuronsSpk - pN_s # record only qN_s neurons from the inhibitory population for raster plot

    KE    = int(numpy.ceil(p * float(K))) # number of excitatory inputs
    KI    = K - KE # number of inhibitory inputs
    KE_fl = float(KE)
    KI_fl = float(KI)

    C = generate_random_net_fixed_number_of_inputs(KE,pN,K,N)
    #W_I = g*J #only constant parameters are implemented
    # this is set inside the set_MF_network_IC function

    P_firing_poisson = PoissonProcess_firingprob(rPoisson)

    # setting initial conditions
    VE,XE,VI,XI,rhoETemp,rhoITemp,thetaE,thetaI,W_I,thetaMean = set_MF_network_IC(pN,qN,g,J,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,theta)
    synapticInput = numpy.array([0.0 for _ in range(N)])

    # forcing a fixed inhibitory synaptic weight
    if 'adaptthresh' in simType:
        A = 0.0
        tauWinv = 0.0
        uW = 0.0

    # running transient time
    if tTrans > 0:
        rhoETemp,rhoITemp,thetaMean,W_I,VE,XE,VI,XI,thetaE,thetaI = run_transient_GLNetEIRand(simType,exc_only_dynthresh,VE,XE,VI,XI,tTrans,rhoETemp,rhoITemp,pN,qN,pN_fl,qN_fl,P_firing_poisson,Iext,mu,theta,Gamma,I,synapticInput,J,W_I,C,KE,K,A,tauTinv,tauWinv,thetaE,thetaI,uT,uW,weightDynType)
    
    # subtracting transient time from total time
    Tmax = Tmax - tTrans 

    # preparing variable for recording spiking data (if needed)
    spkTimeFile = None
    if saveSpikingData and writeOnRun:
        spkTimeFile = open(spkFileName,'w')
        print('*** writing file %s during simulation' % spkFileName)
    spkData,write_spk_time,save_spk_time = get_write_spike_data_functions(spkTimeFile,saveSpikingData,writeOnRun,XE,XI,pN_s,qN_s)

    # running main simulation
    rhoE = numpy.array([0.0 for i in range(Tmax)])
    rhoI = numpy.array([0.0 for i in range(Tmax)])
    #W_I_data = numpy.array([0.0 for i in range(Tmax)]) ############### I'll leave it here for later when I implement heterogeneous parameters
    theta_data = numpy.array([0.0 for i in range(Tmax)])
    rhoE[0] = rhoETemp
    rhoI[0] = rhoITemp
    #W_I_data[0] = W_I ############### I'll leave it here for later when I implement heterogeneous parameters
    theta_data[0] = thetaMean
    for t in range(1,Tmax):
        k       = get_stim_neuron_index(pN_fl)
        XE[k],_ = get_external_stimulus(XE[k],rhoE[t-1],rhoI[t-1],pN_fl)
        #W_I = weightAdapt(W_I,A,tauWinv,uW,rhoE[t-1],rhoI[t-1]) # both the E and I subnetworks receive the same inhibitory adapted input
        sumSynpaticInput_homog(synapticInput,KE,K,N,XE,XI,J,W_I,C) # updates synapticInput variable
        thetaMean = 0.0
        for i in range(pN):
            VE[i],XE[i],thetaE[i] = GLNetEIRand_E_iter(VE[i],XE[i],synapticInput[i],Iext,mu,theta,Gamma,I,P_firing_poisson,tauTinv,uT)
            rhoE[t] += XE[i]
            thetaMean += thetaE[i]
            if (i < pN_s) and XE[i]:
                spkData = save_spk_time(spkData,t,i) #spkData.append((t,i)) #spkData[t][i] = XE[i]
                write_spk_time(t,i)
        for i in range(qN):
            VI[i],XI[i],thetaI[i] = GLNetEIRand_I_iter(VI[i],XI[i],synapticInput[i],Iext,mu,theta,Gamma,I,0.0,tauTinv,uT)
            rhoI[t] += XI[i]
            thetaMean += thetaI[i]
            if (i < qN_s) and XI[i]:
                spkData = save_spk_time(spkData,t,i+pN_s) #spkData.append((t,i+pN_s)) #spkData[t][i+pN_s] = XI[i]
                write_spk_time(t,i+pN_s)
        rhoE[t] = rhoE[t]/pN_fl
        rhoI[t] = rhoI[t]/qN_fl
        #W_I_data[t] = W_I ############### I'll leave it here for later when I implement heterogeneous parameters
        theta_data[t] = thetaMean/N_fl
    # end of time loop
    if saveSpikingData and writeOnRun:
        spkTimeFile.close()
        print('*** closed file %s' % spkFileName)
    return rhoE,rhoI,spkData,numpy.multiply(p*J,rhoE),numpy.multiply(q*g*J,rhoI),(numpy.ones(shape=rhoE.shape)*W_I/J),numpy.divide(I,theta_data)

"""
####################################
#################################### 
####################################
#################################### ADAPTIVE MEAN-FIELD NETWORK SIMULATION
####################################
#################################### 
####################################
"""

#pythran export RunSimulation_GLNetEIMF(str:str dict,str:str dict)
def RunSimulation_GLNetEIMF(simParam_dict,paramType_dict):
    N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,\
        mu,theta,J,Gamma,I,Iext,g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,\
            weightDynType,rPoisson,K,paramCV,writeOnRun,spkFileName,simType,exc_only_dynthresh =  get_system_parameters(simParam_dict,paramType_dict)
    
    # setting the neuron state update function
    GLNetEIMF_E_iter,GLNetEIMF_I_iter = get_MFNet_neuron_state_iter(simType,exc_only_dynthresh)

    # setting the synaptic weight update function
    weightAdapt_iter = get_MFNet_synaptic_weight_iter(weightDynType,simType,q)
    
    # preparing external stimulus in case of avalanche simulation
    get_external_stimulus = get_MFNet_stimulus_func(simType)

    
    # forcing silent initial conditions for aval simulations
    if simType == 'aval':
        print(' ... forcing fXE0 = fXI0 = 0.0 as initial conditions, since simType == aval')
        fXE0 = 0.0
        fXI0 = 0.0
    
    # calculating some params
    tauWinv = 1.0 / tauW
    tauTinv = 1.0 / tauT
    pN      = int(p*N)
    qN      = N - pN

    XE0 = float(XE0)
    XI0 = float(XI0)

    N_fl  = float(N)
    pN_fl = float(pN) if pN > 0 else 1.0 # avoids NaN and division by zero
    qN_fl = float(qN) if qN > 0 else 1.0 # avoids NaN and division by zero

    pN_s = int(p*nNeuronsSpk) # record only pN_s neurons from the excitatory population for raster plot
    qN_s = nNeuronsSpk - pN_s # record only qN_s neurons from the inhibitory population for raster plot

    P_firing_poisson = PoissonProcess_firingprob(rPoisson)

    # setting initial conditions
    # returns W_I = g*J
    VE,XE,VI,XI,rhoETemp,rhoITemp,thetaE,thetaI,W_I,thetaMean     = set_MF_network_IC(pN,qN,g,J,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,theta)

    # running transient time
    if tTrans > 0:
        rhoETemp,rhoITemp,thetaMean,W_I,VE,XE,VI,XI,thetaE,thetaI = run_transient_GLNetEIMF(simType,exc_only_dynthresh,VE,XE,VI,XI,thetaE,thetaI,rhoETemp,rhoITemp,N_fl,pN,qN,pN_fl,qN_fl,P_firing_poisson,weightDynType,tTrans,Iext,mu,J,Gamma,I,p,q,tauTinv,uT,tauWinv,uW,A,W_I)

    # subtracting transient time from total time   
    Tmax = Tmax - tTrans

    # preparing variable for recording spiking data (if needed)
    spkTimeFile = None
    if saveSpikingData and writeOnRun:
        spkTimeFile = open(spkFileName,'w')
        print('*** writing file %s during simulation' % spkFileName)
    spkData,write_spk_time,save_spk_time = get_write_spike_data_functions(spkTimeFile,saveSpikingData,writeOnRun,XE,XI,pN_s,qN_s)

    # running main simulation
    rhoE          = numpy.array([0.0 for i in range(Tmax)])
    rhoI          = numpy.array([0.0 for i in range(Tmax)])
    W_I_data      = numpy.array([0.0 for i in range(Tmax)])
    theta_data    = numpy.array([0.0 for i in range(Tmax)])
    rhoE[0]       = rhoETemp
    rhoI[0]       = rhoITemp
    rhoE_prev     = rhoETemp
    rhoI_prev     = rhoITemp
    W_I_data[0]   = W_I
    theta_data[0] = thetaMean
    for t in range(1,Tmax):
        XE[0],rhoE_prev = get_external_stimulus(XE[0],rhoE_prev,rhoI_prev,pN_fl)
        W_I = weightAdapt_iter(W_I,A,tauWinv,uW,rhoE_prev,rhoI_prev) # both the E and I subnetworks receive the same inhibitory adapted input
        #Iext = 0.0 # stimulus
        thetaMean = 0.0
        for i in range(pN):
            VE[i],XE[i],thetaE[i] = GLNetEIMF_E_iter(VE[i],XE[i],rhoE_prev,rhoI_prev,Iext,mu,thetaE[i],J,Gamma,I,W_I,p,q,tauTinv,uT,P_firing_poisson)
            rhoE[t] += XE[i]
            thetaMean += thetaE[i]
            if (i < pN_s) and XE[i]:
                spkData = save_spk_time(spkData,t,i) #spkData.append((t,i)) #spkData[t][i] = XE[i]
                write_spk_time(t,i)
        for i in range(qN):
            VI[i],XI[i],thetaI[i] = GLNetEIMF_I_iter(VI[i],XI[i],rhoE_prev,rhoI_prev,Iext,mu,thetaI[i],J,Gamma,I,W_I,p,q,tauTinv,uT,0.0)
            rhoI[t] += XI[i]
            thetaMean += thetaI[i]
            if (i < qN_s) and XI[i]:
                spkData = save_spk_time(spkData,t,i+pN_s) #spkData.append((t,i+pN_s)) #spkData[t][i+pN_s] = XI[i]
                write_spk_time(t,i+pN_s)
        rhoE[t] = rhoE[t]/pN_fl
        rhoI[t] = rhoI[t]/qN_fl
        W_I_data[t] = W_I
        theta_data[t] = thetaMean/N_fl
        rhoE_prev = rhoE[t]
        rhoI_prev = rhoI[t]
    # end of time loop
    if saveSpikingData and writeOnRun:
        spkTimeFile.close()
        print('*** closed file %s' % spkFileName)
    return rhoE,rhoI,spkData,numpy.multiply(p*J,rhoE),numpy.multiply(q,numpy.multiply(W_I_data,rhoI)),numpy.divide(W_I_data,J),numpy.divide(I,theta_data)
    #return rhoE,rhoI,spkData,numpy.multiply(p*J,rhoE),(q*numpy.multiply(W_I_data,rhoI)),numpy.divide(W_I_data,J),numpy.divide(I,theta_data)

"""
####################################
#################################### 
####################################
#################################### RANDOM NETWORK SUPPORT FUNCTIONS
####################################
#################################### 
####################################
"""

#pythran export get_stim_neuron_index_aval(float)
def get_stim_neuron_index_aval(pN_fl):
    return int(random.random() * pN_fl)

#pythran export generate_random_net_fixed_input(int,int,int,int)
def generate_random_net_fixed_number_of_inputs(K_ex,pN,K,N):
    """
    ##################
    #BUILD RANDOM NETWORK WITH constant k_in neighbors
    #Neurons cannot have repeated neighbors
    ##################
    returns list C where each entry is the list of neighbor indices:
    C[i] -> list of neighbors of i;
    C[i][:K_ex] -> excitatory neighbors (indices go from 0 to pN); C[i][K_ex:] -> inhibitory neighbors (indices go from 0 to qN)

    K_ex -> number of excitatory inputs
    pN -> total number of excitatory inputs
    K -> total number of inputs
    N -> total number of neurons in the network
    """
    return numpy.array([sorted(random.sample(range(pN),K_ex)) + sorted(random.sample(range(N-pN),K-K_ex)) for _ in range(N)])

#pythran export sumSynpaticInput(float[],int,int,int,float[],float[],float[:,:] order(C),float[:,:] order(C),float[:,:] order(C))
def sumSynpaticInput(synapticInput,K_ex,K,N,XE,XI,J,W,C):
    """
    K_ex -> number of excitatory inputs
    K    -> total number of inputs
    N    -> total number of neurons
    XE   -> state of excitatory neurons
    XI   -> state of inhibitory neurons
    J    -> excitatory synaptic weights (each entry in the outer list is the list of neighbor input excitatory weights)
            J[i] -> list of input excitatory weights for neuron i; contains K_ex entries
    W    -> inhibitory synaptic weights (positively defined; each entry in the outer list is the list of neighbor input inhibitory weights)
            W[i] -> list of input inhibitory weights for neuron i (all positive); contains K-K_ex entries
    C    -> connectivity matrix (each entry in the outer list is the list of neighbor indices)
            C[i] -> list of neighbors of i;
            C[i][:K_ex] -> excitatory neighbors (indices go from 0 to pN-1); C[i][K_ex:] -> inhibitory neighbors (indices go from 0 to N-pN-1)
    """
    for i in range(N):
        s = 0.0
        for j in range(K_ex):
            s += J[i][j] * XE[C[i][j]]
        for j in range(K_ex,K):
            s -= W[i][j-K_ex] * XI[C[i][j]]
        synapticInput[i] = s / float(K)

#pythran export sumSynpaticInput_homog(float[],int,int,int,float[],float[],float,float,float[:,:] order(C))
def sumSynpaticInput_homog(synapticInput,K_ex,K,N,XE,XI,J,W,C):
    """
    K_ex -> number of excitatory inputs
    K    -> total number of inputs
    N    -> total number of neurons
    XE   -> state of excitatory neurons
    XI   -> state of inhibitory neurons
    J    -> excitatory synaptic weights (constant)
    W    -> inhibitory synaptic weights (positive constant)
    C    -> connectivity matrix (each entry in the outer list is the list of neighbor indices)
            C[i] -> list of neighbors of i;
            C[i][:K_ex] -> excitatory neighbors (indices go from 0 to pN-1); C[i][K_ex:] -> inhibitory neighbors (indices go from 0 to N-pN-1)
    """
    for i in range(N):
        sE = 0.0
        sI = 0.0
        for j in range(K_ex):
            sE += XE[C[i][j]]
        for j in range(K_ex,K):
            sI += XI[C[i][j]]
        synapticInput[i] = (J*sE - W*sI) / float(K)

#pythran export run_transient_GLNetEIRand(str,float[],float[],float[],float[],int,float,float,int,int,float,float,float,float,float,float,float,float,float[],float,float,float[:,:] order(C),int,int,float,float,float,float[],float[],float,float,str)
def run_transient_GLNetEIRand(simType,exc_only_dynthresh,VE,XE,VI,XI,tTrans,rhoETemp,rhoITemp,pN,qN,pN_fl,qN_fl,P_firing_poisson,Iext,mu,theta,Gamma,I,synapticInput,J,W_I,C,KE,K,A,tauTinv,tauWinv,thetaE,thetaI,uT,uW,weightDynType):
    # defining functions
    get_external_stimulus,get_stim_neuron_index = get_RandomNet_stimulus_func(simType)
    GLNetEIRand_E_iter, GLNetEIRand_I_iter      = get_RandomNet_neuron_state_iter(simType,exc_only_dynthresh)

    # running simulation
    rhoE_prev = rhoETemp
    rhoI_prev = rhoITemp
    N = len(C)
    for t in range(1,tTrans):
        k               = get_stim_neuron_index(pN_fl)
        XE[k],rhoE_prev = get_external_stimulus(XE[k],rhoE_prev,rhoI_prev,pN_fl)
        #W_I = weightAdapt(W_I,A,tauWinv,uW,rhoE[t-1],rhoI[t-1]) # both the E and I subnetworks receive the same inhibitory adapted input
        sumSynpaticInput_homog(synapticInput,KE,K,N,XE,XI,J,W_I,C) # updates synapticInput variable
        sum_XE = 0.0
        thetaMean = 0.0
        for i in range(pN):
            VE[i],XE[i],thetaE[i] = GLNetEIRand_E_iter(VE[i],XE[i],synapticInput[i],Iext,mu,theta,Gamma,I,P_firing_poisson,tauTinv,uT)
            sum_XE += XE[i]
            thetaMean += thetaE[i]
        sum_XI = 0.0
        for i in range(qN):
            VI[i],XI[i],thetaI[i] = GLNetEIRand_I_iter(VI[i],XI[i],synapticInput[i],Iext,mu,theta,Gamma,I,0.0,tauTinv,uT)
            sum_XI += XI[i]
            thetaMean += thetaI[i]
        rhoE_prev = sum_XE/pN_fl
        rhoI_prev = sum_XI/qN_fl
        thetaMean = thetaMean/(pN_fl + qN_fl)
        
    return rhoE_prev,rhoI_prev,thetaMean,W_I,VE,XE,VI,XI,thetaE,thetaI

"""
####################################
#################################### 
####################################
#################################### MEAN-FIELD SUPPORT FUNCTIONS
####################################
#################################### 
####################################
"""

#pythran export run_transient_GLNetEIMF(str,float[],float[],float[],float[],float[],float[],float,float,float,int,int,float,float,float,str,int,float,float,float,float,float,float,float,float,float,float,float,float,float)
def run_transient_GLNetEIMF(simType,exc_only_dynthresh,VE,XE,VI,XI,thetaE,thetaI,rhoETemp,rhoITemp,N_fl,pN,qN,pN_fl,qN_fl,P_firing_poisson,weightDynType,tTrans,Iext,mu,J,Gamma,I,p,q,tauTinv,uT,tauWinv,uW,A,W_I):
    # defining functions
    get_external_stimulus             = get_MFNet_stimulus_func(simType)
    GLNetEIMF_E_iter,GLNetEIMF_I_iter = get_MFNet_neuron_state_iter(simType,exc_only_dynthresh)
    weightAdapt_iter                  = get_MFNet_synaptic_weight_iter(weightDynType,simType,q)

    # running simulations
    rhoE_prev = rhoETemp
    rhoI_prev = rhoITemp
    thetaMean = 0.0
    for t in range(1,tTrans):
        XE[0],rhoE_prev = get_external_stimulus(XE[0],rhoE_prev,rhoI_prev,pN_fl)
        W_I = weightAdapt_iter(W_I,A,tauWinv,uW,rhoE_prev,rhoI_prev) # both the E and I subnetworks receive the same inhibitory adapted input
        sum_XE = 0.0
        sum_XI = 0.0
        #Iext = 0.0 # stimulus
        thetaMean = 0.0
        for i in range(pN):
            VE[i],XE[i],thetaE[i] = GLNetEIMF_E_iter(VE[i],XE[i],rhoE_prev,rhoI_prev,Iext,mu,thetaE[i],J,Gamma,I,W_I,p,q,tauTinv,uT,P_firing_poisson)
            sum_XE += XE[i]
            thetaMean += thetaE[i]
        for i in range(qN):
            VI[i],XI[i],thetaI[i] = GLNetEIMF_I_iter(VI[i],XI[i],rhoE_prev,rhoI_prev,Iext,mu,thetaI[i],J,Gamma,I,W_I,p,q,tauTinv,uT,0.0)
            sum_XI += XI[i]
            thetaMean += thetaI[i]
        rhoE_prev = sum_XE/pN_fl
        rhoI_prev = sum_XI/qN_fl
        thetaMean = thetaMean/N_fl
    return rhoE_prev,rhoI_prev,thetaMean,W_I,VE,XE,VI,XI,thetaE,thetaI

##-
"""
####################################
#################################### 
####################################
#################################### SIMULATION SUPPORT FUNCTIONS
####################################
#################################### 
####################################
"""

def get_write_spike_data_functions(spkTimeFile,saveSpikingData,writeOnRun,XE,XI,pN_s,qN_s):
    if saveSpikingData:
        if writeOnRun:
            spkData        = [(0,0)]
            write_spk_time = lambda t_ind,k_ind: spkTimeFile.write(str(t_ind) + ',' + str(k_ind) + '\n')
            save_spk_time  = save_spk_data_fake
        else:
            write_spk_time = write_spk_data_fake
            save_spk_time  = save_spk_data
            spkData        = save_initial_spkdata(XE,XI,pN_s,qN_s) # spkData is a list of tuples with spike time stemps [(t#,neuron#),(t2$,neuron#),...]
    else:
        save_spk_time  = save_spk_data_fake
        write_spk_time = write_spk_data_fake
        spkData        = [(0,0)]
    return spkData,write_spk_time,save_spk_time

def get_RandomNet_neuron_state_iter(simType,exc_only_dynthresh):
    print(' ... choosing neuron wiht: ')
    if 'adaptthresh' in simType:
        if 'threshlinear' in simType:
            print(' ....... LINEAR adaptive threshold (additive noise)')
            GLNetEIRand_E_iter = GLNetEIRand_adaptthreshlinear_iter
            GLNetEIRand_I_iter = GLNetEIRand_adaptthreshlinear_iter
        elif 'threshsaturate' in simType:
            print(' ....... SATURATING adaptive threshold (saturating multiplicative noise)')
            GLNetEIRand_E_iter = GLNetEIRand_adaptthreshsaturate_iter
            GLNetEIRand_I_iter = GLNetEIRand_adaptthreshsaturate_iter
        else:
            print(' ....... NONLINEAR adaptive threshold (multiplicative noise)')
            GLNetEIRand_E_iter = GLNetEIRand_adaptthresh_iter
            GLNetEIRand_I_iter = GLNetEIRand_adaptthresh_iter
        if exc_only_dynthresh:
            print(' ....... INHIBITORY neurons will not adapt thresholds!')
            GLNetEIRand_I_iter = GLNetEIRand_static_iter
    else:
        print(' ....... neurons will not adapt thresholds!')
        GLNetEIRand_E_iter = GLNetEIRand_static_iter
        GLNetEIRand_I_iter = GLNetEIRand_static_iter
    return GLNetEIRand_E_iter,GLNetEIRand_I_iter

def get_RandomNet_stimulus_func(simType):
    if simType == 'aval':
        get_external_stimulus = get_external_stimulus_aval
        get_stim_neuron_index = get_stim_neuron_index_aval
    else:
        get_external_stimulus = get_external_stimulus_dynamic
        get_stim_neuron_index = lambda _: 0
    return get_external_stimulus,get_stim_neuron_index

def get_MFNet_neuron_state_iter(simType,exc_only_dynthresh):
    print(' ... choosing neuron wiht: ')
    if 'adapt' in simType:
        if 'threshlinear' in simType:
            print(' ....... LINEAR adaptive threshold (additive noise)')
            GLNetEIMF_E_iter = GLNetEIMF_adaptthreshlinear_iter
            GLNetEIMF_I_iter = GLNetEIMF_adaptthreshlinear_iter
        elif 'threshsaturate' in simType:
            print(' ....... SATURATING adaptive threshold (saturating multiplicative noise)')
            GLNetEIMF_E_iter = GLNetEIMF_adaptthreshsaturate_iter
            GLNetEIMF_I_iter = GLNetEIMF_adaptthreshsaturate_iter
        else:
            print(' ....... NONLINEAR adaptive threshold (multiplicative noise)')
            GLNetEIMF_E_iter = GLNetEIMF_adaptthresh_iter
            GLNetEIMF_I_iter = GLNetEIMF_adaptthresh_iter
        if exc_only_dynthresh:
            print(' ....... INHIBITORY neurons will not adapt thresholds!')
            GLNetEIMF_I_iter = GLNetEIMF_static_iter
    else:
        print(' ....... neurons will not adapt thresholds!')
        GLNetEIMF_E_iter = GLNetEIMF_static_iter
        GLNetEIMF_I_iter = GLNetEIMF_static_iter
    return GLNetEIMF_E_iter,GLNetEIMF_I_iter

def get_MFNet_synaptic_weight_iter(weightDynType,simType,q):
    if weightDynType == "simple":
        weightAdapt_iter = weightAdapt_decrease
    elif weightDynType == "coupled":
        weightAdapt_iter = weightAdapt_increase
    elif weightDynType == "none":
        weightAdapt_iter = weightAdapt_constant
    else:
        raise ValueError('weightDynType is unknown')
    if q == 0.0:
        weightAdapt_iter = lambda W,A,tauWinv,uW,rhoE,rhoI: 0.0
    # forcing a fixed inhibitory synaptic weight
    if 'adaptthresh' in simType:
        print(' ... forcing constant inhibitory W because simType == adaptthresh')
        weightAdapt_iter = weightAdapt_constant
    return weightAdapt_iter

def get_MFNet_stimulus_func(simType):
    if simType == 'aval':
        get_external_stimulus = get_external_stimulus_aval
    else:
        get_external_stimulus = get_external_stimulus_dynamic
    return get_external_stimulus

#pythran export get_external_stimulus_dynamic(float,float,float,float)
def get_external_stimulus_dynamic(XE,rhoE,rhoI,pN_fl):
    return XE,rhoE

#pythran export get_external_stimulus_aval(float,float,float,float)
def get_external_stimulus_aval(XE,rhoE,rhoI,pN_fl):
    if (rhoE + rhoI) < 1e-16:  # causes a spike in an excitatory neuron if the activity is less than the floating-point double precision
        return 1.0, 1.0 / pN_fl
    else:
        return XE,rhoE

#pythran export save_initial_spkdata(float[],float[],int,int)
def save_initial_spkdata(XE,XI,pN,qN):
    """
    spkData = [[0 for i in range(nNeuronsSpk)] for t in range(Tmax)]
    spkData[0] = XE[:pN_s] + XI[:qN_s]
     spkData is a list of tuples
     where each tuple records (time step, neuron index) for each firing
     the pythran breaks with the line below, probably due to enumerate and conditional for loop
    spkData = [ [0,i] for i,x in enumerate(XE[:pN_s]) if x == 1 ] + [ [0,i+pN_s] for i,x in enumerate(XI[:qN_s]) if x == 1 ]
    """
    spkData = []
    i = 0
    while i < pN:
        if XE[i] > 0.5:
            spkData = save_spk_data(spkData,0,i)
        i+=1
    i = 0
    while i < qN:
        if XI[i] > 0.5:
            spkData = save_spk_data(spkData,0,i+pN)
        i+=1
    return spkData

def get_random_inhibitory_weights(W_I,C):
    """
    W_I -> average inhibitory weights
    C   -> connectivity matrix
    """
    return W_I

#pythran export set_MF_network_IC(int,int,float,float,float,float,float,float,float,float,bool,float,float,bool,float)
def set_MF_network_IC(pN,qN,g,J,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,theta):
    VE0    = theta if VE0 == 0.0 else VE0
    thetaE = numpy.array([theta for i in range(pN)])
    XE     = generate_IC_spikes(XE0,pN,int(fXE0*pN),'excitatory',XE0Rand)
    VE     = [abs(random.gauss(VE0,VE0Std)) for i in range(pN)]
    VE     = numpy.array([ (0.0 if x >= 0.5 else v) for x,v in zip(XE,VE) ],dtype=float)
    #for i in range(pN):
    #    VE[i] = 0.0 if XE[i] >= 0.5 else VE[i]

    VI0    = theta if VI0 == 0.0 else VI0
    thetaI = numpy.array([theta for i in range(qN)])
    XI     = generate_IC_spikes(XI0,qN,int(fXI0*qN),'inhibitory',XI0Rand)
    VI     = [abs(random.gauss(VI0,VI0Std)) for i in range(qN)]
    VI     = numpy.array([ (0.0 if x >= 0.5 else v) for x,v in zip(XI,VI) ],dtype=float)
    #for i in range(qN):
    #    VI[i] = 0.0 if XI[i] >= 0.5 else VI[i]

    rhoE0     = float(sum(XE))/(float(pN) if pN > 0 else 1.0)
    rhoI0     = float(sum(XI))/(float(qN) if qN > 0 else 1.0)
    W_I       = g*J
    thetaMean = theta
    return VE,XE,VI,XI,rhoE0,rhoI0,thetaE,thetaI,W_I,thetaMean

#pythran export generate_IC_spikes(float,int,int,str,bool)
def generate_IC_spikes(X0,N,K,neuronType,is_random):
    """generates a list X of zeros with len N containing K ones
    """
    X0 = float(X0>=0.5) # x0 can only be 1 or 0
    if K == 0:
        if (X0 < 0.5):
            print(' ... %s IC: starting from the absorbing state (all inactive neurons) because fX0 = 0.0 and X0 = 0.0'%(neuronType))
            X = numpy.zeros(N)
        else:
            print(' ... %s IC: starting from all active neurons'%(neuronType))
            X = numpy.ones(N)
    else: #(X0 >= 0.5) and is_random:
        print(' ... %s IC: starting with %d %s active neurons regardless of X0'%(neuronType,K,'random' if is_random else 'sequential'))
        X = numpy.zeros(N)
        if is_random:
            start_activity_idx = random.sample(range(N),K)
        else:
            start_activity_idx = list(range(K))
        for k in start_activity_idx:
            X[k] = 1.0
    return X

"""
####################################
#################################### 
####################################
#################################### INTERNAL DYNAMICS OF THE SYSTEM
####################################
#################################### 
####################################
"""

#pythran export GLNetEIRand_adaptthresh_iter(float, float, float, float, float, float, float, float, float, float, float)
def GLNetEIRand_adaptthresh_iter(V,X,synapticInput,Iext,mu,theta,Gamma,I,P_poisson,tauTinv,uT):
    theta = theta * (1.0 - tauTinv + uT*X)
    V     = (mu*V + I + Iext + synapticInput)*(1.0-X)
    X     = float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export GLNetEIRand_adaptthreshlinear_iter(float, float, float, float, float, float, float, float, float, float, float)
def GLNetEIRand_adaptthreshlinear_iter(V,X,synapticInput,Iext,mu,theta,Gamma,I,P_poisson,tauTinv,uT):
    theta = theta * (1.0 - tauTinv) + uT*X
    V     = (mu*V + I + Iext + synapticInput)*(1.0-X)
    X     = float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export GLNetEIRand_adaptthreshsaturate_iter(float, float, float, float, float, float, float, float, float, float, float)
def GLNetEIRand_adaptthreshsaturate_iter(V,X,synapticInput,Iext,mu,theta,Gamma,I,P_poisson,tauTinv,uT):
    theta = min(theta * (1.0 - tauTinv + uT*X),uT/tauTinv)
    V     = (mu*V + I + Iext + synapticInput)*(1.0-X)
    X     = float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export GLNetEIRand_static_iter(float, float, float, float, float, float, float, float, float, float, float)
def GLNetEIRand_static_iter(V,X,synapticInput,Iext,mu,theta,Gamma,I,P_poisson,tauTinv,uT):
    V = (mu*V + I + Iext + synapticInput)*(1.0-X)
    X = float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export GLNetEIMF_adaptthresh_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
def GLNetEIMF_adaptthresh_iter(V,X,rhoE,rhoI,Iext,mu,theta,J,Gamma,I,W_I,p,q,tauTinv,uT,P_poisson):
    theta = theta * (1.0 - tauTinv + uT*X)
    V     = (mu*V + I + Iext + J*p*rhoE - q*W_I*rhoI)*(1.0-X)
    X     = float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export GLNetEIMF_adaptthreshsaturate_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
def GLNetEIMF_adaptthreshsaturate_iter(V,X,rhoE,rhoI,Iext,mu,theta,J,Gamma,I,W_I,p,q,tauTinv,uT,P_poisson):
    theta = min(theta * (1.0 - tauTinv + uT*X),uT/tauTinv)
    V     = (mu*V + I + Iext + J*p*rhoE - q*W_I*rhoI)*(1.0-X)
    X     = float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export GLNetEIMF_adaptthreshlinear_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
def GLNetEIMF_adaptthreshlinear_iter(V,X,rhoE,rhoI,Iext,mu,theta,J,Gamma,I,W_I,p,q,tauTinv,uT,P_poisson):
    theta = theta * (1.0 - tauTinv) + uT*X
    V     = (mu*V + I + Iext + J*p*rhoE - q*W_I*rhoI)*(1.0-X)
    X     = float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export GLNetEIMF_static_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
def GLNetEIMF_static_iter(V,X,rhoE,rhoI,Iext,mu,theta,J,Gamma,I,gJ,p,q,tauTinv,uT,P_poisson):
    V = (mu*V + I + Iext + J*p*rhoE - q*gJ*rhoI)*(1.0-X)
    X = float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export weightAdapt_constant(float, float, float, float, float, float)
def weightAdapt_constant(W,A,tauWinv,uW,rhoE,rhoI):
    return W

#pythran export weightAdapt_decrease(float, float, float, float, float, float)
def weightAdapt_decrease(W,A,tauWinv,uW,rhoE,rhoI):
    return W * (1.0 - tauWinv - uW*rhoI) + tauWinv * A

#pythran export weightAdapt_increase(float, float, float, float, float, float)
def weightAdapt_increase(W,A,tauWinv,uW,rhoE,rhoI):
    return W * (1.0 - tauWinv + uW*rhoE) + tauWinv * A

#pythran export PHI(float, float, float)
def PHI(V,theta,Gamma):
    tg = theta+1.0/Gamma
    return Gamma*(V-theta)*float(V>theta)*float(V<tg)+float(V>=tg)

"""
####################################
#################################### 
####################################
#################################### SUPPORT FUNCTIONS
####################################
#################################### 
####################################
"""

#pythran export multvecelem(float list, float list)
def multvecelem(x,y):
    return [x[i]*yy for i,yy in enumerate(y)]

#pythran export PoissonProcess_firingprob(float)
def PoissonProcess_firingprob(r):
    return 1.0-numpy.exp(-r) # probability of firing is constant

#pythran export save_spk_data_fake((int,int) list,int,int)
def save_spk_data_fake(s,t,k):
    return s

#pythran export save_spk_data((int,int) list,int,int)
def save_spk_data(s,t,k):
    # s -> list to append t_k
    # t -> spike time index
    # k -> neuron index that fired at t
    s.append((t,k))
    return s

#pythran export write_spk_data_fake(int,int)
def write_spk_data_fake(t,k):
    return None

