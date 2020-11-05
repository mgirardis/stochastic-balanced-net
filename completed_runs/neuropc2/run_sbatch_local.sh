#!/bin/bash

#SBATCH -J balancedNet         # Job name
#SBATCH -o out/balnet_%A_%a.out    # Name of stdout output file (%j expands to %jobID)
#SBATCH -e err/balnet_%A_%a.err    # Name of stdout output file (%j expands to %jobID)
#SBATCH -t 700:00:00              # Run time (hh:mm:ss) - 1.5 hours
#SBATCH -N 1-3
#SBATCH --array=2-61       # indices of the lines from lines_to_run.txt to be executed

LINE=$(sed -n "$SLURM_ARRAY_TASK_ID"p lines_to_run.txt)

echo Running task $SLURM_ARRAY_TASK_ID ::: $LINE

python $LINE
