#include<iostream>
using namespace std;

int N, M, A[1000],score[1000];
int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++)
        cin>>A[i];
    for(int i=0,B; i<M; i++){
        cin>>B;
        int num=0;
        for(int j=0; j<N; j++){
            if(A[j] <= B){
                num = j;
                break;
            }
        }
        score[num] += 1;
    }
    int maxScore = 0;
    int answer = 0;
    for(int i=0; i<N; i++){
        if(maxScore < score[i]){
            maxScore = score[i];
            answer = i;
        }
    }
    cout<<answer+1;
    return 0;
}