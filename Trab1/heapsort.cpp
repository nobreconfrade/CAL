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

	int iSmallest = i;
	if (iLeft < n && array[iLeft] < array[i]) {
		iSmallest = iLeft;
	}
	else
		iSmallest = i;

	if (iRight < n && array[iRight] < array[iSmallest]) {
		iSmallest = iRight;
	}

	if (iSmallest != i) {
		// cout << "Swapping: " << array[i] << " " << array[iSmallest] << endl;
		Swap(array[i], array[iSmallest]);
		Heapify(array, iSmallest);
	}
}

void BuildHeap(vector<int>& array)
{
	for(int i = array.size() / 2 - 1; i >= 0; i--)
	{
		Heapify(array, i);
	}
}
void heapSort(vector<int>& array)
{
	BuildHeap(array);
	int iLast = array.size() - 1;
	for(int i = iLast; i > 1; i--)
	{
		Swap(array[0], array[i]);
		Heapify(array, i);
	}
}
