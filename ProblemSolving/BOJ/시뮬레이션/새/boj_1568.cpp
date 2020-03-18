#include<iostream>
using namespace std;
int N;
int main(){
    cin>>N;
    int k = 1;
    int answer = 0;
    while(N>0){
        if(N-k>=0){
            N -= k++;
            answer++;
        }
        else
            k=1;
    }
    cout<<answer<<endl;
     return 0;
}