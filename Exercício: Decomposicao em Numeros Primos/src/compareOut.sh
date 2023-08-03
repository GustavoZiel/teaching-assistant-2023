#!/bin/bash
for i in $(seq 1 8)
do
  echo $i
  diff -s "$i.out" "./Casos de Teste/$i.out"
done
