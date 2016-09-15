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
int Partition(vector<int>& v, int iPivot, int iLeft, int iRight) {
	int iLeftScan 	= iLeft;
	int iRightScan 	= iRight;

	int pivot = v[iPivot];

	while (iLeftScan < iRightScan) {
		while (v[iLeftScan] <= pivot &&
				iLeftScan <= iRight &&
				iRightScan > iLeftScan) {
			iLeftScan += 1;
		}
		while (v[iRightScan] > pivot &&
				iRightScan >= iLeft &&
				iRightScan >= iLeftScan) {
			iRightScan -= 1;
		}

		if (iLeftScan < iRightScan) {
			Swap(v[iLeftScan], v[iRightScan]);
		}
	}

	Swap(v[iPivot], v[iRightScan]);

	return iRightScan;
}

void Quicksort(vector<int>& v, int iLeft, int iRight) {
	if(iRight - iLeft < 2)
		return;

	int iPartition = Partition(v, iLeft, iLeft, iRight);

	Quicksort(v, iLeft, iPartition);
	Quicksort(v, iPartition+1, iRight);
}
