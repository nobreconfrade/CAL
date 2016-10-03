#!/bin/bash

for s in 1
	do
	echo "Sample $s" >> "output_$1.txt"
	for i in 1 2 3 4 5
	do
		out=$(./trabalho1.exe $1 $i)

		echo "$out \n" >> "output_$1.txt"
	done
	echo "end_sample\n" >> "output_$1.txt"
done
