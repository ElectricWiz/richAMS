#!/bin/bash

M=3  # replace with your desired number of outer iterations
N=6  # replace with your desired number of inner iterations

for ((j=1; j<=M; j++))
do
    for ((i=1; i<=N; i++))
    do
    ./sim circle.mac
    hadd test${j}_${i}.root output_t{0..11}.root
    rm output*.root

    if ((i==N))
    then
	    sed -i "s/9.0/3.0/g" ./circle.mac
    else
        if (( i > 1 ))
        then
	        val2=$(echo "scale=1; 3.0 + $i * 1.2" | bc)
            val1=$(echo "scale=1; 3.0 + ($i - 1) * 1.2" | bc)
        else
	        val2=4.2
	        val1=3.0
        fi
        
        sed -i "s/$val1/$val2/g" ./circle.mac 
    fi
    done
done
