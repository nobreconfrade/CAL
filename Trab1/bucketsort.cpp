#include <iostream>
#include <vector>
#include <math.h>

#include "bucketsort.hpp"
//#include "insertsort.hpp"

#define NUM_BUCKETS 10

using namespace std;

template<typename T>
void Swap(T& a, T& b) {
	T t = b;
	b = a;
	a = t;
}

void insertSort2(std::vector<int> &v){
	int j = 0;
	for(int i = 1; i < v.size(); i++){
		j = i;
		while((j > 0) && v[j-1] > v[j]){
			Swap(v[j-1], v[j]);
			j--;
		}
	}
}

/*
void printBuckets(vector<vector<int> >& buckets){
	cout << "Tamanho: " << buckets.size();
	for(int i = 0; i < buckets.size(); i++){
		cout << "Balde[" << i << "] -> ";
		for(int j = 0; j < buckets[i].size(); j++){
			cout << buckets[i][j] << "->";
		}
		cout << endl;
	}
}
*/

void bucketSort(vector<int>& v){
	vector< vector<int> > buckets;
	vector<int> aux;
	int max = v[0];
	int min = v[0];
	double bucketFactor;
	int numBuckets = NUM_BUCKETS;
	int count;
	for(int i = 0; i < v.size(); i++){
		if(v[i] > max) max = v[i];
		if(v[i] < min) min = v[i];
	}

	bucketFactor = ((max - min) + 1.0) / double(numBuckets);

	for(int i = 0; i < numBuckets; i++)
		buckets.push_back(aux);

	for(int i = 0; i < v.size(); i++){
		buckets[trunc(v[i] / float(bucketFactor))].push_back(v[i]);
	}

	for(int i = 0; i < buckets.size(); i++){
		if(buckets[i].empty())
			continue;
		else
			insertSort2(buckets[i]);
	}

	count = 0;
	for(int i = 0; i < buckets.size(); i++){
		if(buckets[i].empty())
			continue;
		else{
			for(int j = 0; j < buckets[i].size(); j++){
				v[count++] = buckets[i][j];
			}
		}
	}

	for(int i = 0; i < buckets.size(); i++){
		if(buckets[i].empty())
			continue;
		else{
			buckets[i].clear();
		}
	}
	buckets.clear();
}
