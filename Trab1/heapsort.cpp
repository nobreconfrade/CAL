#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void Swap(T& a, T& b) {
	T t = b;
	b = a;
	a = t;
}

int LeftChild(int i) {
	return 2 * i + 1;
}

int RightChild(int i) {
	return 2 * i + 2;
}

void Heapify (vector<int>& array, int i) {
	int iLeft  = LeftChild(i);
	int iRight = RightChild(i);

	int n = array.size();

	int iLargest = 0;
	if (iLeft < n && array[iLeft] > array[i]) {
		iLargest = iLeft;
	}
	else
		iLargest = i;

	if (iRight < n && array[iRight] > array[iLargest]) {
		iLargest = iRight;
	}

	if (iLargest != i) {
		// cout << "Swapping: " << array[i] << " " << array[iLargest] << endl;
		Swap(array[i], array[iLargest]);
		Heapify(array, iLargest);
	}
}

// void Heapsort (vector<int>& array) {};
