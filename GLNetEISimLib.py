import random
import numpy

#pythran export get_system_parameters(str:str dict,str:str dict)
def get_system_parameters(simParam_dict,paramType_dict):
    N=get_param(simParam_dict['N'],paramType_dict['N'])
    tTrans=get_param(simParam_dict['tTrans'],paramType_dict['tTrans'])
    Tmax=get_param(simParam_dict['Tmax'],paramType_dict['Tmax'])
    VE0=get_param(simParam_dict['VE0'],paramType_dict['VE0'])
    VE0Std=get_param(simParam_dict['VE0Std'],paramType_dict['VE0Std'])
    VI0=get_param(simParam_dict['VI0'],paramType_dict['VI0'])
    VI0Std=get_param(simParam_dict['VI0Std'],paramType_dict['VI0Std'])
    XE0=get_param(simParam_dict['XE0'],paramType_dict['XE0'])
    fXE0=get_param(simParam_dict['fXE0'],paramType_dict['fXE0'])
    XE0Rand=get_param(simParam_dict['XE0Rand'],paramType_dict['XE0Rand'])
    XI0=get_param(simParam_dict['XI0'],paramType_dict['XI0'])
    fXI0=get_param(simParam_dict['fXI0'],paramType_dict['fXI0'])
    XI0Rand=get_param(simParam_dict['XI0Rand'],paramType_dict['XI0Rand'])
    mu=get_param(simParam_dict['mu'],paramType_dict['mu'])
    theta=get_param(simParam_dict['theta'],paramType_dict['theta'])
    J=get_param(simParam_dict['J'],paramType_dict['J'])
    Gamma=get_param(simParam_dict['Gamma'],paramType_dict['Gamma'])
    I=get_param(simParam_dict['I'],paramType_dict['I'])
    Iext=get_param(simParam_dict['Iext'],paramType_dict['Iext'])
    g=get_param(simParam_dict['g'],paramType_dict['g'])
    p=get_param(simParam_dict['p'],paramType_dict['p'])
    q=get_param(simParam_dict['q'],paramType_dict['q'])
    A=get_param(simParam_dict['A'],paramType_dict['A'])
    tauW=get_param(simParam_dict['tauW'],paramType_dict['tauW'])
    uW=get_param(simParam_dict['uW'],paramType_dict['uW'])
    tauT=get_param(simParam_dict['tauT'],paramType_dict['tauT'])
    uT=get_param(simParam_dict['uT'],paramType_dict['uT'])
    saveSpikingData=get_param(simParam_dict['saveSpikingData'],paramType_dict['saveSpikingData'])
    nNeuronsSpk=get_param(simParam_dict['nNeuronsSpk'],paramType_dict['nNeuronsSpk'])
    weightDynType=get_param(simParam_dict['weightDynType'],paramType_dict['N'])
    rPoisson=get_param(simParam_dict['rPoisson'],paramType_dict['rPoisson'])
    writeOnRun=get_param(simParam_dict['writeOnRun'],paramType_dict['writeOnRun'])
    spkFileName=get_param(simParam_dict['spkFileName'],paramType_dict['spkFileName'])
    return N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson,writeOnRun,spkFileName

#pythran export get_param(str,str)
def get_param(v,vtype):
    if vtype == 'int':
        return int(v)
    elif vtype == 'float':
        return float(v)
    elif vtype == 'str':
        return str(v)
    elif vtype == 'bool':
        return bool(v)
    else:
        raise ValueError('unknown type for v')

#pythran export RunSimulation_adaptthresh(str:str dict,str:str dict)
def RunSimulation_adaptthresh(simParam_dict,paramType_dict):
    N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson,writeOnRun,spkFileName =  get_system_parameters(simParam_dict,paramType_dict)
    tauTinv = 1.0 / tauT
    pN = int(p*N)
    qN = N - pN
    gJ = g*J

    XE0 = float(XE0)
    XI0 = float(XI0)

    N_fl = float(N)
    pN_fl = float(pN) if pN > 0 else 1.0 # avoids NaN and division by zero
    qN_fl = float(qN) if qN > 0 else 1.0 # avoids NaN and division by zero

    pN_s = int(p*nNeuronsSpk) # record only pN_s neurons from the excitatory population for raster plot
    qN_s = nNeuronsSpk - pN_s # record only qN_s neurons from the inhibitory population for raster plot

    P_firing_poisson = PoissonProcess_firingprob(rPoisson)

    # setting initial conditions
    VE = [abs(random.gauss(VE0,VE0Std)) for i in range(pN)]
    thetaE = [theta for i in range(pN)]
    XE = generate_IC_spikes(XE0,pN,int(fXE0*pN),XE0Rand)

    VI = [abs(random.gauss(VI0,VI0Std)) for i in range(qN)]
    thetaI = [theta for i in range(qN)]
    XI = generate_IC_spikes(XI0,qN,int(fXI0*qN),XI0Rand)

    # setting initial condition
    rhoETemp = float(sum(XE))/pN_fl
    rhoITemp = float(sum(XI))/qN_fl

    thetaMean = theta

    # running transient time
    if tTrans > 0:
        rhoETemp,rhoITemp,thetaMean,VE,XE,VI,XI=run_transient_GLNetEI_adaptthresh(VE,XE,VI,XI,thetaE,thetaI,weightDynType,tTrans,rhoETemp,rhoITemp,N_fl,pN,qN,pN_fl,qN_fl,Iext,mu,J,Gamma,I,p,q,tauTinv,uT,gJ,P_firing_poisson)
    
    # subtracting transient time from total time
    Tmax = Tmax - tTrans 

    # preparing variable for recording spiking data (if needed)
    if saveSpikingData:
        if writeOnRun:
            print('*** writing file %s during simulation' % spkFileName)
            spkData = [(0,0)]
            spkTimeFile = open(spkFileName,'w')
            write_spk_time = lambda t_ind,k_ind: spkTimeFile.write(str(t_ind) + ',' + str(k_ind) + '\n')
            save_spk_time = save_spk_data_fake
        else:
            write_spk_time = write_spk_data_fake
            save_spk_time = save_spk_data
            spkData = save_initial_spkdata(XE,XI,pN_s,qN_s) # spkData is a list of tuples with spike time stemps [(t#,neuron#),(t2$,neuron#),...]
    else:
        save_spk_time = save_spk_data_fake
        write_spk_time = write_spk_data_fake
        spkData = [(0,0)]

    # running main simulation
    rhoE = [0.0 for i in range(Tmax)]
    rhoI = [0.0 for i in range(Tmax)]
    theta_data = [0.0 for i in range(Tmax)]
    rhoE[0] = rhoETemp
    rhoI[0] = rhoITemp
    theta_data[0] = thetaMean
    for t in range(1,Tmax):
        #Iext = 0.0 # stimulus
        thetaMean = 0.0
        for i in range(pN):
            VE[i],XE[i],thetaE[i] = GLNetEI_adaptthresh_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,thetaE[i],J,Gamma,I,gJ,p,q,tauTinv,uT,P_firing_poisson)
            rhoE[t] = rhoE[t] + XE[i]
            thetaMean += thetaE[i]
            if (i < pN_s) and XE[i]:
                spkData = save_spk_time(spkData,t,i) #spkData.append((t,i)) #spkData[t][i] = XE[i]
                write_spk_time(t,i)
        for i in range(qN):
            VI[i],XI[i],thetaI[i] = GLNetEI_adaptthresh_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,thetaI[i],J,Gamma,I,gJ,p,q,tauTinv,uT,0.0)
            rhoI[t] = rhoI[t] + XI[i]
            thetaMean += thetaI[i]
            if (i < qN_s) and XI[i]:
                spkData = save_spk_time(spkData,t,i+pN_s) #spkData.append((t,i+pN_s)) #spkData[t][i+pN_s] = XI[i]
                write_spk_time(t,i+pN_s)
        rhoE[t] = rhoE[t]/pN_fl
        rhoI[t] = rhoI[t]/qN_fl
        theta_data[t] = thetaMean/N_fl
    # end of time loop
    if saveSpikingData and writeOnRun:
        spkTimeFile.close()
    return rhoE,rhoI,spkData,[p*J*r for r in rhoE],[q*g*J*r for r in rhoI],[g for r in rhoE],[I/r for r in theta_data]
    #return rhoE,rhoI,spkData,numpy.multiply(p*J,rhoE),numpy.multiply(q*g*J,rhoI),(numpy.ones(shape=(len(rhoE),))*g),(numpy.ones(shape=(len(rhoE),))*I/theta)

#pythran export RunSimulation_aval(str:str dict,str:str dict)
def RunSimulation_aval(simParam_dict,paramType_dict):
    N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson,writeOnRun,spkFileName =  get_system_parameters(simParam_dict,paramType_dict)
    tauTinv = 1.0 / tauT
    pN = int(p*N)
    qN = N - pN

    XE0 = float(XE0)
    XI0 = float(XI0)

    pN_fl = float(pN) if pN > 0 else 1.0 # avoids NaN and division by zero
    qN_fl = float(qN) if qN > 0 else 1.0 # avoids NaN and division by zero

    pN_s = int(p*nNeuronsSpk) # record only pN_s neurons from the excitatory population for raster plot
    qN_s = nNeuronsSpk - pN_s # record only qN_s neurons from the inhibitory population for raster plot

    P_firing_poisson = PoissonProcess_firingprob(rPoisson)

    # setting initial conditions
    VE = [abs(random.gauss(VE0,VE0Std)) for i in range(pN)]
    XE = generate_IC_spikes(XE0,pN,int(fXE0*pN),XE0Rand)

    VI = [abs(random.gauss(VI0,VI0Std)) for i in range(qN)]
    XI = generate_IC_spikes(XI0,qN,int(fXI0*qN),XI0Rand)

    # setting initial condition
    rhoETemp = float(sum(XE))/pN_fl
    rhoITemp = float(sum(XI))/qN_fl

    # running transient time
    if tTrans > 0:
        rhoETemp,rhoITemp,VE,XE,VI,XI=run_transient_GLNetEI_aval(VE,XE,VI,XI,tTrans,rhoETemp,rhoITemp,pN,qN,pN_fl,qN_fl,Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
    
    # subtracting transient time from total time
    Tmax = Tmax - tTrans 

    # preparing variable for recording spiking data (if needed)
    if saveSpikingData:
        if writeOnRun:
            print('*** writing file %s during simulation' % spkFileName)
            spkData = [(0,0)]
            spkTimeFile = open(spkFileName,'w')
            write_spk_time = lambda t_ind,k_ind: spkTimeFile.write(str(t_ind) + ',' + str(k_ind) + '\n')
            save_spk_time = save_spk_data_fake
        else:
            write_spk_time = write_spk_data_fake
            save_spk_time = save_spk_data
            spkData = save_initial_spkdata(XE,XI,pN_s,qN_s) # spkData is a list of tuples with spike time stemps [(t#,neuron#),(t2$,neuron#),...]
    else:
        save_spk_time = save_spk_data_fake
        write_spk_time = write_spk_data_fake
        spkData = [(0,0)]

    # running main simulation
    rhoE = [0.0 for i in range(Tmax)]
    rhoI = [0.0 for i in range(Tmax)]
    rhoE[0] = rhoETemp
    rhoI[0] = rhoITemp
    for t in range(1,Tmax):
        if (rhoETemp + rhoITemp) < 1e-16:
            XE[0] = 1 # causes a spike in an excitatory neuron if the activity is less than the floating-point double precision
            rhoETemp = 1.0 / pN_fl
        for i in range(pN):
            VE[i],XE[i],_ = GLNetEI_iter(VE[i],XE[i],rhoETemp,rhoITemp,Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
            rhoE[t] += XE[i]
            if (i < pN_s) and XE[i]:
                spkData = save_spk_time(spkData,t,i) #spkData.append((t,i)) #spkData[t][i] = XE[i]
                write_spk_time(t,i)
        for i in range(qN):
            VI[i],XI[i],_ = GLNetEI_iter(VI[i],XI[i],rhoETemp,rhoITemp,Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,0.0)
            rhoI[t] += XI[i]
            if (i < qN_s) and XI[i]:
                spkData = save_spk_time(spkData,t,i+pN_s) #spkData.append((t,i+pN_s)) #spkData[t][i+pN_s] = XI[i]
                write_spk_time(t,i+pN_s)
        rhoE[t] = rhoE[t]/pN_fl
        rhoI[t] = rhoI[t]/qN_fl
        rhoETemp = rhoE[t]
        rhoITemp = rhoI[t]
    # end of time loop
    if saveSpikingData and writeOnRun:
        spkTimeFile.close()
    return rhoE,rhoI,spkData,[p*J*r for r in rhoE],[q*g*J*r for r in rhoI],[g for r in rhoE],[I/theta for r in rhoE]
    #return rhoE,rhoI,spkData,numpy.multiply(p*J,rhoE),numpy.multiply(q*g*J,rhoI),(numpy.ones(shape=(len(rhoE),))*g),(numpy.ones(shape=(len(rhoE),))*I/theta)

#pythran export RunSimulation_adapt(str:str dict,str:str dict)
def RunSimulation_adapt(simParam_dict,paramType_dict):
    N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson,writeOnRun,spkFileName =  get_system_parameters(simParam_dict,paramType_dict)

    if weightDynType == "simple":
        weightAdapt = weightAdapt_decrease
    elif weightDynType == "coupled":
        weightAdapt = weightAdapt_increase
    else:
        raise ValueError('weightDynType is unknown')
    if q == 0.0:
        weightAdapt = lambda W,A,tauWinv,uW,rhoE,rhoI: 0.0
    tauWinv = 1.0 / tauW
    tauTinv = 1.0 / tauT
    pN = int(p*N)
    qN = N - pN

    XE0 = float(XE0)
    XI0 = float(XI0)

    N_fl = float(N)
    pN_fl = float(pN) if pN > 0 else 1.0 # avoids NaN and division by zero
    qN_fl = float(qN) if qN > 0 else 1.0 # avoids NaN and division by zero

    pN_s = int(p*nNeuronsSpk) # record only pN_s neurons from the excitatory population for raster plot
    qN_s = nNeuronsSpk - pN_s # record only qN_s neurons from the inhibitory population for raster plot

    P_firing_poisson = PoissonProcess_firingprob(rPoisson)

    # setting initial conditions
    VE = [abs(random.gauss(VE0,VE0Std)) for i in range(pN)]
    thetaE = [theta for i in range(pN)]
    XE = generate_IC_spikes(XE0,pN,int(fXE0*pN),XE0Rand)

    VI = [abs(random.gauss(VI0,VI0Std)) for i in range(qN)]
    thetaI = [theta for i in range(qN)]
    XI = generate_IC_spikes(XI0,qN,int(fXI0*qN),XI0Rand)

    # setting initial conditions
    rhoETemp = float(sum(XE))/pN_fl
    rhoITemp = float(sum(XI))/qN_fl
    W_I = g*J
    thetaMean = theta
    
    # running transient time
    if tTrans > 0:
        rhoETemp,rhoITemp,thetaMean,W_I,VE,XE,VI,XI=run_transient_GLNetEI_adapt(VE,XE,VI,XI,thetaE,thetaI,weightDynType,tTrans,rhoETemp,rhoITemp,N_fl,pN,qN,pN_fl,qN_fl,Iext,mu,J,Gamma,I,p,q,tauTinv,uT,tauWinv,uW,A,P_firing_poisson)
    
    # subtracting transient time from total time   
    Tmax = Tmax - tTrans 

    # preparing variable for recording spiking data (if needed)
    if saveSpikingData:
        if writeOnRun:
            print('*** writing file %s during simulation' % spkFileName)
            spkData = [(0,0)]
            spkTimeFile = open(spkFileName,'w')
            write_spk_time = lambda t_ind,k_ind: spkTimeFile.write(str(t_ind) + ',' + str(k_ind) + '\n')
            save_spk_time = save_spk_data_fake
        else:
            write_spk_time = write_spk_data_fake
            save_spk_time = save_spk_data
            spkData = save_initial_spkdata(XE,XI,pN_s,qN_s) # spkData is a list of tuples with spike time stemps [(t#,neuron#),(t2$,neuron#),...]
    else:
        save_spk_time = save_spk_data_fake
        write_spk_time = write_spk_data_fake
        spkData = [(0,0)]

    # running main simulation
    rhoE = [0.0 for i in range(Tmax)]
    rhoI = [0.0 for i in range(Tmax)]
    W_I_data = [0.0 for i in range(Tmax)]
    theta_data = [0.0 for i in range(Tmax)]
    rhoE[0] = rhoETemp
    rhoI[0] = rhoITemp
    W_I_data[0] = W_I
    theta_data[0] = thetaMean
    for t in range(1,Tmax):
        W_I = weightAdapt(W_I,A,tauWinv,uW,rhoE[t-1],rhoI[t-1]) # both the E and I subnetworks receive the same inhibitory adapted input
        #Iext = 0.0 # stimulus
        thetaMean = 0.0
        for i in range(pN):
            VE[i],XE[i],thetaE[i] = GLNetEI_adaptthresh_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,thetaE[i],J,Gamma,I,W_I,p,q,tauTinv,uT,P_firing_poisson)
            rhoE[t] = rhoE[t] + XE[i]
            thetaMean = thetaMean + thetaE[i]
            if (i < pN_s) and XE[i]:
                spkData = save_spk_time(spkData,t,i) #spkData.append((t,i)) #spkData[t][i] = XE[i]
                write_spk_time(t,i)
        for i in range(qN):
            VI[i],XI[i],thetaI[i] = GLNetEI_adaptthresh_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,thetaI[i],J,Gamma,I,W_I,p,q,tauTinv,uT,0.0)
            rhoI[t] = rhoI[t] + XI[i]
            thetaMean = thetaMean + thetaI[i]
            if (i < qN_s) and XI[i]:
                spkData = save_spk_time(spkData,t,i+pN_s) #spkData.append((t,i+pN_s)) #spkData[t][i+pN_s] = XI[i]
                write_spk_time(t,i+pN_s)
        rhoE[t] = rhoE[t]/pN_fl
        rhoI[t] = rhoI[t]/qN_fl
        W_I_data[t] = W_I
        theta_data[t] = thetaMean/N_fl
    # end of time loop
    if saveSpikingData and writeOnRun:
        spkTimeFile.close()
    return rhoE,rhoI,spkData,[p*J*r for r in rhoE],[q*r for r in multvecelem(W_I_data,rhoI)],[r/J for r in W_I_data],[I/r for r in theta_data]
    #return rhoE,rhoI,spkData,numpy.multiply(p*J,rhoE),(q*numpy.multiply(W_I_data,rhoI)),numpy.divide(W_I_data,J),numpy.divide(I,theta_data)

#pythran export RunSimulation_static(str:str dict,str:str dict)
def RunSimulation_static(simParam_dict,paramType_dict):
    N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson,writeOnRun,spkFileName =  get_system_parameters(simParam_dict,paramType_dict)
    tauWinv = 1.0 / tauW
    tauTinv = 1.0 / tauT
    pN = int(p*N)
    qN = N - pN

    XE0 = float(XE0)
    XI0 = float(XI0)

    pN_fl = float(pN) if pN > 0 else 1.0 # avoids NaN and division by zero
    qN_fl = float(qN) if qN > 0 else 1.0 # avoids NaN and division by zero

    pN_s = int(p*nNeuronsSpk) # record only pN_s neurons from the excitatory population for raster plot
    qN_s = nNeuronsSpk - pN_s # record only qN_s neurons from the inhibitory population for raster plot

    P_firing_poisson = PoissonProcess_firingprob(rPoisson)

    # setting initial conditions
    VE = [abs(random.gauss(VE0,VE0Std)) for i in range(pN)]
    XE = generate_IC_spikes(XE0,pN,int(fXE0*pN),XE0Rand)

    VI = [abs(random.gauss(VI0,VI0Std)) for i in range(qN)]
    XI = generate_IC_spikes(XI0,qN,int(fXI0*qN),XI0Rand)

    # setting initial condition
    rhoETemp = float(sum(XE))/pN_fl
    rhoITemp = float(sum(XI))/qN_fl

    # running transient time
    if tTrans > 0:
        rhoETemp,rhoITemp,VE,XE,VI,XI=run_transient_GLNetEI_static(VE,XE,VI,XI,tTrans,rhoETemp,rhoITemp,pN,qN,pN_fl,qN_fl,Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
    
    # subtracting transient time from total time
    Tmax = Tmax - tTrans 

    # preparing variable for recording spiking data (if needed)
    if saveSpikingData:
        if writeOnRun:
            print('*** writing file %s during simulation' % spkFileName)
            spkData = [(0,0)]
            spkTimeFile = open(spkFileName,'w')
            write_spk_time = lambda t_ind,k_ind: spkTimeFile.write(str(t_ind) + ',' + str(k_ind) + '\n')
            save_spk_time = save_spk_data_fake
        else:
            write_spk_time = write_spk_data_fake
            save_spk_time = save_spk_data
            spkData = save_initial_spkdata(XE,XI,pN_s,qN_s) # spkData is a list of tuples with spike time stemps [(t#,neuron#),(t2$,neuron#),...]
    else:
        save_spk_time = save_spk_data_fake
        write_spk_time = write_spk_data_fake
        spkData = [(0,0)]

    # running main simulation
    rhoE = [0.0 for i in range(Tmax)]
    rhoI = [0.0 for i in range(Tmax)]
    rhoE[0] = rhoETemp
    rhoI[0] = rhoITemp
    for t in range(1,Tmax):
        #Iext = 0.0 # stimulus
        for i in range(pN):
            VE[i],XE[i],_ = GLNetEI_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
            rhoE[t] = rhoE[t] + XE[i]
            if (i < pN_s) and XE[i]:
                spkData = save_spk_time(spkData,t,i) #spkData.append((t,i)) #spkData[t][i] = XE[i]
                write_spk_time(t,i)
        for i in range(qN):
            VI[i],XI[i],_ = GLNetEI_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,0.0)
            rhoI[t] = rhoI[t] + XI[i]
            if (i < qN_s) and XI[i]:
                spkData = save_spk_time(spkData,t,i+pN_s) #spkData.append((t,i+pN_s)) #spkData[t][i+pN_s] = XI[i]
                write_spk_time(t,i+pN_s)
        rhoE[t] = rhoE[t]/pN_fl
        rhoI[t] = rhoI[t]/qN_fl
    # end of time loop
    if saveSpikingData and writeOnRun:
        spkTimeFile.close()
    return rhoE,rhoI,spkData,[p*J*r for r in rhoE],[q*g*J*r for r in rhoI],[g for r in rhoE],[I/theta for r in rhoE]
    #return rhoE,rhoI,spkData,numpy.multiply(p*J,rhoE),numpy.multiply(q*g*J,rhoI),(numpy.ones(shape=(len(rhoE),))*g),(numpy.ones(shape=(len(rhoE),))*I/theta)


#pythran export run_transient_GLNetEI_adaptthresh(list float,list int,list float,list int,list float,list float,str,int,float,float,float,int,int,float,float,float,float,float,float,float,float,float,float,float,float,float)
def run_transient_GLNetEI_adaptthresh(VE,XE,VI,XI,thetaE,thetaI,weightDynType,tTrans,rhoETemp,rhoITemp,N_fl,pN,qN,pN_fl,qN_fl,Iext,mu,J,Gamma,I,p,q,tauTinv,uT,gJ,P_firing_poisson):
    if weightDynType == "simple":
        weightAdapt = weightAdapt_decrease
    elif weightDynType == "coupled":
        weightAdapt = weightAdapt_increase
    rhoE_prev = rhoETemp
    rhoI_prev = rhoITemp
    for t in range(1,tTrans):
        sum_XE = 0.0
        sum_XI = 0.0
        #Iext = 0.0 # stimulus
        thetaMean = 0.0
        for i in range(pN):
            VE[i],XE[i],thetaE[i] = GLNetEI_adaptthresh_iter(VE[i],XE[i],rhoE_prev,rhoI_prev,Iext,mu,thetaE[i],J,Gamma,I,gJ,p,q,tauTinv,uT,P_firing_poisson)
            sum_XE = sum_XE + XE[i]
            thetaMean = thetaMean + thetaE[i]
        for i in range(qN):
            VI[i],XI[i],thetaI[i] = GLNetEI_adaptthresh_iter(VI[i],XI[i],rhoE_prev,rhoI_prev,Iext,mu,thetaI[i],J,Gamma,I,gJ,p,q,tauTinv,uT,0.0)
            sum_XI = sum_XI + XI[i]
            thetaMean = thetaMean + thetaI[i]
        rhoE_prev = sum_XE/pN_fl
        rhoI_prev = sum_XI/qN_fl
        thetaMean = thetaMean/N_fl
    return rhoE_prev,rhoI_prev,thetaMean,VE,XE,VI,XI

#pythran export run_transient_GLNetEI_aval(float list,int list,float list,int list,int,float,float,int,int,float,float,float,float,float,float,float,float,float,float,float,float,float,float)
def run_transient_GLNetEI_aval(VE,XE,VI,XI,tTrans,rhoETemp,rhoITemp,pN,qN,pN_fl,qN_fl,Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson):
    rhoE_prev = rhoETemp
    rhoI_prev = rhoITemp
    for t in range(1,tTrans):
        if (rhoE_prev + rhoI_prev) < 1e-16:
            XE[0] = 1 # causes a spike in an excitatory neuron if the activity is less than the floating-point double precision
            rhoE_prev = 1.0 / pN_fl
        sum_XE = 0.0
        for i in range(pN):
            VE[i],XE[i],_ = GLNetEI_iter(VE[i],XE[i],rhoE_prev,rhoI_prev,Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
            sum_XE = sum_XE + XE[i]
        sum_XI = 0.0
        for i in range(qN):
            VI[i],XI[i],_ = GLNetEI_iter(VI[i],XI[i],rhoE_prev,rhoI_prev,Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,0.0)
            sum_XI = sum_XI + XI[i]
        rhoE_prev = sum_XE/pN_fl
        rhoI_prev = sum_XI/qN_fl
    return rhoE_prev,rhoI_prev,VE,XE,VI,XI

#pythran export run_transient_GLNetEI_adapt(list float,list int,list float,list int,list float,list float,str,int,float,float,float,int,int,float,float,float,float,float,float,float,float,float,float,float,float,float,float,float)
def run_transient_GLNetEI_adapt(VE,XE,VI,XI,thetaE,thetaI,weightDynType,tTrans,rhoETemp,rhoITemp,N_fl,pN,qN,pN_fl,qN_fl,Iext,mu,J,Gamma,I,p,q,tauTinv,uT,tauWinv,uW,A,P_firing_poisson):
    if weightDynType == "simple":
        weightAdapt = weightAdapt_decrease
    elif weightDynType == "coupled":
        weightAdapt = weightAdapt_increase
    rhoE_prev = rhoETemp
    rhoI_prev = rhoITemp
    for t in range(1,tTrans):
        W_I = weightAdapt(W_I,A,tauWinv,uW,rhoE_prev,rhoI_prev) # both the E and I subnetworks receive the same inhibitory adapted input
        sum_XE = 0.0
        sum_XI = 0.0
        #Iext = 0.0 # stimulus
        thetaMean = 0.0
        for i in range(pN):
            VE[i],XE[i],thetaE[i] = GLNetEI_adaptthresh_iter(VE[i],XE[i],rhoE_prev,rhoI_prev,Iext,mu,thetaE[i],J,Gamma,I,W_I,p,q,tauTinv,uT,P_firing_poisson)
            sum_XE = sum_XE + XE[i]
            thetaMean = thetaMean + thetaE[i]
        for i in range(qN):
            VI[i],XI[i],thetaI[i] = GLNetEI_adaptthresh_iter(VI[i],XI[i],rhoE_prev,rhoI_prev,Iext,mu,thetaI[i],J,Gamma,I,W_I,p,q,tauTinv,uT,0.0)
            sum_XI = sum_XI + XI[i]
            thetaMean = thetaMean + thetaI[i]
        rhoE_prev = sum_XE/pN_fl
        rhoI_prev = sum_XI/qN_fl
        thetaMean = thetaMean/N_fl
    return rhoE_prev,rhoI_prev,thetaMean,W_I,VE,XE,VI,XI

#pythran export run_transient_GLNetEI_static(float list,int list,float list,int list,int,float,float,int,int,float,float,float,float,float,float,float,float,float,float,float,float,float,float)
def run_transient_GLNetEI_static(VE,XE,VI,XI,tTrans,rhoETemp,rhoITemp,pN,qN,pN_fl,qN_fl,Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson):
    rhoE_prev = rhoETemp
    rhoI_prev = rhoITemp
    for t in range(1,tTrans):
        sum_XE = 0.0
        for i in range(pN):
            VE[i],XE[i],_ = GLNetEI_iter(VE[i],XE[i],rhoE_prev,rhoI_prev,Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
            sum_XE = sum_XE + XE[i]
        sum_XI = 0.0
        for i in range(qN):
            VI[i],XI[i],_ = GLNetEI_iter(VI[i],XI[i],rhoE_prev,rhoI_prev,Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,0.0)
            sum_XI = sum_XI + XI[i]
        rhoE_prev = sum_XE/pN_fl
        rhoI_prev = sum_XI/qN_fl
    return rhoE_prev,rhoI_prev,VE,XE,VI,XI

#pythran export save_initial_spkdata(int list,int list,int,int)
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
        if XE[i] == 1:
            spkData = save_spk_data(spkData,0,i)
        i+=1
    i = 0
    while i < qN:
        if XI[i] == 1:
            spkData = save_spk_data(spkData,0,i+pN)
        i+=1
    return spkData

#pythran export generate_IC_spikes(int,int,int,bool)
def generate_IC_spikes(X0,N,K,is_random=False):
    """generates a list X of zeros with len N containing K ones
    """
    if (X0 > 0) and is_random:
        X = [0.0 for i in range(N)]
        for k in random.sample(range(N),K):
            X[k] = 1.0
    else:
        X = [X0 for i in range(N)]
    return X

#pythran export generate_random_net_fixed_input(int,int)
def generate_random_net_fixed_input(K_in,N):
    """
    ##################
    #BUILD RANDOM NETWORK WITH constant k_in neighbors
    #Neurons cannot have repeated neighbors
    ##################
    returns list where each entry is the list of neighbor indices
    """
    return [random.sample(range(N),K_in) for _ in range(N)]

#pythran export GLNetEI_adaptthresh_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
def GLNetEI_adaptthresh_iter(V,X,rhoE,rhoI,Iext,mu,theta,J,Gamma,I,W_I,p,q,tauTinv,uT,P_poisson):
    theta = theta * (1.0 - tauTinv + uT*X)
    V = (mu*V + I + Iext + J*p*rhoE - q*W_I*rhoI)*(1.0-X)
    X = float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

#pythran export GLNetEI_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
def GLNetEI_iter(V,X,rhoE,rhoI,Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_poisson):
    V = (mu*V + I + Iext + J*(p*rhoE - q*g*rhoI))*(1.0-X)
    X = float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

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