#!/bin/bash
echo building OpenMP example with GCC+OpenMP ...
gcc -fopenmp omp.c -o bin/omp
echo starting ...
bin/omp