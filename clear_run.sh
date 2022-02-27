#!/bin/bash

THIS_SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

if [ ! -d $THIS_SCRIPT_DIR/out ]; then
    mkdir $THIS_SCRIPT_DIR/out
fi
if [ ! -d $THIS_SCRIPT_DIR/err ]; then
    mkdir $THIS_SCRIPT_DIR/err
fi
if [ ! -d $THIS_SCRIPT_DIR/output ]; then
    mkdir $THIS_SCRIPT_DIR/output
fi

rm $THIS_SCRIPT_DIR/out/*
rm $THIS_SCRIPT_DIR/err/*
rm $THIS_SCRIPT_DIR/output/*
