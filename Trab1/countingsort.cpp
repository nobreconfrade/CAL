#include <iostream>
#include <vector>

#include "countingsort.hpp"

using namespace std;

void countingSort(vector<int>& vec) {
	vector<int> count;
	int max = vec[0];
	int min = vec[0];
	int z = 0;

	for(auto v : vec){
		if(v > max) max = v;
		if(v < min) min = v;
	}

	count.resize((max - min) + 1, 0);

	for(int i = 0; i < vec.size(); i++)
		count[vec[i] - min] += 1;

	for(int i = min; i <= max; i++){
		while(count[i - min] > 0){
			vec[z++] = i;
			count[i - min] -= - 1;
		}
	}

	count.clear();
}
