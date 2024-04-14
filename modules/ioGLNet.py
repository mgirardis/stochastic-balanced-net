import os
import copy
import numpy
import collections.abc

"""

HOW TO ADD A NEW SIMULATION PARAMETER

1. add to one of the functions below ('add_..._params')

2. if you need to pass it to a simulation,
    a) add it to GLNetEISimLib.get_system_parameters
    b) add it to the return of get_system_parameters
    c) fix the get_system_parameters return in all of the GLNetEISimLib.RunSimulation_[...] functions

3. a phase transition parameter
    add it to get_phasetrans_param_struct(args)
    make sure that the returned dict fields match the field names in the
    GLNetEISimLib.get_system_parameters if needed


"""

def add_phasetrans_params(parser,**defaultValues):
    parser.add_argument('-parName', nargs=1, required=False, metavar='NAME',  type=str,   default=get_param_value('parName', defaultValues,['rPoisson']), help='name of the parameter to vary in [val1;val2]')
    parser.add_argument('-parVal1', nargs=1, required=False, metavar='VALUE', type=float, default=get_param_value('parVal1', defaultValues,[1.0e-6]),     help='simulate n values of the parameter in [val1;val2]')
    parser.add_argument('-parVal2', nargs=1, required=False, metavar='VALUE', type=float, default=get_param_value('parVal2', defaultValues,[1.0]),        help='simulate n values of the parameter in [val1;val2]')
    parser.add_argument('-nPar',    nargs=1, required=False, metavar='VALUE', type=int,   default=get_param_value('nPar', defaultValues,[10]),           help='simulate n values of the parameter in [val1;val2]')
    parser.add_argument('-parScale',nargs=1, required=False, metavar='NAME',  type=str,   default=get_param_value('parScale',defaultValues,['log']), choices=['log', 'linear'], help='log: use logspace(val1,val2,n); linear: use linspace(val1,val2,n)')
    parser.add_argument('-saveTimeEvo', required=False, action='store_true', default=False, help='saves rho_EI(t) and IsynEI(t) for each parameter combination')
    parser.add_argument('-noForceActive', required=False, action='store_true', default=False, help='set this parameter to let the activity die out to the absorbing state; by default, the program tries to keep the network active by stimulating it everytime the activity dies out (aval simType)')
    return parser

def add_neuron_params(parser,**defaultValues):
    parser.add_argument('-mu',              nargs=1, required=False, metavar='MU_PARAM',         type=float, default=get_param_value('mu',              defaultValues,[0.0]),                  help='mu neuron parameter')
    parser.add_argument('-Gamma',           nargs=1, required=False, metavar='Gamma_PARAM',      type=float, default=get_param_value('Gamma',           defaultValues,[1.0]),                  help='Gamma neuron parameter')
    parser.add_argument('-J',               nargs=1, required=False, metavar='J_PARAM',          type=float, default=get_param_value('J',               defaultValues,[10.0]),                 help='(interaction) J neuron parameter')
    parser.add_argument('-g',               nargs=1, required=False, metavar='g_PARAM',          type=float, default=get_param_value('g',               defaultValues,[3.0]),                  help='(interaction) g neuron parameter')
    parser.add_argument('-Y',               nargs=1, required=False, metavar='Y_PARAM',          type=float, default=get_param_value('Y',               defaultValues,[1.2]),                  help='Y neurhon parameter (external field)')
    parser.add_argument('-Iext',            nargs=1, required=False, metavar='Iext_PARAM',       type=float, default=get_param_value('Iext',            defaultValues,[0.0]),                  help='external current')
    parser.add_argument('-A',               nargs=1, required=False, metavar='A_PARAM',          type=float, default=get_param_value('A',               defaultValues,[73.5]),                 help='(interaction) stationary state of the inhibitory weights')
    parser.add_argument('-tauW',            nargs=1, required=False, metavar='tauW_PARAM',       type=float, default=get_param_value('tauW',            defaultValues,[100.0]),                help='(interaction) decay time of the inhibitory weights')
    parser.add_argument('-uW',              nargs=1, required=False, metavar='uW_PARAM',         type=float, default=get_param_value('uW',              defaultValues,[0.1]),                  help='(interaction) potentiation fraction of the inhibitory weights')
    parser.add_argument('-tauT',            nargs=1, required=False, metavar='tauT_PARAM',       type=float, default=get_param_value('tauT',            defaultValues,[100.0]),                help='decay time of the threshold')
    parser.add_argument('-uT',              nargs=1, required=False, metavar='uT_PARAM',         type=float, default=get_param_value('uT',              defaultValues,[0.1]),                  help='increase fraction of the threshold')
    parser.add_argument('-theta',           nargs=1, required=False, metavar='theta_PARAM',      type=float, default=get_param_value('theta',           defaultValues,[1.0]),                  help='theta neuron threshold')
    parser.add_argument('-N',               nargs=1, required=False, metavar='N_PARAM',          type=int,   default=get_param_value('N',               defaultValues,[10000]),                help='N total (ex+in) number of network elements')
    parser.add_argument('-p',               nargs=1, required=False, metavar='p_PARAM',          type=float, default=get_param_value('p',               defaultValues,[0.8]),                  help='fraction of excitatory elements')
    parser.add_argument('-rPoisson',        nargs=1, required=False, metavar='rP_PARAM',         type=float, default=get_param_value('rPoisson',        defaultValues,[0.0]),                  help='Poisson rate for external process over each excitatory neuron')
    parser.add_argument('-tTotal',          nargs=1, required=False, metavar='TOTAL_TIME',       type=int,   default=get_param_value('tTotal',          defaultValues,[2000]),                 help='total number of time steps to simulate')
    parser.add_argument('-tTrans',          nargs=1, required=False, metavar='TRANSIENT_TIME',   type=int,   default=get_param_value('tTrans',          defaultValues,[1000]),                 help='transient time (time steps to discard)')
    parser.add_argument('-VE0',             nargs=1, required=False, metavar='MEAN_VE_INIT',     type=float, default=get_param_value('VE0',             defaultValues,[0.0]),                  help='mean initial VE')
    parser.add_argument('-VI0',             nargs=1, required=False, metavar='MEAN_VI_INIT',     type=float, default=get_param_value('VI0',             defaultValues,[0.0]),                  help='mean initial VI')
    parser.add_argument('-VE0Std',          nargs=1, required=False, metavar='STD_VE_INIT',      type=float, default=get_param_value('VE0Std',          defaultValues,[0.0]),                  help='std dev for initial VE')
    parser.add_argument('-VI0Std',          nargs=1, required=False, metavar='STD_VI_INIT',      type=float, default=get_param_value('VI0Std',          defaultValues,[0.0]),                  help='std dev for initial VI')
    parser.add_argument('-XE0',             nargs=1, required=False, metavar='XE_INIT',          type=float, default=get_param_value('XE0',             defaultValues,[0.0]),                  help='init value for XE (for the absorbing state IC, you must set fXE0=XE0=fXI0=XI0=0)')
    parser.add_argument('-XI0',             nargs=1, required=False, metavar='XI_INIT',          type=float, default=get_param_value('XI0',             defaultValues,[0.0]),                  help='init value for XI (for the absorbing state IC, you must set fXE0=XE0=fXI0=XI0=0)')
    parser.add_argument('-fXE0',            nargs=1, required=False, metavar='fXE_INIT',         type=float, default=get_param_value('fXE0',            defaultValues,[0.5]),                  help='fraction of the E population that will have init value XE0 (for the absorbing state IC, you must set fXE0=XE0=fXI0=XI0=0)')
    parser.add_argument('-fXI0',            nargs=1, required=False, metavar='fXI_INIT',         type=float, default=get_param_value('fXI0',            defaultValues,[0.5]),                  help='fraction of the I population that will have init value XI0 (for the absorbing state IC, you must set fXE0=XE0=fXI0=XI0=0)')
    parser.add_argument('-paramCV',         nargs=1, required=False, metavar='CV',               type=float, default=get_param_value('paramCV',         defaultValues,[0.0]),                  help='coefficient of variation (CV) for every and each of the neurons/synapses parameters (except for those that are zero, K and N)')
    parser.add_argument('-K',               nargs=1, required=False, metavar='K_VALUE',          type=int,   default=get_param_value('K',               defaultValues,[10]),                   help='number of input neighbors for random networks')
    parser.add_argument('-outputFile',      nargs=1, required=False, metavar='OUTPUT_FILE_NAME', type=str,   default=get_param_value('outputFile',      defaultValues,['glnet_dynamics.txt']), help='name of the output file')
    parser.add_argument('-nNeuSpikingData', nargs=1, required=False, metavar='N_NEU_SPIKING',    type=int,   default=get_param_value('nNeuSpikingData', defaultValues,[10000]),                help='number of neurons to be recorded for spiking data')
    parser.add_argument('-netType',         nargs=1, required=False, metavar='NET_TYPE',         type=str,   default=get_param_value('netType',         defaultValues,['mf']),     choices=['mf', 'random'], help='network type; mf -> mean-field (all to all), random -> K-input neighbors')
    parser.add_argument('-simType',         nargs=1, required=False, metavar='SIM_TYPE',         type=str,   default=get_param_value('simType',         defaultValues,['static']), choices=['static', 'adapt', 'aval', 'adaptthresh'], help='type of simulation; adapt is the SOqC dynamics; adaptthresh only adapts thresholds (synapses are fixed); aval = static network, seeding a spike everytime that activity dies off')
    parser.add_argument('-weightDynType',   nargs=1, required=False, metavar='WDYN_TYPE',        type=str,   default=get_param_value('weightDynType',   defaultValues,['none']),   choices=['none','simple', 'coupled'], help='simple: (default if simType=adapt) decrease inhibitory weight due to inhibitory activity; coupled: increase inhibitory weight due to excitatory activity')
    parser.add_argument('-noXE0Rand',       required=False, action='store_true', default=False, help='if set, generates sequential initial XE given by XE0')
    parser.add_argument('-noXI0Rand',       required=False, action='store_true', default=False, help='if set, generates sequential initial XI given by XI0')
    parser.add_argument('-saveSpikingData', required=False, action='store_true', default=False, help='saves spiking data for simulation')
    parser.add_argument('-writeOnRun',      required=False, action='store_true', default=False, help='writes spiking data as txt file while program is running to save memory')
    parser.add_argument('-saveTxtFile',     required=False, action='store_true', default=False, help='saves data in text as well as mat')
    return parser

def get_arg_types_dict(args):
    """
    args must be a structtype or a dict
    """
    return { k:type(v).__name__ for k,v in args.items() }

def simParam_to_str_for_pythran(simParam):
    sp = { copy.deepcopy(k):copy.deepcopy(v) for k,v in simParam.items() }
    for k,v in sp.items():
        sp[k] = str(v)
    return sp

def get_sim_param_struct_for_pythran(args):
    #N,tTrans,Tmax,VE0,VE0Std,VI0,VI0Std,XE0,XE0Rand,XI0,XI0Rand,mu,theta,J,Gamma,I,Iext,g,p,q,A,tauW,uW,tauT,uT,saveSpikingData,nNeuronsSpk,weightDynType,rPoisson
    Y = float(args.Y[0])
    theta = float(args.theta[0])
    p = float(args.p[0])
    s = namespace_to_structtype(args) # fix scalar input parameters automatically in this conversion
    # setting the parameters that have another name in the function input inside the GLNetEISimLib.py file
    s.Set(theta=theta,I=float(Y * theta),XE0Rand=not s.noXE0Rand,XI0Rand=not s.noXI0Rand,p=p,q=1.0-p,Tmax=s.tTotal,nNeuronsSpk=s.nNeuSpikingData,spkFileName='')
    s.pop(['noXE0Rand','noXI0Rand','nNeuSpikingData','tTotal','noForceActive'])
    if (s.simType == 'adapt') and (s.weightDynType == 'none'):
        s.weightDynType = 'simple'
    return s

def fix_output_fileName_phasetrans_simulation(outputFileName):
    """fix output file extension and remove output files if they already exist, creates output directory if they don't exist"""
    if outputFileName.lower().endswith('.txt'):
        outputFileName = outputFileName.replace('.txt','.mat')
    if not outputFileName.lower().endswith('.mat'):
        outputFileName += '.mat'

    if os.path.isfile(outputFileName):
        print("* Replacing ... %s" % outputFileName)
        os.remove(outputFileName)
    
    if has_dir_in_path(outputFileName):
        d = os.path.split(outputFileName)[0]
        if d:
            os.makedirs(d,exist_ok=True)

    return outputFileName

def fix_output_fileName_main_simulation(outputFileName):
    """fix output file extension and remove output files if they already exist, creates output directory if they don't exist"""
    if not outputFileName.lower().endswith('.txt'):
        if outputFileName.lower().endswith('.mat'):
            outputFileName = outputFileName.replace('.mat','.txt')
        else:
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
    
    if has_dir_in_path(outputFileName):
        d = os.path.split(outputFileName)[0]
        if d:
            os.makedirs(d,exist_ok=True)

    return outputFileName,matFileName,spkFileName

def get_output_txtfile_header(cmd_line,outputParamValues,rhomedE,rhomedI):
    fileHeader  = "****** cmd line: " + cmd_line + "\n"
    fileHeader += "****** Parameters:\n"
    fileHeader += str(outputParamValues)[11:-1].replace(', ','\n') + "\n"
    fileHeader += "****** Variables\n"
    fileHeader += ("rhoE_mean=%.8g" % rhomedE) + "\n"
    fileHeader += ("rhoI_mean=%.8g" % rhomedI) + "\n"
    fileHeader += "****** Data columns:\n"
    return fileHeader

def has_dir_in_path(path):
    return ('/' in path) or ('\\' in path)

def get_phasetrans_param_struct(args):
    return structtype(parName=args.parName[0],parRange=get_param_range(args),saveTimeEvo=args.saveTimeEvo,forceActivity=not args.noForceActive)

def fix_args_lists_as_scalars(args,return_type_for_values=None):
    if type(args) is dict:
        a = args
    else:
        a = args.__dict__
    for k,v in a.items():
        if (not numpy.isscalar(v)) and (len(v) == 1): #(type(v) is list) and (len(v) == 1):
            a[k] = v[0]
        if not( type(return_type_for_values) is type(None)):
            a[k] = return_type_for_values(a[k])
    if type(args) is dict:
        args = a
    else:
        args.__dict__ = a
    return args

def get_param_range(args):
    if args.parScale[0] == 'log':
        v1 = args.parVal1[0]
        v2 = args.parVal2[0]
        if numpy.sign(v1) != numpy.sign(v2):
            raise ValueError('the signs of parVal1 and parVal2 must be the same')
        s = float(numpy.sign(v1))
        return s*numpy.logspace(numpy.log10(v1),numpy.log10(v2),args.nPar[0])
    elif args.parScale[0] == 'linear':
        return numpy.linspace(args.parVal1[0],args.parVal2[0],args.nPar[0])
    else:
        raise ValueError('unknown parScale')

def get_param_value(paramName,args,default):
    if paramName in args.keys():
        return args[paramName]
    return default

def namespace_to_structtype(a,return_type_for_values=None):
    return structtype(**fix_args_lists_as_scalars(copy.deepcopy(a.__dict__),return_type_for_values=return_type_for_values))

class structtype(collections.abc.MutableMapping):
    def __init__(self,**kwargs):
        self.Set(**kwargs)
    def Set(self,**kwargs):
        self.__dict__.update(kwargs)
    def SetAttr(self,field,value):
        self.__dict__[field] = value
    def GetFields(self):
        return '; '.join([ k for k in self.__dict__.keys() if (k[0:2] != '__') and (k[-2:] != '__') ])
    def keys(self):
        return self.__dict__.keys()
    def items(self):
        return self.__dict__.items()
    def values(self):
        return self.__dict__.values()
    def pop(self,key,default_value=None):
        if type(key) is str:
            return self.__dict__.pop(key,default_value)
        elif isinstance(key,collections.abc.Iterable):
            r = []
            for k in key:
                r.append(self.__dict__.pop(k,default_value))
            return r
        else:
            raise ValueError('key must be a string or a list of strings')
    def __setitem__(self,label,value):
        self.__dict__[label] = value
    def __getitem__(self,label):
        return self.__dict__[label]
    def __repr__(self):
        type_name = type(self).__name__
        arg_strings = []
        star_args = {}
        for arg in self._get_args():
            arg_strings.append(repr(arg))
        for name, value in self._get_kwargs():
            if name.isidentifier():
                arg_strings.append('%s=%r' % (name, value))
            else:
                star_args[name] = value
        if star_args:
            arg_strings.append('**%s' % repr(star_args))
        return '%s(%s)' % (type_name, ', '.join(arg_strings))
    def _get_kwargs(self):
        return sorted(self.__dict__.items())
    def _get_args(self):
        return []
    def __delitem__(self,*args):
        self.__dict__.__delitem__(*args)
    def __len__(self):
        return self.__dict__.__len__()
    def __iter__(self):
        return iter(self.__dict__)