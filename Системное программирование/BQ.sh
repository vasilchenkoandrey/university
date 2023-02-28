#!/bin/bash
read n m
arr=($(cat))
echo ${arr[@]:$n:$m - $n + 1}