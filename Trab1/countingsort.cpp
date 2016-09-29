#include <iostream>
#include <vector>

#include "countingsort.hpp"

using namespace std;

void countingSort(vector<int>& v){
	int max = v[0];
	int min = v[0];
	int z = 0;

	for(int i = 0; i < 10; i++)
	{
		if(v[i] > max) max = v[i];
		if(v[i] < min) min = v[i];
	}

	vector<int> count;
	count.reserve((max - min) + 1);

	for(int i = 0; i < v.size(); i++)
		count[v[i] - min] = count[v[i] - min] + 1;

	for(int i = min; i <= max; i++){
		while(count[i - min] > 0){
			v[z++] = i;
			count[i - min] = count[i - min] - 1;
		}
	}

	count.clear();
}
