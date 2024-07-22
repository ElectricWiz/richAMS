M=3  # replace with your desired number of outer iterations
N=6 # replace with your desired number of inner iterations

for ((j=2; j<=M; j++))
do
    for ((i=1; i<=1; i++))
    do
    python3 DataAnalisis.py $j $i
    sed -i "s/N = 1/N = $j/g" ./DataAnalisis.py

    if ((i==N))
    then
	    sed -i "s/ene = 9.0/ene = 3.0/g" ./DataAnalisis.py
    else
        if (( i > 1 ))
        then
            val2=$(echo "scale=1; 3.0 + $i * 1.2" | bc)
            val1=$(echo "scale=1; 3.0 + ($i - 1) * 1.2" | bc)
        else
            val2=4.2
            val1=3.0
        fi  
    fi

    # Calculate the values for sed command   


    # Use sed to replace the values in circle.mac
    sed -i "s/ene = $val1/ene = $val2/g" ./DataAnalisis.py


    done
done
