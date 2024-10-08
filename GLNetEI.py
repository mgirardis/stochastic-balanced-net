# -*- coding: utf-8 -*-
import os
import sys
import time
import numpy
import argparse
import datetime
import scipy.io
import modules.ioGLNet as io
import modules.GLNetEISimLib_numba as GLNetEISimLib
# import matplotlib.pyplot as plt

def main():

    # for debug

    ##### 2024/August/20
    ##### check if it is writing spikingData txt file
    #sys.argv = 'GLNetEI.py -rPoisson 0.000001000000000 -netType mf -p 1.0 -mu 0.0 -Gamma 0.2 -J 5.0 -Y 1.0 -tauT 100 -uT 0.1 -theta 1.0 -N 100 -simType adaptthresh -tTotal 1000 -tTrans 0 -outputFile glexc_adaptthresh_tau100_u0.1_J5.0_r0.000001.txt -nNeuSpikingData 100 -writeOnRun -saveSpikingData'.split(' ')

    #sys.argv = 'GLNetEI.py -mu 0.0 -Gamma 0.2 -J 10.0 -g 1.50 -Y 1.0 -theta 1.0 -N 100 -simType aval -p 0.8 -tTotal 120000 -tTrans 30000 -outputFile test/test.mat -nNeuSpikingData 100'.split(' ')
    #sys.argv = 'GLNetEI.py -p 1.0 -mu 0.0 -Gamma 0.2 -J 5.2 -Y 1.0 -theta 1.0 -N 100 -simType aval -tTotal 12000 -tTrans 3000 -outputFile output/glexc_aval_G0.2_J5.2_Y1_N100000.txt -nNeuSpikingData 100000'.split(' ')
    #sys.argv = 'GLNetEI.py -mu 0.0 -Gamma 0.2 -J 10.0 -g 1.5 -Y 1.0 -theta 1.0 -N 1000 -simType adapt -p 0.8 -tTotal 10000 -tTrans 3000 -tauT 500.0 -tauW 500.0 -uT 0.1 -uW 0.1 -A 30.0 -outputFile run/output/glei_adapt_G0.2_g1.5_A30_tauW500_Y1_N1000.mat -nNeuSpikingData 1000'.split(' ')

    #sys.argv = 'GLNetEI.py -netType mf -p 1.0 -mu 0.0 -Gamma 0.2 -J 4.8 -Y 1.0 -tauT 20 -uT 0.1 -theta 1.0 -N 1000 -simType adaptthreshlinear -tTotal 100 -tTrans 30 -outputFile ./test.txt -nNeuSpikingData 1000'.split(' ')

    # simulations to visually check whether results are as expected

    # these are returning no dynamics in Y, and weird dynamic in g
    # these are solved by adding an extra option to weightDynType == 'none' from the input for static weight simulations
    #sys.argv = 'GLNetEI.py -mu 0.0 -Gamma 0.2 -J 10.0 -g 1.4 -Y 1.0 -theta 1.0 -N 1000 -simType aval -p 0.8 -tTotal 10000 -tTrans 3000 -outputFile run/output/glei_aval_G0.2_g1.4_Y1_N1000.mat -nNeuSpikingData 1000'.split(' ')
    #sys.argv = 'GLNetEI.py -mu 0.0 -Gamma 0.2 -J 10.0 -g 1.5 -Y 1.0 -theta 1.0 -N 1000 -simType aval -p 0.8 -tTotal 10000 -tTrans 3000 -outputFile run/output/glei_aval_G0.2_g1.5_Y1_N1000.mat -nNeuSpikingData 1000'.split(' ')
    #sys.argv = 'GLNetEI.py -mu 0.0 -Gamma 0.2 -J 10.0 -g 1.6 -Y 1.0 -theta 1.0 -N 1000 -simType aval -p 0.8 -tTotal 10000 -tTrans 3000 -outputFile run/output/glei_aval_G0.2_g1.6_Y1_N1000.mat -nNeuSpikingData 1000'.split(' ')

    # this has no dynamic at all (0 activity)
    # this condition is solved; there was a conflicting definition of the IC
    # since XE0,XI0,fXE0,fXI0 define the IC,
    # now the rho=0 IC is only achieved when all XE0=XI0=fXE0=fXI0=0
    #sys.argv = 'GLNetEI.py -mu 0.0 -Gamma 0.2 -J 10.0 -g 1.4 -Y 1.0 -theta 1.0 -N 1000 -simType static -p 0.8 -tTotal 10000 -tTrans 0 -outputFile run/output/glei_static_G0.2_g1.4_Y1_N1000.mat -nNeuSpikingData 1000'.split(' ')

    cmd_line = ' '.join(sys.argv)
    parser   = argparse.ArgumentParser(description='Simulates a GL network of Excitatory/Inhibitory elements in the mean-field level')
    parser   = io.add_neuron_params(parser)
    args     = parser.parse_args()

    print("* Setting input parameters ...")

    simParam                    = io.get_sim_param_struct_for_pythran(args)
    outputParamValues           = io.namespace_to_structtype(args)
    outputParamValues.W         = (simParam.p-simParam.q*simParam.g)*simParam.J
    outputParamValues.h         = simParam.I - simParam.theta
    outputParamValues.N_rec_Exc = int(simParam.p*simParam.nNeuronsSpk) # number of recorded excitatory neurons

    print(str(outputParamValues)[11:-1].replace(', ','\n'))

    saveTxtFile    = args.saveTxtFile
    outputFileName = args.outputFile[0]

    # fix output file extension and remove output files if they already exist, creates output directory if they don't exist    
    outputFileName,matFileName,simParam.spkFileName = io.fix_output_fileName_main_simulation(outputFileName)

    simType = args.simType[0]
    if (simParam.netType == 'random'):
        RunSimulation = GLNetEISimLib.RunSimulation_GLNetEIRand
    elif (simParam.netType == 'mf'):
        RunSimulation = GLNetEISimLib.RunSimulation_GLNetEIMF
        # if (simType == "adapt") or (simType == "adaptthresh"):
        #     RunSimulation = GLNetEISimLib.RunSimulation_GLNetEIMF_adapt
        # elif (simType == "aval") or (simType == "static"):
        #     RunSimulation = GLNetEISimLib.RunSimulation_GLNetEIMF_aval
        # else:
        #     raise ValueError('unknown simType parameter')
    else:
        raise ValueError('unknown netType parameter')


    print("* Running simulation...")
    simParam_numba,paramType_numba = GLNetEISimLib.convert_simParam_to_numba_dict(io.simParam_to_str_for_pythran(simParam),io.get_arg_types_dict(simParam))
    start_time = time.monotonic()
    #rhoE,rhoI,spkData,excSynCurrent,inhSynCurrent,g_data,Y_data = RunSimulation(**simParam)
    rhoE,rhoI,spkData,excSynCurrent,inhSynCurrent,g_data,Y_data = RunSimulation(simParam_numba,paramType_numba)
    end_time = time.monotonic()
    print("* End of simulation... Total time: {}".format(datetime.timedelta(seconds=end_time - start_time)))

    # calculatinig some physical quantities
    rhomedE = numpy.mean(rhoE)
    rhomedI = numpy.mean(rhoI)
    rhoMean = numpy.multiply(simParam.p,rhoE)+numpy.multiply(simParam.q,rhoI)
    synCurrentNet = numpy.subtract(excSynCurrent, inhSynCurrent)

    fileHeader = ''
    if saveTxtFile:
        fileHeader = io.get_output_txtfile_header(cmd_line,outputParamValues,rhomedE,rhomedI)
        print("* Writing output file ... %s" % outputFileName)
        numpy.savetxt(outputFileName, [list(v) for v in zip(range(simParam.tTrans,simParam.Tmax), rhoE, rhoI, rhoMean, excSynCurrent, inhSynCurrent, synCurrentNet, g_data, Y_data)], fmt="%d\t%15.8E\t%15.8E\t%15.8E\t%15.8E\t%15.8E\t%15.8E\t%15.8E\t%15.8E", header=(fileHeader + "time\t rhoE\t rhoI\t rhoMean\t excSynCurr\t inhSynCurr\t netSynCurr\t g\t Y"))

    print("* Writing output file ... %s" % matFileName)
    matVars = vars(args)
    matVars.update({ 'cmdLine'  : cmd_line})
    matVars.update({ "W"        : outputParamValues.W,
                     "h"        : outputParamValues.h,
                     "rhoE_mean": rhomedE,
                     "rhoI_mean": rhomedI})
    matVars.update({ "time"     : range(simParam.tTrans,simParam.Tmax),
                     "rhoE"     : rhoE,
                     "rhoI"     : rhoI,
                     "rhoMean"  : rhoMean})
    matVars.update({"excSynCurr": excSynCurrent,
                    "inhSynCurr": inhSynCurrent,
                    "netSynCurr": synCurrentNet})
    matVars.update({"gVar"      : g_data,
                    "YVar"      : Y_data,
                    "N_rec_Exc" : outputParamValues.N_rec_Exc})
    scipy.io.savemat(matFileName,matVars,long_field_names=True,do_compression=True)

    if simParam.saveSpikingData and not simParam.writeOnRun:
        if saveTxtFile:
            print("* Writing spiking data file ... %s" % simParam.spkFileName)
            numpy.savetxt(simParam.spkFileName, spkData, fmt="%1d", delimiter=' ', header=(fileHeader + "time step\t neuron index"))

        print("* Appending spiking data file ... %s" % matFileName)
        matVars.update({"spkData":spkData})
        scipy.io.savemat(matFileName,matVars,appendmat=True,long_field_names=True,do_compression=True)

    if simParam.saveSpikingData and simParam.writeOnRun:
        print('-#-')
        print('spkFileName: %s'%simParam.spkFileName)

if __name__ == '__main__':
    main()
