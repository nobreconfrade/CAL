/*
PRAISE THE SUN \o/
Trabalho 1 de Complexidade de Algoritmos: Complexidade de ordenação
Equipe:
    Guilherme Kricheldorf
    Karll Henning
    William Pereira
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <time.h>
#include <ctime>

#include "bubblesort.cpp"
#include "mergesort.cpp"

using namespace std;

void createVector (int sortOption, int vectOption, vector<int> &v);
double calcTime (struct timespec endtime, struct timespec begintime);
void printVector (vector<int> &v, int vectOption);
