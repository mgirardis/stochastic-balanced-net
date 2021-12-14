# -*- coding: utf-8 -*-
import os
import argparse
import numpy
import time
import ioGLNet as io
import scipy.io
import GLNetEISimLib
import datetime
import sys
# import matplotlib.pyplot as plt

def main():

    # for debug
    #sys.argv = 'GLNetEI.py -mu 0.0 -Gamma 0.2 -J 10.0 -g 1.50 -Y 1.0 -theta 1.0 -N 100 -simType aval -p 0.8 -tTotal 120000 -tTrans 30000 -outputFile test/test.mat -nNeuSpikingData 100'.split(' ')
    #sys.argv = 'GLNetEI.py -p 1.0 -mu 0.0 -Gamma 0.2 -J 5.2 -Y 1.0 -theta 1.0 -N 100 -simType aval -tTotal 12000 -tTrans 3000 -outputFile output/glexc_aval_G0.2_J5.2_Y1_N100000.txt -nNeuSpikingData 100000'.split(' ')
    parser = argparse.ArgumentParser(description='Simulates a GL network of Excitatory/Inhibitory elements in the mean-field level')
    parser = io.add_neuron_params(parser)
    args = parser.parse_args()

    print("* Setting input parameters ...")

    simParam = io.get_sim_param_struct_for_pythran(args)
    outputParamValues = io.namespace_to_structtype(args)
    outputParamValues.W = (simParam.p-simParam.q*simParam.g)*simParam.J
    outputParamValues.h = simParam.I - simParam.theta
    outputParamValues.N_rec_Exc = int(simParam.p*simParam.nNeuronsSpk) # number of recorded excitatory neurons

    print(str(outputParamValues)[11:-1].replace(', ','\n'))

    saveTxtFile = args.saveTxtFile
    outputFileName = args.outputFile[0]

    if not outputFileName.lower().endswith('.txt'):
        if outputFileName.lower().endswith('.mat'):
            outputFileName = outputFileName.replace('.mat','.txt')
        else:
            outputFileName += '.txt'
    matFileName = outputFileName.replace('.txt','.mat')
    simParam.spkFileName = outputFileName.replace('.txt','_spkdata.txt')

    if os.path.isfile(outputFileName):
        print("* Replacing ... %s" % outputFileName)
        os.remove(outputFileName)
    if os.path.isfile(matFileName):
        print("* Replacing ... %s" % matFileName)
        os.remove(matFileName)
    if os.path.isfile(simParam.spkFileName):
        print("* Replacing ... %s" % simParam.spkFileName)
        os.remove(simParam.spkFileName)

    simType = args.simType[0]
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
    print("* End of simulation... Total time: {}".format(datetime.timedelta(seconds=end_time - start_time)))

    # calculatinig some physical quantities
    rhomedE = numpy.mean(rhoE)
    rhomedI = numpy.mean(rhoI)
    rhoMean = numpy.multiply(simParam.p,rhoE)+numpy.multiply(simParam.q,rhoI)
    synCurrentNet = numpy.subtract(excSynCurrent, inhSynCurrent)

    fileHeader  = "****** Parameters:\n"
    fileHeader += str(outputParamValues)[11:-1].replace(', ','\n') + "\n"
    fileHeader += "****** Variables\n"
    fileHeader += ("rhoE_mean=%.8g" % rhomedE) + "\n"
    fileHeader += ("rhoI_mean=%.8g" % rhomedI) + "\n"
    fileHeader += "****** Data columns:\n"

    if saveTxtFile:
        print("* Writing output file ... %s" % outputFileName)
        numpy.savetxt(outputFileName, [list(v) for v in zip(range(simParam.tTrans,simParam.Tmax), rhoE, rhoI, rhoMean, excSynCurrent, inhSynCurrent, synCurrentNet, g_data, Y_data)], fmt="%d\t%15.8E\t%15.8E\t%15.8E\t%15.8E\t%15.8E\t%15.8E\t%15.8E\t%15.8E", header=(fileHeader + "time\t rhoE\t rhoI\t rhoMean\t excSynCurr\t inhSynCurr\t netSynCurr\t g\t Y"))

    print("* Writing output file ... %s" % matFileName)
    matVars = vars(args)
    matVars.update({"W":outputParamValues.W, "h":outputParamValues.h, "rhoE_mean":rhomedE, "rhoI_mean":rhomedI})
    matVars.update({"time": range(simParam.tTrans,simParam.Tmax), "rhoE": rhoE, "rhoI": rhoI, "rhoMean": rhoMean})
    matVars.update({"excSynCurr": excSynCurrent, "inhSynCurr": inhSynCurrent, "netSynCurr": synCurrentNet})
    matVars.update({"gVar": g_data, "YVar": Y_data, "N_rec_Exc": outputParamValues.N_rec_Exc})
    scipy.io.savemat(matFileName,matVars,long_field_names=True,do_compression=True)

    if simParam.saveSpikingData and not simParam.writeOnRun:
        if saveTxtFile:
            print("* Writing spiking data file ... %s" % simParam.spkFileName)
            numpy.savetxt(simParam.spkFileName, spkData, fmt="%1d", delimiter=' ', header=(fileHeader + "time step\t neuron index"))

        print("* Appending spiking data file ... %s" % matFileName)
        matVars.update({"spkData":spkData})
        scipy.io.savemat(matFileName,matVars,appendmat=True,long_field_names=True,do_compression=True)

    if simParam.writeOnRun:
        print('-#-')
        print('spkFileName: %s'%simParam.spkFileName)

if __name__ == '__main__':
    main()
