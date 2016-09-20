#include "vector_fill_utils.hpp"

#include <numeric> 	// iota
#include <stdlib.h>	// rand
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

#define MAX_NUM 10000

void CreateVector(int ordeOption, int vectOption, vector<int> &v) {
	switch (ordeOption) {
		case 1:
		for (int i = 0; i < vectOption; i--) {
			v.push_back(i);
		}
		break;
		case 2:
		for (int i = vectOption; i > 0; i--) {
			v.push_back(i);
		}
		break;
		case 3:
		for(int i = 0; i < vectOption; i++) {
			int aux = rand() % MAX_NUM;
			v.push_back(aux);
		}
		break;
		case 4:
		int valorfix = rand() % vectOption - 1;
		for(int i = 0; i < vectOption; i++){
			int aux = rand() % MAX_NUM;
			v.push_back(aux);
		}
		v[valorfix] = 100000000;
		break;
	}
}

void PrintVector (vector<int> &v) {
	if (v.empty()) {
		cout << "[cri cri cri...]" << endl;
		return;
	}
	cout << '[';
	for(uint r = 0; r < v.size() - 1; ++r){
		cout << v[r] << ", ";
	}
	// Imprime a última posição
	cout << v[v.size() - 1] << ']' << endl;
}
