import numpy
import argparse

parser = argparse.ArgumentParser(description='prints command lines to run simulation')
parser.add_argument('-where', nargs=1, required=False, metavar='VALUE', type=str, default=['cluster'], choices=['cluster', 'local'], help='place where to run the processes')
parser.add_argument('-npar', nargs=1, required=False, metavar='VALUE', type=int, default=[8], help='number of parallel processes if run local is chosen')
parser.add_argument('-tauw', nargs=1, required=False, metavar='VALUE', type=float, default=[float('nan')], help='value of tau_w... is nan, then tau_w == tau_theta')

args = parser.parse_args()
runLocal = args.where[0].lower() == 'local'
npar = args.npar[0]
tauw_val = args.tauw[0]


# intervalos completos de parametros (mas dah muito programa pra rodar com todas essas combinacoes)
#GG = numpy.sort(list(numpy.linspace(0.15,1,5))+[0.2])
#gg = 4.0-5.0/(GG*10.0) # the critical point values for each Gamma in GG and J=10, essentially these values should not make any difference
#YY = [1.0,1.001,1.01,1.1,1.2,2,3,4,5]
#NN = [ 1e4,32500,55000,77500,1e5,2e5,3e5,1e6 ]
#ttau = [50.0,100.0,150.0,200.0,250.0,1000.0]

GG = numpy.asarray([0.2]) # Gamma values
gg = 4.0-5.0/(GG*10.0) # the critical point values for each Gamma in GG and J=10, essentially these values should not make any difference

#NN = [ 10000,32500,55000,77500,1e5,2e5,3e5,1e6 ] # network size
#NN = [ 1e4,32500,55000,77500,1e5,2e5,3e5,1e6 ] # network size
NN = [ 1e5 ] # network size
#NN = [ 1e4,1e5 ] # network size

ttau = numpy.asarray([500.0,1000.0,2000.0,3000.0,5000.0,10000.0]) # [1000.0,10000.0]
#ttau = [50.0,100.0,150.0,200.0,250.0,500.0,1000.0] # small tau

YY = [1.0] # Y values (external current) must be >= 1
#YY = [1.0,1.01,1.001] # for small tau

#AA = [30.0, 73.5]
ttauw = ttau if numpy.isnan(tauw_val) else tauw_val
#print(ttauw/ttau)
AA = numpy.unique(numpy.append(numpy.asarray((gg*10.0)*(1.0 + ttauw / ttau)),[30.0,40.0,50.0,60.0])) # eq 25 from the new paper
#AA = numpy.unique(numpy.asarray((gg*10.0)*(1.0 + ttauw / ttau))) # eq 25 from the new paper
#print(AA)
#exit()

if numpy.isnan(tauw_val):
    #line = 'GLNetEI.py -mu 0.0 -Gamma {0:.16f} -J 10.0 -g {1:.16f} -Y {2:.16f} -theta 1.0 -N {3:d} -simType adapt -p 0.8 -tTotal 100000 -tTrans 5000 -tauT {4:.16f} -tauW {4:.16f} -uT 0.1 -uW 0.1 -A {5:.16f} -outputFile output/glei_SOqC_A{5:g}_G{0:g}_g{1:g}_Y{2:g}_N{3:d}_tau{4:g}.txt -weightDynType simple -saveSpikingData -writeOnRun -nNeuSpikingData {3:d}'
    line = 'GLNetEI.py -mu 0.0 -Gamma {0:.16f} -J 10.0 -g {1:.16f} -Y {2:.16f} -theta 1.0 -N {3:d} -simType adapt -p 0.8 -tTotal 100000 -tTrans 5000 -tauT {4:.16f} -tauW {4:.16f} -uT 0.1 -uW 0.1 -A {5:.16f} -outputFile output/glei_SOqC_A{5:g}_G{0:g}_g{1:g}_Y{2:g}_N{3:d}_tau{4:g}.txt -weightDynType simple -nNeuSpikingData {3:d}'
else:
    #line = 'GLNetEI.py -mu 0.0 -Gamma {0:.16f} -J 10.0 -g {1:.16f} -Y {2:.16f} -theta 1.0 -N {3:d} -simType adapt -p 0.8 -tTotal 100000 -tTrans 5000 -tauT {4:.16f} -tauW {6:.16f} -uT 0.1 -uW 0.1 -A {5:.16f} -outputFile output/glei_SOqC_tauw{6:g}_A{5:g}_G{0:g}_g{1:g}_Y{2:g}_N{3:d}_tau{4:g}.txt -weightDynType simple -saveSpikingData -writeOnRun -nNeuSpikingData {3:d}'
    line = 'GLNetEI.py -mu 0.0 -Gamma {0:.16f} -J 10.0 -g {1:.16f} -Y {2:.16f} -theta 1.0 -N {3:d} -simType adapt -p 0.8 -tTotal 100000 -tTrans 5000 -tauT {4:.16f} -tauW {6:.16f} -uT 0.1 -uW 0.1 -A {5:.16f} -outputFile output/glei_SOqC_tauw{6:g}_A{5:g}_G{0:g}_g{1:g}_Y{2:g}_N{3:d}_tau{4:g}.txt -weightDynType simple -nNeuSpikingData {3:d}'

if runLocal:
    print('#!/bin/bash')
    line = 'python ' + line
else:
    print('\n',end='')


total = len(GG) * len(gg) * len(NN) * len(ttau) * len(YY) * len(AA)
kk = 0
for G in GG:
    for g in gg:
        for Y in YY:
            for N in NN:
                for tau in ttau:
                    tauw = tau if numpy.isnan(tauw_val) else tauw_val
                    for A in AA:
                        if numpy.isnan(tauw_val):
                            parList = [G,g,Y,int(N),tau,A]
                        else:
                            parList = [G,g,Y,int(N),tau,A,tauw]
                        if runLocal:
                            if (kk%npar) == 0:
                                print('\n',end='')
                            print(line.format(*parList),end='')
                            if ((kk%npar) < (npar-1)) and (kk < (total-1)):
                                print(' & ',end='')
                            kk += 1
                        else:
                            print(line.format(*parList))

if runLocal:
    print('\n',end='')
