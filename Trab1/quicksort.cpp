#include <iostream>
#include <vector>

#include "quicksort.hpp"
#include "vector_fill_utils.hpp"
using namespace std;

template<typename T>
void Swap(T& a, T& b)
{
	T t(b);
	b = a;
	a = t;
}


int partition(vector<int>& v, int iLeft, int iRight) {
	const int iPivot = (iLeft + iRight) / 2;
	const int pivot = v[iPivot];

	Swap(v[iLeft], v[iPivot]);

	int iLeftScan 	= iLeft + 1;
	int iRightScan 	= iRight;

	while (iLeftScan <= iRightScan) {
		while (v[iLeftScan] <= pivot && iLeftScan <= iRightScan) {
			iLeftScan += 1;
		}

		while (v[iRightScan] > pivot && iLeftScan <= iRightScan) {
			iRightScan -= 1;
		}

		if (iLeftScan < iRightScan) {
			Swap(v[iLeftScan], v[iRightScan]);
		}
	}

	Swap(v[iLeftScan - 1], v[iLeft]);

	return iLeftScan - 1;
}

void quickSort(vector<int>& v, int iLeft, int iRight) {
	if(iLeft >= iRight)
		return;

	// PrintVector(v);
	int iPartition = partition(v, iLeft, iRight);
	// PrintVector(v);
	// cout << "Parition: " << v[iPartition] << endl;
	quickSort(v, iLeft, iPartition - 1);
	quickSort(v, iPartition + 1, iRight);
}


int partition2(vector<int>& v, int iLeft, int iRight) {
	const int iPivot = iLeft;
	const int pivot = v[iPivot];

	int iLeftScan 	= iLeft + 1;
	int iRightScan 	= iRight;

	while (iLeftScan <= iRightScan) {
		while (v[iLeftScan] <= pivot && iLeftScan <= iRightScan) {
			iLeftScan += 1;
		}

		while (v[iRightScan] > pivot && iLeftScan <= iRightScan) {
			iRightScan -= 1;
		}

		if (iLeftScan < iRightScan) {
			Swap(v[iLeftScan], v[iRightScan]);
		}
	}

	Swap(v[iLeftScan - 1], v[iLeft]);

	return iLeftScan - 1;
}


void quickSort2(vector<int>& v, int iLeft, int iRight) {
	if(iLeft >= iRight)
		return;

	// PrintVector(v);
	int iPartition = partition(v, iLeft, iRight);
	// PrintVector(v);
	// cout << "Parition: " << v[iPartition] << endl;
	quickSort(v, iLeft, iPartition - 1);
	quickSort(v, iPartition + 1, iRight);
}
