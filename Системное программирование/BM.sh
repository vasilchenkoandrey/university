#!/bin/bash
read n
sum=0
for ((i=0; i<n; i++))
do
	read x
	sum=$(($sum+$x))
done
printf "%.3f" $(echo "$sum/$n" | bc -l)