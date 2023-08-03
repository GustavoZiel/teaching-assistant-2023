#!/bin/bash
for i in $(seq 1 8)
do
  echo $i
  ./area1 <"./Casos de Teste/$i.in" > "$i.out"
done
