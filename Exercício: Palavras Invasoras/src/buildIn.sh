#!/bin/bash

[ $# == 0 ] && { echo "Error: no amount specified"; 
                 echo "Usage: $0 <value>"; 
                 exit 1;}

max_value=$1
for num in $(seq 1 $max_value)
do
    touch $num.in
done