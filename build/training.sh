#!/bin/bash
N=15

for ((i=0; i<=N; i++))
    do
    ./sim vis.mac
    hadd training.root output_t{0..11}.root
    rm output*.root
    var=$((i+1))
    python3 ./Training.py $var $i
    sed -i "s/N = $i/N = $var/g" ./Training.py
    rm training.root
done
