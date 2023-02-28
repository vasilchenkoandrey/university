#!/bin/bash

read N
arr=($(cat))

maxVal=${arr[0]}
maxPos=0
minVal=${arr[0]}
minPos=0

for ((i=0; i < N; i++))
do
	if ((${arr[$i]} > $maxVal))
	then
		maxVal=${arr[$i]}
		maxPos=$i
    fi
    
    if ((${arr[$i]} < $minVal))
    then
		minVal=${arr[$i]}
		minPos=$i
    fi
done

arr[maxPos]=$minVal
arr[minPos]=$maxVal

for ((i=0; i < N; i++))
do
	echo ${arr[i]}
done
