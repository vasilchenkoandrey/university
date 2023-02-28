#!/bin/bash
res=0
read h1 m1 h2 m2
while [ 1 ]
do
	if (($m1==0))
	then
		if (($h1>12))
        then
            res=$(($res+$h1-12))
        else
            if (($h1==0))
            then
            	res=$(($res+12))
            else
            	res=$(($res+$h1))
            fi
        fi
	else
		if (($m1==30))
		then
			res=$(($res+1))
		fi
	fi
 
	if (($h1==$h2 && $m1==$m2))
	then
		break
	fi
	m1=$(($m1+1))
 
	if (($m1==60))
	then
		m1=0
		h1=$(($h1+1))
	fi
done
echo $res