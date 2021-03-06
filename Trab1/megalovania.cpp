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

using namespace std;

static vector<int> unorderedVector;

void SetupVector();

int main(){
	system("clear");
	int menuOption;
	bool shouldQuit = false;
	do {
		PrintVector(unorderedVector);
		cout << "==============================================" << endl;
		cout << "欢迎 ao trabalho 1 de CAL!" << endl;
		cout << "Escolha o algoritmo de ordenação:" << endl;
		cout << "0.Setup Vector" << endl; cout << "1.Bubble Sort" << endl;
		cout << "2.Insert Sort" << endl;
		cout << "3.Merge Sort" << endl;
		cout << "4.Quick Sort (Pivo na primeira posicao)" << endl;
		cout << "5.Quick Sort (Pivo em qualquer posicao)" << endl;
		cout << "6.Heap Sort" << endl;
		cout << "7.Counting Sort" << endl;
		cout << "8.Bucket Sort" << endl;
		cout << "==============================================" << endl;
		cin >> menuOption;

		auto v = unorderedVector;
		switch (menuOption) {
			case 0:
			{
				SetupVector();
			}
			break;
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
				Timer timer = Timer("QuickSort1");
				quickSort(v, 0, v.size());
			}
			break;
			case 5:
			{
				Timer timer = Timer("QuickSort2");
				quickSort(v, 0, v.size());
			}
			break;
			case 6:
			{
				Timer timer = Timer("HeapSort");
				heapSort(v);
			}
			break;
			case 7:
			{
				Timer timer = Timer("CountingSort");
				countingSort(v);
			}
			break;
			case 8:
			{
				Timer timer = Timer("BucketSort");
				bucketSort(v);
			}
			break;
			default:
				shouldQuit = true;
			break;
		}
		cout << "------------------" << endl;
		cout << "Sorted vector" << endl;
		PrintVector(v);
		cout << "------------------" << endl << endl;
	} while (shouldQuit == false);

}

void SetupVector() {
	if (unorderedVector.size() != 0) {
		unorderedVector.clear();
	}

	uint vectorSize;
	cout << "==============================================" << endl;
	cout << "Escolha o tamanho do vetor:" << endl;
	cout << "==============================================" << endl;
	cin >> vectorSize;
	unorderedVector.reserve(vectorSize);
	cout << "==============================================" << endl;
	cout << "Escolha o tipo de ordenação do vetor:" << endl;
	cout << "1.Ordem crescente" << endl;
	cout << "2.Ordem decrescente" << endl;
	cout << "3.Ordem aleatória e denso" << endl;
	cout << "4.Ordem aleatória denso e 100.000.000" << endl;
	cout << "5.Ordem aleatória denso e elementos repetidos" << endl;
	cout << "5.Ordem aleatória esparso" << endl;
	cout << "6.Ordem aleatória esparso com elemento 100.000.000" << endl;
	cout << "==============================================" << endl;
	uint fillOrderType;
	cin >> fillOrderType;

	CreateVector(fillOrderType, vectorSize, unorderedVector);
}
