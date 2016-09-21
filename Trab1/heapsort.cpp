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

void BuildHeap(vector<int>& array)
{
	for(int i = array.size() / 2; i > 0; i--)
	{
		Heapify(array, i);
	}
}
void heapSort(vector<int>& array)
{
	BuildHeap(array);
	for(int i = array.size(); i > 1; i--)
	{
		Swap(array[1], array[i]);
		Heapify(array, i);
	}
}
