#! /bin/bash

# Generate Out files

gcc -g solucao.c -o solucao -Wall -Werror
valgrind -q ./solucao < ./Casos\ teste/1.in > ./Casos\ teste/1.out
valgrind -q ./solucao < ./Casos\ teste/2.in > ./Casos\ teste/2.out
valgrind -q ./solucao < ./Casos\ teste/3.in > ./Casos\ teste/3.out
valgrind -q ./solucao < ./Casos\ teste/4.in > ./Casos\ teste/4.out
valgrind -q ./solucao < ./Casos\ teste/5.in > ./Casos\ teste/5.out