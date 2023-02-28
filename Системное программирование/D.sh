#!/bin/bash

read N
arr=($(cat))

count=0
res=1

for ((i=0; i<N; i++))
do
	for ((j=0; j<N; j++))
	do
		if ((${arr[i]} == ${arr[j]}))
		then
			let count++
		fi
	done
	
	
	if (($count > $res))
	then
		res=$count
	fi
	
	count=0
done

printf $res