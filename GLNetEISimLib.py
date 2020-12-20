import random
import numpy

#pythran export RunSimulation_aval(int, int, int, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, bool, int, str, float)
#pythran export RunSimulation_adapt(int, int, int, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, bool, int, str, float)
#pythran export RunSimulation_static(int, int, int, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, bool, int, str, float)
#pythran export RunSimulation_adaptthresh(int, int, int, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, bool, int, str, float)
#pythran export GLNetEI_adapt_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
#pythran export GLNetEI_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)
#pythran export weightAdapt_decrease(float, float, float, float, float, float)
#pythran export weightAdapt_increase(float, float, float, float, float, float)
#pythran export PHI(float, float, float)
#pythran export multvecelem(float list, float list)
#pythran export PoissonProcess_firingprob(float)

def RunSimulation_adaptthresh(N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,XE0Rand,XI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauWinv,uW,tauTinv,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson):

    pN = int(p*N)
    qN = N - pN

    pN_fl = float(pN)
    qN_fl = float(qN)

    pN_s = int(p*nNeuronsSpk) # record only pN_s neurons from the excitatory population for raster plot
    qN_s = nNeuronsSpk - pN_s # record only qN_s neurons from the inhibitory population for raster plot

    P_firing_poisson = PoissonProcess_firingprob(rPoisson)

    # setting initial conditions
    VE = [abs(random.gauss(VE0,VE0Std)) for i in range(pN)]
    if XE0Rand:
        XE = [random.randint(0,1) for i in range(pN)]
    else:
        XE = [0 for i in range(pN)]

    VI = [abs(random.gauss(VI0,VI0Std)) for i in range(qN)]
    if XI0Rand:
        XI = [random.randint(0,1) for i in range(qN)]
    else:
        XI = [0 for i in range(qN)]

    # setting initial condition
    rhoETemp = 0.0
    rhoITemp = 0.0

    # running transient time
    if tTrans > 0:
        dummyVar = 0.0
        rhoE = [0.0 for i in range(tTrans)]
        rhoI = [0.0 for i in range(tTrans)]
        rhoE[0] = float(sum(XE))/pN_fl
        rhoI[0] = float(sum(XI))/qN_fl
        for t in range(1,tTrans):
            #Iext = 0.0 # stimulus
            for i in range(pN):
                VE[i],XE[i],dummyVar = GLNetEI_adapt_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
                rhoE[t] = rhoE[t] + XE[i]
            for i in range(qN):
                VI[i],XI[i],dummyVar = GLNetEI_adapt_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,0.0)
                rhoI[t] = rhoI[t] + XI[i]
            rhoE[t] = rhoE[t]/pN_fl
            rhoI[t] = rhoI[t]/qN_fl
        rhoETemp = rhoE[-1]
        rhoITemp = rhoI[-1]
    
    # subtracting transient time from total time
    Tmax = Tmax - tTrans 

    # preparing variable for recording spiking data (if needed)
    if saveSpikingData:
        spkData = [[0 for i in range(nNeuronsSpk)] for t in range(Tmax)]
        spkData[0] = XE[:pN_s] + XI[:qN_s]
    else:
        spkData = []

    # running main simulation
    rhoE = [0.0 for i in range(Tmax)]
    rhoI = [0.0 for i in range(Tmax)]
    rhoE[0] = rhoETemp
    rhoI[0] = rhoITemp
    for t in range(1,Tmax):
        #Iext = 0.0 # stimulus
        for i in range(pN):
            VE[i],XE[i],dummyVar = GLNetEI_adapt_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
            rhoE[t] = rhoE[t] + XE[i]
            if saveSpikingData and (i < pN_s):
                spkData[t][i] = XE[i]
        for i in range(qN):
            VI[i],XI[i],dummyVar = GLNetEI_adapt_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,0.0)
            rhoI[t] = rhoI[t] + XI[i]
            if saveSpikingData and (i < qN_s):
                spkData[t][i+pN_s] = XI[i]
        rhoE[t] = rhoE[t]/pN_fl
        rhoI[t] = rhoI[t]/qN_fl
    # end of time loop
    return rhoE,rhoI,spkData,[p*J*r for r in rhoE],[q*g*J*r for r in rhoI],[g for r in rhoE],[I/theta for r in rhoE]
    #return rhoE,rhoI,spkData,numpy.multiply(p*J,rhoE),numpy.multiply(q*g*J,rhoI),(numpy.ones(shape=(len(rhoE),))*g),(numpy.ones(shape=(len(rhoE),))*I/theta)

def RunSimulation_aval(N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,XE0Rand,XI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauWinv,uW,tauTinv,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson):

    pN = int(p*N)
    qN = N - pN

    pN_fl = float(pN)
    qN_fl = float(qN)

    pN_s = int(p*nNeuronsSpk) # record only pN_s neurons from the excitatory population for raster plot
    qN_s = nNeuronsSpk - pN_s # record only qN_s neurons from the inhibitory population for raster plot

    P_firing_poisson = PoissonProcess_firingprob(rPoisson)

    # setting initial conditions
    VE = [abs(random.gauss(VE0,VE0Std)) for i in range(pN)]
    if XE0Rand:
        XE = [random.randint(0,1) for i in range(pN)]
    else:
        XE = [0 for i in range(pN)]

    VI = [abs(random.gauss(VI0,VI0Std)) for i in range(qN)]
    if XI0Rand:
        XI = [random.randint(0,1) for i in range(qN)]
    else:
        XI = [0 for i in range(qN)]

    # setting initial condition
    rhoETemp = 0.0
    rhoITemp = 0.0

    # running transient time
    if tTrans > 0:
        dummyVar = 0.0
        rhoE = [0.0 for i in range(tTrans)]
        rhoI = [0.0 for i in range(tTrans)]
        rhoE[0] = float(sum(XE))/pN_fl
        rhoI[0] = float(sum(XI))/qN_fl
        for t in range(1,tTrans):
            if (rhoE[t-1] + rhoI[t-1]) < 1e-16:
                XE[0] = 1 # causes a spike in an excitatory neuron if the activity is less than the floating-point double precision
                rhoE[t-1] = 1.0 / pN_fl
            for i in range(pN):
                VE[i],XE[i],dummyVar = GLNetEI_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
                rhoE[t] = rhoE[t] + XE[i]
            for i in range(qN):
                VI[i],XI[i],dummyVar = GLNetEI_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,0.0)
                rhoI[t] = rhoI[t] + XI[i]
            rhoE[t] = rhoE[t]/pN_fl
            rhoI[t] = rhoI[t]/qN_fl
        rhoETemp = rhoE[-1]
        rhoITemp = rhoI[-1]
    
    # subtracting transient time from total time
    Tmax = Tmax - tTrans 

    # preparing variable for recording spiking data (if needed)
    if saveSpikingData:
        spkData = [[0 for i in range(nNeuronsSpk)] for t in range(Tmax)]
        spkData[0] = XE[:pN_s] + XI[:qN_s]
    else:
        spkData = []

    # running main simulation
    rhoE = [0.0 for i in range(Tmax)]
    rhoI = [0.0 for i in range(Tmax)]
    rhoE[0] = rhoETemp
    rhoI[0] = rhoITemp
    for t in range(1,Tmax):
        if (rhoE[t-1] + rhoI[t-1]) < 1e-16:
            XE[0] = 1 # causes a spike in an excitatory neuron if the activity is less than the floating-point double precision
            rhoE[t-1] = 1.0 / pN_fl
        for i in range(pN):
            VE[i],XE[i],dummyVar = GLNetEI_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
            rhoE[t] = rhoE[t] + XE[i]
            if saveSpikingData and (i < pN_s):
                spkData[t][i] = XE[i]
        for i in range(qN):
            VI[i],XI[i],dummyVar = GLNetEI_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,0.0)
            rhoI[t] = rhoI[t] + XI[i]
            if saveSpikingData and (i < qN_s):
                spkData[t][i+pN_s] = XI[i]
        rhoE[t] = rhoE[t]/pN_fl
        rhoI[t] = rhoI[t]/qN_fl
    # end of time loop
    return rhoE,rhoI,spkData,[p*J*r for r in rhoE],[q*g*J*r for r in rhoI],[g for r in rhoE],[I/theta for r in rhoE]
    #return rhoE,rhoI,spkData,numpy.multiply(p*J,rhoE),numpy.multiply(q*g*J,rhoI),(numpy.ones(shape=(len(rhoE),))*g),(numpy.ones(shape=(len(rhoE),))*I/theta)


def RunSimulation_adapt(N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,XE0Rand,XI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauWinv,uW,tauTinv,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson):

    if weightDynType == "simple":
        weightAdapt = weightAdapt_decrease
    elif weightDynType == "coupled":
        weightAdapt = weightAdapt_increase
    else:
        raise ValueError('weightDynType is unknown')

    pN = int(p*N)
    qN = N - pN

    N_fl = float(N)
    pN_fl = float(pN)
    qN_fl = float(qN)

    pN_s = int(p*nNeuronsSpk) # record only pN_s neurons from the excitatory population for raster plot
    qN_s = nNeuronsSpk - pN_s # record only qN_s neurons from the inhibitory population for raster plot

    P_firing_poisson = PoissonProcess_firingprob(rPoisson)

    # setting initial conditions
    VE = [abs(random.gauss(VE0,VE0Std)) for i in range(pN)]
    thetaE = [theta for i in range(pN)]
    if XE0Rand:
        XE = [float(random.randint(0,1)) for i in range(pN)]
    else:
        XE = [0.0 for i in range(pN)]

    VI = [abs(random.gauss(VI0,VI0Std)) for i in range(qN)]
    thetaI = [theta for i in range(qN)]
    if XI0Rand:
        XI = [float(random.randint(0,1)) for i in range(qN)]
    else:
        XI = [0.0 for i in range(qN)]

    # setting initial conditions
    rhoETemp = 0.0 
    rhoITemp = 0.0 
    W_I = g*J
    thetaMean = theta
    
    # running transient time
    if tTrans > 0:
        rhoE = [0.0 for i in range(tTrans)]
        rhoI = [0.0 for i in range(tTrans)]
        rhoE[0] = float(sum(XE))/pN_fl
        rhoI[0] = float(sum(XI))/qN_fl
        for t in range(1,tTrans):
            W_I = weightAdapt(W_I,A,tauWinv,uW,rhoE[t-1],rhoI[t-1]) # both the E and I subnetworks receive the same inhibitory adapted input
            #Iext = 0.0 # stimulus
            thetaMean = 0.0
            for i in range(pN):
                VE[i],XE[i],thetaE[i] = GLNetEI_adapt_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,thetaE[i],J,Gamma,I,W_I,p,q,tauTinv,uT,P_firing_poisson)
                rhoE[t] = rhoE[t] + XE[i]
                thetaMean = thetaMean + thetaE[i]
            for i in range(qN):
                VI[i],XI[i],thetaI[i] = GLNetEI_adapt_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,thetaI[i],J,Gamma,I,W_I,p,q,tauTinv,uT,0.0)
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
        spkData = [[0 for i in range(nNeuronsSpk)] for t in range(Tmax)]
        spkData[0] = XE[:pN_s] + XI[:qN_s]
    else:
        spkData = []

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
            VE[i],XE[i],thetaE[i] = GLNetEI_adapt_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,thetaE[i],J,Gamma,I,W_I,p,q,tauTinv,uT,P_firing_poisson)
            rhoE[t] = rhoE[t] + XE[i]
            thetaMean = thetaMean + thetaE[i]
            if saveSpikingData and (i < pN_s):
                spkData[t][i] = XE[i]
        for i in range(qN):
            VI[i],XI[i],thetaI[i] = GLNetEI_adapt_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,thetaI[i],J,Gamma,I,W_I,p,q,tauTinv,uT,0.0)
            rhoI[t] = rhoI[t] + XI[i]
            thetaMean = thetaMean + thetaI[i]
            if saveSpikingData and (i < qN_s):
                spkData[t][i+pN_s] = XI[i]
        rhoE[t] = rhoE[t]/pN_fl
        rhoI[t] = rhoI[t]/qN_fl
        W_I_data[t] = W_I
        theta_data[t] = thetaMean/N_fl
    # end of time loop
    return rhoE,rhoI,spkData,[p*J*r for r in rhoE],[q*r for r in multvecelem(W_I_data,rhoI)],[r/J for r in W_I_data],[I/r for r in theta_data]
    #return rhoE,rhoI,spkData,numpy.multiply(p*J,rhoE),(q*numpy.multiply(W_I_data,rhoI)),numpy.divide(W_I_data,J),numpy.divide(I,theta_data)

def RunSimulation_static(N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,XE0Rand,XI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauWinv,uW,tauTinv,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson):

    pN = int(p*N)
    qN = N - pN

    pN_fl = float(pN)
    qN_fl = float(qN)

    pN_s = int(p*nNeuronsSpk) # record only pN_s neurons from the excitatory population for raster plot
    qN_s = nNeuronsSpk - pN_s # record only qN_s neurons from the inhibitory population for raster plot

    P_firing_poisson = PoissonProcess_firingprob(rPoisson)

    # setting initial conditions
    VE = [abs(random.gauss(VE0,VE0Std)) for i in range(pN)]
    if XE0Rand:
        XE = [random.randint(0,1) for i in range(pN)]
    else:
        XE = [0 for i in range(pN)]

    VI = [abs(random.gauss(VI0,VI0Std)) for i in range(qN)]
    if XI0Rand:
        XI = [random.randint(0,1) for i in range(qN)]
    else:
        XI = [0 for i in range(qN)]

    # setting initial condition
    rhoETemp = 0.0
    rhoITemp = 0.0

    # running transient time
    if tTrans > 0:
        dummyVar = 0.0
        rhoE = [0.0 for i in range(tTrans)]
        rhoI = [0.0 for i in range(tTrans)]
        rhoE[0] = float(sum(XE))/pN_fl
        rhoI[0] = float(sum(XI))/qN_fl
        for t in range(1,tTrans):
            #Iext = 0.0 # stimulus
            for i in range(pN):
                VE[i],XE[i],dummyVar = GLNetEI_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
                rhoE[t] = rhoE[t] + XE[i]
            for i in range(qN):
                VI[i],XI[i],dummyVar = GLNetEI_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,0.0)
                rhoI[t] = rhoI[t] + XI[i]
            rhoE[t] = rhoE[t]/pN_fl
            rhoI[t] = rhoI[t]/qN_fl
        rhoETemp = rhoE[-1]
        rhoITemp = rhoI[-1]
    
    # subtracting transient time from total time
    Tmax = Tmax - tTrans 

    # preparing variable for recording spiking data (if needed)
    if saveSpikingData:
        spkData = [[0 for i in range(nNeuronsSpk)] for t in range(Tmax)]
        spkData[0] = XE[:pN_s] + XI[:qN_s]
    else:
        spkData = []

    # running main simulation
    rhoE = [0.0 for i in range(Tmax)]
    rhoI = [0.0 for i in range(Tmax)]
    rhoE[0] = rhoETemp
    rhoI[0] = rhoITemp
    for t in range(1,Tmax):
        #Iext = 0.0 # stimulus
        for i in range(pN):
            VE[i],XE[i],dummyVar = GLNetEI_iter(VE[i],XE[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,P_firing_poisson)
            rhoE[t] = rhoE[t] + XE[i]
            if saveSpikingData and (i < pN_s):
                spkData[t][i] = XE[i]
        for i in range(qN):
            VI[i],XI[i],dummyVar = GLNetEI_iter(VI[i],XI[i],rhoE[t-1],rhoI[t-1],Iext,mu,theta,J,Gamma,I,g,p,q,tauTinv,uT,0.0)
            rhoI[t] = rhoI[t] + XI[i]
            if saveSpikingData and (i < qN_s):
                spkData[t][i+pN_s] = XI[i]
        rhoE[t] = rhoE[t]/pN_fl
        rhoI[t] = rhoI[t]/qN_fl
    # end of time loop
    return rhoE,rhoI,spkData,[p*J*r for r in rhoE],[q*g*J*r for r in rhoI],[g for r in rhoE],[I/theta for r in rhoE]
    #return rhoE,rhoI,spkData,numpy.multiply(p*J,rhoE),numpy.multiply(q*g*J,rhoI),(numpy.ones(shape=(len(rhoE),))*g),(numpy.ones(shape=(len(rhoE),))*I/theta)

def GLNetEI_adapt_iter(V,X,rhoE,rhoI,Iext,mu,theta,J,Gamma,I,W_I,p,q,tauTinv,uT,P_poisson):
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
