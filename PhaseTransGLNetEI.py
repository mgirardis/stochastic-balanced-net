# -*- coding: utf-8 -*-
import os
import argparse
import numpy
import time
import warnings
import inputGLNet as inp
from datetime import timedelta
from scipy.io import savemat
import GLNetEISimLib
# import matplotlib.pyplot as plt

def main():

    parser = argparse.ArgumentParser(description='Simulates a phase transition of a GL network of Excitatory/Inhibitory elements in the mean-field level over the chosen parameter')
    parser = inp.add_neuron_params(parser,outputFile=['glnet_phasetr.txt'])
    parser = inp.add_phasetrans_params(parser)
    args = parser.parse_args()

    print("* Setting input parameters ...")
    print(str(args)[10:-1].replace(', ','\n'))

    simParam = inp.get_sim_param_dict_for_pythran(args)
    phasetrParam = inp.get_phasetrans_param_dict(args)

    # output parameters
    simType = args.simType[0]
    saveTxtFile = args.saveTxtFile
    outputFileName = args.outputFile[0]
    if not outputFileName.lower().endswith('.txt'):
        outputFileName += '.txt'
    matFileName = outputFileName.replace('.txt','.mat')
    spkFileName = outputFileName.replace('.txt','_spkdata.txt')

    if saveTxtFile:
        warnings.warn('text file output is not supported')
    if simParam.saveSpikingData:
        warnings.warn('saving spiking data is not supported')

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
    rhoE,rhoI,spkData,excSynCurrent,inhSynCurrent,g_data,Y_data = RunSimulation(**simParam)
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

    print("* Writing output file ... %s" % matFileName)
    matVars = vars(args)
    matVars.update({"W":W, "h":h, "rhoE_mean":rhomedE, "rhoI_mean":rhomedI})
    matVars.update({"time": range(tTrans,tTotal), "rhoE": rhoE, "rhoI": rhoI, "rhoMean": rhoMean})
    matVars.update({"excSynCurr": excSynCurrent, "inhSynCurr": inhSynCurrent, "netSynCurr": synCurrentNet})
    matVars.update({"gVar": g_data, "YVar": Y_data})
    savemat(matFileName,matVars,long_field_names=True)

if __name__ == '__main__':
    main()
