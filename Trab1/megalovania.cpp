/*
PRAISE THE SUN \o/
Trabalho 1 de Complexidade de Algoritmos: Complexidade de ordenação
Equipe:
    Guilherme Kricheldorf
    Karll Henning
    William Pereira
*/
#include <numeric>
#include "megalovania.h"

int main(){
    int sortOption,vectOption,ordeOption;
    // time_t start,finish;
    // clock_t begintime, endtime;
    struct timespec begintime, endtime;
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
    v.resize(vectOption);
    cout << "==============================================" << endl;
    cout << "Escolha o tipo de ordenação do vetor:" << endl;
    cout << "1.Vetor em ordem crescente" << endl;
    cout << "2.Vetor em ordem decrescente" << endl;
    cout << "3.Vetor em ordem aleatória" << endl;
    cout << "4.Vetor em ordem aleatória com um elemento 100.000.000" << endl;
    cout << "==============================================" << endl;
    cin >> ordeOption;

    createVector(ordeOption,vectOption,v);
    // printf("\n");
    // for(int i = 0 ; i < vectOption ; i++)
    //     cout << v[i] << endl;
    // printf("\n");

    switch (sortOption) {
        case 1:
            cout << "start!" << endl;
            clock_gettime(CLOCK_MONOTONIC, &begintime);
            bubbleSort(v);
            clock_gettime(CLOCK_MONOTONIC, &endtime);
            printf("finish! - Tempo de executação: %.4lf\n", calcTime(endtime,begintime));
            break;
        case 2:
            break;
        case 3:
            printVector(v, vectOption);
            cout << "start!" << endl;
            clock_gettime(CLOCK_MONOTONIC, &begintime);
            mergeSort(v, 0, vectOption);
            clock_gettime(CLOCK_MONOTONIC, &endtime);
            printf("finish! - Tempo de executação: %.4lf\n", calcTime(endtime,begintime));
            printVector(v, vectOption);
            break;
        default:
            break;
    }
}

void createVector(int ordeOption, int vectOption, vector<int> &v) {
    switch (ordeOption) {
        case 1:
            iota (begin(v), end(v), 0);
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
            int valorfix = rand() % vectOption-1;
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

double calcTime (struct timespec endtime, struct timespec begintime){
    double finaltime = endtime.tv_sec - begintime.tv_sec;
    finaltime += (endtime.tv_nsec - begintime.tv_nsec) / 1000000000.0;
    return finaltime;
}

void printVector (vector<int> &v, int vectOption) {
    for(int r = 0; r < vectOption; ++r){
        printf("%d\n", v[r]);
    }
}
