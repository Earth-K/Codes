#include<iostream>
using namespace std;
int L, P;
int main(){
    cin>>L>>P;
    int realAns = L*P;
    for(int i=0,n; i<5; i++){
        cin>>n;
        cout<<n - realAns<<" ";
    }
    return 0;
}