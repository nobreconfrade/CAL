#!/bin/bash
# for i in 1 2 3 4
# do
# 	./trabalho1 25000 $i
# done

for i in 1 2 3 4 5
do
	out=$(./trabalho1.exe 1000000 $i)

	echo "$out \n" >> output.txt
done
