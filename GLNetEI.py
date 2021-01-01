# -*- coding: utf-8 -*-
import os
import argparse
import numpy
import time
import ioGLNet as io
from datetime import timedelta
from scipy.io import savemat
import GLNetEISimLib
# import matplotlib.pyplot as plt

def main():

    parser = argparse.ArgumentParser(description='Simulates a GL network of Excitatory/Inhibitory elements in the mean-field level')
    parser = io.add_neuron_params(parser)
    args = parser.parse_args()

    print("* Setting input parameters ...")
    print(str(args)[10:-1].replace(', ','\n'))

    # model parameters
    mu = args.mu[0] #0.0   #0.5
    Gamma = args.Gamma[0] #1.0    #1.0
    J = args.J[0] #10.0            # J = 2
    g = args.g[0] #3.0      # 3   3.5    4.3    4.7    6
    Y = args.Y[0] #1.2
    Iext = args.Iext[0] #0.0
    theta = args.theta[0] #1.0
    I = Y * theta #2.4 - mu      #1.00001
    A = args.A[0]
    tauW = args.tauW[0]
    uW = args.uW[0]
    tauT = args.tauT[0]
    uT = args.uT[0]

    rPoisson = args.rPoisson[0]

    # initial condition
    VE0 = args.VE0[0]
    VI0 = args.VI0[0]
    VE0Std = args.VE0Std[0]
    VI0Std = args.VI0Std[0]
    XE0 = args.XE0[0]
    XI0 = args.XI0[0]
    XE0Rand = args.XE0Rand
    XI0Rand = args.XI0Rand

    # network parameters
    N = args.N[0] #10000
    p = args.p[0] #0.8
    q = 1.0 - p

    # simulation parameters
    weightDynType = args.weightDynType[0]
    simType = args.simType[0]
    tTotal = args.tTotal[0] #2000
    tTrans = args.tTrans[0]
    saveSpikingData = args.saveSpikingData
    saveTxtFile = args.saveTxtFile
    nNeuronsSpk = args.nNeuSpikingData[0]
    outputFileName = args.outputFile[0]
    if not outputFileName.lower().endswith('.txt'):
        outputFileName += '.txt'
    matFileName = outputFileName.replace('.txt','.mat')
    spkFileName = outputFileName.replace('.txt','_spkdata.txt')

    if os.path.isfile(outputFileName):
        print("* Replacing ... %s" % outputFileName)
        os.remove(outputFileName)
    if os.path.isfile(matFileName):
        print("* Replacing ... %s" % matFileName)
        os.remove(matFileName)
    if os.path.isfile(spkFileName):
        print("* Replacing ... %s" % spkFileName)
        os.remove(spkFileName)

    if simType == "static":
        RunSimulation = GLNetEISimLib.RunSimulation_static
    elif simType == "adapt":
        RunSimulation = GLNetEISimLib.RunSimulation_adapt
    elif simType == "adaptthresh":
        RunSimulation = GLNetEISimLib.RunSimulation_adaptthresh
    elif simType == "aval":
        RunSimulation = GLNetEISimLib.RunSimulation_aval
    else:
        raise ValueError('unknown simType parameter')


    print("* Running simulation...")
    start_time = time.monotonic()
    rhoE,rhoI,spkData,excSynCurrent,inhSynCurrent,g_data,Y_data = RunSimulation(int(N),int(tTrans),int(tTotal),float(VE0),float(VE0Std),float(VI0),float(VI0Std),float(XE0),bool(XE0Rand),float(XI0),bool(XI0Rand),float(mu),float(theta),float(J),float(Gamma),float(I),float(Iext),float(g),float(p),float(q),float(A),float(tauW),float(uW),float(tauT),float(uT),bool(saveSpikingData),int(nNeuronsSpk),weightDynType,float(rPoisson))
    end_time = time.monotonic()
    print("* End of simulation... Total time: {}".format(timedelta(seconds=end_time - start_time)))
    rhomedE = numpy.mean(rhoE)
    rhomedI = numpy.mean(rhoI)
    W = (p-q*g)*J
    h = I - theta
    N_rec_exc = int(p*nNeuronsSpk) # number of recorded excitatory neurons
    rhoMean = numpy.multiply(p,rhoE)+numpy.multiply(q,rhoI)
    synCurrentNet = numpy.subtract(excSynCurrent, inhSynCurrent)

    fileHeader  = "****** Parameters:\n"
    fileHeader += ("W=%.8g" % W) + "\n"
    fileHeader += ("h=%.8g" % h) + "\n"
    fileHeader += ("number_recorded_Exc_neurons=%.8g" % N_rec_exc) + "\n"
    fileHeader += str(args)[10:-1].replace(', ','\n') + "\n"
    fileHeader += "****** Variables\n"
    fileHeader += ("rhoE_mean=%.8g" % rhomedE) + "\n"
    fileHeader += ("rhoI_mean=%.8g" % rhomedI) + "\n"
    fileHeader += "****** Data columns:\n"

    if saveTxtFile:
        print("* Writing output file ... %s" % outputFileName)
        numpy.savetxt(outputFileName, [list(v) for v in zip(range(tTrans,tTotal), rhoE, rhoI, rhoMean, excSynCurrent, inhSynCurrent, synCurrentNet, g_data, Y_data)], fmt="%d\t%15.8E\t%15.8E\t%15.8E\t%15.8E\t%15.8E\t%15.8E\t%15.8E\t%15.8E", header=(fileHeader + "time\t rhoE\t rhoI\t rhoMean\t excSynCurr\t inhSynCurr\t netSynCurr\t g\t Y"))

    print("* Writing output file ... %s" % matFileName)
    matVars = vars(args)
    matVars.update({"W":W, "h":h, "rhoE_mean":rhomedE, "rhoI_mean":rhomedI})
    matVars.update({"time": range(tTrans,tTotal), "rhoE": rhoE, "rhoI": rhoI, "rhoMean": rhoMean})
    matVars.update({"excSynCurr": excSynCurrent, "inhSynCurr": inhSynCurrent, "netSynCurr": synCurrentNet})
    matVars.update({"gVar": g_data, "YVar": Y_data, "N_rec_Exc": N_rec_exc})
    savemat(matFileName,matVars,long_field_names=True)

    if saveSpikingData:
        if saveTxtFile:
            print("* Writing spiking data file ... %s" % spkFileName)
            numpy.savetxt(spkFileName, spkData, fmt="%1d", delimiter=' ', header=(fileHeader + "time step\t neuron index"))

        print("* Appending spiking data file ... %s" % matFileName)
        matVars.update({"spkData":spkData})
        savemat(matFileName,matVars,appendmat=True,long_field_names=True)

if __name__ == '__main__':
    main()
