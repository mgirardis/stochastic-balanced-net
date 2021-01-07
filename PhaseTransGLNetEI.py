# -*- coding: utf-8 -*-
import os
import argparse
import numpy
import time
import warnings
import ioGLNet as io
import datetime
import scipy.io
import GLNetEISimLib
# import matplotlib.pyplot as plt

def main():

    parser = argparse.ArgumentParser(description='Simulates a phase transition of a GL network of Excitatory/Inhibitory elements in the mean-field level over the chosen parameter')
    parser = io.add_neuron_params(parser,outputFile=['glnet_phasetr.mat'])
    parser = io.add_phasetrans_params(parser)
    args = parser.parse_args()

    print("* Setting input parameters ...")
    print(str(args)[10:-1].replace(', ','\n'))

    simParam = io.get_sim_param_struct_for_pythran(args)
    phasetrParam = io.get_phasetrans_param_struct(args)
    W = (simParam.p-simParam.q*simParam.g)*simParam.J
    h = simParam.I - simParam.theta
    outputParamValues = io.namespace_to_structtype(args)
    outputParamValues.W = W
    outputParamValues.h = h
    outputParamValues.N_rec_Exc = int(simParam.p*simParam.nNeuronsSpk) # number of recorded excitatory neurons
    outputParamValues[phasetrParam.parName] = numpy.nan

    # output parameters
    simType = args.simType[0]
    saveTxtFile = args.saveTxtFile
    outputFileName = args.outputFile[0]
    if outputFileName.lower().endswith('.txt'):
        outputFileName = outputFileName.replace('.txt','.mat')
    if not outputFileName.lower().endswith('.mat'):
        outputFileName += '.mat'

    if saveTxtFile:
        warnings.warn('text file output is not supported')
    if simParam.saveSpikingData:
        warnings.warn('saving spiking data is not supported')
        simParam.saveSpikingData = False

    if os.path.isfile(outputFileName):
        print("* Replacing ... %s" % outputFileName)
        os.remove(outputFileName)

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

    # setup output variables
    nPoints = phasetrParam.parRange.size
    outVars = io.structtype(avg_rhoE =numpy.zeros(nPoints),std_rhoE =numpy.zeros(nPoints),
                            avg_rhoI =numpy.zeros(nPoints),std_rhoI =numpy.zeros(nPoints),
                            avg_rho  =numpy.zeros(nPoints),std_rho  =numpy.zeros(nPoints),
                            avg_gVar =numpy.zeros(nPoints),std_gVar =numpy.zeros(nPoints),
                            avg_YVar =numpy.zeros(nPoints),std_YVar =numpy.zeros(nPoints),
                            avg_Isyn =numpy.zeros(nPoints),std_Isyn =numpy.zeros(nPoints),
                            avg_IsynE=numpy.zeros(nPoints),std_IsynE=numpy.zeros(nPoints),
                            avg_IsynI=numpy.zeros(nPoints),std_IsynI=numpy.zeros(nPoints))
    
    outVarsT = []
    if phasetrParam.saveTimeEvo:
        tTotal = simParam.Tmax - simParam.tTrans
        outVarsT = io.structtype(time=numpy.zeros((tTotal,1)),rhoE=numpy.zeros((tTotal,nPoints)),rhoI=numpy.zeros((tTotal,nPoints)),
                                 gVar=numpy.zeros((tTotal,nPoints)),YVar=numpy.zeros((tTotal,nPoints)),
                                 IsynE=numpy.zeros((tTotal,nPoints)),IsynI=numpy.zeros((tTotal,nPoints)))
        outVarsT.time = numpy.linspace(0,tTotal-1,tTotal).reshape((tTotal,1))

    print("* Running phase transition simulation...")
    start_time = time.monotonic()
    for k,v in enumerate(phasetrParam.parRange):
        print('{:s} = {:g}'.format(phasetrParam.parName,v))

        # updating parameter
        simParam[phasetrParam.parName] = v

        # running simulation
        rhoE,rhoI,spkData,excSynCurrent,inhSynCurrent,g_data,Y_data = RunSimulation(**simParam)

        # calculating some means
        rhoMean = numpy.multiply(simParam.p,rhoE)+numpy.multiply(simParam.q,rhoI)
        synCurrentNet = numpy.subtract(excSynCurrent, inhSynCurrent)

        # saving output data
        outVars.avg_rhoE[k],outVars.std_rhoE[k] = numpy.mean(rhoE),numpy.std(rhoE)
        outVars.avg_rhoI[k],outVars.std_rhoI[k] = numpy.mean(rhoI),numpy.std(rhoI)
        outVars.avg_rho[k],outVars.std_rho[k] = numpy.mean(rhoMean),numpy.std(rhoMean)
        outVars.avg_gVar[k],outVars.std_gVar[k] = numpy.mean(g_data),numpy.std(g_data)
        outVars.avg_YVar[k],outVars.std_YVar[k] = numpy.mean(Y_data),numpy.std(Y_data)
        outVars.avg_Isyn[k],outVars.std_Isyn[k] = numpy.mean(synCurrentNet),numpy.std(synCurrentNet)
        outVars.avg_IsynE[k],outVars.std_IsynE[k] = numpy.mean(excSynCurrent),numpy.std(excSynCurrent)
        outVars.avg_IsynI[k],outVars.std_IsynI[k] = numpy.mean(inhSynCurrent),numpy.std(inhSynCurrent)
        if phasetrParam.saveTimeEvo:
            outVarsT.rhoE[:,k],outVarsT.rhoI[:,k] = rhoE,rhoI
            outVarsT.gVar[:,k],outVarsT.YVar[:,k] = g_data,Y_data
            outVarsT.IsynE[:,k],outVarsT.IsynI[:,k] = excSynCurrent,inhSynCurrent
    end_time = time.monotonic()
    print("* End of simulation... Total time: {}".format(datetime.timedelta(seconds=end_time - start_time)))

    print("* Writing output file ... %s" % outputFileName)
    outVars.update(**outputParamValues)
    outVars.update(**phasetrParam)
    scipy.io.savemat(outputFileName,outVars,appendmat=True,long_field_names=True)
    if phasetrParam.saveTimeEvo:
        scipy.io.savemat(outputFileName,{**outVars,**outVarsT},appendmat=True,long_field_names=True)

if __name__ == '__main__':
    main()
