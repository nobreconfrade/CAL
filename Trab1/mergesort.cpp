#include <iostream>
using namespace std;

// Tempo: O(n) | Espaço: O(n)
// T(n) = 2T(n/2) + O(n)
void merge (std::vector<int> &v, int e, int m, int d) {

    int i = e, j = m, k = 0;
    int aux[d - e];

    while (i < m && j < d) { // O(n - 1)
        if (v[i] < v[j]) aux[k++] = v[i++];
        else aux[k++] = v[j++];
    }

    while (i < m) { // O(n/2)
        aux[k++] = v[i++];
    }

    while (j < d) { // O(n/2)
        aux[k++] = v[j++];
    }

    for (k = 0, i = e; i < d; i++, k++ ) // O(n)
        v[i] = aux[k];

}

void mergeSort (std::vector<int> &v, int e, int d) {

    if (d - e < 2) return;

    int m = (e + d) / 2;

    mergeSort(v, e, m);
    mergeSort(v, m, d);
    merge(v, e, m, d);

}
