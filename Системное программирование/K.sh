#!/bin/bash
read countArr
for ((k=0; k<countArr; k++))
do
	read N
	read -a arr
	bool=0
	for ((i=0; i<N; i++))
	do
		p=${arr[i]}
		res=0
		for ((j=1; j<p; j++))
		do
			if ((p%j == 0))
			then
				res=$(($j+$res))
			fi
		done
		if ((res == p))
		then
			echo $res
			let bool++
		fi
	done
	
	if ((bool==0))
		then
			echo "-1"
		fi
done