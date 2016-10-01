#!/bin/bash
# for i in 1 2 3 4
# do
# 	./trabalho1 25000 $i
# done

for i in 1 2 3 4 5
do
	out='0';
	count=0;

	out=$(./trabalho1.exe 25000 $i)

	echo $out

	echo "$out" >> tempout.txt
done
