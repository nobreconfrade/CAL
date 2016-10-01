#include "vector_fill_utils.hpp"

#include <numeric> 	// iota
#include <stdlib.h>	// rand
#include <iostream>

using std::vector;
using std::cout;
using std::endl;

template<typename T>
void Swap(T& a, T& b) {
	T t = b;
	b = a;
	a = t;
}

#define MAX_NUM 10000

void CreateVector(int ordeOption, int vectOption, vector<int> &v) {
	switch (ordeOption) {
		case 1:
		cout << "#Crescente#" << endl;
		for (int i = 0; i < vectOption; i++) {
			v.push_back(i);
		}
		break;
		case 2:
		cout << "#Decrescente#" << endl;
		for (int i = vectOption; i > 0; i--) {
			v.push_back(i);
		}
		break;
		case 3:
		cout << "#Aleatório denso#" << endl;
		for (int i = vectOption; i > 0; i--) {
			v.push_back(i);
		}
		for (int r = 0; r < 3; r++) {
			for (int i = 0; i < vectOption; i++) {
				int iSwapPartner = rand() % vectOption;
				Swap(v[i], v[iSwapPartner]);
			}
		}

		break;
		case 4:
		cout << "#Aleatório denso com elemento 100.000.000#" << endl;
		{
			for (int i = vectOption; i > 0; i--) {
				v.push_back(i);
			}
			for (int r = 0; r < 3; r++) {
				for (int i = 0; i < vectOption; i++) {
					int iSwapPartner = rand() % vectOption;
					Swap(v[i], v[iSwapPartner]);
				}
			}

			int iBignum = vectOption / 2;
			v[iBignum] = 100000000;
		}
		break;
		case 5:
		cout << "#Aleatório denso com n/4 elementos repetidos#" << endl;
		for (int i = vectOption; i > 0; i--) {
			v.push_back(i % (vectOption/4));
		}
		for (int i = 0; i < vectOption; i++) {
			int iSwapPartner = rand() % vectOption;
			Swap(v[i], v[iSwapPartner]);
		}
		break;
		case 6:
		cout << "#Aleatório esparso#" << endl;
		for(int i = 0; i < vectOption; i++) {
			int aux = rand() % MAX_NUM;
			v.push_back(aux);
		}
		break;
		case 7:
		cout << "#Aleatório esparso com elemento 100.000.000#" << endl;
		{
			int valorfix = vectOption / 2;
			for(int i = 0; i < vectOption; i++){
				int aux = rand() % MAX_NUM;
				v.push_back(aux);
			}
			v[valorfix] = 100000000;
		}
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
