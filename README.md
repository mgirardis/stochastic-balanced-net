# stochastic-balanced-net
A python simulation of an Excitatory/Inhibitory Network of stochastic integrate-and-fire neurons

# Compiling for linux

You need the `setup.py`, and the `__init__.py` in the `modules/` directory. Then, just run `compile_module.sh` and a cython `.so` should be generated in the modules directory. Required: cython and python development version.

# scientific publications (please cite)

* Girardi-Schappo M, Galera EF, Carvalho TTA, Brochini L, Kamiji NL, Roque AC, Kinouchi O (2021): A unified theory of E/I synaptic balance, quasicritical neuronal avalanches and asynchronous irregular spiking. J. Phys. Complex. 2, 045001, https://doi.org/10.1088/2632-072X/ac2792

* Girardi-Schappo M, Brochini L, Costa AA, Carvalho TTA, Kinouchi O (2020): Synaptic balance due to homeostatically self-organized quasicritical dynamics. Phys. Rev. Research 2, 012042. https://doi.org/10.1103/PhysRevResearch.2.012042

* Carvalho TTA, Fontenele AJ, Girardi-Schappo M, Feliciano T, Aguiar LAA, Silva TPL, de Vasconcelos NAP, Carelli PV, Copelli M (2021): Subsampled directed-percolation models explain scaling relations experimentally observed in the brain. Front. Neural Circuits 14: 576727. https://doi.org/10.3389/fncir.2020.576727
