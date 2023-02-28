#!/bin/bash
read A
read B
if [[ "$A" =~ "$B" ]] 
then
	echo "YES"
else
	echo "NO"
fi