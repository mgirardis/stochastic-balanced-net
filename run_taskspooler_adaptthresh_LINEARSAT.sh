#!/bin/bash

# set the number of simultaneous jobs to run
ts -S 20

# set job name
JOB_LABEL=DTLIN

# set the input file
INPUT_CMD_FILE=run/lines_to_run_glexc_adaptthresh_SATURATE.txt

# set output directory (the directory below MUST EXIST ALREADY before calling this script)
OUTPUT_DIR=run/out

# submit jobs to queue
JID=0
while IFS= read -r line || [[ -n "$line" ]]; do
    JID=$((JID + 1))
    if [ -z "${line}" ]; then
        # cycles loop if line is empty
        continue
    fi
    echo Adding task $JOB_LABEL$JID to queue
    ts -n -L $JOB_LABEL$JID sh -c "./call_python.sh $line > $OUTPUT_DIR/$JOB_LABEL$JID.out"
done < "$INPUT_CMD_FILE"
