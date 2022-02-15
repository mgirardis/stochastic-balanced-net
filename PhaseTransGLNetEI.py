# -*- coding: utf-8 -*-
import os
import argparse
import numpy
import time
import warnings
import ioGLNet as io
import datetime
import scipy.io
import scipy.signal
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
        RunSimulation = GLNetEISimLib.RunSimulation_GLNetEIMF_static
    elif simType == "adapt":
        RunSimulation = GLNetEISimLib.RunSimulation_GLNetEIMF_adapt
    elif simType == "adaptthresh":
        RunSimulation = GLNetEISimLib.RunSimulation_GLNetEIMF_adaptthresh
    elif simType == "aval":
        RunSimulation = GLNetEISimLib.RunSimulation_GLNetEIMF_aval
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
                            avg_IsynI=numpy.zeros(nPoints),std_IsynI=numpy.zeros(nPoints),
                            t_decay  =numpy.zeros(nPoints))
    
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
        #rhoE,rhoI,spkData,excSynCurrent,inhSynCurrent,g_data,Y_data = RunSimulation(**simParam)
        rhoE,rhoI,spkData,excSynCurrent,inhSynCurrent,g_data,Y_data = RunSimulation(io.simParam_to_str_for_pythran(simParam),io.get_arg_types_dict(simParam))

        # calculating some means
        rhoMean = numpy.multiply(simParam.p,rhoE)+numpy.multiply(simParam.q,rhoI)
        synCurrentNet = numpy.subtract(excSynCurrent, inhSynCurrent)

        # saving output data
        """
        apparently there can be metastable states in the adaptive threshold excitatory networks
        in which, for sufficiently high input Poisson rate, the network activity decays to rhoE=0
        after some time of about 10^4 time steps or earlier for higher rates
        """
        t_decay = get_decay_time_idx(rhoE,50)
        outVars.t_decay[k] = t_decay
        outVars.avg_rhoE[k],outVars.std_rhoE[k] = mean_std_before_decay(rhoE,t_decay=t_decay)
        outVars.avg_rhoI[k],outVars.std_rhoI[k] = mean_std_before_decay(rhoI,t_decay=t_decay)
        outVars.avg_rho[k],outVars.std_rho[k] = mean_std_before_decay(rhoMean,t_decay=t_decay)
        outVars.avg_gVar[k],outVars.std_gVar[k] = mean_std_before_decay(g_data,t_decay=t_decay)
        outVars.avg_YVar[k],outVars.std_YVar[k] = mean_std_before_decay(Y_data,t_decay=t_decay)
        outVars.avg_Isyn[k],outVars.std_Isyn[k] = mean_std_before_decay(synCurrentNet,t_decay=t_decay)
        outVars.avg_IsynE[k],outVars.std_IsynE[k] = mean_std_before_decay(excSynCurrent,t_decay=t_decay)
        outVars.avg_IsynI[k],outVars.std_IsynI[k] = mean_std_before_decay(inhSynCurrent,t_decay=t_decay)
        if phasetrParam.saveTimeEvo:
            outVarsT.rhoE[:,k],outVarsT.rhoI[:,k] = rhoE,rhoI
            outVarsT.gVar[:,k],outVarsT.YVar[:,k] = g_data,Y_data
            outVarsT.IsynE[:,k],outVarsT.IsynI[:,k] = excSynCurrent,inhSynCurrent
    end_time = time.monotonic()
    print("* End of simulation... Total time: {}".format(datetime.timedelta(seconds=end_time - start_time)))

    print("* Writing output file ... %s" % outputFileName)
    outVars.update(**outputParamValues)
    outVars.update(**phasetrParam)
    if phasetrParam.saveTimeEvo:
        scipy.io.savemat(outputFileName,{**outVars,**outVarsT},appendmat=True,long_field_names=True,do_compression=True)
    else:
        scipy.io.savemat(outputFileName,outVars,appendmat=True,long_field_names=True,do_compression=True)

def mean_std_before_decay(x,t0=0,t_decay=numpy.nan):
    if numpy.isnan(t_decay):
        t_decay = len(x)
    return numpy.mean(x[t0:t_decay]),numpy.std(x[t0:t_decay])

def get_decay_time_idx(rho,w_filter=50,n_ts_consecutive=100):
    """
    apparently there can be metastable states in the adaptive threshold excitatory networks
    in which, for sufficiently high Poisson rate, the network activity decays to rhoE=0
    after some time

    dt -> time tolerance to be subtracted from the mean decay time
    """
    t_zero = find_consecutive(numpy.asarray(rho)<1.0e-10,n_ts_consecutive)
    if not t_zero:
        return numpy.nan
    rho_f = movingavg_filter(rho,w_filter)
    n = int(numpy.floor(t_zero/2.0))
    k = numpy.argmax(numpy.abs(numpy.diff(rho_f[:t_zero]))[-n:])
    t_decay = k + n
    dt = int(2.2*numpy.abs(t_zero - t_decay))
    t_decay -= dt
    if t_decay<100:
        t_decay = k+n
    return t_decay

def find_consecutive(X,N):
    """
    finds N consecutive True values in X
    returns index of the first True value
    """
    k = 0
    k0 = None
    for i,x in enumerate(X):
        if x:
            if k == 0: # if the counter is zero
                k0 = i # this is the first occurrence of zero
            k += 1 # and thus we count this occurrence
            if k == N: # if we reached the desired number of occurrences
                return k0 # we return the index of the first finding
        else:
            k = 0 # otherwise, resets the counter
            k0 = None # and the index of the first occurrence
    return k0 # nothing was found

def movingavg_filter(x1,w=50):
    return normConvolution(x1,numpy.ones(w))

def normConvolution(x1,x2):
    f = scipy.signal.convolve(x1,x2,mode='same',method='direct')
    f = f*numpy.max(x1)/numpy.max(f) # normalizing
    #fixing boundary conditions
    n = int(numpy.ceil( len(x2)/2.0 ) + 1.0)
    f[:n] = f[n]
    f[-n:] = f[-n]
    return f


if __name__ == '__main__':
    main()
