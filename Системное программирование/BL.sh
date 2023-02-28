#!/bin/bash
read a
read b
read c
if [ $(($a + $b)) -le $c ] || [ $(($a + $c)) -le $b ] || [ $(($b + $c)) -le $a ]
then
echo "ERROR"
elif [ $a -ne $b ] && [ $a -ne $c ] && [ $b -ne $c ]
then
echo "SCALENE"
elif [ $a -eq $b ] && [ $b -eq $c ]
then
echo "EQUILATERAL"
else
echo "ISOSCELES"
fi