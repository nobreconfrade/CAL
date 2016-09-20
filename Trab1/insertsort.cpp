#include <iostream>
#include <vector>

#include "insertsort.hpp"

using namespace std;

template<typename T>
void Swap(T& a, T& b) {
	T t = b;
	b = a;
	a = t;
}

void insertSort(std::vector<int> &v){
	int j = 0;
	for(int i = 1; i < v.size(); i++){
		j = i;
		while((j > 0) && v[j-1] > v[j]){
			Swap(v[j-1], v[j]);
			j--;
		}
	}
}
