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
		// PrintVector(v);
	}
	v = unorderedVector;
	{
		Timer timer = Timer("InsertSort");
		insertSort(v);
		// PrintVector(v);
	}
	v = unorderedVector;
	{
		Timer timer = Timer("MergeSort");
		mergeSort(v, 0, v.size());
		// PrintVector(v);
	}
	v = unorderedVector;
	{
		Timer timer = Timer("QuickSort1");
		quickSort(v, 0, v.size() - 1);
		// PrintVector(v);
	}
	v = unorderedVector;
	{
		Timer timer = Timer("QuickSort2");
		quickSort2(v, 0, v.size() - 1);
		// PrintVector(v);
	}
	v = unorderedVector;
	{
		Timer timer = Timer("HeapSort");
		heapSort(v);
		// PrintVector(v);
	}
	v = unorderedVector;
	{
		Timer timer = Timer("CountingSort");
		countingSort(v);
		// PrintVector(v);
	}
	v = unorderedVector;
	{
		Timer timer = Timer("BucketSort");
		bucketSort(v);
		// PrintVector(v);
	}

	return 0;
}
