#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <sstream>

#include "timer.hpp"
#include "bubblesort.hpp"
#include "insertsort.hpp"
#include "mergesort.hpp"
#include "quicksort.hpp"
#include "countingsort.hpp"
#include "bucketsort.hpp"
#include "heapsort.hpp"
#include "vector_fill_utils.hpp"

using namespace std;

static vector<int> unorderedVector;

int main(int argc, char const *argv[]) {
	if (argc < 3) {
		cout << ":(" << endl;
		cout << "Execute o arquivo no seguinte formato:" << endl <<
				"./trabalho1 [tamanho-do-vetor] [tipo-de-ordenação]" << endl <<
				"Exemplo: ./trabalho1 25000 2" << endl << endl <<
				"Tipos de ordenação:" << endl <<
				"(1) Crescente" << endl <<
				"(2) Descrescente" << endl <<
				"(3) Aleatória esparsa" << endl <<
				"(4) Aleatória esparsa com elemento 100.000.000" << endl <<
				"(5) Aleatória e denso" << endl <<
				"(6) Aleatória denso e elementos repetidos" << endl << endl;
		return -1;
	}

	cout << "1.Ordem crescente" << endl;
	cout << "2.Ordem decrescente" << endl;
	cout << "3.Ordem aleatória esparso" << endl;
	cout << "4.Ordem aleatória esparso com elemento 100.000.000" << endl;
	cout << "5.Ordem aleatória e denso" << endl;
	cout << "6.Ordem aleatória denso e elementos repetidos" << endl;

	istringstream ss;
	int vectorSize, fillOrderType;
	ss = istringstream(argv[1]);
	ss >> vectorSize;
	ss = istringstream(argv[2]);
	ss >> fillOrderType;

	unorderedVector.reserve(vectorSize);
	CreateVector(fillOrderType, vectorSize, unorderedVector);


	auto v = unorderedVector;
	{
		Timer timer = Timer("BubbleSort");
		bubbleSort(v);
	}
	v = unorderedVector;
	{
		Timer timer = Timer("InsertSort");
		insertSort(v);
	}
	v = unorderedVector;
	{
		Timer timer = Timer("MergeSort");
		mergeSort(v, 0, v.size());
	}
	v = unorderedVector;
	{
		Timer timer = Timer("QuickSort1");
		quickSort(v, 0, v.size(), 0);
	}
	v = unorderedVector;
	{
		int iPivot = v.size() / 2;
		Timer timer = Timer("QuickSort2");
		quickSort(v, 0, v.size(), iPivot);
	}
	v = unorderedVector;
	{
		Timer timer = Timer("HeapSort");
		heapSort(v);
	}
	v = unorderedVector;
	{
		Timer timer = Timer("CountingSort");
		countingSort(v);
	}
	v = unorderedVector;
	{
		Timer timer = Timer("BucketSort");
		bucketSort(v);
	}

	return 0;
}
