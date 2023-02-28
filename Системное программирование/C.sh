#!/bin/bash

read N
arr=($(cat))

maxPos=0
minPos=0
j=0

for ((i=0; i < $N; i++))
do
  if ((${arr[$minPos]} > ${arr[$i]}))
  then
    minPos=$i
    fi
    
    if ((${arr[$maxPos]} < ${arr[$i]}))
    then
    maxPos=$i
    fi
done

if (($minPos<$maxPos))
then
  first=$minPos
  second=$maxPos
else
    first=$maxPos
    second=$minPos
fi

for ((i=0; i<$first+1; i++))
do
  echo ${arr[$i]}
done

for ((i=$second-1; i>=$first+1; i--))
do
  echo ${arr[$i]}
done

for ((i=$second; i<$N; i++))
do
  echo ${arr[$i]}
done