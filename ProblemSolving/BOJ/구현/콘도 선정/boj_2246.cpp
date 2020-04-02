#include<iostream>
using namespace std;

int N,D[10000],C[10000],answer;

int main(){
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>D[i]>>C[i];

    for(int i=0; i<N; i++){
        bool flag = false;
        for(int j=0; j<N; j++){
            if(i==j) continue;
            if(D[i] > D[j] && C[i] >= C[j]){
                flag = true;
                break;
            }
            if(C[i] > C[j] && D[i] >= D[j]){
                flag = true;
                break;
            }
        }
        if(!flag)
            answer += 1;
    }
    cout<<answer;
    return 0;
}
