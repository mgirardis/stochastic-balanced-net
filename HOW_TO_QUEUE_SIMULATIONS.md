# HOW TO RUN MANY SIMULATIONS IN PARALLEL

1. install taskspooler from [https://viric.name/soft/ts/](https://viric.name/soft/ts/)

Basically, just

```
$ wget https://viric.name/soft/ts/ts-1.0.3.tar.gz
$ tar zxf ts-1.0.3.tar.gz
$ cd ts-1.0.3
$ make
$ sudo make install
```

this will make the command `ts` available system-wise. Type `ts` in the terminal to watch the queue.

2. copy the files `run_taskspooler.sh`, `clear.sh` and `call_python.sh` to the main simulation directory

3. modify the variables in `run_taskspooler.sh` (e.g., job name, number of simultaneous processes, output directory, name of the input file and other details...)

the input file (e.g., `lines_to_run.txt` must have a single simulation per line, all of which must be independent of one another, since they can and will run in parallel)

4. the script `call_python.sh` must activate the virtual environment and can do any other necessary tricks...

5. the script `clear.sh` can be modified so that it deletes all outputs and clears the queue of the `ts` command... the queue is not cleared automatically