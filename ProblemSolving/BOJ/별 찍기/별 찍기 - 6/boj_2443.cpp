#include<iostream>
using namespace std;
int main(){
    int N, cnt;
    cin >> N;
    cnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++)
            cout<<" ";
        for(int j=0; j<2*N-1-cnt; j++)
            cout<<"*";
        cout<<"\n";
        cnt += 2;
    }
    return 0;
}