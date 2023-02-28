#!/bin/bash
read -a n
k=0
for ((i=1; i<=${n[0]}&&$k==0; i++))
do
	((${n[i]}<=544)) && k=$i
done
(($k)) && echo Crash $k || echo No crash