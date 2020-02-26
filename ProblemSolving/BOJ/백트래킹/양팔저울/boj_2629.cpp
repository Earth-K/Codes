#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int N,M;
int weights[30], balls[7];
int possibleWeight[31][30*500+1];

void solve(int idx, int sumWeight){
    if(idx == N+1)
        return;
    if(possibleWeight[idx][sumWeight] != -1)
        return;

    possibleWeight[idx][sumWeight] = 1;
    solve(idx+1, sumWeight);
    solve(idx+1, sumWeight+weights[idx]);
    solve(idx+1, abs(sumWeight-weights[idx]));
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>weights[i];
    cin>>M;
    for(int j=0; j<M; j++)
        cin>>balls[j];

    memset(possibleWeight, -1, sizeof(possibleWeight));
    solve(0,0);
    for(int j=0; j<M; j++){
        if(balls[j] > 500*N)
            cout<<"N ";
        else if(possibleWeight[N][balls[j]]==1)
            cout<<"Y ";
        else
            cout<<"N ";
    }
     return 0;
}