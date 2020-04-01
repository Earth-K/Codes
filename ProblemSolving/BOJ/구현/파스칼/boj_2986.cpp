#include<iostream>
using namespace std;
int N, K=1;
int main(){
    cin>>N;
    for(int i=2; i*i<=N; i++){
        if(N % i == 0) {
            K = N/i;
            break;
        }
    }
    cout<<N-K;
    return 0;
}