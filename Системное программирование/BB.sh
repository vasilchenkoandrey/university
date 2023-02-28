#!/bin/bash
read M N
res=$(($M*$N-1))
((res % 2 == 1)) && echo first || echo second