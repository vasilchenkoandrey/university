#!/bin/bash
read SIZE
for ((i=0; i<SIZE; i++))
do
	read string[i]
done
str=$(echo ${string[@]} | grep -E -o "\b[A-Za-z0-9]+[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,6}\b" | sort)
echo ${str[@]} | tr " " ";" | sed -r 's/(.*)./\0\n/'
