#!/bin/bash

str=($(cat))

for ((i=0; i<${#str[@]}; i++))
do
	word=${str[i]}

	if [[ $(rev <<< "$word") == "$word" ]]
	then
    	echo $word
	fi
done