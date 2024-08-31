import math
import numpy
import random
from numba import njit,jit,types
from numba.typed import Dict

def convert_simParam_to_numba_dict(simParam_dict,paramType_dict):
    simParam_dict_numba      = Dict.empty(key_type=types.unicode_type,value_type=types.unicode_type)
    simParamTypes_dict_numba = Dict.empty(key_type=types.unicode_type,value_type=types.unicode_type)
    for k,v in simParam_dict.items():
        simParam_dict_numba[k] = v
    for k,v in paramType_dict.items():
        simParamTypes_dict_numba[k] = v
    return simParam_dict_numba,simParamTypes_dict_numba

#pythran export get_system_parameters(str:str dict,str:str dict)
#dict_type = types.DictType(key_type=types.unicode_type,value_type=types.unicode_type)
#@njit(types.Tuple(((types.int64,types.int64,types.int64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.unicode_type,types.float64,types.float64,types.unicode_type,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.unicode_type,types.int64,types.boolean,types.float64,types.float64,types.int64,types.unicode_type,types.boolean,types.boolean,types.unicode_type)))(dict_type,dict_type))
@njit
def get_system_parameters(simParam_dict,paramType_dict):
    _INT_INDEX_ = 0
    _FLT_INDEX_ = 1
    _STR_INDEX_ = 2
    _BOO_INDEX_ = 3
    N                  = get_param(simParam_dict['N']                  , paramType_dict['N']                  )[_INT_INDEX_]
    tTrans             = get_param(simParam_dict['tTrans']             , paramType_dict['tTrans']             )[_INT_INDEX_]
    Tmax               = get_param(simParam_dict['Tmax']               , paramType_dict['Tmax']               )[_INT_INDEX_]
    VE0                = get_param(simParam_dict['VE0']                , paramType_dict['VE0']                )[_FLT_INDEX_]
    VE0Std             = get_param(simParam_dict['VE0Std']             , paramType_dict['VE0Std']             )[_FLT_INDEX_]
    VI0                = get_param(simParam_dict['VI0']                , paramType_dict['VI0']                )[_FLT_INDEX_]
    VI0Std             = get_param(simParam_dict['VI0Std']             , paramType_dict['VI0Std']             )[_FLT_INDEX_]
    XE0                = get_param(simParam_dict['XE0']                , paramType_dict['XE0']                )[_FLT_INDEX_]
    fXE0               = get_param(simParam_dict['fXE0']               , paramType_dict['fXE0']               )[_FLT_INDEX_]
    XE0Rand            = get_param(simParam_dict['XE0Rand']            , paramType_dict['XE0Rand']            )[_BOO_INDEX_]
    XI0                = get_param(simParam_dict['XI0']                , paramType_dict['XI0']                )[_FLT_INDEX_]
    fXI0               = get_param(simParam_dict['fXI0']               , paramType_dict['fXI0']               )[_FLT_INDEX_]
    XI0Rand            = get_param(simParam_dict['XI0Rand']            , paramType_dict['XI0Rand']            )[_BOO_INDEX_]
    mu                 = get_param(simParam_dict['mu']                 , paramType_dict['mu']                 )[_FLT_INDEX_]
    theta              = get_param(simParam_dict['theta']              , paramType_dict['theta']              )[_FLT_INDEX_]
    J                  = get_param(simParam_dict['J']                  , paramType_dict['J']                  )[_FLT_INDEX_]
    Gamma              = get_param(simParam_dict['Gamma']              , paramType_dict['Gamma']              )[_FLT_INDEX_]
    I                  = get_param(simParam_dict['I']                  , paramType_dict['I']                  )[_FLT_INDEX_]
    Iext               = get_param(simParam_dict['Iext']               , paramType_dict['Iext']               )[_FLT_INDEX_]
    g                  = get_param(simParam_dict['g']                  , paramType_dict['g']                  )[_FLT_INDEX_]
    p                  = get_param(simParam_dict['p']                  , paramType_dict['p']                  )[_FLT_INDEX_]
    q                  = get_param(simParam_dict['q']                  , paramType_dict['q']                  )[_FLT_INDEX_]
    A                  = get_param(simParam_dict['A']                  , paramType_dict['A']                  )[_FLT_INDEX_]
    tauW               = get_param(simParam_dict['tauW']               , paramType_dict['tauW']               )[_FLT_INDEX_]
    uW                 = get_param(simParam_dict['uW']                 , paramType_dict['uW']                 )[_FLT_INDEX_]
    tauT               = get_param(simParam_dict['tauT']               , paramType_dict['tauT']               )[_FLT_INDEX_]
    uT                 = get_param(simParam_dict['uT']                 , paramType_dict['uT']                 )[_FLT_INDEX_]
    saveSpikingData    = get_param(simParam_dict['saveSpikingData']    , paramType_dict['saveSpikingData']    )[_BOO_INDEX_]
    nNeuronsSpk        = get_param(simParam_dict['nNeuronsSpk']        , paramType_dict['nNeuronsSpk']        )[_INT_INDEX_]
    weightDynType      = get_param(simParam_dict['weightDynType']      , paramType_dict['weightDynType']      )[_STR_INDEX_]
    rPoisson           = get_param(simParam_dict['rPoisson']           , paramType_dict['rPoisson']           )[_FLT_INDEX_]
    paramCV            = get_param(simParam_dict['paramCV']            , paramType_dict['paramCV']            )[_FLT_INDEX_]
    K                  = get_param(simParam_dict['K']                  , paramType_dict['K']                  )[_INT_INDEX_]
    writeOnRun         = get_param(simParam_dict['writeOnRun']         , paramType_dict['writeOnRun']         )[_BOO_INDEX_]
    spkFileName        = get_param(simParam_dict['spkFileName']        , paramType_dict['spkFileName']        )[_STR_INDEX_]
    simType            = get_param(simParam_dict['simType']            , paramType_dict['simType']            )[_STR_INDEX_]
    exc_only_dynthresh = get_param(simParam_dict['exc_only_dynthresh'] , paramType_dict['exc_only_dynthresh'] )[_BOO_INDEX_]
    paramCV = 0.0
    print(' ... forcing the CV of all parameters to be zero (homogeneous network), since parameter variability is not implemented yet')
    return N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,mu,theta,J,Gamma,I,Iext,\
           g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson,K,paramCV,writeOnRun,spkFileName,simType,\
           exc_only_dynthresh
    #return N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson,K,paramCV,writeOnRun,spkFileName

@njit
def to_float(x):
    # Handle the case where x might be None
    if x is None:
        return 0.0  # or any default float value
    return float(x)

@njit
def to_int(x):
    # Handle the case where x might be None
    if x is None:
        return 0  # or any default float value
    return int(x)


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
@njit
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
    pN      = to_int(p*N)
    qN      = N - pN

    XE0   = to_float(XE0)
    XI0   = to_float(XI0)

    N_fl  = to_float(N)
    pN_fl = to_float(pN) if pN > 0 else 1.0 # avoids NaN and division by zero
    qN_fl = to_float(qN) if qN > 0 else 1.0 # avoids NaN and division by zero

    pN_s  = to_int(p*nNeuronsSpk) # record only pN_s neurons from the excitatory population for raster plot
    qN_s  = nNeuronsSpk - pN_s # record only qN_s neurons from the inhibitory population for raster plot

    KE    = to_int(numpy.ceil(p * to_float(K))) # number of excitatory inputs
    KI    = K - KE # number of inhibitory inputs
    KE_fl = to_float(KE)
    KI_fl = to_float(KI)

    C = generate_random_net_fixed_number_of_inputs(KE,pN,K,N)
    #W_I = g*J #only constant parameters are implemented
    # this is set inside the set_MF_network_IC function

    P_firing_poisson = PoissonProcess_firingprob(rPoisson)

    # setting initial conditions
    VE,XE,VI,XI,rhoETemp,rhoITemp,thetaE,thetaI,W_I,thetaMean = set_MF_network_IC(pN,qN,g,J,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,theta)
    synapticInput = numpy.array([0.0 for _ in range(N)])

    # forcing a fixed inhibitory synaptic weight
    if 'adaptthresh' in simType:
        A       = 0.0
        tauWinv = 0.0
        uW      = 0.0

    # running transient time
    if tTrans > 0:
        rhoETemp,rhoITemp,thetaMean,W_I,VE,XE,VI,XI,thetaE,thetaI = run_transient_GLNetEIRand(simType,exc_only_dynthresh,VE,XE,VI,XI,tTrans,rhoETemp,rhoITemp,pN,qN,pN_fl,qN_fl,P_firing_poisson,Iext,mu,theta,Gamma,I,synapticInput,J,W_I,C,KE,K,A,tauTinv,tauWinv,thetaE,thetaI,uT,uW,weightDynType)
    
    # subtracting transient time from total time
    Tmax = Tmax - tTrans 

    # preparing variable for recording spiking data (if needed)
    spkTimeFile = None
    if saveSpikingData and writeOnRun:
        print('*** writing file ',spkFileName,' during simulation')
        spkTimeFile = open_file(spkFileName)
        #spkTimeFile = open(spkFileName,'w')
    spkData,write_spk_time,save_spk_time = get_write_spike_data_functions(saveSpikingData,writeOnRun,XE,XI,pN_s,qN_s)

    # running main simulation
    rhoE = numpy.array([0.0 for i in range(Tmax)])
    rhoI = numpy.array([0.0 for i in range(Tmax)])
    #W_I_data     = numpy.array([0.0 for i in range(Tmax)]) ############### I'll leave it here for later when I implement heterogeneous parameters
    theta_data    = numpy.array([0.0 for i in range(Tmax)])
    rhoE[0]       = rhoETemp
    rhoI[0]       = rhoITemp
    #W_I_data[0]  = W_I ############### I'll leave it here for later when I implement heterogeneous parameters
    theta_data[0] = thetaMean
    for t in range(1,Tmax):
        k       = get_stim_neuron_index(pN_fl)
        XE[k],_ = get_external_stimulus(XE[k],rhoE[t-1],rhoI[t-1],pN_fl)
        #W_I = weightAdapt(W_I,A,tauWinv,uW,rhoE[t-1],rhoI[t-1]) # both the E and I subnetworks receive the same inhibitory adapted input
        synapticInput = sumSynpaticInput_homog(synapticInput,KE,K,N,XE,XI,J,W_I,C) # updates synapticInput variable
        thetaMean = 0.0
        for i in range(pN):
            VE[i],XE[i],thetaE[i] = GLNetEIRand_E_iter(VE[i],XE[i],synapticInput[i],Iext,mu,theta,Gamma,I,P_firing_poisson,tauTinv,uT)
            rhoE[t] += XE[i]
            thetaMean += thetaE[i]
            if (i < pN_s) and XE[i]:
                spkData = save_spk_time(spkData,t,i) #spkData.append((t,i)) #spkData[t][i] = XE[i]
                write_spk_time(spkTimeFile,t,i)
        for i in range(qN):
            VI[i],XI[i],thetaI[i] = GLNetEIRand_I_iter(VI[i],XI[i],synapticInput[i],Iext,mu,theta,Gamma,I,0.0,tauTinv,uT)
            rhoI[t] += XI[i]
            thetaMean += thetaI[i]
            if (i < qN_s) and XI[i]:
                spkData = save_spk_time(spkData,t,i+pN_s) #spkData.append((t,i+pN_s)) #spkData[t][i+pN_s] = XI[i]
                write_spk_time(spkTimeFile,t,i+pN_s)
        rhoE[t] = rhoE[t]/pN_fl
        rhoI[t] = rhoI[t]/qN_fl
        #W_I_data[t] = W_I ############### I'll leave it here for later when I implement heterogeneous parameters
        theta_data[t] = thetaMean/N_fl
    # end of time loop
    if saveSpikingData and writeOnRun:
        spkTimeFile = close_file(spkFileName)
        #spkTimeFile.close()
        #print('*** closed file ', spkFileName)
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
@njit
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
    pN      = to_int(p*N)
    qN      = N - pN

    XE0 = to_float(XE0)
    XI0 = to_float(XI0)

    N_fl  = to_float(N)
    pN_fl = to_float(pN) if pN > 0 else 1.0 # avoids NaN and division by zero
    qN_fl = to_float(qN) if qN > 0 else 1.0 # avoids NaN and division by zero

    pN_s = to_int(p*nNeuronsSpk) # record only pN_s neurons from the excitatory population for raster plot
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
        print('*** writing file ',spkFileName,' during simulation')
        #spkTimeFile = open(spkFileName,'w')
        spkTimeFile = open_file(spkFileName)
    spkData,write_spk_time,save_spk_time = get_write_spike_data_functions(saveSpikingData,writeOnRun,XE,XI,pN_s,qN_s)

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
                write_spk_time(spkTimeFile,t,i)
        for i in range(qN):
            VI[i],XI[i],thetaI[i] = GLNetEIMF_I_iter(VI[i],XI[i],rhoE_prev,rhoI_prev,Iext,mu,thetaI[i],J,Gamma,I,W_I,p,q,tauTinv,uT,0.0)
            rhoI[t] += XI[i]
            thetaMean += thetaI[i]
            if (i < qN_s) and XI[i]:
                spkData = save_spk_time(spkData,t,i+pN_s) #spkData.append((t,i+pN_s)) #spkData[t][i+pN_s] = XI[i]
                write_spk_time(spkTimeFile,t,i+pN_s)
        rhoE[t] = rhoE[t]/pN_fl
        rhoI[t] = rhoI[t]/qN_fl
        W_I_data[t] = W_I
        theta_data[t] = thetaMean/N_fl
        rhoE_prev = rhoE[t]
        rhoI_prev = rhoI[t]
    # end of time loop
    if saveSpikingData and writeOnRun:
        close_file(spkFileName)
        #spkTimeFile.close()
        #print('*** closed file ', spkFileName)
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
@njit(types.int64(types.float64))
def get_stim_neuron_index_aval(pN_fl):
    return to_int(random.random() * pN_fl)

@njit(types.int64(types.float64))
def get_stim_neuron_index_zero(pN_fl):
    return 0

#pythran export generate_random_net_fixed_input(int,int,int,int)
@njit
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
    if pN < K_ex: # necessary: K_ex <= pN
        raise ValueError('pN (total excitatory population) must be >= K_ex (number of excitatory inputs)')
    if (N-pN) < (K-K_ex): # necessary: K_ex <= pN
        raise ValueError('(N-pN) (total inhibitory population) must be >= (K-K_ex) (number of inhibitory inputs)')
    C = numpy.zeros((N,K),dtype=numpy.int64)
    for i in range(N):
        C[i,:K_ex] = numpy.sort(random_sample(pN,K_ex))
        C[i,K_ex:] = numpy.sort(random_sample(N-pN,K-K_ex))
        #A = numpy.sort(random_sample(pN,K_ex))
        #B = numpy.sort(random_sample(N-pN,K-K_ex))
        #numpy.concatenate((A,B),axis=0)
    return C

#pythran export sumSynpaticInput(float[],int,int,int,float[],float[],float[:,:] order(C),float[:,:] order(C),float[:,:] order(C))
@njit
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
        synapticInput[i] = s / to_float(K)
    return synapticInput

#pythran export sumSynpaticInput_homog(float[],int,int,int,float[],float[],float,float,float[:,:] order(C))
@njit
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
        synapticInput[i] = (J*sE - W*sI) / to_float(K)
    return synapticInput

#pythran export run_transient_GLNetEIRand(str,float[],float[],float[],float[],int,float,float,int,int,float,float,float,float,float,float,float,float,float[],float,float,float[:,:] order(C),int,int,float,float,float,float[],float[],float,float,str)
@njit
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
        synapticInput = sumSynpaticInput_homog(synapticInput,KE,K,N,XE,XI,J,W_I,C) # updates synapticInput variable
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
@njit
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

@njit
def get_write_spike_data_functions(saveSpikingData,writeOnRun,XE,XI,pN_s,qN_s):
    if saveSpikingData:
        if writeOnRun:
            spkData        = numpy.empty((0,2),dtype=numpy.int64) # [(0,0)]
            write_spk_time = write_spk_data #lambda t_ind,k_ind: spkTimeFile.write(str(t_ind) + ',' + str(k_ind) + '\n')
            save_spk_time  = save_spk_data_fake
        else:
            write_spk_time = write_spk_data_fake
            save_spk_time  = save_spk_data
            spkData        = save_initial_spkdata(XE,XI,pN_s,qN_s) # spkData is a list of tuples with spike time stemps [(t#,neuron#),(t2$,neuron#),...]
    else:
        save_spk_time  = save_spk_data_fake
        write_spk_time = write_spk_data_fake
        spkData        = numpy.empty((0,2),dtype=numpy.int64) # [(0,0)]
    return spkData,write_spk_time,save_spk_time

@njit
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

@njit
def get_RandomNet_stimulus_func(simType):
    if simType == 'aval':
        get_external_stimulus = get_external_stimulus_aval
        get_stim_neuron_index = get_stim_neuron_index_aval
    else:
        get_external_stimulus = get_external_stimulus_dynamic
        get_stim_neuron_index = get_stim_neuron_index_zero #lambda _: 0
    return get_external_stimulus,get_stim_neuron_index

@njit
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

@njit
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
        weightAdapt_iter = weightAdapt_zero #lambda W,A,tauWinv,uW,rhoE,rhoI: 0.0
    # forcing a fixed inhibitory synaptic weight
    if 'adaptthresh' in simType:
        print(' ... forcing constant inhibitory W because simType == adaptthresh')
        weightAdapt_iter = weightAdapt_constant
    return weightAdapt_iter

@njit
def get_MFNet_stimulus_func(simType):
    if simType == 'aval':
        get_external_stimulus = get_external_stimulus_aval
    else:
        get_external_stimulus = get_external_stimulus_dynamic
    return get_external_stimulus

#pythran export get_external_stimulus_dynamic(float,float,float,float)
@njit(types.Tuple((types.float64,types.float64))(types.float64,types.float64,types.float64,types.float64))
def get_external_stimulus_dynamic(XE,rhoE,rhoI,pN_fl):
    return XE,rhoE

#pythran export get_external_stimulus_aval(float,float,float,float)
@njit(types.Tuple((types.float64,types.float64))(types.float64,types.float64,types.float64,types.float64))
def get_external_stimulus_aval(XE,rhoE,rhoI,pN_fl):
    if (rhoE + rhoI) < 1e-16:  # causes a spike in an excitatory neuron if the activity is less than the floating-point double precision
        return 1.0, 1.0 / pN_fl
    else:
        return XE,rhoE

#pythran export save_initial_spkdata(float[],float[],int,int)
@njit
def save_initial_spkdata(XE,XI,pN,qN):
    """
    spkData = [[0 for i in range(nNeuronsSpk)] for t in range(Tmax)]
    spkData[0] = XE[:pN_s] + XI[:qN_s]
     spkData is a list of tuples
     where each tuple records (time step, neuron index) for each firing
     the pythran breaks with the line below, probably due to enumerate and conditional for loop
    spkData = [ [0,i] for i,x in enumerate(XE[:pN_s]) if x == 1 ] + [ [0,i+pN_s] for i,x in enumerate(XI[:qN_s]) if x == 1 ]
    """
    spkData = numpy.empty((0,2),dtype=numpy.int64) # spkData = []
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

@njit
def get_random_inhibitory_weights(W_I,C):
    """
    W_I -> average inhibitory weights
    C   -> connectivity matrix
    """
    return W_I

#pythran export set_MF_network_IC(int,int,float,float,float,float,float,float,float,float,bool,float,float,bool,float)
@njit
def set_MF_network_IC(pN,qN,g,J,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,theta):
    VE0    = theta if VE0 == 0.0 else VE0
    thetaE = numpy.array([theta for i in range(pN)])
    XE     = generate_IC_spikes(XE0,pN,to_int(fXE0*pN),'excitatory',XE0Rand)
    VE_lst = numpy.array([abs(random.gauss(VE0,VE0Std)) for _ in range(pN)])
    VE     = numpy.array([ (0.0 if r[0] >= 0.5 else r[1]) for r in numpy.column_stack((XE,VE_lst)) ],dtype=numpy.float64)
    #for i in range(pN):
    #    VE[i] = 0.0 if XE[i] >= 0.5 else VE[i]

    VI0    = theta if VI0 == 0.0 else VI0
    thetaI = numpy.array([theta for i in range(qN)])
    XI     = generate_IC_spikes(XI0,qN,to_int(fXI0*qN),'inhibitory',XI0Rand)
    VI_lst = numpy.array([abs(random.gauss(VI0,VI0Std)) for i in range(qN)])
    VI     = numpy.array([ (0.0 if r[0] >= 0.5 else r[1]) for r in numpy.column_stack((XI,VI_lst)) ],dtype=numpy.float64)
    #for i in range(qN):
    #    VI[i] = 0.0 if XI[i] >= 0.5 else VI[i]

    rhoE0     = to_float(sum(XE))/(to_float(pN) if pN > 0 else 1.0)
    rhoI0     = to_float(sum(XI))/(to_float(qN) if qN > 0 else 1.0)
    W_I       = g*J
    thetaMean = theta
    return VE,XE,VI,XI,rhoE0,rhoI0,thetaE,thetaI,W_I,thetaMean

##pythran export set_Rand_network_IC(int,int,float,float,float,float,float,float,float,float,bool,float,float,bool,float)
#@njit
#def set_Rand_network_IC(pN,qN,g,J,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,theta):
#    VE,XE,VI,XI,rhoE0,rhoI0,thetaE,thetaI,W_I_mean,thetaMean = set_MF_network_IC(pN,qN,g,J,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,theta)
#    return VE,XE,VI,XI,rhoE0,rhoI0,thetaE,thetaI,W_I,thetaMean

#pythran export generate_IC_spikes(float,int,int,str,bool)
@njit
def generate_IC_spikes(X0,N,K,neuronType,is_random):
    """generates a list X of zeros with len N containing K ones
    """
    X0 = bool2float(X0>=0.5) # x0 can only be 1 or 0
    if K == 0:
        if (X0 < 0.5):
            print(' ... ',neuronType,' IC: starting from the absorbing state (all inactive neurons) because fX0 = 0.0 and X0 = 0.0')#print(' ... %s IC: starting from the absorbing state (all inactive neurons) because fX0 = 0.0 and X0 = 0.0'%(neuronType))
            X = numpy.zeros(N)
        else:
            print(' ... ',neuronType,' IC: starting from all active neurons')#print(' ... {0:s} IC: starting from all active neurons'.format(neuronType))
            X = numpy.ones(N)
    else: #(X0 >= 0.5) and is_random:
        txt = 'random' if is_random else 'sequential'
        print(' ... ',neuronType,' IC: starting with ',K,' ',txt,' active neurons regardless of X0')#print(' ... {0:s} IC: starting with {1:g} {2:s} active neurons regardless of X0'.format(neuronType,K,'random' if is_random else 'sequential'))
        X = numpy.zeros(N)
        if is_random:
            start_activity_idx = random_sample(N,K) #random.sample(range(N),K)
        else:
            start_activity_idx = numpy.arange(K) #list(range(K))
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
@njit(types.boolean(types.float64))
def bool2float(x):
    return 1.0 if x else 0.0

#pythran export PHI(float, float, float)
@njit(types.float64(types.float64,types.float64,types.float64))
def PHI(V,theta,Gamma):
    tg = theta+1.0/Gamma
    return Gamma*(V-theta)*bool2float(V>theta)*bool2float(V<tg)+bool2float(V>=tg)


#pythran export GLNetEIRand_adaptthresh_iter(float, float, float, float, float, float, float, float, float, float, float)
@njit(types.Tuple((types.float64,types.float64,types.float64))(types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64))
def GLNetEIRand_adaptthresh_iter(V,X,synapticInput,Iext,mu,theta,Gamma,I,P_poisson,tauTinv,uT):
    theta = theta * (1.0 - tauTinv + uT*X)
    V     = (mu*V + I + Iext + synapticInput)*(1.0-X)
    X     = bool2float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export GLNetEIRand_adaptthreshlinear_iter(float, float, float, float, float, float, float, float, float, float, float)
@njit(types.Tuple((types.float64,types.float64,types.float64))(types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64))
def GLNetEIRand_adaptthreshlinear_iter(V,X,synapticInput,Iext,mu,theta,Gamma,I,P_poisson,tauTinv,uT):
    theta = theta * (1.0 - tauTinv) + uT*X
    V     = (mu*V + I + Iext + synapticInput)*(1.0-X)
    X     = bool2float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export GLNetEIRand_adaptthreshsaturate_iter(float, float, float, float, float, float, float, float, float, float, float)
@njit(types.Tuple((types.float64,types.float64,types.float64))(types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64))
def GLNetEIRand_adaptthreshsaturate_iter(V,X,synapticInput,Iext,mu,theta,Gamma,I,P_poisson,tauTinv,uT):
    theta = min(theta * (1.0 - tauTinv + uT*X),uT/tauTinv)
    V     = (mu*V + I + Iext + synapticInput)*(1.0-X)
    X     = bool2float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export GLNetEIRand_static_iter(float, float, float, float, float, float, float, float, float, float, float)
@njit(types.Tuple((types.float64,types.float64,types.float64))(types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64))
def GLNetEIRand_static_iter(V,X,synapticInput,Iext,mu,theta,Gamma,I,P_poisson,tauTinv,uT):
    V = (mu*V + I + Iext + synapticInput)*(1.0-X)
    X = bool2float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export GLNetEIMF_adaptthresh_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
@njit(types.Tuple((types.float64,types.float64,types.float64))(types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64))
def GLNetEIMF_adaptthresh_iter(V,X,rhoE,rhoI,Iext,mu,theta,J,Gamma,I,W_I,p,q,tauTinv,uT,P_poisson):
    theta = theta * (1.0 - tauTinv + uT*X)
    V     = (mu*V + I + Iext + J*p*rhoE - q*W_I*rhoI)*(1.0-X)
    X     = bool2float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export GLNetEIMF_adaptthreshsaturate_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
@njit(types.Tuple((types.float64,types.float64,types.float64))(types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64))
def GLNetEIMF_adaptthreshsaturate_iter(V,X,rhoE,rhoI,Iext,mu,theta,J,Gamma,I,W_I,p,q,tauTinv,uT,P_poisson):
    theta = min(theta * (1.0 - tauTinv + uT*X),uT/tauTinv)
    V     = (mu*V + I + Iext + J*p*rhoE - q*W_I*rhoI)*(1.0-X)
    X     = bool2float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export GLNetEIMF_adaptthreshlinear_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
@njit(types.Tuple((types.float64,types.float64,types.float64))(types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64))
def GLNetEIMF_adaptthreshlinear_iter(V,X,rhoE,rhoI,Iext,mu,theta,J,Gamma,I,W_I,p,q,tauTinv,uT,P_poisson):
    theta = theta * (1.0 - tauTinv) + uT*X
    V     = (mu*V + I + Iext + J*p*rhoE - q*W_I*rhoI)*(1.0-X)
    X     = bool2float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export GLNetEIMF_static_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
@njit(types.Tuple((types.float64,types.float64,types.float64))(types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64,types.float64))
def GLNetEIMF_static_iter(V,X,rhoE,rhoI,Iext,mu,theta,J,Gamma,I,gJ,p,q,tauTinv,uT,P_poisson):
    V = (mu*V + I + Iext + J*p*rhoE - q*gJ*rhoI)*(1.0-X)
    X = bool2float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export weightAdapt_constant(float, float, float, float, float, float)
@njit(types.float64(types.float64,types.float64,types.float64,types.float64,types.float64,types.float64))
def weightAdapt_zero(W,A,tauWinv,uW,rhoE,rhoI):
    return 0.0

#pythran export weightAdapt_constant(float, float, float, float, float, float)
@njit(types.float64(types.float64,types.float64,types.float64,types.float64,types.float64,types.float64))
def weightAdapt_constant(W,A,tauWinv,uW,rhoE,rhoI):
    return W

#pythran export weightAdapt_decrease(float, float, float, float, float, float)
@njit(types.float64(types.float64,types.float64,types.float64,types.float64,types.float64,types.float64))
def weightAdapt_decrease(W,A,tauWinv,uW,rhoE,rhoI):
    return W * (1.0 - tauWinv - uW*rhoI) + tauWinv * A

#pythran export weightAdapt_increase(float, float, float, float, float, float)
@njit(types.float64(types.float64,types.float64,types.float64,types.float64,types.float64,types.float64))
def weightAdapt_increase(W,A,tauWinv,uW,rhoE,rhoI):
    return W * (1.0 - tauWinv + uW*rhoE) + tauWinv * A



"""
####################################
#################################### 
####################################
#################################### SUPPORT FUNCTIONS
####################################
#################################### 
####################################
"""

@jit(nopython=True)
def my_exp(x): #definimos essa função para evitar o erro de overflow
    return math.exp(x) if x < 709.782712893384 else numpy.inf

#pythran export multvecelem(float list, float list)
@jit(nopython=True)
def multvecelem(x,y):
    return [x[i]*yy for i,yy in enumerate(y)]

#pythran export PoissonProcess_firingprob(float)
@jit(nopython=True)
def PoissonProcess_firingprob(r):
    return 1.0-my_exp(-r) # probability of firing is constant

#pythran export save_spk_data_fake((int,int) list,int,int)
@njit(types.int64[:,:](types.int64[:,:],types.int64,types.int64))
def save_spk_data_fake(s,t,k):
    return s

#pythran export save_spk_data((int,int) list,int,int)
@njit(types.int64[:,:](types.int64[:,:],types.int64,types.int64))
def save_spk_data(s,t,k):
    # s -> numpy array of shape [:,2] to append (t,k)
    # t -> spike time index
    # k -> neuron index that fired at t
    #s=numpy.append(s,[(t,k)],axis=0)
    s=numpy.concatenate((s,numpy.array([(t,k)])),axis=0)
    #s.append((t,k))
    return s

#pythran export write_spk_data_fake(int,int)
@njit(types.void(types.none,types.int64,types.int64))
def write_spk_data_fake(spkFile,t,k):
    return None

@njit(types.void(types.none,types.int64,types.int64))
def write_spk_data(spkFile,t,k):
    #spkFile.write(str(t) + ',' + str(k) + '\n')
    print(t,',',k)

@njit
def open_file(spkFileName):
    #spkTimeFile = open(spkFileName,'w')
    spkTimeFile = None
    print('*** writing file ',spkFileName,' during simulation')
    print('##################################################')
    print('##################################################')
    print('##################################################')
    print('################################################## file ', spkFileName, ' will be printed to stdout')
    print('################################################## due to numba limitation')
    print('##################################################')
    print('##################################################')
    print('##################################################')
    print('[[[ BEGINNING OF FILE ',spkFileName,']]]')
    return spkTimeFile

@njit
def close_file(spkFileName):
    #spkFile.close()
    print('[[[ END OF FILE ',spkFileName,']]]')
    print('##################################################')
    print('##################################################')
    print('##################################################')
    print('##################################################')
    print('##################################################')
    print('##################################################')
    print('##################################################')
    print('##################################################')
    #print('*** closed file ',spkFile)

"""
####################################
#################################### 
####################################
#################################### numba SUPPORT FUNCTIONS
####################################
#################################### 
####################################
"""

@njit(types.int64(types.unicode_type))
def str2int(s):
    final_index, result = len(s) - 1, 0
    for i,v in enumerate(s):
        result += (ord(v) - 48) * (10 ** (final_index - i))
    return result


@jit(nopython=True)
def str2float_helper(text):
    sep = ord(".")
    c_min = ord("0")
    c_max = ord("9")

    n = len(text)
    valid = n > 0
    # determine sign
    start = n - 1
    stop = -1
    sign = 1
    if valid:
        first = ord(text[0])
        if first == ord("+"):
            stop = 0
        elif first == ord("-"):
            sign = -1
            stop = 0
    # parse rest
    sep_pos = 0
    number = 0
    j = 0
    for i in range(start, stop, -1):
        c = ord(text[i])
        if c_min <= c <= c_max:
            number += (c - c_min) * 10 ** j
            j += 1
        elif c == sep and sep_pos == 0:
            sep_pos = j
        else:
            valid = False
            break
    return sign * number, sep_pos, valid


@njit(types.float64(types.unicode_type))
def str2float(text):
    if text == "nan" or text == "NAN" or text == "NaN":
        return math.nan
    exp_chars = b"eE"
    exp_pos = -1
    for exp_char in exp_chars:
        for i, c in enumerate(text[::-1]):
            c = ord(c)
            if c == exp_char:
                exp_pos = i
                break
        if exp_pos > -1:
            break
    if exp_pos > 0:
        exp_number = str2int(text[-exp_pos:])
        if exp_number is None:
            exp_number = 0
        number, sep_pos, valid = str2float_helper(text[:-exp_pos-1])
        result = number / 10.0 ** (sep_pos - exp_number) if valid else None
    else:
        number, sep_pos, valid = str2float_helper(text)
        result = number / 10.0 ** sep_pos if valid else None
    return result


#pythran export get_param(str,str)
@njit(types.Tuple((types.int64,types.float64,types.unicode_type,types.boolean))(types.unicode_type,types.unicode_type))
def get_param(v,vtype):
    a = -1
    b = numpy.nan
    c = ''
    d = False
    if 'int' in vtype:
        a = str2int(v)
    elif 'float' in vtype:
        b = str2float(v)
    elif 'str' in vtype:
        c = v
    elif 'bool' in vtype:
        d = v.lower() == 'true'
    else:
        raise ValueError('unknown type for v in get_param function from GLNetEISimLib')
    return a,b,c,d


@njit
def random_sample(N, K):
    # Initialize a NumPy array with the range of values from 0 to N-1
    population = numpy.arange(N, dtype=numpy.int64)
    
    # Perform Fisher-Yates shuffle for the first K elements
    for i in range(K):
        # Pick a random index from i to N-1
        j = random.randint(i, N-1)
        # Swap the elements at indices i and j
        population[i], population[j] = population[j], population[i]
    
    # Return the first K elements as a NumPy array
    return population[:K]
