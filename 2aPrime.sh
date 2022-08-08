#!/bin/bash
#Shell Script to generate and print prime numbers in the given range

echo "Enter lower bound of the interval: "
read a
echo "Enter upper bound of the interval: "
read b
echo "Prime numbers in the range $a and $b are: "
for((i=a; i<=b; i++))
do
    if (($i == 0 || $i == 1)); then
        continue
    fi
    count=0
    for((j=1; j<=i; j++))
    do
        if [ $((i%j)) == 0 ]; then
            count=$((count+1))
        fi
    done
    if [ $count == 2 ]; then
        echo "$i"
    fi
done
