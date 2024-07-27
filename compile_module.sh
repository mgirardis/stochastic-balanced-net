#!/bin/bash

#mv modules/GLNetEISimLib_cython.py modules/GLNetEISimLib.py -v

python3 setup.py build_ext --inplace

#mv modules/GLNetEISimLib.py modules/GLNetEISimLib_cython.py -v
