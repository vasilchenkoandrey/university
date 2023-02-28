#!/bin/bash
read a
if [[ $a =~ [y,Y] ]]
  then echo "YES"
  else echo "NO"
fi