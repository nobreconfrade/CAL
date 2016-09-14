#include <iostream>
using namespace std;
void bubbleSort(std::vector<int> &v){
	int i,j,r,aux;
	for(i=v.size()-1; i > 0; i--){  
        for(j=0; j < i ; j++){
            if(v[j]>v[j+1]){
                aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;
            }
        }
    }
    // for(r = 0; r < 10; ++r){
    //     printf("%d\n",v[r]);
    // }
}