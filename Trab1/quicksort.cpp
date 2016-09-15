#include <iostream>

// Tempo: O(n) | Espaço: O(1)
int particao(int *v, int e, int d){
    // TODO: partição;
    return -1;
}

void quicksort(int *v, int e, int d){
    if(d-e<2)
        return;
    int p = particao(v,e,d);
    quicksort(v,e,p);
    quicksort(v,p+1,d);
}
