#include<iostream>
using namespace std;
int N;
int main(){
    cin>>N;
    int a = 10;
    while(N>a){
        if(N%a < a/2)
            N = N-N%a;
        else {
            N = N-N%a;
            N += a;
        }
        a *= 10;
    }
    cout<<N<<endl;
    return 0;
}