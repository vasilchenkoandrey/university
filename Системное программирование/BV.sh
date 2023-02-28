#!/bin/bash
read N
fact=($(cat))
for ((i=0; i<N; i++))
do
	seq -s "*" ${fact[$i]} |bc
done