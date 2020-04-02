#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int N, A[100001],B[100001],C[100001], answer = 987654321;

int main(){
    scanf("%d",&N);
    for(int i=0; i<N; i++){
        scanf("%1d",A+i);
        B[i] = A[i];
    }
    for(int i=0 ;i<N; i++)
        scanf("%1d",C+i);
    
    int res = 0;
    for(int i=0; i<N-1; i++){
        if(A[i] == C[i])
            continue;
        for(int j=0; j<3; j++)
            A[i+j] = !A[i+j];
        res += 1;
    }
    if(C[N-1] == A[N-1])
        answer = min(answer, res);
    
    res = 1;
    B[0] = !B[0];
    B[1] = !B[1];
    for(int i=0; i<N-1; i++){
        if(B[i] == C[i])
            continue;
        for(int j=0; j<3; j++)
            B[i+j] = !B[i+j];
        res += 1;
    }
    if(C[N-1] == B[N-1])
        answer = min(answer, res);
    
    if(answer == 987654321) cout<<"-1";
    else    cout<<answer;
    
    return 0;
}