import random
import numpy

#pythran export RunSimulation_aval(int, int, int, float, float, float, float, float, float, bool, float, float, bool, float, float, float, float, float, float, float, float, float, float, float, float, float, float, bool, int, str, float, bool, str)
#pythran export RunSimulation_adapt(int, int, int, float, float, float, float, float, float, bool, float, float, bool, float, float, float, float, float, float, float, float, float, float, float, float, float, float, bool, int, str, float, bool, str)
#pythran export RunSimulation_static(int, int, int, float, float, float, float, float, float, bool, float, float, bool, float, float, float, float, float, float, float, float, float, float, float, float, float, float, bool, int, str, float, bool, str)
#pythran export RunSimulation_adaptthresh(int, int, int, float, float, float, float, float, float, bool, float, float, bool, float, float, float, float, float, float, float, float, float, float, float, float, float, float, bool, int, str, float, bool, str)
#pythran export GLNetEI_adaptthresh_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
#pythran export GLNetEI_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
#pythran export weightAdapt_decrease(float, float, float, float, float, float)
#pythran export weightAdapt_increase(float, float, float, float, float, float)
#pythran export PHI(float, float, float)
#pythran export multvecelem(float list, float list)
#pythran export PoissonProcess_firingprob(float)
#pythran export save_spk_data_fake((int,int) list,int,int)
#pythran export save_spk_data((int,int) list,int,int)
#pythran export write_spk_data_fake(int,int)

def RunSimulation_adaptthresh(N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson,writeOnRun,spkFileName):
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
    if (XE0 > 0) and XE0Rand:
        XE = [0.0 for i in range(pN)]
        for k in random.sample(range(pN),k=int(fXE0*pN)):
            XE[k] = 1.0
    else:
        XE = [XE0 for i in range(pN)]

    VI = [abs(random.gauss(VI0,VI0Std)) for i in range(qN)]
    thetaI = [theta for i in range(qN)]
    if (XI0 > 0) and XI0Rand:
        XI = [0.0 for i in range(qN)]
        for k in random.sample(range(qN),k=int(fXI0*qN)):
            XI[k] = 1.0
    else:
        XI = [XI0 for i in range(qN)]

    # setting initial condition
    rhoETemp = float(sum(XE))/pN_fl
    rhoITemp = float(sum(XI))/qN_fl

    thetaMean = theta

    # running transient time
    if tTrans > 0:
        dummyVar = 0.0
        rhoE = [0.0 for i in range(tTrans)]
        rhoI = [0.0 for i in range(tTrans)]
        rhoE[0] = rhoETemp
        rhoI[0] = rhoITemp
        for t in range(1,tTrans):
            thetaMean = 0.0
            #Iext = 0.0 # stimulus
            for i in range(pN):
                VE[i],XE[i],thetaE[i] = GLNetEI_adaptthresh_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,thetaE[i],J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
                rhoE[t] = rhoE[t] + XE[i]
                thetaMean += thetaE[i]
            for i in range(qN):
                VI[i],XI[i],thetaI[i] = GLNetEI_adaptthresh_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,thetaI[i],J,Gamma,I,g,p,q,tauTinv,uT,0.0)
                rhoI[t] = rhoI[t] + XI[i]
                thetaMean += thetaI[i]
            rhoE[t] = rhoE[t]/pN_fl
            rhoI[t] = rhoI[t]/qN_fl
            thetaMean = thetaMean/N_fl
        rhoETemp = rhoE[-1]
        rhoITemp = rhoI[-1]
    
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
            #spkData = [[0 for i in range(nNeuronsSpk)] for t in range(Tmax)]
            #spkData[0] = XE[:pN_s] + XI[:qN_s]
            # spkData is a list of tuples
            # where each tuple records (time step, neuron index) for each firing
            # the pythran breaks with the line below, probably due to enumerate and conditional for loop
            #spkData = [ [0,i] for i,x in enumerate(XE[:pN_s]) if x == 1 ] + [ [0,i+pN_s] for i,x in enumerate(XI[:qN_s]) if x == 1 ]
            write_spk_time = write_spk_data_fake
            save_spk_time = save_spk_data
            spkData = []
            i = 0
            while i < pN_s:
                if XE[i] == 1:
                    spkData = save_spk_time(spkData,0,i)
                i+=1
            i = 0
            while i < qN_s:
                if XI[i] == 1:
                    spkData = save_spk_time(spkData,0,i+pN_s)
                i+=1
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
            VE[i],XE[i],thetaE[i] = GLNetEI_adaptthresh_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,thetaE[i],J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
            rhoE[t] = rhoE[t] + XE[i]
            thetaMean += thetaE[i]
            if (i < pN_s) and XE[i]:
                spkData = save_spk_time(spkData,t,i) #spkData.append((t,i)) #spkData[t][i] = XE[i]
                write_spk_time(t,i)
        for i in range(qN):
            VI[i],XI[i],thetaI[i] = GLNetEI_adaptthresh_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,thetaI[i],J,Gamma,I,g,p,q,tauTinv,uT,0.0)
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

def RunSimulation_aval(N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson,writeOnRun,spkFileName):
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
    if (XE0 > 0) and XE0Rand:
        XE = [0.0 for i in range(pN)]
        for k in random.sample(range(pN),k=int(fXE0*pN)):
            XE[k] = 1.0
    else:
        XE = [XE0 for i in range(pN)]

    VI = [abs(random.gauss(VI0,VI0Std)) for i in range(qN)]
    if (XI0 > 0) and XI0Rand:
        XI = [0.0 for i in range(qN)]
        for k in random.sample(range(qN),k=int(fXI0*qN)):
            XI[k] = 1.0
    else:
        XI = [XI0 for i in range(qN)]

    # setting initial condition
    rhoETemp = float(sum(XE))/pN_fl
    rhoITemp = float(sum(XI))/qN_fl

    # running transient time
    if tTrans > 0:
        rhoE = [0.0 for i in range(tTrans)]
        rhoI = [0.0 for i in range(tTrans)]
        rhoE[0] = rhoETemp
        rhoI[0] = rhoITemp
        for t in range(1,tTrans):
            if (rhoE[t-1] + rhoI[t-1]) < 1e-16:
                XE[0] = 1 # causes a spike in an excitatory neuron if the activity is less than the floating-point double precision
                rhoE[t-1] = 1.0 / pN_fl
            for i in range(pN):
                VE[i],XE[i],_ = GLNetEI_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
                rhoE[t] = rhoE[t] + XE[i]
            for i in range(qN):
                VI[i],XI[i],_ = GLNetEI_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,0.0)
                rhoI[t] = rhoI[t] + XI[i]
            rhoE[t] = rhoE[t]/pN_fl
            rhoI[t] = rhoI[t]/qN_fl
        rhoETemp = rhoE[-1]
        rhoITemp = rhoI[-1]
    
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
            #spkData = [[0 for i in range(nNeuronsSpk)] for t in range(Tmax)]
            #spkData[0] = XE[:pN_s] + XI[:qN_s]
            # spkData is a list of tuples
            # where each tuple records (time step, neuron index) for each firing
            # the pythran breaks with the line below, probably due to enumerate and conditional for loop
            #spkData = [ [0,i] for i,x in enumerate(XE[:pN_s]) if x == 1 ] + [ [0,i+pN_s] for i,x in enumerate(XI[:qN_s]) if x == 1 ]
            write_spk_time = write_spk_data_fake
            save_spk_time = save_spk_data
            spkData = []
            i = 0
            while i < pN_s:
                if XE[i] == 1:
                    spkData = save_spk_time(spkData,0,i)
                i+=1
            i = 0
            while i < qN_s:
                if XI[i] == 1:
                    spkData = save_spk_time(spkData,0,i+pN_s)
                i+=1
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


def RunSimulation_adapt(N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson,writeOnRun,spkFileName):

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
    if (XE0 > 0) and XE0Rand:
        XE = [0.0 for i in range(pN)]
        for k in random.sample(range(pN),k=int(fXE0*pN)):
            XE[k] = 1.0
    else:
        XE = [XE0 for i in range(pN)]

    VI = [abs(random.gauss(VI0,VI0Std)) for i in range(qN)]
    thetaI = [theta for i in range(qN)]
    if (XI0 > 0) and XI0Rand:
        XI = [0.0 for i in range(qN)]
        for k in random.sample(range(qN),k=int(fXI0*qN)):
            XI[k] = 1.0
    else:
        XI = [XI0 for i in range(qN)]

    # setting initial conditions
    rhoETemp = float(sum(XE))/pN_fl
    rhoITemp = float(sum(XI))/qN_fl
    W_I = g*J
    thetaMean = theta
    
    # running transient time
    if tTrans > 0:
        rhoE = [0.0 for i in range(tTrans)]
        rhoI = [0.0 for i in range(tTrans)]
        rhoE[0] = rhoETemp
        rhoI[0] = rhoITemp
        for t in range(1,tTrans):
            W_I = weightAdapt(W_I,A,tauWinv,uW,rhoE[t-1],rhoI[t-1]) # both the E and I subnetworks receive the same inhibitory adapted input
            #Iext = 0.0 # stimulus
            thetaMean = 0.0
            for i in range(pN):
                VE[i],XE[i],thetaE[i] = GLNetEI_adaptthresh_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,thetaE[i],J,Gamma,I,W_I,p,q,tauTinv,uT,P_firing_poisson)
                rhoE[t] = rhoE[t] + XE[i]
                thetaMean = thetaMean + thetaE[i]
            for i in range(qN):
                VI[i],XI[i],thetaI[i] = GLNetEI_adaptthresh_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,thetaI[i],J,Gamma,I,W_I,p,q,tauTinv,uT,0.0)
                rhoI[t] = rhoI[t] + XI[i]
                thetaMean = thetaMean + thetaI[i]
            rhoE[t] = rhoE[t]/pN_fl
            rhoI[t] = rhoI[t]/qN_fl
            thetaMean = thetaMean/N_fl

        rhoETemp = rhoE[-1]
        rhoITemp = rhoI[-1]
    
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
            #spkData = [[0 for i in range(nNeuronsSpk)] for t in range(Tmax)]
            #spkData[0] = XE[:pN_s] + XI[:qN_s]
            # spkData is a list of tuples
            # where each tuple records (time step, neuron index) for each firing
            # the pythran breaks with the line below, probably due to enumerate and conditional for loop
            #spkData = [ [0,i] for i,x in enumerate(XE[:pN_s]) if x == 1 ] + [ [0,i+pN_s] for i,x in enumerate(XI[:qN_s]) if x == 1 ]
            write_spk_time = write_spk_data_fake
            save_spk_time = save_spk_data
            spkData = []
            i = 0
            while i < pN_s:
                if XE[i] == 1:
                    spkData = save_spk_time(spkData,0,i)
                i+=1
            i = 0
            while i < qN_s:
                if XI[i] == 1:
                    spkData = save_spk_time(spkData,0,i+pN_s)
                i+=1
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

def RunSimulation_static(N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,fXE0,XE0Rand,XI0,fXI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson,writeOnRun,spkFileName):
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
    if (XE0 > 0) and XE0Rand:
        XE = [0.0 for i in range(pN)]
        for k in random.sample(range(pN),k=int(fXE0*pN)):
            XE[k] = 1.0
    else:
        XE = [XE0 for i in range(pN)]

    VI = [abs(random.gauss(VI0,VI0Std)) for i in range(qN)]
    if (XI0 > 0) and XI0Rand:
        XI = [0.0 for i in range(qN)]
        for k in random.sample(range(qN),k=int(fXI0*qN)):
            XI[k] = 1.0
    else:
        XI = [XI0 for i in range(qN)]

    # setting initial condition
    rhoETemp = float(sum(XE))/pN_fl
    rhoITemp = float(sum(XI))/qN_fl

    # running transient time
    if tTrans > 0:
        rhoE = [0.0 for i in range(tTrans)]
        rhoI = [0.0 for i in range(tTrans)]
        rhoE[0] = rhoETemp
        rhoI[0] = rhoITemp
        for t in range(1,tTrans):
            #Iext = 0.0 # stimulus
            for i in range(pN):
                VE[i],XE[i],_ = GLNetEI_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
                rhoE[t] = rhoE[t] + XE[i]
            for i in range(qN):
                VI[i],XI[i],_ = GLNetEI_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,0.0)
                rhoI[t] = rhoI[t] + XI[i]
            rhoE[t] = rhoE[t]/pN_fl
            rhoI[t] = rhoI[t]/qN_fl
        rhoETemp = rhoE[-1]
        rhoITemp = rhoI[-1]
    
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
            #spkData = [[0 for i in range(nNeuronsSpk)] for t in range(Tmax)]
            #spkData[0] = XE[:pN_s] + XI[:qN_s]
            # spkData is a list of tuples
            # where each tuple records (time step, neuron index) for each firing
            # the pythran breaks with the line below, probably due to enumerate and conditional for loop
            #spkData = [ [0,i] for i,x in enumerate(XE[:pN_s]) if x == 1 ] + [ [0,i+pN_s] for i,x in enumerate(XI[:qN_s]) if x == 1 ]
            write_spk_time = write_spk_data_fake
            save_spk_time = save_spk_data
            spkData = []
            i = 0
            while i < pN_s:
                if XE[i] == 1:
                    spkData = save_spk_time(spkData,0,i)
                i+=1
            i = 0
            while i < qN_s:
                if XI[i] == 1:
                    spkData = save_spk_time(spkData,0,i+pN_s)
                i+=1
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

def GLNetEI_adaptthresh_iter(V,X,rhoE,rhoI,Iext,mu,theta,J,Gamma,I,W_I,p,q,tauTinv,uT,P_poisson):
    theta = theta * (1.0 - tauTinv + uT*X)
    V = (mu*V + I + Iext + J*p*rhoE - q*W_I*rhoI)*(1.0-X)
    X = float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

def GLNetEI_iter(V,X,rhoE,rhoI,Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_poisson):
    V = (mu*V + I + Iext + J*(p*rhoE - q*g*rhoI))*(1.0-X)
    X = float(random.random() < (PHI(V,theta,Gamma) * (1.0-P_poisson) + P_poisson )) # the neuron fires if random < Phi(V) + P_poisson - Phi(V)*P_poisson, because Phi(V) and P_poisson are independent processes with nonzero intersection
    return V,X,theta

def weightAdapt_decrease(W,A,tauWinv,uW,rhoE,rhoI):
    return W * (1.0 - tauWinv - uW*rhoI) + tauWinv * A

def weightAdapt_increase(W,A,tauWinv,uW,rhoE,rhoI):
    return W * (1.0 - tauWinv + uW*rhoE) + tauWinv * A

def PHI(V,theta,Gamma):
    tg = theta+1.0/Gamma
    return Gamma*(V-theta)*float(V>theta)*float(V<tg)+float(V>=tg)

def multvecelem(x,y):
    return [x[i]*yy for i,yy in enumerate(y)]

def PoissonProcess_firingprob(r):
    return 1.0-numpy.exp(-r) # probability of firing is constant

def save_spk_data_fake(s,t,k):
    return s

def save_spk_data(s,t,k):
    # s -> list to append t_k
    # t -> spike time index
    # k -> neuron index that fired at t
    s.append((t,k))
    return s

def write_spk_data_fake(t,k):
    return None