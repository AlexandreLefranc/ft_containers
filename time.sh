#!/bin/sh

# make ft
# make std

N=5000
for i in `seq 1 $N`
do
	./containers_FT > /dev/null
done