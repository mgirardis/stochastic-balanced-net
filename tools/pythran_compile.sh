#!/bin/bash

THIS_SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
PY_SCRIPT_DIR=$(dirname "$THIS_SCRIPT_DIR")

export PYTHRANRC=$THIS_SCRIPT_DIR/config.pythranrc

# the line below generates a cpp code
#pythran GLNetEISimLib.py -o GLNetEISimLib.cpp -Ofast -march=native -v -e

#################
################
################
################ use pythran 0.9.9.dev0 ~/programs/python/pythran, since it has a bug correction made locally by me
################
################
################
pythran $PY_SCRIPT_DIR/modules/GLNetEISimLib.py -o $PY_SCRIPT_DIR/modules/GLNetEISimLib.so -Ofast -march=native -v

# compile line generated by pythran
# x86_64-linux-gnu-gcc -pthread -Wno-unused-result -Wsign-compare -DNDEBUG -fwrapv -Wall -fstack-protector-strong -Wformat -Werror=format-security -fwrapv -fPIC -DENABLE_PYTHON_MODULE -D__PYTHRAN__=3 -DPYTHRAN_BLAS_BLAS -I/usr/local/lib/python3.8/dist-packages/pythran -I/usr/local/lib/python3.8/dist-packages/numpy/core/include -I/usr/include/python3.8 -c GLNetEISimLib.cpp -o GLNetEISimLib.o -std=c++11 -fno-math-errno -w -fvisibility=hidden -fno-wrapv -Ofast -march=native
