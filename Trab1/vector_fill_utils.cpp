#include "vector_fill_utils.hpp"

#include <numeric> 	// iota
#include <stdlib.h>	// rand
#include <iostream>

using std::vector;

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
			int aux = rand() % 10000000;
			v.push_back(aux);
		}
		break;
		case 4:
		int valorfix = rand() % vectOption - 1;
		for(int i = 0; i < vectOption; i++){
			if(i == valorfix){
				v.push_back(100000000);
			}
			else{
				int aux = rand() % 10000000;
				v.push_back(aux);
			}
		}
		break;
	}
}

void PrintVector (vector<int> &v, int vectOption) {
	for(int r = 0; r < vectOption; ++r){
		std::cout << v[r] << ',';
	}
	std::cout << std::endl;
}
