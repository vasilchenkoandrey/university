#!/bin/bash
read str
k=1
for (( i=0; i<$k; ++i ))
do
    strRes=${str:1}
    for (( j=1; j<${#str}; ++j ))
    do
        strDraft=${str:0:$j}${str:$(($j + 1))}
        if [ $strDraft -gt $strRes ]
        then
            strRes=$strDraft
        fi
    done
    str=$strRes
done
echo $str