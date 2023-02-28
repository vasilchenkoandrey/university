#!/bin/bash
read n k
if (($n<=$k))
then
	echo 2
else
	if ((($n*2)%k==0))
	then
	    echo $((2*$n/$k))
	else
		echo $((2*$n/$k+1))
	fi
fi
