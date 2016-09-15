#include <iostream>
#include <vector>

#include "quicksort.hpp"

using namespace std;

template<typename T>
void Swap(T& a, T& b) {
	T t = b;
	b = a;
	a = t;
}

// Tempo: O(n) | Espaço: O(1)
int Partition(vector<int>& v, int e, int d) {
	int iLeftScan 	= e;
	int iRightScan 	= d;

	int iPivot = e;
	int pivot = v[iPivot];

	while (iLeftScan < iRightScan) {
		while (v[iLeftScan] <= pivot && iLeftScan <= d && iRightScan > iLeftScan) {
			iLeftScan += 1;
		}
		while (v[iRightScan] > pivot && iRightScan >= e && iRightScan >= iLeftScan) {
			iRightScan -= 1;
		}

		if (iRightScan > iLeftScan) {
			Swap(v[iLeftScan], v[iRightScan]);
		}
	}

	Swap(v[iPivot], v[iRightScan]);

	return iRightScan;
}

void Quicksort(vector<int>& v, int e, int d) {
	if(d - e < 2)
		return;

	int iPartition = Partition(v, e, d);
	
	Quicksort(v, e, iPartition);
	Quicksort(v, iPartition+1, d);
}
