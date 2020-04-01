#include<iostream>
using namespace std;
int N,M, score[101], targets[101];
int main(){
    cin>>N>>M;
    for(int i=1,n; i<=M; i++){
        cin>>targets[i];
    }
    for(int i=1; i<=M; i++){
        for(int j=1,pick; j<=N; j++){
            cin>>pick;
            if(pick == targets[i]){
                score[j] += 1;
            }
            else{
                score[targets[i]] += 1;
            }
        }
    }
    for(int i=1; i<=N; i++){
        cout<<score[i]<<"\n";
    }
     return 0;
}