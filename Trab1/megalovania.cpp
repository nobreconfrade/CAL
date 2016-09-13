/*
PRAISE THE SUN \o/
Trabalho 1 de Complexidade de Algoritmos: Complexidade de ordenação
Equipe:
    Guilherme Kricheldorf
    Karll Henning
    William Pereira
*/
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
    cout << "4.Quick Sort" << endl;
    cout << "4.Heap Sort" << endl;
    cout << "5.Counting Sort" << endl;
    cout << "6.Bucket Sort" << endl;
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
    cout << "3.Vetor em ordem aleatória com um elemento 100.000.000" << endl;
    cout << "==============================================" << endl;
    cin >> ordeOption;

    createVector(vectOption,ordeOption,v);
    cout << v.size() << endl;
    for(int i = 0 ; i < vectOption ; i++)
        cout << v[i] << endl;

    switch (sortOption) {
        case 1:
            break;
        case 2:
            break;
        default:
            break;
    }
}

void createVector(int ordeOption, int vectOption, vector<int> &v) {
    switch (ordeOption) {
        case 1:
            for(int i = 0 ; i < vectOption ; i++){
                v[i] = i;
            }
            break;
        case 2:
            for (int i = vectOption; i > 0; i--) {
                v.push_back(i);
            }
    }
}
