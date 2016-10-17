#!/bin/bash

for i in 1 2 3 4 5
do
	./hashTree < entrada-5.txt > saidaReal-5.txt
done

for i in 1 2 3 4 5
do
	./tree < entrada-5.txt > saidaReal-5.txt
done

for i in 1 2 3 4 5
do
	./list < entrada-5.txt > saidaReal-5.txt
done
