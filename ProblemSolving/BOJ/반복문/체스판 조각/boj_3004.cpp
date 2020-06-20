#include<iostream>
using namespace std;
int main(){
    int N,answer;
    cin>>N;
    answer = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(i+j == N){
                if(answer < (i+1)*(j+1)){
                    answer = (i+1)*(j+1);
                }
            }
        }
    }
    cout<<answer;
    return 0;
}