/*
PRAISE THE SUN \o/
Trabalho 1 de Complexidade de Algoritmos: Complexidade de ordenação
Equipe:
	Guilherme Kricheldorf
	Karll Henning
	William Pereira
*/

#include "timer.hpp"
#include "vector_fill_utils.hpp"

#include "megalovania.h"

int main(){
	int sortOption,vectOption,ordeOption;

	vector<int> v;
	system("clear");
	cout << "==============================================" << endl;
	cout << "欢迎 ao trabalho 1 de CAL!" << endl;
	cout << "Escolha o algoritmo de ordenação:" << endl;
	cout << "1.Bubble Sort" << endl;
	cout << "2.Insert Sort" << endl;
	cout << "3.Merge Sort" << endl;
	cout << "4.Quick Sort (Pivo na primeira posicao)" << endl;
	cout << "5.Quick Sort (Pivo em qualquer posicao)" << endl;
	cout << "6.Heap Sort" << endl;
	cout << "7.Counting Sort" << endl;
	cout << "8.Bucket Sort" << endl;
	cout << "==============================================" << endl;
	cin >> sortOption;
	cout << "==============================================" << endl;
	cout << "Escolha o tamanho do vetor:" << endl;
	cout << "==============================================" << endl;
	cin >> vectOption;
	v.reserve(vectOption);
	cout << "==============================================" << endl;
	cout << "Escolha o tipo de ordenação do vetor:" << endl;
	cout << "1.Vetor em ordem crescente" << endl;
	cout << "2.Vetor em ordem decrescente" << endl;
	cout << "3.Vetor em ordem aleatória" << endl;
	cout << "4.Vetor em ordem aleatória com um elemento 100.000.000" << endl;
	cout << "==============================================" << endl;
	cin >> ordeOption;

	CreateVector(ordeOption, vectOption, v);

	switch (sortOption) {
		case 1:
		{
			Timer timer = Timer("BubbleSort");
			bubbleSort(v);
		}
		break;
		case 2:
		{
			Timer timer = Timer("InsertSort");
			insertSort(v);
		}
		break;
		case 3:
		{
			Timer timer = Timer("MergeSort");
			mergeSort(v, 0, v.size());
		}
		break;
		case 4:
		{
			Timer timer = Timer("QuickSort");
			quickSort(v, 0, v.size());
		}
		break;
		case 5:
		{

		}
		break;
		case 6:
		{

		}
		break;
		case 7:
		{

		}
		break;
		case 8:
		{

		}
		break;
		default:
		break;
	}

	PrintVector(v, vectOption);
}
