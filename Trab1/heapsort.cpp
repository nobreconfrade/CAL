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

void Heapify (vector<int>& array, int i, int iLimit) {
	int iLeft  = LeftChild(i);
	int iRight = RightChild(i);

	int iMax = i;
	if (iLeft <= iLimit && array[iLeft] > array[iMax])
		iMax = iLeft;

	if (iRight <= iLimit && array[iRight] > array[iMax])
		iMax = iRight;

	if (iMax != i) {
		// cout << "Swapping: " << array[i] << " " << array[iMax] << endl;
		Swap(array[i], array[iMax]);
		Heapify(array, iMax, iLimit);
	}
}

void BuildHeap(vector<int>& array)
{
	int iLast = array.size() - 1;
	int iMid  = iLast / 2;

	for(int i = iMid; i >= 0; i--)
	{
		Heapify(array, i, iLast);
	}
}
void heapSort(vector<int>& array)
{
	BuildHeap(array);

	int iLast = array.size() - 1;
	for(int i = iLast; i > 0; i--)
	{
		Swap(array[0], array[i]);
		Heapify(array, 0, i - 1);
	}
}
