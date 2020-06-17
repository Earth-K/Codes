#include<iostream>
using namespace std;
int main(){
    int N;
    cin>>N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=(N+1)/2 ;j++){
            cout<<"* ";
        }
        cout<<"\n";
        for(int j=1; j<=N/2 ;j++){
            cout<<" *";
        }
        cout<<"\n";
    }
    return 0;
}