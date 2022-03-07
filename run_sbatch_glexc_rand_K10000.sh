#!/bin/bash

#SBATCH -J K10000         # Job name
#SBATCH -o run/out/K10000_%A_%a.out    # Name of stdout output file (%j expands to %jobID)
#SBATCH -e run/err/K10000_%A_%a.err    # Name of stdout output file (%j expands to %jobID)
#SBATCH -t 700:00:00              # Run time (hh:mm:ss) - 1.5 hours
#SBATCH -N 1-8
#SBATCH --array=2-76       # indices of the lines from lines_to_run.txt to be executed

LINE=$(sed -n "$SLURM_ARRAY_TASK_ID"p run/lines_to_run_glexc_rand_K10000_poisson.txt)
echo Running task $SLURM_ARRAY_TASK_ID ::: $LINE

python $LINE
