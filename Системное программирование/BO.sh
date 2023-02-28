#!/bin/bash
arr=($(cat))
printf "%d\n" "${arr[@]:1}"|sort|uniq -u