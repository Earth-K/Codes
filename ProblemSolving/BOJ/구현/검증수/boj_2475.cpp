#include<iostream>
using namespace std;

int main(){
    int answer = 0;
    for(int i=0,n; i<5; i++){
        cin>>n;
        answer += (n*n)%10;
    }
    cout<<answer%10;
    return 0;
}