#include <climits> // added by Mauricio -- the compiler was complaining about this
#include <pythonic/core.hpp>
#include <pythonic/python/core.hpp>
#include <pythonic/types/bool.hpp>
#include <pythonic/types/int.hpp>
#ifdef _OPENMP
#include <omp.h>
#endif
#include <pythonic/include/types/float.hpp>
#include <pythonic/include/types/list.hpp>
#include <pythonic/include/types/str.hpp>
#include <pythonic/include/types/int.hpp>
#include <pythonic/include/types/bool.hpp>
#include <pythonic/include/types/tuple.hpp>
#include <pythonic/include/types/dict.hpp>
#include <pythonic/include/types/ndarray.hpp>
#include <pythonic/types/tuple.hpp>
#include <pythonic/types/ndarray.hpp>
#include <pythonic/types/int.hpp>
#include <pythonic/types/str.hpp>
#include <pythonic/types/float.hpp>
#include <pythonic/types/dict.hpp>
#include <pythonic/types/list.hpp>
#include <pythonic/types/bool.hpp>
#include <pythonic/include/builtins/False.hpp>
#include <pythonic/include/builtins/None.hpp>
#include <pythonic/include/builtins/ValueError.hpp>
#include <pythonic/include/builtins/abs.hpp>
#include <pythonic/include/builtins/bool_.hpp>
#include <pythonic/include/builtins/enumerate.hpp>
#include <pythonic/include/builtins/float_.hpp>
#include <pythonic/include/builtins/int_.hpp>
#include <pythonic/include/builtins/len.hpp>
#include <pythonic/include/builtins/list.hpp>
#include <pythonic/include/builtins/list/append.hpp>
#include <pythonic/include/builtins/map.hpp>
#include <pythonic/include/builtins/max.hpp>
#include <pythonic/include/builtins/open.hpp>
#include <pythonic/include/builtins/print.hpp>
#include <pythonic/include/builtins/pythran/and_.hpp>
#include <pythonic/include/builtins/range.hpp>
#include <pythonic/include/builtins/sorted.hpp>
#include <pythonic/include/builtins/str.hpp>
#include <pythonic/include/builtins/str/__mod__.hpp>
#include <pythonic/include/builtins/str/join.hpp>
#include <pythonic/include/builtins/sum.hpp>
#include <pythonic/include/builtins/tuple.hpp>
#include <pythonic/include/functools/partial.hpp>
#include <pythonic/include/io/_io/TextIOWrapper/close.hpp>
#include <pythonic/include/io/_io/TextIOWrapper/write.hpp>
#include <pythonic/include/numpy/array.hpp>
#include <pythonic/include/numpy/ceil.hpp>
#include <pythonic/include/numpy/divide.hpp>
#include <pythonic/include/numpy/exp.hpp>
#include <pythonic/include/numpy/multiply.hpp>
#include <pythonic/include/numpy/nan.hpp>
#include <pythonic/include/operator_/add.hpp>
#include <pythonic/include/operator_/div.hpp>
#include <pythonic/include/operator_/eq.hpp>
#include <pythonic/include/operator_/ge.hpp>
#include <pythonic/include/operator_/gt.hpp>
#include <pythonic/include/operator_/iadd.hpp>
#include <pythonic/include/operator_/isub.hpp>
#include <pythonic/include/operator_/lt.hpp>
#include <pythonic/include/operator_/mul.hpp>
#include <pythonic/include/operator_/neg.hpp>
#include <pythonic/include/operator_/sub.hpp>
#include <pythonic/include/random/gauss.hpp>
#include <pythonic/include/random/random.hpp>
#include <pythonic/include/random/sample.hpp>
#include <pythonic/include/types/str.hpp>
#include <pythonic/builtins/False.hpp>
#include <pythonic/builtins/None.hpp>
#include <pythonic/builtins/ValueError.hpp>
#include <pythonic/builtins/abs.hpp>
#include <pythonic/builtins/bool_.hpp>
#include <pythonic/builtins/enumerate.hpp>
#include <pythonic/builtins/float_.hpp>
#include <pythonic/builtins/int_.hpp>
#include <pythonic/builtins/len.hpp>
#include <pythonic/builtins/list.hpp>
#include <pythonic/builtins/list/append.hpp>
#include <pythonic/builtins/map.hpp>
#include <pythonic/builtins/max.hpp>
#include <pythonic/builtins/open.hpp>
#include <pythonic/builtins/print.hpp>
#include <pythonic/builtins/pythran/and_.hpp>
#include <pythonic/builtins/range.hpp>
#include <pythonic/builtins/sorted.hpp>
#include <pythonic/builtins/str.hpp>
#include <pythonic/builtins/str/__mod__.hpp>
#include <pythonic/builtins/str/join.hpp>
#include <pythonic/builtins/sum.hpp>
#include <pythonic/builtins/tuple.hpp>
#include <pythonic/functools/partial.hpp>
#include <pythonic/io/_io/TextIOWrapper/close.hpp>
#include <pythonic/io/_io/TextIOWrapper/write.hpp>
#include <pythonic/numpy/array.hpp>
#include <pythonic/numpy/ceil.hpp>
#include <pythonic/numpy/divide.hpp>
#include <pythonic/numpy/exp.hpp>
#include <pythonic/numpy/multiply.hpp>
#include <pythonic/numpy/nan.hpp>
#include <pythonic/operator_/add.hpp>
#include <pythonic/operator_/div.hpp>
#include <pythonic/operator_/eq.hpp>
#include <pythonic/operator_/ge.hpp>
#include <pythonic/operator_/gt.hpp>
#include <pythonic/operator_/iadd.hpp>
#include <pythonic/operator_/isub.hpp>
#include <pythonic/operator_/lt.hpp>
#include <pythonic/operator_/mul.hpp>
#include <pythonic/operator_/neg.hpp>
#include <pythonic/operator_/sub.hpp>
#include <pythonic/random/gauss.hpp>
#include <pythonic/random/random.hpp>
#include <pythonic/random/sample.hpp>
#include <pythonic/types/str.hpp>
namespace __pythran_GLNetEISimLib
{
  struct multvecelem_lambda21
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type1;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type1>::type>::type __type2;
      typedef decltype(std::declval<__type0>()[std::declval<__type2>()]) __type3;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type1>::type>::type __type4;
      typedef typename pythonic::returnable<decltype(pythonic::operator_::mul(std::declval<__type3>(), std::declval<__type4>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& x, argument_type1&& __tuple00) const
    ;
  }  ;
  struct generate_IC_spikes_lambda20
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename pythonic::returnable<typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& X0, argument_type1&& i) const
    ;
  }  ;
  struct set_MF_network_IC_lambda19
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename pythonic::returnable<typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& theta, argument_type1&& i) const
    ;
  }  ;
  struct set_MF_network_IC_lambda18
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::abs{})>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::random::functor::gauss{})>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type2;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type3;
      typedef decltype(std::declval<__type1>()(std::declval<__type2>(), std::declval<__type3>())) __type4;
      typedef typename pythonic::returnable<decltype(std::declval<__type0>()(std::declval<__type4>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0&& VI0, argument_type1&& VI0Std, argument_type2&& i) const
    ;
  }  ;
  struct set_MF_network_IC_lambda17
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename pythonic::returnable<typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& theta, argument_type1&& i) const
    ;
  }  ;
  struct set_MF_network_IC_lambda16
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::abs{})>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::random::functor::gauss{})>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type2;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type3;
      typedef decltype(std::declval<__type1>()(std::declval<__type2>(), std::declval<__type3>())) __type4;
      typedef typename pythonic::returnable<decltype(std::declval<__type0>()(std::declval<__type4>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0&& VE0, argument_type1&& VE0Std, argument_type2&& i) const
    ;
  }  ;
  struct generate_random_net_fixed_input_lambda15
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::sorted{})>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::random::functor::sample{})>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type2;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type3;
      typedef decltype(std::declval<__type2>()(std::declval<__type3>())) __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type5;
      typedef decltype(std::declval<__type1>()(std::declval<__type4>(), std::declval<__type5>())) __type6;
      typedef decltype(std::declval<__type0>()(std::declval<__type6>())) __type7;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type8;
      typedef decltype(pythonic::operator_::sub(std::declval<__type8>(), std::declval<__type3>())) __type9;
      typedef decltype(std::declval<__type2>()(std::declval<__type9>())) __type10;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type11;
      typedef decltype(pythonic::operator_::sub(std::declval<__type11>(), std::declval<__type5>())) __type12;
      typedef decltype(std::declval<__type1>()(std::declval<__type10>(), std::declval<__type12>())) __type13;
      typedef decltype(std::declval<__type0>()(std::declval<__type13>())) __type14;
      typedef typename pythonic::returnable<decltype(pythonic::operator_::add(std::declval<__type7>(), std::declval<__type14>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4>::result_type operator()(argument_type0&& K, argument_type1&& K_ex, argument_type2&& N, argument_type3&& pN, argument_type4&& _) const
    ;
  }  ;
  struct RunSimulation_GLNetEIMF_static_lambda14
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type1;
      typedef typename pythonic::returnable<decltype(pythonic::operator_::div(std::declval<__type0>(), std::declval<__type1>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0&& I, argument_type1&& theta, argument_type2&& _) const
    ;
  }  ;
  struct RunSimulation_GLNetEIMF_static_lambda13
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename pythonic::returnable<typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& g, argument_type1&& _) const
    ;
  }  ;
  struct RunSimulation_GLNetEIMF_static_lambda12
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::io::_io::TextIOWrapper::functor::write{})>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::str::functor::join{})>::type>::type __type2;
      typedef pythonic::types::str __type3;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::str{})>::type>::type __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type5;
      typedef decltype(std::declval<__type4>()(std::declval<__type5>())) __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type7;
      typedef decltype(std::declval<__type4>()(std::declval<__type7>())) __type8;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type6>(), std::declval<__type8>())) __type9;
      typedef decltype(std::declval<__type2>()(std::declval<__type3>(), std::declval<__type9>())) __type10;
      typedef decltype(pythonic::operator_::add(std::declval<__type10>(), std::declval<__type3>())) __type11;
      typedef typename pythonic::returnable<decltype(std::declval<__type0>()(std::declval<__type1>(), std::declval<__type11>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0&& spkTimeFile, argument_type1&& t_ind, argument_type2&& k_ind) const
    ;
  }  ;
  struct RunSimulation_GLNetEIMF_adapt_lambda11
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::io::_io::TextIOWrapper::functor::write{})>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::str::functor::join{})>::type>::type __type2;
      typedef pythonic::types::str __type3;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::str{})>::type>::type __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type5;
      typedef decltype(std::declval<__type4>()(std::declval<__type5>())) __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type7;
      typedef decltype(std::declval<__type4>()(std::declval<__type7>())) __type8;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type6>(), std::declval<__type8>())) __type9;
      typedef decltype(std::declval<__type2>()(std::declval<__type3>(), std::declval<__type9>())) __type10;
      typedef decltype(pythonic::operator_::add(std::declval<__type10>(), std::declval<__type3>())) __type11;
      typedef typename pythonic::returnable<decltype(std::declval<__type0>()(std::declval<__type1>(), std::declval<__type11>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0&& spkTimeFile, argument_type1&& t_ind, argument_type2&& k_ind) const
    ;
  }  ;
  struct RunSimulation_GLNetEIMF_adapt_lambda10
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 >
    struct type
    {
      typedef typename pythonic::returnable<double>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5>::result_type operator()(argument_type0&& W, argument_type1&& A, argument_type2&& tauWinv, argument_type3&& uW, argument_type4&& rhoE, argument_type5&& rhoI) const
    ;
  }  ;
  struct RunSimulation_GLNetEIMF_aval_lambda9
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type1;
      typedef typename pythonic::returnable<decltype(pythonic::operator_::div(std::declval<__type0>(), std::declval<__type1>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0&& I, argument_type1&& theta, argument_type2&& _) const
    ;
  }  ;
  struct RunSimulation_GLNetEIMF_aval_lambda8
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename pythonic::returnable<typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& g, argument_type1&& _) const
    ;
  }  ;
  struct RunSimulation_GLNetEIMF_aval_lambda7
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::io::_io::TextIOWrapper::functor::write{})>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::str::functor::join{})>::type>::type __type2;
      typedef pythonic::types::str __type3;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::str{})>::type>::type __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type5;
      typedef decltype(std::declval<__type4>()(std::declval<__type5>())) __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type7;
      typedef decltype(std::declval<__type4>()(std::declval<__type7>())) __type8;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type6>(), std::declval<__type8>())) __type9;
      typedef decltype(std::declval<__type2>()(std::declval<__type3>(), std::declval<__type9>())) __type10;
      typedef decltype(pythonic::operator_::add(std::declval<__type10>(), std::declval<__type3>())) __type11;
      typedef typename pythonic::returnable<decltype(std::declval<__type0>()(std::declval<__type1>(), std::declval<__type11>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0&& spkTimeFile, argument_type1&& t_ind, argument_type2&& k_ind) const
    ;
  }  ;
  struct RunSimulation_GLNetEIMF_adaptthresh_lambda6
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename pythonic::returnable<typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& g, argument_type1&& _) const
    ;
  }  ;
  struct RunSimulation_GLNetEIMF_adaptthresh_lambda5
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::io::_io::TextIOWrapper::functor::write{})>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::str::functor::join{})>::type>::type __type2;
      typedef pythonic::types::str __type3;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::str{})>::type>::type __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type5;
      typedef decltype(std::declval<__type4>()(std::declval<__type5>())) __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type7;
      typedef decltype(std::declval<__type4>()(std::declval<__type7>())) __type8;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type6>(), std::declval<__type8>())) __type9;
      typedef decltype(std::declval<__type2>()(std::declval<__type3>(), std::declval<__type9>())) __type10;
      typedef decltype(pythonic::operator_::add(std::declval<__type10>(), std::declval<__type3>())) __type11;
      typedef typename pythonic::returnable<decltype(std::declval<__type0>()(std::declval<__type1>(), std::declval<__type11>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0&& spkTimeFile, argument_type1&& t_ind, argument_type2&& k_ind) const
    ;
  }  ;
  struct RunSimulation_GLNetEIRand_static_lambda4
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type1;
      typedef typename pythonic::returnable<decltype(pythonic::operator_::div(std::declval<__type0>(), std::declval<__type1>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0&& I, argument_type1&& theta, argument_type2&& r) const
    ;
  }  ;
  struct RunSimulation_GLNetEIRand_static_lambda3
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename pythonic::returnable<typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& g, argument_type1&& r) const
    ;
  }  ;
  struct RunSimulation_GLNetEIRand_static_lambda2
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type1;
      typedef decltype(pythonic::operator_::mul(std::declval<__type0>(), std::declval<__type1>())) __type2;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type3;
      typedef decltype(pythonic::operator_::mul(std::declval<__type2>(), std::declval<__type3>())) __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type5;
      typedef typename pythonic::returnable<decltype(pythonic::operator_::mul(std::declval<__type4>(), std::declval<__type5>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3>::result_type operator()(argument_type0&& J, argument_type1&& g, argument_type2&& q, argument_type3&& r) const
    ;
  }  ;
  struct RunSimulation_GLNetEIRand_static_lambda1
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type1;
      typedef decltype(pythonic::operator_::mul(std::declval<__type0>(), std::declval<__type1>())) __type2;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type3;
      typedef typename pythonic::returnable<decltype(pythonic::operator_::mul(std::declval<__type2>(), std::declval<__type3>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0&& J, argument_type1&& p, argument_type2&& r) const
    ;
  }  ;
  struct RunSimulation_GLNetEIRand_static_lambda0
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::io::_io::TextIOWrapper::functor::write{})>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::str::functor::join{})>::type>::type __type2;
      typedef pythonic::types::str __type3;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::str{})>::type>::type __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type5;
      typedef decltype(std::declval<__type4>()(std::declval<__type5>())) __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type7;
      typedef decltype(std::declval<__type4>()(std::declval<__type7>())) __type8;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type6>(), std::declval<__type8>())) __type9;
      typedef decltype(std::declval<__type2>()(std::declval<__type3>(), std::declval<__type9>())) __type10;
      typedef decltype(pythonic::operator_::add(std::declval<__type10>(), std::declval<__type3>())) __type11;
      typedef typename pythonic::returnable<decltype(std::declval<__type0>()(std::declval<__type1>(), std::declval<__type11>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0&& spkTimeFile, argument_type1&& t_ind, argument_type2&& k_ind) const
    ;
  }  ;
  struct write_spk_data_fake
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename pythonic::returnable<pythonic::types::none_type>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& t, argument_type1&& k) const
    ;
  }  ;
  struct save_spk_data
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type1;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type0>(), std::declval<__type1>())) __type2;
      typedef __type2 __ptype0;
      typedef __type2 __ptype1;
      typedef typename pythonic::returnable<typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0&& s, argument_type1&& t, argument_type2&& k) const
    ;
  }  ;
  struct save_spk_data_fake
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename pythonic::returnable<typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0&& s, argument_type1&& t, argument_type2&& k) const
    ;
  }  ;
  struct PoissonProcess_firingprob
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 >
    struct type
    {
      typedef double __type0;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::exp{})>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type2;
      typedef decltype(pythonic::operator_::neg(std::declval<__type2>())) __type3;
      typedef decltype(std::declval<__type1>()(std::declval<__type3>())) __type4;
      typedef typename pythonic::returnable<decltype(pythonic::operator_::sub(std::declval<__type0>(), std::declval<__type4>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 >
    typename type<argument_type0>::result_type operator()(argument_type0&& r) const
    ;
  }  ;
  struct PHI
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type2;
      typedef decltype(pythonic::operator_::sub(std::declval<__type1>(), std::declval<__type2>())) __type3;
      typedef decltype(pythonic::operator_::mul(std::declval<__type0>(), std::declval<__type3>())) __type4;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type5;
      typedef decltype(pythonic::operator_::gt(std::declval<__type1>(), std::declval<__type2>())) __type6;
      typedef decltype(std::declval<__type5>()(std::declval<__type6>())) __type7;
      typedef decltype(pythonic::operator_::mul(std::declval<__type4>(), std::declval<__type7>())) __type8;
      typedef double __type9;
      typedef decltype(pythonic::operator_::div(std::declval<__type9>(), std::declval<__type0>())) __type10;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::add(std::declval<__type2>(), std::declval<__type10>()))>::type __type11;
      typedef decltype(pythonic::operator_::lt(std::declval<__type1>(), std::declval<__type11>())) __type12;
      typedef decltype(std::declval<__type5>()(std::declval<__type12>())) __type13;
      typedef decltype(pythonic::operator_::mul(std::declval<__type8>(), std::declval<__type13>())) __type14;
      typedef decltype(pythonic::operator_::ge(std::declval<__type1>(), std::declval<__type11>())) __type15;
      typedef decltype(std::declval<__type5>()(std::declval<__type15>())) __type16;
      typedef typename pythonic::returnable<decltype(pythonic::operator_::add(std::declval<__type14>(), std::declval<__type16>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
    typename type<argument_type0, argument_type1, argument_type2>::result_type operator()(argument_type0&& V, argument_type1&& theta, argument_type2&& Gamma) const
    ;
  }  ;
  struct weightAdapt_increase
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type0;
      typedef double __type1;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type2;
      typedef decltype(pythonic::operator_::sub(std::declval<__type1>(), std::declval<__type2>())) __type3;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type5;
      typedef decltype(pythonic::operator_::mul(std::declval<__type4>(), std::declval<__type5>())) __type6;
      typedef decltype(pythonic::operator_::add(std::declval<__type3>(), std::declval<__type6>())) __type7;
      typedef decltype(pythonic::operator_::mul(std::declval<__type0>(), std::declval<__type7>())) __type8;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type9;
      typedef decltype(pythonic::operator_::mul(std::declval<__type2>(), std::declval<__type9>())) __type10;
      typedef typename pythonic::returnable<decltype(pythonic::operator_::add(std::declval<__type8>(), std::declval<__type10>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5>::result_type operator()(argument_type0&& W, argument_type1&& A, argument_type2&& tauWinv, argument_type3&& uW, argument_type4&& rhoE, argument_type5&& rhoI) const
    ;
  }  ;
  struct weightAdapt_decrease
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type0;
      typedef double __type1;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type2;
      typedef decltype(pythonic::operator_::sub(std::declval<__type1>(), std::declval<__type2>())) __type3;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type5;
      typedef decltype(pythonic::operator_::mul(std::declval<__type4>(), std::declval<__type5>())) __type6;
      typedef decltype(pythonic::operator_::sub(std::declval<__type3>(), std::declval<__type6>())) __type7;
      typedef decltype(pythonic::operator_::mul(std::declval<__type0>(), std::declval<__type7>())) __type8;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type9;
      typedef decltype(pythonic::operator_::mul(std::declval<__type2>(), std::declval<__type9>())) __type10;
      typedef typename pythonic::returnable<decltype(pythonic::operator_::add(std::declval<__type8>(), std::declval<__type10>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5>::result_type operator()(argument_type0&& W, argument_type1&& A, argument_type2&& tauWinv, argument_type3&& uW, argument_type4&& rhoE, argument_type5&& rhoI) const
    ;
  }  ;
  struct sumSynpaticInput_homog
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type0;
      typedef typename pythonic::assignable<double>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type2;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type3;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type5;
      typedef decltype(std::declval<__type4>()(std::declval<__type5>())) __type6;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type6>::type::iterator>::value_type>::type __type7;
      typedef decltype(std::declval<__type3>()[std::declval<__type7>()]) __type8;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type9;
      typedef decltype(std::declval<__type4>()(std::declval<__type9>())) __type10;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type10>::type::iterator>::value_type>::type __type11;
      typedef decltype(std::declval<__type8>()[std::declval<__type11>()]) __type12;
      typedef decltype(std::declval<__type2>()[std::declval<__type12>()]) __type13;
      typedef decltype(pythonic::operator_::add(std::declval<__type1>(), std::declval<__type13>())) __type14;
      typedef typename __combined<__type1,__type14>::type __type15;
      typedef typename __combined<__type15,__type13>::type __type16;
      typedef decltype(pythonic::operator_::mul(std::declval<__type0>(), std::declval<__type16>())) __type17;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type __type18;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type19;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type20;
      typedef decltype(std::declval<__type4>()(std::declval<__type9>(), std::declval<__type20>())) __type21;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type21>::type::iterator>::value_type>::type __type22;
      typedef decltype(std::declval<__type8>()[std::declval<__type22>()]) __type23;
      typedef decltype(std::declval<__type19>()[std::declval<__type23>()]) __type24;
      typedef decltype(pythonic::operator_::add(std::declval<__type1>(), std::declval<__type24>())) __type25;
      typedef typename __combined<__type1,__type25>::type __type26;
      typedef typename __combined<__type26,__type24>::type __type27;
      typedef decltype(pythonic::operator_::mul(std::declval<__type18>(), std::declval<__type27>())) __type28;
      typedef decltype(pythonic::operator_::sub(std::declval<__type17>(), std::declval<__type28>())) __type29;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type30;
      typedef decltype(std::declval<__type30>()(std::declval<__type20>())) __type31;
      typedef decltype(pythonic::operator_::div(std::declval<__type29>(), std::declval<__type31>())) __type32;
      typedef __type32 __ptype2;
      typedef __type7 __ptype3;
      typedef typename pythonic::returnable<pythonic::types::none_type>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8>::result_type operator()(argument_type0&& synapticInput, argument_type1&& K_ex, argument_type2&& K, argument_type3&& N, argument_type4&& XE, argument_type5&& XI, argument_type6&& J, argument_type7&& W, argument_type8&& C) const
    ;
  }  ;
  struct sumSynpaticInput
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 >
    struct type
    {
      typedef typename pythonic::assignable<double>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type2;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type3;
      typedef decltype(std::declval<__type2>()(std::declval<__type3>())) __type4;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type4>::type::iterator>::value_type>::type __type5;
      typedef decltype(std::declval<__type1>()[std::declval<__type5>()]) __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type7;
      typedef decltype(std::declval<__type2>()(std::declval<__type7>())) __type8;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type8>::type::iterator>::value_type>::type __type9;
      typedef decltype(std::declval<__type6>()[std::declval<__type9>()]) __type10;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type11;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type12;
      typedef decltype(std::declval<__type12>()[std::declval<__type5>()]) __type13;
      typedef decltype(std::declval<__type13>()[std::declval<__type9>()]) __type14;
      typedef decltype(std::declval<__type11>()[std::declval<__type14>()]) __type15;
      typedef decltype(pythonic::operator_::mul(std::declval<__type10>(), std::declval<__type15>())) __type16;
      typedef decltype(pythonic::operator_::add(std::declval<__type0>(), std::declval<__type16>())) __type17;
      typedef typename __combined<__type0,__type17>::type __type18;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type __type19;
      typedef decltype(std::declval<__type19>()[std::declval<__type5>()]) __type20;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type21;
      typedef decltype(std::declval<__type2>()(std::declval<__type7>(), std::declval<__type21>())) __type22;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type22>::type::iterator>::value_type>::type __type23;
      typedef decltype(pythonic::operator_::sub(std::declval<__type23>(), std::declval<__type7>())) __type24;
      typedef decltype(std::declval<__type20>()[std::declval<__type24>()]) __type25;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type26;
      typedef decltype(std::declval<__type13>()[std::declval<__type23>()]) __type27;
      typedef decltype(std::declval<__type26>()[std::declval<__type27>()]) __type28;
      typedef decltype(pythonic::operator_::mul(std::declval<__type25>(), std::declval<__type28>())) __type29;
      typedef decltype(pythonic::operator_::sub(std::declval<__type18>(), std::declval<__type29>())) __type30;
      typedef typename __combined<__type18,__type30>::type __type31;
      typedef typename __combined<__type31,__type16>::type __type32;
      typedef typename __combined<__type32,__type29>::type __type33;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type34;
      typedef decltype(std::declval<__type34>()(std::declval<__type21>())) __type35;
      typedef decltype(pythonic::operator_::div(std::declval<__type33>(), std::declval<__type35>())) __type36;
      typedef __type36 __ptype6;
      typedef __type5 __ptype7;
      typedef typename pythonic::returnable<pythonic::types::none_type>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8>::result_type operator()(argument_type0&& synapticInput, argument_type1&& K_ex, argument_type2&& K, argument_type3&& N, argument_type4&& XE, argument_type5&& XI, argument_type6&& J, argument_type7&& W, argument_type8&& C) const
    ;
  }  ;
  struct get_param
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef long __type0;
      typedef typename pythonic::lazy<__type0>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::int_{})>::type>::type __type2;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type3;
      typedef decltype(std::declval<__type2>()(std::declval<__type3>())) __type4;
      typedef typename pythonic::lazy<__type4>::type __type5;
      typedef typename __combined<__type1,__type5>::type __type6;
      typedef double __type7;
      typedef typename pythonic::lazy<__type7>::type __type8;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type9;
      typedef decltype(std::declval<__type9>()(std::declval<__type3>())) __type10;
      typedef typename pythonic::lazy<__type10>::type __type11;
      typedef typename __combined<__type8,__type11>::type __type12;
      typedef pythonic::types::str __type13;
      typedef typename pythonic::lazy<__type13>::type __type14;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::str{})>::type>::type __type15;
      typedef decltype(std::declval<__type15>()(std::declval<__type3>())) __type16;
      typedef typename pythonic::lazy<__type16>::type __type17;
      typedef typename __combined<__type14,__type17>::type __type18;
      typedef bool __type19;
      typedef typename pythonic::lazy<__type19>::type __type20;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::bool_{})>::type>::type __type21;
      typedef decltype(std::declval<__type21>()(std::declval<__type3>())) __type22;
      typedef typename pythonic::lazy<__type22>::type __type23;
      typedef typename __combined<__type20,__type23>::type __type24;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type6>(), std::declval<__type12>(), std::declval<__type18>(), std::declval<__type24>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& v, argument_type1&& vtype) const
    ;
  }  ;
  struct multvecelem
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::list{})>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::map{})>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::functools::functor::partial{})>::type>::type __type2;
      typedef multvecelem_lambda21 __type3;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type4;
      typedef decltype(std::declval<__type2>()(std::declval<__type3>(), std::declval<__type4>())) __type5;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::enumerate{})>::type>::type __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type7;
      typedef decltype(std::declval<__type6>()(std::declval<__type7>())) __type8;
      typedef decltype(std::declval<__type1>()(std::declval<__type5>(), std::declval<__type8>())) __type9;
      typedef typename pythonic::returnable<decltype(std::declval<__type0>()(std::declval<__type9>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& x, argument_type1&& y) const
    ;
  }  ;
  struct GLNetEIMF_iter
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type1;
      typedef decltype(pythonic::operator_::mul(std::declval<__type0>(), std::declval<__type1>())) __type2;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type9>::type>::type __type3;
      typedef decltype(pythonic::operator_::add(std::declval<__type2>(), std::declval<__type3>())) __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type5;
      typedef decltype(pythonic::operator_::add(std::declval<__type4>(), std::declval<__type5>())) __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type __type7;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type11>::type>::type __type8;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type9;
      typedef decltype(pythonic::operator_::mul(std::declval<__type8>(), std::declval<__type9>())) __type10;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type12>::type>::type __type11;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type10>::type>::type __type12;
      typedef decltype(pythonic::operator_::mul(std::declval<__type11>(), std::declval<__type12>())) __type13;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type14;
      typedef decltype(pythonic::operator_::mul(std::declval<__type13>(), std::declval<__type14>())) __type15;
      typedef decltype(pythonic::operator_::sub(std::declval<__type10>(), std::declval<__type15>())) __type16;
      typedef decltype(pythonic::operator_::mul(std::declval<__type7>(), std::declval<__type16>())) __type17;
      typedef decltype(pythonic::operator_::add(std::declval<__type6>(), std::declval<__type17>())) __type18;
      typedef double __type19;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type20;
      typedef decltype(pythonic::operator_::sub(std::declval<__type19>(), std::declval<__type20>())) __type21;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::mul(std::declval<__type18>(), std::declval<__type21>()))>::type __type22;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type23;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::random::functor::random{})>::type>::type __type24;
      typedef decltype(std::declval<__type24>()()) __type25;
      typedef PHI __type26;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type27;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type28;
      typedef decltype(std::declval<__type26>()(std::declval<__type22>(), std::declval<__type27>(), std::declval<__type28>())) __type29;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type13>::type>::type __type30;
      typedef decltype(pythonic::operator_::sub(std::declval<__type19>(), std::declval<__type30>())) __type31;
      typedef decltype(pythonic::operator_::mul(std::declval<__type29>(), std::declval<__type31>())) __type32;
      typedef decltype(pythonic::operator_::add(std::declval<__type32>(), std::declval<__type30>())) __type33;
      typedef decltype(pythonic::operator_::lt(std::declval<__type25>(), std::declval<__type33>())) __type34;
      typedef typename pythonic::assignable<decltype(std::declval<__type23>()(std::declval<__type34>()))>::type __type35;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type22>(), std::declval<__type35>(), std::declval<__type27>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13>::result_type operator()(argument_type0&& V, argument_type1&& X, argument_type2&& rhoE, argument_type3&& rhoI, argument_type4&& Iext, argument_type5&& mu, argument_type6&& theta, argument_type7&& J, argument_type8&& Gamma, argument_type9&& I, argument_type10&& g, argument_type11&& p, argument_type12&& q, argument_type13&& P_poisson) const
    ;
  }  ;
  struct GLNetEIMF_adaptthresh_iter
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type2;
      typedef decltype(pythonic::operator_::mul(std::declval<__type1>(), std::declval<__type2>())) __type3;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type9>::type>::type __type4;
      typedef decltype(pythonic::operator_::add(std::declval<__type3>(), std::declval<__type4>())) __type5;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type6;
      typedef decltype(pythonic::operator_::add(std::declval<__type5>(), std::declval<__type6>())) __type7;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type __type8;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type11>::type>::type __type9;
      typedef decltype(pythonic::operator_::mul(std::declval<__type8>(), std::declval<__type9>())) __type10;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type11;
      typedef decltype(pythonic::operator_::mul(std::declval<__type10>(), std::declval<__type11>())) __type12;
      typedef decltype(pythonic::operator_::add(std::declval<__type7>(), std::declval<__type12>())) __type13;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type12>::type>::type __type14;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type10>::type>::type __type15;
      typedef decltype(pythonic::operator_::mul(std::declval<__type14>(), std::declval<__type15>())) __type16;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type17;
      typedef decltype(pythonic::operator_::mul(std::declval<__type16>(), std::declval<__type17>())) __type18;
      typedef decltype(pythonic::operator_::sub(std::declval<__type13>(), std::declval<__type18>())) __type19;
      typedef double __type20;
      typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type>::type __type21;
      typedef decltype(pythonic::operator_::sub(std::declval<__type20>(), std::declval<__type21>())) __type22;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::mul(std::declval<__type19>(), std::declval<__type22>()))>::type __type23;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type24;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::random::functor::random{})>::type>::type __type25;
      typedef decltype(std::declval<__type25>()()) __type26;
      typedef PHI __type27;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type28;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type13>::type>::type __type29;
      typedef decltype(pythonic::operator_::sub(std::declval<__type20>(), std::declval<__type29>())) __type30;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type14>::type>::type __type31;
      typedef decltype(pythonic::operator_::mul(std::declval<__type31>(), std::declval<__type21>())) __type32;
      typedef decltype(pythonic::operator_::add(std::declval<__type30>(), std::declval<__type32>())) __type33;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::mul(std::declval<__type28>(), std::declval<__type33>()))>::type __type34;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type35;
      typedef decltype(std::declval<__type27>()(std::declval<__type23>(), std::declval<__type34>(), std::declval<__type35>())) __type36;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type15>::type>::type __type37;
      typedef decltype(pythonic::operator_::sub(std::declval<__type20>(), std::declval<__type37>())) __type38;
      typedef decltype(pythonic::operator_::mul(std::declval<__type36>(), std::declval<__type38>())) __type39;
      typedef decltype(pythonic::operator_::add(std::declval<__type39>(), std::declval<__type37>())) __type40;
      typedef decltype(pythonic::operator_::lt(std::declval<__type26>(), std::declval<__type40>())) __type41;
      typedef typename pythonic::assignable<decltype(std::declval<__type24>()(std::declval<__type41>()))>::type __type42;
      typedef __type0 __ptype10;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type23>(), std::declval<__type42>(), std::declval<__type34>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13, argument_type14, argument_type15>::result_type operator()(argument_type0&& V, argument_type1&& X, argument_type2&& rhoE, argument_type3&& rhoI, argument_type4&& Iext, argument_type5&& mu, argument_type6&& theta, argument_type7&& J, argument_type8&& Gamma, argument_type9&& I, argument_type10&& W_I, argument_type11&& p, argument_type12&& q, argument_type13&& tauTinv, argument_type14&& uT, argument_type15&& P_poisson) const
    ;
  }  ;
  struct GLNetEIRand_iter
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type1;
      typedef decltype(pythonic::operator_::mul(std::declval<__type0>(), std::declval<__type1>())) __type2;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type __type3;
      typedef decltype(pythonic::operator_::add(std::declval<__type2>(), std::declval<__type3>())) __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type5;
      typedef decltype(pythonic::operator_::add(std::declval<__type4>(), std::declval<__type5>())) __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type7;
      typedef decltype(pythonic::operator_::add(std::declval<__type6>(), std::declval<__type7>())) __type8;
      typedef double __type9;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type10;
      typedef decltype(pythonic::operator_::sub(std::declval<__type9>(), std::declval<__type10>())) __type11;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::mul(std::declval<__type8>(), std::declval<__type11>()))>::type __type12;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type13;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::random::functor::random{})>::type>::type __type14;
      typedef decltype(std::declval<__type14>()()) __type15;
      typedef PHI __type16;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type17;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type18;
      typedef decltype(std::declval<__type16>()(std::declval<__type12>(), std::declval<__type17>(), std::declval<__type18>())) __type19;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type20;
      typedef decltype(pythonic::operator_::sub(std::declval<__type9>(), std::declval<__type20>())) __type21;
      typedef decltype(pythonic::operator_::mul(std::declval<__type19>(), std::declval<__type21>())) __type22;
      typedef decltype(pythonic::operator_::add(std::declval<__type22>(), std::declval<__type20>())) __type23;
      typedef decltype(pythonic::operator_::lt(std::declval<__type15>(), std::declval<__type23>())) __type24;
      typedef typename pythonic::assignable<decltype(std::declval<__type13>()(std::declval<__type24>()))>::type __type25;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type12>(), std::declval<__type25>(), std::declval<__type17>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8>::result_type operator()(argument_type0&& V, argument_type1&& X, argument_type2&& synapticInput, argument_type3&& Iext, argument_type4&& mu, argument_type5&& theta, argument_type6&& Gamma, argument_type7&& I, argument_type8&& P_poisson) const
    ;
  }  ;
  struct GLNetEIRand_adaptthresh_iter
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type2;
      typedef decltype(pythonic::operator_::mul(std::declval<__type1>(), std::declval<__type2>())) __type3;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type __type4;
      typedef decltype(pythonic::operator_::add(std::declval<__type3>(), std::declval<__type4>())) __type5;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type6;
      typedef decltype(pythonic::operator_::add(std::declval<__type5>(), std::declval<__type6>())) __type7;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type8;
      typedef decltype(pythonic::operator_::add(std::declval<__type7>(), std::declval<__type8>())) __type9;
      typedef double __type10;
      typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type>::type __type11;
      typedef decltype(pythonic::operator_::sub(std::declval<__type10>(), std::declval<__type11>())) __type12;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::mul(std::declval<__type9>(), std::declval<__type12>()))>::type __type13;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type14;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::random::functor::random{})>::type>::type __type15;
      typedef decltype(std::declval<__type15>()()) __type16;
      typedef PHI __type17;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type18;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type19;
      typedef decltype(pythonic::operator_::sub(std::declval<__type10>(), std::declval<__type19>())) __type20;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type9>::type>::type __type21;
      typedef decltype(pythonic::operator_::mul(std::declval<__type21>(), std::declval<__type11>())) __type22;
      typedef decltype(pythonic::operator_::add(std::declval<__type20>(), std::declval<__type22>())) __type23;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::mul(std::declval<__type18>(), std::declval<__type23>()))>::type __type24;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type25;
      typedef decltype(std::declval<__type17>()(std::declval<__type13>(), std::declval<__type24>(), std::declval<__type25>())) __type26;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type10>::type>::type __type27;
      typedef decltype(pythonic::operator_::sub(std::declval<__type10>(), std::declval<__type27>())) __type28;
      typedef decltype(pythonic::operator_::mul(std::declval<__type26>(), std::declval<__type28>())) __type29;
      typedef decltype(pythonic::operator_::add(std::declval<__type29>(), std::declval<__type27>())) __type30;
      typedef decltype(pythonic::operator_::lt(std::declval<__type16>(), std::declval<__type30>())) __type31;
      typedef typename pythonic::assignable<decltype(std::declval<__type14>()(std::declval<__type31>()))>::type __type32;
      typedef __type0 __ptype11;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type13>(), std::declval<__type32>(), std::declval<__type24>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10>::result_type operator()(argument_type0&& V, argument_type1&& X, argument_type2&& synapticInput, argument_type3&& Iext, argument_type4&& mu, argument_type5&& theta, argument_type6&& Gamma, argument_type7&& I, argument_type8&& tauTinv, argument_type9&& uT, argument_type10&& P_poisson) const
    ;
  }  ;
  struct generate_IC_spikes
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 = bool>
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::array{})>::type>::type __type0;
      typedef double __type1;
      typedef pythonic::types::list<typename std::remove_reference<__type1>::type> __type2;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::max{})>::type>::type __type3;
      typedef long __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type5;
      typedef typename __combined<__type4,__type5>::type __type6;
      typedef decltype(std::declval<__type3>()(std::declval<__type6>(), std::declval<__type5>())) __type7;
      typedef decltype(pythonic::operator_::mul(std::declval<__type2>(), std::declval<__type7>())) __type8;
      typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type8>()))>::type __type9;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::random::functor::sample{})>::type>::type __type10;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type11;
      typedef decltype(std::declval<__type11>()(std::declval<__type5>())) __type12;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type13;
      typedef decltype(std::declval<__type10>()(std::declval<__type12>(), std::declval<__type13>())) __type14;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type14>::type::iterator>::value_type>::type __type15;
      typedef indexable<__type15> __type16;
      typedef typename __combined<__type9,__type16>::type __type17;
      typedef container<typename std::remove_reference<__type1>::type> __type18;
      typedef typename __combined<__type17,__type18>::type __type19;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::map{})>::type>::type __type20;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::functools::functor::partial{})>::type>::type __type21;
      typedef generate_IC_spikes_lambda20 __type22;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type23;
      typedef decltype(std::declval<__type21>()(std::declval<__type22>(), std::declval<__type23>())) __type24;
      typedef decltype(std::declval<__type20>()(std::declval<__type24>(), std::declval<__type12>())) __type25;
      typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type25>()))>::type __type26;
      typedef typename pythonic::returnable<typename __combined<__type19,__type26>::type>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 = bool>
    typename type<argument_type0, argument_type1, argument_type2, argument_type3>::result_type operator()(argument_type0&& X0, argument_type1&& N, argument_type2&& K, argument_type3 is_random= pythonic::builtins::False) const
    ;
  }  ;
  struct save_initial_spkdata
  {
    typedef void callable;
    typedef void pure;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 >
    struct type
    {
      typedef typename pythonic::assignable<pythonic::types::empty_list>::type __type0;
      typedef long __type1;
      typedef typename pythonic::assignable<long>::type __type2;
      typedef typename save_spk_data::type<__type0, __type1, __type2>::__ptype0 __type3;
      typedef pythonic::types::list<typename std::remove_reference<__type3>::type> __type4;
      typedef typename __combined<__type0,__type4>::type __type5;
      typedef typename save_spk_data::type<__type5, __type1, __type2>::__ptype1 __type6;
      typedef pythonic::types::list<typename std::remove_reference<__type6>::type> __type7;
      typedef typename __combined<__type5,__type7>::type __type8;
      typedef save_spk_data __type9;
      typedef decltype(std::declval<__type9>()(std::declval<__type8>(), std::declval<__type1>(), std::declval<__type2>())) __type10;
      typedef typename __combined<__type8,__type10>::type __type11;
      typedef typename __combined<__type4,__type7>::type __type12;
      typedef typename pythonic::assignable<typename __combined<__type12,__type10>::type>::type __type13;
      typedef typename __combined<__type11,__type13>::type __type14;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type15;
      typedef decltype(pythonic::operator_::add(std::declval<__type2>(), std::declval<__type15>())) __type16;
      typedef typename save_spk_data::type<__type14, __type1, __type16>::__ptype0 __type17;
      typedef pythonic::types::list<typename std::remove_reference<__type17>::type> __type18;
      typedef typename __combined<__type11,__type18>::type __type19;
      typedef typename __combined<__type14,__type18>::type __type20;
      typedef typename save_spk_data::type<__type20, __type1, __type16>::__ptype1 __type21;
      typedef pythonic::types::list<typename std::remove_reference<__type21>::type> __type22;
      typedef typename __combined<__type19,__type22>::type __type23;
      typedef typename __combined<__type20,__type22>::type __type24;
      typedef decltype(std::declval<__type9>()(std::declval<__type24>(), std::declval<__type1>(), std::declval<__type16>())) __type25;
      typedef typename __combined<__type23,__type25>::type __type26;
      typedef typename __combined<__type13,__type18>::type __type27;
      typedef typename __combined<__type27,__type22>::type __type28;
      typedef typename __combined<__type28,__type25>::type __type29;
      typedef typename __combined<__type26,__type29>::type __type30;
      typedef typename __combined<__type30,__type24>::type __type31;
      typedef typename __combined<__type18,__type22>::type __type32;
      typedef typename pythonic::assignable<typename __combined<__type32,__type25>::type>::type __type33;
      typedef typename pythonic::returnable<typename __combined<__type31,__type33>::type>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3>::result_type operator()(argument_type0&& XE, argument_type1&& XI, argument_type2&& pN, argument_type3&& qN) const
    ;
  }  ;
  struct generate_random_net_fixed_input
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::array{})>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::map{})>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::functools::functor::partial{})>::type>::type __type2;
      typedef generate_random_net_fixed_input_lambda15 __type3;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type5;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type7;
      typedef decltype(std::declval<__type2>()(std::declval<__type3>(), std::declval<__type4>(), std::declval<__type5>(), std::declval<__type6>(), std::declval<__type7>())) __type8;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type9;
      typedef decltype(std::declval<__type9>()(std::declval<__type6>())) __type10;
      typedef decltype(std::declval<__type1>()(std::declval<__type8>(), std::declval<__type10>())) __type11;
      typedef typename pythonic::returnable<decltype(std::declval<__type0>()(std::declval<__type11>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3>::result_type operator()(argument_type0&& K_ex, argument_type1&& pN, argument_type2&& K, argument_type3&& N) const
    ;
  }  ;
  struct get_system_parameters
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef get_param __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type1;
      typedef pythonic::types::str __type2;
      typedef decltype(std::declval<__type1>()[std::declval<__type2>()]) __type3;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type4;
      typedef decltype(std::declval<__type4>()[std::declval<__type2>()]) __type5;
      typedef decltype(std::declval<__type0>()(std::declval<__type3>(), std::declval<__type5>())) __type6;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type6>::type>::type __type7;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type6>::type>::type __type8;
      typedef typename std::tuple_element<3,typename std::remove_reference<__type6>::type>::type __type9;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type6>::type>::type __type10;
      typedef double __type11;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type7>(), std::declval<__type7>(), std::declval<__type7>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type7>(), std::declval<__type8>(), std::declval<__type9>(), std::declval<__type7>(), std::declval<__type8>(), std::declval<__type9>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type8>(), std::declval<__type9>(), std::declval<__type7>(), std::declval<__type10>(), std::declval<__type8>(), std::declval<__type7>(), std::declval<__type11>(), std::declval<__type9>(), std::declval<__type10>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& simParam_dict, argument_type1&& paramType_dict) const
    ;
  }  ;
  struct run_transient_GLNetEIMF_static
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 , typename argument_type16 , typename argument_type17 , typename argument_type18 , typename argument_type19 , typename argument_type20 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type1;
      typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type>::type __type2;
      typedef double __type3;
      typedef typename pythonic::lazy<__type3>::type __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type5;
      typedef GLNetEIMF_iter __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type7;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type8;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type9;
      typedef decltype(std::declval<__type8>()(std::declval<__type9>())) __type10;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type10>::type::iterator>::value_type>::type __type11;
      typedef decltype(std::declval<__type7>()[std::declval<__type11>()]) __type12;
      typedef decltype(std::declval<__type5>()[std::declval<__type11>()]) __type13;
      typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type>::type __type14;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type12>::type>::type __type15;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type13>::type>::type __type16;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type14>::type>::type __type17;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type15>::type>::type __type18;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type16>::type>::type __type19;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type17>::type>::type __type20;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type18>::type>::type __type21;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type19>::type>::type __type22;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type20>::type>::type __type23;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type10>::type>::type __type24;
      typedef typename pythonic::assignable<decltype(std::declval<__type6>()(std::declval<__type12>(), std::declval<__type13>(), std::declval<__type2>(), std::declval<__type14>(), std::declval<__type15>(), std::declval<__type16>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type22>(), std::declval<__type23>(), std::declval<__type24>()))>::type __type25;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type25>::type>::type __type26;
      typedef container<typename std::remove_reference<__type26>::type> __type27;
      typedef typename __combined<__type5,__type27>::type __type28;
      typedef indexable<__type11> __type29;
      typedef typename __combined<__type28,__type29>::type __type30;
      typedef decltype(std::declval<__type30>()[std::declval<__type11>()]) __type31;
      typedef decltype(pythonic::operator_::add(std::declval<__type4>(), std::declval<__type31>())) __type32;
      typedef typename pythonic::lazy<__type32>::type __type33;
      typedef typename __combined<__type4,__type33>::type __type34;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type35;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type34>(), std::declval<__type35>()))>::type __type36;
      typedef typename __combined<__type2,__type36>::type __type37;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type38;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type39;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type __type40;
      typedef decltype(std::declval<__type8>()(std::declval<__type40>())) __type41;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type41>::type::iterator>::value_type>::type __type42;
      typedef decltype(std::declval<__type39>()[std::declval<__type42>()]) __type43;
      typedef decltype(std::declval<__type38>()[std::declval<__type42>()]) __type44;
      typedef typename pythonic::assignable<decltype(std::declval<__type6>()(std::declval<__type43>(), std::declval<__type44>(), std::declval<__type2>(), std::declval<__type14>(), std::declval<__type15>(), std::declval<__type16>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type22>(), std::declval<__type23>(), std::declval<__type3>()))>::type __type45;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type45>::type>::type __type46;
      typedef container<typename std::remove_reference<__type46>::type> __type47;
      typedef typename __combined<__type38,__type47>::type __type48;
      typedef indexable<__type42> __type49;
      typedef typename __combined<__type48,__type49>::type __type50;
      typedef decltype(std::declval<__type50>()[std::declval<__type42>()]) __type51;
      typedef decltype(pythonic::operator_::add(std::declval<__type4>(), std::declval<__type51>())) __type52;
      typedef typename pythonic::lazy<__type52>::type __type53;
      typedef typename __combined<__type4,__type53>::type __type54;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type9>::type>::type __type55;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type54>(), std::declval<__type55>()))>::type __type56;
      typedef typename __combined<__type14,__type56>::type __type57;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type25>::type>::type __type58;
      typedef container<typename std::remove_reference<__type58>::type> __type59;
      typedef typename __combined<__type7,__type59>::type __type60;
      typedef typename __combined<__type60,__type29>::type __type61;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type45>::type>::type __type62;
      typedef container<typename std::remove_reference<__type62>::type> __type63;
      typedef typename __combined<__type39,__type63>::type __type64;
      typedef typename __combined<__type64,__type49>::type __type65;
      typedef __type0 __ptype12;
      typedef __type1 __ptype13;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type37>(), std::declval<__type57>(), std::declval<__type61>(), std::declval<__type30>(), std::declval<__type65>(), std::declval<__type50>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 , typename argument_type16 , typename argument_type17 , typename argument_type18 , typename argument_type19 , typename argument_type20 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13, argument_type14, argument_type15, argument_type16, argument_type17, argument_type18, argument_type19, argument_type20>::result_type operator()(argument_type0&& VE, argument_type1&& XE, argument_type2&& VI, argument_type3&& XI, argument_type4&& rhoETemp, argument_type5&& rhoITemp, argument_type6&& pN, argument_type7&& qN, argument_type8&& pN_fl, argument_type9&& qN_fl, argument_type10&& P_firing_poisson, argument_type11&& tTrans, argument_type12&& Iext, argument_type13&& mu, argument_type14&& theta, argument_type15&& J, argument_type16&& Gamma, argument_type17&& I, argument_type18&& g, argument_type19&& p, argument_type20&& q) const
    ;
  }  ;
  struct run_transient_GLNetEIMF_aval
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 , typename argument_type16 , typename argument_type17 , typename argument_type18 , typename argument_type19 , typename argument_type20 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type1;
      typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type>::type __type2;
      typedef double __type3;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type4;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type3>(), std::declval<__type4>()))>::type __type5;
      typedef typename __combined<__type2,__type5>::type __type6;
      typedef typename pythonic::lazy<__type3>::type __type7;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type8;
      typedef long __type9;
      typedef container<typename std::remove_reference<__type9>::type> __type10;
      typedef typename __combined<__type8,__type10>::type __type11;
      typedef indexable<__type9> __type12;
      typedef typename __combined<__type11,__type12>::type __type13;
      typedef GLNetEIMF_iter __type14;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type15;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type16;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type17;
      typedef decltype(std::declval<__type16>()(std::declval<__type17>())) __type18;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type18>::type::iterator>::value_type>::type __type19;
      typedef decltype(std::declval<__type15>()[std::declval<__type19>()]) __type20;
      typedef decltype(std::declval<__type13>()[std::declval<__type19>()]) __type21;
      typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type>::type __type22;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type12>::type>::type __type23;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type13>::type>::type __type24;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type14>::type>::type __type25;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type15>::type>::type __type26;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type16>::type>::type __type27;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type17>::type>::type __type28;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type18>::type>::type __type29;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type19>::type>::type __type30;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type20>::type>::type __type31;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type10>::type>::type __type32;
      typedef typename pythonic::assignable<decltype(std::declval<__type14>()(std::declval<__type20>(), std::declval<__type21>(), std::declval<__type6>(), std::declval<__type22>(), std::declval<__type23>(), std::declval<__type24>(), std::declval<__type25>(), std::declval<__type26>(), std::declval<__type27>(), std::declval<__type28>(), std::declval<__type29>(), std::declval<__type30>(), std::declval<__type31>(), std::declval<__type32>()))>::type __type33;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type33>::type>::type __type34;
      typedef container<typename std::remove_reference<__type34>::type> __type35;
      typedef typename __combined<__type13,__type35>::type __type36;
      typedef indexable<__type19> __type37;
      typedef typename __combined<__type36,__type37>::type __type38;
      typedef decltype(std::declval<__type38>()[std::declval<__type19>()]) __type39;
      typedef decltype(pythonic::operator_::add(std::declval<__type7>(), std::declval<__type39>())) __type40;
      typedef typename pythonic::lazy<__type40>::type __type41;
      typedef typename __combined<__type7,__type41>::type __type42;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type42>(), std::declval<__type4>()))>::type __type43;
      typedef typename __combined<__type6,__type43>::type __type44;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type45;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type46;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type __type47;
      typedef decltype(std::declval<__type16>()(std::declval<__type47>())) __type48;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type48>::type::iterator>::value_type>::type __type49;
      typedef decltype(std::declval<__type46>()[std::declval<__type49>()]) __type50;
      typedef decltype(std::declval<__type45>()[std::declval<__type49>()]) __type51;
      typedef typename pythonic::assignable<decltype(std::declval<__type14>()(std::declval<__type50>(), std::declval<__type51>(), std::declval<__type6>(), std::declval<__type22>(), std::declval<__type23>(), std::declval<__type24>(), std::declval<__type25>(), std::declval<__type26>(), std::declval<__type27>(), std::declval<__type28>(), std::declval<__type29>(), std::declval<__type30>(), std::declval<__type31>(), std::declval<__type3>()))>::type __type52;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type52>::type>::type __type53;
      typedef container<typename std::remove_reference<__type53>::type> __type54;
      typedef typename __combined<__type45,__type54>::type __type55;
      typedef indexable<__type49> __type56;
      typedef typename __combined<__type55,__type56>::type __type57;
      typedef decltype(std::declval<__type57>()[std::declval<__type49>()]) __type58;
      typedef decltype(pythonic::operator_::add(std::declval<__type7>(), std::declval<__type58>())) __type59;
      typedef typename pythonic::lazy<__type59>::type __type60;
      typedef typename __combined<__type7,__type60>::type __type61;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type9>::type>::type __type62;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type61>(), std::declval<__type62>()))>::type __type63;
      typedef typename __combined<__type22,__type63>::type __type64;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type33>::type>::type __type65;
      typedef container<typename std::remove_reference<__type65>::type> __type66;
      typedef typename __combined<__type15,__type66>::type __type67;
      typedef typename __combined<__type67,__type37>::type __type68;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type52>::type>::type __type69;
      typedef container<typename std::remove_reference<__type69>::type> __type70;
      typedef typename __combined<__type46,__type70>::type __type71;
      typedef typename __combined<__type71,__type56>::type __type72;
      typedef __type0 __ptype30;
      typedef __type1 __ptype31;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type44>(), std::declval<__type64>(), std::declval<__type68>(), std::declval<__type38>(), std::declval<__type72>(), std::declval<__type57>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 , typename argument_type16 , typename argument_type17 , typename argument_type18 , typename argument_type19 , typename argument_type20 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13, argument_type14, argument_type15, argument_type16, argument_type17, argument_type18, argument_type19, argument_type20>::result_type operator()(argument_type0&& VE, argument_type1&& XE, argument_type2&& VI, argument_type3&& XI, argument_type4&& rhoETemp, argument_type5&& rhoITemp, argument_type6&& pN, argument_type7&& qN, argument_type8&& pN_fl, argument_type9&& qN_fl, argument_type10&& P_firing_poisson, argument_type11&& tTrans, argument_type12&& Iext, argument_type13&& mu, argument_type14&& theta, argument_type15&& J, argument_type16&& Gamma, argument_type17&& I, argument_type18&& g, argument_type19&& p, argument_type20&& q) const
    ;
  }  ;
  struct run_transient_GLNetEIMF_adaptthresh
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 , typename argument_type16 , typename argument_type17 , typename argument_type18 , typename argument_type19 , typename argument_type20 , typename argument_type21 , typename argument_type22 , typename argument_type23 , typename argument_type24 , typename argument_type25 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type __type1;
      typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type>::type __type2;
      typedef double __type3;
      typedef typename pythonic::lazy<__type3>::type __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type5;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type6;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type7;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type9>::type>::type __type8;
      typedef decltype(std::declval<__type7>()(std::declval<__type8>())) __type9;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type9>::type::iterator>::value_type>::type __type10;
      typedef decltype(std::declval<__type6>()[std::declval<__type10>()]) __type11;
      typedef decltype(std::declval<__type5>()[std::declval<__type10>()]) __type12;
      typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type>::type __type13;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type17>::type>::type __type14;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type18>::type>::type __type15;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type16;
      typedef decltype(std::declval<__type16>()[std::declval<__type10>()]) __type17;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type19>::type>::type __type18;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type20>::type>::type __type19;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type21>::type>::type __type20;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type13>::type>::type __type21;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type22>::type>::type __type22;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type23>::type>::type __type23;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type24>::type>::type __type24;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type25>::type>::type __type25;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type14>::type>::type __type26;
      typedef typename GLNetEIMF_adaptthresh_iter::type<__type11, __type12, __type2, __type13, __type14, __type15, __type17, __type18, __type19, __type20, __type21, __type22, __type23, __type24, __type25, __type26>::__ptype10 __type27;
      typedef container<typename std::remove_reference<__type27>::type> __type28;
      typedef typename __combined<__type5,__type28>::type __type29;
      typedef GLNetEIMF_adaptthresh_iter __type30;
      typedef typename pythonic::assignable<decltype(std::declval<__type30>()(std::declval<__type11>(), std::declval<__type12>(), std::declval<__type2>(), std::declval<__type13>(), std::declval<__type14>(), std::declval<__type15>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type22>(), std::declval<__type23>(), std::declval<__type24>(), std::declval<__type25>(), std::declval<__type26>()))>::type __type31;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type31>::type>::type __type32;
      typedef container<typename std::remove_reference<__type32>::type> __type33;
      typedef typename __combined<__type29,__type33>::type __type34;
      typedef indexable<__type10> __type35;
      typedef typename __combined<__type34,__type35>::type __type36;
      typedef decltype(std::declval<__type36>()[std::declval<__type10>()]) __type37;
      typedef decltype(pythonic::operator_::add(std::declval<__type4>(), std::declval<__type37>())) __type38;
      typedef typename pythonic::lazy<__type38>::type __type39;
      typedef typename __combined<__type4,__type39>::type __type40;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type11>::type>::type __type41;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type40>(), std::declval<__type41>()))>::type __type42;
      typedef typename __combined<__type2,__type42>::type __type43;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type44;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type45;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type10>::type>::type __type46;
      typedef decltype(std::declval<__type7>()(std::declval<__type46>())) __type47;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type47>::type::iterator>::value_type>::type __type48;
      typedef decltype(std::declval<__type45>()[std::declval<__type48>()]) __type49;
      typedef decltype(std::declval<__type44>()[std::declval<__type48>()]) __type50;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type51;
      typedef decltype(std::declval<__type51>()[std::declval<__type48>()]) __type52;
      typedef typename GLNetEIMF_adaptthresh_iter::type<__type49, __type50, __type2, __type13, __type14, __type15, __type52, __type18, __type19, __type20, __type21, __type22, __type23, __type24, __type25, __type3>::__ptype10 __type53;
      typedef container<typename std::remove_reference<__type53>::type> __type54;
      typedef typename __combined<__type44,__type54>::type __type55;
      typedef typename pythonic::assignable<decltype(std::declval<__type30>()(std::declval<__type49>(), std::declval<__type50>(), std::declval<__type2>(), std::declval<__type13>(), std::declval<__type14>(), std::declval<__type15>(), std::declval<__type52>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type22>(), std::declval<__type23>(), std::declval<__type24>(), std::declval<__type25>(), std::declval<__type3>()))>::type __type56;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type56>::type>::type __type57;
      typedef container<typename std::remove_reference<__type57>::type> __type58;
      typedef typename __combined<__type55,__type58>::type __type59;
      typedef indexable<__type48> __type60;
      typedef typename __combined<__type59,__type60>::type __type61;
      typedef decltype(std::declval<__type61>()[std::declval<__type48>()]) __type62;
      typedef decltype(pythonic::operator_::add(std::declval<__type4>(), std::declval<__type62>())) __type63;
      typedef typename pythonic::lazy<__type63>::type __type64;
      typedef typename __combined<__type4,__type64>::type __type65;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type12>::type>::type __type66;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type65>(), std::declval<__type66>()))>::type __type67;
      typedef typename __combined<__type13,__type67>::type __type68;
      typedef typename pythonic::assignable<double>::type __type69;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type31>::type>::type __type70;
      typedef container<typename std::remove_reference<__type70>::type> __type71;
      typedef typename __combined<__type16,__type71>::type __type72;
      typedef typename __combined<__type72,__type35>::type __type73;
      typedef decltype(std::declval<__type73>()[std::declval<__type10>()]) __type74;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::add(std::declval<__type69>(), std::declval<__type74>()))>::type __type75;
      typedef typename __combined<__type69,__type75>::type __type76;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type56>::type>::type __type77;
      typedef container<typename std::remove_reference<__type77>::type> __type78;
      typedef typename __combined<__type51,__type78>::type __type79;
      typedef typename __combined<__type79,__type60>::type __type80;
      typedef decltype(std::declval<__type80>()[std::declval<__type48>()]) __type81;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::add(std::declval<__type76>(), std::declval<__type81>()))>::type __type82;
      typedef typename __combined<__type76,__type82>::type __type83;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type84;
      typedef decltype(pythonic::operator_::div(std::declval<__type83>(), std::declval<__type84>())) __type85;
      typedef typename pythonic::lazy<__type85>::type __type86;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type31>::type>::type __type87;
      typedef container<typename std::remove_reference<__type87>::type> __type88;
      typedef typename __combined<__type6,__type88>::type __type89;
      typedef typename __combined<__type89,__type35>::type __type90;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type56>::type>::type __type91;
      typedef container<typename std::remove_reference<__type91>::type> __type92;
      typedef typename __combined<__type45,__type92>::type __type93;
      typedef typename __combined<__type93,__type60>::type __type94;
      typedef __type0 __ptype52;
      typedef __type1 __ptype53;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type43>(), std::declval<__type68>(), std::declval<__type86>(), std::declval<__type90>(), std::declval<__type36>(), std::declval<__type94>(), std::declval<__type61>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 , typename argument_type16 , typename argument_type17 , typename argument_type18 , typename argument_type19 , typename argument_type20 , typename argument_type21 , typename argument_type22 , typename argument_type23 , typename argument_type24 , typename argument_type25 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13, argument_type14, argument_type15, argument_type16, argument_type17, argument_type18, argument_type19, argument_type20, argument_type21, argument_type22, argument_type23, argument_type24, argument_type25>::result_type operator()(argument_type0&& VE, argument_type1&& XE, argument_type2&& VI, argument_type3&& XI, argument_type4&& thetaE, argument_type5&& thetaI, argument_type6&& rhoETemp, argument_type7&& rhoITemp, argument_type8&& N_fl, argument_type9&& pN, argument_type10&& qN, argument_type11&& pN_fl, argument_type12&& qN_fl, argument_type13&& gJ, argument_type14&& P_firing_poisson, argument_type15&& weightDynType, argument_type16&& tTrans, argument_type17&& Iext, argument_type18&& mu, argument_type19&& J, argument_type20&& Gamma, argument_type21&& I, argument_type22&& p, argument_type23&& q, argument_type24&& tauTinv, argument_type25&& uT) const
    ;
  }  ;
  struct run_transient_GLNetEIRand_static
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 , typename argument_type16 , typename argument_type17 , typename argument_type18 , typename argument_type19 , typename argument_type20 , typename argument_type21 , typename argument_type22 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type1;
      typedef typename pythonic::lazy<__type0>::type __type2;
      typedef double __type3;
      typedef typename pythonic::lazy<__type3>::type __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type5;
      typedef GLNetEIRand_iter __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type7;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type8;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type __type9;
      typedef decltype(std::declval<__type8>()(std::declval<__type9>())) __type10;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type10>::type::iterator>::value_type>::type __type11;
      typedef decltype(std::declval<__type7>()[std::declval<__type11>()]) __type12;
      typedef decltype(std::declval<__type5>()[std::declval<__type11>()]) __type13;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type17>::type>::type __type14;
      typedef decltype(std::declval<__type14>()[std::declval<__type11>()]) __type15;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type12>::type>::type __type16;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type13>::type>::type __type17;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type14>::type>::type __type18;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type15>::type>::type __type19;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type16>::type>::type __type20;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type11>::type>::type __type21;
      typedef typename pythonic::assignable<decltype(std::declval<__type6>()(std::declval<__type12>(), std::declval<__type13>(), std::declval<__type15>(), std::declval<__type16>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type21>()))>::type __type22;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type22>::type>::type __type23;
      typedef container<typename std::remove_reference<__type23>::type> __type24;
      typedef typename __combined<__type5,__type24>::type __type25;
      typedef indexable<__type11> __type26;
      typedef typename __combined<__type25,__type26>::type __type27;
      typedef decltype(std::declval<__type27>()[std::declval<__type11>()]) __type28;
      typedef decltype(pythonic::operator_::add(std::declval<__type4>(), std::declval<__type28>())) __type29;
      typedef typename pythonic::lazy<__type29>::type __type30;
      typedef typename __combined<__type4,__type30>::type __type31;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type9>::type>::type __type32;
      typedef decltype(pythonic::operator_::div(std::declval<__type31>(), std::declval<__type32>())) __type33;
      typedef typename pythonic::lazy<__type33>::type __type34;
      typedef typename __combined<__type2,__type34>::type __type35;
      typedef typename pythonic::lazy<__type1>::type __type36;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type37;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type38;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type39;
      typedef decltype(std::declval<__type8>()(std::declval<__type39>())) __type40;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type40>::type::iterator>::value_type>::type __type41;
      typedef decltype(std::declval<__type38>()[std::declval<__type41>()]) __type42;
      typedef decltype(std::declval<__type37>()[std::declval<__type41>()]) __type43;
      typedef decltype(std::declval<__type14>()[std::declval<__type41>()]) __type44;
      typedef typename pythonic::assignable<decltype(std::declval<__type6>()(std::declval<__type42>(), std::declval<__type43>(), std::declval<__type44>(), std::declval<__type16>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type3>()))>::type __type45;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type45>::type>::type __type46;
      typedef container<typename std::remove_reference<__type46>::type> __type47;
      typedef typename __combined<__type37,__type47>::type __type48;
      typedef indexable<__type41> __type49;
      typedef typename __combined<__type48,__type49>::type __type50;
      typedef decltype(std::declval<__type50>()[std::declval<__type41>()]) __type51;
      typedef decltype(pythonic::operator_::add(std::declval<__type4>(), std::declval<__type51>())) __type52;
      typedef typename pythonic::lazy<__type52>::type __type53;
      typedef typename __combined<__type4,__type53>::type __type54;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type10>::type>::type __type55;
      typedef decltype(pythonic::operator_::div(std::declval<__type54>(), std::declval<__type55>())) __type56;
      typedef typename pythonic::lazy<__type56>::type __type57;
      typedef typename __combined<__type36,__type57>::type __type58;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type22>::type>::type __type59;
      typedef container<typename std::remove_reference<__type59>::type> __type60;
      typedef typename __combined<__type7,__type60>::type __type61;
      typedef typename __combined<__type61,__type26>::type __type62;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type45>::type>::type __type63;
      typedef container<typename std::remove_reference<__type63>::type> __type64;
      typedef typename __combined<__type38,__type64>::type __type65;
      typedef typename __combined<__type65,__type49>::type __type66;
      typedef __type0 __ptype82;
      typedef __type1 __ptype83;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type35>(), std::declval<__type58>(), std::declval<__type62>(), std::declval<__type27>(), std::declval<__type66>(), std::declval<__type50>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 , typename argument_type16 , typename argument_type17 , typename argument_type18 , typename argument_type19 , typename argument_type20 , typename argument_type21 , typename argument_type22 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13, argument_type14, argument_type15, argument_type16, argument_type17, argument_type18, argument_type19, argument_type20, argument_type21, argument_type22>::result_type operator()(argument_type0&& VE, argument_type1&& XE, argument_type2&& VI, argument_type3&& XI, argument_type4&& tTrans, argument_type5&& rhoETemp, argument_type6&& rhoITemp, argument_type7&& pN, argument_type8&& qN, argument_type9&& pN_fl, argument_type10&& qN_fl, argument_type11&& P_firing_poisson, argument_type12&& Iext, argument_type13&& mu, argument_type14&& theta, argument_type15&& Gamma, argument_type16&& I, argument_type17&& synapticInput, argument_type18&& J, argument_type19&& W, argument_type20&& C, argument_type21&& KE, argument_type22&& K) const
    ;
  }  ;
  struct run_transient_GLNetEIMF_adapt
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 , typename argument_type16 , typename argument_type17 , typename argument_type18 , typename argument_type19 , typename argument_type20 , typename argument_type21 , typename argument_type22 , typename argument_type23 , typename argument_type24 , typename argument_type25 , typename argument_type26 , typename argument_type27 , typename argument_type28 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<argument_type28>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type1;
      typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type>::type __type2;
      typedef double __type3;
      typedef typename pythonic::lazy<__type3>::type __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type5;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type6;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type7;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type9>::type>::type __type8;
      typedef decltype(std::declval<__type7>()(std::declval<__type8>())) __type9;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type9>::type::iterator>::value_type>::type __type10;
      typedef decltype(std::declval<__type6>()[std::declval<__type10>()]) __type11;
      typedef decltype(std::declval<__type5>()[std::declval<__type10>()]) __type12;
      typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type>::type __type13;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type16>::type>::type __type14;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type17>::type>::type __type15;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type16;
      typedef decltype(std::declval<__type16>()[std::declval<__type10>()]) __type17;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type18>::type>::type __type18;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type19>::type>::type __type19;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type20>::type>::type __type20;
      typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type28>::type>::type>::type __type21;
      typedef typename pythonic::assignable<weightAdapt_decrease>::type __type22;
      typedef typename pythonic::assignable<weightAdapt_increase>::type __type23;
      typedef typename __combined<__type22,__type23>::type __type24;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type27>::type>::type __type25;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type25>::type>::type __type26;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type26>::type>::type __type27;
      typedef typename pythonic::assignable<decltype(std::declval<__type24>()(std::declval<__type21>(), std::declval<__type25>(), std::declval<__type26>(), std::declval<__type27>(), std::declval<__type2>(), std::declval<__type13>()))>::type __type28;
      typedef typename __combined<__type21,__type28>::type __type29;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type21>::type>::type __type30;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type22>::type>::type __type31;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type23>::type>::type __type32;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type24>::type>::type __type33;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type13>::type>::type __type34;
      typedef typename GLNetEIMF_adaptthresh_iter::type<__type11, __type12, __type2, __type13, __type14, __type15, __type17, __type18, __type19, __type20, __type29, __type30, __type31, __type32, __type33, __type34>::__ptype10 __type35;
      typedef container<typename std::remove_reference<__type35>::type> __type36;
      typedef typename __combined<__type5,__type36>::type __type37;
      typedef GLNetEIMF_adaptthresh_iter __type38;
      typedef typename pythonic::assignable<decltype(std::declval<__type38>()(std::declval<__type11>(), std::declval<__type12>(), std::declval<__type2>(), std::declval<__type13>(), std::declval<__type14>(), std::declval<__type15>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type29>(), std::declval<__type30>(), std::declval<__type31>(), std::declval<__type32>(), std::declval<__type33>(), std::declval<__type34>()))>::type __type39;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type39>::type>::type __type40;
      typedef container<typename std::remove_reference<__type40>::type> __type41;
      typedef typename __combined<__type37,__type41>::type __type42;
      typedef indexable<__type10> __type43;
      typedef typename __combined<__type42,__type43>::type __type44;
      typedef decltype(std::declval<__type44>()[std::declval<__type10>()]) __type45;
      typedef decltype(pythonic::operator_::add(std::declval<__type4>(), std::declval<__type45>())) __type46;
      typedef typename pythonic::lazy<__type46>::type __type47;
      typedef typename __combined<__type4,__type47>::type __type48;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type11>::type>::type __type49;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type48>(), std::declval<__type49>()))>::type __type50;
      typedef typename __combined<__type2,__type50>::type __type51;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type52;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type53;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type10>::type>::type __type54;
      typedef decltype(std::declval<__type7>()(std::declval<__type54>())) __type55;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type55>::type::iterator>::value_type>::type __type56;
      typedef decltype(std::declval<__type53>()[std::declval<__type56>()]) __type57;
      typedef decltype(std::declval<__type52>()[std::declval<__type56>()]) __type58;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type59;
      typedef decltype(std::declval<__type59>()[std::declval<__type56>()]) __type60;
      typedef typename GLNetEIMF_adaptthresh_iter::type<__type57, __type58, __type2, __type13, __type14, __type15, __type60, __type18, __type19, __type20, __type29, __type30, __type31, __type32, __type33, __type3>::__ptype10 __type61;
      typedef container<typename std::remove_reference<__type61>::type> __type62;
      typedef typename __combined<__type52,__type62>::type __type63;
      typedef typename pythonic::assignable<decltype(std::declval<__type38>()(std::declval<__type57>(), std::declval<__type58>(), std::declval<__type2>(), std::declval<__type13>(), std::declval<__type14>(), std::declval<__type15>(), std::declval<__type60>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type29>(), std::declval<__type30>(), std::declval<__type31>(), std::declval<__type32>(), std::declval<__type33>(), std::declval<__type3>()))>::type __type64;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type64>::type>::type __type65;
      typedef container<typename std::remove_reference<__type65>::type> __type66;
      typedef typename __combined<__type63,__type66>::type __type67;
      typedef indexable<__type56> __type68;
      typedef typename __combined<__type67,__type68>::type __type69;
      typedef decltype(std::declval<__type69>()[std::declval<__type56>()]) __type70;
      typedef decltype(pythonic::operator_::add(std::declval<__type4>(), std::declval<__type70>())) __type71;
      typedef typename pythonic::lazy<__type71>::type __type72;
      typedef typename __combined<__type4,__type72>::type __type73;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type12>::type>::type __type74;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type73>(), std::declval<__type74>()))>::type __type75;
      typedef typename __combined<__type13,__type75>::type __type76;
      typedef typename pythonic::assignable<double>::type __type77;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type39>::type>::type __type78;
      typedef container<typename std::remove_reference<__type78>::type> __type79;
      typedef typename __combined<__type16,__type79>::type __type80;
      typedef typename __combined<__type80,__type43>::type __type81;
      typedef decltype(std::declval<__type81>()[std::declval<__type10>()]) __type82;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::add(std::declval<__type77>(), std::declval<__type82>()))>::type __type83;
      typedef typename __combined<__type77,__type83>::type __type84;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type64>::type>::type __type85;
      typedef container<typename std::remove_reference<__type85>::type> __type86;
      typedef typename __combined<__type59,__type86>::type __type87;
      typedef typename __combined<__type87,__type68>::type __type88;
      typedef decltype(std::declval<__type88>()[std::declval<__type56>()]) __type89;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::add(std::declval<__type84>(), std::declval<__type89>()))>::type __type90;
      typedef typename __combined<__type84,__type90>::type __type91;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type92;
      typedef decltype(pythonic::operator_::div(std::declval<__type91>(), std::declval<__type92>())) __type93;
      typedef typename pythonic::lazy<__type93>::type __type94;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type39>::type>::type __type95;
      typedef container<typename std::remove_reference<__type95>::type> __type96;
      typedef typename __combined<__type6,__type96>::type __type97;
      typedef typename __combined<__type97,__type43>::type __type98;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type64>::type>::type __type99;
      typedef container<typename std::remove_reference<__type99>::type> __type100;
      typedef typename __combined<__type53,__type100>::type __type101;
      typedef typename __combined<__type101,__type68>::type __type102;
      typedef __type0 __ptype104;
      typedef __type1 __ptype105;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type51>(), std::declval<__type76>(), std::declval<__type94>(), std::declval<__type29>(), std::declval<__type98>(), std::declval<__type44>(), std::declval<__type102>(), std::declval<__type69>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 , typename argument_type16 , typename argument_type17 , typename argument_type18 , typename argument_type19 , typename argument_type20 , typename argument_type21 , typename argument_type22 , typename argument_type23 , typename argument_type24 , typename argument_type25 , typename argument_type26 , typename argument_type27 , typename argument_type28 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13, argument_type14, argument_type15, argument_type16, argument_type17, argument_type18, argument_type19, argument_type20, argument_type21, argument_type22, argument_type23, argument_type24, argument_type25, argument_type26, argument_type27, argument_type28>::result_type operator()(argument_type0&& VE, argument_type1&& XE, argument_type2&& VI, argument_type3&& XI, argument_type4&& thetaE, argument_type5&& thetaI, argument_type6&& rhoETemp, argument_type7&& rhoITemp, argument_type8&& N_fl, argument_type9&& pN, argument_type10&& qN, argument_type11&& pN_fl, argument_type12&& qN_fl, argument_type13&& P_firing_poisson, argument_type14&& weightDynType, argument_type15&& tTrans, argument_type16&& Iext, argument_type17&& mu, argument_type18&& J, argument_type19&& Gamma, argument_type20&& I, argument_type21&& p, argument_type22&& q, argument_type23&& tauTinv, argument_type24&& uT, argument_type25&& tauWinv, argument_type26&& uW, argument_type27&& A, argument_type28&& W_I) const
    ;
  }  ;
  struct set_MF_network_IC
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::array{})>::type>::type __type0;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::map{})>::type>::type __type1;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::functools::functor::partial{})>::type>::type __type2;
      typedef set_MF_network_IC_lambda16 __type3;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type4;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type5;
      typedef decltype(std::declval<__type2>()(std::declval<__type3>(), std::declval<__type4>(), std::declval<__type5>())) __type6;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type7;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type8;
      typedef decltype(std::declval<__type7>()(std::declval<__type8>())) __type9;
      typedef decltype(std::declval<__type1>()(std::declval<__type6>(), std::declval<__type9>())) __type10;
      typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type10>()))>::type __type11;
      typedef generate_IC_spikes __type12;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type13;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::int_{})>::type>::type __type14;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type9>::type>::type __type15;
      typedef decltype(pythonic::operator_::mul(std::declval<__type15>(), std::declval<__type8>())) __type16;
      typedef decltype(std::declval<__type14>()(std::declval<__type16>())) __type17;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type10>::type>::type __type18;
      typedef typename pythonic::assignable<decltype(std::declval<__type12>()(std::declval<__type13>(), std::declval<__type8>(), std::declval<__type17>(), std::declval<__type18>()))>::type __type19;
      typedef set_MF_network_IC_lambda18 __type20;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type21;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type __type22;
      typedef decltype(std::declval<__type2>()(std::declval<__type20>(), std::declval<__type21>(), std::declval<__type22>())) __type23;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type24;
      typedef decltype(std::declval<__type7>()(std::declval<__type24>())) __type25;
      typedef decltype(std::declval<__type1>()(std::declval<__type23>(), std::declval<__type25>())) __type26;
      typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type26>()))>::type __type27;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type11>::type>::type __type28;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type12>::type>::type __type29;
      typedef decltype(pythonic::operator_::mul(std::declval<__type29>(), std::declval<__type24>())) __type30;
      typedef decltype(std::declval<__type14>()(std::declval<__type30>())) __type31;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type13>::type>::type __type32;
      typedef typename pythonic::assignable<decltype(std::declval<__type12>()(std::declval<__type28>(), std::declval<__type24>(), std::declval<__type31>(), std::declval<__type32>()))>::type __type33;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type34;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::sum{})>::type>::type __type35;
      typedef decltype(std::declval<__type35>()(std::declval<__type19>())) __type36;
      typedef decltype(std::declval<__type34>()(std::declval<__type36>())) __type37;
      typedef decltype(std::declval<__type34>()(std::declval<__type8>())) __type38;
      typedef double __type39;
      typedef typename __combined<__type38,__type39>::type __type40;
      typedef decltype(pythonic::operator_::div(std::declval<__type37>(), std::declval<__type40>())) __type41;
      typedef decltype(std::declval<__type35>()(std::declval<__type33>())) __type42;
      typedef decltype(std::declval<__type34>()(std::declval<__type42>())) __type43;
      typedef decltype(std::declval<__type34>()(std::declval<__type24>())) __type44;
      typedef typename __combined<__type44,__type39>::type __type45;
      typedef decltype(pythonic::operator_::div(std::declval<__type43>(), std::declval<__type45>())) __type46;
      typedef set_MF_network_IC_lambda17 __type47;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type14>::type>::type __type48;
      typedef decltype(std::declval<__type2>()(std::declval<__type47>(), std::declval<__type48>())) __type49;
      typedef decltype(std::declval<__type1>()(std::declval<__type49>(), std::declval<__type9>())) __type50;
      typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type50>()))>::type __type51;
      typedef set_MF_network_IC_lambda19 __type52;
      typedef decltype(std::declval<__type2>()(std::declval<__type52>(), std::declval<__type48>())) __type53;
      typedef decltype(std::declval<__type1>()(std::declval<__type53>(), std::declval<__type25>())) __type54;
      typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type54>()))>::type __type55;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type56;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type57;
      typedef decltype(pythonic::operator_::mul(std::declval<__type56>(), std::declval<__type57>())) __type58;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type11>(), std::declval<__type19>(), std::declval<__type27>(), std::declval<__type33>(), std::declval<__type41>(), std::declval<__type46>(), std::declval<__type51>(), std::declval<__type55>(), std::declval<__type58>(), std::declval<__type48>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 >
    typename type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13, argument_type14>::result_type operator()(argument_type0&& pN, argument_type1&& qN, argument_type2&& g, argument_type3&& J, argument_type4&& VE0, argument_type5&& VE0Std, argument_type6&& VI0, argument_type7&& VI0Std, argument_type8&& XE0, argument_type9&& fXE0, argument_type10&& XE0Rand, argument_type11&& XI0, argument_type12&& fXI0, argument_type13&& XI0Rand, argument_type14&& theta) const
    ;
  }  ;
  struct RunSimulation_GLNetEIMF_adaptthresh
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::array{})>::type>::type __type0;
      typedef double __type1;
      typedef pythonic::types::list<typename std::remove_reference<__type1>::type> __type2;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::max{})>::type>::type __type3;
      typedef long __type4;
      typedef get_system_parameters __type5;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type7;
      typedef typename pythonic::assignable<decltype(std::declval<__type5>()(std::declval<__type6>(), std::declval<__type7>()))>::type __type8;
      typedef set_MF_network_IC __type9;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::int_{})>::type>::type __type10;
      typedef typename pythonic::assignable<typename std::tuple_element<20,typename std::remove_reference<__type8>::type>::type>::type __type11;
      typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type8>::type>::type>::type __type12;
      typedef decltype(pythonic::operator_::mul(std::declval<__type11>(), std::declval<__type12>())) __type13;
      typedef typename pythonic::assignable<decltype(std::declval<__type10>()(std::declval<__type13>()))>::type __type14;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type12>(), std::declval<__type14>()))>::type __type15;
      typedef typename pythonic::assignable<typename std::tuple_element<19,typename std::remove_reference<__type8>::type>::type>::type __type16;
      typedef typename pythonic::assignable<typename std::tuple_element<15,typename std::remove_reference<__type8>::type>::type>::type __type17;
      typedef typename std::tuple_element<3,typename std::remove_reference<__type8>::type>::type __type18;
      typedef typename std::tuple_element<4,typename std::remove_reference<__type8>::type>::type __type19;
      typedef typename std::tuple_element<5,typename std::remove_reference<__type8>::type>::type __type20;
      typedef typename std::tuple_element<6,typename std::remove_reference<__type8>::type>::type __type21;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type22;
      typedef typename std::tuple_element<7,typename std::remove_reference<__type8>::type>::type __type23;
      typedef decltype(std::declval<__type22>()(std::declval<__type23>())) __type24;
      typedef typename std::tuple_element<8,typename std::remove_reference<__type8>::type>::type __type25;
      typedef typename std::tuple_element<9,typename std::remove_reference<__type8>::type>::type __type26;
      typedef typename std::tuple_element<10,typename std::remove_reference<__type8>::type>::type __type27;
      typedef decltype(std::declval<__type22>()(std::declval<__type27>())) __type28;
      typedef typename std::tuple_element<11,typename std::remove_reference<__type8>::type>::type __type29;
      typedef typename std::tuple_element<12,typename std::remove_reference<__type8>::type>::type __type30;
      typedef typename std::tuple_element<14,typename std::remove_reference<__type8>::type>::type __type31;
      typedef typename pythonic::assignable<decltype(std::declval<__type9>()(std::declval<__type14>(), std::declval<__type15>(), std::declval<__type16>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type24>(), std::declval<__type25>(), std::declval<__type26>(), std::declval<__type28>(), std::declval<__type29>(), std::declval<__type30>(), std::declval<__type31>()))>::type __type32;
      typedef typename std::tuple_element<9,typename std::remove_reference<__type32>::type>::type __type33;
      typedef container<typename std::remove_reference<__type33>::type> __type34;
      typedef typename __combined<__type8,__type34>::type __type35;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type35>::type>::type __type36;
      typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type8>::type>::type>::type __type37;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type36>(), std::declval<__type37>()))>::type __type38;
      typedef typename __combined<__type4,__type38>::type __type39;
      typedef decltype(std::declval<__type3>()(std::declval<__type39>(), std::declval<__type38>())) __type40;
      typedef decltype(pythonic::operator_::mul(std::declval<__type2>(), std::declval<__type40>())) __type41;
      typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type41>()))>::type __type42;
      typedef indexable<__type4> __type43;
      typedef typename __combined<__type42,__type43>::type __type44;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type45;
      typedef decltype(std::declval<__type45>()(std::declval<__type4>(), std::declval<__type38>())) __type46;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type46>::type::iterator>::value_type>::type __type47;
      typedef indexable<__type47> __type48;
      typedef typename __combined<__type44,__type48>::type __type49;
      typedef typename std::tuple_element<4,typename std::remove_reference<__type32>::type>::type __type50;
      typedef typename pythonic::lazy<__type50>::type __type51;
      typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type32>::type>::type>::type __type52;
      typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type32>::type>::type>::type __type53;
      typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type32>::type>::type>::type __type54;
      typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type32>::type>::type>::type __type55;
      typedef typename pythonic::assignable<typename std::tuple_element<6,typename std::remove_reference<__type32>::type>::type>::type __type56;
      typedef typename pythonic::assignable<typename std::tuple_element<7,typename std::remove_reference<__type32>::type>::type>::type __type57;
      typedef typename std::tuple_element<5,typename std::remove_reference<__type32>::type>::type __type58;
      typedef typename pythonic::lazy<__type58>::type __type59;
      typedef typename pythonic::assignable<decltype(std::declval<__type22>()(std::declval<__type12>()))>::type __type60;
      typedef decltype(std::declval<__type22>()(std::declval<__type14>())) __type61;
      typedef typename pythonic::assignable<typename __combined<__type61,__type1>::type>::type __type62;
      typedef decltype(std::declval<__type22>()(std::declval<__type15>())) __type63;
      typedef typename pythonic::assignable<typename __combined<__type63,__type1>::type>::type __type64;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::mul(std::declval<__type16>(), std::declval<__type17>()))>::type __type65;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::exp{})>::type>::type __type66;
      typedef typename std::tuple_element<30,typename std::remove_reference<__type8>::type>::type __type67;
      typedef decltype(pythonic::operator_::neg(std::declval<__type67>())) __type68;
      typedef decltype(std::declval<__type66>()(std::declval<__type68>())) __type69;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type1>(), std::declval<__type69>()))>::type __type70;
      typedef typename std::tuple_element<29,typename std::remove_reference<__type35>::type>::type __type71;
      typedef typename pythonic::assignable<typename std::tuple_element<18,typename std::remove_reference<__type8>::type>::type>::type __type72;
      typedef typename pythonic::assignable<typename std::tuple_element<13,typename std::remove_reference<__type8>::type>::type>::type __type73;
      typedef typename pythonic::assignable<typename std::tuple_element<16,typename std::remove_reference<__type8>::type>::type>::type __type74;
      typedef typename pythonic::assignable<typename std::tuple_element<17,typename std::remove_reference<__type8>::type>::type>::type __type75;
      typedef typename pythonic::assignable<typename std::tuple_element<21,typename std::remove_reference<__type8>::type>::type>::type __type76;
      typedef typename std::tuple_element<25,typename std::remove_reference<__type8>::type>::type __type77;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type1>(), std::declval<__type77>()))>::type __type78;
      typedef typename pythonic::assignable<typename std::tuple_element<26,typename std::remove_reference<__type8>::type>::type>::type __type79;
      typedef typename run_transient_GLNetEIMF_adaptthresh::type<__type52, __type53, __type54, __type55, __type56, __type57, __type51, __type59, __type60, __type14, __type15, __type62, __type64, __type65, __type70, __type71, __type37, __type72, __type73, __type17, __type74, __type75, __type11, __type76, __type78, __type79>::__ptype52 __type80;
      typedef typename __combined<__type51,__type80>::type __type81;
      typedef run_transient_GLNetEIMF_adaptthresh __type82;
      typedef typename run_transient_GLNetEIMF_adaptthresh::type<__type52, __type53, __type54, __type55, __type56, __type57, __type81, __type59, __type60, __type14, __type15, __type62, __type64, __type65, __type70, __type71, __type37, __type72, __type73, __type17, __type74, __type75, __type11, __type76, __type78, __type79>::__ptype53 __type83;
      typedef typename __combined<__type59,__type83>::type __type84;
      typedef typename pythonic::assignable<decltype(std::declval<__type82>()(std::declval<__type52>(), std::declval<__type53>(), std::declval<__type54>(), std::declval<__type55>(), std::declval<__type56>(), std::declval<__type57>(), std::declval<__type81>(), std::declval<__type84>(), std::declval<__type60>(), std::declval<__type14>(), std::declval<__type15>(), std::declval<__type62>(), std::declval<__type64>(), std::declval<__type65>(), std::declval<__type70>(), std::declval<__type71>(), std::declval<__type37>(), std::declval<__type72>(), std::declval<__type73>(), std::declval<__type17>(), std::declval<__type74>(), std::declval<__type75>(), std::declval<__type11>(), std::declval<__type76>(), std::declval<__type78>(), std::declval<__type79>()))>::type __type85;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type85>::type>::type __type86;
      typedef typename pythonic::lazy<__type86>::type __type87;
      typedef typename __combined<__type81,__type87>::type __type88;
      typedef container<typename std::remove_reference<__type88>::type> __type89;
      typedef typename __combined<__type49,__type89>::type __type90;
      typedef typename __combined<__type44,__type89>::type __type91;
      typedef decltype(std::declval<__type91>()[std::declval<__type47>()]) __type92;
      typedef typename std::tuple_element<4,typename std::remove_reference<__type85>::type>::type __type93;
      typedef typename __combined<__type53,__type93>::type __type94;
      typedef decltype(std::declval<__type45>()(std::declval<__type14>())) __type95;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type95>::type::iterator>::value_type>::type __type96;
      typedef indexable<__type96> __type97;
      typedef typename __combined<__type94,__type97>::type __type98;
      typedef typename pythonic::assignable<typename std::tuple_element<4,typename std::remove_reference<__type85>::type>::type>::type __type99;
      typedef typename __combined<__type99,__type97>::type __type100;
      typedef typename __combined<__type98,__type100>::type __type101;
      typedef typename std::tuple_element<3,typename std::remove_reference<__type85>::type>::type __type102;
      typedef typename __combined<__type52,__type102>::type __type103;
      typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type85>::type>::type>::type __type104;
      typedef typename __combined<__type103,__type104>::type __type105;
      typedef decltype(std::declval<__type105>()[std::declval<__type96>()]) __type106;
      typedef typename __combined<__type94,__type99>::type __type107;
      typedef decltype(std::declval<__type107>()[std::declval<__type96>()]) __type108;
      typedef decltype(pythonic::operator_::sub(std::declval<__type47>(), std::declval<__type4>())) __type109;
      typedef decltype(std::declval<__type91>()[std::declval<__type109>()]) __type110;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type85>::type>::type __type111;
      typedef typename pythonic::lazy<__type111>::type __type112;
      typedef typename __combined<__type84,__type112>::type __type113;
      typedef container<typename std::remove_reference<__type113>::type> __type114;
      typedef typename __combined<__type44,__type114>::type __type115;
      typedef decltype(std::declval<__type115>()[std::declval<__type109>()]) __type116;
      typedef decltype(std::declval<__type56>()[std::declval<__type96>()]) __type117;
      typedef typename GLNetEIMF_adaptthresh_iter::type<__type106, __type108, __type110, __type116, __type72, __type73, __type117, __type17, __type74, __type75, __type65, __type11, __type76, __type78, __type79, __type70>::__ptype10 __type118;
      typedef container<typename std::remove_reference<__type118>::type> __type119;
      typedef typename __combined<__type101,__type119>::type __type120;
      typedef GLNetEIMF_adaptthresh_iter __type121;
      typedef typename pythonic::assignable<decltype(std::declval<__type121>()(std::declval<__type106>(), std::declval<__type108>(), std::declval<__type110>(), std::declval<__type116>(), std::declval<__type72>(), std::declval<__type73>(), std::declval<__type117>(), std::declval<__type17>(), std::declval<__type74>(), std::declval<__type75>(), std::declval<__type65>(), std::declval<__type11>(), std::declval<__type76>(), std::declval<__type78>(), std::declval<__type79>(), std::declval<__type70>()))>::type __type122;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type122>::type>::type __type123;
      typedef container<typename std::remove_reference<__type123>::type> __type124;
      typedef typename __combined<__type120,__type124>::type __type125;
      typedef decltype(std::declval<__type125>()[std::declval<__type96>()]) __type126;
      typedef decltype(pythonic::operator_::add(std::declval<__type92>(), std::declval<__type126>())) __type127;
      typedef container<typename std::remove_reference<__type127>::type> __type128;
      typedef typename __combined<__type90,__type128>::type __type129;
      typedef decltype(std::declval<__type129>()[std::declval<__type47>()]) __type130;
      typedef decltype(pythonic::operator_::div(std::declval<__type130>(), std::declval<__type62>())) __type131;
      typedef container<typename std::remove_reference<__type131>::type> __type132;
      typedef typename __combined<__type129,__type132>::type __type133;
      typedef typename __combined<__type49,__type114>::type __type134;
      typedef decltype(std::declval<__type115>()[std::declval<__type47>()]) __type135;
      typedef typename std::tuple_element<6,typename std::remove_reference<__type85>::type>::type __type136;
      typedef typename __combined<__type55,__type136>::type __type137;
      typedef decltype(std::declval<__type45>()(std::declval<__type15>())) __type138;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type138>::type::iterator>::value_type>::type __type139;
      typedef indexable<__type139> __type140;
      typedef typename __combined<__type137,__type140>::type __type141;
      typedef typename pythonic::assignable<typename std::tuple_element<6,typename std::remove_reference<__type85>::type>::type>::type __type142;
      typedef typename __combined<__type142,__type140>::type __type143;
      typedef typename __combined<__type141,__type143>::type __type144;
      typedef typename std::tuple_element<5,typename std::remove_reference<__type85>::type>::type __type145;
      typedef typename __combined<__type54,__type145>::type __type146;
      typedef typename pythonic::assignable<typename std::tuple_element<5,typename std::remove_reference<__type85>::type>::type>::type __type147;
      typedef typename __combined<__type146,__type147>::type __type148;
      typedef decltype(std::declval<__type148>()[std::declval<__type139>()]) __type149;
      typedef typename __combined<__type137,__type142>::type __type150;
      typedef decltype(std::declval<__type150>()[std::declval<__type139>()]) __type151;
      typedef decltype(std::declval<__type129>()[std::declval<__type109>()]) __type152;
      typedef decltype(std::declval<__type57>()[std::declval<__type139>()]) __type153;
      typedef typename GLNetEIMF_adaptthresh_iter::type<__type149, __type151, __type152, __type116, __type72, __type73, __type153, __type17, __type74, __type75, __type65, __type11, __type76, __type78, __type79, __type1>::__ptype10 __type154;
      typedef container<typename std::remove_reference<__type154>::type> __type155;
      typedef typename __combined<__type144,__type155>::type __type156;
      typedef typename pythonic::assignable<decltype(std::declval<__type121>()(std::declval<__type149>(), std::declval<__type151>(), std::declval<__type152>(), std::declval<__type116>(), std::declval<__type72>(), std::declval<__type73>(), std::declval<__type153>(), std::declval<__type17>(), std::declval<__type74>(), std::declval<__type75>(), std::declval<__type65>(), std::declval<__type11>(), std::declval<__type76>(), std::declval<__type78>(), std::declval<__type79>(), std::declval<__type1>()))>::type __type157;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type157>::type>::type __type158;
      typedef container<typename std::remove_reference<__type158>::type> __type159;
      typedef typename __combined<__type156,__type159>::type __type160;
      typedef decltype(std::declval<__type160>()[std::declval<__type139>()]) __type161;
      typedef decltype(pythonic::operator_::add(std::declval<__type135>(), std::declval<__type161>())) __type162;
      typedef container<typename std::remove_reference<__type162>::type> __type163;
      typedef typename __combined<__type134,__type163>::type __type164;
      typedef decltype(std::declval<__type164>()[std::declval<__type47>()]) __type165;
      typedef decltype(pythonic::operator_::div(std::declval<__type165>(), std::declval<__type64>())) __type166;
      typedef container<typename std::remove_reference<__type166>::type> __type167;
      typedef typename __combined<__type164,__type167>::type __type168;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type4>(), std::declval<__type4>())) __type169;
      typedef typename pythonic::assignable<pythonic::types::list<typename std::remove_reference<__type169>::type>>::type __type170;
      typedef save_initial_spkdata __type171;
      typedef typename pythonic::assignable<typename std::tuple_element<28,typename std::remove_reference<__type8>::type>::type>::type __type172;
      typedef decltype(pythonic::operator_::mul(std::declval<__type11>(), std::declval<__type172>())) __type173;
      typedef typename pythonic::assignable<decltype(std::declval<__type10>()(std::declval<__type173>()))>::type __type174;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type172>(), std::declval<__type174>()))>::type __type175;
      typedef typename pythonic::assignable<decltype(std::declval<__type171>()(std::declval<__type107>(), std::declval<__type150>(), std::declval<__type174>(), std::declval<__type175>()))>::type __type176;
      typedef typename __combined<__type170,__type176>::type __type177;
      typedef typename save_spk_data::type<__type177, __type47, __type96>::__ptype0 __type178;
      typedef pythonic::types::list<typename std::remove_reference<__type178>::type> __type179;
      typedef typename __combined<__type170,__type179>::type __type180;
      typedef typename __combined<__type177,__type179>::type __type181;
      typedef typename save_spk_data::type<__type181, __type47, __type96>::__ptype1 __type182;
      typedef pythonic::types::list<typename std::remove_reference<__type182>::type> __type183;
      typedef typename __combined<__type180,__type183>::type __type184;
      typedef typename pythonic::assignable<save_spk_data_fake>::type __type185;
      typedef typename pythonic::assignable<save_spk_data>::type __type186;
      typedef typename __combined<__type185,__type186>::type __type187;
      typedef typename __combined<__type181,__type183>::type __type188;
      typedef decltype(std::declval<__type187>()(std::declval<__type188>(), std::declval<__type47>(), std::declval<__type96>())) __type189;
      typedef typename __combined<__type184,__type189>::type __type190;
      typedef typename __combined<__type176,__type179>::type __type191;
      typedef typename __combined<__type191,__type183>::type __type192;
      typedef typename __combined<__type192,__type189>::type __type193;
      typedef typename __combined<__type190,__type193>::type __type194;
      typedef typename __combined<__type194,__type188>::type __type195;
      typedef typename __combined<__type179,__type183>::type __type196;
      typedef typename pythonic::assignable<typename __combined<__type196,__type189>::type>::type __type197;
      typedef typename __combined<__type195,__type197>::type __type198;
      typedef typename __combined<__type196,__type189>::type __type199;
      typedef typename __combined<__type198,__type199>::type __type200;
      typedef decltype(pythonic::operator_::add(std::declval<__type139>(), std::declval<__type174>())) __type201;
      typedef typename save_spk_data::type<__type200, __type47, __type201>::__ptype0 __type202;
      typedef pythonic::types::list<typename std::remove_reference<__type202>::type> __type203;
      typedef typename __combined<__type190,__type203>::type __type204;
      typedef typename __combined<__type200,__type203>::type __type205;
      typedef typename save_spk_data::type<__type205, __type47, __type201>::__ptype1 __type206;
      typedef pythonic::types::list<typename std::remove_reference<__type206>::type> __type207;
      typedef typename __combined<__type204,__type207>::type __type208;
      typedef typename __combined<__type205,__type207>::type __type209;
      typedef decltype(std::declval<__type187>()(std::declval<__type209>(), std::declval<__type47>(), std::declval<__type201>())) __type210;
      typedef typename __combined<__type208,__type210>::type __type211;
      typedef typename __combined<__type193,__type203>::type __type212;
      typedef typename __combined<__type212,__type207>::type __type213;
      typedef typename __combined<__type213,__type210>::type __type214;
      typedef typename __combined<__type211,__type214>::type __type215;
      typedef typename __combined<__type215,__type188>::type __type216;
      typedef typename __combined<__type197,__type203>::type __type217;
      typedef typename __combined<__type217,__type207>::type __type218;
      typedef typename __combined<__type218,__type210>::type __type219;
      typedef typename __combined<__type216,__type219>::type __type220;
      typedef typename __combined<__type199,__type203>::type __type221;
      typedef typename __combined<__type221,__type207>::type __type222;
      typedef typename pythonic::assignable<typename __combined<__type222,__type210>::type>::type __type223;
      typedef typename __combined<__type220,__type223>::type __type224;
      typedef typename __combined<__type224,__type209>::type __type225;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::multiply{})>::type>::type __type226;
      typedef decltype(pythonic::operator_::mul(std::declval<__type11>(), std::declval<__type17>())) __type227;
      typedef decltype(std::declval<__type226>()(std::declval<__type227>(), std::declval<__type133>())) __type228;
      typedef decltype(pythonic::operator_::mul(std::declval<__type76>(), std::declval<__type16>())) __type229;
      typedef decltype(pythonic::operator_::mul(std::declval<__type229>(), std::declval<__type17>())) __type230;
      typedef decltype(std::declval<__type226>()(std::declval<__type230>(), std::declval<__type168>())) __type231;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::map{})>::type>::type __type232;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::functools::functor::partial{})>::type>::type __type233;
      typedef RunSimulation_GLNetEIMF_adaptthresh_lambda6 __type234;
      typedef decltype(std::declval<__type233>()(std::declval<__type234>(), std::declval<__type16>())) __type235;
      typedef decltype(std::declval<__type232>()(std::declval<__type235>(), std::declval<__type133>())) __type236;
      typedef decltype(std::declval<__type0>()(std::declval<__type236>())) __type237;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::divide{})>::type>::type __type238;
      typedef typename pythonic::lazy<__type33>::type __type239;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type85>::type>::type __type240;
      typedef typename pythonic::lazy<__type240>::type __type241;
      typedef typename __combined<__type239,__type241>::type __type242;
      typedef container<typename std::remove_reference<__type242>::type> __type243;
      typedef typename __combined<__type49,__type243>::type __type244;
      typedef typename pythonic::assignable<double>::type __type245;
      typedef typename __combined<__type56,__type97>::type __type246;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type122>::type>::type __type247;
      typedef container<typename std::remove_reference<__type247>::type> __type248;
      typedef typename __combined<__type246,__type248>::type __type249;
      typedef decltype(std::declval<__type249>()[std::declval<__type96>()]) __type250;
      typedef decltype(pythonic::operator_::add(std::declval<__type245>(), std::declval<__type250>())) __type251;
      typedef typename __combined<__type245,__type251>::type __type252;
      typedef typename __combined<__type57,__type140>::type __type253;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type157>::type>::type __type254;
      typedef container<typename std::remove_reference<__type254>::type> __type255;
      typedef typename __combined<__type253,__type255>::type __type256;
      typedef decltype(std::declval<__type256>()[std::declval<__type139>()]) __type257;
      typedef decltype(pythonic::operator_::add(std::declval<__type252>(), std::declval<__type257>())) __type258;
      typedef typename __combined<__type252,__type258>::type __type259;
      typedef typename __combined<__type259,__type250>::type __type260;
      typedef typename __combined<__type260,__type257>::type __type261;
      typedef decltype(pythonic::operator_::div(std::declval<__type261>(), std::declval<__type60>())) __type262;
      typedef container<typename std::remove_reference<__type262>::type> __type263;
      typedef typename __combined<__type244,__type263>::type __type264;
      typedef decltype(std::declval<__type238>()(std::declval<__type75>(), std::declval<__type264>())) __type265;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type133>(), std::declval<__type168>(), std::declval<__type225>(), std::declval<__type228>(), std::declval<__type231>(), std::declval<__type237>(), std::declval<__type265>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& simParam_dict, argument_type1&& paramType_dict) const
    ;
  }  ;
  struct RunSimulation_GLNetEIMF_static
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::array{})>::type>::type __type0;
      typedef double __type1;
      typedef pythonic::types::list<typename std::remove_reference<__type1>::type> __type2;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::max{})>::type>::type __type3;
      typedef long __type4;
      typedef get_system_parameters __type5;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type7;
      typedef typename pythonic::assignable<decltype(std::declval<__type5>()(std::declval<__type6>(), std::declval<__type7>()))>::type __type8;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type8>::type>::type __type9;
      typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type8>::type>::type>::type __type10;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type9>(), std::declval<__type10>()))>::type __type11;
      typedef typename __combined<__type4,__type11>::type __type12;
      typedef decltype(std::declval<__type3>()(std::declval<__type12>(), std::declval<__type11>())) __type13;
      typedef decltype(pythonic::operator_::mul(std::declval<__type2>(), std::declval<__type13>())) __type14;
      typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type14>()))>::type __type15;
      typedef indexable<__type4> __type16;
      typedef typename __combined<__type15,__type16>::type __type17;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type18;
      typedef decltype(std::declval<__type18>()(std::declval<__type4>(), std::declval<__type11>())) __type19;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type19>::type::iterator>::value_type>::type __type20;
      typedef indexable<__type20> __type21;
      typedef typename __combined<__type17,__type21>::type __type22;
      typedef set_MF_network_IC __type23;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::int_{})>::type>::type __type24;
      typedef typename pythonic::assignable<typename std::tuple_element<20,typename std::remove_reference<__type8>::type>::type>::type __type25;
      typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type8>::type>::type>::type __type26;
      typedef decltype(pythonic::operator_::mul(std::declval<__type25>(), std::declval<__type26>())) __type27;
      typedef typename pythonic::assignable<decltype(std::declval<__type24>()(std::declval<__type27>()))>::type __type28;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type26>(), std::declval<__type28>()))>::type __type29;
      typedef typename pythonic::assignable<typename std::tuple_element<19,typename std::remove_reference<__type8>::type>::type>::type __type30;
      typedef typename pythonic::assignable<typename std::tuple_element<15,typename std::remove_reference<__type8>::type>::type>::type __type31;
      typedef typename std::tuple_element<3,typename std::remove_reference<__type8>::type>::type __type32;
      typedef typename std::tuple_element<4,typename std::remove_reference<__type8>::type>::type __type33;
      typedef typename std::tuple_element<5,typename std::remove_reference<__type8>::type>::type __type34;
      typedef typename std::tuple_element<6,typename std::remove_reference<__type8>::type>::type __type35;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type36;
      typedef typename std::tuple_element<7,typename std::remove_reference<__type8>::type>::type __type37;
      typedef decltype(std::declval<__type36>()(std::declval<__type37>())) __type38;
      typedef typename std::tuple_element<8,typename std::remove_reference<__type8>::type>::type __type39;
      typedef typename std::tuple_element<9,typename std::remove_reference<__type8>::type>::type __type40;
      typedef typename std::tuple_element<10,typename std::remove_reference<__type8>::type>::type __type41;
      typedef decltype(std::declval<__type36>()(std::declval<__type41>())) __type42;
      typedef typename std::tuple_element<11,typename std::remove_reference<__type8>::type>::type __type43;
      typedef typename std::tuple_element<12,typename std::remove_reference<__type8>::type>::type __type44;
      typedef typename pythonic::assignable<typename std::tuple_element<14,typename std::remove_reference<__type8>::type>::type>::type __type45;
      typedef typename pythonic::assignable<decltype(std::declval<__type23>()(std::declval<__type28>(), std::declval<__type29>(), std::declval<__type30>(), std::declval<__type31>(), std::declval<__type32>(), std::declval<__type33>(), std::declval<__type34>(), std::declval<__type35>(), std::declval<__type38>(), std::declval<__type39>(), std::declval<__type40>(), std::declval<__type42>(), std::declval<__type43>(), std::declval<__type44>(), std::declval<__type45>()))>::type __type46;
      typedef typename std::tuple_element<4,typename std::remove_reference<__type46>::type>::type __type47;
      typedef typename pythonic::lazy<__type47>::type __type48;
      typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type46>::type>::type>::type __type49;
      typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type46>::type>::type>::type __type50;
      typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type46>::type>::type>::type __type51;
      typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type46>::type>::type>::type __type52;
      typedef typename std::tuple_element<5,typename std::remove_reference<__type46>::type>::type __type53;
      typedef typename pythonic::lazy<__type53>::type __type54;
      typedef decltype(std::declval<__type36>()(std::declval<__type28>())) __type55;
      typedef typename pythonic::assignable<typename __combined<__type55,__type1>::type>::type __type56;
      typedef decltype(std::declval<__type36>()(std::declval<__type29>())) __type57;
      typedef typename pythonic::assignable<typename __combined<__type57,__type1>::type>::type __type58;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::exp{})>::type>::type __type59;
      typedef typename std::tuple_element<30,typename std::remove_reference<__type8>::type>::type __type60;
      typedef decltype(pythonic::operator_::neg(std::declval<__type60>())) __type61;
      typedef decltype(std::declval<__type59>()(std::declval<__type61>())) __type62;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type1>(), std::declval<__type62>()))>::type __type63;
      typedef typename pythonic::assignable<typename std::tuple_element<18,typename std::remove_reference<__type8>::type>::type>::type __type64;
      typedef typename pythonic::assignable<typename std::tuple_element<13,typename std::remove_reference<__type8>::type>::type>::type __type65;
      typedef typename pythonic::assignable<typename std::tuple_element<16,typename std::remove_reference<__type8>::type>::type>::type __type66;
      typedef typename pythonic::assignable<typename std::tuple_element<17,typename std::remove_reference<__type8>::type>::type>::type __type67;
      typedef typename pythonic::assignable<typename std::tuple_element<21,typename std::remove_reference<__type8>::type>::type>::type __type68;
      typedef typename run_transient_GLNetEIMF_static::type<__type49, __type50, __type51, __type52, __type48, __type54, __type28, __type29, __type56, __type58, __type63, __type10, __type64, __type65, __type45, __type31, __type66, __type67, __type30, __type25, __type68>::__ptype12 __type69;
      typedef typename __combined<__type48,__type69>::type __type70;
      typedef run_transient_GLNetEIMF_static __type71;
      typedef typename run_transient_GLNetEIMF_static::type<__type49, __type50, __type51, __type52, __type70, __type54, __type28, __type29, __type56, __type58, __type63, __type10, __type64, __type65, __type45, __type31, __type66, __type67, __type30, __type25, __type68>::__ptype13 __type72;
      typedef typename __combined<__type54,__type72>::type __type73;
      typedef typename pythonic::assignable<decltype(std::declval<__type71>()(std::declval<__type49>(), std::declval<__type50>(), std::declval<__type51>(), std::declval<__type52>(), std::declval<__type70>(), std::declval<__type73>(), std::declval<__type28>(), std::declval<__type29>(), std::declval<__type56>(), std::declval<__type58>(), std::declval<__type63>(), std::declval<__type10>(), std::declval<__type64>(), std::declval<__type65>(), std::declval<__type45>(), std::declval<__type31>(), std::declval<__type66>(), std::declval<__type67>(), std::declval<__type30>(), std::declval<__type25>(), std::declval<__type68>()))>::type __type74;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type74>::type>::type __type75;
      typedef typename pythonic::lazy<__type75>::type __type76;
      typedef typename __combined<__type70,__type76>::type __type77;
      typedef container<typename std::remove_reference<__type77>::type> __type78;
      typedef typename __combined<__type22,__type78>::type __type79;
      typedef typename __combined<__type17,__type78>::type __type80;
      typedef decltype(std::declval<__type80>()[std::declval<__type20>()]) __type81;
      typedef typename std::tuple_element<3,typename std::remove_reference<__type74>::type>::type __type82;
      typedef typename __combined<__type50,__type82>::type __type83;
      typedef decltype(std::declval<__type18>()(std::declval<__type28>())) __type84;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type84>::type::iterator>::value_type>::type __type85;
      typedef indexable<__type85> __type86;
      typedef typename __combined<__type83,__type86>::type __type87;
      typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type74>::type>::type>::type __type88;
      typedef typename __combined<__type88,__type86>::type __type89;
      typedef typename __combined<__type87,__type89>::type __type90;
      typedef GLNetEIMF_iter __type91;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type74>::type>::type __type92;
      typedef typename __combined<__type49,__type92>::type __type93;
      typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type74>::type>::type>::type __type94;
      typedef typename __combined<__type93,__type94>::type __type95;
      typedef decltype(std::declval<__type95>()[std::declval<__type85>()]) __type96;
      typedef typename __combined<__type83,__type88>::type __type97;
      typedef decltype(std::declval<__type97>()[std::declval<__type85>()]) __type98;
      typedef decltype(pythonic::operator_::sub(std::declval<__type20>(), std::declval<__type4>())) __type99;
      typedef decltype(std::declval<__type80>()[std::declval<__type99>()]) __type100;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type74>::type>::type __type101;
      typedef typename pythonic::lazy<__type101>::type __type102;
      typedef typename __combined<__type73,__type102>::type __type103;
      typedef container<typename std::remove_reference<__type103>::type> __type104;
      typedef typename __combined<__type17,__type104>::type __type105;
      typedef decltype(std::declval<__type105>()[std::declval<__type99>()]) __type106;
      typedef typename pythonic::assignable<decltype(std::declval<__type91>()(std::declval<__type96>(), std::declval<__type98>(), std::declval<__type100>(), std::declval<__type106>(), std::declval<__type64>(), std::declval<__type65>(), std::declval<__type45>(), std::declval<__type31>(), std::declval<__type66>(), std::declval<__type67>(), std::declval<__type30>(), std::declval<__type25>(), std::declval<__type68>(), std::declval<__type63>()))>::type __type107;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type107>::type>::type __type108;
      typedef container<typename std::remove_reference<__type108>::type> __type109;
      typedef typename __combined<__type90,__type109>::type __type110;
      typedef decltype(std::declval<__type110>()[std::declval<__type85>()]) __type111;
      typedef decltype(pythonic::operator_::add(std::declval<__type81>(), std::declval<__type111>())) __type112;
      typedef container<typename std::remove_reference<__type112>::type> __type113;
      typedef typename __combined<__type79,__type113>::type __type114;
      typedef decltype(std::declval<__type114>()[std::declval<__type20>()]) __type115;
      typedef decltype(pythonic::operator_::div(std::declval<__type115>(), std::declval<__type56>())) __type116;
      typedef container<typename std::remove_reference<__type116>::type> __type117;
      typedef typename __combined<__type114,__type117>::type __type118;
      typedef typename __combined<__type22,__type104>::type __type119;
      typedef decltype(std::declval<__type105>()[std::declval<__type20>()]) __type120;
      typedef typename std::tuple_element<5,typename std::remove_reference<__type74>::type>::type __type121;
      typedef typename __combined<__type52,__type121>::type __type122;
      typedef decltype(std::declval<__type18>()(std::declval<__type29>())) __type123;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type123>::type::iterator>::value_type>::type __type124;
      typedef indexable<__type124> __type125;
      typedef typename __combined<__type122,__type125>::type __type126;
      typedef typename pythonic::assignable<typename std::tuple_element<5,typename std::remove_reference<__type74>::type>::type>::type __type127;
      typedef typename __combined<__type127,__type125>::type __type128;
      typedef typename __combined<__type126,__type128>::type __type129;
      typedef typename std::tuple_element<4,typename std::remove_reference<__type74>::type>::type __type130;
      typedef typename __combined<__type51,__type130>::type __type131;
      typedef typename pythonic::assignable<typename std::tuple_element<4,typename std::remove_reference<__type74>::type>::type>::type __type132;
      typedef typename __combined<__type131,__type132>::type __type133;
      typedef decltype(std::declval<__type133>()[std::declval<__type124>()]) __type134;
      typedef typename __combined<__type122,__type127>::type __type135;
      typedef decltype(std::declval<__type135>()[std::declval<__type124>()]) __type136;
      typedef decltype(std::declval<__type114>()[std::declval<__type99>()]) __type137;
      typedef typename pythonic::assignable<decltype(std::declval<__type91>()(std::declval<__type134>(), std::declval<__type136>(), std::declval<__type137>(), std::declval<__type106>(), std::declval<__type64>(), std::declval<__type65>(), std::declval<__type45>(), std::declval<__type31>(), std::declval<__type66>(), std::declval<__type67>(), std::declval<__type30>(), std::declval<__type25>(), std::declval<__type68>(), std::declval<__type1>()))>::type __type138;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type138>::type>::type __type139;
      typedef container<typename std::remove_reference<__type139>::type> __type140;
      typedef typename __combined<__type129,__type140>::type __type141;
      typedef decltype(std::declval<__type141>()[std::declval<__type124>()]) __type142;
      typedef decltype(pythonic::operator_::add(std::declval<__type120>(), std::declval<__type142>())) __type143;
      typedef container<typename std::remove_reference<__type143>::type> __type144;
      typedef typename __combined<__type119,__type144>::type __type145;
      typedef decltype(std::declval<__type145>()[std::declval<__type20>()]) __type146;
      typedef decltype(pythonic::operator_::div(std::declval<__type146>(), std::declval<__type58>())) __type147;
      typedef container<typename std::remove_reference<__type147>::type> __type148;
      typedef typename __combined<__type145,__type148>::type __type149;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type4>(), std::declval<__type4>())) __type150;
      typedef typename pythonic::assignable<pythonic::types::list<typename std::remove_reference<__type150>::type>>::type __type151;
      typedef save_initial_spkdata __type152;
      typedef typename pythonic::assignable<typename std::tuple_element<28,typename std::remove_reference<__type8>::type>::type>::type __type153;
      typedef decltype(pythonic::operator_::mul(std::declval<__type25>(), std::declval<__type153>())) __type154;
      typedef typename pythonic::assignable<decltype(std::declval<__type24>()(std::declval<__type154>()))>::type __type155;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type153>(), std::declval<__type155>()))>::type __type156;
      typedef typename pythonic::assignable<decltype(std::declval<__type152>()(std::declval<__type97>(), std::declval<__type135>(), std::declval<__type155>(), std::declval<__type156>()))>::type __type157;
      typedef typename __combined<__type151,__type157>::type __type158;
      typedef typename save_spk_data::type<__type158, __type20, __type85>::__ptype0 __type159;
      typedef pythonic::types::list<typename std::remove_reference<__type159>::type> __type160;
      typedef typename __combined<__type151,__type160>::type __type161;
      typedef typename __combined<__type158,__type160>::type __type162;
      typedef typename save_spk_data::type<__type162, __type20, __type85>::__ptype1 __type163;
      typedef pythonic::types::list<typename std::remove_reference<__type163>::type> __type164;
      typedef typename __combined<__type161,__type164>::type __type165;
      typedef typename pythonic::assignable<save_spk_data_fake>::type __type166;
      typedef typename pythonic::assignable<save_spk_data>::type __type167;
      typedef typename __combined<__type166,__type167>::type __type168;
      typedef typename __combined<__type162,__type164>::type __type169;
      typedef decltype(std::declval<__type168>()(std::declval<__type169>(), std::declval<__type20>(), std::declval<__type85>())) __type170;
      typedef typename __combined<__type165,__type170>::type __type171;
      typedef typename __combined<__type157,__type160>::type __type172;
      typedef typename __combined<__type172,__type164>::type __type173;
      typedef typename __combined<__type173,__type170>::type __type174;
      typedef typename __combined<__type171,__type174>::type __type175;
      typedef typename __combined<__type175,__type169>::type __type176;
      typedef typename __combined<__type160,__type164>::type __type177;
      typedef typename __combined<__type177,__type170>::type __type178;
      typedef typename __combined<__type176,__type178>::type __type179;
      typedef typename pythonic::assignable<typename __combined<__type177,__type170>::type>::type __type180;
      typedef typename __combined<__type179,__type180>::type __type181;
      typedef decltype(pythonic::operator_::add(std::declval<__type124>(), std::declval<__type155>())) __type182;
      typedef typename save_spk_data::type<__type181, __type20, __type182>::__ptype0 __type183;
      typedef pythonic::types::list<typename std::remove_reference<__type183>::type> __type184;
      typedef typename __combined<__type171,__type184>::type __type185;
      typedef typename __combined<__type181,__type184>::type __type186;
      typedef typename save_spk_data::type<__type186, __type20, __type182>::__ptype1 __type187;
      typedef pythonic::types::list<typename std::remove_reference<__type187>::type> __type188;
      typedef typename __combined<__type185,__type188>::type __type189;
      typedef typename __combined<__type186,__type188>::type __type190;
      typedef decltype(std::declval<__type168>()(std::declval<__type190>(), std::declval<__type20>(), std::declval<__type182>())) __type191;
      typedef typename __combined<__type189,__type191>::type __type192;
      typedef typename __combined<__type174,__type184>::type __type193;
      typedef typename __combined<__type193,__type188>::type __type194;
      typedef typename __combined<__type194,__type191>::type __type195;
      typedef typename __combined<__type192,__type195>::type __type196;
      typedef typename __combined<__type196,__type169>::type __type197;
      typedef typename __combined<__type178,__type184>::type __type198;
      typedef typename __combined<__type198,__type188>::type __type199;
      typedef typename pythonic::assignable<typename __combined<__type199,__type191>::type>::type __type200;
      typedef typename __combined<__type197,__type200>::type __type201;
      typedef typename __combined<__type180,__type184>::type __type202;
      typedef typename __combined<__type202,__type188>::type __type203;
      typedef typename __combined<__type203,__type191>::type __type204;
      typedef typename __combined<__type201,__type204>::type __type205;
      typedef typename __combined<__type205,__type190>::type __type206;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::multiply{})>::type>::type __type207;
      typedef decltype(pythonic::operator_::mul(std::declval<__type25>(), std::declval<__type31>())) __type208;
      typedef decltype(std::declval<__type207>()(std::declval<__type208>(), std::declval<__type118>())) __type209;
      typedef decltype(pythonic::operator_::mul(std::declval<__type68>(), std::declval<__type30>())) __type210;
      typedef decltype(pythonic::operator_::mul(std::declval<__type210>(), std::declval<__type31>())) __type211;
      typedef decltype(std::declval<__type207>()(std::declval<__type211>(), std::declval<__type149>())) __type212;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::map{})>::type>::type __type213;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::functools::functor::partial{})>::type>::type __type214;
      typedef RunSimulation_GLNetEIMF_static_lambda13 __type215;
      typedef decltype(std::declval<__type214>()(std::declval<__type215>(), std::declval<__type30>())) __type216;
      typedef decltype(std::declval<__type213>()(std::declval<__type216>(), std::declval<__type118>())) __type217;
      typedef decltype(std::declval<__type0>()(std::declval<__type217>())) __type218;
      typedef RunSimulation_GLNetEIMF_static_lambda14 __type219;
      typedef decltype(std::declval<__type214>()(std::declval<__type219>(), std::declval<__type67>(), std::declval<__type45>())) __type220;
      typedef decltype(std::declval<__type213>()(std::declval<__type220>(), std::declval<__type118>())) __type221;
      typedef decltype(std::declval<__type0>()(std::declval<__type221>())) __type222;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type118>(), std::declval<__type149>(), std::declval<__type206>(), std::declval<__type209>(), std::declval<__type212>(), std::declval<__type218>(), std::declval<__type222>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& simParam_dict, argument_type1&& paramType_dict) const
    ;
  }  ;
  struct RunSimulation_GLNetEIMF_aval
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::array{})>::type>::type __type0;
      typedef double __type1;
      typedef pythonic::types::list<typename std::remove_reference<__type1>::type> __type2;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::max{})>::type>::type __type3;
      typedef long __type4;
      typedef get_system_parameters __type5;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type7;
      typedef typename pythonic::assignable<decltype(std::declval<__type5>()(std::declval<__type6>(), std::declval<__type7>()))>::type __type8;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type8>::type>::type __type9;
      typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type8>::type>::type>::type __type10;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type9>(), std::declval<__type10>()))>::type __type11;
      typedef typename __combined<__type4,__type11>::type __type12;
      typedef decltype(std::declval<__type3>()(std::declval<__type12>(), std::declval<__type11>())) __type13;
      typedef decltype(pythonic::operator_::mul(std::declval<__type2>(), std::declval<__type13>())) __type14;
      typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type14>()))>::type __type15;
      typedef indexable<__type4> __type16;
      typedef typename __combined<__type15,__type16>::type __type17;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type18;
      typedef decltype(std::declval<__type18>()(std::declval<__type4>(), std::declval<__type11>())) __type19;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type19>::type::iterator>::value_type>::type __type20;
      typedef indexable<__type20> __type21;
      typedef typename __combined<__type17,__type21>::type __type22;
      typedef set_MF_network_IC __type23;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::int_{})>::type>::type __type24;
      typedef typename pythonic::assignable<typename std::tuple_element<20,typename std::remove_reference<__type8>::type>::type>::type __type25;
      typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type8>::type>::type>::type __type26;
      typedef decltype(pythonic::operator_::mul(std::declval<__type25>(), std::declval<__type26>())) __type27;
      typedef typename pythonic::assignable<decltype(std::declval<__type24>()(std::declval<__type27>()))>::type __type28;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type26>(), std::declval<__type28>()))>::type __type29;
      typedef typename pythonic::assignable<typename std::tuple_element<19,typename std::remove_reference<__type8>::type>::type>::type __type30;
      typedef typename pythonic::assignable<typename std::tuple_element<15,typename std::remove_reference<__type8>::type>::type>::type __type31;
      typedef typename std::tuple_element<3,typename std::remove_reference<__type8>::type>::type __type32;
      typedef typename std::tuple_element<4,typename std::remove_reference<__type8>::type>::type __type33;
      typedef typename std::tuple_element<5,typename std::remove_reference<__type8>::type>::type __type34;
      typedef typename std::tuple_element<6,typename std::remove_reference<__type8>::type>::type __type35;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type36;
      typedef typename std::tuple_element<7,typename std::remove_reference<__type8>::type>::type __type37;
      typedef decltype(std::declval<__type36>()(std::declval<__type37>())) __type38;
      typedef typename std::tuple_element<8,typename std::remove_reference<__type8>::type>::type __type39;
      typedef typename std::tuple_element<9,typename std::remove_reference<__type8>::type>::type __type40;
      typedef typename std::tuple_element<10,typename std::remove_reference<__type8>::type>::type __type41;
      typedef decltype(std::declval<__type36>()(std::declval<__type41>())) __type42;
      typedef typename std::tuple_element<11,typename std::remove_reference<__type8>::type>::type __type43;
      typedef typename std::tuple_element<12,typename std::remove_reference<__type8>::type>::type __type44;
      typedef typename pythonic::assignable<typename std::tuple_element<14,typename std::remove_reference<__type8>::type>::type>::type __type45;
      typedef typename pythonic::assignable<decltype(std::declval<__type23>()(std::declval<__type28>(), std::declval<__type29>(), std::declval<__type30>(), std::declval<__type31>(), std::declval<__type32>(), std::declval<__type33>(), std::declval<__type34>(), std::declval<__type35>(), std::declval<__type38>(), std::declval<__type39>(), std::declval<__type40>(), std::declval<__type42>(), std::declval<__type43>(), std::declval<__type44>(), std::declval<__type45>()))>::type __type46;
      typedef typename pythonic::assignable<typename std::tuple_element<4,typename std::remove_reference<__type46>::type>::type>::type __type47;
      typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type46>::type>::type>::type __type48;
      typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type46>::type>::type>::type __type49;
      typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type46>::type>::type>::type __type50;
      typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type46>::type>::type>::type __type51;
      typedef typename pythonic::assignable<typename std::tuple_element<5,typename std::remove_reference<__type46>::type>::type>::type __type52;
      typedef decltype(std::declval<__type36>()(std::declval<__type28>())) __type53;
      typedef typename pythonic::assignable<typename __combined<__type53,__type1>::type>::type __type54;
      typedef decltype(std::declval<__type36>()(std::declval<__type29>())) __type55;
      typedef typename pythonic::assignable<typename __combined<__type55,__type1>::type>::type __type56;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::exp{})>::type>::type __type57;
      typedef typename std::tuple_element<30,typename std::remove_reference<__type8>::type>::type __type58;
      typedef decltype(pythonic::operator_::neg(std::declval<__type58>())) __type59;
      typedef decltype(std::declval<__type57>()(std::declval<__type59>())) __type60;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type1>(), std::declval<__type60>()))>::type __type61;
      typedef typename pythonic::assignable<typename std::tuple_element<18,typename std::remove_reference<__type8>::type>::type>::type __type62;
      typedef typename pythonic::assignable<typename std::tuple_element<13,typename std::remove_reference<__type8>::type>::type>::type __type63;
      typedef typename pythonic::assignable<typename std::tuple_element<16,typename std::remove_reference<__type8>::type>::type>::type __type64;
      typedef typename pythonic::assignable<typename std::tuple_element<17,typename std::remove_reference<__type8>::type>::type>::type __type65;
      typedef typename pythonic::assignable<typename std::tuple_element<21,typename std::remove_reference<__type8>::type>::type>::type __type66;
      typedef typename run_transient_GLNetEIMF_aval::type<__type48, __type49, __type50, __type51, __type47, __type52, __type28, __type29, __type54, __type56, __type61, __type10, __type62, __type63, __type45, __type31, __type64, __type65, __type30, __type25, __type66>::__ptype30 __type67;
      typedef typename __combined<__type47,__type67>::type __type68;
      typedef run_transient_GLNetEIMF_aval __type69;
      typedef typename run_transient_GLNetEIMF_aval::type<__type48, __type49, __type50, __type51, __type68, __type52, __type28, __type29, __type54, __type56, __type61, __type10, __type62, __type63, __type45, __type31, __type64, __type65, __type30, __type25, __type66>::__ptype31 __type70;
      typedef typename __combined<__type52,__type70>::type __type71;
      typedef typename pythonic::assignable<decltype(std::declval<__type69>()(std::declval<__type48>(), std::declval<__type49>(), std::declval<__type50>(), std::declval<__type51>(), std::declval<__type68>(), std::declval<__type71>(), std::declval<__type28>(), std::declval<__type29>(), std::declval<__type54>(), std::declval<__type56>(), std::declval<__type61>(), std::declval<__type10>(), std::declval<__type62>(), std::declval<__type63>(), std::declval<__type45>(), std::declval<__type31>(), std::declval<__type64>(), std::declval<__type65>(), std::declval<__type30>(), std::declval<__type25>(), std::declval<__type66>()))>::type __type72;
      typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type72>::type>::type>::type __type73;
      typedef typename __combined<__type68,__type73>::type __type74;
      typedef container<typename std::remove_reference<__type74>::type> __type75;
      typedef typename __combined<__type22,__type75>::type __type76;
      typedef typename std::tuple_element<3,typename std::remove_reference<__type72>::type>::type __type77;
      typedef typename __combined<__type49,__type77>::type __type78;
      typedef typename __combined<__type78,__type16>::type __type79;
      typedef decltype(std::declval<__type18>()(std::declval<__type28>())) __type80;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type80>::type::iterator>::value_type>::type __type81;
      typedef indexable<__type81> __type82;
      typedef typename __combined<__type79,__type82>::type __type83;
      typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type72>::type>::type>::type __type84;
      typedef typename __combined<__type84,__type16>::type __type85;
      typedef typename __combined<__type85,__type82>::type __type86;
      typedef typename __combined<__type83,__type86>::type __type87;
      typedef container<typename std::remove_reference<__type4>::type> __type88;
      typedef typename __combined<__type87,__type88>::type __type89;
      typedef GLNetEIMF_iter __type90;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type72>::type>::type __type91;
      typedef typename __combined<__type48,__type91>::type __type92;
      typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type72>::type>::type>::type __type93;
      typedef typename __combined<__type92,__type93>::type __type94;
      typedef decltype(std::declval<__type94>()[std::declval<__type81>()]) __type95;
      typedef typename __combined<__type79,__type85>::type __type96;
      typedef typename __combined<__type96,__type88>::type __type97;
      typedef decltype(std::declval<__type97>()[std::declval<__type81>()]) __type98;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type1>(), std::declval<__type54>()))>::type __type99;
      typedef typename __combined<__type74,__type99>::type __type100;
      typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type72>::type>::type>::type __type101;
      typedef typename __combined<__type71,__type101>::type __type102;
      typedef typename pythonic::assignable<decltype(std::declval<__type90>()(std::declval<__type95>(), std::declval<__type98>(), std::declval<__type100>(), std::declval<__type102>(), std::declval<__type62>(), std::declval<__type63>(), std::declval<__type45>(), std::declval<__type31>(), std::declval<__type64>(), std::declval<__type65>(), std::declval<__type30>(), std::declval<__type25>(), std::declval<__type66>(), std::declval<__type61>()))>::type __type103;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type103>::type>::type __type104;
      typedef container<typename std::remove_reference<__type104>::type> __type105;
      typedef typename __combined<__type89,__type105>::type __type106;
      typedef decltype(std::declval<__type106>()[std::declval<__type81>()]) __type107;
      typedef container<typename std::remove_reference<__type107>::type> __type108;
      typedef typename __combined<__type76,__type108>::type __type109;
      typedef decltype(std::declval<__type109>()[std::declval<__type20>()]) __type110;
      typedef decltype(pythonic::operator_::div(std::declval<__type110>(), std::declval<__type54>())) __type111;
      typedef container<typename std::remove_reference<__type111>::type> __type112;
      typedef typename __combined<__type109,__type112>::type __type113;
      typedef container<typename std::remove_reference<__type102>::type> __type114;
      typedef typename __combined<__type22,__type114>::type __type115;
      typedef typename std::tuple_element<5,typename std::remove_reference<__type72>::type>::type __type116;
      typedef typename __combined<__type51,__type116>::type __type117;
      typedef decltype(std::declval<__type18>()(std::declval<__type29>())) __type118;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type118>::type::iterator>::value_type>::type __type119;
      typedef indexable<__type119> __type120;
      typedef typename __combined<__type117,__type120>::type __type121;
      typedef typename pythonic::assignable<typename std::tuple_element<5,typename std::remove_reference<__type72>::type>::type>::type __type122;
      typedef typename __combined<__type122,__type120>::type __type123;
      typedef typename __combined<__type121,__type123>::type __type124;
      typedef typename std::tuple_element<4,typename std::remove_reference<__type72>::type>::type __type125;
      typedef typename __combined<__type50,__type125>::type __type126;
      typedef typename pythonic::assignable<typename std::tuple_element<4,typename std::remove_reference<__type72>::type>::type>::type __type127;
      typedef typename __combined<__type126,__type127>::type __type128;
      typedef decltype(std::declval<__type128>()[std::declval<__type119>()]) __type129;
      typedef typename __combined<__type117,__type122>::type __type130;
      typedef decltype(std::declval<__type130>()[std::declval<__type119>()]) __type131;
      typedef typename pythonic::assignable<decltype(std::declval<__type90>()(std::declval<__type129>(), std::declval<__type131>(), std::declval<__type100>(), std::declval<__type102>(), std::declval<__type62>(), std::declval<__type63>(), std::declval<__type45>(), std::declval<__type31>(), std::declval<__type64>(), std::declval<__type65>(), std::declval<__type30>(), std::declval<__type25>(), std::declval<__type66>(), std::declval<__type1>()))>::type __type132;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type132>::type>::type __type133;
      typedef container<typename std::remove_reference<__type133>::type> __type134;
      typedef typename __combined<__type124,__type134>::type __type135;
      typedef decltype(std::declval<__type135>()[std::declval<__type119>()]) __type136;
      typedef container<typename std::remove_reference<__type136>::type> __type137;
      typedef typename __combined<__type115,__type137>::type __type138;
      typedef decltype(std::declval<__type138>()[std::declval<__type20>()]) __type139;
      typedef decltype(pythonic::operator_::div(std::declval<__type139>(), std::declval<__type56>())) __type140;
      typedef container<typename std::remove_reference<__type140>::type> __type141;
      typedef typename __combined<__type138,__type141>::type __type142;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type4>(), std::declval<__type4>())) __type143;
      typedef typename pythonic::assignable<pythonic::types::list<typename std::remove_reference<__type143>::type>>::type __type144;
      typedef save_initial_spkdata __type145;
      typedef typename __combined<__type78,__type84>::type __type146;
      typedef typename pythonic::assignable<typename std::tuple_element<28,typename std::remove_reference<__type8>::type>::type>::type __type147;
      typedef decltype(pythonic::operator_::mul(std::declval<__type25>(), std::declval<__type147>())) __type148;
      typedef typename pythonic::assignable<decltype(std::declval<__type24>()(std::declval<__type148>()))>::type __type149;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type147>(), std::declval<__type149>()))>::type __type150;
      typedef typename pythonic::assignable<decltype(std::declval<__type145>()(std::declval<__type146>(), std::declval<__type130>(), std::declval<__type149>(), std::declval<__type150>()))>::type __type151;
      typedef typename __combined<__type144,__type151>::type __type152;
      typedef typename save_spk_data::type<__type152, __type20, __type81>::__ptype0 __type153;
      typedef pythonic::types::list<typename std::remove_reference<__type153>::type> __type154;
      typedef typename __combined<__type144,__type154>::type __type155;
      typedef typename __combined<__type152,__type154>::type __type156;
      typedef typename save_spk_data::type<__type156, __type20, __type81>::__ptype1 __type157;
      typedef pythonic::types::list<typename std::remove_reference<__type157>::type> __type158;
      typedef typename __combined<__type155,__type158>::type __type159;
      typedef typename pythonic::assignable<save_spk_data_fake>::type __type160;
      typedef typename pythonic::assignable<save_spk_data>::type __type161;
      typedef typename __combined<__type160,__type161>::type __type162;
      typedef typename __combined<__type156,__type158>::type __type163;
      typedef decltype(std::declval<__type162>()(std::declval<__type163>(), std::declval<__type20>(), std::declval<__type81>())) __type164;
      typedef typename __combined<__type159,__type164>::type __type165;
      typedef typename __combined<__type151,__type154>::type __type166;
      typedef typename __combined<__type166,__type158>::type __type167;
      typedef typename __combined<__type167,__type164>::type __type168;
      typedef typename __combined<__type165,__type168>::type __type169;
      typedef typename __combined<__type169,__type163>::type __type170;
      typedef typename __combined<__type154,__type158>::type __type171;
      typedef typename pythonic::assignable<typename __combined<__type171,__type164>::type>::type __type172;
      typedef typename __combined<__type170,__type172>::type __type173;
      typedef typename __combined<__type171,__type164>::type __type174;
      typedef typename __combined<__type173,__type174>::type __type175;
      typedef decltype(pythonic::operator_::add(std::declval<__type119>(), std::declval<__type149>())) __type176;
      typedef typename save_spk_data::type<__type175, __type20, __type176>::__ptype0 __type177;
      typedef pythonic::types::list<typename std::remove_reference<__type177>::type> __type178;
      typedef typename __combined<__type165,__type178>::type __type179;
      typedef typename __combined<__type175,__type178>::type __type180;
      typedef typename save_spk_data::type<__type180, __type20, __type176>::__ptype1 __type181;
      typedef pythonic::types::list<typename std::remove_reference<__type181>::type> __type182;
      typedef typename __combined<__type179,__type182>::type __type183;
      typedef typename __combined<__type180,__type182>::type __type184;
      typedef decltype(std::declval<__type162>()(std::declval<__type184>(), std::declval<__type20>(), std::declval<__type176>())) __type185;
      typedef typename __combined<__type183,__type185>::type __type186;
      typedef typename __combined<__type168,__type178>::type __type187;
      typedef typename __combined<__type187,__type182>::type __type188;
      typedef typename __combined<__type188,__type185>::type __type189;
      typedef typename __combined<__type186,__type189>::type __type190;
      typedef typename __combined<__type190,__type163>::type __type191;
      typedef typename __combined<__type172,__type178>::type __type192;
      typedef typename __combined<__type192,__type182>::type __type193;
      typedef typename __combined<__type193,__type185>::type __type194;
      typedef typename __combined<__type191,__type194>::type __type195;
      typedef typename __combined<__type174,__type178>::type __type196;
      typedef typename __combined<__type196,__type182>::type __type197;
      typedef typename pythonic::assignable<typename __combined<__type197,__type185>::type>::type __type198;
      typedef typename __combined<__type195,__type198>::type __type199;
      typedef typename __combined<__type199,__type184>::type __type200;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::multiply{})>::type>::type __type201;
      typedef decltype(pythonic::operator_::mul(std::declval<__type25>(), std::declval<__type31>())) __type202;
      typedef decltype(std::declval<__type201>()(std::declval<__type202>(), std::declval<__type113>())) __type203;
      typedef decltype(pythonic::operator_::mul(std::declval<__type66>(), std::declval<__type30>())) __type204;
      typedef decltype(pythonic::operator_::mul(std::declval<__type204>(), std::declval<__type31>())) __type205;
      typedef decltype(std::declval<__type201>()(std::declval<__type205>(), std::declval<__type142>())) __type206;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::map{})>::type>::type __type207;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::functools::functor::partial{})>::type>::type __type208;
      typedef RunSimulation_GLNetEIMF_aval_lambda8 __type209;
      typedef decltype(std::declval<__type208>()(std::declval<__type209>(), std::declval<__type30>())) __type210;
      typedef decltype(std::declval<__type207>()(std::declval<__type210>(), std::declval<__type113>())) __type211;
      typedef decltype(std::declval<__type0>()(std::declval<__type211>())) __type212;
      typedef RunSimulation_GLNetEIMF_aval_lambda9 __type213;
      typedef decltype(std::declval<__type208>()(std::declval<__type213>(), std::declval<__type65>(), std::declval<__type45>())) __type214;
      typedef decltype(std::declval<__type207>()(std::declval<__type214>(), std::declval<__type113>())) __type215;
      typedef decltype(std::declval<__type0>()(std::declval<__type215>())) __type216;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type113>(), std::declval<__type142>(), std::declval<__type200>(), std::declval<__type203>(), std::declval<__type206>(), std::declval<__type212>(), std::declval<__type216>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& simParam_dict, argument_type1&& paramType_dict) const
    ;
  }  ;
  struct RunSimulation_GLNetEIMF_adapt
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::array{})>::type>::type __type0;
      typedef double __type1;
      typedef pythonic::types::list<typename std::remove_reference<__type1>::type> __type2;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::max{})>::type>::type __type3;
      typedef long __type4;
      typedef get_system_parameters __type5;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type7;
      typedef typename pythonic::assignable<decltype(std::declval<__type5>()(std::declval<__type6>(), std::declval<__type7>()))>::type __type8;
      typedef set_MF_network_IC __type9;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::int_{})>::type>::type __type10;
      typedef typename pythonic::assignable<typename std::tuple_element<20,typename std::remove_reference<__type8>::type>::type>::type __type11;
      typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type8>::type>::type>::type __type12;
      typedef decltype(pythonic::operator_::mul(std::declval<__type11>(), std::declval<__type12>())) __type13;
      typedef typename pythonic::assignable<decltype(std::declval<__type10>()(std::declval<__type13>()))>::type __type14;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type12>(), std::declval<__type14>()))>::type __type15;
      typedef typename std::tuple_element<19,typename std::remove_reference<__type8>::type>::type __type16;
      typedef typename pythonic::assignable<typename std::tuple_element<15,typename std::remove_reference<__type8>::type>::type>::type __type17;
      typedef typename std::tuple_element<3,typename std::remove_reference<__type8>::type>::type __type18;
      typedef typename std::tuple_element<4,typename std::remove_reference<__type8>::type>::type __type19;
      typedef typename std::tuple_element<5,typename std::remove_reference<__type8>::type>::type __type20;
      typedef typename std::tuple_element<6,typename std::remove_reference<__type8>::type>::type __type21;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type22;
      typedef typename std::tuple_element<7,typename std::remove_reference<__type8>::type>::type __type23;
      typedef decltype(std::declval<__type22>()(std::declval<__type23>())) __type24;
      typedef typename std::tuple_element<8,typename std::remove_reference<__type8>::type>::type __type25;
      typedef typename std::tuple_element<9,typename std::remove_reference<__type8>::type>::type __type26;
      typedef typename std::tuple_element<10,typename std::remove_reference<__type8>::type>::type __type27;
      typedef decltype(std::declval<__type22>()(std::declval<__type27>())) __type28;
      typedef typename std::tuple_element<11,typename std::remove_reference<__type8>::type>::type __type29;
      typedef typename std::tuple_element<12,typename std::remove_reference<__type8>::type>::type __type30;
      typedef typename std::tuple_element<14,typename std::remove_reference<__type8>::type>::type __type31;
      typedef typename pythonic::assignable<decltype(std::declval<__type9>()(std::declval<__type14>(), std::declval<__type15>(), std::declval<__type16>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type24>(), std::declval<__type25>(), std::declval<__type26>(), std::declval<__type28>(), std::declval<__type29>(), std::declval<__type30>(), std::declval<__type31>()))>::type __type32;
      typedef typename std::tuple_element<9,typename std::remove_reference<__type32>::type>::type __type33;
      typedef container<typename std::remove_reference<__type33>::type> __type34;
      typedef typename __combined<__type8,__type34>::type __type35;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type35>::type>::type __type36;
      typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type8>::type>::type>::type __type37;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type36>(), std::declval<__type37>()))>::type __type38;
      typedef typename __combined<__type4,__type38>::type __type39;
      typedef decltype(std::declval<__type3>()(std::declval<__type39>(), std::declval<__type38>())) __type40;
      typedef decltype(pythonic::operator_::mul(std::declval<__type2>(), std::declval<__type40>())) __type41;
      typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type41>()))>::type __type42;
      typedef indexable<__type4> __type43;
      typedef typename __combined<__type42,__type43>::type __type44;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type45;
      typedef decltype(std::declval<__type45>()(std::declval<__type4>(), std::declval<__type38>())) __type46;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type46>::type::iterator>::value_type>::type __type47;
      typedef indexable<__type47> __type48;
      typedef typename __combined<__type44,__type48>::type __type49;
      typedef typename std::tuple_element<4,typename std::remove_reference<__type32>::type>::type __type50;
      typedef typename pythonic::lazy<__type50>::type __type51;
      typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type32>::type>::type>::type __type52;
      typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type32>::type>::type>::type __type53;
      typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type32>::type>::type>::type __type54;
      typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type32>::type>::type>::type __type55;
      typedef typename pythonic::assignable<typename std::tuple_element<6,typename std::remove_reference<__type32>::type>::type>::type __type56;
      typedef typename pythonic::assignable<typename std::tuple_element<7,typename std::remove_reference<__type32>::type>::type>::type __type57;
      typedef typename std::tuple_element<5,typename std::remove_reference<__type32>::type>::type __type58;
      typedef typename pythonic::lazy<__type58>::type __type59;
      typedef typename pythonic::assignable<decltype(std::declval<__type22>()(std::declval<__type12>()))>::type __type60;
      typedef decltype(std::declval<__type22>()(std::declval<__type14>())) __type61;
      typedef typename pythonic::assignable<typename __combined<__type61,__type1>::type>::type __type62;
      typedef decltype(std::declval<__type22>()(std::declval<__type15>())) __type63;
      typedef typename pythonic::assignable<typename __combined<__type63,__type1>::type>::type __type64;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::exp{})>::type>::type __type65;
      typedef typename std::tuple_element<30,typename std::remove_reference<__type8>::type>::type __type66;
      typedef decltype(pythonic::operator_::neg(std::declval<__type66>())) __type67;
      typedef decltype(std::declval<__type65>()(std::declval<__type67>())) __type68;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type1>(), std::declval<__type68>()))>::type __type69;
      typedef typename pythonic::assignable<typename std::tuple_element<29,typename std::remove_reference<__type8>::type>::type>::type __type70;
      typedef typename pythonic::assignable<typename std::tuple_element<18,typename std::remove_reference<__type8>::type>::type>::type __type71;
      typedef typename pythonic::assignable<typename std::tuple_element<13,typename std::remove_reference<__type8>::type>::type>::type __type72;
      typedef typename pythonic::assignable<typename std::tuple_element<16,typename std::remove_reference<__type8>::type>::type>::type __type73;
      typedef typename pythonic::assignable<typename std::tuple_element<17,typename std::remove_reference<__type8>::type>::type>::type __type74;
      typedef typename pythonic::assignable<typename std::tuple_element<21,typename std::remove_reference<__type8>::type>::type>::type __type75;
      typedef typename std::tuple_element<25,typename std::remove_reference<__type8>::type>::type __type76;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type1>(), std::declval<__type76>()))>::type __type77;
      typedef typename pythonic::assignable<typename std::tuple_element<26,typename std::remove_reference<__type8>::type>::type>::type __type78;
      typedef typename std::tuple_element<23,typename std::remove_reference<__type8>::type>::type __type79;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type1>(), std::declval<__type79>()))>::type __type80;
      typedef typename pythonic::assignable<typename std::tuple_element<24,typename std::remove_reference<__type8>::type>::type>::type __type81;
      typedef typename pythonic::assignable<typename std::tuple_element<22,typename std::remove_reference<__type8>::type>::type>::type __type82;
      typedef typename pythonic::assignable<typename std::tuple_element<8,typename std::remove_reference<__type32>::type>::type>::type __type83;
      typedef typename run_transient_GLNetEIMF_adapt::type<__type52, __type53, __type54, __type55, __type56, __type57, __type51, __type59, __type60, __type14, __type15, __type62, __type64, __type69, __type70, __type37, __type71, __type72, __type17, __type73, __type74, __type11, __type75, __type77, __type78, __type80, __type81, __type82, __type83>::__ptype104 __type84;
      typedef typename __combined<__type83,__type84>::type __type85;
      typedef typename run_transient_GLNetEIMF_adapt::type<__type52, __type53, __type54, __type55, __type56, __type57, __type51, __type59, __type60, __type14, __type15, __type62, __type64, __type69, __type70, __type37, __type71, __type72, __type17, __type73, __type74, __type11, __type75, __type77, __type78, __type80, __type81, __type82, __type85>::__ptype105 __type86;
      typedef typename __combined<__type51,__type86>::type __type87;
      typedef run_transient_GLNetEIMF_adapt __type88;
      typedef typename pythonic::assignable<decltype(std::declval<__type88>()(std::declval<__type52>(), std::declval<__type53>(), std::declval<__type54>(), std::declval<__type55>(), std::declval<__type56>(), std::declval<__type57>(), std::declval<__type87>(), std::declval<__type59>(), std::declval<__type60>(), std::declval<__type14>(), std::declval<__type15>(), std::declval<__type62>(), std::declval<__type64>(), std::declval<__type69>(), std::declval<__type70>(), std::declval<__type37>(), std::declval<__type71>(), std::declval<__type72>(), std::declval<__type17>(), std::declval<__type73>(), std::declval<__type74>(), std::declval<__type11>(), std::declval<__type75>(), std::declval<__type77>(), std::declval<__type78>(), std::declval<__type80>(), std::declval<__type81>(), std::declval<__type82>(), std::declval<__type85>()))>::type __type89;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type89>::type>::type __type90;
      typedef typename pythonic::lazy<__type90>::type __type91;
      typedef typename __combined<__type87,__type91>::type __type92;
      typedef container<typename std::remove_reference<__type92>::type> __type93;
      typedef typename __combined<__type49,__type93>::type __type94;
      typedef typename __combined<__type44,__type93>::type __type95;
      typedef decltype(std::declval<__type95>()[std::declval<__type47>()]) __type96;
      typedef typename std::tuple_element<5,typename std::remove_reference<__type89>::type>::type __type97;
      typedef typename __combined<__type53,__type97>::type __type98;
      typedef decltype(std::declval<__type45>()(std::declval<__type14>())) __type99;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type99>::type::iterator>::value_type>::type __type100;
      typedef indexable<__type100> __type101;
      typedef typename __combined<__type98,__type101>::type __type102;
      typedef typename pythonic::assignable<typename std::tuple_element<5,typename std::remove_reference<__type89>::type>::type>::type __type103;
      typedef typename __combined<__type103,__type101>::type __type104;
      typedef typename __combined<__type102,__type104>::type __type105;
      typedef typename std::tuple_element<4,typename std::remove_reference<__type89>::type>::type __type106;
      typedef typename __combined<__type52,__type106>::type __type107;
      typedef typename pythonic::assignable<typename std::tuple_element<4,typename std::remove_reference<__type89>::type>::type>::type __type108;
      typedef typename __combined<__type107,__type108>::type __type109;
      typedef decltype(std::declval<__type109>()[std::declval<__type100>()]) __type110;
      typedef typename __combined<__type98,__type103>::type __type111;
      typedef decltype(std::declval<__type111>()[std::declval<__type100>()]) __type112;
      typedef decltype(pythonic::operator_::sub(std::declval<__type47>(), std::declval<__type4>())) __type113;
      typedef decltype(std::declval<__type95>()[std::declval<__type113>()]) __type114;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type89>::type>::type __type115;
      typedef typename pythonic::lazy<__type115>::type __type116;
      typedef typename __combined<__type59,__type116>::type __type117;
      typedef container<typename std::remove_reference<__type117>::type> __type118;
      typedef typename __combined<__type44,__type118>::type __type119;
      typedef decltype(std::declval<__type119>()[std::declval<__type113>()]) __type120;
      typedef decltype(std::declval<__type56>()[std::declval<__type100>()]) __type121;
      typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type89>::type>::type>::type __type122;
      typedef typename __combined<__type85,__type122>::type __type123;
      typedef typename pythonic::assignable<weightAdapt_decrease>::type __type124;
      typedef typename pythonic::assignable<weightAdapt_increase>::type __type125;
      typedef typename __combined<__type124,__type125>::type __type126;
      typedef typename pythonic::assignable<RunSimulation_GLNetEIMF_adapt_lambda10>::type __type127;
      typedef typename __combined<__type126,__type127>::type __type128;
      typedef typename pythonic::assignable<decltype(std::declval<__type128>()(std::declval<__type123>(), std::declval<__type82>(), std::declval<__type80>(), std::declval<__type81>(), std::declval<__type114>(), std::declval<__type120>()))>::type __type129;
      typedef typename __combined<__type123,__type129>::type __type130;
      typedef typename GLNetEIMF_adaptthresh_iter::type<__type110, __type112, __type114, __type120, __type71, __type72, __type121, __type17, __type73, __type74, __type130, __type11, __type75, __type77, __type78, __type69>::__ptype10 __type131;
      typedef container<typename std::remove_reference<__type131>::type> __type132;
      typedef typename __combined<__type105,__type132>::type __type133;
      typedef GLNetEIMF_adaptthresh_iter __type134;
      typedef typename pythonic::assignable<decltype(std::declval<__type134>()(std::declval<__type110>(), std::declval<__type112>(), std::declval<__type114>(), std::declval<__type120>(), std::declval<__type71>(), std::declval<__type72>(), std::declval<__type121>(), std::declval<__type17>(), std::declval<__type73>(), std::declval<__type74>(), std::declval<__type130>(), std::declval<__type11>(), std::declval<__type75>(), std::declval<__type77>(), std::declval<__type78>(), std::declval<__type69>()))>::type __type135;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type135>::type>::type __type136;
      typedef container<typename std::remove_reference<__type136>::type> __type137;
      typedef typename __combined<__type133,__type137>::type __type138;
      typedef decltype(std::declval<__type138>()[std::declval<__type100>()]) __type139;
      typedef decltype(pythonic::operator_::add(std::declval<__type96>(), std::declval<__type139>())) __type140;
      typedef container<typename std::remove_reference<__type140>::type> __type141;
      typedef typename __combined<__type94,__type141>::type __type142;
      typedef decltype(std::declval<__type142>()[std::declval<__type47>()]) __type143;
      typedef decltype(pythonic::operator_::div(std::declval<__type143>(), std::declval<__type62>())) __type144;
      typedef container<typename std::remove_reference<__type144>::type> __type145;
      typedef typename __combined<__type142,__type145>::type __type146;
      typedef typename __combined<__type49,__type118>::type __type147;
      typedef decltype(std::declval<__type119>()[std::declval<__type47>()]) __type148;
      typedef typename std::tuple_element<7,typename std::remove_reference<__type89>::type>::type __type149;
      typedef typename __combined<__type55,__type149>::type __type150;
      typedef decltype(std::declval<__type45>()(std::declval<__type15>())) __type151;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type151>::type::iterator>::value_type>::type __type152;
      typedef indexable<__type152> __type153;
      typedef typename __combined<__type150,__type153>::type __type154;
      typedef typename pythonic::assignable<typename std::tuple_element<7,typename std::remove_reference<__type89>::type>::type>::type __type155;
      typedef typename __combined<__type155,__type153>::type __type156;
      typedef typename __combined<__type154,__type156>::type __type157;
      typedef typename std::tuple_element<6,typename std::remove_reference<__type89>::type>::type __type158;
      typedef typename __combined<__type54,__type158>::type __type159;
      typedef typename pythonic::assignable<typename std::tuple_element<6,typename std::remove_reference<__type89>::type>::type>::type __type160;
      typedef typename __combined<__type159,__type160>::type __type161;
      typedef decltype(std::declval<__type161>()[std::declval<__type152>()]) __type162;
      typedef typename __combined<__type150,__type155>::type __type163;
      typedef decltype(std::declval<__type163>()[std::declval<__type152>()]) __type164;
      typedef decltype(std::declval<__type142>()[std::declval<__type113>()]) __type165;
      typedef decltype(std::declval<__type57>()[std::declval<__type152>()]) __type166;
      typedef typename GLNetEIMF_adaptthresh_iter::type<__type162, __type164, __type165, __type120, __type71, __type72, __type166, __type17, __type73, __type74, __type130, __type11, __type75, __type77, __type78, __type1>::__ptype10 __type167;
      typedef container<typename std::remove_reference<__type167>::type> __type168;
      typedef typename __combined<__type157,__type168>::type __type169;
      typedef typename pythonic::assignable<decltype(std::declval<__type134>()(std::declval<__type162>(), std::declval<__type164>(), std::declval<__type165>(), std::declval<__type120>(), std::declval<__type71>(), std::declval<__type72>(), std::declval<__type166>(), std::declval<__type17>(), std::declval<__type73>(), std::declval<__type74>(), std::declval<__type130>(), std::declval<__type11>(), std::declval<__type75>(), std::declval<__type77>(), std::declval<__type78>(), std::declval<__type1>()))>::type __type170;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type170>::type>::type __type171;
      typedef container<typename std::remove_reference<__type171>::type> __type172;
      typedef typename __combined<__type169,__type172>::type __type173;
      typedef decltype(std::declval<__type173>()[std::declval<__type152>()]) __type174;
      typedef decltype(pythonic::operator_::add(std::declval<__type148>(), std::declval<__type174>())) __type175;
      typedef container<typename std::remove_reference<__type175>::type> __type176;
      typedef typename __combined<__type147,__type176>::type __type177;
      typedef decltype(std::declval<__type177>()[std::declval<__type47>()]) __type178;
      typedef decltype(pythonic::operator_::div(std::declval<__type178>(), std::declval<__type64>())) __type179;
      typedef container<typename std::remove_reference<__type179>::type> __type180;
      typedef typename __combined<__type177,__type180>::type __type181;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type4>(), std::declval<__type4>())) __type182;
      typedef typename pythonic::assignable<pythonic::types::list<typename std::remove_reference<__type182>::type>>::type __type183;
      typedef save_initial_spkdata __type184;
      typedef typename pythonic::assignable<typename std::tuple_element<28,typename std::remove_reference<__type8>::type>::type>::type __type185;
      typedef decltype(pythonic::operator_::mul(std::declval<__type11>(), std::declval<__type185>())) __type186;
      typedef typename pythonic::assignable<decltype(std::declval<__type10>()(std::declval<__type186>()))>::type __type187;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type185>(), std::declval<__type187>()))>::type __type188;
      typedef typename pythonic::assignable<decltype(std::declval<__type184>()(std::declval<__type111>(), std::declval<__type163>(), std::declval<__type187>(), std::declval<__type188>()))>::type __type189;
      typedef typename __combined<__type183,__type189>::type __type190;
      typedef typename save_spk_data::type<__type190, __type47, __type100>::__ptype0 __type191;
      typedef pythonic::types::list<typename std::remove_reference<__type191>::type> __type192;
      typedef typename __combined<__type183,__type192>::type __type193;
      typedef typename __combined<__type190,__type192>::type __type194;
      typedef typename save_spk_data::type<__type194, __type47, __type100>::__ptype1 __type195;
      typedef pythonic::types::list<typename std::remove_reference<__type195>::type> __type196;
      typedef typename __combined<__type193,__type196>::type __type197;
      typedef typename pythonic::assignable<save_spk_data_fake>::type __type198;
      typedef typename pythonic::assignable<save_spk_data>::type __type199;
      typedef typename __combined<__type198,__type199>::type __type200;
      typedef typename __combined<__type194,__type196>::type __type201;
      typedef decltype(std::declval<__type200>()(std::declval<__type201>(), std::declval<__type47>(), std::declval<__type100>())) __type202;
      typedef typename __combined<__type197,__type202>::type __type203;
      typedef typename __combined<__type189,__type192>::type __type204;
      typedef typename __combined<__type204,__type196>::type __type205;
      typedef typename __combined<__type205,__type202>::type __type206;
      typedef typename __combined<__type203,__type206>::type __type207;
      typedef typename __combined<__type207,__type201>::type __type208;
      typedef typename __combined<__type192,__type196>::type __type209;
      typedef typename __combined<__type209,__type202>::type __type210;
      typedef typename __combined<__type208,__type210>::type __type211;
      typedef typename pythonic::assignable<typename __combined<__type209,__type202>::type>::type __type212;
      typedef typename __combined<__type211,__type212>::type __type213;
      typedef decltype(pythonic::operator_::add(std::declval<__type152>(), std::declval<__type187>())) __type214;
      typedef typename save_spk_data::type<__type213, __type47, __type214>::__ptype0 __type215;
      typedef pythonic::types::list<typename std::remove_reference<__type215>::type> __type216;
      typedef typename __combined<__type203,__type216>::type __type217;
      typedef typename __combined<__type213,__type216>::type __type218;
      typedef typename save_spk_data::type<__type218, __type47, __type214>::__ptype1 __type219;
      typedef pythonic::types::list<typename std::remove_reference<__type219>::type> __type220;
      typedef typename __combined<__type217,__type220>::type __type221;
      typedef typename __combined<__type218,__type220>::type __type222;
      typedef decltype(std::declval<__type200>()(std::declval<__type222>(), std::declval<__type47>(), std::declval<__type214>())) __type223;
      typedef typename __combined<__type221,__type223>::type __type224;
      typedef typename __combined<__type206,__type216>::type __type225;
      typedef typename __combined<__type225,__type220>::type __type226;
      typedef typename __combined<__type226,__type223>::type __type227;
      typedef typename __combined<__type224,__type227>::type __type228;
      typedef typename __combined<__type228,__type201>::type __type229;
      typedef typename __combined<__type210,__type216>::type __type230;
      typedef typename __combined<__type230,__type220>::type __type231;
      typedef typename pythonic::assignable<typename __combined<__type231,__type223>::type>::type __type232;
      typedef typename __combined<__type229,__type232>::type __type233;
      typedef typename __combined<__type212,__type216>::type __type234;
      typedef typename __combined<__type234,__type220>::type __type235;
      typedef typename __combined<__type235,__type223>::type __type236;
      typedef typename __combined<__type233,__type236>::type __type237;
      typedef typename __combined<__type237,__type222>::type __type238;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::multiply{})>::type>::type __type239;
      typedef decltype(pythonic::operator_::mul(std::declval<__type11>(), std::declval<__type17>())) __type240;
      typedef decltype(std::declval<__type239>()(std::declval<__type240>(), std::declval<__type146>())) __type241;
      typedef container<typename std::remove_reference<__type123>::type> __type242;
      typedef typename __combined<__type49,__type242>::type __type243;
      typedef container<typename std::remove_reference<__type130>::type> __type244;
      typedef typename __combined<__type243,__type244>::type __type245;
      typedef decltype(std::declval<__type239>()(std::declval<__type245>(), std::declval<__type181>())) __type246;
      typedef decltype(std::declval<__type239>()(std::declval<__type75>(), std::declval<__type246>())) __type247;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::divide{})>::type>::type __type248;
      typedef decltype(std::declval<__type248>()(std::declval<__type245>(), std::declval<__type17>())) __type249;
      typedef typename pythonic::lazy<__type33>::type __type250;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type89>::type>::type __type251;
      typedef typename pythonic::lazy<__type251>::type __type252;
      typedef typename __combined<__type250,__type252>::type __type253;
      typedef container<typename std::remove_reference<__type253>::type> __type254;
      typedef typename __combined<__type49,__type254>::type __type255;
      typedef typename pythonic::assignable<double>::type __type256;
      typedef typename __combined<__type56,__type101>::type __type257;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type135>::type>::type __type258;
      typedef container<typename std::remove_reference<__type258>::type> __type259;
      typedef typename __combined<__type257,__type259>::type __type260;
      typedef decltype(std::declval<__type260>()[std::declval<__type100>()]) __type261;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::add(std::declval<__type256>(), std::declval<__type261>()))>::type __type262;
      typedef typename __combined<__type256,__type262>::type __type263;
      typedef typename __combined<__type57,__type153>::type __type264;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type170>::type>::type __type265;
      typedef container<typename std::remove_reference<__type265>::type> __type266;
      typedef typename __combined<__type264,__type266>::type __type267;
      typedef decltype(std::declval<__type267>()[std::declval<__type152>()]) __type268;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::add(std::declval<__type263>(), std::declval<__type268>()))>::type __type269;
      typedef typename __combined<__type263,__type269>::type __type270;
      typedef decltype(pythonic::operator_::div(std::declval<__type270>(), std::declval<__type60>())) __type271;
      typedef container<typename std::remove_reference<__type271>::type> __type272;
      typedef typename __combined<__type255,__type272>::type __type273;
      typedef decltype(std::declval<__type248>()(std::declval<__type74>(), std::declval<__type273>())) __type274;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type146>(), std::declval<__type181>(), std::declval<__type238>(), std::declval<__type241>(), std::declval<__type247>(), std::declval<__type249>(), std::declval<__type274>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& simParam_dict, argument_type1&& paramType_dict) const
    ;
  }  ;
  struct RunSimulation_GLNetEIRand_static
  {
    typedef void callable;
    ;
    template <typename argument_type0 , typename argument_type1 >
    struct type
    {
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::array{})>::type>::type __type0;
      typedef double __type1;
      typedef pythonic::types::list<typename std::remove_reference<__type1>::type> __type2;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::max{})>::type>::type __type3;
      typedef long __type4;
      typedef get_system_parameters __type5;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type6;
      typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type7;
      typedef typename pythonic::assignable<decltype(std::declval<__type5>()(std::declval<__type6>(), std::declval<__type7>()))>::type __type8;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type8>::type>::type __type9;
      typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type8>::type>::type>::type __type10;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type9>(), std::declval<__type10>()))>::type __type11;
      typedef typename __combined<__type4,__type11>::type __type12;
      typedef decltype(std::declval<__type3>()(std::declval<__type12>(), std::declval<__type11>())) __type13;
      typedef decltype(pythonic::operator_::mul(std::declval<__type2>(), std::declval<__type13>())) __type14;
      typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type14>()))>::type __type15;
      typedef indexable<__type4> __type16;
      typedef typename __combined<__type15,__type16>::type __type17;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type18;
      typedef decltype(std::declval<__type18>()(std::declval<__type4>(), std::declval<__type11>())) __type19;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type19>::type::iterator>::value_type>::type __type20;
      typedef indexable<__type20> __type21;
      typedef typename __combined<__type17,__type21>::type __type22;
      typedef set_MF_network_IC __type23;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::int_{})>::type>::type __type24;
      typedef typename pythonic::assignable<typename std::tuple_element<20,typename std::remove_reference<__type8>::type>::type>::type __type25;
      typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type8>::type>::type>::type __type26;
      typedef decltype(pythonic::operator_::mul(std::declval<__type25>(), std::declval<__type26>())) __type27;
      typedef typename pythonic::assignable<decltype(std::declval<__type24>()(std::declval<__type27>()))>::type __type28;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type26>(), std::declval<__type28>()))>::type __type29;
      typedef typename pythonic::assignable<typename std::tuple_element<19,typename std::remove_reference<__type8>::type>::type>::type __type30;
      typedef typename pythonic::assignable<typename std::tuple_element<15,typename std::remove_reference<__type8>::type>::type>::type __type31;
      typedef typename std::tuple_element<3,typename std::remove_reference<__type8>::type>::type __type32;
      typedef typename std::tuple_element<4,typename std::remove_reference<__type8>::type>::type __type33;
      typedef typename std::tuple_element<5,typename std::remove_reference<__type8>::type>::type __type34;
      typedef typename std::tuple_element<6,typename std::remove_reference<__type8>::type>::type __type35;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type36;
      typedef typename std::tuple_element<7,typename std::remove_reference<__type8>::type>::type __type37;
      typedef decltype(std::declval<__type36>()(std::declval<__type37>())) __type38;
      typedef typename std::tuple_element<8,typename std::remove_reference<__type8>::type>::type __type39;
      typedef typename std::tuple_element<9,typename std::remove_reference<__type8>::type>::type __type40;
      typedef typename std::tuple_element<10,typename std::remove_reference<__type8>::type>::type __type41;
      typedef decltype(std::declval<__type36>()(std::declval<__type41>())) __type42;
      typedef typename std::tuple_element<11,typename std::remove_reference<__type8>::type>::type __type43;
      typedef typename std::tuple_element<12,typename std::remove_reference<__type8>::type>::type __type44;
      typedef typename pythonic::assignable<typename std::tuple_element<14,typename std::remove_reference<__type8>::type>::type>::type __type45;
      typedef typename pythonic::assignable<decltype(std::declval<__type23>()(std::declval<__type28>(), std::declval<__type29>(), std::declval<__type30>(), std::declval<__type31>(), std::declval<__type32>(), std::declval<__type33>(), std::declval<__type34>(), std::declval<__type35>(), std::declval<__type38>(), std::declval<__type39>(), std::declval<__type40>(), std::declval<__type42>(), std::declval<__type43>(), std::declval<__type44>(), std::declval<__type45>()))>::type __type46;
      typedef typename std::tuple_element<4,typename std::remove_reference<__type46>::type>::type __type47;
      typedef typename pythonic::lazy<__type47>::type __type48;
      typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type46>::type>::type>::type __type49;
      typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type46>::type>::type>::type __type50;
      typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type46>::type>::type>::type __type51;
      typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type46>::type>::type>::type __type52;
      typedef typename std::tuple_element<5,typename std::remove_reference<__type46>::type>::type __type53;
      typedef typename pythonic::lazy<__type53>::type __type54;
      typedef decltype(std::declval<__type36>()(std::declval<__type28>())) __type55;
      typedef typename pythonic::assignable<typename __combined<__type55,__type1>::type>::type __type56;
      typedef decltype(std::declval<__type36>()(std::declval<__type29>())) __type57;
      typedef typename pythonic::assignable<typename __combined<__type57,__type1>::type>::type __type58;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::exp{})>::type>::type __type59;
      typedef typename std::tuple_element<30,typename std::remove_reference<__type8>::type>::type __type60;
      typedef decltype(pythonic::operator_::neg(std::declval<__type60>())) __type61;
      typedef decltype(std::declval<__type59>()(std::declval<__type61>())) __type62;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type1>(), std::declval<__type62>()))>::type __type63;
      typedef typename pythonic::assignable<typename std::tuple_element<18,typename std::remove_reference<__type8>::type>::type>::type __type64;
      typedef typename pythonic::assignable<typename std::tuple_element<13,typename std::remove_reference<__type8>::type>::type>::type __type65;
      typedef typename pythonic::assignable<typename std::tuple_element<16,typename std::remove_reference<__type8>::type>::type>::type __type66;
      typedef typename pythonic::assignable<typename std::tuple_element<17,typename std::remove_reference<__type8>::type>::type>::type __type67;
      typedef typename __combined<__type4,__type26>::type __type68;
      typedef decltype(std::declval<__type3>()(std::declval<__type68>(), std::declval<__type26>())) __type69;
      typedef decltype(pythonic::operator_::mul(std::declval<__type2>(), std::declval<__type69>())) __type70;
      typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type70>()))>::type __type71;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::mul(std::declval<__type30>(), std::declval<__type31>()))>::type __type72;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::map{})>::type>::type __type73;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::functools::functor::partial{})>::type>::type __type74;
      typedef generate_random_net_fixed_input_lambda15 __type75;
      typedef typename pythonic::assignable<typename std::tuple_element<31,typename std::remove_reference<__type8>::type>::type>::type __type76;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::ceil{})>::type>::type __type77;
      typedef decltype(std::declval<__type36>()(std::declval<__type76>())) __type78;
      typedef decltype(pythonic::operator_::mul(std::declval<__type25>(), std::declval<__type78>())) __type79;
      typedef decltype(std::declval<__type77>()(std::declval<__type79>())) __type80;
      typedef typename pythonic::assignable<decltype(std::declval<__type24>()(std::declval<__type80>()))>::type __type81;
      typedef typename pythonic::assignable<typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type8>::type>::type>::type>::type __type82;
      typedef decltype(std::declval<__type74>()(std::declval<__type75>(), std::declval<__type76>(), std::declval<__type81>(), std::declval<__type82>(), std::declval<__type28>())) __type83;
      typedef decltype(std::declval<__type18>()(std::declval<__type82>())) __type84;
      typedef decltype(std::declval<__type73>()(std::declval<__type83>(), std::declval<__type84>())) __type85;
      typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type85>()))>::type __type86;
      typedef typename run_transient_GLNetEIRand_static::type<__type49, __type50, __type51, __type52, __type10, __type48, __type54, __type28, __type29, __type56, __type58, __type63, __type64, __type65, __type45, __type66, __type67, __type71, __type31, __type72, __type86, __type81, __type76>::__ptype82 __type87;
      typedef typename __combined<__type48,__type87>::type __type88;
      typedef run_transient_GLNetEIRand_static __type89;
      typedef typename run_transient_GLNetEIRand_static::type<__type49, __type50, __type51, __type52, __type10, __type88, __type54, __type28, __type29, __type56, __type58, __type63, __type64, __type65, __type45, __type66, __type67, __type71, __type31, __type72, __type86, __type81, __type76>::__ptype83 __type90;
      typedef typename __combined<__type54,__type90>::type __type91;
      typedef typename pythonic::assignable<decltype(std::declval<__type89>()(std::declval<__type49>(), std::declval<__type50>(), std::declval<__type51>(), std::declval<__type52>(), std::declval<__type10>(), std::declval<__type88>(), std::declval<__type91>(), std::declval<__type28>(), std::declval<__type29>(), std::declval<__type56>(), std::declval<__type58>(), std::declval<__type63>(), std::declval<__type64>(), std::declval<__type65>(), std::declval<__type45>(), std::declval<__type66>(), std::declval<__type67>(), std::declval<__type71>(), std::declval<__type31>(), std::declval<__type72>(), std::declval<__type86>(), std::declval<__type81>(), std::declval<__type76>()))>::type __type92;
      typedef typename std::tuple_element<0,typename std::remove_reference<__type92>::type>::type __type93;
      typedef typename pythonic::lazy<__type93>::type __type94;
      typedef typename __combined<__type88,__type94>::type __type95;
      typedef container<typename std::remove_reference<__type95>::type> __type96;
      typedef typename __combined<__type22,__type96>::type __type97;
      typedef typename __combined<__type17,__type96>::type __type98;
      typedef decltype(std::declval<__type98>()[std::declval<__type20>()]) __type99;
      typedef typename std::tuple_element<3,typename std::remove_reference<__type92>::type>::type __type100;
      typedef typename __combined<__type50,__type100>::type __type101;
      typedef decltype(std::declval<__type18>()(std::declval<__type28>())) __type102;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type102>::type::iterator>::value_type>::type __type103;
      typedef indexable<__type103> __type104;
      typedef typename __combined<__type101,__type104>::type __type105;
      typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type92>::type>::type>::type __type106;
      typedef typename __combined<__type106,__type104>::type __type107;
      typedef typename __combined<__type105,__type107>::type __type108;
      typedef GLNetEIRand_iter __type109;
      typedef typename std::tuple_element<2,typename std::remove_reference<__type92>::type>::type __type110;
      typedef typename __combined<__type49,__type110>::type __type111;
      typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type92>::type>::type>::type __type112;
      typedef typename __combined<__type111,__type112>::type __type113;
      typedef decltype(std::declval<__type113>()[std::declval<__type103>()]) __type114;
      typedef typename __combined<__type101,__type106>::type __type115;
      typedef decltype(std::declval<__type115>()[std::declval<__type103>()]) __type116;
      typedef typename std::tuple_element<5,typename std::remove_reference<__type92>::type>::type __type117;
      typedef typename __combined<__type52,__type117>::type __type118;
      typedef typename pythonic::assignable<typename std::tuple_element<5,typename std::remove_reference<__type92>::type>::type>::type __type119;
      typedef typename __combined<__type118,__type119>::type __type120;
      typedef typename sumSynpaticInput_homog::type<__type71, __type81, __type76, __type26, __type115, __type120, __type31, __type72, __type86>::__ptype2 __type121;
      typedef container<typename std::remove_reference<__type121>::type> __type122;
      typedef typename __combined<__type71,__type122>::type __type123;
      typedef typename sumSynpaticInput_homog::type<__type123, __type81, __type76, __type26, __type115, __type120, __type31, __type72, __type86>::__ptype3 __type124;
      typedef indexable<__type124> __type125;
      typedef typename __combined<__type123,__type125>::type __type126;
      typedef decltype(std::declval<__type126>()[std::declval<__type103>()]) __type127;
      typedef typename pythonic::assignable<decltype(std::declval<__type109>()(std::declval<__type114>(), std::declval<__type116>(), std::declval<__type127>(), std::declval<__type64>(), std::declval<__type65>(), std::declval<__type45>(), std::declval<__type66>(), std::declval<__type67>(), std::declval<__type63>()))>::type __type128;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type128>::type>::type __type129;
      typedef container<typename std::remove_reference<__type129>::type> __type130;
      typedef typename __combined<__type108,__type130>::type __type131;
      typedef decltype(std::declval<__type131>()[std::declval<__type103>()]) __type132;
      typedef decltype(pythonic::operator_::add(std::declval<__type99>(), std::declval<__type132>())) __type133;
      typedef container<typename std::remove_reference<__type133>::type> __type134;
      typedef typename __combined<__type97,__type134>::type __type135;
      typedef decltype(std::declval<__type135>()[std::declval<__type20>()]) __type136;
      typedef decltype(pythonic::operator_::div(std::declval<__type136>(), std::declval<__type56>())) __type137;
      typedef container<typename std::remove_reference<__type137>::type> __type138;
      typedef typename __combined<__type135,__type138>::type __type139;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type92>::type>::type __type140;
      typedef typename pythonic::lazy<__type140>::type __type141;
      typedef typename __combined<__type91,__type141>::type __type142;
      typedef container<typename std::remove_reference<__type142>::type> __type143;
      typedef typename __combined<__type22,__type143>::type __type144;
      typedef typename __combined<__type17,__type143>::type __type145;
      typedef decltype(std::declval<__type145>()[std::declval<__type20>()]) __type146;
      typedef decltype(std::declval<__type18>()(std::declval<__type29>())) __type147;
      typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type147>::type::iterator>::value_type>::type __type148;
      typedef indexable<__type148> __type149;
      typedef typename __combined<__type118,__type149>::type __type150;
      typedef typename __combined<__type119,__type149>::type __type151;
      typedef typename __combined<__type150,__type151>::type __type152;
      typedef typename std::tuple_element<4,typename std::remove_reference<__type92>::type>::type __type153;
      typedef typename __combined<__type51,__type153>::type __type154;
      typedef typename pythonic::assignable<typename std::tuple_element<4,typename std::remove_reference<__type92>::type>::type>::type __type155;
      typedef typename __combined<__type154,__type155>::type __type156;
      typedef decltype(std::declval<__type156>()[std::declval<__type148>()]) __type157;
      typedef decltype(std::declval<__type120>()[std::declval<__type148>()]) __type158;
      typedef decltype(std::declval<__type126>()[std::declval<__type148>()]) __type159;
      typedef typename pythonic::assignable<decltype(std::declval<__type109>()(std::declval<__type157>(), std::declval<__type158>(), std::declval<__type159>(), std::declval<__type64>(), std::declval<__type65>(), std::declval<__type45>(), std::declval<__type66>(), std::declval<__type67>(), std::declval<__type1>()))>::type __type160;
      typedef typename std::tuple_element<1,typename std::remove_reference<__type160>::type>::type __type161;
      typedef container<typename std::remove_reference<__type161>::type> __type162;
      typedef typename __combined<__type152,__type162>::type __type163;
      typedef decltype(std::declval<__type163>()[std::declval<__type148>()]) __type164;
      typedef decltype(pythonic::operator_::add(std::declval<__type146>(), std::declval<__type164>())) __type165;
      typedef container<typename std::remove_reference<__type165>::type> __type166;
      typedef typename __combined<__type144,__type166>::type __type167;
      typedef decltype(std::declval<__type167>()[std::declval<__type20>()]) __type168;
      typedef decltype(pythonic::operator_::div(std::declval<__type168>(), std::declval<__type58>())) __type169;
      typedef container<typename std::remove_reference<__type169>::type> __type170;
      typedef typename __combined<__type167,__type170>::type __type171;
      typedef decltype(pythonic::types::make_tuple(std::declval<__type4>(), std::declval<__type4>())) __type172;
      typedef typename pythonic::assignable<pythonic::types::list<typename std::remove_reference<__type172>::type>>::type __type173;
      typedef save_initial_spkdata __type174;
      typedef typename pythonic::assignable<typename std::tuple_element<28,typename std::remove_reference<__type8>::type>::type>::type __type175;
      typedef decltype(pythonic::operator_::mul(std::declval<__type25>(), std::declval<__type175>())) __type176;
      typedef typename pythonic::assignable<decltype(std::declval<__type24>()(std::declval<__type176>()))>::type __type177;
      typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type175>(), std::declval<__type177>()))>::type __type178;
      typedef typename pythonic::assignable<decltype(std::declval<__type174>()(std::declval<__type115>(), std::declval<__type120>(), std::declval<__type177>(), std::declval<__type178>()))>::type __type179;
      typedef typename __combined<__type173,__type179>::type __type180;
      typedef typename save_spk_data::type<__type180, __type20, __type103>::__ptype0 __type181;
      typedef pythonic::types::list<typename std::remove_reference<__type181>::type> __type182;
      typedef typename __combined<__type173,__type182>::type __type183;
      typedef typename __combined<__type180,__type182>::type __type184;
      typedef typename save_spk_data::type<__type184, __type20, __type103>::__ptype1 __type185;
      typedef pythonic::types::list<typename std::remove_reference<__type185>::type> __type186;
      typedef typename __combined<__type183,__type186>::type __type187;
      typedef typename pythonic::assignable<save_spk_data_fake>::type __type188;
      typedef typename pythonic::assignable<save_spk_data>::type __type189;
      typedef typename __combined<__type188,__type189>::type __type190;
      typedef typename __combined<__type184,__type186>::type __type191;
      typedef decltype(std::declval<__type190>()(std::declval<__type191>(), std::declval<__type20>(), std::declval<__type103>())) __type192;
      typedef typename __combined<__type187,__type192>::type __type193;
      typedef typename __combined<__type179,__type182>::type __type194;
      typedef typename __combined<__type194,__type186>::type __type195;
      typedef typename __combined<__type195,__type192>::type __type196;
      typedef typename __combined<__type193,__type196>::type __type197;
      typedef typename __combined<__type197,__type191>::type __type198;
      typedef typename __combined<__type182,__type186>::type __type199;
      typedef typename pythonic::assignable<typename __combined<__type199,__type192>::type>::type __type200;
      typedef typename __combined<__type198,__type200>::type __type201;
      typedef typename __combined<__type199,__type192>::type __type202;
      typedef typename __combined<__type201,__type202>::type __type203;
      typedef decltype(pythonic::operator_::add(std::declval<__type148>(), std::declval<__type177>())) __type204;
      typedef typename save_spk_data::type<__type203, __type20, __type204>::__ptype0 __type205;
      typedef pythonic::types::list<typename std::remove_reference<__type205>::type> __type206;
      typedef typename __combined<__type193,__type206>::type __type207;
      typedef typename __combined<__type203,__type206>::type __type208;
      typedef typename save_spk_data::type<__type208, __type20, __type204>::__ptype1 __type209;
      typedef pythonic::types::list<typename std::remove_reference<__type209>::type> __type210;
      typedef typename __combined<__type207,__type210>::type __type211;
      typedef typename __combined<__type208,__type210>::type __type212;
      typedef decltype(std::declval<__type190>()(std::declval<__type212>(), std::declval<__type20>(), std::declval<__type204>())) __type213;
      typedef typename __combined<__type211,__type213>::type __type214;
      typedef typename __combined<__type196,__type206>::type __type215;
      typedef typename __combined<__type215,__type210>::type __type216;
      typedef typename __combined<__type216,__type213>::type __type217;
      typedef typename __combined<__type214,__type217>::type __type218;
      typedef typename __combined<__type218,__type191>::type __type219;
      typedef typename __combined<__type200,__type206>::type __type220;
      typedef typename __combined<__type220,__type210>::type __type221;
      typedef typename __combined<__type221,__type213>::type __type222;
      typedef typename __combined<__type219,__type222>::type __type223;
      typedef typename __combined<__type202,__type206>::type __type224;
      typedef typename __combined<__type224,__type210>::type __type225;
      typedef typename pythonic::assignable<typename __combined<__type225,__type213>::type>::type __type226;
      typedef typename __combined<__type223,__type226>::type __type227;
      typedef typename __combined<__type227,__type212>::type __type228;
      typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::list{})>::type>::type __type229;
      typedef RunSimulation_GLNetEIRand_static_lambda1 __type230;
      typedef decltype(std::declval<__type74>()(std::declval<__type230>(), std::declval<__type31>(), std::declval<__type25>())) __type231;
      typedef decltype(std::declval<__type73>()(std::declval<__type231>(), std::declval<__type139>())) __type232;
      typedef decltype(std::declval<__type229>()(std::declval<__type232>())) __type233;
      typedef RunSimulation_GLNetEIRand_static_lambda2 __type234;
      typedef typename std::tuple_element<21,typename std::remove_reference<__type8>::type>::type __type235;
      typedef decltype(std::declval<__type74>()(std::declval<__type234>(), std::declval<__type31>(), std::declval<__type30>(), std::declval<__type235>())) __type236;
      typedef decltype(std::declval<__type73>()(std::declval<__type236>(), std::declval<__type171>())) __type237;
      typedef decltype(std::declval<__type229>()(std::declval<__type237>())) __type238;
      typedef RunSimulation_GLNetEIRand_static_lambda3 __type239;
      typedef decltype(std::declval<__type74>()(std::declval<__type239>(), std::declval<__type30>())) __type240;
      typedef decltype(std::declval<__type73>()(std::declval<__type240>(), std::declval<__type139>())) __type241;
      typedef decltype(std::declval<__type229>()(std::declval<__type241>())) __type242;
      typedef RunSimulation_GLNetEIRand_static_lambda4 __type243;
      typedef decltype(std::declval<__type74>()(std::declval<__type243>(), std::declval<__type67>(), std::declval<__type45>())) __type244;
      typedef decltype(std::declval<__type73>()(std::declval<__type244>(), std::declval<__type139>())) __type245;
      typedef decltype(std::declval<__type229>()(std::declval<__type245>())) __type246;
      typedef typename pythonic::returnable<decltype(pythonic::types::make_tuple(std::declval<__type139>(), std::declval<__type171>(), std::declval<__type228>(), std::declval<__type233>(), std::declval<__type238>(), std::declval<__type242>(), std::declval<__type246>()))>::type result_type;
    }  
    ;
    template <typename argument_type0 , typename argument_type1 >
    typename type<argument_type0, argument_type1>::result_type operator()(argument_type0&& simParam_dict, argument_type1&& paramType_dict) const
    ;
  }  ;
  template <typename argument_type0 , typename argument_type1 >
  typename multvecelem_lambda21::type<argument_type0, argument_type1>::result_type multvecelem_lambda21::operator()(argument_type0&& x, argument_type1&& __tuple00) const
  {
    return pythonic::operator_::mul(x[std::get<0>(__tuple00)], std::get<1>(__tuple00));
  }
  template <typename argument_type0 , typename argument_type1 >
  typename generate_IC_spikes_lambda20::type<argument_type0, argument_type1>::result_type generate_IC_spikes_lambda20::operator()(argument_type0&& X0, argument_type1&& i) const
  {
    return X0;
  }
  template <typename argument_type0 , typename argument_type1 >
  typename set_MF_network_IC_lambda19::type<argument_type0, argument_type1>::result_type set_MF_network_IC_lambda19::operator()(argument_type0&& theta, argument_type1&& i) const
  {
    return theta;
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename set_MF_network_IC_lambda18::type<argument_type0, argument_type1, argument_type2>::result_type set_MF_network_IC_lambda18::operator()(argument_type0&& VI0, argument_type1&& VI0Std, argument_type2&& i) const
  {
    return pythonic::builtins::functor::abs{}(pythonic::random::functor::gauss{}(VI0, VI0Std));
  }
  template <typename argument_type0 , typename argument_type1 >
  typename set_MF_network_IC_lambda17::type<argument_type0, argument_type1>::result_type set_MF_network_IC_lambda17::operator()(argument_type0&& theta, argument_type1&& i) const
  {
    return theta;
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename set_MF_network_IC_lambda16::type<argument_type0, argument_type1, argument_type2>::result_type set_MF_network_IC_lambda16::operator()(argument_type0&& VE0, argument_type1&& VE0Std, argument_type2&& i) const
  {
    return pythonic::builtins::functor::abs{}(pythonic::random::functor::gauss{}(VE0, VE0Std));
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 >
  typename generate_random_net_fixed_input_lambda15::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4>::result_type generate_random_net_fixed_input_lambda15::operator()(argument_type0&& K, argument_type1&& K_ex, argument_type2&& N, argument_type3&& pN, argument_type4&& _) const
  {
    return pythonic::operator_::add(pythonic::builtins::functor::sorted{}(pythonic::random::functor::sample{}(pythonic::builtins::functor::range{}(pN), K_ex)), pythonic::builtins::functor::sorted{}(pythonic::random::functor::sample{}(pythonic::builtins::functor::range{}(pythonic::operator_::sub(N, pN)), pythonic::operator_::sub(K, K_ex))));
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename RunSimulation_GLNetEIMF_static_lambda14::type<argument_type0, argument_type1, argument_type2>::result_type RunSimulation_GLNetEIMF_static_lambda14::operator()(argument_type0&& I, argument_type1&& theta, argument_type2&& _) const
  {
    return pythonic::operator_::div(I, theta);
  }
  template <typename argument_type0 , typename argument_type1 >
  typename RunSimulation_GLNetEIMF_static_lambda13::type<argument_type0, argument_type1>::result_type RunSimulation_GLNetEIMF_static_lambda13::operator()(argument_type0&& g, argument_type1&& _) const
  {
    return g;
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename RunSimulation_GLNetEIMF_static_lambda12::type<argument_type0, argument_type1, argument_type2>::result_type RunSimulation_GLNetEIMF_static_lambda12::operator()(argument_type0&& spkTimeFile, argument_type1&& t_ind, argument_type2&& k_ind) const
  {
    return pythonic::io::_io::TextIOWrapper::functor::write{}(spkTimeFile, pythonic::operator_::add(pythonic::builtins::str::functor::join{}(pythonic::types::str(","), pythonic::types::make_tuple(pythonic::builtins::functor::str{}(t_ind), pythonic::builtins::functor::str{}(k_ind))), pythonic::types::str(pythonic::types::str("\n"
""))));
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename RunSimulation_GLNetEIMF_adapt_lambda11::type<argument_type0, argument_type1, argument_type2>::result_type RunSimulation_GLNetEIMF_adapt_lambda11::operator()(argument_type0&& spkTimeFile, argument_type1&& t_ind, argument_type2&& k_ind) const
  {
    return pythonic::io::_io::TextIOWrapper::functor::write{}(spkTimeFile, pythonic::operator_::add(pythonic::builtins::str::functor::join{}(pythonic::types::str(","), pythonic::types::make_tuple(pythonic::builtins::functor::str{}(t_ind), pythonic::builtins::functor::str{}(k_ind))), pythonic::types::str(pythonic::types::str("\n"
""))));
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 >
  typename RunSimulation_GLNetEIMF_adapt_lambda10::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5>::result_type RunSimulation_GLNetEIMF_adapt_lambda10::operator()(argument_type0&& W, argument_type1&& A, argument_type2&& tauWinv, argument_type3&& uW, argument_type4&& rhoE, argument_type5&& rhoI) const
  {
    return 0.0;
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename RunSimulation_GLNetEIMF_aval_lambda9::type<argument_type0, argument_type1, argument_type2>::result_type RunSimulation_GLNetEIMF_aval_lambda9::operator()(argument_type0&& I, argument_type1&& theta, argument_type2&& _) const
  {
    return pythonic::operator_::div(I, theta);
  }
  template <typename argument_type0 , typename argument_type1 >
  typename RunSimulation_GLNetEIMF_aval_lambda8::type<argument_type0, argument_type1>::result_type RunSimulation_GLNetEIMF_aval_lambda8::operator()(argument_type0&& g, argument_type1&& _) const
  {
    return g;
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename RunSimulation_GLNetEIMF_aval_lambda7::type<argument_type0, argument_type1, argument_type2>::result_type RunSimulation_GLNetEIMF_aval_lambda7::operator()(argument_type0&& spkTimeFile, argument_type1&& t_ind, argument_type2&& k_ind) const
  {
    return pythonic::io::_io::TextIOWrapper::functor::write{}(spkTimeFile, pythonic::operator_::add(pythonic::builtins::str::functor::join{}(pythonic::types::str(","), pythonic::types::make_tuple(pythonic::builtins::functor::str{}(t_ind), pythonic::builtins::functor::str{}(k_ind))), pythonic::types::str(pythonic::types::str("\n"
""))));
  }
  template <typename argument_type0 , typename argument_type1 >
  typename RunSimulation_GLNetEIMF_adaptthresh_lambda6::type<argument_type0, argument_type1>::result_type RunSimulation_GLNetEIMF_adaptthresh_lambda6::operator()(argument_type0&& g, argument_type1&& _) const
  {
    return g;
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename RunSimulation_GLNetEIMF_adaptthresh_lambda5::type<argument_type0, argument_type1, argument_type2>::result_type RunSimulation_GLNetEIMF_adaptthresh_lambda5::operator()(argument_type0&& spkTimeFile, argument_type1&& t_ind, argument_type2&& k_ind) const
  {
    return pythonic::io::_io::TextIOWrapper::functor::write{}(spkTimeFile, pythonic::operator_::add(pythonic::builtins::str::functor::join{}(pythonic::types::str(","), pythonic::types::make_tuple(pythonic::builtins::functor::str{}(t_ind), pythonic::builtins::functor::str{}(k_ind))), pythonic::types::str(pythonic::types::str("\n"
""))));
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename RunSimulation_GLNetEIRand_static_lambda4::type<argument_type0, argument_type1, argument_type2>::result_type RunSimulation_GLNetEIRand_static_lambda4::operator()(argument_type0&& I, argument_type1&& theta, argument_type2&& r) const
  {
    return pythonic::operator_::div(I, theta);
  }
  template <typename argument_type0 , typename argument_type1 >
  typename RunSimulation_GLNetEIRand_static_lambda3::type<argument_type0, argument_type1>::result_type RunSimulation_GLNetEIRand_static_lambda3::operator()(argument_type0&& g, argument_type1&& r) const
  {
    return g;
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 >
  typename RunSimulation_GLNetEIRand_static_lambda2::type<argument_type0, argument_type1, argument_type2, argument_type3>::result_type RunSimulation_GLNetEIRand_static_lambda2::operator()(argument_type0&& J, argument_type1&& g, argument_type2&& q, argument_type3&& r) const
  {
    return pythonic::operator_::mul(pythonic::operator_::mul(pythonic::operator_::mul(q, g), J), r);
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename RunSimulation_GLNetEIRand_static_lambda1::type<argument_type0, argument_type1, argument_type2>::result_type RunSimulation_GLNetEIRand_static_lambda1::operator()(argument_type0&& J, argument_type1&& p, argument_type2&& r) const
  {
    return pythonic::operator_::mul(pythonic::operator_::mul(p, J), r);
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename RunSimulation_GLNetEIRand_static_lambda0::type<argument_type0, argument_type1, argument_type2>::result_type RunSimulation_GLNetEIRand_static_lambda0::operator()(argument_type0&& spkTimeFile, argument_type1&& t_ind, argument_type2&& k_ind) const
  {
    return pythonic::io::_io::TextIOWrapper::functor::write{}(spkTimeFile, pythonic::operator_::add(pythonic::builtins::str::functor::join{}(pythonic::types::str(","), pythonic::types::make_tuple(pythonic::builtins::functor::str{}(t_ind), pythonic::builtins::functor::str{}(k_ind))), pythonic::types::str(pythonic::types::str("\n"
""))));
  }
  template <typename argument_type0 , typename argument_type1 >
  typename write_spk_data_fake::type<argument_type0, argument_type1>::result_type write_spk_data_fake::operator()(argument_type0&& t, argument_type1&& k) const
  {
    return pythonic::builtins::None;
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename save_spk_data::type<argument_type0, argument_type1, argument_type2>::result_type save_spk_data::operator()(argument_type0&& s, argument_type1&& t, argument_type2&& k) const
  {
    pythonic::builtins::list::functor::append{}(s, pythonic::types::make_tuple(t, k));
    return s;
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename save_spk_data_fake::type<argument_type0, argument_type1, argument_type2>::result_type save_spk_data_fake::operator()(argument_type0&& s, argument_type1&& t, argument_type2&& k) const
  {
    return s;
  }
  template <typename argument_type0 >
  typename PoissonProcess_firingprob::type<argument_type0>::result_type PoissonProcess_firingprob::operator()(argument_type0&& r) const
  {
    return pythonic::operator_::sub(1.0, pythonic::numpy::functor::exp{}(pythonic::operator_::neg(r)));
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 >
  typename PHI::type<argument_type0, argument_type1, argument_type2>::result_type PHI::operator()(argument_type0&& V, argument_type1&& theta, argument_type2&& Gamma) const
  {
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::add(theta, pythonic::operator_::div(1.0, Gamma)))>::type tg = pythonic::operator_::add(theta, pythonic::operator_::div(1.0, Gamma));
    return pythonic::operator_::add(pythonic::operator_::mul(pythonic::operator_::mul(pythonic::operator_::mul(Gamma, pythonic::operator_::sub(V, theta)), pythonic::builtins::functor::float_{}(pythonic::operator_::gt(V, theta))), pythonic::builtins::functor::float_{}(pythonic::operator_::lt(V, tg))), pythonic::builtins::functor::float_{}(pythonic::operator_::ge(V, tg)));
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 >
  typename weightAdapt_increase::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5>::result_type weightAdapt_increase::operator()(argument_type0&& W, argument_type1&& A, argument_type2&& tauWinv, argument_type3&& uW, argument_type4&& rhoE, argument_type5&& rhoI) const
  {
    return pythonic::operator_::add(pythonic::operator_::mul(W, pythonic::operator_::add(pythonic::operator_::sub(1.0, tauWinv), pythonic::operator_::mul(uW, rhoE))), pythonic::operator_::mul(tauWinv, A));
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 >
  typename weightAdapt_decrease::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5>::result_type weightAdapt_decrease::operator()(argument_type0&& W, argument_type1&& A, argument_type2&& tauWinv, argument_type3&& uW, argument_type4&& rhoE, argument_type5&& rhoI) const
  {
    return pythonic::operator_::add(pythonic::operator_::mul(W, pythonic::operator_::sub(pythonic::operator_::sub(1.0, tauWinv), pythonic::operator_::mul(uW, rhoI))), pythonic::operator_::mul(tauWinv, A));
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 >
  typename sumSynpaticInput_homog::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8>::result_type sumSynpaticInput_homog::operator()(argument_type0&& synapticInput, argument_type1&& K_ex, argument_type2&& K, argument_type3&& N, argument_type4&& XE, argument_type5&& XI, argument_type6&& J, argument_type7&& W, argument_type8&& C) const
  {
    typedef typename pythonic::assignable<double>::type __type0;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type1;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type2;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type3;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type4;
    typedef decltype(std::declval<__type3>()(std::declval<__type4>())) __type5;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type5>::type::iterator>::value_type>::type __type6;
    typedef decltype(std::declval<__type2>()[std::declval<__type6>()]) __type7;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type8;
    typedef decltype(std::declval<__type3>()(std::declval<__type8>())) __type9;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type9>::type::iterator>::value_type>::type __type10;
    typedef decltype(std::declval<__type7>()[std::declval<__type10>()]) __type11;
    typedef decltype(std::declval<__type1>()[std::declval<__type11>()]) __type12;
    typedef decltype(pythonic::operator_::add(std::declval<__type0>(), std::declval<__type12>())) __type13;
    typedef typename __combined<__type0,__type13>::type __type14;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type15;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type16;
    typedef decltype(std::declval<__type3>()(std::declval<__type8>(), std::declval<__type16>())) __type17;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type17>::type::iterator>::value_type>::type __type18;
    typedef decltype(std::declval<__type7>()[std::declval<__type18>()]) __type19;
    typedef decltype(std::declval<__type15>()[std::declval<__type19>()]) __type20;
    typedef decltype(pythonic::operator_::add(std::declval<__type0>(), std::declval<__type20>())) __type21;
    typedef typename __combined<__type0,__type21>::type __type22;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type17>::type::iterator>::value_type>::type>::type j_;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type5>::type::iterator>::value_type>::type>::type i;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type9>::type::iterator>::value_type>::type>::type j;
    {
      long  __target140219921844688 = N;
      for (long  i=0L; i < __target140219921844688; i += 1L)
      {
        typename pythonic::assignable<typename __combined<__type14,__type12>::type>::type sE = 0.0;
        typename pythonic::assignable<typename __combined<__type22,__type20>::type>::type sI = 0.0;
        {
          long  __target140219921874896 = K_ex;
          for (long  j=0L; j < __target140219921874896; j += 1L)
          {
            sE += XE[C.fast(i).fast(j)];
          }
        }
        {
          long  __target140219921891440 = K;
          for (long  j_=K_ex; j_ < __target140219921891440; j_ += 1L)
          {
            sI += XI[C.fast(i)[j_]];
          }
        }
        synapticInput.fast(i) = pythonic::operator_::div(pythonic::operator_::sub(pythonic::operator_::mul(J, sE), pythonic::operator_::mul(W, sI)), pythonic::builtins::functor::float_{}(K));
      }
    }
    return pythonic::builtins::None;
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 >
  typename sumSynpaticInput::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8>::result_type sumSynpaticInput::operator()(argument_type0&& synapticInput, argument_type1&& K_ex, argument_type2&& K, argument_type3&& N, argument_type4&& XE, argument_type5&& XI, argument_type6&& J, argument_type7&& W, argument_type8&& C) const
  {
    typedef typename pythonic::assignable<double>::type __type0;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type1;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type2;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type3;
    typedef decltype(std::declval<__type2>()(std::declval<__type3>())) __type4;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type4>::type::iterator>::value_type>::type __type5;
    typedef decltype(std::declval<__type1>()[std::declval<__type5>()]) __type6;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type7;
    typedef decltype(std::declval<__type2>()(std::declval<__type7>())) __type8;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type8>::type::iterator>::value_type>::type __type9;
    typedef decltype(std::declval<__type6>()[std::declval<__type9>()]) __type10;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type11;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type12;
    typedef decltype(std::declval<__type12>()[std::declval<__type5>()]) __type13;
    typedef decltype(std::declval<__type13>()[std::declval<__type9>()]) __type14;
    typedef decltype(std::declval<__type11>()[std::declval<__type14>()]) __type15;
    typedef decltype(pythonic::operator_::mul(std::declval<__type10>(), std::declval<__type15>())) __type16;
    typedef decltype(pythonic::operator_::add(std::declval<__type0>(), std::declval<__type16>())) __type17;
    typedef typename __combined<__type0,__type17>::type __type18;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type __type19;
    typedef decltype(std::declval<__type19>()[std::declval<__type5>()]) __type20;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type21;
    typedef decltype(std::declval<__type2>()(std::declval<__type7>(), std::declval<__type21>())) __type22;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type22>::type::iterator>::value_type>::type __type23;
    typedef decltype(pythonic::operator_::sub(std::declval<__type23>(), std::declval<__type7>())) __type24;
    typedef decltype(std::declval<__type20>()[std::declval<__type24>()]) __type25;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type26;
    typedef decltype(std::declval<__type13>()[std::declval<__type23>()]) __type27;
    typedef decltype(std::declval<__type26>()[std::declval<__type27>()]) __type28;
    typedef decltype(pythonic::operator_::mul(std::declval<__type25>(), std::declval<__type28>())) __type29;
    typedef decltype(pythonic::operator_::sub(std::declval<__type18>(), std::declval<__type29>())) __type30;
    typedef typename __combined<__type18,__type30>::type __type31;
    typedef typename __combined<__type31,__type16>::type __type32;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type22>::type::iterator>::value_type>::type>::type j_;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type4>::type::iterator>::value_type>::type>::type i;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type8>::type::iterator>::value_type>::type>::type j;
    {
      long  __target140219921831104 = N;
      for (long  i=0L; i < __target140219921831104; i += 1L)
      {
        typename pythonic::assignable<typename __combined<__type32,__type29>::type>::type s = 0.0;
        {
          long  __target140219921844928 = K_ex;
          for (long  j=0L; j < __target140219921844928; j += 1L)
          {
            s += pythonic::operator_::mul(J.fast(i).fast(j), XE[C.fast(i).fast(j)]);
          }
        }
        {
          long  __target140219921845120 = K;
          for (long  j_=K_ex; j_ < __target140219921845120; j_ += 1L)
          {
            s -= pythonic::operator_::mul(W.fast(i)[pythonic::operator_::sub(j_, K_ex)], XI[C.fast(i)[j_]]);
          }
        }
        synapticInput.fast(i) = pythonic::operator_::div(s, pythonic::builtins::functor::float_{}(K));
      }
    }
    return pythonic::builtins::None;
  }
  template <typename argument_type0 , typename argument_type1 >
  typename get_param::type<argument_type0, argument_type1>::result_type get_param::operator()(argument_type0&& v, argument_type1&& vtype) const
  {
    typedef long __type0;
    typedef typename pythonic::lazy<__type0>::type __type1;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::int_{})>::type>::type __type2;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type3;
    typedef decltype(std::declval<__type2>()(std::declval<__type3>())) __type4;
    typedef typename pythonic::lazy<__type4>::type __type5;
    typedef typename __combined<__type1,__type5>::type __type6;
    typedef double __type7;
    typedef typename pythonic::lazy<__type7>::type __type8;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type9;
    typedef decltype(std::declval<__type9>()(std::declval<__type3>())) __type10;
    typedef typename pythonic::lazy<__type10>::type __type11;
    typedef typename __combined<__type8,__type11>::type __type12;
    typedef pythonic::types::str __type13;
    typedef typename pythonic::lazy<__type13>::type __type14;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::str{})>::type>::type __type15;
    typedef decltype(std::declval<__type15>()(std::declval<__type3>())) __type16;
    typedef typename pythonic::lazy<__type16>::type __type17;
    typedef typename __combined<__type14,__type17>::type __type18;
    typedef bool __type19;
    typedef typename pythonic::lazy<__type19>::type __type20;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::bool_{})>::type>::type __type21;
    typedef decltype(std::declval<__type21>()(std::declval<__type3>())) __type22;
    typedef typename pythonic::lazy<__type22>::type __type23;
    typedef typename __combined<__type20,__type23>::type __type24;
    typename pythonic::lazy<__type6>::type a = -1L;
    typename pythonic::lazy<__type12>::type b = pythonic::numpy::nan;
    typename pythonic::lazy<__type18>::type c = pythonic::types::str("");
    typename pythonic::lazy<__type24>::type d = pythonic::builtins::False;
    if (pythonic::operator_::eq(vtype, pythonic::types::str("int")))
    {
      a = pythonic::builtins::functor::int_{}(v);
    }
    else
    {
      if (pythonic::operator_::eq(vtype, pythonic::types::str("float")))
      {
        b = pythonic::builtins::functor::float_{}(v);
      }
      else
      {
        if (pythonic::operator_::eq(vtype, pythonic::types::str("str")))
        {
          c = pythonic::builtins::functor::str{}(v);
        }
        else
        {
          if (pythonic::operator_::eq(vtype, pythonic::types::str("bool")))
          {
            d = pythonic::builtins::functor::bool_{}(v);
          }
          else
          {
            throw pythonic::builtins::functor::ValueError{}(pythonic::types::str("unknown type for v"));
          }
        }
      }
    }
    return pythonic::types::make_tuple(a, b, c, d);
  }
  template <typename argument_type0 , typename argument_type1 >
  typename multvecelem::type<argument_type0, argument_type1>::result_type multvecelem::operator()(argument_type0&& x, argument_type1&& y) const
  {
    return pythonic::builtins::functor::list{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(multvecelem_lambda21(), x), pythonic::builtins::functor::enumerate{}(y)));
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 >
  typename GLNetEIMF_iter::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13>::result_type GLNetEIMF_iter::operator()(argument_type0&& V, argument_type1&& X, argument_type2&& rhoE, argument_type3&& rhoI, argument_type4&& Iext, argument_type5&& mu, argument_type6&& theta, argument_type7&& J, argument_type8&& Gamma, argument_type9&& I, argument_type10&& g, argument_type11&& p, argument_type12&& q, argument_type13&& P_poisson) const
  {
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::mul(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::mul(mu, V), I), Iext), pythonic::operator_::mul(J, pythonic::operator_::sub(pythonic::operator_::mul(p, rhoE), pythonic::operator_::mul(pythonic::operator_::mul(q, g), rhoI)))), pythonic::operator_::sub(1.0, X)))>::type V__ = pythonic::operator_::mul(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::mul(mu, V), I), Iext), pythonic::operator_::mul(J, pythonic::operator_::sub(pythonic::operator_::mul(p, rhoE), pythonic::operator_::mul(pythonic::operator_::mul(q, g), rhoI)))), pythonic::operator_::sub(1.0, X));
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::float_{}(pythonic::operator_::lt(pythonic::random::functor::random{}(), pythonic::operator_::add(pythonic::operator_::mul(PHI()(V__, theta, Gamma), pythonic::operator_::sub(1.0, P_poisson)), P_poisson))))>::type X__ = pythonic::builtins::functor::float_{}(pythonic::operator_::lt(pythonic::random::functor::random{}(), pythonic::operator_::add(pythonic::operator_::mul(PHI()(V__, theta, Gamma), pythonic::operator_::sub(1.0, P_poisson)), P_poisson)));
    return pythonic::types::make_tuple(V__, X__, theta);
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 >
  typename GLNetEIMF_adaptthresh_iter::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13, argument_type14, argument_type15>::result_type GLNetEIMF_adaptthresh_iter::operator()(argument_type0&& V, argument_type1&& X, argument_type2&& rhoE, argument_type3&& rhoI, argument_type4&& Iext, argument_type5&& mu, argument_type6&& theta, argument_type7&& J, argument_type8&& Gamma, argument_type9&& I, argument_type10&& W_I, argument_type11&& p, argument_type12&& q, argument_type13&& tauTinv, argument_type14&& uT, argument_type15&& P_poisson) const
  {
    typename pythonic::assignable_noescape<decltype(X)>::type X_ = X;
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::mul(theta, pythonic::operator_::add(pythonic::operator_::sub(1.0, tauTinv), pythonic::operator_::mul(uT, X_))))>::type theta__ = pythonic::operator_::mul(theta, pythonic::operator_::add(pythonic::operator_::sub(1.0, tauTinv), pythonic::operator_::mul(uT, X_)));
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::mul(pythonic::operator_::sub(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::mul(mu, V), I), Iext), pythonic::operator_::mul(pythonic::operator_::mul(J, p), rhoE)), pythonic::operator_::mul(pythonic::operator_::mul(q, W_I), rhoI)), pythonic::operator_::sub(1.0, X_)))>::type V__ = pythonic::operator_::mul(pythonic::operator_::sub(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::mul(mu, V), I), Iext), pythonic::operator_::mul(pythonic::operator_::mul(J, p), rhoE)), pythonic::operator_::mul(pythonic::operator_::mul(q, W_I), rhoI)), pythonic::operator_::sub(1.0, X_));
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::float_{}(pythonic::operator_::lt(pythonic::random::functor::random{}(), pythonic::operator_::add(pythonic::operator_::mul(PHI()(V__, theta__, Gamma), pythonic::operator_::sub(1.0, P_poisson)), P_poisson))))>::type X__ = pythonic::builtins::functor::float_{}(pythonic::operator_::lt(pythonic::random::functor::random{}(), pythonic::operator_::add(pythonic::operator_::mul(PHI()(V__, theta__, Gamma), pythonic::operator_::sub(1.0, P_poisson)), P_poisson)));
    return pythonic::types::make_tuple(V__, X__, theta__);
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 >
  typename GLNetEIRand_iter::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8>::result_type GLNetEIRand_iter::operator()(argument_type0&& V, argument_type1&& X, argument_type2&& synapticInput, argument_type3&& Iext, argument_type4&& mu, argument_type5&& theta, argument_type6&& Gamma, argument_type7&& I, argument_type8&& P_poisson) const
  {
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::mul(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::mul(mu, V), I), Iext), synapticInput), pythonic::operator_::sub(1.0, X)))>::type V__ = pythonic::operator_::mul(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::mul(mu, V), I), Iext), synapticInput), pythonic::operator_::sub(1.0, X));
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::float_{}(pythonic::operator_::lt(pythonic::random::functor::random{}(), pythonic::operator_::add(pythonic::operator_::mul(PHI()(V__, theta, Gamma), pythonic::operator_::sub(1.0, P_poisson)), P_poisson))))>::type X__ = pythonic::builtins::functor::float_{}(pythonic::operator_::lt(pythonic::random::functor::random{}(), pythonic::operator_::add(pythonic::operator_::mul(PHI()(V__, theta, Gamma), pythonic::operator_::sub(1.0, P_poisson)), P_poisson)));
    return pythonic::types::make_tuple(V__, X__, theta);
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 >
  typename GLNetEIRand_adaptthresh_iter::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10>::result_type GLNetEIRand_adaptthresh_iter::operator()(argument_type0&& V, argument_type1&& X, argument_type2&& synapticInput, argument_type3&& Iext, argument_type4&& mu, argument_type5&& theta, argument_type6&& Gamma, argument_type7&& I, argument_type8&& tauTinv, argument_type9&& uT, argument_type10&& P_poisson) const
  {
    typename pythonic::assignable_noescape<decltype(X)>::type X_ = X;
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::mul(theta, pythonic::operator_::add(pythonic::operator_::sub(1.0, tauTinv), pythonic::operator_::mul(uT, X_))))>::type theta__ = pythonic::operator_::mul(theta, pythonic::operator_::add(pythonic::operator_::sub(1.0, tauTinv), pythonic::operator_::mul(uT, X_)));
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::mul(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::mul(mu, V), I), Iext), synapticInput), pythonic::operator_::sub(1.0, X_)))>::type V__ = pythonic::operator_::mul(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::add(pythonic::operator_::mul(mu, V), I), Iext), synapticInput), pythonic::operator_::sub(1.0, X_));
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::float_{}(pythonic::operator_::lt(pythonic::random::functor::random{}(), pythonic::operator_::add(pythonic::operator_::mul(PHI()(V__, theta__, Gamma), pythonic::operator_::sub(1.0, P_poisson)), P_poisson))))>::type X__ = pythonic::builtins::functor::float_{}(pythonic::operator_::lt(pythonic::random::functor::random{}(), pythonic::operator_::add(pythonic::operator_::mul(PHI()(V__, theta__, Gamma), pythonic::operator_::sub(1.0, P_poisson)), P_poisson)));
    return pythonic::types::make_tuple(V__, X__, theta__);
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 >
  typename generate_IC_spikes::type<argument_type0, argument_type1, argument_type2, argument_type3>::result_type generate_IC_spikes::operator()(argument_type0&& X0, argument_type1&& N, argument_type2&& K, argument_type3 is_random) const
  {
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::array{})>::type>::type __type0;
    typedef double __type1;
    typedef pythonic::types::list<typename std::remove_reference<__type1>::type> __type2;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::max{})>::type>::type __type3;
    typedef long __type4;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type5;
    typedef typename __combined<__type4,__type5>::type __type6;
    typedef decltype(std::declval<__type3>()(std::declval<__type6>(), std::declval<__type5>())) __type7;
    typedef decltype(pythonic::operator_::mul(std::declval<__type2>(), std::declval<__type7>())) __type8;
    typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type8>()))>::type __type9;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::random::functor::sample{})>::type>::type __type10;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type11;
    typedef decltype(std::declval<__type11>()(std::declval<__type5>())) __type12;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type13;
    typedef decltype(std::declval<__type10>()(std::declval<__type12>(), std::declval<__type13>())) __type14;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type14>::type::iterator>::value_type>::type __type15;
    typedef indexable<__type15> __type16;
    typedef typename __combined<__type9,__type16>::type __type17;
    typedef container<typename std::remove_reference<__type1>::type> __type18;
    typedef typename __combined<__type17,__type18>::type __type19;
    typedef typename __combined<__type19,__type16>::type __type20;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::map{})>::type>::type __type21;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::functools::functor::partial{})>::type>::type __type22;
    typedef generate_IC_spikes_lambda20 __type23;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type24;
    typedef decltype(std::declval<__type22>()(std::declval<__type23>(), std::declval<__type24>())) __type25;
    typedef decltype(std::declval<__type21>()(std::declval<__type25>(), std::declval<__type12>())) __type26;
    typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type26>()))>::type __type27;
    typename pythonic::assignable<typename __combined<__type20,__type27>::type>::type X;
    if (pythonic::builtins::pythran::and_([&] () { return pythonic::operator_::gt(X0, 0L); }, [&] () { return is_random; }))
    {
      X = pythonic::numpy::functor::array{}(pythonic::operator_::mul(typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<double>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(0.0)>::type>::type>::type>>::type>::type({0.0, pythonic::types::single_value()}), pythonic::builtins::functor::max{}(0L, N)));
      {
        for (auto&& k: pythonic::random::functor::sample{}(pythonic::builtins::functor::range{}(N), K))
        {
          X[k] = 1.0;
        }
      }
    }
    else
    {
      X = pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(generate_IC_spikes_lambda20(), X0), pythonic::builtins::functor::range{}(N)));
    }
    return X;
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 >
  typename save_initial_spkdata::type<argument_type0, argument_type1, argument_type2, argument_type3>::result_type save_initial_spkdata::operator()(argument_type0&& XE, argument_type1&& XI, argument_type2&& pN, argument_type3&& qN) const
  {
    typedef typename pythonic::assignable<pythonic::types::empty_list>::type __type0;
    typedef long __type1;
    typedef typename pythonic::assignable<long>::type __type2;
    typedef typename save_spk_data::type<__type0, __type1, __type2>::__ptype0 __type3;
    typedef pythonic::types::list<typename std::remove_reference<__type3>::type> __type4;
    typedef typename __combined<__type0,__type4>::type __type5;
    typedef typename save_spk_data::type<__type5, __type1, __type2>::__ptype1 __type6;
    typedef pythonic::types::list<typename std::remove_reference<__type6>::type> __type7;
    typedef typename __combined<__type5,__type7>::type __type8;
    typedef save_spk_data __type9;
    typedef decltype(std::declval<__type9>()(std::declval<__type8>(), std::declval<__type1>(), std::declval<__type2>())) __type10;
    typedef typename __combined<__type8,__type10>::type __type11;
    typedef typename __combined<__type4,__type7>::type __type12;
    typedef typename pythonic::assignable<typename __combined<__type12,__type10>::type>::type __type13;
    typedef typename __combined<__type11,__type13>::type __type14;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type15;
    typedef decltype(pythonic::operator_::add(std::declval<__type2>(), std::declval<__type15>())) __type16;
    typedef typename save_spk_data::type<__type14, __type1, __type16>::__ptype0 __type17;
    typedef pythonic::types::list<typename std::remove_reference<__type17>::type> __type18;
    typedef typename __combined<__type11,__type18>::type __type19;
    typedef typename __combined<__type14,__type18>::type __type20;
    typedef typename save_spk_data::type<__type20, __type1, __type16>::__ptype1 __type21;
    typedef pythonic::types::list<typename std::remove_reference<__type21>::type> __type22;
    typedef typename __combined<__type19,__type22>::type __type23;
    typedef typename __combined<__type20,__type22>::type __type24;
    typedef decltype(std::declval<__type9>()(std::declval<__type24>(), std::declval<__type1>(), std::declval<__type16>())) __type25;
    typedef typename __combined<__type23,__type25>::type __type26;
    typedef typename __combined<__type26,__type8>::type __type27;
    typedef typename __combined<__type13,__type18>::type __type28;
    typedef typename __combined<__type28,__type22>::type __type29;
    typedef typename __combined<__type29,__type25>::type __type30;
    typedef typename __combined<__type27,__type30>::type __type31;
    typedef typename __combined<__type31,__type24>::type __type32;
    typedef typename __combined<__type18,__type22>::type __type33;
    typedef typename pythonic::assignable<typename __combined<__type33,__type25>::type>::type __type34;
    typedef decltype(pythonic::operator_::add(std::declval<__type2>(), std::declval<__type1>())) __type35;
    typedef typename __combined<__type2,__type35>::type __type36;
    typename pythonic::assignable<typename __combined<__type32,__type34>::type>::type spkData = pythonic::types::empty_list(pythonic::types::empty_list());
    typename pythonic::assignable<typename __combined<__type36,__type1>::type>::type i = 0L;
    while (pythonic::operator_::lt(i, pN))
    {
      if (pythonic::operator_::eq(XE.fast(i), 1L))
      {
        spkData = save_spk_data()(spkData, 0L, i);
      }
      i += 1L;
    }
    typename pythonic::assignable<typename __combined<__type36,__type1>::type>::type i_ = 0L;
    while (pythonic::operator_::lt(i_, qN))
    {
      if (pythonic::operator_::eq(XI.fast(i_), 1L))
      {
        spkData = save_spk_data()(spkData, 0L, pythonic::operator_::add(i_, pN));
      }
      i_ += 1L;
    }
    return spkData;
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 >
  typename generate_random_net_fixed_input::type<argument_type0, argument_type1, argument_type2, argument_type3>::result_type generate_random_net_fixed_input::operator()(argument_type0&& K_ex, argument_type1&& pN, argument_type2&& K, argument_type3&& N) const
  {
    return pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(generate_random_net_fixed_input_lambda15(), K, K_ex, N, pN), pythonic::builtins::functor::range{}(N)));
  }
  template <typename argument_type0 , typename argument_type1 >
  typename get_system_parameters::type<argument_type0, argument_type1>::result_type get_system_parameters::operator()(argument_type0&& simParam_dict, argument_type1&& paramType_dict) const
  {
    pythonic::builtins::functor::print{}(pythonic::types::str(" ... forcing the CV of all parameters to be zero (homogeneous network), since parameter variability is not implemented yet"));
    return pythonic::types::make_tuple(std::get<0>(get_param()(simParam_dict[pythonic::types::str("N")], paramType_dict[pythonic::types::str("N")])), std::get<0>(get_param()(simParam_dict[pythonic::types::str("tTrans")], paramType_dict[pythonic::types::str("tTrans")])), std::get<0>(get_param()(simParam_dict[pythonic::types::str("Tmax")], paramType_dict[pythonic::types::str("Tmax")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("VE0")], paramType_dict[pythonic::types::str("VE0")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("VE0Std")], paramType_dict[pythonic::types::str("VE0Std")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("VI0")], paramType_dict[pythonic::types::str("VI0")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("VI0Std")], paramType_dict[pythonic::types::str("VI0Std")])), std::get<0>(get_param()(simParam_dict[pythonic::types::str("XE0")], paramType_dict[pythonic::types::str("XE0")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("fXE0")], paramType_dict[pythonic::types::str("fXE0")])), std::get<3>(get_param()(simParam_dict[pythonic::types::str("XE0Rand")], paramType_dict[pythonic::types::str("XE0Rand")])), std::get<0>(get_param()(simParam_dict[pythonic::types::str("XI0")], paramType_dict[pythonic::types::str("XI0")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("fXI0")], paramType_dict[pythonic::types::str("fXI0")])), std::get<3>(get_param()(simParam_dict[pythonic::types::str("XI0Rand")], paramType_dict[pythonic::types::str("XI0Rand")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("mu")], paramType_dict[pythonic::types::str("mu")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("theta")], paramType_dict[pythonic::types::str("theta")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("J")], paramType_dict[pythonic::types::str("J")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("Gamma")], paramType_dict[pythonic::types::str("Gamma")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("I")], paramType_dict[pythonic::types::str("I")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("Iext")], paramType_dict[pythonic::types::str("Iext")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("g")], paramType_dict[pythonic::types::str("g")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("p")], paramType_dict[pythonic::types::str("p")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("q")], paramType_dict[pythonic::types::str("q")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("A")], paramType_dict[pythonic::types::str("A")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("tauW")], paramType_dict[pythonic::types::str("tauW")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("uW")], paramType_dict[pythonic::types::str("uW")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("tauT")], paramType_dict[pythonic::types::str("tauT")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("uT")], paramType_dict[pythonic::types::str("uT")])), std::get<3>(get_param()(simParam_dict[pythonic::types::str("saveSpikingData")], paramType_dict[pythonic::types::str("saveSpikingData")])), std::get<0>(get_param()(simParam_dict[pythonic::types::str("nNeuronsSpk")], paramType_dict[pythonic::types::str("nNeuronsSpk")])), std::get<2>(get_param()(simParam_dict[pythonic::types::str("weightDynType")], paramType_dict[pythonic::types::str("weightDynType")])), std::get<1>(get_param()(simParam_dict[pythonic::types::str("rPoisson")], paramType_dict[pythonic::types::str("rPoisson")])), std::get<0>(get_param()(simParam_dict[pythonic::types::str("K")], paramType_dict[pythonic::types::str("K")])), 0.0, std::get<3>(get_param()(simParam_dict[pythonic::types::str("writeOnRun")], paramType_dict[pythonic::types::str("writeOnRun")])), std::get<2>(get_param()(simParam_dict[pythonic::types::str("spkFileName")], paramType_dict[pythonic::types::str("spkFileName")])));
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 , typename argument_type16 , typename argument_type17 , typename argument_type18 , typename argument_type19 , typename argument_type20 >
  typename run_transient_GLNetEIMF_static::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13, argument_type14, argument_type15, argument_type16, argument_type17, argument_type18, argument_type19, argument_type20>::result_type run_transient_GLNetEIMF_static::operator()(argument_type0&& VE, argument_type1&& XE, argument_type2&& VI, argument_type3&& XI, argument_type4&& rhoETemp, argument_type5&& rhoITemp, argument_type6&& pN, argument_type7&& qN, argument_type8&& pN_fl, argument_type9&& qN_fl, argument_type10&& P_firing_poisson, argument_type11&& tTrans, argument_type12&& Iext, argument_type13&& mu, argument_type14&& theta, argument_type15&& J, argument_type16&& Gamma, argument_type17&& I, argument_type18&& g, argument_type19&& p, argument_type20&& q) const
  {
    typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type>::type __type0;
    typedef double __type1;
    typedef typename pythonic::lazy<__type1>::type __type2;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type3;
    typedef GLNetEIMF_iter __type4;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type5;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type6;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type7;
    typedef decltype(std::declval<__type6>()(std::declval<__type7>())) __type8;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type8>::type::iterator>::value_type>::type __type9;
    typedef decltype(std::declval<__type5>()[std::declval<__type9>()]) __type10;
    typedef decltype(std::declval<__type3>()[std::declval<__type9>()]) __type11;
    typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type>::type __type12;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type12>::type>::type __type13;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type13>::type>::type __type14;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type14>::type>::type __type15;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type15>::type>::type __type16;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type16>::type>::type __type17;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type17>::type>::type __type18;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type18>::type>::type __type19;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type19>::type>::type __type20;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type20>::type>::type __type21;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type10>::type>::type __type22;
    typedef typename pythonic::assignable<decltype(std::declval<__type4>()(std::declval<__type10>(), std::declval<__type11>(), std::declval<__type0>(), std::declval<__type12>(), std::declval<__type13>(), std::declval<__type14>(), std::declval<__type15>(), std::declval<__type16>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type22>()))>::type __type23;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type23>::type>::type __type24;
    typedef container<typename std::remove_reference<__type24>::type> __type25;
    typedef typename __combined<__type3,__type25>::type __type26;
    typedef indexable<__type9> __type27;
    typedef typename __combined<__type26,__type27>::type __type28;
    typedef decltype(std::declval<__type28>()[std::declval<__type9>()]) __type29;
    typedef decltype(pythonic::operator_::add(std::declval<__type2>(), std::declval<__type29>())) __type30;
    typedef typename pythonic::lazy<__type30>::type __type31;
    typedef typename __combined<__type2,__type31>::type __type32;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type33;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type32>(), std::declval<__type33>()))>::type __type34;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type35;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type36;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type __type37;
    typedef decltype(std::declval<__type6>()(std::declval<__type37>())) __type38;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type38>::type::iterator>::value_type>::type __type39;
    typedef decltype(std::declval<__type36>()[std::declval<__type39>()]) __type40;
    typedef decltype(std::declval<__type35>()[std::declval<__type39>()]) __type41;
    typedef typename pythonic::assignable<decltype(std::declval<__type4>()(std::declval<__type40>(), std::declval<__type41>(), std::declval<__type0>(), std::declval<__type12>(), std::declval<__type13>(), std::declval<__type14>(), std::declval<__type15>(), std::declval<__type16>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type1>()))>::type __type42;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type42>::type>::type __type43;
    typedef container<typename std::remove_reference<__type43>::type> __type44;
    typedef typename __combined<__type35,__type44>::type __type45;
    typedef indexable<__type39> __type46;
    typedef typename __combined<__type45,__type46>::type __type47;
    typedef decltype(std::declval<__type47>()[std::declval<__type39>()]) __type48;
    typedef decltype(pythonic::operator_::add(std::declval<__type2>(), std::declval<__type48>())) __type49;
    typedef typename pythonic::lazy<__type49>::type __type50;
    typedef typename __combined<__type2,__type50>::type __type51;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type9>::type>::type __type52;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type51>(), std::declval<__type52>()))>::type __type53;
    typedef long __type54;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type11>::type>::type __type55;
    typedef decltype(std::declval<__type6>()(std::declval<__type54>(), std::declval<__type55>())) __type56;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type56>::type::iterator>::value_type>::type>::type t;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type38>::type::iterator>::value_type>::type>::type i_;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type8>::type::iterator>::value_type>::type>::type i;
    typename pythonic::assignable<typename __combined<__type0,__type34>::type>::type rhoE_prev = rhoETemp;
    typename pythonic::assignable<typename __combined<__type12,__type53>::type>::type rhoI_prev = rhoITemp;
    {
      long  __target140219921672560 = tTrans;
      for (long  t=1L; t < __target140219921672560; t += 1L)
      {
        typename pythonic::lazy<__type32>::type sum_XE = 0.0;
        {
          long  __target140219921673760 = pN;
          for (long  i=0L; i < __target140219921673760; i += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_iter()(VE[i], XE[i], rhoE_prev, rhoI_prev, Iext, mu, theta, J, Gamma, I, g, p, q, P_firing_poisson))>::type __tuple0 = GLNetEIMF_iter()(VE[i], XE[i], rhoE_prev, rhoI_prev, Iext, mu, theta, J, Gamma, I, g, p, q, P_firing_poisson);
            VE.fast(i) = std::get<0>(__tuple0);
            XE.fast(i) = std::get<1>(__tuple0);
            sum_XE = pythonic::operator_::add(sum_XE, XE.fast(i));
          }
        }
        typename pythonic::lazy<__type51>::type sum_XI = 0.0;
        {
          long  __target140219921674096 = qN;
          for (long  i_=0L; i_ < __target140219921674096; i_ += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_iter()(VI[i_], XI[i_], rhoE_prev, rhoI_prev, Iext, mu, theta, J, Gamma, I, g, p, q, 0.0))>::type __tuple1 = GLNetEIMF_iter()(VI[i_], XI[i_], rhoE_prev, rhoI_prev, Iext, mu, theta, J, Gamma, I, g, p, q, 0.0);
            VI.fast(i_) = std::get<0>(__tuple1);
            XI.fast(i_) = std::get<1>(__tuple1);
            sum_XI = pythonic::operator_::add(sum_XI, XI.fast(i_));
          }
        }
        rhoE_prev = pythonic::operator_::div(sum_XE, pN_fl);
        rhoI_prev = pythonic::operator_::div(sum_XI, qN_fl);
      }
    }
    return pythonic::types::make_tuple(rhoE_prev, rhoI_prev, VE, XE, VI, XI);
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 , typename argument_type16 , typename argument_type17 , typename argument_type18 , typename argument_type19 , typename argument_type20 >
  typename run_transient_GLNetEIMF_aval::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13, argument_type14, argument_type15, argument_type16, argument_type17, argument_type18, argument_type19, argument_type20>::result_type run_transient_GLNetEIMF_aval::operator()(argument_type0&& VE, argument_type1&& XE, argument_type2&& VI, argument_type3&& XI, argument_type4&& rhoETemp, argument_type5&& rhoITemp, argument_type6&& pN, argument_type7&& qN, argument_type8&& pN_fl, argument_type9&& qN_fl, argument_type10&& P_firing_poisson, argument_type11&& tTrans, argument_type12&& Iext, argument_type13&& mu, argument_type14&& theta, argument_type15&& J, argument_type16&& Gamma, argument_type17&& I, argument_type18&& g, argument_type19&& p, argument_type20&& q) const
  {
    typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type>::type __type0;
    typedef double __type1;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type2;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type1>(), std::declval<__type2>()))>::type __type3;
    typedef typename __combined<__type0,__type3>::type __type4;
    typedef typename pythonic::lazy<__type1>::type __type5;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type6;
    typedef long __type7;
    typedef container<typename std::remove_reference<__type7>::type> __type8;
    typedef typename __combined<__type6,__type8>::type __type9;
    typedef indexable<__type7> __type10;
    typedef typename __combined<__type9,__type10>::type __type11;
    typedef GLNetEIMF_iter __type12;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type13;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type14;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type15;
    typedef decltype(std::declval<__type14>()(std::declval<__type15>())) __type16;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type16>::type::iterator>::value_type>::type __type17;
    typedef decltype(std::declval<__type13>()[std::declval<__type17>()]) __type18;
    typedef decltype(std::declval<__type11>()[std::declval<__type17>()]) __type19;
    typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type>::type __type20;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type12>::type>::type __type21;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type13>::type>::type __type22;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type14>::type>::type __type23;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type15>::type>::type __type24;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type16>::type>::type __type25;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type17>::type>::type __type26;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type18>::type>::type __type27;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type19>::type>::type __type28;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type20>::type>::type __type29;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type10>::type>::type __type30;
    typedef typename pythonic::assignable<decltype(std::declval<__type12>()(std::declval<__type18>(), std::declval<__type19>(), std::declval<__type4>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type22>(), std::declval<__type23>(), std::declval<__type24>(), std::declval<__type25>(), std::declval<__type26>(), std::declval<__type27>(), std::declval<__type28>(), std::declval<__type29>(), std::declval<__type30>()))>::type __type31;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type31>::type>::type __type32;
    typedef container<typename std::remove_reference<__type32>::type> __type33;
    typedef typename __combined<__type11,__type33>::type __type34;
    typedef indexable<__type17> __type35;
    typedef typename __combined<__type34,__type35>::type __type36;
    typedef decltype(std::declval<__type36>()[std::declval<__type17>()]) __type37;
    typedef decltype(pythonic::operator_::add(std::declval<__type5>(), std::declval<__type37>())) __type38;
    typedef typename pythonic::lazy<__type38>::type __type39;
    typedef typename __combined<__type5,__type39>::type __type40;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type40>(), std::declval<__type2>()))>::type __type41;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type42;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type43;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type __type44;
    typedef decltype(std::declval<__type14>()(std::declval<__type44>())) __type45;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type45>::type::iterator>::value_type>::type __type46;
    typedef decltype(std::declval<__type43>()[std::declval<__type46>()]) __type47;
    typedef decltype(std::declval<__type42>()[std::declval<__type46>()]) __type48;
    typedef typename pythonic::assignable<decltype(std::declval<__type12>()(std::declval<__type47>(), std::declval<__type48>(), std::declval<__type4>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type22>(), std::declval<__type23>(), std::declval<__type24>(), std::declval<__type25>(), std::declval<__type26>(), std::declval<__type27>(), std::declval<__type28>(), std::declval<__type29>(), std::declval<__type1>()))>::type __type49;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type49>::type>::type __type50;
    typedef container<typename std::remove_reference<__type50>::type> __type51;
    typedef typename __combined<__type42,__type51>::type __type52;
    typedef indexable<__type46> __type53;
    typedef typename __combined<__type52,__type53>::type __type54;
    typedef decltype(std::declval<__type54>()[std::declval<__type46>()]) __type55;
    typedef decltype(pythonic::operator_::add(std::declval<__type5>(), std::declval<__type55>())) __type56;
    typedef typename pythonic::lazy<__type56>::type __type57;
    typedef typename __combined<__type5,__type57>::type __type58;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type9>::type>::type __type59;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type58>(), std::declval<__type59>()))>::type __type60;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type11>::type>::type __type61;
    typedef decltype(std::declval<__type14>()(std::declval<__type7>(), std::declval<__type61>())) __type62;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type62>::type::iterator>::value_type>::type>::type t;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type45>::type::iterator>::value_type>::type>::type i_;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type16>::type::iterator>::value_type>::type>::type i;
    typename pythonic::assignable<typename __combined<__type4,__type41>::type>::type rhoE_prev = rhoETemp;
    typename pythonic::assignable<typename __combined<__type20,__type60>::type>::type rhoI_prev = rhoITemp;
    {
      long  __target140219921535760 = tTrans;
      for (long  t=1L; t < __target140219921535760; t += 1L)
      {
        if (pythonic::operator_::lt(pythonic::operator_::add(rhoE_prev, rhoI_prev), 1e-16))
        {
          std::get<0>(XE) = 1L;
          rhoE_prev = pythonic::operator_::div(1.0, pN_fl);
        }
        typename pythonic::lazy<__type40>::type sum_XE = 0.0;
        {
          long  __target140219921537200 = pN;
          for (long  i=0L; i < __target140219921537200; i += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_iter()(VE[i], XE[i], rhoE_prev, rhoI_prev, Iext, mu, theta, J, Gamma, I, g, p, q, P_firing_poisson))>::type __tuple0 = GLNetEIMF_iter()(VE[i], XE[i], rhoE_prev, rhoI_prev, Iext, mu, theta, J, Gamma, I, g, p, q, P_firing_poisson);
            VE.fast(i) = std::get<0>(__tuple0);
            XE.fast(i) = std::get<1>(__tuple0);
            sum_XE = pythonic::operator_::add(sum_XE, XE.fast(i));
          }
        }
        typename pythonic::lazy<__type58>::type sum_XI = 0.0;
        {
          long  __target140219921538064 = qN;
          for (long  i_=0L; i_ < __target140219921538064; i_ += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_iter()(VI[i_], XI[i_], rhoE_prev, rhoI_prev, Iext, mu, theta, J, Gamma, I, g, p, q, 0.0))>::type __tuple1 = GLNetEIMF_iter()(VI[i_], XI[i_], rhoE_prev, rhoI_prev, Iext, mu, theta, J, Gamma, I, g, p, q, 0.0);
            VI.fast(i_) = std::get<0>(__tuple1);
            XI.fast(i_) = std::get<1>(__tuple1);
            sum_XI = pythonic::operator_::add(sum_XI, XI.fast(i_));
          }
        }
        rhoE_prev = pythonic::operator_::div(sum_XE, pN_fl);
        rhoI_prev = pythonic::operator_::div(sum_XI, qN_fl);
      }
    }
    return pythonic::types::make_tuple(rhoE_prev, rhoI_prev, VE, XE, VI, XI);
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 , typename argument_type16 , typename argument_type17 , typename argument_type18 , typename argument_type19 , typename argument_type20 , typename argument_type21 , typename argument_type22 , typename argument_type23 , typename argument_type24 , typename argument_type25 >
  typename run_transient_GLNetEIMF_adaptthresh::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13, argument_type14, argument_type15, argument_type16, argument_type17, argument_type18, argument_type19, argument_type20, argument_type21, argument_type22, argument_type23, argument_type24, argument_type25>::result_type run_transient_GLNetEIMF_adaptthresh::operator()(argument_type0&& VE, argument_type1&& XE, argument_type2&& VI, argument_type3&& XI, argument_type4&& thetaE, argument_type5&& thetaI, argument_type6&& rhoETemp, argument_type7&& rhoITemp, argument_type8&& N_fl, argument_type9&& pN, argument_type10&& qN, argument_type11&& pN_fl, argument_type12&& qN_fl, argument_type13&& gJ, argument_type14&& P_firing_poisson, argument_type15&& weightDynType, argument_type16&& tTrans, argument_type17&& Iext, argument_type18&& mu, argument_type19&& J, argument_type20&& Gamma, argument_type21&& I, argument_type22&& p, argument_type23&& q, argument_type24&& tauTinv, argument_type25&& uT) const
  {
    typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type>::type __type0;
    typedef double __type1;
    typedef typename pythonic::lazy<__type1>::type __type2;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type3;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type4;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type5;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type9>::type>::type __type6;
    typedef decltype(std::declval<__type5>()(std::declval<__type6>())) __type7;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type7>::type::iterator>::value_type>::type __type8;
    typedef decltype(std::declval<__type4>()[std::declval<__type8>()]) __type9;
    typedef decltype(std::declval<__type3>()[std::declval<__type8>()]) __type10;
    typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type>::type __type11;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type17>::type>::type __type12;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type18>::type>::type __type13;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type14;
    typedef decltype(std::declval<__type14>()[std::declval<__type8>()]) __type15;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type19>::type>::type __type16;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type20>::type>::type __type17;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type21>::type>::type __type18;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type13>::type>::type __type19;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type22>::type>::type __type20;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type23>::type>::type __type21;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type24>::type>::type __type22;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type25>::type>::type __type23;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type14>::type>::type __type24;
    typedef typename GLNetEIMF_adaptthresh_iter::type<__type9, __type10, __type0, __type11, __type12, __type13, __type15, __type16, __type17, __type18, __type19, __type20, __type21, __type22, __type23, __type24>::__ptype10 __type25;
    typedef container<typename std::remove_reference<__type25>::type> __type26;
    typedef typename __combined<__type3,__type26>::type __type27;
    typedef GLNetEIMF_adaptthresh_iter __type28;
    typedef typename pythonic::assignable<decltype(std::declval<__type28>()(std::declval<__type9>(), std::declval<__type10>(), std::declval<__type0>(), std::declval<__type11>(), std::declval<__type12>(), std::declval<__type13>(), std::declval<__type15>(), std::declval<__type16>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type22>(), std::declval<__type23>(), std::declval<__type24>()))>::type __type29;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type29>::type>::type __type30;
    typedef container<typename std::remove_reference<__type30>::type> __type31;
    typedef typename __combined<__type27,__type31>::type __type32;
    typedef indexable<__type8> __type33;
    typedef typename __combined<__type32,__type33>::type __type34;
    typedef decltype(std::declval<__type34>()[std::declval<__type8>()]) __type35;
    typedef decltype(pythonic::operator_::add(std::declval<__type2>(), std::declval<__type35>())) __type36;
    typedef typename pythonic::lazy<__type36>::type __type37;
    typedef typename __combined<__type2,__type37>::type __type38;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type11>::type>::type __type39;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type38>(), std::declval<__type39>()))>::type __type40;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type41;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type42;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type10>::type>::type __type43;
    typedef decltype(std::declval<__type5>()(std::declval<__type43>())) __type44;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type44>::type::iterator>::value_type>::type __type45;
    typedef decltype(std::declval<__type42>()[std::declval<__type45>()]) __type46;
    typedef decltype(std::declval<__type41>()[std::declval<__type45>()]) __type47;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type48;
    typedef decltype(std::declval<__type48>()[std::declval<__type45>()]) __type49;
    typedef typename GLNetEIMF_adaptthresh_iter::type<__type46, __type47, __type0, __type11, __type12, __type13, __type49, __type16, __type17, __type18, __type19, __type20, __type21, __type22, __type23, __type1>::__ptype10 __type50;
    typedef container<typename std::remove_reference<__type50>::type> __type51;
    typedef typename __combined<__type41,__type51>::type __type52;
    typedef typename pythonic::assignable<decltype(std::declval<__type28>()(std::declval<__type46>(), std::declval<__type47>(), std::declval<__type0>(), std::declval<__type11>(), std::declval<__type12>(), std::declval<__type13>(), std::declval<__type49>(), std::declval<__type16>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type22>(), std::declval<__type23>(), std::declval<__type1>()))>::type __type53;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type53>::type>::type __type54;
    typedef container<typename std::remove_reference<__type54>::type> __type55;
    typedef typename __combined<__type52,__type55>::type __type56;
    typedef indexable<__type45> __type57;
    typedef typename __combined<__type56,__type57>::type __type58;
    typedef decltype(std::declval<__type58>()[std::declval<__type45>()]) __type59;
    typedef decltype(pythonic::operator_::add(std::declval<__type2>(), std::declval<__type59>())) __type60;
    typedef typename pythonic::lazy<__type60>::type __type61;
    typedef typename __combined<__type2,__type61>::type __type62;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type12>::type>::type __type63;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type62>(), std::declval<__type63>()))>::type __type64;
    typedef typename pythonic::assignable<double>::type __type65;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type29>::type>::type __type66;
    typedef container<typename std::remove_reference<__type66>::type> __type67;
    typedef typename __combined<__type14,__type67>::type __type68;
    typedef typename __combined<__type68,__type33>::type __type69;
    typedef decltype(std::declval<__type69>()[std::declval<__type8>()]) __type70;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::add(std::declval<__type65>(), std::declval<__type70>()))>::type __type71;
    typedef typename __combined<__type65,__type71>::type __type72;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type53>::type>::type __type73;
    typedef container<typename std::remove_reference<__type73>::type> __type74;
    typedef typename __combined<__type48,__type74>::type __type75;
    typedef typename __combined<__type75,__type57>::type __type76;
    typedef decltype(std::declval<__type76>()[std::declval<__type45>()]) __type77;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::add(std::declval<__type72>(), std::declval<__type77>()))>::type __type78;
    typedef long __type79;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type16>::type>::type __type80;
    typedef decltype(std::declval<__type5>()(std::declval<__type79>(), std::declval<__type80>())) __type81;
    typedef typename __combined<__type72,__type78>::type __type82;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type83;
    typedef decltype(pythonic::operator_::div(std::declval<__type82>(), std::declval<__type83>())) __type84;
    typedef typename pythonic::lazy<__type84>::type __type85;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type81>::type::iterator>::value_type>::type>::type t;
    typename pythonic::lazy<__type85>::type thetaMean_;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type44>::type::iterator>::value_type>::type>::type i_;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type7>::type::iterator>::value_type>::type>::type i;
    typename pythonic::assignable<typename __combined<__type0,__type40>::type>::type rhoE_prev = rhoETemp;
    typename pythonic::assignable<typename __combined<__type11,__type64>::type>::type rhoI_prev = rhoITemp;
    {
      long  __target140219921974416 = tTrans;
      for (long  t=1L; t < __target140219921974416; t += 1L)
      {
        typename pythonic::lazy<__type38>::type sum_XE = 0.0;
        typename pythonic::lazy<__type62>::type sum_XI = 0.0;
        typename pythonic::assignable<typename __combined<__type72,__type78>::type>::type thetaMean = 0.0;
        {
          long  __target140219921977296 = pN;
          for (long  i=0L; i < __target140219921977296; i += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_adaptthresh_iter()(VE[i], XE[i], rhoE_prev, rhoI_prev, Iext, mu, thetaE[i], J, Gamma, I, gJ, p, q, tauTinv, uT, P_firing_poisson))>::type __tuple0 = GLNetEIMF_adaptthresh_iter()(VE[i], XE[i], rhoE_prev, rhoI_prev, Iext, mu, thetaE[i], J, Gamma, I, gJ, p, q, tauTinv, uT, P_firing_poisson);
            VE.fast(i) = std::get<0>(__tuple0);
            XE.fast(i) = std::get<1>(__tuple0);
            thetaE.fast(i) = std::get<2>(__tuple0);
            sum_XE = pythonic::operator_::add(sum_XE, XE.fast(i));
            thetaMean = pythonic::operator_::add(thetaMean, thetaE.fast(i));
          }
        }
        {
          long  __target140219921985792 = qN;
          for (long  i_=0L; i_ < __target140219921985792; i_ += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_adaptthresh_iter()(VI[i_], XI[i_], rhoE_prev, rhoI_prev, Iext, mu, thetaI[i_], J, Gamma, I, gJ, p, q, tauTinv, uT, 0.0))>::type __tuple1 = GLNetEIMF_adaptthresh_iter()(VI[i_], XI[i_], rhoE_prev, rhoI_prev, Iext, mu, thetaI[i_], J, Gamma, I, gJ, p, q, tauTinv, uT, 0.0);
            VI.fast(i_) = std::get<0>(__tuple1);
            XI.fast(i_) = std::get<1>(__tuple1);
            thetaI.fast(i_) = std::get<2>(__tuple1);
            sum_XI = pythonic::operator_::add(sum_XI, XI.fast(i_));
            thetaMean = pythonic::operator_::add(thetaMean, thetaI.fast(i_));
          }
        }
        rhoE_prev = pythonic::operator_::div(sum_XE, pN_fl);
        rhoI_prev = pythonic::operator_::div(sum_XI, qN_fl);
        thetaMean_ = pythonic::operator_::div(thetaMean, N_fl);
      }
    }
    return pythonic::types::make_tuple(rhoE_prev, rhoI_prev, thetaMean_, VE, XE, VI, XI);
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 , typename argument_type16 , typename argument_type17 , typename argument_type18 , typename argument_type19 , typename argument_type20 , typename argument_type21 , typename argument_type22 >
  typename run_transient_GLNetEIRand_static::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13, argument_type14, argument_type15, argument_type16, argument_type17, argument_type18, argument_type19, argument_type20, argument_type21, argument_type22>::result_type run_transient_GLNetEIRand_static::operator()(argument_type0&& VE, argument_type1&& XE, argument_type2&& VI, argument_type3&& XI, argument_type4&& tTrans, argument_type5&& rhoETemp, argument_type6&& rhoITemp, argument_type7&& pN, argument_type8&& qN, argument_type9&& pN_fl, argument_type10&& qN_fl, argument_type11&& P_firing_poisson, argument_type12&& Iext, argument_type13&& mu, argument_type14&& theta, argument_type15&& Gamma, argument_type16&& I, argument_type17&& synapticInput, argument_type18&& J, argument_type19&& W, argument_type20&& C, argument_type21&& KE, argument_type22&& K) const
  {
    typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type0;
    typedef typename pythonic::lazy<__type0>::type __type1;
    typedef double __type2;
    typedef typename pythonic::lazy<__type2>::type __type3;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type4;
    typedef GLNetEIRand_iter __type5;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type6;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type7;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type __type8;
    typedef decltype(std::declval<__type7>()(std::declval<__type8>())) __type9;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type9>::type::iterator>::value_type>::type __type10;
    typedef decltype(std::declval<__type6>()[std::declval<__type10>()]) __type11;
    typedef decltype(std::declval<__type4>()[std::declval<__type10>()]) __type12;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type17>::type>::type __type13;
    typedef decltype(std::declval<__type13>()[std::declval<__type10>()]) __type14;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type12>::type>::type __type15;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type13>::type>::type __type16;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type14>::type>::type __type17;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type15>::type>::type __type18;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type16>::type>::type __type19;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type11>::type>::type __type20;
    typedef typename pythonic::assignable<decltype(std::declval<__type5>()(std::declval<__type11>(), std::declval<__type12>(), std::declval<__type14>(), std::declval<__type15>(), std::declval<__type16>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>()))>::type __type21;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type21>::type>::type __type22;
    typedef container<typename std::remove_reference<__type22>::type> __type23;
    typedef typename __combined<__type4,__type23>::type __type24;
    typedef indexable<__type10> __type25;
    typedef typename __combined<__type24,__type25>::type __type26;
    typedef decltype(std::declval<__type26>()[std::declval<__type10>()]) __type27;
    typedef decltype(pythonic::operator_::add(std::declval<__type3>(), std::declval<__type27>())) __type28;
    typedef typename pythonic::lazy<__type28>::type __type29;
    typedef typename __combined<__type3,__type29>::type __type30;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type9>::type>::type __type31;
    typedef decltype(pythonic::operator_::div(std::declval<__type30>(), std::declval<__type31>())) __type32;
    typedef typename pythonic::lazy<__type32>::type __type33;
    typedef typename __combined<__type1,__type33>::type __type34;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type __type35;
    typedef typename pythonic::lazy<__type35>::type __type36;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type37;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type38;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type39;
    typedef decltype(std::declval<__type7>()(std::declval<__type39>())) __type40;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type40>::type::iterator>::value_type>::type __type41;
    typedef decltype(std::declval<__type38>()[std::declval<__type41>()]) __type42;
    typedef decltype(std::declval<__type37>()[std::declval<__type41>()]) __type43;
    typedef decltype(std::declval<__type13>()[std::declval<__type41>()]) __type44;
    typedef typename pythonic::assignable<decltype(std::declval<__type5>()(std::declval<__type42>(), std::declval<__type43>(), std::declval<__type44>(), std::declval<__type15>(), std::declval<__type16>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type2>()))>::type __type45;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type45>::type>::type __type46;
    typedef container<typename std::remove_reference<__type46>::type> __type47;
    typedef typename __combined<__type37,__type47>::type __type48;
    typedef indexable<__type41> __type49;
    typedef typename __combined<__type48,__type49>::type __type50;
    typedef decltype(std::declval<__type50>()[std::declval<__type41>()]) __type51;
    typedef decltype(pythonic::operator_::add(std::declval<__type3>(), std::declval<__type51>())) __type52;
    typedef typename pythonic::lazy<__type52>::type __type53;
    typedef typename __combined<__type3,__type53>::type __type54;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type10>::type>::type __type55;
    typedef decltype(pythonic::operator_::div(std::declval<__type54>(), std::declval<__type55>())) __type56;
    typedef typename pythonic::lazy<__type56>::type __type57;
    typedef typename __combined<__type36,__type57>::type __type58;
    typedef long __type59;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type60;
    typedef decltype(std::declval<__type7>()(std::declval<__type59>(), std::declval<__type60>())) __type61;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type61>::type::iterator>::value_type>::type>::type t;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type40>::type::iterator>::value_type>::type>::type i_;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type9>::type::iterator>::value_type>::type>::type i;
    typename pythonic::lazy<__type34>::type rhoE_prev = rhoETemp;
    typename pythonic::lazy<__type58>::type rhoI_prev = rhoITemp;
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::len{}(C))>::type N = pythonic::builtins::functor::len{}(C);
    {
      long  __target140219921913552 = tTrans;
      for (long  t=1L; t < __target140219921913552; t += 1L)
      {
        sumSynpaticInput_homog()(synapticInput, KE, K, N, XE, XI, J, W, C);
        typename pythonic::lazy<__type30>::type sum_XE = 0.0;
        {
          long  __target140219921915184 = pN;
          for (long  i=0L; i < __target140219921915184; i += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIRand_iter()(VE[i], XE[i], synapticInput[i], Iext, mu, theta, Gamma, I, P_firing_poisson))>::type __tuple0 = GLNetEIRand_iter()(VE[i], XE[i], synapticInput[i], Iext, mu, theta, Gamma, I, P_firing_poisson);
            VE.fast(i) = std::get<0>(__tuple0);
            XE.fast(i) = std::get<1>(__tuple0);
            sum_XE = pythonic::operator_::add(sum_XE, XE.fast(i));
          }
        }
        typename pythonic::lazy<__type54>::type sum_XI = 0.0;
        {
          long  __target140219921915520 = qN;
          for (long  i_=0L; i_ < __target140219921915520; i_ += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIRand_iter()(VI[i_], XI[i_], synapticInput[i_], Iext, mu, theta, Gamma, I, 0.0))>::type __tuple1 = GLNetEIRand_iter()(VI[i_], XI[i_], synapticInput[i_], Iext, mu, theta, Gamma, I, 0.0);
            VI.fast(i_) = std::get<0>(__tuple1);
            XI.fast(i_) = std::get<1>(__tuple1);
            sum_XI = pythonic::operator_::add(sum_XI, XI.fast(i_));
          }
        }
        rhoE_prev = pythonic::operator_::div(sum_XE, pN_fl);
        rhoI_prev = pythonic::operator_::div(sum_XI, qN_fl);
      }
    }
    return pythonic::types::make_tuple(rhoE_prev, rhoI_prev, VE, XE, VI, XI);
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 , typename argument_type15 , typename argument_type16 , typename argument_type17 , typename argument_type18 , typename argument_type19 , typename argument_type20 , typename argument_type21 , typename argument_type22 , typename argument_type23 , typename argument_type24 , typename argument_type25 , typename argument_type26 , typename argument_type27 , typename argument_type28 >
  typename run_transient_GLNetEIMF_adapt::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13, argument_type14, argument_type15, argument_type16, argument_type17, argument_type18, argument_type19, argument_type20, argument_type21, argument_type22, argument_type23, argument_type24, argument_type25, argument_type26, argument_type27, argument_type28>::result_type run_transient_GLNetEIMF_adapt::operator()(argument_type0&& VE, argument_type1&& XE, argument_type2&& VI, argument_type3&& XI, argument_type4&& thetaE, argument_type5&& thetaI, argument_type6&& rhoETemp, argument_type7&& rhoITemp, argument_type8&& N_fl, argument_type9&& pN, argument_type10&& qN, argument_type11&& pN_fl, argument_type12&& qN_fl, argument_type13&& P_firing_poisson, argument_type14&& weightDynType, argument_type15&& tTrans, argument_type16&& Iext, argument_type17&& mu, argument_type18&& J, argument_type19&& Gamma, argument_type20&& I, argument_type21&& p, argument_type22&& q, argument_type23&& tauTinv, argument_type24&& uT, argument_type25&& tauWinv, argument_type26&& uW, argument_type27&& A, argument_type28&& W_I) const
  {
    typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type28>::type>::type>::type __type0;
    typedef typename pythonic::assignable<weightAdapt_decrease>::type __type1;
    typedef typename pythonic::assignable<weightAdapt_increase>::type __type2;
    typedef typename __combined<__type1,__type2>::type __type3;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type27>::type>::type __type4;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type25>::type>::type __type5;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type26>::type>::type __type6;
    typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type6>::type>::type>::type __type7;
    typedef typename pythonic::assignable<typename std::remove_cv<typename std::remove_reference<argument_type7>::type>::type>::type __type8;
    typedef typename pythonic::assignable<decltype(std::declval<__type3>()(std::declval<__type0>(), std::declval<__type4>(), std::declval<__type5>(), std::declval<__type6>(), std::declval<__type7>(), std::declval<__type8>()))>::type __type9;
    typedef double __type10;
    typedef typename pythonic::lazy<__type10>::type __type11;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type12;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type13;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type14;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type9>::type>::type __type15;
    typedef decltype(std::declval<__type14>()(std::declval<__type15>())) __type16;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type16>::type::iterator>::value_type>::type __type17;
    typedef decltype(std::declval<__type13>()[std::declval<__type17>()]) __type18;
    typedef decltype(std::declval<__type12>()[std::declval<__type17>()]) __type19;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type16>::type>::type __type20;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type17>::type>::type __type21;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type4>::type>::type __type22;
    typedef decltype(std::declval<__type22>()[std::declval<__type17>()]) __type23;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type18>::type>::type __type24;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type19>::type>::type __type25;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type20>::type>::type __type26;
    typedef typename __combined<__type0,__type9>::type __type27;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type21>::type>::type __type28;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type22>::type>::type __type29;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type23>::type>::type __type30;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type24>::type>::type __type31;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type13>::type>::type __type32;
    typedef typename GLNetEIMF_adaptthresh_iter::type<__type18, __type19, __type7, __type8, __type20, __type21, __type23, __type24, __type25, __type26, __type27, __type28, __type29, __type30, __type31, __type32>::__ptype10 __type33;
    typedef container<typename std::remove_reference<__type33>::type> __type34;
    typedef typename __combined<__type12,__type34>::type __type35;
    typedef GLNetEIMF_adaptthresh_iter __type36;
    typedef typename pythonic::assignable<decltype(std::declval<__type36>()(std::declval<__type18>(), std::declval<__type19>(), std::declval<__type7>(), std::declval<__type8>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type23>(), std::declval<__type24>(), std::declval<__type25>(), std::declval<__type26>(), std::declval<__type27>(), std::declval<__type28>(), std::declval<__type29>(), std::declval<__type30>(), std::declval<__type31>(), std::declval<__type32>()))>::type __type37;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type37>::type>::type __type38;
    typedef container<typename std::remove_reference<__type38>::type> __type39;
    typedef typename __combined<__type35,__type39>::type __type40;
    typedef indexable<__type17> __type41;
    typedef typename __combined<__type40,__type41>::type __type42;
    typedef decltype(std::declval<__type42>()[std::declval<__type17>()]) __type43;
    typedef decltype(pythonic::operator_::add(std::declval<__type11>(), std::declval<__type43>())) __type44;
    typedef typename pythonic::lazy<__type44>::type __type45;
    typedef typename __combined<__type11,__type45>::type __type46;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type11>::type>::type __type47;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type46>(), std::declval<__type47>()))>::type __type48;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type3>::type>::type __type49;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type2>::type>::type __type50;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type10>::type>::type __type51;
    typedef decltype(std::declval<__type14>()(std::declval<__type51>())) __type52;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type52>::type::iterator>::value_type>::type __type53;
    typedef decltype(std::declval<__type50>()[std::declval<__type53>()]) __type54;
    typedef decltype(std::declval<__type49>()[std::declval<__type53>()]) __type55;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type5>::type>::type __type56;
    typedef decltype(std::declval<__type56>()[std::declval<__type53>()]) __type57;
    typedef typename GLNetEIMF_adaptthresh_iter::type<__type54, __type55, __type7, __type8, __type20, __type21, __type57, __type24, __type25, __type26, __type27, __type28, __type29, __type30, __type31, __type10>::__ptype10 __type58;
    typedef container<typename std::remove_reference<__type58>::type> __type59;
    typedef typename __combined<__type49,__type59>::type __type60;
    typedef typename pythonic::assignable<decltype(std::declval<__type36>()(std::declval<__type54>(), std::declval<__type55>(), std::declval<__type7>(), std::declval<__type8>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type57>(), std::declval<__type24>(), std::declval<__type25>(), std::declval<__type26>(), std::declval<__type27>(), std::declval<__type28>(), std::declval<__type29>(), std::declval<__type30>(), std::declval<__type31>(), std::declval<__type10>()))>::type __type61;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type61>::type>::type __type62;
    typedef container<typename std::remove_reference<__type62>::type> __type63;
    typedef typename __combined<__type60,__type63>::type __type64;
    typedef indexable<__type53> __type65;
    typedef typename __combined<__type64,__type65>::type __type66;
    typedef decltype(std::declval<__type66>()[std::declval<__type53>()]) __type67;
    typedef decltype(pythonic::operator_::add(std::declval<__type11>(), std::declval<__type67>())) __type68;
    typedef typename pythonic::lazy<__type68>::type __type69;
    typedef typename __combined<__type11,__type69>::type __type70;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type12>::type>::type __type71;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type70>(), std::declval<__type71>()))>::type __type72;
    typedef typename pythonic::assignable<double>::type __type73;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type37>::type>::type __type74;
    typedef container<typename std::remove_reference<__type74>::type> __type75;
    typedef typename __combined<__type22,__type75>::type __type76;
    typedef typename __combined<__type76,__type41>::type __type77;
    typedef decltype(std::declval<__type77>()[std::declval<__type17>()]) __type78;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::add(std::declval<__type73>(), std::declval<__type78>()))>::type __type79;
    typedef typename __combined<__type73,__type79>::type __type80;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type61>::type>::type __type81;
    typedef container<typename std::remove_reference<__type81>::type> __type82;
    typedef typename __combined<__type56,__type82>::type __type83;
    typedef typename __combined<__type83,__type65>::type __type84;
    typedef decltype(std::declval<__type84>()[std::declval<__type53>()]) __type85;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::add(std::declval<__type80>(), std::declval<__type85>()))>::type __type86;
    typedef long __type87;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type15>::type>::type __type88;
    typedef decltype(std::declval<__type14>()(std::declval<__type87>(), std::declval<__type88>())) __type89;
    typedef typename __combined<__type80,__type86>::type __type90;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type8>::type>::type __type91;
    typedef decltype(pythonic::operator_::div(std::declval<__type90>(), std::declval<__type91>())) __type92;
    typedef typename pythonic::lazy<__type92>::type __type93;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type89>::type::iterator>::value_type>::type>::type t;
    typename pythonic::lazy<__type93>::type thetaMean_;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type52>::type::iterator>::value_type>::type>::type i_;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type16>::type::iterator>::value_type>::type>::type i;
    typename pythonic::assignable<typename __combined<__type1,__type2>::type>::type weightAdapt;
    typename pythonic::assignable<typename __combined<__type0,__type9>::type>::type W_I_ = W_I;
    if (pythonic::operator_::eq(weightDynType, pythonic::types::str("simple")))
    {
      weightAdapt = weightAdapt_decrease();
    }
    else
    {
      if (pythonic::operator_::eq(weightDynType, pythonic::types::str("coupled")))
      {
        weightAdapt = weightAdapt_increase();
      }
    }
    typename pythonic::assignable<typename __combined<__type7,__type48>::type>::type rhoE_prev = rhoETemp;
    typename pythonic::assignable<typename __combined<__type8,__type72>::type>::type rhoI_prev = rhoITemp;
    {
      long  __target140219921593728 = tTrans;
      for (long  t=1L; t < __target140219921593728; t += 1L)
      {
        W_I_ = weightAdapt(W_I_, A, tauWinv, uW, rhoE_prev, rhoI_prev);
        typename pythonic::lazy<__type46>::type sum_XE = 0.0;
        typename pythonic::lazy<__type70>::type sum_XI = 0.0;
        typename pythonic::assignable<typename __combined<__type80,__type86>::type>::type thetaMean = 0.0;
        {
          long  __target140219921609344 = pN;
          for (long  i=0L; i < __target140219921609344; i += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_adaptthresh_iter()(VE[i], XE[i], rhoE_prev, rhoI_prev, Iext, mu, thetaE[i], J, Gamma, I, W_I_, p, q, tauTinv, uT, P_firing_poisson))>::type __tuple0 = GLNetEIMF_adaptthresh_iter()(VE[i], XE[i], rhoE_prev, rhoI_prev, Iext, mu, thetaE[i], J, Gamma, I, W_I_, p, q, tauTinv, uT, P_firing_poisson);
            VE.fast(i) = std::get<0>(__tuple0);
            XE.fast(i) = std::get<1>(__tuple0);
            thetaE.fast(i) = std::get<2>(__tuple0);
            sum_XE = pythonic::operator_::add(sum_XE, XE.fast(i));
            thetaMean = pythonic::operator_::add(thetaMean, thetaE.fast(i));
          }
        }
        {
          long  __target140219921610448 = qN;
          for (long  i_=0L; i_ < __target140219921610448; i_ += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_adaptthresh_iter()(VI[i_], XI[i_], rhoE_prev, rhoI_prev, Iext, mu, thetaI[i_], J, Gamma, I, W_I_, p, q, tauTinv, uT, 0.0))>::type __tuple1 = GLNetEIMF_adaptthresh_iter()(VI[i_], XI[i_], rhoE_prev, rhoI_prev, Iext, mu, thetaI[i_], J, Gamma, I, W_I_, p, q, tauTinv, uT, 0.0);
            VI.fast(i_) = std::get<0>(__tuple1);
            XI.fast(i_) = std::get<1>(__tuple1);
            thetaI.fast(i_) = std::get<2>(__tuple1);
            sum_XI = pythonic::operator_::add(sum_XI, XI.fast(i_));
            thetaMean = pythonic::operator_::add(thetaMean, thetaI.fast(i_));
          }
        }
        rhoE_prev = pythonic::operator_::div(sum_XE, pN_fl);
        rhoI_prev = pythonic::operator_::div(sum_XI, qN_fl);
        thetaMean_ = pythonic::operator_::div(thetaMean, N_fl);
      }
    }
    return pythonic::types::make_tuple(rhoE_prev, rhoI_prev, thetaMean_, W_I_, VE, XE, VI, XI);
  }
  template <typename argument_type0 , typename argument_type1 , typename argument_type2 , typename argument_type3 , typename argument_type4 , typename argument_type5 , typename argument_type6 , typename argument_type7 , typename argument_type8 , typename argument_type9 , typename argument_type10 , typename argument_type11 , typename argument_type12 , typename argument_type13 , typename argument_type14 >
  typename set_MF_network_IC::type<argument_type0, argument_type1, argument_type2, argument_type3, argument_type4, argument_type5, argument_type6, argument_type7, argument_type8, argument_type9, argument_type10, argument_type11, argument_type12, argument_type13, argument_type14>::result_type set_MF_network_IC::operator()(argument_type0&& pN, argument_type1&& qN, argument_type2&& g, argument_type3&& J, argument_type4&& VE0, argument_type5&& VE0Std, argument_type6&& VI0, argument_type7&& VI0Std, argument_type8&& XE0, argument_type9&& fXE0, argument_type10&& XE0Rand, argument_type11&& XI0, argument_type12&& fXI0, argument_type13&& XI0Rand, argument_type14&& theta) const
  {
    typename pythonic::assignable_noescape<decltype(pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(set_MF_network_IC_lambda16(), VE0, VE0Std), pythonic::builtins::functor::range{}(pN))))>::type VE = pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(set_MF_network_IC_lambda16(), VE0, VE0Std), pythonic::builtins::functor::range{}(pN)));
    typename pythonic::assignable_noescape<decltype(pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(set_MF_network_IC_lambda17(), theta), pythonic::builtins::functor::range{}(pN))))>::type thetaE = pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(set_MF_network_IC_lambda17(), theta), pythonic::builtins::functor::range{}(pN)));
    typename pythonic::assignable_noescape<decltype(generate_IC_spikes()(XE0, pN, pythonic::builtins::functor::int_{}(pythonic::operator_::mul(fXE0, pN)), XE0Rand))>::type XE = generate_IC_spikes()(XE0, pN, pythonic::builtins::functor::int_{}(pythonic::operator_::mul(fXE0, pN)), XE0Rand);
    typename pythonic::assignable_noescape<decltype(pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(set_MF_network_IC_lambda18(), VI0, VI0Std), pythonic::builtins::functor::range{}(qN))))>::type VI = pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(set_MF_network_IC_lambda18(), VI0, VI0Std), pythonic::builtins::functor::range{}(qN)));
    typename pythonic::assignable_noescape<decltype(pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(set_MF_network_IC_lambda19(), theta), pythonic::builtins::functor::range{}(qN))))>::type thetaI = pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(set_MF_network_IC_lambda19(), theta), pythonic::builtins::functor::range{}(qN)));
    typename pythonic::assignable_noescape<decltype(generate_IC_spikes()(XI0, qN, pythonic::builtins::functor::int_{}(pythonic::operator_::mul(fXI0, qN)), XI0Rand))>::type XI = generate_IC_spikes()(XI0, qN, pythonic::builtins::functor::int_{}(pythonic::operator_::mul(fXI0, qN)), XI0Rand);
    return pythonic::types::make_tuple(VE, XE, VI, XI, pythonic::operator_::div(pythonic::builtins::functor::float_{}(pythonic::builtins::functor::sum{}(XE)), (((bool)pythonic::operator_::gt(pN, 0L)) ? typename __combined<decltype(pythonic::builtins::functor::float_{}(pN)), decltype(1.0)>::type(pythonic::builtins::functor::float_{}(pN)) : typename __combined<decltype(pythonic::builtins::functor::float_{}(pN)), decltype(1.0)>::type(1.0))), pythonic::operator_::div(pythonic::builtins::functor::float_{}(pythonic::builtins::functor::sum{}(XI)), (((bool)pythonic::operator_::gt(qN, 0L)) ? typename __combined<decltype(pythonic::builtins::functor::float_{}(qN)), decltype(1.0)>::type(pythonic::builtins::functor::float_{}(qN)) : typename __combined<decltype(pythonic::builtins::functor::float_{}(qN)), decltype(1.0)>::type(1.0))), thetaE, thetaI, pythonic::operator_::mul(g, J), theta);
  }
  template <typename argument_type0 , typename argument_type1 >
  typename RunSimulation_GLNetEIMF_adaptthresh::type<argument_type0, argument_type1>::result_type RunSimulation_GLNetEIMF_adaptthresh::operator()(argument_type0&& simParam_dict, argument_type1&& paramType_dict) const
  {
    typedef get_system_parameters __type0;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type1;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type2;
    typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type1>(), std::declval<__type2>()))>::type __type3;
    typedef set_MF_network_IC __type4;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::int_{})>::type>::type __type5;
    typedef typename pythonic::assignable<typename std::tuple_element<20,typename std::remove_reference<__type3>::type>::type>::type __type6;
    typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type3>::type>::type>::type __type7;
    typedef decltype(pythonic::operator_::mul(std::declval<__type6>(), std::declval<__type7>())) __type8;
    typedef typename pythonic::assignable<decltype(std::declval<__type5>()(std::declval<__type8>()))>::type __type9;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type7>(), std::declval<__type9>()))>::type __type10;
    typedef typename pythonic::assignable<typename std::tuple_element<19,typename std::remove_reference<__type3>::type>::type>::type __type11;
    typedef typename pythonic::assignable<typename std::tuple_element<15,typename std::remove_reference<__type3>::type>::type>::type __type12;
    typedef typename std::tuple_element<3,typename std::remove_reference<__type3>::type>::type __type13;
    typedef typename std::tuple_element<4,typename std::remove_reference<__type3>::type>::type __type14;
    typedef typename std::tuple_element<5,typename std::remove_reference<__type3>::type>::type __type15;
    typedef typename std::tuple_element<6,typename std::remove_reference<__type3>::type>::type __type16;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type17;
    typedef typename std::tuple_element<7,typename std::remove_reference<__type3>::type>::type __type18;
    typedef decltype(std::declval<__type17>()(std::declval<__type18>())) __type19;
    typedef typename std::tuple_element<8,typename std::remove_reference<__type3>::type>::type __type20;
    typedef typename std::tuple_element<9,typename std::remove_reference<__type3>::type>::type __type21;
    typedef typename std::tuple_element<10,typename std::remove_reference<__type3>::type>::type __type22;
    typedef decltype(std::declval<__type17>()(std::declval<__type22>())) __type23;
    typedef typename std::tuple_element<11,typename std::remove_reference<__type3>::type>::type __type24;
    typedef typename std::tuple_element<12,typename std::remove_reference<__type3>::type>::type __type25;
    typedef typename std::tuple_element<14,typename std::remove_reference<__type3>::type>::type __type26;
    typedef typename pythonic::assignable<decltype(std::declval<__type4>()(std::declval<__type9>(), std::declval<__type10>(), std::declval<__type11>(), std::declval<__type12>(), std::declval<__type13>(), std::declval<__type14>(), std::declval<__type15>(), std::declval<__type16>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type23>(), std::declval<__type24>(), std::declval<__type25>(), std::declval<__type26>()))>::type __type27;
    typedef typename std::tuple_element<9,typename std::remove_reference<__type27>::type>::type __type28;
    typedef container<typename std::remove_reference<__type28>::type> __type29;
    typedef decltype(std::declval<__type17>()(std::declval<__type9>())) __type30;
    typedef double __type31;
    typedef decltype(std::declval<__type17>()(std::declval<__type10>())) __type32;
    typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type27>::type>::type>::type __type33;
    typedef run_transient_GLNetEIMF_adaptthresh __type34;
    typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type27>::type>::type>::type __type35;
    typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type27>::type>::type>::type __type36;
    typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type27>::type>::type>::type __type37;
    typedef typename pythonic::assignable<typename std::tuple_element<6,typename std::remove_reference<__type27>::type>::type>::type __type38;
    typedef typename pythonic::assignable<typename std::tuple_element<7,typename std::remove_reference<__type27>::type>::type>::type __type39;
    typedef typename std::tuple_element<4,typename std::remove_reference<__type27>::type>::type __type40;
    typedef typename pythonic::lazy<__type40>::type __type41;
    typedef typename std::tuple_element<5,typename std::remove_reference<__type27>::type>::type __type42;
    typedef typename pythonic::lazy<__type42>::type __type43;
    typedef typename pythonic::assignable<decltype(std::declval<__type17>()(std::declval<__type7>()))>::type __type44;
    typedef typename pythonic::assignable<typename __combined<__type30,__type31>::type>::type __type45;
    typedef typename pythonic::assignable<typename __combined<__type32,__type31>::type>::type __type46;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::mul(std::declval<__type11>(), std::declval<__type12>()))>::type __type47;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::exp{})>::type>::type __type48;
    typedef typename std::tuple_element<30,typename std::remove_reference<__type3>::type>::type __type49;
    typedef decltype(pythonic::operator_::neg(std::declval<__type49>())) __type50;
    typedef decltype(std::declval<__type48>()(std::declval<__type50>())) __type51;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type31>(), std::declval<__type51>()))>::type __type52;
    typedef typename __combined<__type3,__type29>::type __type53;
    typedef typename std::tuple_element<29,typename std::remove_reference<__type53>::type>::type __type54;
    typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type3>::type>::type>::type __type55;
    typedef typename pythonic::assignable<typename std::tuple_element<18,typename std::remove_reference<__type3>::type>::type>::type __type56;
    typedef typename pythonic::assignable<typename std::tuple_element<13,typename std::remove_reference<__type3>::type>::type>::type __type57;
    typedef typename pythonic::assignable<typename std::tuple_element<16,typename std::remove_reference<__type3>::type>::type>::type __type58;
    typedef typename pythonic::assignable<typename std::tuple_element<17,typename std::remove_reference<__type3>::type>::type>::type __type59;
    typedef typename pythonic::assignable<typename std::tuple_element<21,typename std::remove_reference<__type3>::type>::type>::type __type60;
    typedef typename std::tuple_element<25,typename std::remove_reference<__type3>::type>::type __type61;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type31>(), std::declval<__type61>()))>::type __type62;
    typedef typename pythonic::assignable<typename std::tuple_element<26,typename std::remove_reference<__type3>::type>::type>::type __type63;
    typedef typename run_transient_GLNetEIMF_adaptthresh::type<__type33, __type35, __type36, __type37, __type38, __type39, __type41, __type43, __type44, __type9, __type10, __type45, __type46, __type47, __type52, __type54, __type55, __type56, __type57, __type12, __type58, __type59, __type6, __type60, __type62, __type63>::__ptype52 __type64;
    typedef typename __combined<__type41,__type64>::type __type65;
    typedef typename run_transient_GLNetEIMF_adaptthresh::type<__type33, __type35, __type36, __type37, __type38, __type39, __type65, __type43, __type44, __type9, __type10, __type45, __type46, __type47, __type52, __type54, __type55, __type56, __type57, __type12, __type58, __type59, __type6, __type60, __type62, __type63>::__ptype53 __type66;
    typedef typename __combined<__type43,__type66>::type __type67;
    typedef typename pythonic::assignable<decltype(std::declval<__type34>()(std::declval<__type33>(), std::declval<__type35>(), std::declval<__type36>(), std::declval<__type37>(), std::declval<__type38>(), std::declval<__type39>(), std::declval<__type65>(), std::declval<__type67>(), std::declval<__type44>(), std::declval<__type9>(), std::declval<__type10>(), std::declval<__type45>(), std::declval<__type46>(), std::declval<__type47>(), std::declval<__type52>(), std::declval<__type54>(), std::declval<__type55>(), std::declval<__type56>(), std::declval<__type57>(), std::declval<__type12>(), std::declval<__type58>(), std::declval<__type59>(), std::declval<__type6>(), std::declval<__type60>(), std::declval<__type62>(), std::declval<__type63>()))>::type __type68;
    typedef typename std::tuple_element<3,typename std::remove_reference<__type68>::type>::type __type69;
    typedef typename __combined<__type33,__type69>::type __type70;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type71;
    typedef decltype(std::declval<__type71>()(std::declval<__type9>())) __type72;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type72>::type::iterator>::value_type>::type __type73;
    typedef indexable<__type73> __type74;
    typedef typename __combined<__type70,__type74>::type __type75;
    typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type68>::type>::type>::type __type76;
    typedef typename __combined<__type76,__type74>::type __type77;
    typedef typename __combined<__type75,__type77>::type __type78;
    typedef GLNetEIMF_adaptthresh_iter __type79;
    typedef typename __combined<__type70,__type76>::type __type80;
    typedef decltype(std::declval<__type80>()[std::declval<__type73>()]) __type81;
    typedef typename std::tuple_element<4,typename std::remove_reference<__type68>::type>::type __type82;
    typedef typename __combined<__type35,__type82>::type __type83;
    typedef typename pythonic::assignable<typename std::tuple_element<4,typename std::remove_reference<__type68>::type>::type>::type __type84;
    typedef typename __combined<__type83,__type84>::type __type85;
    typedef decltype(std::declval<__type85>()[std::declval<__type73>()]) __type86;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::array{})>::type>::type __type87;
    typedef pythonic::types::list<typename std::remove_reference<__type31>::type> __type88;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::max{})>::type>::type __type89;
    typedef long __type90;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type53>::type>::type __type91;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type91>(), std::declval<__type55>()))>::type __type92;
    typedef typename __combined<__type90,__type92>::type __type93;
    typedef decltype(std::declval<__type89>()(std::declval<__type93>(), std::declval<__type92>())) __type94;
    typedef decltype(pythonic::operator_::mul(std::declval<__type88>(), std::declval<__type94>())) __type95;
    typedef typename pythonic::assignable<decltype(std::declval<__type87>()(std::declval<__type95>()))>::type __type96;
    typedef indexable<__type90> __type97;
    typedef typename __combined<__type96,__type97>::type __type98;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type68>::type>::type __type99;
    typedef typename pythonic::lazy<__type99>::type __type100;
    typedef typename __combined<__type65,__type100>::type __type101;
    typedef container<typename std::remove_reference<__type101>::type> __type102;
    typedef typename __combined<__type98,__type102>::type __type103;
    typedef decltype(std::declval<__type71>()(std::declval<__type90>(), std::declval<__type92>())) __type104;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type104>::type::iterator>::value_type>::type __type105;
    typedef decltype(pythonic::operator_::sub(std::declval<__type105>(), std::declval<__type90>())) __type106;
    typedef decltype(std::declval<__type103>()[std::declval<__type106>()]) __type107;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type68>::type>::type __type108;
    typedef typename pythonic::lazy<__type108>::type __type109;
    typedef typename __combined<__type67,__type109>::type __type110;
    typedef container<typename std::remove_reference<__type110>::type> __type111;
    typedef typename __combined<__type98,__type111>::type __type112;
    typedef decltype(std::declval<__type112>()[std::declval<__type106>()]) __type113;
    typedef decltype(std::declval<__type38>()[std::declval<__type73>()]) __type114;
    typedef typename pythonic::assignable<decltype(std::declval<__type79>()(std::declval<__type81>(), std::declval<__type86>(), std::declval<__type107>(), std::declval<__type113>(), std::declval<__type56>(), std::declval<__type57>(), std::declval<__type114>(), std::declval<__type12>(), std::declval<__type58>(), std::declval<__type59>(), std::declval<__type47>(), std::declval<__type6>(), std::declval<__type60>(), std::declval<__type62>(), std::declval<__type63>(), std::declval<__type52>()))>::type __type115;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type115>::type>::type __type116;
    typedef container<typename std::remove_reference<__type116>::type> __type117;
    typedef typename __combined<__type78,__type117>::type __type118;
    typedef typename __combined<__type83,__type74>::type __type119;
    typedef typename __combined<__type84,__type74>::type __type120;
    typedef typename __combined<__type119,__type120>::type __type121;
    typedef typename GLNetEIMF_adaptthresh_iter::type<__type81, __type86, __type107, __type113, __type56, __type57, __type114, __type12, __type58, __type59, __type47, __type6, __type60, __type62, __type63, __type52>::__ptype10 __type122;
    typedef container<typename std::remove_reference<__type122>::type> __type123;
    typedef typename __combined<__type121,__type123>::type __type124;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type115>::type>::type __type125;
    typedef container<typename std::remove_reference<__type125>::type> __type126;
    typedef typename __combined<__type124,__type126>::type __type127;
    typedef typename std::tuple_element<5,typename std::remove_reference<__type68>::type>::type __type128;
    typedef typename __combined<__type36,__type128>::type __type129;
    typedef decltype(std::declval<__type71>()(std::declval<__type10>())) __type130;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type130>::type::iterator>::value_type>::type __type131;
    typedef indexable<__type131> __type132;
    typedef typename __combined<__type129,__type132>::type __type133;
    typedef typename pythonic::assignable<typename std::tuple_element<5,typename std::remove_reference<__type68>::type>::type>::type __type134;
    typedef typename __combined<__type134,__type132>::type __type135;
    typedef typename __combined<__type133,__type135>::type __type136;
    typedef typename __combined<__type129,__type134>::type __type137;
    typedef decltype(std::declval<__type137>()[std::declval<__type131>()]) __type138;
    typedef typename std::tuple_element<6,typename std::remove_reference<__type68>::type>::type __type139;
    typedef typename __combined<__type37,__type139>::type __type140;
    typedef typename pythonic::assignable<typename std::tuple_element<6,typename std::remove_reference<__type68>::type>::type>::type __type141;
    typedef typename __combined<__type140,__type141>::type __type142;
    typedef decltype(std::declval<__type142>()[std::declval<__type131>()]) __type143;
    typedef indexable<__type105> __type144;
    typedef typename __combined<__type98,__type144>::type __type145;
    typedef typename __combined<__type145,__type102>::type __type146;
    typedef decltype(std::declval<__type103>()[std::declval<__type105>()]) __type147;
    typedef decltype(std::declval<__type127>()[std::declval<__type73>()]) __type148;
    typedef decltype(pythonic::operator_::add(std::declval<__type147>(), std::declval<__type148>())) __type149;
    typedef container<typename std::remove_reference<__type149>::type> __type150;
    typedef typename __combined<__type146,__type150>::type __type151;
    typedef decltype(std::declval<__type151>()[std::declval<__type106>()]) __type152;
    typedef decltype(std::declval<__type39>()[std::declval<__type131>()]) __type153;
    typedef typename pythonic::assignable<decltype(std::declval<__type79>()(std::declval<__type138>(), std::declval<__type143>(), std::declval<__type152>(), std::declval<__type113>(), std::declval<__type56>(), std::declval<__type57>(), std::declval<__type153>(), std::declval<__type12>(), std::declval<__type58>(), std::declval<__type59>(), std::declval<__type47>(), std::declval<__type6>(), std::declval<__type60>(), std::declval<__type62>(), std::declval<__type63>(), std::declval<__type31>()))>::type __type154;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type154>::type>::type __type155;
    typedef container<typename std::remove_reference<__type155>::type> __type156;
    typedef typename __combined<__type136,__type156>::type __type157;
    typedef typename __combined<__type140,__type132>::type __type158;
    typedef typename __combined<__type141,__type132>::type __type159;
    typedef typename __combined<__type158,__type159>::type __type160;
    typedef typename GLNetEIMF_adaptthresh_iter::type<__type138, __type143, __type152, __type113, __type56, __type57, __type153, __type12, __type58, __type59, __type47, __type6, __type60, __type62, __type63, __type31>::__ptype10 __type161;
    typedef container<typename std::remove_reference<__type161>::type> __type162;
    typedef typename __combined<__type160,__type162>::type __type163;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type154>::type>::type __type164;
    typedef container<typename std::remove_reference<__type164>::type> __type165;
    typedef typename __combined<__type163,__type165>::type __type166;
    typedef typename __combined<__type38,__type74>::type __type167;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type115>::type>::type __type168;
    typedef container<typename std::remove_reference<__type168>::type> __type169;
    typedef typename __combined<__type167,__type169>::type __type170;
    typedef typename __combined<__type39,__type132>::type __type171;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type154>::type>::type __type172;
    typedef container<typename std::remove_reference<__type172>::type> __type173;
    typedef typename __combined<__type171,__type173>::type __type174;
    typedef typename pythonic::lazy<__type28>::type __type175;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type68>::type>::type __type176;
    typedef typename pythonic::lazy<__type176>::type __type177;
    typedef typename __combined<__type175,__type177>::type __type178;
    typedef typename __combined<__type146,__type97>::type __type179;
    typedef typename __combined<__type179,__type150>::type __type180;
    typedef typename __combined<__type180,__type144>::type __type181;
    typedef decltype(std::declval<__type151>()[std::declval<__type105>()]) __type182;
    typedef decltype(pythonic::operator_::div(std::declval<__type182>(), std::declval<__type45>())) __type183;
    typedef container<typename std::remove_reference<__type183>::type> __type184;
    typedef typename __combined<__type145,__type111>::type __type185;
    typedef typename __combined<__type185,__type97>::type __type186;
    typedef decltype(std::declval<__type112>()[std::declval<__type105>()]) __type187;
    typedef decltype(std::declval<__type166>()[std::declval<__type131>()]) __type188;
    typedef decltype(pythonic::operator_::add(std::declval<__type187>(), std::declval<__type188>())) __type189;
    typedef container<typename std::remove_reference<__type189>::type> __type190;
    typedef typename __combined<__type186,__type190>::type __type191;
    typedef typename __combined<__type191,__type144>::type __type192;
    typedef typename __combined<__type185,__type190>::type __type193;
    typedef decltype(std::declval<__type193>()[std::declval<__type105>()]) __type194;
    typedef decltype(pythonic::operator_::div(std::declval<__type194>(), std::declval<__type46>())) __type195;
    typedef container<typename std::remove_reference<__type195>::type> __type196;
    typedef container<typename std::remove_reference<__type178>::type> __type197;
    typedef typename __combined<__type145,__type197>::type __type198;
    typedef typename __combined<__type198,__type97>::type __type199;
    typedef typename pythonic::assignable<double>::type __type200;
    typedef decltype(std::declval<__type170>()[std::declval<__type73>()]) __type201;
    typedef decltype(pythonic::operator_::add(std::declval<__type200>(), std::declval<__type201>())) __type202;
    typedef typename __combined<__type200,__type202>::type __type203;
    typedef decltype(std::declval<__type174>()[std::declval<__type131>()]) __type204;
    typedef decltype(pythonic::operator_::add(std::declval<__type203>(), std::declval<__type204>())) __type205;
    typedef typename __combined<__type203,__type205>::type __type206;
    typedef typename __combined<__type206,__type201>::type __type207;
    typedef typename __combined<__type207,__type204>::type __type208;
    typedef decltype(pythonic::operator_::div(std::declval<__type208>(), std::declval<__type44>())) __type209;
    typedef container<typename std::remove_reference<__type209>::type> __type210;
    typedef typename __combined<__type199,__type210>::type __type211;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::functools::functor::partial{})>::type>::type __type212;
    typedef RunSimulation_GLNetEIMF_adaptthresh_lambda5 __type213;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::open{})>::type>::type __type214;
    typedef typename pythonic::assignable<typename std::tuple_element<34,typename std::remove_reference<__type3>::type>::type>::type __type215;
    typedef pythonic::types::str __type216;
    typedef typename pythonic::assignable<decltype(std::declval<__type214>()(std::declval<__type215>(), std::declval<__type216>()))>::type __type217;
    typedef typename pythonic::assignable<decltype(std::declval<__type212>()(std::declval<__type213>(), std::declval<__type217>()))>::type __type218;
    typedef typename pythonic::assignable<write_spk_data_fake>::type __type219;
    typedef typename pythonic::assignable<save_spk_data_fake>::type __type220;
    typedef typename pythonic::assignable<save_spk_data>::type __type221;
    typedef decltype(pythonic::types::make_tuple(std::declval<__type90>(), std::declval<__type90>())) __type222;
    typedef typename pythonic::assignable<pythonic::types::list<typename std::remove_reference<__type222>::type>>::type __type223;
    typedef save_initial_spkdata __type224;
    typedef typename pythonic::assignable<typename std::tuple_element<28,typename std::remove_reference<__type3>::type>::type>::type __type225;
    typedef decltype(pythonic::operator_::mul(std::declval<__type6>(), std::declval<__type225>())) __type226;
    typedef typename pythonic::assignable<decltype(std::declval<__type5>()(std::declval<__type226>()))>::type __type227;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type225>(), std::declval<__type227>()))>::type __type228;
    typedef typename pythonic::assignable<decltype(std::declval<__type224>()(std::declval<__type85>(), std::declval<__type142>(), std::declval<__type227>(), std::declval<__type228>()))>::type __type229;
    typedef typename __combined<__type223,__type229>::type __type230;
    typedef typename save_spk_data::type<__type230, __type105, __type73>::__ptype0 __type231;
    typedef pythonic::types::list<typename std::remove_reference<__type231>::type> __type232;
    typedef typename __combined<__type223,__type232>::type __type233;
    typedef typename __combined<__type230,__type232>::type __type234;
    typedef typename save_spk_data::type<__type234, __type105, __type73>::__ptype1 __type235;
    typedef pythonic::types::list<typename std::remove_reference<__type235>::type> __type236;
    typedef typename __combined<__type233,__type236>::type __type237;
    typedef typename __combined<__type220,__type221>::type __type238;
    typedef typename __combined<__type234,__type236>::type __type239;
    typedef decltype(std::declval<__type238>()(std::declval<__type239>(), std::declval<__type105>(), std::declval<__type73>())) __type240;
    typedef typename __combined<__type237,__type240>::type __type241;
    typedef typename __combined<__type229,__type232>::type __type242;
    typedef typename __combined<__type242,__type236>::type __type243;
    typedef typename __combined<__type243,__type240>::type __type244;
    typedef typename __combined<__type241,__type244>::type __type245;
    typedef typename __combined<__type245,__type239>::type __type246;
    typedef typename __combined<__type232,__type236>::type __type247;
    typedef typename pythonic::assignable<typename __combined<__type247,__type240>::type>::type __type248;
    typedef typename __combined<__type246,__type248>::type __type249;
    typedef typename __combined<__type247,__type240>::type __type250;
    typedef typename __combined<__type249,__type250>::type __type251;
    typedef decltype(pythonic::operator_::add(std::declval<__type131>(), std::declval<__type227>())) __type252;
    typedef typename save_spk_data::type<__type251, __type105, __type252>::__ptype0 __type253;
    typedef pythonic::types::list<typename std::remove_reference<__type253>::type> __type254;
    typedef typename __combined<__type241,__type254>::type __type255;
    typedef typename __combined<__type251,__type254>::type __type256;
    typedef typename save_spk_data::type<__type256, __type105, __type252>::__ptype1 __type257;
    typedef pythonic::types::list<typename std::remove_reference<__type257>::type> __type258;
    typedef typename __combined<__type255,__type258>::type __type259;
    typedef typename __combined<__type256,__type258>::type __type260;
    typedef decltype(std::declval<__type238>()(std::declval<__type260>(), std::declval<__type105>(), std::declval<__type252>())) __type261;
    typedef typename __combined<__type259,__type261>::type __type262;
    typedef typename __combined<__type244,__type254>::type __type263;
    typedef typename __combined<__type263,__type258>::type __type264;
    typedef typename __combined<__type264,__type261>::type __type265;
    typedef typename __combined<__type262,__type265>::type __type266;
    typedef typename __combined<__type266,__type239>::type __type267;
    typedef typename __combined<__type248,__type254>::type __type268;
    typedef typename __combined<__type268,__type258>::type __type269;
    typedef typename __combined<__type269,__type261>::type __type270;
    typedef typename __combined<__type267,__type270>::type __type271;
    typedef typename __combined<__type250,__type254>::type __type272;
    typedef typename __combined<__type272,__type258>::type __type273;
    typedef typename pythonic::assignable<typename __combined<__type273,__type261>::type>::type __type274;
    typedef typename __combined<__type271,__type274>::type __type275;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type72>::type::iterator>::value_type>::type>::type i;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type104>::type::iterator>::value_type>::type>::type t;
    typename pythonic::assignable<typename __combined<__type218,__type219>::type>::type write_spk_time;
    typename pythonic::assignable<typename __combined<__type220,__type221>::type>::type save_spk_time;
    typename pythonic::assignable<typename __combined<__type275,__type260>::type>::type spkData;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type130>::type::iterator>::value_type>::type>::type i_;
    typename pythonic::assignable<typename pythonic::assignable<decltype(std::declval<__type214>()(std::declval<__type215>(), std::declval<__type216>()))>::type>::type spkTimeFile;
    typename pythonic::assignable<typename __combined<__type3,__type29>::type>::type __tuple0 = get_system_parameters()(simParam_dict, paramType_dict);
    typename pythonic::assignable_noescape<decltype(std::get<0>(__tuple0))>::type N = std::get<0>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<1>(__tuple0))>::type tTrans = std::get<1>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<13>(__tuple0))>::type mu = std::get<13>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<15>(__tuple0))>::type J = std::get<15>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<16>(__tuple0))>::type Gamma = std::get<16>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<17>(__tuple0))>::type I = std::get<17>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<18>(__tuple0))>::type Iext = std::get<18>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<19>(__tuple0))>::type g = std::get<19>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<20>(__tuple0))>::type p = std::get<20>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<21>(__tuple0))>::type q = std::get<21>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<26>(__tuple0))>::type uT = std::get<26>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<27>(__tuple0))>::type saveSpikingData = std::get<27>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<28>(__tuple0))>::type nNeuronsSpk = std::get<28>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<33>(__tuple0))>::type writeOnRun = std::get<33>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<34>(__tuple0))>::type spkFileName = std::get<34>(__tuple0);
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::div(1.0, std::get<25>(__tuple0)))>::type tauTinv = pythonic::operator_::div(1.0, std::get<25>(__tuple0));
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, N)))>::type pN = pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, N));
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(N, pN))>::type qN = pythonic::operator_::sub(N, pN);
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::mul(g, J))>::type gJ = pythonic::operator_::mul(g, J);
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::float_{}(N))>::type N_fl = pythonic::builtins::functor::float_{}(N);
    typename pythonic::assignable<typename pythonic::assignable<typename __combined<__type30,__type31>::type>::type>::type pN_fl = (((bool)pythonic::operator_::gt(pN, 0L)) ? typename __combined<decltype(pythonic::builtins::functor::float_{}(pN)), decltype(1.0)>::type(pythonic::builtins::functor::float_{}(pN)) : typename __combined<decltype(pythonic::builtins::functor::float_{}(pN)), decltype(1.0)>::type(1.0));
    typename pythonic::assignable<typename pythonic::assignable<typename __combined<__type32,__type31>::type>::type>::type qN_fl = (((bool)pythonic::operator_::gt(qN, 0L)) ? typename __combined<decltype(pythonic::builtins::functor::float_{}(qN)), decltype(1.0)>::type(pythonic::builtins::functor::float_{}(qN)) : typename __combined<decltype(pythonic::builtins::functor::float_{}(qN)), decltype(1.0)>::type(1.0));
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, nNeuronsSpk)))>::type pN_s = pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, nNeuronsSpk));
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(nNeuronsSpk, pN_s))>::type qN_s = pythonic::operator_::sub(nNeuronsSpk, pN_s);
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(1.0, pythonic::numpy::functor::exp{}(pythonic::operator_::neg(std::get<30>(__tuple0)))))>::type P_firing_poisson = pythonic::operator_::sub(1.0, pythonic::numpy::functor::exp{}(pythonic::operator_::neg(std::get<30>(__tuple0))));
    typename pythonic::assignable_noescape<decltype(set_MF_network_IC()(pN, qN, g, J, std::get<3>(__tuple0), std::get<4>(__tuple0), std::get<5>(__tuple0), std::get<6>(__tuple0), pythonic::builtins::functor::float_{}(std::get<7>(__tuple0)), std::get<8>(__tuple0), std::get<9>(__tuple0), pythonic::builtins::functor::float_{}(std::get<10>(__tuple0)), std::get<11>(__tuple0), std::get<12>(__tuple0), std::get<14>(__tuple0)))>::type __tuple1 = set_MF_network_IC()(pN, qN, g, J, std::get<3>(__tuple0), std::get<4>(__tuple0), std::get<5>(__tuple0), std::get<6>(__tuple0), pythonic::builtins::functor::float_{}(std::get<7>(__tuple0)), std::get<8>(__tuple0), std::get<9>(__tuple0), pythonic::builtins::functor::float_{}(std::get<10>(__tuple0)), std::get<11>(__tuple0), std::get<12>(__tuple0), std::get<14>(__tuple0));
    typename pythonic::assignable<typename __combined<__type118,__type74>::type>::type VE = std::get<0>(__tuple1);
    typename pythonic::assignable<typename __combined<__type127,__type74>::type>::type XE = std::get<1>(__tuple1);
    typename pythonic::assignable<typename __combined<__type157,__type132>::type>::type VI = std::get<2>(__tuple1);
    typename pythonic::assignable<typename __combined<__type166,__type132>::type>::type XI = std::get<3>(__tuple1);
    typename pythonic::lazy<__type101>::type rhoETemp = std::get<4>(__tuple1);
    typename pythonic::lazy<__type110>::type rhoITemp = std::get<5>(__tuple1);
    typename pythonic::assignable<typename __combined<__type170,__type74>::type>::type thetaE = std::get<6>(__tuple1);
    typename pythonic::assignable<typename __combined<__type174,__type132>::type>::type thetaI = std::get<7>(__tuple1);
    typename pythonic::lazy<__type178>::type thetaMean = std::get<9>(__tuple1);
    if (pythonic::operator_::gt(tTrans, 0L))
    {
      typename pythonic::assignable_noescape<decltype(run_transient_GLNetEIMF_adaptthresh()(VE, XE, VI, XI, thetaE, thetaI, rhoETemp, rhoITemp, N_fl, pN, qN, pN_fl, qN_fl, gJ, P_firing_poisson, std::get<29>(__tuple0), tTrans, Iext, mu, J, Gamma, I, p, q, tauTinv, uT))>::type __tuple2 = run_transient_GLNetEIMF_adaptthresh()(VE, XE, VI, XI, thetaE, thetaI, rhoETemp, rhoITemp, N_fl, pN, qN, pN_fl, qN_fl, gJ, P_firing_poisson, std::get<29>(__tuple0), tTrans, Iext, mu, J, Gamma, I, p, q, tauTinv, uT);
      rhoETemp = std::get<0>(__tuple2);
      rhoITemp = std::get<1>(__tuple2);
      thetaMean = std::get<2>(__tuple2);
      VE = std::get<3>(__tuple2);
      XE = std::get<4>(__tuple2);
      VI = std::get<5>(__tuple2);
      XI = std::get<6>(__tuple2);
    }
    typename pythonic::assignable<typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type91>(), std::declval<__type55>()))>::type>::type Tmax_ = pythonic::operator_::sub(std::get<2>(__tuple0), tTrans);
    if (saveSpikingData)
    {
      if (writeOnRun)
      {
        pythonic::builtins::functor::print{}(pythonic::builtins::str::functor::__mod__{}(pythonic::types::str("*** writing file %s during simulation"), spkFileName));
        spkData = typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::types::make_tuple(0L, 0L))>::type>::type>::type>>::type>::type({pythonic::types::make_tuple(0L, 0L), pythonic::types::single_value()});
        spkTimeFile = pythonic::builtins::functor::open{}(spkFileName, pythonic::types::str("w"));
        write_spk_time = pythonic::functools::functor::partial{}(RunSimulation_GLNetEIMF_adaptthresh_lambda5(), spkTimeFile);
        save_spk_time = save_spk_data_fake();
      }
      else
      {
        write_spk_time = write_spk_data_fake();
        save_spk_time = save_spk_data();
        spkData = save_initial_spkdata()(XE, XI, pN_s, qN_s);
      }
    }
    else
    {
      save_spk_time = save_spk_data_fake();
      write_spk_time = write_spk_data_fake();
      spkData = typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::types::make_tuple(0L, 0L))>::type>::type>::type>>::type>::type({pythonic::types::make_tuple(0L, 0L), pythonic::types::single_value()});
    }
    typename pythonic::assignable<typename __combined<__type181,__type184>::type>::type rhoE = pythonic::numpy::functor::array{}(pythonic::operator_::mul(typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<double>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(0.0)>::type>::type>::type>>::type>::type({0.0, pythonic::types::single_value()}), pythonic::builtins::functor::max{}(0L, Tmax_)));
    typename pythonic::assignable<typename __combined<__type192,__type196>::type>::type rhoI = pythonic::numpy::functor::array{}(pythonic::operator_::mul(typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<double>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(0.0)>::type>::type>::type>>::type>::type({0.0, pythonic::types::single_value()}), pythonic::builtins::functor::max{}(0L, Tmax_)));
    typename pythonic::assignable<typename __combined<__type211,__type144>::type>::type theta_data = pythonic::numpy::functor::array{}(pythonic::operator_::mul(typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<double>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(0.0)>::type>::type>::type>>::type>::type({0.0, pythonic::types::single_value()}), pythonic::builtins::functor::max{}(0L, Tmax_)));
    std::get<0>(rhoE) = rhoETemp;
    std::get<0>(rhoI) = rhoITemp;
    std::get<0>(theta_data) = thetaMean;
    {
      long  __target140219922605680 = Tmax_;
      for (long  t=1L; t < __target140219922605680; t += 1L)
      {
        typename pythonic::assignable<typename __combined<__type207,__type204>::type>::type thetaMean_ = 0.0;
        {
          long  __target140219922620480 = pN;
          for (long  i=0L; i < __target140219922620480; i += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_adaptthresh_iter()(VE[i], XE[i], rhoE[pythonic::operator_::sub(t, 1L)], rhoI[pythonic::operator_::sub(t, 1L)], Iext, mu, thetaE[i], J, Gamma, I, gJ, p, q, tauTinv, uT, P_firing_poisson))>::type __tuple3 = GLNetEIMF_adaptthresh_iter()(VE[i], XE[i], rhoE[pythonic::operator_::sub(t, 1L)], rhoI[pythonic::operator_::sub(t, 1L)], Iext, mu, thetaE[i], J, Gamma, I, gJ, p, q, tauTinv, uT, P_firing_poisson);
            VE.fast(i) = std::get<0>(__tuple3);
            XE.fast(i) = std::get<1>(__tuple3);
            thetaE.fast(i) = std::get<2>(__tuple3);
            rhoE.fast(t) = pythonic::operator_::add(rhoE.fast(t), XE.fast(i));
            thetaMean_ += thetaE.fast(i);
            if (pythonic::builtins::pythran::and_([&] () { return pythonic::operator_::lt(i, pN_s); }, [&] () { return XE.fast(i); }))
            {
              spkData = save_spk_time(spkData, t, i);
              write_spk_time(t, i);
            }
          }
        }
        {
          long  __target140219922620720 = qN;
          for (long  i_=0L; i_ < __target140219922620720; i_ += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_adaptthresh_iter()(VI[i_], XI[i_], rhoE[pythonic::operator_::sub(t, 1L)], rhoI[pythonic::operator_::sub(t, 1L)], Iext, mu, thetaI[i_], J, Gamma, I, gJ, p, q, tauTinv, uT, 0.0))>::type __tuple4 = GLNetEIMF_adaptthresh_iter()(VI[i_], XI[i_], rhoE[pythonic::operator_::sub(t, 1L)], rhoI[pythonic::operator_::sub(t, 1L)], Iext, mu, thetaI[i_], J, Gamma, I, gJ, p, q, tauTinv, uT, 0.0);
            VI.fast(i_) = std::get<0>(__tuple4);
            XI.fast(i_) = std::get<1>(__tuple4);
            thetaI.fast(i_) = std::get<2>(__tuple4);
            rhoI.fast(t) = pythonic::operator_::add(rhoI.fast(t), XI.fast(i_));
            thetaMean_ += thetaI.fast(i_);
            if (pythonic::builtins::pythran::and_([&] () { return pythonic::operator_::lt(i_, qN_s); }, [&] () { return XI.fast(i_); }))
            {
              spkData = save_spk_time(spkData, t, pythonic::operator_::add(i_, pN_s));
              write_spk_time(t, pythonic::operator_::add(i_, pN_s));
            }
          }
        }
        rhoE.fast(t) = pythonic::operator_::div(rhoE.fast(t), pN_fl);
        rhoI.fast(t) = pythonic::operator_::div(rhoI.fast(t), qN_fl);
        theta_data.fast(t) = pythonic::operator_::div(thetaMean_, N_fl);
      }
    }
    if (pythonic::builtins::pythran::and_([&] () { return saveSpikingData; }, [&] () { return writeOnRun; }))
    {
      pythonic::io::_io::TextIOWrapper::functor::close{}(spkTimeFile);
    }
    return pythonic::types::make_tuple(rhoE, rhoI, spkData, pythonic::numpy::functor::multiply{}(pythonic::operator_::mul(p, J), rhoE), pythonic::numpy::functor::multiply{}(pythonic::operator_::mul(pythonic::operator_::mul(q, g), J), rhoI), pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(RunSimulation_GLNetEIMF_adaptthresh_lambda6(), g), rhoE)), pythonic::numpy::functor::divide{}(I, theta_data));
  }
  template <typename argument_type0 , typename argument_type1 >
  typename RunSimulation_GLNetEIMF_static::type<argument_type0, argument_type1>::result_type RunSimulation_GLNetEIMF_static::operator()(argument_type0&& simParam_dict, argument_type1&& paramType_dict) const
  {
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type0;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::int_{})>::type>::type __type1;
    typedef get_system_parameters __type2;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type3;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type4;
    typedef typename pythonic::assignable<decltype(std::declval<__type2>()(std::declval<__type3>(), std::declval<__type4>()))>::type __type5;
    typedef typename pythonic::assignable<typename std::tuple_element<20,typename std::remove_reference<__type5>::type>::type>::type __type6;
    typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type5>::type>::type>::type __type7;
    typedef decltype(pythonic::operator_::mul(std::declval<__type6>(), std::declval<__type7>())) __type8;
    typedef typename pythonic::assignable<decltype(std::declval<__type1>()(std::declval<__type8>()))>::type __type9;
    typedef decltype(std::declval<__type0>()(std::declval<__type9>())) __type10;
    typedef double __type11;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type7>(), std::declval<__type9>()))>::type __type12;
    typedef decltype(std::declval<__type0>()(std::declval<__type12>())) __type13;
    typedef set_MF_network_IC __type14;
    typedef typename pythonic::assignable<typename std::tuple_element<19,typename std::remove_reference<__type5>::type>::type>::type __type15;
    typedef typename pythonic::assignable<typename std::tuple_element<15,typename std::remove_reference<__type5>::type>::type>::type __type16;
    typedef typename std::tuple_element<3,typename std::remove_reference<__type5>::type>::type __type17;
    typedef typename std::tuple_element<4,typename std::remove_reference<__type5>::type>::type __type18;
    typedef typename std::tuple_element<5,typename std::remove_reference<__type5>::type>::type __type19;
    typedef typename std::tuple_element<6,typename std::remove_reference<__type5>::type>::type __type20;
    typedef typename std::tuple_element<7,typename std::remove_reference<__type5>::type>::type __type21;
    typedef decltype(std::declval<__type0>()(std::declval<__type21>())) __type22;
    typedef typename std::tuple_element<8,typename std::remove_reference<__type5>::type>::type __type23;
    typedef typename std::tuple_element<9,typename std::remove_reference<__type5>::type>::type __type24;
    typedef typename std::tuple_element<10,typename std::remove_reference<__type5>::type>::type __type25;
    typedef decltype(std::declval<__type0>()(std::declval<__type25>())) __type26;
    typedef typename std::tuple_element<11,typename std::remove_reference<__type5>::type>::type __type27;
    typedef typename std::tuple_element<12,typename std::remove_reference<__type5>::type>::type __type28;
    typedef typename pythonic::assignable<typename std::tuple_element<14,typename std::remove_reference<__type5>::type>::type>::type __type29;
    typedef typename pythonic::assignable<decltype(std::declval<__type14>()(std::declval<__type9>(), std::declval<__type12>(), std::declval<__type15>(), std::declval<__type16>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type22>(), std::declval<__type23>(), std::declval<__type24>(), std::declval<__type26>(), std::declval<__type27>(), std::declval<__type28>(), std::declval<__type29>()))>::type __type30;
    typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type30>::type>::type>::type __type31;
    typedef run_transient_GLNetEIMF_static __type32;
    typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type30>::type>::type>::type __type33;
    typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type30>::type>::type>::type __type34;
    typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type30>::type>::type>::type __type35;
    typedef typename std::tuple_element<4,typename std::remove_reference<__type30>::type>::type __type36;
    typedef typename pythonic::lazy<__type36>::type __type37;
    typedef typename std::tuple_element<5,typename std::remove_reference<__type30>::type>::type __type38;
    typedef typename pythonic::lazy<__type38>::type __type39;
    typedef typename pythonic::assignable<typename __combined<__type10,__type11>::type>::type __type40;
    typedef typename pythonic::assignable<typename __combined<__type13,__type11>::type>::type __type41;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::exp{})>::type>::type __type42;
    typedef typename std::tuple_element<30,typename std::remove_reference<__type5>::type>::type __type43;
    typedef decltype(pythonic::operator_::neg(std::declval<__type43>())) __type44;
    typedef decltype(std::declval<__type42>()(std::declval<__type44>())) __type45;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type11>(), std::declval<__type45>()))>::type __type46;
    typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type5>::type>::type>::type __type47;
    typedef typename pythonic::assignable<typename std::tuple_element<18,typename std::remove_reference<__type5>::type>::type>::type __type48;
    typedef typename pythonic::assignable<typename std::tuple_element<13,typename std::remove_reference<__type5>::type>::type>::type __type49;
    typedef typename pythonic::assignable<typename std::tuple_element<16,typename std::remove_reference<__type5>::type>::type>::type __type50;
    typedef typename pythonic::assignable<typename std::tuple_element<17,typename std::remove_reference<__type5>::type>::type>::type __type51;
    typedef typename pythonic::assignable<typename std::tuple_element<21,typename std::remove_reference<__type5>::type>::type>::type __type52;
    typedef typename run_transient_GLNetEIMF_static::type<__type31, __type33, __type34, __type35, __type37, __type39, __type9, __type12, __type40, __type41, __type46, __type47, __type48, __type49, __type29, __type16, __type50, __type51, __type15, __type6, __type52>::__ptype12 __type53;
    typedef typename __combined<__type37,__type53>::type __type54;
    typedef typename run_transient_GLNetEIMF_static::type<__type31, __type33, __type34, __type35, __type54, __type39, __type9, __type12, __type40, __type41, __type46, __type47, __type48, __type49, __type29, __type16, __type50, __type51, __type15, __type6, __type52>::__ptype13 __type55;
    typedef typename __combined<__type39,__type55>::type __type56;
    typedef typename pythonic::assignable<decltype(std::declval<__type32>()(std::declval<__type31>(), std::declval<__type33>(), std::declval<__type34>(), std::declval<__type35>(), std::declval<__type54>(), std::declval<__type56>(), std::declval<__type9>(), std::declval<__type12>(), std::declval<__type40>(), std::declval<__type41>(), std::declval<__type46>(), std::declval<__type47>(), std::declval<__type48>(), std::declval<__type49>(), std::declval<__type29>(), std::declval<__type16>(), std::declval<__type50>(), std::declval<__type51>(), std::declval<__type15>(), std::declval<__type6>(), std::declval<__type52>()))>::type __type57;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type57>::type>::type __type58;
    typedef typename __combined<__type31,__type58>::type __type59;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type60;
    typedef decltype(std::declval<__type60>()(std::declval<__type9>())) __type61;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type61>::type::iterator>::value_type>::type __type62;
    typedef indexable<__type62> __type63;
    typedef typename __combined<__type59,__type63>::type __type64;
    typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type57>::type>::type>::type __type65;
    typedef typename __combined<__type65,__type63>::type __type66;
    typedef typename __combined<__type64,__type66>::type __type67;
    typedef GLNetEIMF_iter __type68;
    typedef typename __combined<__type59,__type65>::type __type69;
    typedef decltype(std::declval<__type69>()[std::declval<__type62>()]) __type70;
    typedef typename std::tuple_element<3,typename std::remove_reference<__type57>::type>::type __type71;
    typedef typename __combined<__type33,__type71>::type __type72;
    typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type57>::type>::type>::type __type73;
    typedef typename __combined<__type72,__type73>::type __type74;
    typedef decltype(std::declval<__type74>()[std::declval<__type62>()]) __type75;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::array{})>::type>::type __type76;
    typedef pythonic::types::list<typename std::remove_reference<__type11>::type> __type77;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::max{})>::type>::type __type78;
    typedef long __type79;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type5>::type>::type __type80;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type80>(), std::declval<__type47>()))>::type __type81;
    typedef typename __combined<__type79,__type81>::type __type82;
    typedef decltype(std::declval<__type78>()(std::declval<__type82>(), std::declval<__type81>())) __type83;
    typedef decltype(pythonic::operator_::mul(std::declval<__type77>(), std::declval<__type83>())) __type84;
    typedef typename pythonic::assignable<decltype(std::declval<__type76>()(std::declval<__type84>()))>::type __type85;
    typedef indexable<__type79> __type86;
    typedef typename __combined<__type85,__type86>::type __type87;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type57>::type>::type __type88;
    typedef typename pythonic::lazy<__type88>::type __type89;
    typedef typename __combined<__type54,__type89>::type __type90;
    typedef container<typename std::remove_reference<__type90>::type> __type91;
    typedef typename __combined<__type87,__type91>::type __type92;
    typedef decltype(std::declval<__type60>()(std::declval<__type79>(), std::declval<__type81>())) __type93;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type93>::type::iterator>::value_type>::type __type94;
    typedef decltype(pythonic::operator_::sub(std::declval<__type94>(), std::declval<__type79>())) __type95;
    typedef decltype(std::declval<__type92>()[std::declval<__type95>()]) __type96;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type57>::type>::type __type97;
    typedef typename pythonic::lazy<__type97>::type __type98;
    typedef typename __combined<__type56,__type98>::type __type99;
    typedef container<typename std::remove_reference<__type99>::type> __type100;
    typedef typename __combined<__type87,__type100>::type __type101;
    typedef decltype(std::declval<__type101>()[std::declval<__type95>()]) __type102;
    typedef typename pythonic::assignable<decltype(std::declval<__type68>()(std::declval<__type70>(), std::declval<__type75>(), std::declval<__type96>(), std::declval<__type102>(), std::declval<__type48>(), std::declval<__type49>(), std::declval<__type29>(), std::declval<__type16>(), std::declval<__type50>(), std::declval<__type51>(), std::declval<__type15>(), std::declval<__type6>(), std::declval<__type52>(), std::declval<__type46>()))>::type __type103;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type103>::type>::type __type104;
    typedef container<typename std::remove_reference<__type104>::type> __type105;
    typedef typename __combined<__type67,__type105>::type __type106;
    typedef typename __combined<__type72,__type63>::type __type107;
    typedef typename __combined<__type73,__type63>::type __type108;
    typedef typename __combined<__type107,__type108>::type __type109;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type103>::type>::type __type110;
    typedef container<typename std::remove_reference<__type110>::type> __type111;
    typedef typename __combined<__type109,__type111>::type __type112;
    typedef typename std::tuple_element<4,typename std::remove_reference<__type57>::type>::type __type113;
    typedef typename __combined<__type34,__type113>::type __type114;
    typedef decltype(std::declval<__type60>()(std::declval<__type12>())) __type115;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type115>::type::iterator>::value_type>::type __type116;
    typedef indexable<__type116> __type117;
    typedef typename __combined<__type114,__type117>::type __type118;
    typedef typename pythonic::assignable<typename std::tuple_element<4,typename std::remove_reference<__type57>::type>::type>::type __type119;
    typedef typename __combined<__type119,__type117>::type __type120;
    typedef typename __combined<__type118,__type120>::type __type121;
    typedef typename __combined<__type114,__type119>::type __type122;
    typedef decltype(std::declval<__type122>()[std::declval<__type116>()]) __type123;
    typedef typename std::tuple_element<5,typename std::remove_reference<__type57>::type>::type __type124;
    typedef typename __combined<__type35,__type124>::type __type125;
    typedef typename pythonic::assignable<typename std::tuple_element<5,typename std::remove_reference<__type57>::type>::type>::type __type126;
    typedef typename __combined<__type125,__type126>::type __type127;
    typedef decltype(std::declval<__type127>()[std::declval<__type116>()]) __type128;
    typedef indexable<__type94> __type129;
    typedef typename __combined<__type87,__type129>::type __type130;
    typedef typename __combined<__type130,__type91>::type __type131;
    typedef decltype(std::declval<__type92>()[std::declval<__type94>()]) __type132;
    typedef decltype(std::declval<__type112>()[std::declval<__type62>()]) __type133;
    typedef decltype(pythonic::operator_::add(std::declval<__type132>(), std::declval<__type133>())) __type134;
    typedef container<typename std::remove_reference<__type134>::type> __type135;
    typedef typename __combined<__type131,__type135>::type __type136;
    typedef decltype(std::declval<__type136>()[std::declval<__type95>()]) __type137;
    typedef typename pythonic::assignable<decltype(std::declval<__type68>()(std::declval<__type123>(), std::declval<__type128>(), std::declval<__type137>(), std::declval<__type102>(), std::declval<__type48>(), std::declval<__type49>(), std::declval<__type29>(), std::declval<__type16>(), std::declval<__type50>(), std::declval<__type51>(), std::declval<__type15>(), std::declval<__type6>(), std::declval<__type52>(), std::declval<__type11>()))>::type __type138;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type138>::type>::type __type139;
    typedef container<typename std::remove_reference<__type139>::type> __type140;
    typedef typename __combined<__type121,__type140>::type __type141;
    typedef typename __combined<__type125,__type117>::type __type142;
    typedef typename __combined<__type126,__type117>::type __type143;
    typedef typename __combined<__type142,__type143>::type __type144;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type138>::type>::type __type145;
    typedef container<typename std::remove_reference<__type145>::type> __type146;
    typedef typename __combined<__type144,__type146>::type __type147;
    typedef typename __combined<__type131,__type86>::type __type148;
    typedef typename __combined<__type148,__type135>::type __type149;
    typedef typename __combined<__type149,__type129>::type __type150;
    typedef decltype(std::declval<__type136>()[std::declval<__type94>()]) __type151;
    typedef decltype(pythonic::operator_::div(std::declval<__type151>(), std::declval<__type40>())) __type152;
    typedef container<typename std::remove_reference<__type152>::type> __type153;
    typedef typename __combined<__type130,__type100>::type __type154;
    typedef typename __combined<__type154,__type86>::type __type155;
    typedef decltype(std::declval<__type101>()[std::declval<__type94>()]) __type156;
    typedef decltype(std::declval<__type147>()[std::declval<__type116>()]) __type157;
    typedef decltype(pythonic::operator_::add(std::declval<__type156>(), std::declval<__type157>())) __type158;
    typedef container<typename std::remove_reference<__type158>::type> __type159;
    typedef typename __combined<__type155,__type159>::type __type160;
    typedef typename __combined<__type160,__type129>::type __type161;
    typedef typename __combined<__type154,__type159>::type __type162;
    typedef decltype(std::declval<__type162>()[std::declval<__type94>()]) __type163;
    typedef decltype(pythonic::operator_::div(std::declval<__type163>(), std::declval<__type41>())) __type164;
    typedef container<typename std::remove_reference<__type164>::type> __type165;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::functools::functor::partial{})>::type>::type __type166;
    typedef RunSimulation_GLNetEIMF_static_lambda12 __type167;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::open{})>::type>::type __type168;
    typedef typename pythonic::assignable<typename std::tuple_element<34,typename std::remove_reference<__type5>::type>::type>::type __type169;
    typedef pythonic::types::str __type170;
    typedef typename pythonic::assignable<decltype(std::declval<__type168>()(std::declval<__type169>(), std::declval<__type170>()))>::type __type171;
    typedef typename pythonic::assignable<decltype(std::declval<__type166>()(std::declval<__type167>(), std::declval<__type171>()))>::type __type172;
    typedef typename pythonic::assignable<write_spk_data_fake>::type __type173;
    typedef typename pythonic::assignable<save_spk_data_fake>::type __type174;
    typedef typename pythonic::assignable<save_spk_data>::type __type175;
    typedef decltype(pythonic::types::make_tuple(std::declval<__type79>(), std::declval<__type79>())) __type176;
    typedef typename pythonic::assignable<pythonic::types::list<typename std::remove_reference<__type176>::type>>::type __type177;
    typedef save_initial_spkdata __type178;
    typedef typename pythonic::assignable<typename std::tuple_element<28,typename std::remove_reference<__type5>::type>::type>::type __type179;
    typedef decltype(pythonic::operator_::mul(std::declval<__type6>(), std::declval<__type179>())) __type180;
    typedef typename pythonic::assignable<decltype(std::declval<__type1>()(std::declval<__type180>()))>::type __type181;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type179>(), std::declval<__type181>()))>::type __type182;
    typedef typename pythonic::assignable<decltype(std::declval<__type178>()(std::declval<__type74>(), std::declval<__type127>(), std::declval<__type181>(), std::declval<__type182>()))>::type __type183;
    typedef typename __combined<__type177,__type183>::type __type184;
    typedef typename save_spk_data::type<__type184, __type94, __type62>::__ptype0 __type185;
    typedef pythonic::types::list<typename std::remove_reference<__type185>::type> __type186;
    typedef typename __combined<__type177,__type186>::type __type187;
    typedef typename __combined<__type184,__type186>::type __type188;
    typedef typename save_spk_data::type<__type188, __type94, __type62>::__ptype1 __type189;
    typedef pythonic::types::list<typename std::remove_reference<__type189>::type> __type190;
    typedef typename __combined<__type187,__type190>::type __type191;
    typedef typename __combined<__type174,__type175>::type __type192;
    typedef typename __combined<__type188,__type190>::type __type193;
    typedef decltype(std::declval<__type192>()(std::declval<__type193>(), std::declval<__type94>(), std::declval<__type62>())) __type194;
    typedef typename __combined<__type191,__type194>::type __type195;
    typedef typename __combined<__type183,__type186>::type __type196;
    typedef typename __combined<__type196,__type190>::type __type197;
    typedef typename __combined<__type197,__type194>::type __type198;
    typedef typename __combined<__type195,__type198>::type __type199;
    typedef typename __combined<__type199,__type193>::type __type200;
    typedef typename __combined<__type186,__type190>::type __type201;
    typedef typename __combined<__type201,__type194>::type __type202;
    typedef typename __combined<__type200,__type202>::type __type203;
    typedef typename pythonic::assignable<typename __combined<__type201,__type194>::type>::type __type204;
    typedef typename __combined<__type203,__type204>::type __type205;
    typedef decltype(pythonic::operator_::add(std::declval<__type116>(), std::declval<__type181>())) __type206;
    typedef typename save_spk_data::type<__type205, __type94, __type206>::__ptype0 __type207;
    typedef pythonic::types::list<typename std::remove_reference<__type207>::type> __type208;
    typedef typename __combined<__type195,__type208>::type __type209;
    typedef typename __combined<__type205,__type208>::type __type210;
    typedef typename save_spk_data::type<__type210, __type94, __type206>::__ptype1 __type211;
    typedef pythonic::types::list<typename std::remove_reference<__type211>::type> __type212;
    typedef typename __combined<__type209,__type212>::type __type213;
    typedef typename __combined<__type210,__type212>::type __type214;
    typedef decltype(std::declval<__type192>()(std::declval<__type214>(), std::declval<__type94>(), std::declval<__type206>())) __type215;
    typedef typename __combined<__type213,__type215>::type __type216;
    typedef typename __combined<__type198,__type208>::type __type217;
    typedef typename __combined<__type217,__type212>::type __type218;
    typedef typename __combined<__type218,__type215>::type __type219;
    typedef typename __combined<__type216,__type219>::type __type220;
    typedef typename __combined<__type220,__type193>::type __type221;
    typedef typename __combined<__type202,__type208>::type __type222;
    typedef typename __combined<__type222,__type212>::type __type223;
    typedef typename pythonic::assignable<typename __combined<__type223,__type215>::type>::type __type224;
    typedef typename __combined<__type221,__type224>::type __type225;
    typedef typename __combined<__type204,__type208>::type __type226;
    typedef typename __combined<__type226,__type212>::type __type227;
    typedef typename __combined<__type227,__type215>::type __type228;
    typedef typename __combined<__type225,__type228>::type __type229;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type93>::type::iterator>::value_type>::type>::type t;
    typename pythonic::assignable<typename __combined<__type172,__type173>::type>::type write_spk_time;
    typename pythonic::assignable<typename __combined<__type174,__type175>::type>::type save_spk_time;
    typename pythonic::assignable<typename __combined<__type229,__type214>::type>::type spkData;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type115>::type::iterator>::value_type>::type>::type i_;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type61>::type::iterator>::value_type>::type>::type i;
    typename pythonic::assignable<typename pythonic::assignable<decltype(std::declval<__type168>()(std::declval<__type169>(), std::declval<__type170>()))>::type>::type spkTimeFile;
    typename pythonic::assignable_noescape<decltype(get_system_parameters()(simParam_dict, paramType_dict))>::type __tuple0 = get_system_parameters()(simParam_dict, paramType_dict);
    typename pythonic::assignable_noescape<decltype(std::get<0>(__tuple0))>::type N = std::get<0>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<1>(__tuple0))>::type tTrans = std::get<1>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<13>(__tuple0))>::type mu = std::get<13>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<14>(__tuple0))>::type theta = std::get<14>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<15>(__tuple0))>::type J = std::get<15>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<16>(__tuple0))>::type Gamma = std::get<16>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<17>(__tuple0))>::type I = std::get<17>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<18>(__tuple0))>::type Iext = std::get<18>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<19>(__tuple0))>::type g = std::get<19>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<20>(__tuple0))>::type p = std::get<20>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<21>(__tuple0))>::type q = std::get<21>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<27>(__tuple0))>::type saveSpikingData = std::get<27>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<28>(__tuple0))>::type nNeuronsSpk = std::get<28>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<33>(__tuple0))>::type writeOnRun = std::get<33>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<34>(__tuple0))>::type spkFileName = std::get<34>(__tuple0);
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, N)))>::type pN = pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, N));
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(N, pN))>::type qN = pythonic::operator_::sub(N, pN);
    typename pythonic::assignable<typename pythonic::assignable<typename __combined<__type10,__type11>::type>::type>::type pN_fl = (((bool)pythonic::operator_::gt(pN, 0L)) ? typename __combined<decltype(pythonic::builtins::functor::float_{}(pN)), decltype(1.0)>::type(pythonic::builtins::functor::float_{}(pN)) : typename __combined<decltype(pythonic::builtins::functor::float_{}(pN)), decltype(1.0)>::type(1.0));
    typename pythonic::assignable<typename pythonic::assignable<typename __combined<__type13,__type11>::type>::type>::type qN_fl = (((bool)pythonic::operator_::gt(qN, 0L)) ? typename __combined<decltype(pythonic::builtins::functor::float_{}(qN)), decltype(1.0)>::type(pythonic::builtins::functor::float_{}(qN)) : typename __combined<decltype(pythonic::builtins::functor::float_{}(qN)), decltype(1.0)>::type(1.0));
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, nNeuronsSpk)))>::type pN_s = pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, nNeuronsSpk));
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(nNeuronsSpk, pN_s))>::type qN_s = pythonic::operator_::sub(nNeuronsSpk, pN_s);
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(1.0, pythonic::numpy::functor::exp{}(pythonic::operator_::neg(std::get<30>(__tuple0)))))>::type P_firing_poisson = pythonic::operator_::sub(1.0, pythonic::numpy::functor::exp{}(pythonic::operator_::neg(std::get<30>(__tuple0))));
    typename pythonic::assignable_noescape<decltype(set_MF_network_IC()(pN, qN, g, J, std::get<3>(__tuple0), std::get<4>(__tuple0), std::get<5>(__tuple0), std::get<6>(__tuple0), pythonic::builtins::functor::float_{}(std::get<7>(__tuple0)), std::get<8>(__tuple0), std::get<9>(__tuple0), pythonic::builtins::functor::float_{}(std::get<10>(__tuple0)), std::get<11>(__tuple0), std::get<12>(__tuple0), theta))>::type __tuple1 = set_MF_network_IC()(pN, qN, g, J, std::get<3>(__tuple0), std::get<4>(__tuple0), std::get<5>(__tuple0), std::get<6>(__tuple0), pythonic::builtins::functor::float_{}(std::get<7>(__tuple0)), std::get<8>(__tuple0), std::get<9>(__tuple0), pythonic::builtins::functor::float_{}(std::get<10>(__tuple0)), std::get<11>(__tuple0), std::get<12>(__tuple0), theta);
    typename pythonic::assignable<typename __combined<__type106,__type63>::type>::type VE = std::get<0>(__tuple1);
    typename pythonic::assignable<typename __combined<__type112,__type63>::type>::type XE = std::get<1>(__tuple1);
    typename pythonic::assignable<typename __combined<__type141,__type117>::type>::type VI = std::get<2>(__tuple1);
    typename pythonic::assignable<typename __combined<__type147,__type117>::type>::type XI = std::get<3>(__tuple1);
    typename pythonic::lazy<__type90>::type rhoETemp = std::get<4>(__tuple1);
    typename pythonic::lazy<__type99>::type rhoITemp = std::get<5>(__tuple1);
    if (pythonic::operator_::gt(tTrans, 0L))
    {
      typename pythonic::assignable_noescape<decltype(run_transient_GLNetEIMF_static()(VE, XE, VI, XI, rhoETemp, rhoITemp, pN, qN, pN_fl, qN_fl, P_firing_poisson, tTrans, Iext, mu, theta, J, Gamma, I, g, p, q))>::type __tuple2 = run_transient_GLNetEIMF_static()(VE, XE, VI, XI, rhoETemp, rhoITemp, pN, qN, pN_fl, qN_fl, P_firing_poisson, tTrans, Iext, mu, theta, J, Gamma, I, g, p, q);
      rhoETemp = std::get<0>(__tuple2);
      rhoITemp = std::get<1>(__tuple2);
      VE = std::get<2>(__tuple2);
      XE = std::get<3>(__tuple2);
      VI = std::get<4>(__tuple2);
      XI = std::get<5>(__tuple2);
    }
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(std::get<2>(__tuple0), tTrans))>::type Tmax_ = pythonic::operator_::sub(std::get<2>(__tuple0), tTrans);
    if (saveSpikingData)
    {
      if (writeOnRun)
      {
        pythonic::builtins::functor::print{}(pythonic::builtins::str::functor::__mod__{}(pythonic::types::str("*** writing file %s during simulation"), spkFileName));
        spkData = typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::types::make_tuple(0L, 0L))>::type>::type>::type>>::type>::type({pythonic::types::make_tuple(0L, 0L), pythonic::types::single_value()});
        spkTimeFile = pythonic::builtins::functor::open{}(spkFileName, pythonic::types::str("w"));
        write_spk_time = pythonic::functools::functor::partial{}(RunSimulation_GLNetEIMF_static_lambda12(), spkTimeFile);
        save_spk_time = save_spk_data_fake();
      }
      else
      {
        write_spk_time = write_spk_data_fake();
        save_spk_time = save_spk_data();
        spkData = save_initial_spkdata()(XE, XI, pN_s, qN_s);
      }
    }
    else
    {
      save_spk_time = save_spk_data_fake();
      write_spk_time = write_spk_data_fake();
      spkData = typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::types::make_tuple(0L, 0L))>::type>::type>::type>>::type>::type({pythonic::types::make_tuple(0L, 0L), pythonic::types::single_value()});
    }
    typename pythonic::assignable<typename __combined<__type150,__type153>::type>::type rhoE = pythonic::numpy::functor::array{}(pythonic::operator_::mul(typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<double>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(0.0)>::type>::type>::type>>::type>::type({0.0, pythonic::types::single_value()}), pythonic::builtins::functor::max{}(0L, Tmax_)));
    typename pythonic::assignable<typename __combined<__type161,__type165>::type>::type rhoI = pythonic::numpy::functor::array{}(pythonic::operator_::mul(typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<double>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(0.0)>::type>::type>::type>>::type>::type({0.0, pythonic::types::single_value()}), pythonic::builtins::functor::max{}(0L, Tmax_)));
    std::get<0>(rhoE) = rhoETemp;
    std::get<0>(rhoI) = rhoITemp;
    {
      long  __target140219922241280 = Tmax_;
      for (long  t=1L; t < __target140219922241280; t += 1L)
      {
        {
          long  __target140219921736896 = pN;
          for (long  i=0L; i < __target140219921736896; i += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_iter()(VE[i], XE[i], rhoE[pythonic::operator_::sub(t, 1L)], rhoI[pythonic::operator_::sub(t, 1L)], Iext, mu, theta, J, Gamma, I, g, p, q, P_firing_poisson))>::type __tuple3 = GLNetEIMF_iter()(VE[i], XE[i], rhoE[pythonic::operator_::sub(t, 1L)], rhoI[pythonic::operator_::sub(t, 1L)], Iext, mu, theta, J, Gamma, I, g, p, q, P_firing_poisson);
            VE.fast(i) = std::get<0>(__tuple3);
            XE.fast(i) = std::get<1>(__tuple3);
            rhoE.fast(t) = pythonic::operator_::add(rhoE.fast(t), XE.fast(i));
            if (pythonic::builtins::pythran::and_([&] () { return pythonic::operator_::lt(i, pN_s); }, [&] () { return XE.fast(i); }))
            {
              spkData = save_spk_time(spkData, t, i);
              write_spk_time(t, i);
            }
          }
        }
        {
          long  __target140219921736944 = qN;
          for (long  i_=0L; i_ < __target140219921736944; i_ += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_iter()(VI[i_], XI[i_], rhoE[pythonic::operator_::sub(t, 1L)], rhoI[pythonic::operator_::sub(t, 1L)], Iext, mu, theta, J, Gamma, I, g, p, q, 0.0))>::type __tuple4 = GLNetEIMF_iter()(VI[i_], XI[i_], rhoE[pythonic::operator_::sub(t, 1L)], rhoI[pythonic::operator_::sub(t, 1L)], Iext, mu, theta, J, Gamma, I, g, p, q, 0.0);
            VI.fast(i_) = std::get<0>(__tuple4);
            XI.fast(i_) = std::get<1>(__tuple4);
            rhoI.fast(t) = pythonic::operator_::add(rhoI.fast(t), XI.fast(i_));
            if (pythonic::builtins::pythran::and_([&] () { return pythonic::operator_::lt(i_, qN_s); }, [&] () { return XI.fast(i_); }))
            {
              spkData = save_spk_time(spkData, t, pythonic::operator_::add(i_, pN_s));
              write_spk_time(t, pythonic::operator_::add(i_, pN_s));
            }
          }
        }
        rhoE.fast(t) = pythonic::operator_::div(rhoE.fast(t), pN_fl);
        rhoI.fast(t) = pythonic::operator_::div(rhoI.fast(t), qN_fl);
      }
    }
    if (pythonic::builtins::pythran::and_([&] () { return saveSpikingData; }, [&] () { return writeOnRun; }))
    {
      pythonic::io::_io::TextIOWrapper::functor::close{}(spkTimeFile);
    }
    return pythonic::types::make_tuple(rhoE, rhoI, spkData, pythonic::numpy::functor::multiply{}(pythonic::operator_::mul(p, J), rhoE), pythonic::numpy::functor::multiply{}(pythonic::operator_::mul(pythonic::operator_::mul(q, g), J), rhoI), pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(RunSimulation_GLNetEIMF_static_lambda13(), g), rhoE)), pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(RunSimulation_GLNetEIMF_static_lambda14(), I, theta), rhoE)));
  }
  template <typename argument_type0 , typename argument_type1 >
  typename RunSimulation_GLNetEIMF_aval::type<argument_type0, argument_type1>::result_type RunSimulation_GLNetEIMF_aval::operator()(argument_type0&& simParam_dict, argument_type1&& paramType_dict) const
  {
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type0;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::int_{})>::type>::type __type1;
    typedef get_system_parameters __type2;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type3;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type4;
    typedef typename pythonic::assignable<decltype(std::declval<__type2>()(std::declval<__type3>(), std::declval<__type4>()))>::type __type5;
    typedef typename pythonic::assignable<typename std::tuple_element<20,typename std::remove_reference<__type5>::type>::type>::type __type6;
    typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type5>::type>::type>::type __type7;
    typedef decltype(pythonic::operator_::mul(std::declval<__type6>(), std::declval<__type7>())) __type8;
    typedef typename pythonic::assignable<decltype(std::declval<__type1>()(std::declval<__type8>()))>::type __type9;
    typedef decltype(std::declval<__type0>()(std::declval<__type9>())) __type10;
    typedef double __type11;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type7>(), std::declval<__type9>()))>::type __type12;
    typedef decltype(std::declval<__type0>()(std::declval<__type12>())) __type13;
    typedef set_MF_network_IC __type14;
    typedef typename pythonic::assignable<typename std::tuple_element<19,typename std::remove_reference<__type5>::type>::type>::type __type15;
    typedef typename pythonic::assignable<typename std::tuple_element<15,typename std::remove_reference<__type5>::type>::type>::type __type16;
    typedef typename std::tuple_element<3,typename std::remove_reference<__type5>::type>::type __type17;
    typedef typename std::tuple_element<4,typename std::remove_reference<__type5>::type>::type __type18;
    typedef typename std::tuple_element<5,typename std::remove_reference<__type5>::type>::type __type19;
    typedef typename std::tuple_element<6,typename std::remove_reference<__type5>::type>::type __type20;
    typedef typename std::tuple_element<7,typename std::remove_reference<__type5>::type>::type __type21;
    typedef decltype(std::declval<__type0>()(std::declval<__type21>())) __type22;
    typedef typename std::tuple_element<8,typename std::remove_reference<__type5>::type>::type __type23;
    typedef typename std::tuple_element<9,typename std::remove_reference<__type5>::type>::type __type24;
    typedef typename std::tuple_element<10,typename std::remove_reference<__type5>::type>::type __type25;
    typedef decltype(std::declval<__type0>()(std::declval<__type25>())) __type26;
    typedef typename std::tuple_element<11,typename std::remove_reference<__type5>::type>::type __type27;
    typedef typename std::tuple_element<12,typename std::remove_reference<__type5>::type>::type __type28;
    typedef typename pythonic::assignable<typename std::tuple_element<14,typename std::remove_reference<__type5>::type>::type>::type __type29;
    typedef typename pythonic::assignable<decltype(std::declval<__type14>()(std::declval<__type9>(), std::declval<__type12>(), std::declval<__type15>(), std::declval<__type16>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type22>(), std::declval<__type23>(), std::declval<__type24>(), std::declval<__type26>(), std::declval<__type27>(), std::declval<__type28>(), std::declval<__type29>()))>::type __type30;
    typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type30>::type>::type>::type __type31;
    typedef run_transient_GLNetEIMF_aval __type32;
    typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type30>::type>::type>::type __type33;
    typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type30>::type>::type>::type __type34;
    typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type30>::type>::type>::type __type35;
    typedef typename pythonic::assignable<typename std::tuple_element<4,typename std::remove_reference<__type30>::type>::type>::type __type36;
    typedef typename pythonic::assignable<typename std::tuple_element<5,typename std::remove_reference<__type30>::type>::type>::type __type37;
    typedef typename pythonic::assignable<typename __combined<__type10,__type11>::type>::type __type38;
    typedef typename pythonic::assignable<typename __combined<__type13,__type11>::type>::type __type39;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::exp{})>::type>::type __type40;
    typedef typename std::tuple_element<30,typename std::remove_reference<__type5>::type>::type __type41;
    typedef decltype(pythonic::operator_::neg(std::declval<__type41>())) __type42;
    typedef decltype(std::declval<__type40>()(std::declval<__type42>())) __type43;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type11>(), std::declval<__type43>()))>::type __type44;
    typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type5>::type>::type>::type __type45;
    typedef typename pythonic::assignable<typename std::tuple_element<18,typename std::remove_reference<__type5>::type>::type>::type __type46;
    typedef typename pythonic::assignable<typename std::tuple_element<13,typename std::remove_reference<__type5>::type>::type>::type __type47;
    typedef typename pythonic::assignable<typename std::tuple_element<16,typename std::remove_reference<__type5>::type>::type>::type __type48;
    typedef typename pythonic::assignable<typename std::tuple_element<17,typename std::remove_reference<__type5>::type>::type>::type __type49;
    typedef typename pythonic::assignable<typename std::tuple_element<21,typename std::remove_reference<__type5>::type>::type>::type __type50;
    typedef typename run_transient_GLNetEIMF_aval::type<__type31, __type33, __type34, __type35, __type36, __type37, __type9, __type12, __type38, __type39, __type44, __type45, __type46, __type47, __type29, __type16, __type48, __type49, __type15, __type6, __type50>::__ptype30 __type51;
    typedef typename __combined<__type36,__type51>::type __type52;
    typedef typename run_transient_GLNetEIMF_aval::type<__type31, __type33, __type34, __type35, __type52, __type37, __type9, __type12, __type38, __type39, __type44, __type45, __type46, __type47, __type29, __type16, __type48, __type49, __type15, __type6, __type50>::__ptype31 __type53;
    typedef typename __combined<__type37,__type53>::type __type54;
    typedef typename pythonic::assignable<decltype(std::declval<__type32>()(std::declval<__type31>(), std::declval<__type33>(), std::declval<__type34>(), std::declval<__type35>(), std::declval<__type52>(), std::declval<__type54>(), std::declval<__type9>(), std::declval<__type12>(), std::declval<__type38>(), std::declval<__type39>(), std::declval<__type44>(), std::declval<__type45>(), std::declval<__type46>(), std::declval<__type47>(), std::declval<__type29>(), std::declval<__type16>(), std::declval<__type48>(), std::declval<__type49>(), std::declval<__type15>(), std::declval<__type6>(), std::declval<__type50>()))>::type __type55;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type55>::type>::type __type56;
    typedef typename __combined<__type31,__type56>::type __type57;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type58;
    typedef decltype(std::declval<__type58>()(std::declval<__type9>())) __type59;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type59>::type::iterator>::value_type>::type __type60;
    typedef indexable<__type60> __type61;
    typedef typename __combined<__type57,__type61>::type __type62;
    typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type55>::type>::type>::type __type63;
    typedef typename __combined<__type63,__type61>::type __type64;
    typedef typename __combined<__type62,__type64>::type __type65;
    typedef GLNetEIMF_iter __type66;
    typedef typename __combined<__type57,__type63>::type __type67;
    typedef decltype(std::declval<__type67>()[std::declval<__type60>()]) __type68;
    typedef typename std::tuple_element<3,typename std::remove_reference<__type55>::type>::type __type69;
    typedef typename __combined<__type33,__type69>::type __type70;
    typedef long __type71;
    typedef indexable<__type71> __type72;
    typedef typename __combined<__type70,__type72>::type __type73;
    typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type55>::type>::type>::type __type74;
    typedef typename __combined<__type74,__type72>::type __type75;
    typedef typename __combined<__type73,__type75>::type __type76;
    typedef container<typename std::remove_reference<__type71>::type> __type77;
    typedef typename __combined<__type76,__type77>::type __type78;
    typedef decltype(std::declval<__type78>()[std::declval<__type60>()]) __type79;
    typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type55>::type>::type>::type __type80;
    typedef typename __combined<__type52,__type80>::type __type81;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type11>(), std::declval<__type38>()))>::type __type82;
    typedef typename __combined<__type81,__type82>::type __type83;
    typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type55>::type>::type>::type __type84;
    typedef typename __combined<__type54,__type84>::type __type85;
    typedef typename pythonic::assignable<decltype(std::declval<__type66>()(std::declval<__type68>(), std::declval<__type79>(), std::declval<__type83>(), std::declval<__type85>(), std::declval<__type46>(), std::declval<__type47>(), std::declval<__type29>(), std::declval<__type16>(), std::declval<__type48>(), std::declval<__type49>(), std::declval<__type15>(), std::declval<__type6>(), std::declval<__type50>(), std::declval<__type44>()))>::type __type86;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type86>::type>::type __type87;
    typedef container<typename std::remove_reference<__type87>::type> __type88;
    typedef typename __combined<__type65,__type88>::type __type89;
    typedef typename __combined<__type73,__type61>::type __type90;
    typedef typename __combined<__type75,__type61>::type __type91;
    typedef typename __combined<__type90,__type91>::type __type92;
    typedef typename __combined<__type92,__type77>::type __type93;
    typedef typename __combined<__type93,__type72>::type __type94;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type86>::type>::type __type95;
    typedef container<typename std::remove_reference<__type95>::type> __type96;
    typedef typename __combined<__type94,__type96>::type __type97;
    typedef typename std::tuple_element<4,typename std::remove_reference<__type55>::type>::type __type98;
    typedef typename __combined<__type34,__type98>::type __type99;
    typedef decltype(std::declval<__type58>()(std::declval<__type12>())) __type100;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type100>::type::iterator>::value_type>::type __type101;
    typedef indexable<__type101> __type102;
    typedef typename __combined<__type99,__type102>::type __type103;
    typedef typename pythonic::assignable<typename std::tuple_element<4,typename std::remove_reference<__type55>::type>::type>::type __type104;
    typedef typename __combined<__type104,__type102>::type __type105;
    typedef typename __combined<__type103,__type105>::type __type106;
    typedef typename __combined<__type99,__type104>::type __type107;
    typedef decltype(std::declval<__type107>()[std::declval<__type101>()]) __type108;
    typedef typename std::tuple_element<5,typename std::remove_reference<__type55>::type>::type __type109;
    typedef typename __combined<__type35,__type109>::type __type110;
    typedef typename pythonic::assignable<typename std::tuple_element<5,typename std::remove_reference<__type55>::type>::type>::type __type111;
    typedef typename __combined<__type110,__type111>::type __type112;
    typedef decltype(std::declval<__type112>()[std::declval<__type101>()]) __type113;
    typedef typename pythonic::assignable<decltype(std::declval<__type66>()(std::declval<__type108>(), std::declval<__type113>(), std::declval<__type83>(), std::declval<__type85>(), std::declval<__type46>(), std::declval<__type47>(), std::declval<__type29>(), std::declval<__type16>(), std::declval<__type48>(), std::declval<__type49>(), std::declval<__type15>(), std::declval<__type6>(), std::declval<__type50>(), std::declval<__type11>()))>::type __type114;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type114>::type>::type __type115;
    typedef container<typename std::remove_reference<__type115>::type> __type116;
    typedef typename __combined<__type106,__type116>::type __type117;
    typedef typename __combined<__type110,__type102>::type __type118;
    typedef typename __combined<__type111,__type102>::type __type119;
    typedef typename __combined<__type118,__type119>::type __type120;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type114>::type>::type __type121;
    typedef container<typename std::remove_reference<__type121>::type> __type122;
    typedef typename __combined<__type120,__type122>::type __type123;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::array{})>::type>::type __type124;
    typedef pythonic::types::list<typename std::remove_reference<__type11>::type> __type125;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::max{})>::type>::type __type126;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type5>::type>::type __type127;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type127>(), std::declval<__type45>()))>::type __type128;
    typedef typename __combined<__type71,__type128>::type __type129;
    typedef decltype(std::declval<__type126>()(std::declval<__type129>(), std::declval<__type128>())) __type130;
    typedef decltype(pythonic::operator_::mul(std::declval<__type125>(), std::declval<__type130>())) __type131;
    typedef typename pythonic::assignable<decltype(std::declval<__type124>()(std::declval<__type131>()))>::type __type132;
    typedef typename __combined<__type132,__type72>::type __type133;
    typedef decltype(std::declval<__type58>()(std::declval<__type71>(), std::declval<__type128>())) __type134;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type134>::type::iterator>::value_type>::type __type135;
    typedef indexable<__type135> __type136;
    typedef typename __combined<__type133,__type136>::type __type137;
    typedef container<typename std::remove_reference<__type81>::type> __type138;
    typedef typename __combined<__type137,__type138>::type __type139;
    typedef typename __combined<__type93,__type96>::type __type140;
    typedef decltype(std::declval<__type140>()[std::declval<__type60>()]) __type141;
    typedef container<typename std::remove_reference<__type141>::type> __type142;
    typedef typename __combined<__type139,__type142>::type __type143;
    typedef decltype(std::declval<__type143>()[std::declval<__type135>()]) __type144;
    typedef decltype(pythonic::operator_::div(std::declval<__type144>(), std::declval<__type38>())) __type145;
    typedef container<typename std::remove_reference<__type145>::type> __type146;
    typedef typename __combined<__type143,__type146>::type __type147;
    typedef typename pythonic::assignable<decltype(std::declval<__type147>()[std::declval<__type135>()])>::type __type148;
    typedef container<typename std::remove_reference<__type85>::type> __type149;
    typedef typename __combined<__type137,__type149>::type __type150;
    typedef decltype(std::declval<__type123>()[std::declval<__type101>()]) __type151;
    typedef container<typename std::remove_reference<__type151>::type> __type152;
    typedef typename __combined<__type150,__type152>::type __type153;
    typedef decltype(std::declval<__type153>()[std::declval<__type135>()]) __type154;
    typedef decltype(pythonic::operator_::div(std::declval<__type154>(), std::declval<__type39>())) __type155;
    typedef container<typename std::remove_reference<__type155>::type> __type156;
    typedef typename __combined<__type153,__type156>::type __type157;
    typedef typename pythonic::assignable<decltype(std::declval<__type157>()[std::declval<__type135>()])>::type __type158;
    typedef typename __combined<__type139,__type72>::type __type159;
    typedef typename __combined<__type159,__type136>::type __type160;
    typedef typename __combined<__type160,__type142>::type __type161;
    typedef typename __combined<__type150,__type72>::type __type162;
    typedef typename __combined<__type162,__type136>::type __type163;
    typedef typename __combined<__type163,__type152>::type __type164;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::functools::functor::partial{})>::type>::type __type165;
    typedef RunSimulation_GLNetEIMF_aval_lambda7 __type166;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::open{})>::type>::type __type167;
    typedef typename pythonic::assignable<typename std::tuple_element<34,typename std::remove_reference<__type5>::type>::type>::type __type168;
    typedef pythonic::types::str __type169;
    typedef typename pythonic::assignable<decltype(std::declval<__type167>()(std::declval<__type168>(), std::declval<__type169>()))>::type __type170;
    typedef typename pythonic::assignable<decltype(std::declval<__type165>()(std::declval<__type166>(), std::declval<__type170>()))>::type __type171;
    typedef typename pythonic::assignable<write_spk_data_fake>::type __type172;
    typedef typename pythonic::assignable<save_spk_data_fake>::type __type173;
    typedef typename pythonic::assignable<save_spk_data>::type __type174;
    typedef decltype(pythonic::types::make_tuple(std::declval<__type71>(), std::declval<__type71>())) __type175;
    typedef typename pythonic::assignable<pythonic::types::list<typename std::remove_reference<__type175>::type>>::type __type176;
    typedef save_initial_spkdata __type177;
    typedef typename __combined<__type70,__type74>::type __type178;
    typedef typename pythonic::assignable<typename std::tuple_element<28,typename std::remove_reference<__type5>::type>::type>::type __type179;
    typedef decltype(pythonic::operator_::mul(std::declval<__type6>(), std::declval<__type179>())) __type180;
    typedef typename pythonic::assignable<decltype(std::declval<__type1>()(std::declval<__type180>()))>::type __type181;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type179>(), std::declval<__type181>()))>::type __type182;
    typedef typename pythonic::assignable<decltype(std::declval<__type177>()(std::declval<__type178>(), std::declval<__type112>(), std::declval<__type181>(), std::declval<__type182>()))>::type __type183;
    typedef typename __combined<__type176,__type183>::type __type184;
    typedef typename save_spk_data::type<__type184, __type135, __type60>::__ptype0 __type185;
    typedef pythonic::types::list<typename std::remove_reference<__type185>::type> __type186;
    typedef typename __combined<__type176,__type186>::type __type187;
    typedef typename __combined<__type184,__type186>::type __type188;
    typedef typename save_spk_data::type<__type188, __type135, __type60>::__ptype1 __type189;
    typedef pythonic::types::list<typename std::remove_reference<__type189>::type> __type190;
    typedef typename __combined<__type187,__type190>::type __type191;
    typedef typename __combined<__type173,__type174>::type __type192;
    typedef typename __combined<__type188,__type190>::type __type193;
    typedef decltype(std::declval<__type192>()(std::declval<__type193>(), std::declval<__type135>(), std::declval<__type60>())) __type194;
    typedef typename __combined<__type191,__type194>::type __type195;
    typedef typename __combined<__type183,__type186>::type __type196;
    typedef typename __combined<__type196,__type190>::type __type197;
    typedef typename __combined<__type197,__type194>::type __type198;
    typedef typename __combined<__type195,__type198>::type __type199;
    typedef typename __combined<__type199,__type193>::type __type200;
    typedef typename __combined<__type186,__type190>::type __type201;
    typedef typename pythonic::assignable<typename __combined<__type201,__type194>::type>::type __type202;
    typedef typename __combined<__type200,__type202>::type __type203;
    typedef typename __combined<__type201,__type194>::type __type204;
    typedef typename __combined<__type203,__type204>::type __type205;
    typedef decltype(pythonic::operator_::add(std::declval<__type101>(), std::declval<__type181>())) __type206;
    typedef typename save_spk_data::type<__type205, __type135, __type206>::__ptype0 __type207;
    typedef pythonic::types::list<typename std::remove_reference<__type207>::type> __type208;
    typedef typename __combined<__type195,__type208>::type __type209;
    typedef typename __combined<__type205,__type208>::type __type210;
    typedef typename save_spk_data::type<__type210, __type135, __type206>::__ptype1 __type211;
    typedef pythonic::types::list<typename std::remove_reference<__type211>::type> __type212;
    typedef typename __combined<__type209,__type212>::type __type213;
    typedef typename __combined<__type210,__type212>::type __type214;
    typedef decltype(std::declval<__type192>()(std::declval<__type214>(), std::declval<__type135>(), std::declval<__type206>())) __type215;
    typedef typename __combined<__type213,__type215>::type __type216;
    typedef typename __combined<__type198,__type208>::type __type217;
    typedef typename __combined<__type217,__type212>::type __type218;
    typedef typename __combined<__type218,__type215>::type __type219;
    typedef typename __combined<__type216,__type219>::type __type220;
    typedef typename __combined<__type220,__type193>::type __type221;
    typedef typename __combined<__type202,__type208>::type __type222;
    typedef typename __combined<__type222,__type212>::type __type223;
    typedef typename __combined<__type223,__type215>::type __type224;
    typedef typename __combined<__type221,__type224>::type __type225;
    typedef typename __combined<__type204,__type208>::type __type226;
    typedef typename __combined<__type226,__type212>::type __type227;
    typedef typename pythonic::assignable<typename __combined<__type227,__type215>::type>::type __type228;
    typedef typename __combined<__type225,__type228>::type __type229;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type134>::type::iterator>::value_type>::type>::type t;
    typename pythonic::assignable<typename __combined<__type171,__type172>::type>::type write_spk_time;
    typename pythonic::assignable<typename __combined<__type173,__type174>::type>::type save_spk_time;
    typename pythonic::assignable<typename __combined<__type229,__type214>::type>::type spkData;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type100>::type::iterator>::value_type>::type>::type i_;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type59>::type::iterator>::value_type>::type>::type i;
    typename pythonic::assignable<typename pythonic::assignable<decltype(std::declval<__type167>()(std::declval<__type168>(), std::declval<__type169>()))>::type>::type spkTimeFile;
    typename pythonic::assignable_noescape<decltype(get_system_parameters()(simParam_dict, paramType_dict))>::type __tuple0 = get_system_parameters()(simParam_dict, paramType_dict);
    typename pythonic::assignable_noescape<decltype(std::get<0>(__tuple0))>::type N = std::get<0>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<1>(__tuple0))>::type tTrans = std::get<1>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<13>(__tuple0))>::type mu = std::get<13>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<14>(__tuple0))>::type theta = std::get<14>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<15>(__tuple0))>::type J = std::get<15>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<16>(__tuple0))>::type Gamma = std::get<16>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<17>(__tuple0))>::type I = std::get<17>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<18>(__tuple0))>::type Iext = std::get<18>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<19>(__tuple0))>::type g = std::get<19>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<20>(__tuple0))>::type p = std::get<20>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<21>(__tuple0))>::type q = std::get<21>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<27>(__tuple0))>::type saveSpikingData = std::get<27>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<28>(__tuple0))>::type nNeuronsSpk = std::get<28>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<33>(__tuple0))>::type writeOnRun = std::get<33>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<34>(__tuple0))>::type spkFileName = std::get<34>(__tuple0);
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, N)))>::type pN = pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, N));
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(N, pN))>::type qN = pythonic::operator_::sub(N, pN);
    typename pythonic::assignable<typename pythonic::assignable<typename __combined<__type10,__type11>::type>::type>::type pN_fl = (((bool)pythonic::operator_::gt(pN, 0L)) ? typename __combined<decltype(pythonic::builtins::functor::float_{}(pN)), decltype(1.0)>::type(pythonic::builtins::functor::float_{}(pN)) : typename __combined<decltype(pythonic::builtins::functor::float_{}(pN)), decltype(1.0)>::type(1.0));
    typename pythonic::assignable<typename pythonic::assignable<typename __combined<__type13,__type11>::type>::type>::type qN_fl = (((bool)pythonic::operator_::gt(qN, 0L)) ? typename __combined<decltype(pythonic::builtins::functor::float_{}(qN)), decltype(1.0)>::type(pythonic::builtins::functor::float_{}(qN)) : typename __combined<decltype(pythonic::builtins::functor::float_{}(qN)), decltype(1.0)>::type(1.0));
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, nNeuronsSpk)))>::type pN_s = pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, nNeuronsSpk));
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(nNeuronsSpk, pN_s))>::type qN_s = pythonic::operator_::sub(nNeuronsSpk, pN_s);
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(1.0, pythonic::numpy::functor::exp{}(pythonic::operator_::neg(std::get<30>(__tuple0)))))>::type P_firing_poisson = pythonic::operator_::sub(1.0, pythonic::numpy::functor::exp{}(pythonic::operator_::neg(std::get<30>(__tuple0))));
    typename pythonic::assignable_noescape<decltype(set_MF_network_IC()(pN, qN, g, J, std::get<3>(__tuple0), std::get<4>(__tuple0), std::get<5>(__tuple0), std::get<6>(__tuple0), pythonic::builtins::functor::float_{}(std::get<7>(__tuple0)), std::get<8>(__tuple0), std::get<9>(__tuple0), pythonic::builtins::functor::float_{}(std::get<10>(__tuple0)), std::get<11>(__tuple0), std::get<12>(__tuple0), theta))>::type __tuple1 = set_MF_network_IC()(pN, qN, g, J, std::get<3>(__tuple0), std::get<4>(__tuple0), std::get<5>(__tuple0), std::get<6>(__tuple0), pythonic::builtins::functor::float_{}(std::get<7>(__tuple0)), std::get<8>(__tuple0), std::get<9>(__tuple0), pythonic::builtins::functor::float_{}(std::get<10>(__tuple0)), std::get<11>(__tuple0), std::get<12>(__tuple0), theta);
    typename pythonic::assignable<typename __combined<__type89,__type61>::type>::type VE = std::get<0>(__tuple1);
    typename pythonic::assignable<typename __combined<__type97,__type61>::type>::type XE = std::get<1>(__tuple1);
    typename pythonic::assignable<typename __combined<__type117,__type102>::type>::type VI = std::get<2>(__tuple1);
    typename pythonic::assignable<typename __combined<__type123,__type102>::type>::type XI = std::get<3>(__tuple1);
    typename pythonic::assignable<typename __combined<__type83,__type148>::type>::type rhoETemp = std::get<4>(__tuple1);
    typename pythonic::assignable<typename __combined<__type85,__type158>::type>::type rhoITemp = std::get<5>(__tuple1);
    if (pythonic::operator_::gt(tTrans, 0L))
    {
      typename pythonic::assignable_noescape<decltype(run_transient_GLNetEIMF_aval()(VE, XE, VI, XI, rhoETemp, rhoITemp, pN, qN, pN_fl, qN_fl, P_firing_poisson, tTrans, Iext, mu, theta, J, Gamma, I, g, p, q))>::type __tuple2 = run_transient_GLNetEIMF_aval()(VE, XE, VI, XI, rhoETemp, rhoITemp, pN, qN, pN_fl, qN_fl, P_firing_poisson, tTrans, Iext, mu, theta, J, Gamma, I, g, p, q);
      rhoETemp = std::get<0>(__tuple2);
      rhoITemp = std::get<1>(__tuple2);
      VE = std::get<2>(__tuple2);
      XE = std::get<3>(__tuple2);
      VI = std::get<4>(__tuple2);
      XI = std::get<5>(__tuple2);
    }
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(std::get<2>(__tuple0), tTrans))>::type Tmax_ = pythonic::operator_::sub(std::get<2>(__tuple0), tTrans);
    if (saveSpikingData)
    {
      if (writeOnRun)
      {
        pythonic::builtins::functor::print{}(pythonic::builtins::str::functor::__mod__{}(pythonic::types::str("*** writing file %s during simulation"), spkFileName));
        spkData = typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::types::make_tuple(0L, 0L))>::type>::type>::type>>::type>::type({pythonic::types::make_tuple(0L, 0L), pythonic::types::single_value()});
        spkTimeFile = pythonic::builtins::functor::open{}(spkFileName, pythonic::types::str("w"));
        write_spk_time = pythonic::functools::functor::partial{}(RunSimulation_GLNetEIMF_aval_lambda7(), spkTimeFile);
        save_spk_time = save_spk_data_fake();
      }
      else
      {
        write_spk_time = write_spk_data_fake();
        save_spk_time = save_spk_data();
        spkData = save_initial_spkdata()(XE, XI, pN_s, qN_s);
      }
    }
    else
    {
      save_spk_time = save_spk_data_fake();
      write_spk_time = write_spk_data_fake();
      spkData = typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::types::make_tuple(0L, 0L))>::type>::type>::type>>::type>::type({pythonic::types::make_tuple(0L, 0L), pythonic::types::single_value()});
    }
    typename pythonic::assignable<typename __combined<__type161,__type146>::type>::type rhoE = pythonic::numpy::functor::array{}(pythonic::operator_::mul(typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<double>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(0.0)>::type>::type>::type>>::type>::type({0.0, pythonic::types::single_value()}), pythonic::builtins::functor::max{}(0L, Tmax_)));
    typename pythonic::assignable<typename __combined<__type164,__type156>::type>::type rhoI = pythonic::numpy::functor::array{}(pythonic::operator_::mul(typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<double>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(0.0)>::type>::type>::type>>::type>::type({0.0, pythonic::types::single_value()}), pythonic::builtins::functor::max{}(0L, Tmax_)));
    std::get<0>(rhoE) = rhoETemp;
    std::get<0>(rhoI) = rhoITemp;
    {
      long  __target140219922301712 = Tmax_;
      for (long  t=1L; t < __target140219922301712; t += 1L)
      {
        if (pythonic::operator_::lt(pythonic::operator_::add(rhoETemp, rhoITemp), 1e-16))
        {
          std::get<0>(XE) = 1L;
          rhoETemp = pythonic::operator_::div(1.0, pN_fl);
        }
        {
          long  __target140219922321664 = pN;
          for (long  i=0L; i < __target140219922321664; i += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_iter()(VE[i], XE[i], rhoETemp, rhoITemp, Iext, mu, theta, J, Gamma, I, g, p, q, P_firing_poisson))>::type __tuple3 = GLNetEIMF_iter()(VE[i], XE[i], rhoETemp, rhoITemp, Iext, mu, theta, J, Gamma, I, g, p, q, P_firing_poisson);
            VE[i] = std::get<0>(__tuple3);
            XE[i] = std::get<1>(__tuple3);
            rhoE[t] += XE[i];
            if (pythonic::builtins::pythran::and_([&] () { return pythonic::operator_::lt(i, pN_s); }, [&] () { return XE[i]; }))
            {
              spkData = save_spk_time(spkData, t, i);
              write_spk_time(t, i);
            }
          }
        }
        {
          long  __target140219922321904 = qN;
          for (long  i_=0L; i_ < __target140219922321904; i_ += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_iter()(VI[i_], XI[i_], rhoETemp, rhoITemp, Iext, mu, theta, J, Gamma, I, g, p, q, 0.0))>::type __tuple4 = GLNetEIMF_iter()(VI[i_], XI[i_], rhoETemp, rhoITemp, Iext, mu, theta, J, Gamma, I, g, p, q, 0.0);
            VI[i_] = std::get<0>(__tuple4);
            XI[i_] = std::get<1>(__tuple4);
            rhoI[t] += XI[i_];
            if (pythonic::builtins::pythran::and_([&] () { return pythonic::operator_::lt(i_, qN_s); }, [&] () { return XI[i_]; }))
            {
              spkData = save_spk_time(spkData, t, pythonic::operator_::add(i_, pN_s));
              write_spk_time(t, pythonic::operator_::add(i_, pN_s));
            }
          }
        }
        rhoE[t] = pythonic::operator_::div(rhoE[t], pN_fl);
        rhoI[t] = pythonic::operator_::div(rhoI[t], qN_fl);
        rhoETemp = rhoE[t];
        rhoITemp = rhoI[t];
      }
    }
    if (pythonic::builtins::pythran::and_([&] () { return saveSpikingData; }, [&] () { return writeOnRun; }))
    {
      pythonic::io::_io::TextIOWrapper::functor::close{}(spkTimeFile);
    }
    return pythonic::types::make_tuple(rhoE, rhoI, spkData, pythonic::numpy::functor::multiply{}(pythonic::operator_::mul(p, J), rhoE), pythonic::numpy::functor::multiply{}(pythonic::operator_::mul(pythonic::operator_::mul(q, g), J), rhoI), pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(RunSimulation_GLNetEIMF_aval_lambda8(), g), rhoE)), pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(RunSimulation_GLNetEIMF_aval_lambda9(), I, theta), rhoE)));
  }
  template <typename argument_type0 , typename argument_type1 >
  typename RunSimulation_GLNetEIMF_adapt::type<argument_type0, argument_type1>::result_type RunSimulation_GLNetEIMF_adapt::operator()(argument_type0&& simParam_dict, argument_type1&& paramType_dict) const
  {
    typedef get_system_parameters __type0;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type1;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type2;
    typedef typename pythonic::assignable<decltype(std::declval<__type0>()(std::declval<__type1>(), std::declval<__type2>()))>::type __type3;
    typedef set_MF_network_IC __type4;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::int_{})>::type>::type __type5;
    typedef typename pythonic::assignable<typename std::tuple_element<20,typename std::remove_reference<__type3>::type>::type>::type __type6;
    typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type3>::type>::type>::type __type7;
    typedef decltype(pythonic::operator_::mul(std::declval<__type6>(), std::declval<__type7>())) __type8;
    typedef typename pythonic::assignable<decltype(std::declval<__type5>()(std::declval<__type8>()))>::type __type9;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type7>(), std::declval<__type9>()))>::type __type10;
    typedef typename std::tuple_element<19,typename std::remove_reference<__type3>::type>::type __type11;
    typedef typename pythonic::assignable<typename std::tuple_element<15,typename std::remove_reference<__type3>::type>::type>::type __type12;
    typedef typename std::tuple_element<3,typename std::remove_reference<__type3>::type>::type __type13;
    typedef typename std::tuple_element<4,typename std::remove_reference<__type3>::type>::type __type14;
    typedef typename std::tuple_element<5,typename std::remove_reference<__type3>::type>::type __type15;
    typedef typename std::tuple_element<6,typename std::remove_reference<__type3>::type>::type __type16;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type17;
    typedef typename std::tuple_element<7,typename std::remove_reference<__type3>::type>::type __type18;
    typedef decltype(std::declval<__type17>()(std::declval<__type18>())) __type19;
    typedef typename std::tuple_element<8,typename std::remove_reference<__type3>::type>::type __type20;
    typedef typename std::tuple_element<9,typename std::remove_reference<__type3>::type>::type __type21;
    typedef typename std::tuple_element<10,typename std::remove_reference<__type3>::type>::type __type22;
    typedef decltype(std::declval<__type17>()(std::declval<__type22>())) __type23;
    typedef typename std::tuple_element<11,typename std::remove_reference<__type3>::type>::type __type24;
    typedef typename std::tuple_element<12,typename std::remove_reference<__type3>::type>::type __type25;
    typedef typename std::tuple_element<14,typename std::remove_reference<__type3>::type>::type __type26;
    typedef typename pythonic::assignable<decltype(std::declval<__type4>()(std::declval<__type9>(), std::declval<__type10>(), std::declval<__type11>(), std::declval<__type12>(), std::declval<__type13>(), std::declval<__type14>(), std::declval<__type15>(), std::declval<__type16>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type21>(), std::declval<__type23>(), std::declval<__type24>(), std::declval<__type25>(), std::declval<__type26>()))>::type __type27;
    typedef typename std::tuple_element<9,typename std::remove_reference<__type27>::type>::type __type28;
    typedef container<typename std::remove_reference<__type28>::type> __type29;
    typedef decltype(std::declval<__type17>()(std::declval<__type9>())) __type30;
    typedef double __type31;
    typedef decltype(std::declval<__type17>()(std::declval<__type10>())) __type32;
    typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type27>::type>::type>::type __type33;
    typedef run_transient_GLNetEIMF_adapt __type34;
    typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type27>::type>::type>::type __type35;
    typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type27>::type>::type>::type __type36;
    typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type27>::type>::type>::type __type37;
    typedef typename pythonic::assignable<typename std::tuple_element<6,typename std::remove_reference<__type27>::type>::type>::type __type38;
    typedef typename pythonic::assignable<typename std::tuple_element<7,typename std::remove_reference<__type27>::type>::type>::type __type39;
    typedef typename std::tuple_element<4,typename std::remove_reference<__type27>::type>::type __type40;
    typedef typename pythonic::lazy<__type40>::type __type41;
    typedef typename std::tuple_element<5,typename std::remove_reference<__type27>::type>::type __type42;
    typedef typename pythonic::lazy<__type42>::type __type43;
    typedef typename pythonic::assignable<decltype(std::declval<__type17>()(std::declval<__type7>()))>::type __type44;
    typedef typename pythonic::assignable<typename __combined<__type30,__type31>::type>::type __type45;
    typedef typename pythonic::assignable<typename __combined<__type32,__type31>::type>::type __type46;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::exp{})>::type>::type __type47;
    typedef typename std::tuple_element<30,typename std::remove_reference<__type3>::type>::type __type48;
    typedef decltype(pythonic::operator_::neg(std::declval<__type48>())) __type49;
    typedef decltype(std::declval<__type47>()(std::declval<__type49>())) __type50;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type31>(), std::declval<__type50>()))>::type __type51;
    typedef typename pythonic::assignable<typename std::tuple_element<29,typename std::remove_reference<__type3>::type>::type>::type __type52;
    typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type3>::type>::type>::type __type53;
    typedef typename pythonic::assignable<typename std::tuple_element<18,typename std::remove_reference<__type3>::type>::type>::type __type54;
    typedef typename pythonic::assignable<typename std::tuple_element<13,typename std::remove_reference<__type3>::type>::type>::type __type55;
    typedef typename pythonic::assignable<typename std::tuple_element<16,typename std::remove_reference<__type3>::type>::type>::type __type56;
    typedef typename pythonic::assignable<typename std::tuple_element<17,typename std::remove_reference<__type3>::type>::type>::type __type57;
    typedef typename pythonic::assignable<typename std::tuple_element<21,typename std::remove_reference<__type3>::type>::type>::type __type58;
    typedef typename std::tuple_element<25,typename std::remove_reference<__type3>::type>::type __type59;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type31>(), std::declval<__type59>()))>::type __type60;
    typedef typename pythonic::assignable<typename std::tuple_element<26,typename std::remove_reference<__type3>::type>::type>::type __type61;
    typedef typename std::tuple_element<23,typename std::remove_reference<__type3>::type>::type __type62;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::div(std::declval<__type31>(), std::declval<__type62>()))>::type __type63;
    typedef typename pythonic::assignable<typename std::tuple_element<24,typename std::remove_reference<__type3>::type>::type>::type __type64;
    typedef typename pythonic::assignable<typename std::tuple_element<22,typename std::remove_reference<__type3>::type>::type>::type __type65;
    typedef typename pythonic::assignable<typename std::tuple_element<8,typename std::remove_reference<__type27>::type>::type>::type __type66;
    typedef typename run_transient_GLNetEIMF_adapt::type<__type33, __type35, __type36, __type37, __type38, __type39, __type41, __type43, __type44, __type9, __type10, __type45, __type46, __type51, __type52, __type53, __type54, __type55, __type12, __type56, __type57, __type6, __type58, __type60, __type61, __type63, __type64, __type65, __type66>::__ptype104 __type67;
    typedef typename __combined<__type66,__type67>::type __type68;
    typedef typename run_transient_GLNetEIMF_adapt::type<__type33, __type35, __type36, __type37, __type38, __type39, __type41, __type43, __type44, __type9, __type10, __type45, __type46, __type51, __type52, __type53, __type54, __type55, __type12, __type56, __type57, __type6, __type58, __type60, __type61, __type63, __type64, __type65, __type68>::__ptype105 __type69;
    typedef typename __combined<__type41,__type69>::type __type70;
    typedef typename pythonic::assignable<decltype(std::declval<__type34>()(std::declval<__type33>(), std::declval<__type35>(), std::declval<__type36>(), std::declval<__type37>(), std::declval<__type38>(), std::declval<__type39>(), std::declval<__type70>(), std::declval<__type43>(), std::declval<__type44>(), std::declval<__type9>(), std::declval<__type10>(), std::declval<__type45>(), std::declval<__type46>(), std::declval<__type51>(), std::declval<__type52>(), std::declval<__type53>(), std::declval<__type54>(), std::declval<__type55>(), std::declval<__type12>(), std::declval<__type56>(), std::declval<__type57>(), std::declval<__type6>(), std::declval<__type58>(), std::declval<__type60>(), std::declval<__type61>(), std::declval<__type63>(), std::declval<__type64>(), std::declval<__type65>(), std::declval<__type68>()))>::type __type71;
    typedef typename std::tuple_element<4,typename std::remove_reference<__type71>::type>::type __type72;
    typedef typename __combined<__type33,__type72>::type __type73;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type74;
    typedef decltype(std::declval<__type74>()(std::declval<__type9>())) __type75;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type75>::type::iterator>::value_type>::type __type76;
    typedef indexable<__type76> __type77;
    typedef typename __combined<__type73,__type77>::type __type78;
    typedef typename pythonic::assignable<typename std::tuple_element<4,typename std::remove_reference<__type71>::type>::type>::type __type79;
    typedef typename __combined<__type79,__type77>::type __type80;
    typedef typename __combined<__type78,__type80>::type __type81;
    typedef GLNetEIMF_adaptthresh_iter __type82;
    typedef typename __combined<__type73,__type79>::type __type83;
    typedef decltype(std::declval<__type83>()[std::declval<__type76>()]) __type84;
    typedef typename std::tuple_element<5,typename std::remove_reference<__type71>::type>::type __type85;
    typedef typename __combined<__type35,__type85>::type __type86;
    typedef typename pythonic::assignable<typename std::tuple_element<5,typename std::remove_reference<__type71>::type>::type>::type __type87;
    typedef typename __combined<__type86,__type87>::type __type88;
    typedef decltype(std::declval<__type88>()[std::declval<__type76>()]) __type89;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::array{})>::type>::type __type90;
    typedef pythonic::types::list<typename std::remove_reference<__type31>::type> __type91;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::max{})>::type>::type __type92;
    typedef long __type93;
    typedef typename __combined<__type3,__type29>::type __type94;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type94>::type>::type __type95;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type95>(), std::declval<__type53>()))>::type __type96;
    typedef typename __combined<__type93,__type96>::type __type97;
    typedef decltype(std::declval<__type92>()(std::declval<__type97>(), std::declval<__type96>())) __type98;
    typedef decltype(pythonic::operator_::mul(std::declval<__type91>(), std::declval<__type98>())) __type99;
    typedef typename pythonic::assignable<decltype(std::declval<__type90>()(std::declval<__type99>()))>::type __type100;
    typedef indexable<__type93> __type101;
    typedef typename __combined<__type100,__type101>::type __type102;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type71>::type>::type __type103;
    typedef typename pythonic::lazy<__type103>::type __type104;
    typedef typename __combined<__type70,__type104>::type __type105;
    typedef container<typename std::remove_reference<__type105>::type> __type106;
    typedef typename __combined<__type102,__type106>::type __type107;
    typedef decltype(std::declval<__type74>()(std::declval<__type93>(), std::declval<__type96>())) __type108;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type108>::type::iterator>::value_type>::type __type109;
    typedef decltype(pythonic::operator_::sub(std::declval<__type109>(), std::declval<__type93>())) __type110;
    typedef decltype(std::declval<__type107>()[std::declval<__type110>()]) __type111;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type71>::type>::type __type112;
    typedef typename pythonic::lazy<__type112>::type __type113;
    typedef typename __combined<__type43,__type113>::type __type114;
    typedef container<typename std::remove_reference<__type114>::type> __type115;
    typedef typename __combined<__type102,__type115>::type __type116;
    typedef decltype(std::declval<__type116>()[std::declval<__type110>()]) __type117;
    typedef decltype(std::declval<__type38>()[std::declval<__type76>()]) __type118;
    typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type71>::type>::type>::type __type119;
    typedef typename __combined<__type68,__type119>::type __type120;
    typedef typename pythonic::assignable<weightAdapt_decrease>::type __type121;
    typedef typename pythonic::assignable<weightAdapt_increase>::type __type122;
    typedef typename __combined<__type121,__type122>::type __type123;
    typedef typename pythonic::assignable<RunSimulation_GLNetEIMF_adapt_lambda10>::type __type124;
    typedef typename __combined<__type123,__type124>::type __type125;
    typedef typename pythonic::assignable<decltype(std::declval<__type125>()(std::declval<__type120>(), std::declval<__type65>(), std::declval<__type63>(), std::declval<__type64>(), std::declval<__type111>(), std::declval<__type117>()))>::type __type126;
    typedef typename __combined<__type120,__type126>::type __type127;
    typedef typename pythonic::assignable<decltype(std::declval<__type82>()(std::declval<__type84>(), std::declval<__type89>(), std::declval<__type111>(), std::declval<__type117>(), std::declval<__type54>(), std::declval<__type55>(), std::declval<__type118>(), std::declval<__type12>(), std::declval<__type56>(), std::declval<__type57>(), std::declval<__type127>(), std::declval<__type6>(), std::declval<__type58>(), std::declval<__type60>(), std::declval<__type61>(), std::declval<__type51>()))>::type __type128;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type128>::type>::type __type129;
    typedef container<typename std::remove_reference<__type129>::type> __type130;
    typedef typename __combined<__type81,__type130>::type __type131;
    typedef typename __combined<__type86,__type77>::type __type132;
    typedef typename __combined<__type87,__type77>::type __type133;
    typedef typename __combined<__type132,__type133>::type __type134;
    typedef typename GLNetEIMF_adaptthresh_iter::type<__type84, __type89, __type111, __type117, __type54, __type55, __type118, __type12, __type56, __type57, __type127, __type6, __type58, __type60, __type61, __type51>::__ptype10 __type135;
    typedef container<typename std::remove_reference<__type135>::type> __type136;
    typedef typename __combined<__type134,__type136>::type __type137;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type128>::type>::type __type138;
    typedef container<typename std::remove_reference<__type138>::type> __type139;
    typedef typename __combined<__type137,__type139>::type __type140;
    typedef typename std::tuple_element<6,typename std::remove_reference<__type71>::type>::type __type141;
    typedef typename __combined<__type36,__type141>::type __type142;
    typedef decltype(std::declval<__type74>()(std::declval<__type10>())) __type143;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type143>::type::iterator>::value_type>::type __type144;
    typedef indexable<__type144> __type145;
    typedef typename __combined<__type142,__type145>::type __type146;
    typedef typename pythonic::assignable<typename std::tuple_element<6,typename std::remove_reference<__type71>::type>::type>::type __type147;
    typedef typename __combined<__type147,__type145>::type __type148;
    typedef typename __combined<__type146,__type148>::type __type149;
    typedef typename __combined<__type142,__type147>::type __type150;
    typedef decltype(std::declval<__type150>()[std::declval<__type144>()]) __type151;
    typedef typename std::tuple_element<7,typename std::remove_reference<__type71>::type>::type __type152;
    typedef typename __combined<__type37,__type152>::type __type153;
    typedef typename pythonic::assignable<typename std::tuple_element<7,typename std::remove_reference<__type71>::type>::type>::type __type154;
    typedef typename __combined<__type153,__type154>::type __type155;
    typedef decltype(std::declval<__type155>()[std::declval<__type144>()]) __type156;
    typedef indexable<__type109> __type157;
    typedef typename __combined<__type102,__type157>::type __type158;
    typedef typename __combined<__type158,__type106>::type __type159;
    typedef decltype(std::declval<__type107>()[std::declval<__type109>()]) __type160;
    typedef decltype(std::declval<__type140>()[std::declval<__type76>()]) __type161;
    typedef decltype(pythonic::operator_::add(std::declval<__type160>(), std::declval<__type161>())) __type162;
    typedef container<typename std::remove_reference<__type162>::type> __type163;
    typedef typename __combined<__type159,__type163>::type __type164;
    typedef decltype(std::declval<__type164>()[std::declval<__type110>()]) __type165;
    typedef decltype(std::declval<__type39>()[std::declval<__type144>()]) __type166;
    typedef typename pythonic::assignable<decltype(std::declval<__type82>()(std::declval<__type151>(), std::declval<__type156>(), std::declval<__type165>(), std::declval<__type117>(), std::declval<__type54>(), std::declval<__type55>(), std::declval<__type166>(), std::declval<__type12>(), std::declval<__type56>(), std::declval<__type57>(), std::declval<__type127>(), std::declval<__type6>(), std::declval<__type58>(), std::declval<__type60>(), std::declval<__type61>(), std::declval<__type31>()))>::type __type167;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type167>::type>::type __type168;
    typedef container<typename std::remove_reference<__type168>::type> __type169;
    typedef typename __combined<__type149,__type169>::type __type170;
    typedef typename __combined<__type153,__type145>::type __type171;
    typedef typename __combined<__type154,__type145>::type __type172;
    typedef typename __combined<__type171,__type172>::type __type173;
    typedef typename GLNetEIMF_adaptthresh_iter::type<__type151, __type156, __type165, __type117, __type54, __type55, __type166, __type12, __type56, __type57, __type127, __type6, __type58, __type60, __type61, __type31>::__ptype10 __type174;
    typedef container<typename std::remove_reference<__type174>::type> __type175;
    typedef typename __combined<__type173,__type175>::type __type176;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type167>::type>::type __type177;
    typedef container<typename std::remove_reference<__type177>::type> __type178;
    typedef typename __combined<__type176,__type178>::type __type179;
    typedef typename __combined<__type38,__type77>::type __type180;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type128>::type>::type __type181;
    typedef container<typename std::remove_reference<__type181>::type> __type182;
    typedef typename __combined<__type180,__type182>::type __type183;
    typedef typename __combined<__type39,__type145>::type __type184;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type167>::type>::type __type185;
    typedef container<typename std::remove_reference<__type185>::type> __type186;
    typedef typename __combined<__type184,__type186>::type __type187;
    typedef typename pythonic::lazy<__type28>::type __type188;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type71>::type>::type __type189;
    typedef typename pythonic::lazy<__type189>::type __type190;
    typedef typename __combined<__type188,__type190>::type __type191;
    typedef typename __combined<__type159,__type101>::type __type192;
    typedef typename __combined<__type192,__type163>::type __type193;
    typedef typename __combined<__type193,__type157>::type __type194;
    typedef decltype(std::declval<__type164>()[std::declval<__type109>()]) __type195;
    typedef decltype(pythonic::operator_::div(std::declval<__type195>(), std::declval<__type45>())) __type196;
    typedef container<typename std::remove_reference<__type196>::type> __type197;
    typedef typename __combined<__type158,__type115>::type __type198;
    typedef typename __combined<__type198,__type101>::type __type199;
    typedef decltype(std::declval<__type116>()[std::declval<__type109>()]) __type200;
    typedef decltype(std::declval<__type179>()[std::declval<__type144>()]) __type201;
    typedef decltype(pythonic::operator_::add(std::declval<__type200>(), std::declval<__type201>())) __type202;
    typedef container<typename std::remove_reference<__type202>::type> __type203;
    typedef typename __combined<__type199,__type203>::type __type204;
    typedef typename __combined<__type204,__type157>::type __type205;
    typedef typename __combined<__type198,__type203>::type __type206;
    typedef decltype(std::declval<__type206>()[std::declval<__type109>()]) __type207;
    typedef decltype(pythonic::operator_::div(std::declval<__type207>(), std::declval<__type46>())) __type208;
    typedef container<typename std::remove_reference<__type208>::type> __type209;
    typedef container<typename std::remove_reference<__type120>::type> __type210;
    typedef typename __combined<__type158,__type210>::type __type211;
    typedef typename __combined<__type211,__type101>::type __type212;
    typedef container<typename std::remove_reference<__type127>::type> __type213;
    typedef typename __combined<__type212,__type213>::type __type214;
    typedef container<typename std::remove_reference<__type191>::type> __type215;
    typedef typename __combined<__type158,__type215>::type __type216;
    typedef typename __combined<__type216,__type101>::type __type217;
    typedef typename pythonic::assignable<double>::type __type218;
    typedef decltype(std::declval<__type183>()[std::declval<__type76>()]) __type219;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::add(std::declval<__type218>(), std::declval<__type219>()))>::type __type220;
    typedef typename __combined<__type218,__type220>::type __type221;
    typedef decltype(std::declval<__type187>()[std::declval<__type144>()]) __type222;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::add(std::declval<__type221>(), std::declval<__type222>()))>::type __type223;
    typedef typename __combined<__type221,__type223>::type __type224;
    typedef decltype(pythonic::operator_::div(std::declval<__type224>(), std::declval<__type44>())) __type225;
    typedef container<typename std::remove_reference<__type225>::type> __type226;
    typedef typename __combined<__type217,__type226>::type __type227;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::functools::functor::partial{})>::type>::type __type228;
    typedef RunSimulation_GLNetEIMF_adapt_lambda11 __type229;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::open{})>::type>::type __type230;
    typedef typename pythonic::assignable<typename std::tuple_element<34,typename std::remove_reference<__type3>::type>::type>::type __type231;
    typedef pythonic::types::str __type232;
    typedef typename pythonic::assignable<decltype(std::declval<__type230>()(std::declval<__type231>(), std::declval<__type232>()))>::type __type233;
    typedef typename pythonic::assignable<decltype(std::declval<__type228>()(std::declval<__type229>(), std::declval<__type233>()))>::type __type234;
    typedef typename pythonic::assignable<write_spk_data_fake>::type __type235;
    typedef typename pythonic::assignable<save_spk_data_fake>::type __type236;
    typedef typename pythonic::assignable<save_spk_data>::type __type237;
    typedef decltype(pythonic::types::make_tuple(std::declval<__type93>(), std::declval<__type93>())) __type238;
    typedef typename pythonic::assignable<pythonic::types::list<typename std::remove_reference<__type238>::type>>::type __type239;
    typedef save_initial_spkdata __type240;
    typedef typename pythonic::assignable<typename std::tuple_element<28,typename std::remove_reference<__type3>::type>::type>::type __type241;
    typedef decltype(pythonic::operator_::mul(std::declval<__type6>(), std::declval<__type241>())) __type242;
    typedef typename pythonic::assignable<decltype(std::declval<__type5>()(std::declval<__type242>()))>::type __type243;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type241>(), std::declval<__type243>()))>::type __type244;
    typedef typename pythonic::assignable<decltype(std::declval<__type240>()(std::declval<__type88>(), std::declval<__type155>(), std::declval<__type243>(), std::declval<__type244>()))>::type __type245;
    typedef typename __combined<__type239,__type245>::type __type246;
    typedef typename save_spk_data::type<__type246, __type109, __type76>::__ptype0 __type247;
    typedef pythonic::types::list<typename std::remove_reference<__type247>::type> __type248;
    typedef typename __combined<__type239,__type248>::type __type249;
    typedef typename __combined<__type246,__type248>::type __type250;
    typedef typename save_spk_data::type<__type250, __type109, __type76>::__ptype1 __type251;
    typedef pythonic::types::list<typename std::remove_reference<__type251>::type> __type252;
    typedef typename __combined<__type249,__type252>::type __type253;
    typedef typename __combined<__type236,__type237>::type __type254;
    typedef typename __combined<__type250,__type252>::type __type255;
    typedef decltype(std::declval<__type254>()(std::declval<__type255>(), std::declval<__type109>(), std::declval<__type76>())) __type256;
    typedef typename __combined<__type253,__type256>::type __type257;
    typedef typename __combined<__type245,__type248>::type __type258;
    typedef typename __combined<__type258,__type252>::type __type259;
    typedef typename __combined<__type259,__type256>::type __type260;
    typedef typename __combined<__type257,__type260>::type __type261;
    typedef typename __combined<__type261,__type255>::type __type262;
    typedef typename __combined<__type248,__type252>::type __type263;
    typedef typename __combined<__type263,__type256>::type __type264;
    typedef typename __combined<__type262,__type264>::type __type265;
    typedef typename pythonic::assignable<typename __combined<__type263,__type256>::type>::type __type266;
    typedef typename __combined<__type265,__type266>::type __type267;
    typedef decltype(pythonic::operator_::add(std::declval<__type144>(), std::declval<__type243>())) __type268;
    typedef typename save_spk_data::type<__type267, __type109, __type268>::__ptype0 __type269;
    typedef pythonic::types::list<typename std::remove_reference<__type269>::type> __type270;
    typedef typename __combined<__type257,__type270>::type __type271;
    typedef typename __combined<__type267,__type270>::type __type272;
    typedef typename save_spk_data::type<__type272, __type109, __type268>::__ptype1 __type273;
    typedef pythonic::types::list<typename std::remove_reference<__type273>::type> __type274;
    typedef typename __combined<__type271,__type274>::type __type275;
    typedef typename __combined<__type272,__type274>::type __type276;
    typedef decltype(std::declval<__type254>()(std::declval<__type276>(), std::declval<__type109>(), std::declval<__type268>())) __type277;
    typedef typename __combined<__type275,__type277>::type __type278;
    typedef typename __combined<__type260,__type270>::type __type279;
    typedef typename __combined<__type279,__type274>::type __type280;
    typedef typename __combined<__type280,__type277>::type __type281;
    typedef typename __combined<__type278,__type281>::type __type282;
    typedef typename __combined<__type282,__type255>::type __type283;
    typedef typename __combined<__type264,__type270>::type __type284;
    typedef typename __combined<__type284,__type274>::type __type285;
    typedef typename pythonic::assignable<typename __combined<__type285,__type277>::type>::type __type286;
    typedef typename __combined<__type283,__type286>::type __type287;
    typedef typename __combined<__type266,__type270>::type __type288;
    typedef typename __combined<__type288,__type274>::type __type289;
    typedef typename __combined<__type289,__type277>::type __type290;
    typedef typename __combined<__type287,__type290>::type __type291;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type75>::type::iterator>::value_type>::type>::type i;
    typename pythonic::assignable<typename __combined<__type123,__type124>::type>::type weightAdapt;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type108>::type::iterator>::value_type>::type>::type t;
    typename pythonic::assignable<typename __combined<__type234,__type235>::type>::type write_spk_time;
    typename pythonic::assignable<typename __combined<__type236,__type237>::type>::type save_spk_time;
    typename pythonic::assignable<typename __combined<__type291,__type276>::type>::type spkData;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type143>::type::iterator>::value_type>::type>::type i_;
    typename pythonic::assignable<typename pythonic::assignable<decltype(std::declval<__type230>()(std::declval<__type231>(), std::declval<__type232>()))>::type>::type spkTimeFile;
    typename pythonic::assignable<typename __combined<__type3,__type29>::type>::type __tuple0 = get_system_parameters()(simParam_dict, paramType_dict);
    typename pythonic::assignable_noescape<decltype(std::get<0>(__tuple0))>::type N = std::get<0>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<1>(__tuple0))>::type tTrans = std::get<1>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<13>(__tuple0))>::type mu = std::get<13>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<15>(__tuple0))>::type J = std::get<15>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<16>(__tuple0))>::type Gamma = std::get<16>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<17>(__tuple0))>::type I = std::get<17>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<18>(__tuple0))>::type Iext = std::get<18>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<20>(__tuple0))>::type p = std::get<20>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<21>(__tuple0))>::type q = std::get<21>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<22>(__tuple0))>::type A = std::get<22>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<24>(__tuple0))>::type uW = std::get<24>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<26>(__tuple0))>::type uT = std::get<26>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<27>(__tuple0))>::type saveSpikingData = std::get<27>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<28>(__tuple0))>::type nNeuronsSpk = std::get<28>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<29>(__tuple0))>::type weightDynType = std::get<29>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<33>(__tuple0))>::type writeOnRun = std::get<33>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<34>(__tuple0))>::type spkFileName = std::get<34>(__tuple0);
    if (pythonic::operator_::eq(weightDynType, pythonic::types::str("simple")))
    {
      weightAdapt = weightAdapt_decrease();
    }
    else
    {
      if (pythonic::operator_::eq(weightDynType, pythonic::types::str("coupled")))
      {
        weightAdapt = weightAdapt_increase();
      }
      else
      {
        throw pythonic::builtins::functor::ValueError{}(pythonic::types::str("weightDynType is unknown"));
      }
    }
    if (pythonic::operator_::eq(q, 0.0))
    {
      weightAdapt = RunSimulation_GLNetEIMF_adapt_lambda10();
    }
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::div(1.0, std::get<23>(__tuple0)))>::type tauWinv = pythonic::operator_::div(1.0, std::get<23>(__tuple0));
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::div(1.0, std::get<25>(__tuple0)))>::type tauTinv = pythonic::operator_::div(1.0, std::get<25>(__tuple0));
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, N)))>::type pN = pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, N));
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(N, pN))>::type qN = pythonic::operator_::sub(N, pN);
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::float_{}(N))>::type N_fl = pythonic::builtins::functor::float_{}(N);
    typename pythonic::assignable<typename pythonic::assignable<typename __combined<__type30,__type31>::type>::type>::type pN_fl = (((bool)pythonic::operator_::gt(pN, 0L)) ? typename __combined<decltype(pythonic::builtins::functor::float_{}(pN)), decltype(1.0)>::type(pythonic::builtins::functor::float_{}(pN)) : typename __combined<decltype(pythonic::builtins::functor::float_{}(pN)), decltype(1.0)>::type(1.0));
    typename pythonic::assignable<typename pythonic::assignable<typename __combined<__type32,__type31>::type>::type>::type qN_fl = (((bool)pythonic::operator_::gt(qN, 0L)) ? typename __combined<decltype(pythonic::builtins::functor::float_{}(qN)), decltype(1.0)>::type(pythonic::builtins::functor::float_{}(qN)) : typename __combined<decltype(pythonic::builtins::functor::float_{}(qN)), decltype(1.0)>::type(1.0));
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, nNeuronsSpk)))>::type pN_s = pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, nNeuronsSpk));
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(nNeuronsSpk, pN_s))>::type qN_s = pythonic::operator_::sub(nNeuronsSpk, pN_s);
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(1.0, pythonic::numpy::functor::exp{}(pythonic::operator_::neg(std::get<30>(__tuple0)))))>::type P_firing_poisson = pythonic::operator_::sub(1.0, pythonic::numpy::functor::exp{}(pythonic::operator_::neg(std::get<30>(__tuple0))));
    typename pythonic::assignable_noescape<decltype(set_MF_network_IC()(pN, qN, std::get<19>(__tuple0), J, std::get<3>(__tuple0), std::get<4>(__tuple0), std::get<5>(__tuple0), std::get<6>(__tuple0), pythonic::builtins::functor::float_{}(std::get<7>(__tuple0)), std::get<8>(__tuple0), std::get<9>(__tuple0), pythonic::builtins::functor::float_{}(std::get<10>(__tuple0)), std::get<11>(__tuple0), std::get<12>(__tuple0), std::get<14>(__tuple0)))>::type __tuple1 = set_MF_network_IC()(pN, qN, std::get<19>(__tuple0), J, std::get<3>(__tuple0), std::get<4>(__tuple0), std::get<5>(__tuple0), std::get<6>(__tuple0), pythonic::builtins::functor::float_{}(std::get<7>(__tuple0)), std::get<8>(__tuple0), std::get<9>(__tuple0), pythonic::builtins::functor::float_{}(std::get<10>(__tuple0)), std::get<11>(__tuple0), std::get<12>(__tuple0), std::get<14>(__tuple0));
    typename pythonic::assignable<typename __combined<__type131,__type77>::type>::type VE = std::get<0>(__tuple1);
    typename pythonic::assignable<typename __combined<__type140,__type77>::type>::type XE = std::get<1>(__tuple1);
    typename pythonic::assignable<typename __combined<__type170,__type145>::type>::type VI = std::get<2>(__tuple1);
    typename pythonic::assignable<typename __combined<__type179,__type145>::type>::type XI = std::get<3>(__tuple1);
    typename pythonic::lazy<__type105>::type rhoETemp = std::get<4>(__tuple1);
    typename pythonic::lazy<__type114>::type rhoITemp = std::get<5>(__tuple1);
    typename pythonic::assignable<typename __combined<__type183,__type77>::type>::type thetaE = std::get<6>(__tuple1);
    typename pythonic::assignable<typename __combined<__type187,__type145>::type>::type thetaI = std::get<7>(__tuple1);
    typename pythonic::assignable<typename __combined<__type120,__type126>::type>::type W_I = std::get<8>(__tuple1);
    typename pythonic::lazy<__type191>::type thetaMean = std::get<9>(__tuple1);
    if (pythonic::operator_::gt(tTrans, 0L))
    {
      typename pythonic::assignable_noescape<decltype(run_transient_GLNetEIMF_adapt()(VE, XE, VI, XI, thetaE, thetaI, rhoETemp, rhoITemp, N_fl, pN, qN, pN_fl, qN_fl, P_firing_poisson, weightDynType, tTrans, Iext, mu, J, Gamma, I, p, q, tauTinv, uT, tauWinv, uW, A, W_I))>::type __tuple2 = run_transient_GLNetEIMF_adapt()(VE, XE, VI, XI, thetaE, thetaI, rhoETemp, rhoITemp, N_fl, pN, qN, pN_fl, qN_fl, P_firing_poisson, weightDynType, tTrans, Iext, mu, J, Gamma, I, p, q, tauTinv, uT, tauWinv, uW, A, W_I);
      rhoETemp = std::get<0>(__tuple2);
      rhoITemp = std::get<1>(__tuple2);
      thetaMean = std::get<2>(__tuple2);
      W_I = std::get<3>(__tuple2);
      VE = std::get<4>(__tuple2);
      XE = std::get<5>(__tuple2);
      VI = std::get<6>(__tuple2);
      XI = std::get<7>(__tuple2);
    }
    typename pythonic::assignable<typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type95>(), std::declval<__type53>()))>::type>::type Tmax_ = pythonic::operator_::sub(std::get<2>(__tuple0), tTrans);
    if (saveSpikingData)
    {
      if (writeOnRun)
      {
        pythonic::builtins::functor::print{}(pythonic::builtins::str::functor::__mod__{}(pythonic::types::str("*** writing file %s during simulation"), spkFileName));
        spkData = typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::types::make_tuple(0L, 0L))>::type>::type>::type>>::type>::type({pythonic::types::make_tuple(0L, 0L), pythonic::types::single_value()});
        spkTimeFile = pythonic::builtins::functor::open{}(spkFileName, pythonic::types::str("w"));
        write_spk_time = pythonic::functools::functor::partial{}(RunSimulation_GLNetEIMF_adapt_lambda11(), spkTimeFile);
        save_spk_time = save_spk_data_fake();
      }
      else
      {
        write_spk_time = write_spk_data_fake();
        save_spk_time = save_spk_data();
        spkData = save_initial_spkdata()(XE, XI, pN_s, qN_s);
      }
    }
    else
    {
      save_spk_time = save_spk_data_fake();
      write_spk_time = write_spk_data_fake();
      spkData = typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::types::make_tuple(0L, 0L))>::type>::type>::type>>::type>::type({pythonic::types::make_tuple(0L, 0L), pythonic::types::single_value()});
    }
    typename pythonic::assignable<typename __combined<__type194,__type197>::type>::type rhoE = pythonic::numpy::functor::array{}(pythonic::operator_::mul(typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<double>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(0.0)>::type>::type>::type>>::type>::type({0.0, pythonic::types::single_value()}), pythonic::builtins::functor::max{}(0L, Tmax_)));
    typename pythonic::assignable<typename __combined<__type205,__type209>::type>::type rhoI = pythonic::numpy::functor::array{}(pythonic::operator_::mul(typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<double>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(0.0)>::type>::type>::type>>::type>::type({0.0, pythonic::types::single_value()}), pythonic::builtins::functor::max{}(0L, Tmax_)));
    typename pythonic::assignable<typename __combined<__type214,__type157>::type>::type W_I_data = pythonic::numpy::functor::array{}(pythonic::operator_::mul(typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<double>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(0.0)>::type>::type>::type>>::type>::type({0.0, pythonic::types::single_value()}), pythonic::builtins::functor::max{}(0L, Tmax_)));
    typename pythonic::assignable<typename __combined<__type227,__type157>::type>::type theta_data = pythonic::numpy::functor::array{}(pythonic::operator_::mul(typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<double>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(0.0)>::type>::type>::type>>::type>::type({0.0, pythonic::types::single_value()}), pythonic::builtins::functor::max{}(0L, Tmax_)));
    std::get<0>(rhoE) = rhoETemp;
    std::get<0>(rhoI) = rhoITemp;
    std::get<0>(W_I_data) = W_I;
    std::get<0>(theta_data) = thetaMean;
    {
      long  __target140219922009920 = Tmax_;
      for (long  t=1L; t < __target140219922009920; t += 1L)
      {
        W_I = weightAdapt(W_I, A, tauWinv, uW, rhoE[pythonic::operator_::sub(t, 1L)], rhoI[pythonic::operator_::sub(t, 1L)]);
        typename pythonic::assignable<typename __combined<__type221,__type223>::type>::type thetaMean_ = 0.0;
        {
          long  __target140219922028480 = pN;
          for (long  i=0L; i < __target140219922028480; i += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_adaptthresh_iter()(VE[i], XE[i], rhoE[pythonic::operator_::sub(t, 1L)], rhoI[pythonic::operator_::sub(t, 1L)], Iext, mu, thetaE[i], J, Gamma, I, W_I, p, q, tauTinv, uT, P_firing_poisson))>::type __tuple3 = GLNetEIMF_adaptthresh_iter()(VE[i], XE[i], rhoE[pythonic::operator_::sub(t, 1L)], rhoI[pythonic::operator_::sub(t, 1L)], Iext, mu, thetaE[i], J, Gamma, I, W_I, p, q, tauTinv, uT, P_firing_poisson);
            VE[i] = std::get<0>(__tuple3);
            XE[i] = std::get<1>(__tuple3);
            thetaE[i] = std::get<2>(__tuple3);
            rhoE[t] = pythonic::operator_::add(rhoE[t], XE[i]);
            thetaMean_ = pythonic::operator_::add(thetaMean_, thetaE[i]);
            if (pythonic::builtins::pythran::and_([&] () { return pythonic::operator_::lt(i, pN_s); }, [&] () { return XE[i]; }))
            {
              spkData = save_spk_time(spkData, t, i);
              write_spk_time(t, i);
            }
          }
        }
        {
          long  __target140219922028576 = qN;
          for (long  i_=0L; i_ < __target140219922028576; i_ += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIMF_adaptthresh_iter()(VI[i_], XI[i_], rhoE[pythonic::operator_::sub(t, 1L)], rhoI[pythonic::operator_::sub(t, 1L)], Iext, mu, thetaI[i_], J, Gamma, I, W_I, p, q, tauTinv, uT, 0.0))>::type __tuple4 = GLNetEIMF_adaptthresh_iter()(VI[i_], XI[i_], rhoE[pythonic::operator_::sub(t, 1L)], rhoI[pythonic::operator_::sub(t, 1L)], Iext, mu, thetaI[i_], J, Gamma, I, W_I, p, q, tauTinv, uT, 0.0);
            VI[i_] = std::get<0>(__tuple4);
            XI[i_] = std::get<1>(__tuple4);
            thetaI[i_] = std::get<2>(__tuple4);
            rhoI[t] = pythonic::operator_::add(rhoI[t], XI[i_]);
            thetaMean_ = pythonic::operator_::add(thetaMean_, thetaI[i_]);
            if (pythonic::builtins::pythran::and_([&] () { return pythonic::operator_::lt(i_, qN_s); }, [&] () { return XI[i_]; }))
            {
              spkData = save_spk_time(spkData, t, pythonic::operator_::add(i_, pN_s));
              write_spk_time(t, pythonic::operator_::add(i_, pN_s));
            }
          }
        }
        rhoE[t] = pythonic::operator_::div(rhoE[t], pN_fl);
        rhoI[t] = pythonic::operator_::div(rhoI[t], qN_fl);
        W_I_data[t] = W_I;
        theta_data[t] = pythonic::operator_::div(thetaMean_, N_fl);
      }
    }
    if (pythonic::builtins::pythran::and_([&] () { return saveSpikingData; }, [&] () { return writeOnRun; }))
    {
      pythonic::io::_io::TextIOWrapper::functor::close{}(spkTimeFile);
    }
    return pythonic::types::make_tuple(rhoE, rhoI, spkData, pythonic::numpy::functor::multiply{}(pythonic::operator_::mul(p, J), rhoE), pythonic::numpy::functor::multiply{}(q, pythonic::numpy::functor::multiply{}(W_I_data, rhoI)), pythonic::numpy::functor::divide{}(W_I_data, J), pythonic::numpy::functor::divide{}(I, theta_data));
  }
  template <typename argument_type0 , typename argument_type1 >
  typename RunSimulation_GLNetEIRand_static::type<argument_type0, argument_type1>::result_type RunSimulation_GLNetEIRand_static::operator()(argument_type0&& simParam_dict, argument_type1&& paramType_dict) const
  {
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::float_{})>::type>::type __type0;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::int_{})>::type>::type __type1;
    typedef get_system_parameters __type2;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type0>::type>::type __type3;
    typedef typename std::remove_cv<typename std::remove_reference<argument_type1>::type>::type __type4;
    typedef typename pythonic::assignable<decltype(std::declval<__type2>()(std::declval<__type3>(), std::declval<__type4>()))>::type __type5;
    typedef typename pythonic::assignable<typename std::tuple_element<20,typename std::remove_reference<__type5>::type>::type>::type __type6;
    typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type5>::type>::type>::type __type7;
    typedef decltype(pythonic::operator_::mul(std::declval<__type6>(), std::declval<__type7>())) __type8;
    typedef typename pythonic::assignable<decltype(std::declval<__type1>()(std::declval<__type8>()))>::type __type9;
    typedef decltype(std::declval<__type0>()(std::declval<__type9>())) __type10;
    typedef double __type11;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type7>(), std::declval<__type9>()))>::type __type12;
    typedef decltype(std::declval<__type0>()(std::declval<__type12>())) __type13;
    typedef set_MF_network_IC __type14;
    typedef typename pythonic::assignable<typename std::tuple_element<19,typename std::remove_reference<__type5>::type>::type>::type __type15;
    typedef typename pythonic::assignable<typename std::tuple_element<15,typename std::remove_reference<__type5>::type>::type>::type __type16;
    typedef typename std::tuple_element<3,typename std::remove_reference<__type5>::type>::type __type17;
    typedef typename std::tuple_element<4,typename std::remove_reference<__type5>::type>::type __type18;
    typedef typename std::tuple_element<5,typename std::remove_reference<__type5>::type>::type __type19;
    typedef typename std::tuple_element<6,typename std::remove_reference<__type5>::type>::type __type20;
    typedef typename std::tuple_element<7,typename std::remove_reference<__type5>::type>::type __type21;
    typedef decltype(std::declval<__type0>()(std::declval<__type21>())) __type22;
    typedef typename std::tuple_element<8,typename std::remove_reference<__type5>::type>::type __type23;
    typedef typename std::tuple_element<9,typename std::remove_reference<__type5>::type>::type __type24;
    typedef typename std::tuple_element<10,typename std::remove_reference<__type5>::type>::type __type25;
    typedef decltype(std::declval<__type0>()(std::declval<__type25>())) __type26;
    typedef typename std::tuple_element<11,typename std::remove_reference<__type5>::type>::type __type27;
    typedef typename std::tuple_element<12,typename std::remove_reference<__type5>::type>::type __type28;
    typedef typename pythonic::assignable<typename std::tuple_element<14,typename std::remove_reference<__type5>::type>::type>::type __type29;
    typedef typename pythonic::assignable<decltype(std::declval<__type14>()(std::declval<__type9>(), std::declval<__type12>(), std::declval<__type15>(), std::declval<__type16>(), std::declval<__type17>(), std::declval<__type18>(), std::declval<__type19>(), std::declval<__type20>(), std::declval<__type22>(), std::declval<__type23>(), std::declval<__type24>(), std::declval<__type26>(), std::declval<__type27>(), std::declval<__type28>(), std::declval<__type29>()))>::type __type30;
    typedef typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type30>::type>::type>::type __type31;
    typedef run_transient_GLNetEIRand_static __type32;
    typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type30>::type>::type>::type __type33;
    typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type30>::type>::type>::type __type34;
    typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type30>::type>::type>::type __type35;
    typedef typename pythonic::assignable<typename std::tuple_element<1,typename std::remove_reference<__type5>::type>::type>::type __type36;
    typedef typename std::tuple_element<4,typename std::remove_reference<__type30>::type>::type __type37;
    typedef typename pythonic::lazy<__type37>::type __type38;
    typedef typename std::tuple_element<5,typename std::remove_reference<__type30>::type>::type __type39;
    typedef typename pythonic::lazy<__type39>::type __type40;
    typedef typename pythonic::assignable<typename __combined<__type10,__type11>::type>::type __type41;
    typedef typename pythonic::assignable<typename __combined<__type13,__type11>::type>::type __type42;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::exp{})>::type>::type __type43;
    typedef typename std::tuple_element<30,typename std::remove_reference<__type5>::type>::type __type44;
    typedef decltype(pythonic::operator_::neg(std::declval<__type44>())) __type45;
    typedef decltype(std::declval<__type43>()(std::declval<__type45>())) __type46;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type11>(), std::declval<__type46>()))>::type __type47;
    typedef typename pythonic::assignable<typename std::tuple_element<18,typename std::remove_reference<__type5>::type>::type>::type __type48;
    typedef typename pythonic::assignable<typename std::tuple_element<13,typename std::remove_reference<__type5>::type>::type>::type __type49;
    typedef typename pythonic::assignable<typename std::tuple_element<16,typename std::remove_reference<__type5>::type>::type>::type __type50;
    typedef typename pythonic::assignable<typename std::tuple_element<17,typename std::remove_reference<__type5>::type>::type>::type __type51;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::array{})>::type>::type __type52;
    typedef pythonic::types::list<typename std::remove_reference<__type11>::type> __type53;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::max{})>::type>::type __type54;
    typedef long __type55;
    typedef typename __combined<__type55,__type7>::type __type56;
    typedef decltype(std::declval<__type54>()(std::declval<__type56>(), std::declval<__type7>())) __type57;
    typedef decltype(pythonic::operator_::mul(std::declval<__type53>(), std::declval<__type57>())) __type58;
    typedef typename pythonic::assignable<decltype(std::declval<__type52>()(std::declval<__type58>()))>::type __type59;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::mul(std::declval<__type15>(), std::declval<__type16>()))>::type __type60;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::map{})>::type>::type __type61;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::functools::functor::partial{})>::type>::type __type62;
    typedef generate_random_net_fixed_input_lambda15 __type63;
    typedef typename pythonic::assignable<typename std::tuple_element<31,typename std::remove_reference<__type5>::type>::type>::type __type64;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::numpy::functor::ceil{})>::type>::type __type65;
    typedef decltype(std::declval<__type0>()(std::declval<__type64>())) __type66;
    typedef decltype(pythonic::operator_::mul(std::declval<__type6>(), std::declval<__type66>())) __type67;
    typedef decltype(std::declval<__type65>()(std::declval<__type67>())) __type68;
    typedef typename pythonic::assignable<decltype(std::declval<__type1>()(std::declval<__type68>()))>::type __type69;
    typedef typename pythonic::assignable<typename pythonic::assignable<typename std::tuple_element<0,typename std::remove_reference<__type5>::type>::type>::type>::type __type70;
    typedef decltype(std::declval<__type62>()(std::declval<__type63>(), std::declval<__type64>(), std::declval<__type69>(), std::declval<__type70>(), std::declval<__type9>())) __type71;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::range{})>::type>::type __type72;
    typedef decltype(std::declval<__type72>()(std::declval<__type70>())) __type73;
    typedef decltype(std::declval<__type61>()(std::declval<__type71>(), std::declval<__type73>())) __type74;
    typedef typename pythonic::assignable<decltype(std::declval<__type52>()(std::declval<__type74>()))>::type __type75;
    typedef typename run_transient_GLNetEIRand_static::type<__type31, __type33, __type34, __type35, __type36, __type38, __type40, __type9, __type12, __type41, __type42, __type47, __type48, __type49, __type29, __type50, __type51, __type59, __type16, __type60, __type75, __type69, __type64>::__ptype82 __type76;
    typedef typename __combined<__type38,__type76>::type __type77;
    typedef typename run_transient_GLNetEIRand_static::type<__type31, __type33, __type34, __type35, __type36, __type77, __type40, __type9, __type12, __type41, __type42, __type47, __type48, __type49, __type29, __type50, __type51, __type59, __type16, __type60, __type75, __type69, __type64>::__ptype83 __type78;
    typedef typename __combined<__type40,__type78>::type __type79;
    typedef typename pythonic::assignable<decltype(std::declval<__type32>()(std::declval<__type31>(), std::declval<__type33>(), std::declval<__type34>(), std::declval<__type35>(), std::declval<__type36>(), std::declval<__type77>(), std::declval<__type79>(), std::declval<__type9>(), std::declval<__type12>(), std::declval<__type41>(), std::declval<__type42>(), std::declval<__type47>(), std::declval<__type48>(), std::declval<__type49>(), std::declval<__type29>(), std::declval<__type50>(), std::declval<__type51>(), std::declval<__type59>(), std::declval<__type16>(), std::declval<__type60>(), std::declval<__type75>(), std::declval<__type69>(), std::declval<__type64>()))>::type __type80;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type80>::type>::type __type81;
    typedef typename __combined<__type31,__type81>::type __type82;
    typedef decltype(std::declval<__type72>()(std::declval<__type9>())) __type83;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type83>::type::iterator>::value_type>::type __type84;
    typedef indexable<__type84> __type85;
    typedef typename __combined<__type82,__type85>::type __type86;
    typedef typename pythonic::assignable<typename std::tuple_element<2,typename std::remove_reference<__type80>::type>::type>::type __type87;
    typedef typename __combined<__type87,__type85>::type __type88;
    typedef typename __combined<__type86,__type88>::type __type89;
    typedef GLNetEIRand_iter __type90;
    typedef typename __combined<__type82,__type87>::type __type91;
    typedef decltype(std::declval<__type91>()[std::declval<__type84>()]) __type92;
    typedef typename std::tuple_element<3,typename std::remove_reference<__type80>::type>::type __type93;
    typedef typename __combined<__type33,__type93>::type __type94;
    typedef typename pythonic::assignable<typename std::tuple_element<3,typename std::remove_reference<__type80>::type>::type>::type __type95;
    typedef typename __combined<__type94,__type95>::type __type96;
    typedef decltype(std::declval<__type96>()[std::declval<__type84>()]) __type97;
    typedef typename std::tuple_element<5,typename std::remove_reference<__type80>::type>::type __type98;
    typedef typename __combined<__type35,__type98>::type __type99;
    typedef typename pythonic::assignable<typename std::tuple_element<5,typename std::remove_reference<__type80>::type>::type>::type __type100;
    typedef typename __combined<__type99,__type100>::type __type101;
    typedef typename sumSynpaticInput_homog::type<__type59, __type69, __type64, __type7, __type96, __type101, __type16, __type60, __type75>::__ptype2 __type102;
    typedef container<typename std::remove_reference<__type102>::type> __type103;
    typedef typename __combined<__type59,__type103>::type __type104;
    typedef typename sumSynpaticInput_homog::type<__type104, __type69, __type64, __type7, __type96, __type101, __type16, __type60, __type75>::__ptype3 __type105;
    typedef indexable<__type105> __type106;
    typedef typename __combined<__type104,__type106>::type __type107;
    typedef decltype(std::declval<__type107>()[std::declval<__type84>()]) __type108;
    typedef typename pythonic::assignable<decltype(std::declval<__type90>()(std::declval<__type92>(), std::declval<__type97>(), std::declval<__type108>(), std::declval<__type48>(), std::declval<__type49>(), std::declval<__type29>(), std::declval<__type50>(), std::declval<__type51>(), std::declval<__type47>()))>::type __type109;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type109>::type>::type __type110;
    typedef container<typename std::remove_reference<__type110>::type> __type111;
    typedef typename __combined<__type89,__type111>::type __type112;
    typedef typename __combined<__type94,__type85>::type __type113;
    typedef typename __combined<__type95,__type85>::type __type114;
    typedef typename __combined<__type113,__type114>::type __type115;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type109>::type>::type __type116;
    typedef container<typename std::remove_reference<__type116>::type> __type117;
    typedef typename __combined<__type115,__type117>::type __type118;
    typedef typename std::tuple_element<4,typename std::remove_reference<__type80>::type>::type __type119;
    typedef typename __combined<__type34,__type119>::type __type120;
    typedef decltype(std::declval<__type72>()(std::declval<__type12>())) __type121;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type121>::type::iterator>::value_type>::type __type122;
    typedef indexable<__type122> __type123;
    typedef typename __combined<__type120,__type123>::type __type124;
    typedef typename pythonic::assignable<typename std::tuple_element<4,typename std::remove_reference<__type80>::type>::type>::type __type125;
    typedef typename __combined<__type125,__type123>::type __type126;
    typedef typename __combined<__type124,__type126>::type __type127;
    typedef typename __combined<__type120,__type125>::type __type128;
    typedef decltype(std::declval<__type128>()[std::declval<__type122>()]) __type129;
    typedef decltype(std::declval<__type101>()[std::declval<__type122>()]) __type130;
    typedef decltype(std::declval<__type107>()[std::declval<__type122>()]) __type131;
    typedef typename pythonic::assignable<decltype(std::declval<__type90>()(std::declval<__type129>(), std::declval<__type130>(), std::declval<__type131>(), std::declval<__type48>(), std::declval<__type49>(), std::declval<__type29>(), std::declval<__type50>(), std::declval<__type51>(), std::declval<__type11>()))>::type __type132;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type132>::type>::type __type133;
    typedef container<typename std::remove_reference<__type133>::type> __type134;
    typedef typename __combined<__type127,__type134>::type __type135;
    typedef typename __combined<__type99,__type123>::type __type136;
    typedef typename __combined<__type100,__type123>::type __type137;
    typedef typename __combined<__type136,__type137>::type __type138;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type132>::type>::type __type139;
    typedef container<typename std::remove_reference<__type139>::type> __type140;
    typedef typename __combined<__type138,__type140>::type __type141;
    typedef typename std::tuple_element<0,typename std::remove_reference<__type80>::type>::type __type142;
    typedef typename pythonic::lazy<__type142>::type __type143;
    typedef typename __combined<__type77,__type143>::type __type144;
    typedef typename std::tuple_element<1,typename std::remove_reference<__type80>::type>::type __type145;
    typedef typename pythonic::lazy<__type145>::type __type146;
    typedef typename __combined<__type79,__type146>::type __type147;
    typedef typename std::tuple_element<2,typename std::remove_reference<__type5>::type>::type __type148;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type148>(), std::declval<__type36>()))>::type __type149;
    typedef typename __combined<__type55,__type149>::type __type150;
    typedef decltype(std::declval<__type54>()(std::declval<__type150>(), std::declval<__type149>())) __type151;
    typedef decltype(pythonic::operator_::mul(std::declval<__type53>(), std::declval<__type151>())) __type152;
    typedef typename pythonic::assignable<decltype(std::declval<__type52>()(std::declval<__type152>()))>::type __type153;
    typedef indexable<__type55> __type154;
    typedef typename __combined<__type153,__type154>::type __type155;
    typedef decltype(std::declval<__type72>()(std::declval<__type55>(), std::declval<__type149>())) __type156;
    typedef typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type156>::type::iterator>::value_type>::type __type157;
    typedef indexable<__type157> __type158;
    typedef typename __combined<__type155,__type158>::type __type159;
    typedef container<typename std::remove_reference<__type144>::type> __type160;
    typedef typename __combined<__type159,__type160>::type __type161;
    typedef typename __combined<__type161,__type154>::type __type162;
    typedef typename __combined<__type155,__type160>::type __type163;
    typedef decltype(std::declval<__type163>()[std::declval<__type157>()]) __type164;
    typedef decltype(std::declval<__type118>()[std::declval<__type84>()]) __type165;
    typedef decltype(pythonic::operator_::add(std::declval<__type164>(), std::declval<__type165>())) __type166;
    typedef container<typename std::remove_reference<__type166>::type> __type167;
    typedef typename __combined<__type162,__type167>::type __type168;
    typedef typename __combined<__type168,__type158>::type __type169;
    typedef typename __combined<__type161,__type167>::type __type170;
    typedef decltype(std::declval<__type170>()[std::declval<__type157>()]) __type171;
    typedef decltype(pythonic::operator_::div(std::declval<__type171>(), std::declval<__type41>())) __type172;
    typedef container<typename std::remove_reference<__type172>::type> __type173;
    typedef container<typename std::remove_reference<__type147>::type> __type174;
    typedef typename __combined<__type159,__type174>::type __type175;
    typedef typename __combined<__type175,__type154>::type __type176;
    typedef typename __combined<__type155,__type174>::type __type177;
    typedef decltype(std::declval<__type177>()[std::declval<__type157>()]) __type178;
    typedef decltype(std::declval<__type141>()[std::declval<__type122>()]) __type179;
    typedef decltype(pythonic::operator_::add(std::declval<__type178>(), std::declval<__type179>())) __type180;
    typedef container<typename std::remove_reference<__type180>::type> __type181;
    typedef typename __combined<__type176,__type181>::type __type182;
    typedef typename __combined<__type182,__type158>::type __type183;
    typedef typename __combined<__type175,__type181>::type __type184;
    typedef decltype(std::declval<__type184>()[std::declval<__type157>()]) __type185;
    typedef decltype(pythonic::operator_::div(std::declval<__type185>(), std::declval<__type42>())) __type186;
    typedef container<typename std::remove_reference<__type186>::type> __type187;
    typedef RunSimulation_GLNetEIRand_static_lambda0 __type188;
    typedef typename std::remove_cv<typename std::remove_reference<decltype(pythonic::builtins::functor::open{})>::type>::type __type189;
    typedef typename pythonic::assignable<typename std::tuple_element<34,typename std::remove_reference<__type5>::type>::type>::type __type190;
    typedef pythonic::types::str __type191;
    typedef typename pythonic::assignable<decltype(std::declval<__type189>()(std::declval<__type190>(), std::declval<__type191>()))>::type __type192;
    typedef typename pythonic::assignable<decltype(std::declval<__type62>()(std::declval<__type188>(), std::declval<__type192>()))>::type __type193;
    typedef typename pythonic::assignable<write_spk_data_fake>::type __type194;
    typedef typename pythonic::assignable<save_spk_data_fake>::type __type195;
    typedef typename pythonic::assignable<save_spk_data>::type __type196;
    typedef decltype(pythonic::types::make_tuple(std::declval<__type55>(), std::declval<__type55>())) __type197;
    typedef typename pythonic::assignable<pythonic::types::list<typename std::remove_reference<__type197>::type>>::type __type198;
    typedef save_initial_spkdata __type199;
    typedef typename pythonic::assignable<typename std::tuple_element<28,typename std::remove_reference<__type5>::type>::type>::type __type200;
    typedef decltype(pythonic::operator_::mul(std::declval<__type6>(), std::declval<__type200>())) __type201;
    typedef typename pythonic::assignable<decltype(std::declval<__type1>()(std::declval<__type201>()))>::type __type202;
    typedef typename pythonic::assignable<decltype(pythonic::operator_::sub(std::declval<__type200>(), std::declval<__type202>()))>::type __type203;
    typedef typename pythonic::assignable<decltype(std::declval<__type199>()(std::declval<__type96>(), std::declval<__type101>(), std::declval<__type202>(), std::declval<__type203>()))>::type __type204;
    typedef typename __combined<__type198,__type204>::type __type205;
    typedef typename save_spk_data::type<__type205, __type157, __type84>::__ptype0 __type206;
    typedef pythonic::types::list<typename std::remove_reference<__type206>::type> __type207;
    typedef typename __combined<__type198,__type207>::type __type208;
    typedef typename __combined<__type205,__type207>::type __type209;
    typedef typename save_spk_data::type<__type209, __type157, __type84>::__ptype1 __type210;
    typedef pythonic::types::list<typename std::remove_reference<__type210>::type> __type211;
    typedef typename __combined<__type208,__type211>::type __type212;
    typedef typename __combined<__type195,__type196>::type __type213;
    typedef typename __combined<__type209,__type211>::type __type214;
    typedef decltype(std::declval<__type213>()(std::declval<__type214>(), std::declval<__type157>(), std::declval<__type84>())) __type215;
    typedef typename __combined<__type212,__type215>::type __type216;
    typedef typename __combined<__type204,__type207>::type __type217;
    typedef typename __combined<__type217,__type211>::type __type218;
    typedef typename __combined<__type218,__type215>::type __type219;
    typedef typename __combined<__type216,__type219>::type __type220;
    typedef typename __combined<__type220,__type214>::type __type221;
    typedef typename __combined<__type207,__type211>::type __type222;
    typedef typename pythonic::assignable<typename __combined<__type222,__type215>::type>::type __type223;
    typedef typename __combined<__type221,__type223>::type __type224;
    typedef typename __combined<__type222,__type215>::type __type225;
    typedef typename __combined<__type224,__type225>::type __type226;
    typedef decltype(pythonic::operator_::add(std::declval<__type122>(), std::declval<__type202>())) __type227;
    typedef typename save_spk_data::type<__type226, __type157, __type227>::__ptype0 __type228;
    typedef pythonic::types::list<typename std::remove_reference<__type228>::type> __type229;
    typedef typename __combined<__type216,__type229>::type __type230;
    typedef typename __combined<__type226,__type229>::type __type231;
    typedef typename save_spk_data::type<__type231, __type157, __type227>::__ptype1 __type232;
    typedef pythonic::types::list<typename std::remove_reference<__type232>::type> __type233;
    typedef typename __combined<__type230,__type233>::type __type234;
    typedef typename __combined<__type231,__type233>::type __type235;
    typedef decltype(std::declval<__type213>()(std::declval<__type235>(), std::declval<__type157>(), std::declval<__type227>())) __type236;
    typedef typename __combined<__type234,__type236>::type __type237;
    typedef typename __combined<__type219,__type229>::type __type238;
    typedef typename __combined<__type238,__type233>::type __type239;
    typedef typename __combined<__type239,__type236>::type __type240;
    typedef typename __combined<__type237,__type240>::type __type241;
    typedef typename __combined<__type241,__type214>::type __type242;
    typedef typename __combined<__type223,__type229>::type __type243;
    typedef typename __combined<__type243,__type233>::type __type244;
    typedef typename __combined<__type244,__type236>::type __type245;
    typedef typename __combined<__type242,__type245>::type __type246;
    typedef typename __combined<__type225,__type229>::type __type247;
    typedef typename __combined<__type247,__type233>::type __type248;
    typedef typename pythonic::assignable<typename __combined<__type248,__type236>::type>::type __type249;
    typedef typename __combined<__type246,__type249>::type __type250;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type83>::type::iterator>::value_type>::type>::type i;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type156>::type::iterator>::value_type>::type>::type t;
    typename pythonic::assignable<typename __combined<__type193,__type194>::type>::type write_spk_time;
    typename pythonic::assignable<typename __combined<__type195,__type196>::type>::type save_spk_time;
    typename pythonic::assignable<typename __combined<__type250,__type235>::type>::type spkData;
    typename pythonic::assignable<typename std::remove_cv<typename std::iterator_traits<typename std::remove_reference<__type121>::type::iterator>::value_type>::type>::type i_;
    typename pythonic::assignable<typename pythonic::assignable<decltype(std::declval<__type189>()(std::declval<__type190>(), std::declval<__type191>()))>::type>::type spkTimeFile;
    typename pythonic::assignable_noescape<decltype(get_system_parameters()(simParam_dict, paramType_dict))>::type __tuple0 = get_system_parameters()(simParam_dict, paramType_dict);
    typename pythonic::assignable_noescape<decltype(std::get<0>(__tuple0))>::type N = std::get<0>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<1>(__tuple0))>::type tTrans = std::get<1>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<13>(__tuple0))>::type mu = std::get<13>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<14>(__tuple0))>::type theta = std::get<14>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<15>(__tuple0))>::type J = std::get<15>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<16>(__tuple0))>::type Gamma = std::get<16>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<17>(__tuple0))>::type I = std::get<17>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<18>(__tuple0))>::type Iext = std::get<18>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<19>(__tuple0))>::type g = std::get<19>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<20>(__tuple0))>::type p = std::get<20>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<27>(__tuple0))>::type saveSpikingData = std::get<27>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<28>(__tuple0))>::type nNeuronsSpk = std::get<28>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<31>(__tuple0))>::type K = std::get<31>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<33>(__tuple0))>::type writeOnRun = std::get<33>(__tuple0);
    typename pythonic::assignable_noescape<decltype(std::get<34>(__tuple0))>::type spkFileName = std::get<34>(__tuple0);
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, N)))>::type pN = pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, N));
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(N, pN))>::type qN = pythonic::operator_::sub(N, pN);
    typename pythonic::assignable<typename pythonic::assignable<typename __combined<__type10,__type11>::type>::type>::type pN_fl = (((bool)pythonic::operator_::gt(pN, 0L)) ? typename __combined<decltype(pythonic::builtins::functor::float_{}(pN)), decltype(1.0)>::type(pythonic::builtins::functor::float_{}(pN)) : typename __combined<decltype(pythonic::builtins::functor::float_{}(pN)), decltype(1.0)>::type(1.0));
    typename pythonic::assignable<typename pythonic::assignable<typename __combined<__type13,__type11>::type>::type>::type qN_fl = (((bool)pythonic::operator_::gt(qN, 0L)) ? typename __combined<decltype(pythonic::builtins::functor::float_{}(qN)), decltype(1.0)>::type(pythonic::builtins::functor::float_{}(qN)) : typename __combined<decltype(pythonic::builtins::functor::float_{}(qN)), decltype(1.0)>::type(1.0));
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, nNeuronsSpk)))>::type pN_s = pythonic::builtins::functor::int_{}(pythonic::operator_::mul(p, nNeuronsSpk));
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(nNeuronsSpk, pN_s))>::type qN_s = pythonic::operator_::sub(nNeuronsSpk, pN_s);
    typename pythonic::assignable_noescape<decltype(pythonic::builtins::functor::int_{}(pythonic::numpy::functor::ceil{}(pythonic::operator_::mul(p, pythonic::builtins::functor::float_{}(K)))))>::type KE = pythonic::builtins::functor::int_{}(pythonic::numpy::functor::ceil{}(pythonic::operator_::mul(p, pythonic::builtins::functor::float_{}(K))));
    typename pythonic::assignable_noescape<decltype(N)>::type __pythran_inlinegenerate_random_net_fixed_inputN0 = N;
    typename pythonic::assignable_noescape<decltype(pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(generate_random_net_fixed_input_lambda15(), K, KE, __pythran_inlinegenerate_random_net_fixed_inputN0, pN), pythonic::builtins::functor::range{}(__pythran_inlinegenerate_random_net_fixed_inputN0))))>::type C = pythonic::numpy::functor::array{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(generate_random_net_fixed_input_lambda15(), K, KE, __pythran_inlinegenerate_random_net_fixed_inputN0, pN), pythonic::builtins::functor::range{}(__pythran_inlinegenerate_random_net_fixed_inputN0)));
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::mul(g, J))>::type W = pythonic::operator_::mul(g, J);
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(1.0, pythonic::numpy::functor::exp{}(pythonic::operator_::neg(std::get<30>(__tuple0)))))>::type P_firing_poisson = pythonic::operator_::sub(1.0, pythonic::numpy::functor::exp{}(pythonic::operator_::neg(std::get<30>(__tuple0))));
    typename pythonic::assignable_noescape<decltype(set_MF_network_IC()(pN, qN, g, J, std::get<3>(__tuple0), std::get<4>(__tuple0), std::get<5>(__tuple0), std::get<6>(__tuple0), pythonic::builtins::functor::float_{}(std::get<7>(__tuple0)), std::get<8>(__tuple0), std::get<9>(__tuple0), pythonic::builtins::functor::float_{}(std::get<10>(__tuple0)), std::get<11>(__tuple0), std::get<12>(__tuple0), theta))>::type __tuple1 = set_MF_network_IC()(pN, qN, g, J, std::get<3>(__tuple0), std::get<4>(__tuple0), std::get<5>(__tuple0), std::get<6>(__tuple0), pythonic::builtins::functor::float_{}(std::get<7>(__tuple0)), std::get<8>(__tuple0), std::get<9>(__tuple0), pythonic::builtins::functor::float_{}(std::get<10>(__tuple0)), std::get<11>(__tuple0), std::get<12>(__tuple0), theta);
    typename pythonic::assignable<typename __combined<__type112,__type85>::type>::type VE = std::get<0>(__tuple1);
    typename pythonic::assignable<typename __combined<__type118,__type85>::type>::type XE = std::get<1>(__tuple1);
    typename pythonic::assignable<typename __combined<__type135,__type123>::type>::type VI = std::get<2>(__tuple1);
    typename pythonic::assignable<typename __combined<__type141,__type123>::type>::type XI = std::get<3>(__tuple1);
    typename pythonic::lazy<__type144>::type rhoETemp = std::get<4>(__tuple1);
    typename pythonic::lazy<__type147>::type rhoITemp = std::get<5>(__tuple1);
    typename pythonic::assignable<typename __combined<__type104,__type106>::type>::type synapticInput = pythonic::numpy::functor::array{}(pythonic::operator_::mul(typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<double>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(0.0)>::type>::type>::type>>::type>::type({0.0, pythonic::types::single_value()}), pythonic::builtins::functor::max{}(0L, N)));
    if (pythonic::operator_::gt(tTrans, 0L))
    {
      typename pythonic::assignable_noescape<decltype(run_transient_GLNetEIRand_static()(VE, XE, VI, XI, tTrans, rhoETemp, rhoITemp, pN, qN, pN_fl, qN_fl, P_firing_poisson, Iext, mu, theta, Gamma, I, synapticInput, J, W, C, KE, K))>::type __tuple2 = run_transient_GLNetEIRand_static()(VE, XE, VI, XI, tTrans, rhoETemp, rhoITemp, pN, qN, pN_fl, qN_fl, P_firing_poisson, Iext, mu, theta, Gamma, I, synapticInput, J, W, C, KE, K);
      rhoETemp = std::get<0>(__tuple2);
      rhoITemp = std::get<1>(__tuple2);
      VE = std::get<2>(__tuple2);
      XE = std::get<3>(__tuple2);
      VI = std::get<4>(__tuple2);
      XI = std::get<5>(__tuple2);
    }
    typename pythonic::assignable_noescape<decltype(pythonic::operator_::sub(std::get<2>(__tuple0), tTrans))>::type Tmax_ = pythonic::operator_::sub(std::get<2>(__tuple0), tTrans);
    if (saveSpikingData)
    {
      if (writeOnRun)
      {
        pythonic::builtins::functor::print{}(pythonic::builtins::str::functor::__mod__{}(pythonic::types::str("*** writing file %s during simulation"), spkFileName));
        spkData = typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::types::make_tuple(0L, 0L))>::type>::type>::type>>::type>::type({pythonic::types::make_tuple(0L, 0L), pythonic::types::single_value()});
        spkTimeFile = pythonic::builtins::functor::open{}(spkFileName, pythonic::types::str("w"));
        write_spk_time = pythonic::functools::functor::partial{}(RunSimulation_GLNetEIRand_static_lambda0(), spkTimeFile);
        save_spk_time = save_spk_data_fake();
      }
      else
      {
        write_spk_time = write_spk_data_fake();
        save_spk_time = save_spk_data();
        spkData = save_initial_spkdata()(XE, XI, pN_s, qN_s);
      }
    }
    else
    {
      save_spk_time = save_spk_data_fake();
      write_spk_time = write_spk_data_fake();
      spkData = typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(pythonic::types::make_tuple(0L, 0L))>::type>::type>::type>>::type>::type({pythonic::types::make_tuple(0L, 0L), pythonic::types::single_value()});
    }
    typename pythonic::assignable<typename __combined<__type169,__type173>::type>::type rhoE = pythonic::numpy::functor::array{}(pythonic::operator_::mul(typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<double>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(0.0)>::type>::type>::type>>::type>::type({0.0, pythonic::types::single_value()}), pythonic::builtins::functor::max{}(0L, Tmax_)));
    typename pythonic::assignable<typename __combined<__type183,__type187>::type>::type rhoI = pythonic::numpy::functor::array{}(pythonic::operator_::mul(typename pythonic::assignable<typename __combined<pythonic::types::list<typename std::remove_reference<double>::type>,pythonic::types::list<typename std::remove_reference<typename std::remove_cv<typename std::remove_reference<decltype(0.0)>::type>::type>::type>>::type>::type({0.0, pythonic::types::single_value()}), pythonic::builtins::functor::max{}(0L, Tmax_)));
    std::get<0>(rhoE) = rhoETemp;
    std::get<0>(rhoI) = rhoITemp;
    {
      long  __target140219922909216 = Tmax_;
      for (long  t=1L; t < __target140219922909216; t += 1L)
      {
        sumSynpaticInput_homog()(synapticInput, KE, K, N, XE, XI, J, W, C);
        {
          long  __target140219922921024 = pN;
          for (long  i=0L; i < __target140219922921024; i += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIRand_iter()(VE[i], XE[i], synapticInput[i], Iext, mu, theta, Gamma, I, P_firing_poisson))>::type __tuple3 = GLNetEIRand_iter()(VE[i], XE[i], synapticInput[i], Iext, mu, theta, Gamma, I, P_firing_poisson);
            VE.fast(i) = std::get<0>(__tuple3);
            XE.fast(i) = std::get<1>(__tuple3);
            rhoE.fast(t) = pythonic::operator_::add(rhoE.fast(t), XE.fast(i));
            if (pythonic::builtins::pythran::and_([&] () { return pythonic::operator_::lt(i, pN_s); }, [&] () { return XE.fast(i); }))
            {
              spkData = save_spk_time(spkData, t, i);
              write_spk_time(t, i);
            }
          }
        }
        {
          long  __target140219922921360 = qN;
          for (long  i_=0L; i_ < __target140219922921360; i_ += 1L)
          {
            typename pythonic::assignable_noescape<decltype(GLNetEIRand_iter()(VI[i_], XI[i_], synapticInput[i_], Iext, mu, theta, Gamma, I, 0.0))>::type __tuple4 = GLNetEIRand_iter()(VI[i_], XI[i_], synapticInput[i_], Iext, mu, theta, Gamma, I, 0.0);
            VI.fast(i_) = std::get<0>(__tuple4);
            XI.fast(i_) = std::get<1>(__tuple4);
            rhoI.fast(t) = pythonic::operator_::add(rhoI.fast(t), XI.fast(i_));
            if (pythonic::builtins::pythran::and_([&] () { return pythonic::operator_::lt(i_, qN_s); }, [&] () { return XI.fast(i_); }))
            {
              spkData = save_spk_time(spkData, t, pythonic::operator_::add(i_, pN_s));
              write_spk_time(t, pythonic::operator_::add(i_, pN_s));
            }
          }
        }
        rhoE.fast(t) = pythonic::operator_::div(rhoE.fast(t), pN_fl);
        rhoI.fast(t) = pythonic::operator_::div(rhoI.fast(t), qN_fl);
      }
    }
    if (pythonic::builtins::pythran::and_([&] () { return saveSpikingData; }, [&] () { return writeOnRun; }))
    {
      pythonic::io::_io::TextIOWrapper::functor::close{}(spkTimeFile);
    }
    return pythonic::types::make_tuple(rhoE, rhoI, spkData, pythonic::builtins::functor::list{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(RunSimulation_GLNetEIRand_static_lambda1(), J, p), rhoE)), pythonic::builtins::functor::list{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(RunSimulation_GLNetEIRand_static_lambda2(), J, g, std::get<21>(__tuple0)), rhoI)), pythonic::builtins::functor::list{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(RunSimulation_GLNetEIRand_static_lambda3(), g), rhoE)), pythonic::builtins::functor::list{}(pythonic::builtins::functor::map{}(pythonic::functools::functor::partial{}(RunSimulation_GLNetEIRand_static_lambda4(), I, theta), rhoE)));
  }
}
#include <pythonic/python/exception_handler.hpp>
#ifdef ENABLE_PYTHON_MODULE
typename __pythran_GLNetEISimLib::write_spk_data_fake::type<long, long>::result_type write_spk_data_fake0(long&& t, long&& k) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::write_spk_data_fake()(t, k);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::save_spk_data::type<pythonic::types::list<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>, long, long>::result_type save_spk_data0(pythonic::types::list<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>&& s, long&& t, long&& k) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::save_spk_data()(s, t, k);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::save_spk_data_fake::type<pythonic::types::list<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>, long, long>::result_type save_spk_data_fake0(pythonic::types::list<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>&& s, long&& t, long&& k) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::save_spk_data_fake()(s, t, k);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::PoissonProcess_firingprob::type<double>::result_type PoissonProcess_firingprob0(double&& r) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::PoissonProcess_firingprob()(r);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::multvecelem::type<pythonic::types::list<double>, pythonic::types::list<double>>::result_type multvecelem0(pythonic::types::list<double>&& x, pythonic::types::list<double>&& y) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::multvecelem()(x, y);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::PHI::type<double, double, double>::result_type PHI0(double&& V, double&& theta, double&& Gamma) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::PHI()(V, theta, Gamma);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::weightAdapt_increase::type<double, double, double, double, double, double>::result_type weightAdapt_increase0(double&& W, double&& A, double&& tauWinv, double&& uW, double&& rhoE, double&& rhoI) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::weightAdapt_increase()(W, A, tauWinv, uW, rhoE, rhoI);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::weightAdapt_decrease::type<double, double, double, double, double, double>::result_type weightAdapt_decrease0(double&& W, double&& A, double&& tauWinv, double&& uW, double&& rhoE, double&& rhoI) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::weightAdapt_decrease()(W, A, tauWinv, uW, rhoE, rhoI);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::GLNetEIMF_iter::type<double, double, double, double, double, double, double, double, double, double, double, double, double, double>::result_type GLNetEIMF_iter0(double&& V, double&& X, double&& rhoE, double&& rhoI, double&& Iext, double&& mu, double&& theta, double&& J, double&& Gamma, double&& I, double&& g, double&& p, double&& q, double&& P_poisson) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::GLNetEIMF_iter()(V, X, rhoE, rhoI, Iext, mu, theta, J, Gamma, I, g, p, q, P_poisson);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::GLNetEIMF_adaptthresh_iter::type<double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double>::result_type GLNetEIMF_adaptthresh_iter0(double&& V, double&& X, double&& rhoE, double&& rhoI, double&& Iext, double&& mu, double&& theta, double&& J, double&& Gamma, double&& I, double&& W_I, double&& p, double&& q, double&& tauTinv, double&& uT, double&& P_poisson) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::GLNetEIMF_adaptthresh_iter()(V, X, rhoE, rhoI, Iext, mu, theta, J, Gamma, I, W_I, p, q, tauTinv, uT, P_poisson);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::GLNetEIRand_iter::type<double, double, double, double, double, double, double, double, double>::result_type GLNetEIRand_iter0(double&& V, double&& X, double&& synapticInput, double&& Iext, double&& mu, double&& theta, double&& Gamma, double&& I, double&& P_poisson) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::GLNetEIRand_iter()(V, X, synapticInput, Iext, mu, theta, Gamma, I, P_poisson);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::GLNetEIRand_adaptthresh_iter::type<double, double, double, double, double, double, double, double, double, double, double>::result_type GLNetEIRand_adaptthresh_iter0(double&& V, double&& X, double&& synapticInput, double&& Iext, double&& mu, double&& theta, double&& Gamma, double&& I, double&& tauTinv, double&& uT, double&& P_poisson) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::GLNetEIRand_adaptthresh_iter()(V, X, synapticInput, Iext, mu, theta, Gamma, I, tauTinv, uT, P_poisson);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::generate_IC_spikes::type<long, long, long, bool>::result_type generate_IC_spikes0(long&& X0, long&& N, long&& K, bool&& is_random) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::generate_IC_spikes()(X0, N, K, is_random);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::set_MF_network_IC::type<long, long, double, double, double, double, double, double, long, double, bool, long, double, bool, double>::result_type set_MF_network_IC0(long&& pN, long&& qN, double&& g, double&& J, double&& VE0, double&& VE0Std, double&& VI0, double&& VI0Std, long&& XE0, double&& fXE0, bool&& XE0Rand, long&& XI0, double&& fXI0, bool&& XI0Rand, double&& theta) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::set_MF_network_IC()(pN, qN, g, J, VE0, VE0Std, VI0, VI0Std, XE0, fXE0, XE0Rand, XI0, fXI0, XI0Rand, theta);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::save_initial_spkdata::type<pythonic::types::ndarray<long,pythonic::types::pshape<long>>, pythonic::types::ndarray<long,pythonic::types::pshape<long>>, long, long>::result_type save_initial_spkdata0(pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XE, pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XI, long&& pN, long&& qN) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::save_initial_spkdata()(XE, XI, pN, qN);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::run_transient_GLNetEIMF_static::type<pythonic::types::ndarray<double,pythonic::types::pshape<long>>, pythonic::types::ndarray<long,pythonic::types::pshape<long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long>>, pythonic::types::ndarray<long,pythonic::types::pshape<long>>, double, double, long, long, double, double, double, long, double, double, double, double, double, double, double, double, double>::result_type run_transient_GLNetEIMF_static0(pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& VE, pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XE, pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& VI, pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XI, double&& rhoETemp, double&& rhoITemp, long&& pN, long&& qN, double&& pN_fl, double&& qN_fl, double&& P_firing_poisson, long&& tTrans, double&& Iext, double&& mu, double&& theta, double&& J, double&& Gamma, double&& I, double&& g, double&& p, double&& q) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::run_transient_GLNetEIMF_static()(VE, XE, VI, XI, rhoETemp, rhoITemp, pN, qN, pN_fl, qN_fl, P_firing_poisson, tTrans, Iext, mu, theta, J, Gamma, I, g, p, q);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::run_transient_GLNetEIMF_adapt::type<pythonic::types::ndarray<double,pythonic::types::pshape<long>>, pythonic::types::ndarray<long,pythonic::types::pshape<long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long>>, pythonic::types::ndarray<long,pythonic::types::pshape<long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long>>, double, double, double, long, long, double, double, double, pythonic::types::str, long, double, double, double, double, double, double, double, double, double, double, double, double, double>::result_type run_transient_GLNetEIMF_adapt0(pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& VE, pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XE, pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& VI, pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XI, pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& thetaE, pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& thetaI, double&& rhoETemp, double&& rhoITemp, double&& N_fl, long&& pN, long&& qN, double&& pN_fl, double&& qN_fl, double&& P_firing_poisson, pythonic::types::str&& weightDynType, long&& tTrans, double&& Iext, double&& mu, double&& J, double&& Gamma, double&& I, double&& p, double&& q, double&& tauTinv, double&& uT, double&& tauWinv, double&& uW, double&& A, double&& W_I) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::run_transient_GLNetEIMF_adapt()(VE, XE, VI, XI, thetaE, thetaI, rhoETemp, rhoITemp, N_fl, pN, qN, pN_fl, qN_fl, P_firing_poisson, weightDynType, tTrans, Iext, mu, J, Gamma, I, p, q, tauTinv, uT, tauWinv, uW, A, W_I);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::run_transient_GLNetEIMF_aval::type<pythonic::types::ndarray<double,pythonic::types::pshape<long>>, pythonic::types::ndarray<long,pythonic::types::pshape<long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long>>, pythonic::types::ndarray<long,pythonic::types::pshape<long>>, double, double, long, long, double, double, double, long, double, double, double, double, double, double, double, double, double>::result_type run_transient_GLNetEIMF_aval0(pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& VE, pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XE, pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& VI, pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XI, double&& rhoETemp, double&& rhoITemp, long&& pN, long&& qN, double&& pN_fl, double&& qN_fl, double&& P_firing_poisson, long&& tTrans, double&& Iext, double&& mu, double&& theta, double&& J, double&& Gamma, double&& I, double&& g, double&& p, double&& q) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::run_transient_GLNetEIMF_aval()(VE, XE, VI, XI, rhoETemp, rhoITemp, pN, qN, pN_fl, qN_fl, P_firing_poisson, tTrans, Iext, mu, theta, J, Gamma, I, g, p, q);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::run_transient_GLNetEIMF_adaptthresh::type<pythonic::types::ndarray<double,pythonic::types::pshape<long>>, pythonic::types::ndarray<long,pythonic::types::pshape<long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long>>, pythonic::types::ndarray<long,pythonic::types::pshape<long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long>>, double, double, double, long, long, double, double, double, double, pythonic::types::str, long, double, double, double, double, double, double, double, double, double>::result_type run_transient_GLNetEIMF_adaptthresh0(pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& VE, pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XE, pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& VI, pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XI, pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& thetaE, pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& thetaI, double&& rhoETemp, double&& rhoITemp, double&& N_fl, long&& pN, long&& qN, double&& pN_fl, double&& qN_fl, double&& gJ, double&& P_firing_poisson, pythonic::types::str&& weightDynType, long&& tTrans, double&& Iext, double&& mu, double&& J, double&& Gamma, double&& I, double&& p, double&& q, double&& tauTinv, double&& uT) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::run_transient_GLNetEIMF_adaptthresh()(VE, XE, VI, XI, thetaE, thetaI, rhoETemp, rhoITemp, N_fl, pN, qN, pN_fl, qN_fl, gJ, P_firing_poisson, weightDynType, tTrans, Iext, mu, J, Gamma, I, p, q, tauTinv, uT);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::run_transient_GLNetEIRand_static::type<pythonic::types::ndarray<double,pythonic::types::pshape<long>>, pythonic::types::ndarray<long,pythonic::types::pshape<long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long>>, pythonic::types::ndarray<long,pythonic::types::pshape<long>>, long, double, double, long, long, double, double, double, double, double, double, double, double, pythonic::types::ndarray<double,pythonic::types::pshape<long>>, double, double, pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>, long, long>::result_type run_transient_GLNetEIRand_static0(pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& VE, pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XE, pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& VI, pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XI, long&& tTrans, double&& rhoETemp, double&& rhoITemp, long&& pN, long&& qN, double&& pN_fl, double&& qN_fl, double&& P_firing_poisson, double&& Iext, double&& mu, double&& theta, double&& Gamma, double&& I, pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& synapticInput, double&& J, double&& W, pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>&& C, long&& KE, long&& K) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::run_transient_GLNetEIRand_static()(VE, XE, VI, XI, tTrans, rhoETemp, rhoITemp, pN, qN, pN_fl, qN_fl, P_firing_poisson, Iext, mu, theta, Gamma, I, synapticInput, J, W, C, KE, K);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::sumSynpaticInput_homog::type<pythonic::types::ndarray<double,pythonic::types::pshape<long>>, long, long, long, pythonic::types::ndarray<long,pythonic::types::pshape<long>>, pythonic::types::ndarray<long,pythonic::types::pshape<long>>, double, double, pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>>::result_type sumSynpaticInput_homog0(pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& synapticInput, long&& K_ex, long&& K, long&& N, pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XE, pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XI, double&& J, double&& W, pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>&& C) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::sumSynpaticInput_homog()(synapticInput, K_ex, K, N, XE, XI, J, W, C);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::sumSynpaticInput::type<pythonic::types::ndarray<double,pythonic::types::pshape<long>>, long, long, long, pythonic::types::ndarray<long,pythonic::types::pshape<long>>, pythonic::types::ndarray<long,pythonic::types::pshape<long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>, pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>>::result_type sumSynpaticInput0(pythonic::types::ndarray<double,pythonic::types::pshape<long>>&& synapticInput, long&& K_ex, long&& K, long&& N, pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XE, pythonic::types::ndarray<long,pythonic::types::pshape<long>>&& XI, pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>&& J, pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>&& W, pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>&& C) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::sumSynpaticInput()(synapticInput, K_ex, K, N, XE, XI, J, W, C);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::generate_random_net_fixed_input::type<long, long, long, long>::result_type generate_random_net_fixed_input0(long&& K_ex, long&& pN, long&& K, long&& N) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::generate_random_net_fixed_input()(K_ex, pN, K, N);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::RunSimulation_GLNetEIMF_static::type<pythonic::types::dict<pythonic::types::str,pythonic::types::str>, pythonic::types::dict<pythonic::types::str,pythonic::types::str>>::result_type RunSimulation_GLNetEIMF_static0(pythonic::types::dict<pythonic::types::str,pythonic::types::str>&& simParam_dict, pythonic::types::dict<pythonic::types::str,pythonic::types::str>&& paramType_dict) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::RunSimulation_GLNetEIMF_static()(simParam_dict, paramType_dict);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::RunSimulation_GLNetEIMF_adapt::type<pythonic::types::dict<pythonic::types::str,pythonic::types::str>, pythonic::types::dict<pythonic::types::str,pythonic::types::str>>::result_type RunSimulation_GLNetEIMF_adapt0(pythonic::types::dict<pythonic::types::str,pythonic::types::str>&& simParam_dict, pythonic::types::dict<pythonic::types::str,pythonic::types::str>&& paramType_dict) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::RunSimulation_GLNetEIMF_adapt()(simParam_dict, paramType_dict);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::RunSimulation_GLNetEIMF_aval::type<pythonic::types::dict<pythonic::types::str,pythonic::types::str>, pythonic::types::dict<pythonic::types::str,pythonic::types::str>>::result_type RunSimulation_GLNetEIMF_aval0(pythonic::types::dict<pythonic::types::str,pythonic::types::str>&& simParam_dict, pythonic::types::dict<pythonic::types::str,pythonic::types::str>&& paramType_dict) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::RunSimulation_GLNetEIMF_aval()(simParam_dict, paramType_dict);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::RunSimulation_GLNetEIMF_adaptthresh::type<pythonic::types::dict<pythonic::types::str,pythonic::types::str>, pythonic::types::dict<pythonic::types::str,pythonic::types::str>>::result_type RunSimulation_GLNetEIMF_adaptthresh0(pythonic::types::dict<pythonic::types::str,pythonic::types::str>&& simParam_dict, pythonic::types::dict<pythonic::types::str,pythonic::types::str>&& paramType_dict) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::RunSimulation_GLNetEIMF_adaptthresh()(simParam_dict, paramType_dict);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::RunSimulation_GLNetEIRand_static::type<pythonic::types::dict<pythonic::types::str,pythonic::types::str>, pythonic::types::dict<pythonic::types::str,pythonic::types::str>>::result_type RunSimulation_GLNetEIRand_static0(pythonic::types::dict<pythonic::types::str,pythonic::types::str>&& simParam_dict, pythonic::types::dict<pythonic::types::str,pythonic::types::str>&& paramType_dict) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::RunSimulation_GLNetEIRand_static()(simParam_dict, paramType_dict);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::get_param::type<pythonic::types::str, pythonic::types::str>::result_type get_param0(pythonic::types::str&& v, pythonic::types::str&& vtype) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::get_param()(v, vtype);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}
typename __pythran_GLNetEISimLib::get_system_parameters::type<pythonic::types::dict<pythonic::types::str,pythonic::types::str>, pythonic::types::dict<pythonic::types::str,pythonic::types::str>>::result_type get_system_parameters0(pythonic::types::dict<pythonic::types::str,pythonic::types::str>&& simParam_dict, pythonic::types::dict<pythonic::types::str,pythonic::types::str>&& paramType_dict) 
{
  
                            PyThreadState *_save = PyEval_SaveThread();
                            try {
                                auto res = __pythran_GLNetEISimLib::get_system_parameters()(simParam_dict, paramType_dict);
                                PyEval_RestoreThread(_save);
                                return res;
                            }
                            catch(...) {
                                PyEval_RestoreThread(_save);
                                throw;
                            }
                            ;
}

static PyObject *
__pythran_wrap_write_spk_data_fake0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[2+1];
    char const* keywords[] = {"t", "k",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OO",
                                     (char**)keywords , &args_obj[0], &args_obj[1]))
        return nullptr;
    if(is_convertible<long>(args_obj[0]) && is_convertible<long>(args_obj[1]))
        return to_python(write_spk_data_fake0(from_python<long>(args_obj[0]), from_python<long>(args_obj[1])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_save_spk_data0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"s", "t", "k",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::list<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>>(args_obj[0]) && is_convertible<long>(args_obj[1]) && is_convertible<long>(args_obj[2]))
        return to_python(save_spk_data0(from_python<pythonic::types::list<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>>(args_obj[0]), from_python<long>(args_obj[1]), from_python<long>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_save_spk_data_fake0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"s", "t", "k",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<pythonic::types::list<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>>(args_obj[0]) && is_convertible<long>(args_obj[1]) && is_convertible<long>(args_obj[2]))
        return to_python(save_spk_data_fake0(from_python<pythonic::types::list<decltype(pythonic::types::make_tuple(std::declval<long>(), std::declval<long>()))>>(args_obj[0]), from_python<long>(args_obj[1]), from_python<long>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_PoissonProcess_firingprob0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[1+1];
    char const* keywords[] = {"r",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "O",
                                     (char**)keywords , &args_obj[0]))
        return nullptr;
    if(is_convertible<double>(args_obj[0]))
        return to_python(PoissonProcess_firingprob0(from_python<double>(args_obj[0])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_multvecelem0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[2+1];
    char const* keywords[] = {"x", "y",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OO",
                                     (char**)keywords , &args_obj[0], &args_obj[1]))
        return nullptr;
    if(is_convertible<pythonic::types::list<double>>(args_obj[0]) && is_convertible<pythonic::types::list<double>>(args_obj[1]))
        return to_python(multvecelem0(from_python<pythonic::types::list<double>>(args_obj[0]), from_python<pythonic::types::list<double>>(args_obj[1])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_PHI0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[3+1];
    char const* keywords[] = {"V", "theta", "Gamma",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2]))
        return nullptr;
    if(is_convertible<double>(args_obj[0]) && is_convertible<double>(args_obj[1]) && is_convertible<double>(args_obj[2]))
        return to_python(PHI0(from_python<double>(args_obj[0]), from_python<double>(args_obj[1]), from_python<double>(args_obj[2])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_weightAdapt_increase0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[6+1];
    char const* keywords[] = {"W", "A", "tauWinv", "uW", "rhoE", "rhoI",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3], &args_obj[4], &args_obj[5]))
        return nullptr;
    if(is_convertible<double>(args_obj[0]) && is_convertible<double>(args_obj[1]) && is_convertible<double>(args_obj[2]) && is_convertible<double>(args_obj[3]) && is_convertible<double>(args_obj[4]) && is_convertible<double>(args_obj[5]))
        return to_python(weightAdapt_increase0(from_python<double>(args_obj[0]), from_python<double>(args_obj[1]), from_python<double>(args_obj[2]), from_python<double>(args_obj[3]), from_python<double>(args_obj[4]), from_python<double>(args_obj[5])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_weightAdapt_decrease0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[6+1];
    char const* keywords[] = {"W", "A", "tauWinv", "uW", "rhoE", "rhoI",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3], &args_obj[4], &args_obj[5]))
        return nullptr;
    if(is_convertible<double>(args_obj[0]) && is_convertible<double>(args_obj[1]) && is_convertible<double>(args_obj[2]) && is_convertible<double>(args_obj[3]) && is_convertible<double>(args_obj[4]) && is_convertible<double>(args_obj[5]))
        return to_python(weightAdapt_decrease0(from_python<double>(args_obj[0]), from_python<double>(args_obj[1]), from_python<double>(args_obj[2]), from_python<double>(args_obj[3]), from_python<double>(args_obj[4]), from_python<double>(args_obj[5])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_GLNetEIMF_iter0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[14+1];
    char const* keywords[] = {"V", "X", "rhoE", "rhoI", "Iext", "mu", "theta", "J", "Gamma", "I", "g", "p", "q", "P_poisson",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOOOOOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3], &args_obj[4], &args_obj[5], &args_obj[6], &args_obj[7], &args_obj[8], &args_obj[9], &args_obj[10], &args_obj[11], &args_obj[12], &args_obj[13]))
        return nullptr;
    if(is_convertible<double>(args_obj[0]) && is_convertible<double>(args_obj[1]) && is_convertible<double>(args_obj[2]) && is_convertible<double>(args_obj[3]) && is_convertible<double>(args_obj[4]) && is_convertible<double>(args_obj[5]) && is_convertible<double>(args_obj[6]) && is_convertible<double>(args_obj[7]) && is_convertible<double>(args_obj[8]) && is_convertible<double>(args_obj[9]) && is_convertible<double>(args_obj[10]) && is_convertible<double>(args_obj[11]) && is_convertible<double>(args_obj[12]) && is_convertible<double>(args_obj[13]))
        return to_python(GLNetEIMF_iter0(from_python<double>(args_obj[0]), from_python<double>(args_obj[1]), from_python<double>(args_obj[2]), from_python<double>(args_obj[3]), from_python<double>(args_obj[4]), from_python<double>(args_obj[5]), from_python<double>(args_obj[6]), from_python<double>(args_obj[7]), from_python<double>(args_obj[8]), from_python<double>(args_obj[9]), from_python<double>(args_obj[10]), from_python<double>(args_obj[11]), from_python<double>(args_obj[12]), from_python<double>(args_obj[13])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_GLNetEIMF_adaptthresh_iter0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[16+1];
    char const* keywords[] = {"V", "X", "rhoE", "rhoI", "Iext", "mu", "theta", "J", "Gamma", "I", "W_I", "p", "q", "tauTinv", "uT", "P_poisson",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOOOOOOOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3], &args_obj[4], &args_obj[5], &args_obj[6], &args_obj[7], &args_obj[8], &args_obj[9], &args_obj[10], &args_obj[11], &args_obj[12], &args_obj[13], &args_obj[14], &args_obj[15]))
        return nullptr;
    if(is_convertible<double>(args_obj[0]) && is_convertible<double>(args_obj[1]) && is_convertible<double>(args_obj[2]) && is_convertible<double>(args_obj[3]) && is_convertible<double>(args_obj[4]) && is_convertible<double>(args_obj[5]) && is_convertible<double>(args_obj[6]) && is_convertible<double>(args_obj[7]) && is_convertible<double>(args_obj[8]) && is_convertible<double>(args_obj[9]) && is_convertible<double>(args_obj[10]) && is_convertible<double>(args_obj[11]) && is_convertible<double>(args_obj[12]) && is_convertible<double>(args_obj[13]) && is_convertible<double>(args_obj[14]) && is_convertible<double>(args_obj[15]))
        return to_python(GLNetEIMF_adaptthresh_iter0(from_python<double>(args_obj[0]), from_python<double>(args_obj[1]), from_python<double>(args_obj[2]), from_python<double>(args_obj[3]), from_python<double>(args_obj[4]), from_python<double>(args_obj[5]), from_python<double>(args_obj[6]), from_python<double>(args_obj[7]), from_python<double>(args_obj[8]), from_python<double>(args_obj[9]), from_python<double>(args_obj[10]), from_python<double>(args_obj[11]), from_python<double>(args_obj[12]), from_python<double>(args_obj[13]), from_python<double>(args_obj[14]), from_python<double>(args_obj[15])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_GLNetEIRand_iter0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[9+1];
    char const* keywords[] = {"V", "X", "synapticInput", "Iext", "mu", "theta", "Gamma", "I", "P_poisson",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3], &args_obj[4], &args_obj[5], &args_obj[6], &args_obj[7], &args_obj[8]))
        return nullptr;
    if(is_convertible<double>(args_obj[0]) && is_convertible<double>(args_obj[1]) && is_convertible<double>(args_obj[2]) && is_convertible<double>(args_obj[3]) && is_convertible<double>(args_obj[4]) && is_convertible<double>(args_obj[5]) && is_convertible<double>(args_obj[6]) && is_convertible<double>(args_obj[7]) && is_convertible<double>(args_obj[8]))
        return to_python(GLNetEIRand_iter0(from_python<double>(args_obj[0]), from_python<double>(args_obj[1]), from_python<double>(args_obj[2]), from_python<double>(args_obj[3]), from_python<double>(args_obj[4]), from_python<double>(args_obj[5]), from_python<double>(args_obj[6]), from_python<double>(args_obj[7]), from_python<double>(args_obj[8])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_GLNetEIRand_adaptthresh_iter0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[11+1];
    char const* keywords[] = {"V", "X", "synapticInput", "Iext", "mu", "theta", "Gamma", "I", "tauTinv", "uT", "P_poisson",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3], &args_obj[4], &args_obj[5], &args_obj[6], &args_obj[7], &args_obj[8], &args_obj[9], &args_obj[10]))
        return nullptr;
    if(is_convertible<double>(args_obj[0]) && is_convertible<double>(args_obj[1]) && is_convertible<double>(args_obj[2]) && is_convertible<double>(args_obj[3]) && is_convertible<double>(args_obj[4]) && is_convertible<double>(args_obj[5]) && is_convertible<double>(args_obj[6]) && is_convertible<double>(args_obj[7]) && is_convertible<double>(args_obj[8]) && is_convertible<double>(args_obj[9]) && is_convertible<double>(args_obj[10]))
        return to_python(GLNetEIRand_adaptthresh_iter0(from_python<double>(args_obj[0]), from_python<double>(args_obj[1]), from_python<double>(args_obj[2]), from_python<double>(args_obj[3]), from_python<double>(args_obj[4]), from_python<double>(args_obj[5]), from_python<double>(args_obj[6]), from_python<double>(args_obj[7]), from_python<double>(args_obj[8]), from_python<double>(args_obj[9]), from_python<double>(args_obj[10])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_generate_IC_spikes0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[4+1];
    char const* keywords[] = {"X0", "N", "K", "is_random",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3]))
        return nullptr;
    if(is_convertible<long>(args_obj[0]) && is_convertible<long>(args_obj[1]) && is_convertible<long>(args_obj[2]) && is_convertible<bool>(args_obj[3]))
        return to_python(generate_IC_spikes0(from_python<long>(args_obj[0]), from_python<long>(args_obj[1]), from_python<long>(args_obj[2]), from_python<bool>(args_obj[3])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_set_MF_network_IC0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[15+1];
    char const* keywords[] = {"pN", "qN", "g", "J", "VE0", "VE0Std", "VI0", "VI0Std", "XE0", "fXE0", "XE0Rand", "XI0", "fXI0", "XI0Rand", "theta",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOOOOOOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3], &args_obj[4], &args_obj[5], &args_obj[6], &args_obj[7], &args_obj[8], &args_obj[9], &args_obj[10], &args_obj[11], &args_obj[12], &args_obj[13], &args_obj[14]))
        return nullptr;
    if(is_convertible<long>(args_obj[0]) && is_convertible<long>(args_obj[1]) && is_convertible<double>(args_obj[2]) && is_convertible<double>(args_obj[3]) && is_convertible<double>(args_obj[4]) && is_convertible<double>(args_obj[5]) && is_convertible<double>(args_obj[6]) && is_convertible<double>(args_obj[7]) && is_convertible<long>(args_obj[8]) && is_convertible<double>(args_obj[9]) && is_convertible<bool>(args_obj[10]) && is_convertible<long>(args_obj[11]) && is_convertible<double>(args_obj[12]) && is_convertible<bool>(args_obj[13]) && is_convertible<double>(args_obj[14]))
        return to_python(set_MF_network_IC0(from_python<long>(args_obj[0]), from_python<long>(args_obj[1]), from_python<double>(args_obj[2]), from_python<double>(args_obj[3]), from_python<double>(args_obj[4]), from_python<double>(args_obj[5]), from_python<double>(args_obj[6]), from_python<double>(args_obj[7]), from_python<long>(args_obj[8]), from_python<double>(args_obj[9]), from_python<bool>(args_obj[10]), from_python<long>(args_obj[11]), from_python<double>(args_obj[12]), from_python<bool>(args_obj[13]), from_python<double>(args_obj[14])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_save_initial_spkdata0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[4+1];
    char const* keywords[] = {"XE", "XI", "pN", "qN",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[1]) && is_convertible<long>(args_obj[2]) && is_convertible<long>(args_obj[3]))
        return to_python(save_initial_spkdata0(from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[0]), from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[1]), from_python<long>(args_obj[2]), from_python<long>(args_obj[3])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_run_transient_GLNetEIMF_static0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[21+1];
    char const* keywords[] = {"VE", "XE", "VI", "XI", "rhoETemp", "rhoITemp", "pN", "qN", "pN_fl", "qN_fl", "P_firing_poisson", "tTrans", "Iext", "mu", "theta", "J", "Gamma", "I", "g", "p", "q",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOOOOOOOOOOOOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3], &args_obj[4], &args_obj[5], &args_obj[6], &args_obj[7], &args_obj[8], &args_obj[9], &args_obj[10], &args_obj[11], &args_obj[12], &args_obj[13], &args_obj[14], &args_obj[15], &args_obj[16], &args_obj[17], &args_obj[18], &args_obj[19], &args_obj[20]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[2]) && is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[3]) && is_convertible<double>(args_obj[4]) && is_convertible<double>(args_obj[5]) && is_convertible<long>(args_obj[6]) && is_convertible<long>(args_obj[7]) && is_convertible<double>(args_obj[8]) && is_convertible<double>(args_obj[9]) && is_convertible<double>(args_obj[10]) && is_convertible<long>(args_obj[11]) && is_convertible<double>(args_obj[12]) && is_convertible<double>(args_obj[13]) && is_convertible<double>(args_obj[14]) && is_convertible<double>(args_obj[15]) && is_convertible<double>(args_obj[16]) && is_convertible<double>(args_obj[17]) && is_convertible<double>(args_obj[18]) && is_convertible<double>(args_obj[19]) && is_convertible<double>(args_obj[20]))
        return to_python(run_transient_GLNetEIMF_static0(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[0]), from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[1]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[2]), from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[3]), from_python<double>(args_obj[4]), from_python<double>(args_obj[5]), from_python<long>(args_obj[6]), from_python<long>(args_obj[7]), from_python<double>(args_obj[8]), from_python<double>(args_obj[9]), from_python<double>(args_obj[10]), from_python<long>(args_obj[11]), from_python<double>(args_obj[12]), from_python<double>(args_obj[13]), from_python<double>(args_obj[14]), from_python<double>(args_obj[15]), from_python<double>(args_obj[16]), from_python<double>(args_obj[17]), from_python<double>(args_obj[18]), from_python<double>(args_obj[19]), from_python<double>(args_obj[20])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_run_transient_GLNetEIMF_adapt0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[29+1];
    char const* keywords[] = {"VE", "XE", "VI", "XI", "thetaE", "thetaI", "rhoETemp", "rhoITemp", "N_fl", "pN", "qN", "pN_fl", "qN_fl", "P_firing_poisson", "weightDynType", "tTrans", "Iext", "mu", "J", "Gamma", "I", "p", "q", "tauTinv", "uT", "tauWinv", "uW", "A", "W_I",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOOOOOOOOOOOOOOOOOOOOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3], &args_obj[4], &args_obj[5], &args_obj[6], &args_obj[7], &args_obj[8], &args_obj[9], &args_obj[10], &args_obj[11], &args_obj[12], &args_obj[13], &args_obj[14], &args_obj[15], &args_obj[16], &args_obj[17], &args_obj[18], &args_obj[19], &args_obj[20], &args_obj[21], &args_obj[22], &args_obj[23], &args_obj[24], &args_obj[25], &args_obj[26], &args_obj[27], &args_obj[28]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[2]) && is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[3]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[4]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[5]) && is_convertible<double>(args_obj[6]) && is_convertible<double>(args_obj[7]) && is_convertible<double>(args_obj[8]) && is_convertible<long>(args_obj[9]) && is_convertible<long>(args_obj[10]) && is_convertible<double>(args_obj[11]) && is_convertible<double>(args_obj[12]) && is_convertible<double>(args_obj[13]) && is_convertible<pythonic::types::str>(args_obj[14]) && is_convertible<long>(args_obj[15]) && is_convertible<double>(args_obj[16]) && is_convertible<double>(args_obj[17]) && is_convertible<double>(args_obj[18]) && is_convertible<double>(args_obj[19]) && is_convertible<double>(args_obj[20]) && is_convertible<double>(args_obj[21]) && is_convertible<double>(args_obj[22]) && is_convertible<double>(args_obj[23]) && is_convertible<double>(args_obj[24]) && is_convertible<double>(args_obj[25]) && is_convertible<double>(args_obj[26]) && is_convertible<double>(args_obj[27]) && is_convertible<double>(args_obj[28]))
        return to_python(run_transient_GLNetEIMF_adapt0(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[0]), from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[1]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[2]), from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[3]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[4]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[5]), from_python<double>(args_obj[6]), from_python<double>(args_obj[7]), from_python<double>(args_obj[8]), from_python<long>(args_obj[9]), from_python<long>(args_obj[10]), from_python<double>(args_obj[11]), from_python<double>(args_obj[12]), from_python<double>(args_obj[13]), from_python<pythonic::types::str>(args_obj[14]), from_python<long>(args_obj[15]), from_python<double>(args_obj[16]), from_python<double>(args_obj[17]), from_python<double>(args_obj[18]), from_python<double>(args_obj[19]), from_python<double>(args_obj[20]), from_python<double>(args_obj[21]), from_python<double>(args_obj[22]), from_python<double>(args_obj[23]), from_python<double>(args_obj[24]), from_python<double>(args_obj[25]), from_python<double>(args_obj[26]), from_python<double>(args_obj[27]), from_python<double>(args_obj[28])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_run_transient_GLNetEIMF_aval0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[21+1];
    char const* keywords[] = {"VE", "XE", "VI", "XI", "rhoETemp", "rhoITemp", "pN", "qN", "pN_fl", "qN_fl", "P_firing_poisson", "tTrans", "Iext", "mu", "theta", "J", "Gamma", "I", "g", "p", "q",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOOOOOOOOOOOOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3], &args_obj[4], &args_obj[5], &args_obj[6], &args_obj[7], &args_obj[8], &args_obj[9], &args_obj[10], &args_obj[11], &args_obj[12], &args_obj[13], &args_obj[14], &args_obj[15], &args_obj[16], &args_obj[17], &args_obj[18], &args_obj[19], &args_obj[20]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[2]) && is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[3]) && is_convertible<double>(args_obj[4]) && is_convertible<double>(args_obj[5]) && is_convertible<long>(args_obj[6]) && is_convertible<long>(args_obj[7]) && is_convertible<double>(args_obj[8]) && is_convertible<double>(args_obj[9]) && is_convertible<double>(args_obj[10]) && is_convertible<long>(args_obj[11]) && is_convertible<double>(args_obj[12]) && is_convertible<double>(args_obj[13]) && is_convertible<double>(args_obj[14]) && is_convertible<double>(args_obj[15]) && is_convertible<double>(args_obj[16]) && is_convertible<double>(args_obj[17]) && is_convertible<double>(args_obj[18]) && is_convertible<double>(args_obj[19]) && is_convertible<double>(args_obj[20]))
        return to_python(run_transient_GLNetEIMF_aval0(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[0]), from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[1]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[2]), from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[3]), from_python<double>(args_obj[4]), from_python<double>(args_obj[5]), from_python<long>(args_obj[6]), from_python<long>(args_obj[7]), from_python<double>(args_obj[8]), from_python<double>(args_obj[9]), from_python<double>(args_obj[10]), from_python<long>(args_obj[11]), from_python<double>(args_obj[12]), from_python<double>(args_obj[13]), from_python<double>(args_obj[14]), from_python<double>(args_obj[15]), from_python<double>(args_obj[16]), from_python<double>(args_obj[17]), from_python<double>(args_obj[18]), from_python<double>(args_obj[19]), from_python<double>(args_obj[20])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_run_transient_GLNetEIMF_adaptthresh0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[26+1];
    char const* keywords[] = {"VE", "XE", "VI", "XI", "thetaE", "thetaI", "rhoETemp", "rhoITemp", "N_fl", "pN", "qN", "pN_fl", "qN_fl", "gJ", "P_firing_poisson", "weightDynType", "tTrans", "Iext", "mu", "J", "Gamma", "I", "p", "q", "tauTinv", "uT",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOOOOOOOOOOOOOOOOOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3], &args_obj[4], &args_obj[5], &args_obj[6], &args_obj[7], &args_obj[8], &args_obj[9], &args_obj[10], &args_obj[11], &args_obj[12], &args_obj[13], &args_obj[14], &args_obj[15], &args_obj[16], &args_obj[17], &args_obj[18], &args_obj[19], &args_obj[20], &args_obj[21], &args_obj[22], &args_obj[23], &args_obj[24], &args_obj[25]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[2]) && is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[3]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[4]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[5]) && is_convertible<double>(args_obj[6]) && is_convertible<double>(args_obj[7]) && is_convertible<double>(args_obj[8]) && is_convertible<long>(args_obj[9]) && is_convertible<long>(args_obj[10]) && is_convertible<double>(args_obj[11]) && is_convertible<double>(args_obj[12]) && is_convertible<double>(args_obj[13]) && is_convertible<double>(args_obj[14]) && is_convertible<pythonic::types::str>(args_obj[15]) && is_convertible<long>(args_obj[16]) && is_convertible<double>(args_obj[17]) && is_convertible<double>(args_obj[18]) && is_convertible<double>(args_obj[19]) && is_convertible<double>(args_obj[20]) && is_convertible<double>(args_obj[21]) && is_convertible<double>(args_obj[22]) && is_convertible<double>(args_obj[23]) && is_convertible<double>(args_obj[24]) && is_convertible<double>(args_obj[25]))
        return to_python(run_transient_GLNetEIMF_adaptthresh0(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[0]), from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[1]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[2]), from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[3]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[4]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[5]), from_python<double>(args_obj[6]), from_python<double>(args_obj[7]), from_python<double>(args_obj[8]), from_python<long>(args_obj[9]), from_python<long>(args_obj[10]), from_python<double>(args_obj[11]), from_python<double>(args_obj[12]), from_python<double>(args_obj[13]), from_python<double>(args_obj[14]), from_python<pythonic::types::str>(args_obj[15]), from_python<long>(args_obj[16]), from_python<double>(args_obj[17]), from_python<double>(args_obj[18]), from_python<double>(args_obj[19]), from_python<double>(args_obj[20]), from_python<double>(args_obj[21]), from_python<double>(args_obj[22]), from_python<double>(args_obj[23]), from_python<double>(args_obj[24]), from_python<double>(args_obj[25])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_run_transient_GLNetEIRand_static0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[23+1];
    char const* keywords[] = {"VE", "XE", "VI", "XI", "tTrans", "rhoETemp", "rhoITemp", "pN", "qN", "pN_fl", "qN_fl", "P_firing_poisson", "Iext", "mu", "theta", "Gamma", "I", "synapticInput", "J", "W", "C", "KE", "K",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOOOOOOOOOOOOOOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3], &args_obj[4], &args_obj[5], &args_obj[6], &args_obj[7], &args_obj[8], &args_obj[9], &args_obj[10], &args_obj[11], &args_obj[12], &args_obj[13], &args_obj[14], &args_obj[15], &args_obj[16], &args_obj[17], &args_obj[18], &args_obj[19], &args_obj[20], &args_obj[21], &args_obj[22]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[0]) && is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[1]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[2]) && is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[3]) && is_convertible<long>(args_obj[4]) && is_convertible<double>(args_obj[5]) && is_convertible<double>(args_obj[6]) && is_convertible<long>(args_obj[7]) && is_convertible<long>(args_obj[8]) && is_convertible<double>(args_obj[9]) && is_convertible<double>(args_obj[10]) && is_convertible<double>(args_obj[11]) && is_convertible<double>(args_obj[12]) && is_convertible<double>(args_obj[13]) && is_convertible<double>(args_obj[14]) && is_convertible<double>(args_obj[15]) && is_convertible<double>(args_obj[16]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[17]) && is_convertible<double>(args_obj[18]) && is_convertible<double>(args_obj[19]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>>(args_obj[20]) && is_convertible<long>(args_obj[21]) && is_convertible<long>(args_obj[22]))
        return to_python(run_transient_GLNetEIRand_static0(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[0]), from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[1]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[2]), from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[3]), from_python<long>(args_obj[4]), from_python<double>(args_obj[5]), from_python<double>(args_obj[6]), from_python<long>(args_obj[7]), from_python<long>(args_obj[8]), from_python<double>(args_obj[9]), from_python<double>(args_obj[10]), from_python<double>(args_obj[11]), from_python<double>(args_obj[12]), from_python<double>(args_obj[13]), from_python<double>(args_obj[14]), from_python<double>(args_obj[15]), from_python<double>(args_obj[16]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[17]), from_python<double>(args_obj[18]), from_python<double>(args_obj[19]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>>(args_obj[20]), from_python<long>(args_obj[21]), from_python<long>(args_obj[22])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_sumSynpaticInput_homog0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[9+1];
    char const* keywords[] = {"synapticInput", "K_ex", "K", "N", "XE", "XI", "J", "W", "C",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3], &args_obj[4], &args_obj[5], &args_obj[6], &args_obj[7], &args_obj[8]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[0]) && is_convertible<long>(args_obj[1]) && is_convertible<long>(args_obj[2]) && is_convertible<long>(args_obj[3]) && is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[4]) && is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[5]) && is_convertible<double>(args_obj[6]) && is_convertible<double>(args_obj[7]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>>(args_obj[8]))
        return to_python(sumSynpaticInput_homog0(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[0]), from_python<long>(args_obj[1]), from_python<long>(args_obj[2]), from_python<long>(args_obj[3]), from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[4]), from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[5]), from_python<double>(args_obj[6]), from_python<double>(args_obj[7]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>>(args_obj[8])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_sumSynpaticInput0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[9+1];
    char const* keywords[] = {"synapticInput", "K_ex", "K", "N", "XE", "XI", "J", "W", "C",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOOOOOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3], &args_obj[4], &args_obj[5], &args_obj[6], &args_obj[7], &args_obj[8]))
        return nullptr;
    if(is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[0]) && is_convertible<long>(args_obj[1]) && is_convertible<long>(args_obj[2]) && is_convertible<long>(args_obj[3]) && is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[4]) && is_convertible<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[5]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>>(args_obj[6]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>>(args_obj[7]) && is_convertible<pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>>(args_obj[8]))
        return to_python(sumSynpaticInput0(from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long>>>(args_obj[0]), from_python<long>(args_obj[1]), from_python<long>(args_obj[2]), from_python<long>(args_obj[3]), from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[4]), from_python<pythonic::types::ndarray<long,pythonic::types::pshape<long>>>(args_obj[5]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>>(args_obj[6]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>>(args_obj[7]), from_python<pythonic::types::ndarray<double,pythonic::types::pshape<long,long>>>(args_obj[8])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_generate_random_net_fixed_input0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[4+1];
    char const* keywords[] = {"K_ex", "pN", "K", "N",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OOOO",
                                     (char**)keywords , &args_obj[0], &args_obj[1], &args_obj[2], &args_obj[3]))
        return nullptr;
    if(is_convertible<long>(args_obj[0]) && is_convertible<long>(args_obj[1]) && is_convertible<long>(args_obj[2]) && is_convertible<long>(args_obj[3]))
        return to_python(generate_random_net_fixed_input0(from_python<long>(args_obj[0]), from_python<long>(args_obj[1]), from_python<long>(args_obj[2]), from_python<long>(args_obj[3])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_RunSimulation_GLNetEIMF_static0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[2+1];
    char const* keywords[] = {"simParam_dict", "paramType_dict",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OO",
                                     (char**)keywords , &args_obj[0], &args_obj[1]))
        return nullptr;
    if(is_convertible<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[0]) && is_convertible<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[1]))
        return to_python(RunSimulation_GLNetEIMF_static0(from_python<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[0]), from_python<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[1])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_RunSimulation_GLNetEIMF_adapt0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[2+1];
    char const* keywords[] = {"simParam_dict", "paramType_dict",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OO",
                                     (char**)keywords , &args_obj[0], &args_obj[1]))
        return nullptr;
    if(is_convertible<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[0]) && is_convertible<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[1]))
        return to_python(RunSimulation_GLNetEIMF_adapt0(from_python<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[0]), from_python<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[1])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_RunSimulation_GLNetEIMF_aval0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[2+1];
    char const* keywords[] = {"simParam_dict", "paramType_dict",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OO",
                                     (char**)keywords , &args_obj[0], &args_obj[1]))
        return nullptr;
    if(is_convertible<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[0]) && is_convertible<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[1]))
        return to_python(RunSimulation_GLNetEIMF_aval0(from_python<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[0]), from_python<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[1])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_RunSimulation_GLNetEIMF_adaptthresh0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[2+1];
    char const* keywords[] = {"simParam_dict", "paramType_dict",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OO",
                                     (char**)keywords , &args_obj[0], &args_obj[1]))
        return nullptr;
    if(is_convertible<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[0]) && is_convertible<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[1]))
        return to_python(RunSimulation_GLNetEIMF_adaptthresh0(from_python<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[0]), from_python<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[1])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_RunSimulation_GLNetEIRand_static0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[2+1];
    char const* keywords[] = {"simParam_dict", "paramType_dict",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OO",
                                     (char**)keywords , &args_obj[0], &args_obj[1]))
        return nullptr;
    if(is_convertible<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[0]) && is_convertible<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[1]))
        return to_python(RunSimulation_GLNetEIRand_static0(from_python<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[0]), from_python<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[1])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_get_param0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[2+1];
    char const* keywords[] = {"v", "vtype",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OO",
                                     (char**)keywords , &args_obj[0], &args_obj[1]))
        return nullptr;
    if(is_convertible<pythonic::types::str>(args_obj[0]) && is_convertible<pythonic::types::str>(args_obj[1]))
        return to_python(get_param0(from_python<pythonic::types::str>(args_obj[0]), from_python<pythonic::types::str>(args_obj[1])));
    else {
        return nullptr;
    }
}

static PyObject *
__pythran_wrap_get_system_parameters0(PyObject *self, PyObject *args, PyObject *kw)
{
    PyObject* args_obj[2+1];
    char const* keywords[] = {"simParam_dict", "paramType_dict",  nullptr};
    if(! PyArg_ParseTupleAndKeywords(args, kw, "OO",
                                     (char**)keywords , &args_obj[0], &args_obj[1]))
        return nullptr;
    if(is_convertible<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[0]) && is_convertible<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[1]))
        return to_python(get_system_parameters0(from_python<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[0]), from_python<pythonic::types::dict<pythonic::types::str,pythonic::types::str>>(args_obj[1])));
    else {
        return nullptr;
    }
}

            static PyObject *
            __pythran_wrapall_write_spk_data_fake(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_write_spk_data_fake0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "write_spk_data_fake", "\n""    - write_spk_data_fake(int, int)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_save_spk_data(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_save_spk_data0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "save_spk_data", "\n""    - save_spk_data((int, int) list, int, int)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_save_spk_data_fake(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_save_spk_data_fake0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "save_spk_data_fake", "\n""    - save_spk_data_fake((int, int) list, int, int)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_PoissonProcess_firingprob(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_PoissonProcess_firingprob0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "PoissonProcess_firingprob", "\n""    - PoissonProcess_firingprob(float)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_multvecelem(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_multvecelem0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "multvecelem", "\n""    - multvecelem(float list, float list)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_PHI(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_PHI0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "PHI", "\n""    - PHI(float, float, float)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_weightAdapt_increase(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_weightAdapt_increase0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "weightAdapt_increase", "\n""    - weightAdapt_increase(float, float, float, float, float, float)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_weightAdapt_decrease(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_weightAdapt_decrease0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "weightAdapt_decrease", "\n""    - weightAdapt_decrease(float, float, float, float, float, float)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_GLNetEIMF_iter(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_GLNetEIMF_iter0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "GLNetEIMF_iter", "\n""    - GLNetEIMF_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_GLNetEIMF_adaptthresh_iter(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_GLNetEIMF_adaptthresh_iter0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "GLNetEIMF_adaptthresh_iter", "\n""    - GLNetEIMF_adaptthresh_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_GLNetEIRand_iter(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_GLNetEIRand_iter0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "GLNetEIRand_iter", "\n""    - GLNetEIRand_iter(float, float, float, float, float, float, float, float, float)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_GLNetEIRand_adaptthresh_iter(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_GLNetEIRand_adaptthresh_iter0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "GLNetEIRand_adaptthresh_iter", "\n""    - GLNetEIRand_adaptthresh_iter(float, float, float, float, float, float, float, float, float, float, float)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_generate_IC_spikes(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_generate_IC_spikes0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "generate_IC_spikes", "\n""    - generate_IC_spikes(int, int, int, bool)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_set_MF_network_IC(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_set_MF_network_IC0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "set_MF_network_IC", "\n""    - set_MF_network_IC(int, int, float, float, float, float, float, float, int, float, bool, int, float, bool, float)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_save_initial_spkdata(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_save_initial_spkdata0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "save_initial_spkdata", "\n""    - save_initial_spkdata(int[:], int[:], int, int)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_run_transient_GLNetEIMF_static(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_run_transient_GLNetEIMF_static0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "run_transient_GLNetEIMF_static", "\n""    - run_transient_GLNetEIMF_static(float[:], int[:], float[:], int[:], float, float, int, int, float, float, float, int, float, float, float, float, float, float, float, float, float)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_run_transient_GLNetEIMF_adapt(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_run_transient_GLNetEIMF_adapt0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "run_transient_GLNetEIMF_adapt", "\n""    - run_transient_GLNetEIMF_adapt(float[:], int[:], float[:], int[:], float[:], float[:], float, float, float, int, int, float, float, float, str, int, float, float, float, float, float, float, float, float, float, float, float, float, float)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_run_transient_GLNetEIMF_aval(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_run_transient_GLNetEIMF_aval0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "run_transient_GLNetEIMF_aval", "\n""    - run_transient_GLNetEIMF_aval(float[:], int[:], float[:], int[:], float, float, int, int, float, float, float, int, float, float, float, float, float, float, float, float, float)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_run_transient_GLNetEIMF_adaptthresh(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_run_transient_GLNetEIMF_adaptthresh0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "run_transient_GLNetEIMF_adaptthresh", "\n""    - run_transient_GLNetEIMF_adaptthresh(float[:], int[:], float[:], int[:], float[:], float[:], float, float, float, int, int, float, float, float, float, str, int, float, float, float, float, float, float, float, float, float)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_run_transient_GLNetEIRand_static(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_run_transient_GLNetEIRand_static0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "run_transient_GLNetEIRand_static", "\n""    - run_transient_GLNetEIRand_static(float[:], int[:], float[:], int[:], int, float, float, int, int, float, float, float, float, float, float, float, float, float[:], float, float, float[:,:], int, int)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_sumSynpaticInput_homog(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_sumSynpaticInput_homog0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "sumSynpaticInput_homog", "\n""    - sumSynpaticInput_homog(float[:], int, int, int, int[:], int[:], float, float, float[:,:])", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_sumSynpaticInput(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_sumSynpaticInput0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "sumSynpaticInput", "\n""    - sumSynpaticInput(float[:], int, int, int, int[:], int[:], float[:,:], float[:,:], float[:,:])", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_generate_random_net_fixed_input(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_generate_random_net_fixed_input0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "generate_random_net_fixed_input", "\n""    - generate_random_net_fixed_input(int, int, int, int)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_RunSimulation_GLNetEIMF_static(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_RunSimulation_GLNetEIMF_static0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "RunSimulation_GLNetEIMF_static", "\n""    - RunSimulation_GLNetEIMF_static(str:str dict, str:str dict)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_RunSimulation_GLNetEIMF_adapt(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_RunSimulation_GLNetEIMF_adapt0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "RunSimulation_GLNetEIMF_adapt", "\n""    - RunSimulation_GLNetEIMF_adapt(str:str dict, str:str dict)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_RunSimulation_GLNetEIMF_aval(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_RunSimulation_GLNetEIMF_aval0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "RunSimulation_GLNetEIMF_aval", "\n""    - RunSimulation_GLNetEIMF_aval(str:str dict, str:str dict)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_RunSimulation_GLNetEIMF_adaptthresh(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_RunSimulation_GLNetEIMF_adaptthresh0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "RunSimulation_GLNetEIMF_adaptthresh", "\n""    - RunSimulation_GLNetEIMF_adaptthresh(str:str dict, str:str dict)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_RunSimulation_GLNetEIRand_static(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_RunSimulation_GLNetEIRand_static0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "RunSimulation_GLNetEIRand_static", "\n""    - RunSimulation_GLNetEIRand_static(str:str dict, str:str dict)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_get_param(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_get_param0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "get_param", "\n""    - get_param(str, str)", args, kw);
                });
            }


            static PyObject *
            __pythran_wrapall_get_system_parameters(PyObject *self, PyObject *args, PyObject *kw)
            {
                return pythonic::handle_python_exception([self, args, kw]()
                -> PyObject* {

if(PyObject* obj = __pythran_wrap_get_system_parameters0(self, args, kw))
    return obj;
PyErr_Clear();

                return pythonic::python::raise_invalid_argument(
                               "get_system_parameters", "\n""    - get_system_parameters(str:str dict, str:str dict)", args, kw);
                });
            }


static PyMethodDef Methods[] = {
    {
    "write_spk_data_fake",
    (PyCFunction)__pythran_wrapall_write_spk_data_fake,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - write_spk_data_fake(int, int)"},{
    "save_spk_data",
    (PyCFunction)__pythran_wrapall_save_spk_data,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - save_spk_data((int, int) list, int, int)"},{
    "save_spk_data_fake",
    (PyCFunction)__pythran_wrapall_save_spk_data_fake,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - save_spk_data_fake((int, int) list, int, int)"},{
    "PoissonProcess_firingprob",
    (PyCFunction)__pythran_wrapall_PoissonProcess_firingprob,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - PoissonProcess_firingprob(float)"},{
    "multvecelem",
    (PyCFunction)__pythran_wrapall_multvecelem,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - multvecelem(float list, float list)"},{
    "PHI",
    (PyCFunction)__pythran_wrapall_PHI,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - PHI(float, float, float)"},{
    "weightAdapt_increase",
    (PyCFunction)__pythran_wrapall_weightAdapt_increase,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - weightAdapt_increase(float, float, float, float, float, float)"},{
    "weightAdapt_decrease",
    (PyCFunction)__pythran_wrapall_weightAdapt_decrease,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - weightAdapt_decrease(float, float, float, float, float, float)"},{
    "GLNetEIMF_iter",
    (PyCFunction)__pythran_wrapall_GLNetEIMF_iter,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - GLNetEIMF_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float)"},{
    "GLNetEIMF_adaptthresh_iter",
    (PyCFunction)__pythran_wrapall_GLNetEIMF_adaptthresh_iter,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - GLNetEIMF_adaptthresh_iter(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float)"},{
    "GLNetEIRand_iter",
    (PyCFunction)__pythran_wrapall_GLNetEIRand_iter,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - GLNetEIRand_iter(float, float, float, float, float, float, float, float, float)"},{
    "GLNetEIRand_adaptthresh_iter",
    (PyCFunction)__pythran_wrapall_GLNetEIRand_adaptthresh_iter,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - GLNetEIRand_adaptthresh_iter(float, float, float, float, float, float, float, float, float, float, float)"},{
    "generate_IC_spikes",
    (PyCFunction)__pythran_wrapall_generate_IC_spikes,
    METH_VARARGS | METH_KEYWORDS,
    "generates a list X of zeros with len N containing K ones\n""\n""\n""    Supported prototypes:\n""\n""    - generate_IC_spikes(int, int, int, bool)"},{
    "set_MF_network_IC",
    (PyCFunction)__pythran_wrapall_set_MF_network_IC,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - set_MF_network_IC(int, int, float, float, float, float, float, float, int, float, bool, int, float, bool, float)"},{
    "save_initial_spkdata",
    (PyCFunction)__pythran_wrapall_save_initial_spkdata,
    METH_VARARGS | METH_KEYWORDS,
    "\n""spkData = [[0 for i in range(nNeuronsSpk)] for t in range(Tmax)]\n""spkData[0] = XE[:pN_s] + XI[:qN_s]\n"" spkData is a list of tuples\n"" where each tuple records (time step, neuron index) for each firing\n"" the pythran breaks with the line below, probably due to enumerate and conditional for loop\n""spkData = [ [0,i] for i,x in enumerate(XE[:pN_s]) if x == 1 ] + [ [0,i+pN_s] for i,x in enumerate(XI[:qN_s]) if x == 1 ]\n""\n""\n""Supported prototypes:\n""\n""- save_initial_spkdata(int[:], int[:], int, int)"},{
    "run_transient_GLNetEIMF_static",
    (PyCFunction)__pythran_wrapall_run_transient_GLNetEIMF_static,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - run_transient_GLNetEIMF_static(float[:], int[:], float[:], int[:], float, float, int, int, float, float, float, int, float, float, float, float, float, float, float, float, float)"},{
    "run_transient_GLNetEIMF_adapt",
    (PyCFunction)__pythran_wrapall_run_transient_GLNetEIMF_adapt,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - run_transient_GLNetEIMF_adapt(float[:], int[:], float[:], int[:], float[:], float[:], float, float, float, int, int, float, float, float, str, int, float, float, float, float, float, float, float, float, float, float, float, float, float)"},{
    "run_transient_GLNetEIMF_aval",
    (PyCFunction)__pythran_wrapall_run_transient_GLNetEIMF_aval,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - run_transient_GLNetEIMF_aval(float[:], int[:], float[:], int[:], float, float, int, int, float, float, float, int, float, float, float, float, float, float, float, float, float)"},{
    "run_transient_GLNetEIMF_adaptthresh",
    (PyCFunction)__pythran_wrapall_run_transient_GLNetEIMF_adaptthresh,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - run_transient_GLNetEIMF_adaptthresh(float[:], int[:], float[:], int[:], float[:], float[:], float, float, float, int, int, float, float, float, float, str, int, float, float, float, float, float, float, float, float, float)"},{
    "run_transient_GLNetEIRand_static",
    (PyCFunction)__pythran_wrapall_run_transient_GLNetEIRand_static,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - run_transient_GLNetEIRand_static(float[:], int[:], float[:], int[:], int, float, float, int, int, float, float, float, float, float, float, float, float, float[:], float, float, float[:,:], int, int)"},{
    "sumSynpaticInput_homog",
    (PyCFunction)__pythran_wrapall_sumSynpaticInput_homog,
    METH_VARARGS | METH_KEYWORDS,
    "\n""K_ex -> number of excitatory inputs\n""K -> total number of inputs\n""N -> total number of neurons\n""XE -> state of excitatory neurons\n""XI -> state of inhibitory neurons\n""J -> excitatory synaptic weights (constant)\n""W -> inhibitory synaptic weights (positive constant)\n""C -> connectivity matrix (each entry in the outer list is the list of neighbor indices)\n""     C[i] -> list of neighbors of i;\n""     C[i][:K_ex] -> excitatory neighbors (indices go from 0 to pN-1); C[i][K_ex:] -> inhibitory neighbors (indices go from 0 to N-pN-1)\n""\n""\n""Supported prototypes:\n""\n""- sumSynpaticInput_homog(float[:], int, int, int, int[:], int[:], float, float, float[:,:])"},{
    "sumSynpaticInput",
    (PyCFunction)__pythran_wrapall_sumSynpaticInput,
    METH_VARARGS | METH_KEYWORDS,
    "\n""K_ex -> number of excitatory inputs\n""K -> total number of inputs\n""N -> total number of neurons\n""XE -> state of excitatory neurons\n""XI -> state of inhibitory neurons\n""J -> excitatory synaptic weights (each entry in the outer list is the list of neighbor input excitatory weights)\n""     J[i] -> list of input excitatory weights for neuron i; contains K_ex entries\n""W -> inhibitory synaptic weights (positively defined; each entry in the outer list is the list of neighbor input inhibitory weights)\n""     W[i] -> list of input inhibitory weights for neuron i (all positive); contains K-K_ex entries\n""C -> connectivity matrix (each entry in the outer list is the list of neighbor indices)\n""     C[i] -> list of neighbors of i;\n""     C[i][:K_ex] -> excitatory neighbors (indices go from 0 to pN-1); C[i][K_ex:] -> inhibitory neighbors (indices go from 0 to N-pN-1)\n""\n""\n""Supported prototypes:\n""\n""- sumSynpaticInput(float[:], int, int, int, int[:], int[:], float[:,:], float[:,:], float[:,:])"},{
    "generate_random_net_fixed_input",
    (PyCFunction)__pythran_wrapall_generate_random_net_fixed_input,
    METH_VARARGS | METH_KEYWORDS,
    "\n""##################\n""#BUILD RANDOM NETWORK WITH constant k_in neighbors\n""#Neurons cannot have repeated neighbors\n""##################\n""returns list C where each entry is the list of neighbor indices:\n""C[i] -> list of neighbors of i;\n""C[i][:K_ex] -> excitatory neighbors (indices go from 0 to pN); C[i][K_ex:] -> inhibitory neighbors (indices go from 0 to qN)\n""\n""Supported prototypes:\n""\n""- generate_random_net_fixed_input(int, int, int, int)\n""\n""K_ex -> number of excitatory inputs\n""pN -> total number of excitatory inputs\n""K -> total number of inputs\n""N -> total number of neurons in the network\n"""},{
    "RunSimulation_GLNetEIMF_static",
    (PyCFunction)__pythran_wrapall_RunSimulation_GLNetEIMF_static,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - RunSimulation_GLNetEIMF_static(str:str dict, str:str dict)"},{
    "RunSimulation_GLNetEIMF_adapt",
    (PyCFunction)__pythran_wrapall_RunSimulation_GLNetEIMF_adapt,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - RunSimulation_GLNetEIMF_adapt(str:str dict, str:str dict)"},{
    "RunSimulation_GLNetEIMF_aval",
    (PyCFunction)__pythran_wrapall_RunSimulation_GLNetEIMF_aval,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - RunSimulation_GLNetEIMF_aval(str:str dict, str:str dict)"},{
    "RunSimulation_GLNetEIMF_adaptthresh",
    (PyCFunction)__pythran_wrapall_RunSimulation_GLNetEIMF_adaptthresh,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - RunSimulation_GLNetEIMF_adaptthresh(str:str dict, str:str dict)"},{
    "RunSimulation_GLNetEIRand_static",
    (PyCFunction)__pythran_wrapall_RunSimulation_GLNetEIRand_static,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - RunSimulation_GLNetEIRand_static(str:str dict, str:str dict)"},{
    "get_param",
    (PyCFunction)__pythran_wrapall_get_param,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - get_param(str, str)"},{
    "get_system_parameters",
    (PyCFunction)__pythran_wrapall_get_system_parameters,
    METH_VARARGS | METH_KEYWORDS,
    "Supported prototypes:\n""\n""    - get_system_parameters(str:str dict, str:str dict)"},
    {NULL, NULL, 0, NULL}
};


#if PY_MAJOR_VERSION >= 3
  static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "GLNetEISimLib",            /* m_name */
    "",         /* m_doc */
    -1,                  /* m_size */
    Methods,             /* m_methods */
    NULL,                /* m_reload */
    NULL,                /* m_traverse */
    NULL,                /* m_clear */
    NULL,                /* m_free */
  };
#define PYTHRAN_RETURN return theModule
#define PYTHRAN_MODULE_INIT(s) PyInit_##s
#else
#define PYTHRAN_RETURN return
#define PYTHRAN_MODULE_INIT(s) init##s
#endif
PyMODINIT_FUNC
PYTHRAN_MODULE_INIT(GLNetEISimLib)(void)
#ifndef _WIN32
__attribute__ ((visibility("default")))
__attribute__ ((externally_visible))
#endif
;
PyMODINIT_FUNC
PYTHRAN_MODULE_INIT(GLNetEISimLib)(void) {
    import_array()
    #if PY_MAJOR_VERSION >= 3
    PyObject* theModule = PyModule_Create(&moduledef);
    #else
    PyObject* theModule = Py_InitModule3("GLNetEISimLib",
                                         Methods,
                                         ""
    );
    #endif
    if(! theModule)
        PYTHRAN_RETURN;
    PyObject * theDoc = Py_BuildValue("(sss)",
                                      "0.9.9.dev",
                                      "2022-02-21 13:37:57.952808",
                                      "a1a6af1f3dc1fa6882bf03a3523531f049bdad0e5014e95503062f013350967f");
    if(! theDoc)
        PYTHRAN_RETURN;
    PyModule_AddObject(theModule,
                       "__pythran__",
                       theDoc);


    PYTHRAN_RETURN;
}

#endif