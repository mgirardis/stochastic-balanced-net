#!/bin/bash

#SBATCH -J balancedNet         # Job name
#SBATCH -o run/out/balnet_%A_%a.out    # Name of stdout output file (%j expands to %jobID)
#SBATCH -e run/err/balnet_%A_%a.err    # Name of stdout output file (%j expands to %jobID)
#SBATCH -t 700:00:00              # Run time (hh:mm:ss) - 1.5 hours
#SBATCH -N 1-3
#SBATCH --array=2-24       # indices of the lines from lines_to_run.txt to be executed

# going up one directory
THIS_SCRIPT_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )
#MAIN_SCRIPT_DIR=$(dirname "$THIS_SCRIPT_DIR")

#echo going to ... $MAIN_SCRIPT_DIR
#cd $MAIN_SCRIPT_DIR

LINE=$(sed -n "$SLURM_ARRAY_TASK_ID"p $THIS_SCRIPT_DIR/run/lines_to_run_tests.txt)
#LINE=$(sed -n "$SLURM_ARRAY_TASK_ID"p lines_to_run_tests.txt)
echo Running task $SLURM_ARRAY_TASK_ID ::: $LINE

python $LINE
