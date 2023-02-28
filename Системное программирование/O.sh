#!/bin/bash
read x
s=$(fold -w1 <<<"$x" | sort | tr -d '\n')
del=${s:$(((${#s}-1)/2)):1}
print=${x//${s:$(((${#s}-1)/2)):1}}
echo $del
[ "$print" ] && echo $print || echo NULL