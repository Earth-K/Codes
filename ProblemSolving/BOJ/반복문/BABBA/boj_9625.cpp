#include<iostream>
using namespace std;

int main(){
    int K, cntA, cntB;
    cntA = 1;
    cntB = 0;
    cin>>K;    
    while(K--){
        int nextA,nextB;
        nextA = cntB;
        nextB = cntA+cntB;

        cntA = nextA;
        cntB = nextB;
    }
    cout<<cntA<<" "<<cntB;

    return 0;
}