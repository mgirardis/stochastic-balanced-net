#!/bin/bash

#THIS_SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

if [ ! -d run/out ]; then
    mkdir run/out
fi
if [ ! -d run/err ]; then
    mkdir run/err
fi
if [ ! -d run/output ]; then
    mkdir run/output
fi

rm run/out/*
rm run/err/*
rm run/output/*
