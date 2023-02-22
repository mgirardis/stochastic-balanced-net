#!/bin/bash

#SBATCH -J DT_Poi_aval                      # Job name
#SBATCH -o run/out/DT_Poi_aval_%A_%a.out    # Name of stdout output file (%j expands to %jobID)
#SBATCH -e run/err/DT_Poi_aval_%A_%a.err    # Name of stdout output file (%j expands to %jobID)
#SBATCH -t 700:00:00                        # Run time (hh:mm:ss) - 1.5 hours
#SBATCH -N 1-8
#SBATCH --array=2-49       # indices of the lines from lines_to_run.txt to be executed

LINE=$(sed -n "$SLURM_ARRAY_TASK_ID"p run/lines_to_run_adaptthresh_aval_poi.txt)
echo Running task $SLURM_ARRAY_TASK_ID ::: $LINE

python $LINE
