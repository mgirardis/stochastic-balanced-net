
def add_phasetrans_params(parser,**defaultValues):
    parser.add_argument('-parName', nargs=1, required=False, metavar='NAME',  type=float, default=get_param_value('parName', defaultValues,['rPoisson']), help='name of the parameter to vary in [val1;val2]')
    parser.add_argument('-parVal1', nargs=1, required=False, metavar='VALUE', type=float, default=get_param_value('parVal1', defaultValues,[1.0e-6]),     help='simulate n values of the parameter in [val1;val2]')
    parser.add_argument('-parVal2', nargs=1, required=False, metavar='VALUE', type=float, default=get_param_value('parVal2', defaultValues,[1.0]),        help='simulate n values of the parameter in [val1;val2]')
    parser.add_argument('-nPar',    nargs=1, required=False, metavar='VALUE', type=int,   default=get_param_value('nPar', defaultValues,[1.0]),           help='simulate n values of the parameter in [val1;val2]')
    parser.add_argument('-parScale',nargs=1, required=False, metavar='NAME',  type=str,   default=get_param_value('parScale',defaultValues,['log']), choices=['log', 'linear'], help='log: use logspace(val1,val2,n); linear: use linspace(val1,val2,n)')
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
    parser.add_argument('-XE0',             nargs=1, required=False, metavar='XE_INIT',          type=int,   default=get_param_value('XE0',             defaultValues,[0]),                    help='init value for XE')
    parser.add_argument('-XI0',             nargs=1, required=False, metavar='XI_INIT',          type=int,   default=get_param_value('XI0',             defaultValues,[0]),                    help='init value for XI')
    parser.add_argument('-outputFile',      nargs=1, required=False, metavar='OUTPUT_FILE_NAME', type=str,   default=get_param_value('outputFile',      defaultValues,['glnet_dynamics.txt']), help='name of the output file')
    parser.add_argument('-nNeuSpikingData', nargs=1, required=False, metavar='N_NEU_SPIKING',    type=int,   default=get_param_value('nNeuSpikingData', defaultValues,[10000]),                help='number of neurons to be recorded for spiking data')
    parser.add_argument('-simType',         nargs=1, required=False, metavar='SIM_TYPE',         type=str,   default=get_param_value('simType',         defaultValues,['static']), choices=['static', 'adapt', 'aval', 'adaptthresh'], help='type of simulation; adapt is the SOqC dynamics; adaptthresh only adapts thresholds (synapses are fixed); aval = static network, seeding a spike everytime that activity dies off')
    parser.add_argument('-weightDynType',   nargs=1, required=False, metavar='WDYN_TYPE',        type=str,   default=get_param_value('weightDynType',   defaultValues,['simple']), choices=['simple', 'coupled'], help='simple: decrease inhibitory weight due to inhibitory activity; coupled: increase inhibitory weight due to excitatory activity')
    parser.add_argument('-XE0Rand',         required=False, action='store_true', default=False, help='generates random initial XE')
    parser.add_argument('-XI0Rand',         required=False, action='store_true', default=False, help='generates random initial XI')
    parser.add_argument('-saveSpikingData', required=False, action='store_true', default=False, help='saves spiking data for simulation')
    parser.add_argument('-saveTxtFile',     required=False, action='store_true', default=False, help='saves data in text as well as mat')
    return parser

def get_sim_param_dict_for_pythran(args):
    return dict(
    mu = float(args.mu[0]),
    Gamma = float(args.Gamma[0]),
    J = float(args.J[0]),
    g = float(args.g[0]),
    Y = float(args.Y[0]),
    Iext = float(args.Iext[0]),
    theta = float(args.theta[0]),
    I = float(Y * theta),
    A = float(args.A[0]),
    tauW = float(args.tauW[0]),
    uW = float(args.uW[0]),
    tauT = float(args.tauT[0]),
    uT = float(args.uT[0]),
    rPoisson = float(args.rPoisson[0]),
    VE0 = float(args.VE0[0]),
    VI0 = float(args.VI0[0]),
    VE0Std = float(args.VE0Std[0]),
    VI0Std = float(args.VI0Std[0]),
    XE0 = float(args.XE0[0]),
    XI0 = float(args.XI0[0]),
    XE0Rand = bool(args.XE0Rand),
    XI0Rand = bool(args.XI0Rand),
    N = int(args.N[0]),
    p = float(args.p[0]),
    q = float(1.0 - p),
    Tmax = int(args.tTotal[0]),
    tTrans = int(args.tTrans[0]),
    saveSpikingData = args.saveSpikingData,
    weightDynType =  args.weightDynType[0],
    nNeuronsSpk = int(args.nNeuSpikingData[0]))

def get_phasetrans_param_dict(args):
    return structtype(name=args.parName[0],range=get_param_range(args))

def fix_args_lists_as_scalars(args):
    for k,v in args.__dict__.items():
        if (type(v) is list) and (len(v) == 1):
            args.__dict__[k] = v[0]
    return args

def get_param_range(args,numpy=None):
    if numpy is None:
        import numpy
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

class structtype():
    def __init__(self,**kwargs):
        self.Set(**kwargs)
    def Set(self,**kwargs):
        self.__dict__.update(kwargs)
    def SetAttr(self,label,value):
        self.__dict__[label] = value
    #def __repr__(self):
    #    return 'struct|'+self.__dict__.__repr__()+'|' #str(['.'+k.__str__() + ': '+ v.__repr__() for k,v in self.__dict__.items()])
    #def __str__(self):
    #    return 'struct|'+self.__dict__.__str__()+'|' #str(['.'+k.__str__() + ': '+ v.__repr__() for k,v in self.__dict__.items()])
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