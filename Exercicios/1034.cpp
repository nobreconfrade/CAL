#include <iostream>
using namespace std;
#define INFINITE 0xFFFFF;

// http://www.ccs.neu.edu/home/jaa/CSG713.04F/Information/Handouts/dyn_prog.pdf
void iceblocks(int *tam,int n, int m){
    int c[100000],p,min,i;
    c[0] = 0;
    for(p=1;p<m;p++){
        min=INFINITE;
        for(i=0;i<n;i++){
            if(tam[i]<=p){
                if(1+c[p-tam[i]]<min){
                    min = 1 + c[p-tam[i]];
                }
            }
        }
        c[p] = min; //???
        // cout <<c[p]<< '\n';
    }
    // for(i=0;i<m;i++)
    //     cout <<c[i]<< '\n';
    cout <<c[m-1]<< '\n';
}

int main(){
    int stances,i;
    cin>>stances;
    for (int t = 0; t < stances ; t++){
        int n,m;
        cin>>n>>m;
        int tam[n];
        for(i=0;i<n;i++)
            cin>>tam[i];
        iceblocks(tam,n,m);
    }
    return 0;
}
