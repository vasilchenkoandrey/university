#!/bin/bash
read x
digit_count=0
max_digit=0
max_digit_pos=0
while (($x>0))
do
    tmp=$(($x%10))
    if (($tmp>$max_digit))
    then
        max_digit=$tmp
    	max_digit_pos=$digit_count
	fi
    digit_count=$(($digit_count+1))
    x=$(($x/10))
done
 
if (($max_digit_pos==$digit_count/2))
then
    echo 0
else 
    if (($max_digit_pos>$digit_count/2))
	then
        echo -1
    else
        echo 1
    fi
fi