#!/bin/bash

for i in 1 2 3 4 5
do
	out=$(./trabalho1.exe $1 $i)

	echo "$out \n" >> "output_$1.txt"
done
