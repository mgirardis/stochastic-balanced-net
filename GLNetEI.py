# -*- coding: utf-8 -*-
import os
import argparse
import numpy
import time
from datetime import timedelta
from scipy.io import savemat
import GLNetEISimLib
# import matplotlib.pyplot as plt

def main():

    parser = argparse.ArgumentParser(description='Simulates a GL network of Excitatory/Inhibitory elements in the mean-field level')
    parser.add_argument('-mu', nargs=1, required=False, metavar='MU_PARAM', type=float, default=[0.0], help='mu neuron parameter')
    parser.add_argument('-Gamma', nargs=1, required=False, metavar='Gamma_PARAM', type=float, default=[1.0], help='Gamma neuron parameter')
    parser.add_argument('-J', nargs=1, required=False, metavar='J_PARAM', type=float, default=[10.0], help='(interaction) J neuron parameter')
    parser.add_argument('-g', nargs=1, required=False, metavar='g_PARAM', type=float, default=[3.0], help='(interaction) g neuron parameter')
    parser.add_argument('-Y', nargs=1, required=False, metavar='Y_PARAM', type=float, default=[1.2], help='Y neuron parameter (external field)')
    parser.add_argument('-Iext', nargs=1, required=False, metavar='Iext_PARAM', type=float, default=[0.0], help='external current')
    parser.add_argument('-A', nargs=1, required=False, metavar='A_PARAM', type=float, default=[73.5], help='(interaction) stationary state of the inhibitory weights')
    parser.add_argument('-tauW', nargs=1, required=False, metavar='tauW_PARAM', type=float, default=[100.0], help='(interaction) decay time of the inhibitory weights')
    parser.add_argument('-uW', nargs=1, required=False, metavar='uW_PARAM', type=float, default=[0.1], help='(interaction) potentiation fraction of the inhibitory weights')
    parser.add_argument('-tauT', nargs=1, required=False, metavar='tauT_PARAM', type=float, default=[100.0], help='decay time of the threshold')
    parser.add_argument('-uT', nargs=1, required=False, metavar='uT_PARAM', type=float, default=[0.1], help='increase fraction of the threshold')
    parser.add_argument('-theta', nargs=1, required=False, metavar='theta_PARAM', type=float, default=[1.0], help='theta neuron threshold')
    parser.add_argument('-N', nargs=1, required=False, metavar='N_PARAM', type=int, default=[10000], help='N total (ex+in) number of network elements')
    parser.add_argument('-p', nargs=1, required=False, metavar='p_PARAM', type=float, default=[0.8], help='fraction of excitatory elements')
    parser.add_argument('-rPoisson', nargs=1, required=False, metavar='p_PARAM', type=float, default=[0.0], help='Poisson rate for external process over each excitatory neuron')
    parser.add_argument('-tTotal', nargs=1, required=False, metavar='TOTAL_TIME', type=int, default=[2000], help='total number of time steps to simulate')
    parser.add_argument('-tTrans', nargs=1, required=False, metavar='TRANSIENT_TIME', type=int, default=[1000], help='transient time (time steps to discard)')
    parser.add_argument('-VE0', nargs=1, required=False, metavar='MEAN_VE_INIT', type=float, default=[0.0], help='mean initial VE')
    parser.add_argument('-VI0', nargs=1, required=False, metavar='MEAN_VI_INIT', type=float, default=[0.0], help='mean initial VI')
    parser.add_argument('-VE0Std', nargs=1, required=False, metavar='STD_VE_INIT', type=float, default=[0.0], help='std dev for initial VE')
    parser.add_argument('-VI0Std', nargs=1, required=False, metavar='STD_VI_INIT', type=float, default=[0.0], help='std dev for initial VI')
    parser.add_argument('-XE0', nargs=1, required=False, metavar='XE_INIT', type=int, default=[0], help='init value for XE')
    parser.add_argument('-XI0', nargs=1, required=False, metavar='XI_INIT', type=int, default=[0], help='init value for XI')
    parser.add_argument('-XE0Rand', required=False, action='store_true', default=False, help='generates random initial XE')
    parser.add_argument('-XI0Rand', required=False, action='store_true', default=False, help='generates random initial XI')
    parser.add_argument('-outputFile', nargs=1, required=False, metavar='OUTPUT_FILE_NAME', type=str, default=['glnet_dynamics.txt'], help='name of the output file')
    parser.add_argument('-saveSpikingData', required=False, action='store_true', default=False, help='saves spiking data for simulation')
    parser.add_argument('-saveTxtFile', required=False, action='store_true', default=False, help='saves data in text as well as mat')
    parser.add_argument('-nNeuSpikingData', nargs=1, required=False, metavar='N_NEU_SPIKING', type=int, default=[10000], help='number of neurons to be recorded for spiking data')
    parser.add_argument('-simType', nargs=1, required=False, metavar='SIM_TYPE', type=str, default=['static'], choices=['static', 'adapt', 'aval', 'adaptthresh'], help='type of simulation; adapt is the SOqC dynamics; adaptthresh only adapts thresholds (synapses are fixed); aval = static network, seeding a spike everytime that activity dies off')
    parser.add_argument('-weightDynType', nargs=1, required=False, metavar='WDYN_TYPE', type=str, default=['simple'], choices=['simple', 'coupled'], help='simple: decrease inhibitory weight due to inhibitory activity; coupled: increase inhibitory weight due to excitatory activity')

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
    tauWinv = 1.0/args.tauW[0]
    uW = args.uW[0]
    tauTinv = 1.0/args.tauT[0]
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
    weightDynType = args.weightDynType[0]

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
    elif simType == "adapt":
        RunSimulation = GLNetEISimLib.RunSimulation_adapt
    elif simType == "aval":
        RunSimulation = GLNetEISimLib.RunSimulation_aval
    else:
        raise ValueError('unknown simType parameter')


    print("* Running simulation...")
    start_time = time.monotonic()
    rhoE,rhoI,spkData,excSynCurrent,inhSynCurrent,g_data,Y_data = RunSimulation(N,tTrans,tTotal,VE0,VE0Std,VI0,VI0Std,XE0,XE0Rand,XI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauWinv,uW,tauTinv,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson)
    end_time = time.monotonic()
    print("* End of simulation... Total time: {}".format(timedelta(seconds=end_time - start_time)))
    rhomedE = numpy.mean(rhoE)
    rhomedI = numpy.mean(rhoI)
    W = (p-q*g)*J
    h = I - theta
    rhoMean = numpy.multiply(p,rhoE)+numpy.multiply(q,rhoI)
    synCurrentNet = numpy.subtract(excSynCurrent, inhSynCurrent)

    fileHeader  = "****** Parameters:\n"
    fileHeader += ("W=%.8g" % W) + "\n"
    fileHeader += ("h=%.8g" % h) + "\n"
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
    matVars.update({"gVar": g_data, "YVar": Y_data})
    savemat(matFileName,matVars,long_field_names=True)

    if saveSpikingData:
        if saveTxtFile:
            print("* Writing spiking data file ... %s" % spkFileName)
            numpy.savetxt(spkFileName, zip(range(tTrans,tTotal),*spkData), fmt="%1d", delimiter=' ', header=(fileHeader + "time\t neurons spkData"))

        print("* Appending spiking data file ... %s" % matFileName)
        matVars.update({"spkData":spkData})
        savemat(matFileName,matVars,appendmat=True,long_field_names=True)

if __name__ == '__main__':
    main()
