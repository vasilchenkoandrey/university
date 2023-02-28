#!/bin/bash
read N
for (( i=0; i<$N; i++ ))
do
	read str[$i]
	sed "s/^\s*[[:alnum:]]\+[[:alnum:]._-]*[[:alnum:]]\+@[[:alnum:]]\+\.[[:alpha:]]\{2,4\}\s*$/YES/;t;s/.*/NO/" <<< ${str[$i]}
done