#!/bin/bash
read x
read y
if [ $x -lt $y ]
then
	echo "X is less than Y"
else
	if [ $x -gt $y ]
	then
		echo "X is greater than Y"
	else
		if [ $x -eq $y ]
		then
			echo "X is equal to Y"
		fi
	fi
fi