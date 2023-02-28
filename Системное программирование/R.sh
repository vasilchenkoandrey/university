#!/bin/bash
read r
for ((i=0; i<$r; i++))
do
    read l w h
    s=$((2*$h*$(($w+l))))
    if (($s%16!=0))
    then
		echo $(($s/16+1)) | bc -l
	else
		echo $(($s/16)) | bc -l
	fi
done