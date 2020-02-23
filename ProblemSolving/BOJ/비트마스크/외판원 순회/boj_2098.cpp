#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 987654321
using namespace std;
int N,W[16][16],start;
int dp[16][1<<16];

int TSP(int cur, int visited){
    if(visited == (1<<N)-1){
        if(W[cur][start] == 0) 
            return INF;
        else 
            return W[cur][start];
    }
    
    int &ret = dp[cur][visited];
    if(ret != -1) return ret;

    ret = INF;
    for(int i=0; i<N; i++){
        if(visited & (1<<i)) continue;
        if(W[cur][i] == 0) continue;
        ret = min(ret, W[cur][i] + TSP(i, visited|(1<<i)));
    }
    return ret;
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>W[i][j];
    memset(dp,-1,sizeof(dp));
    cout<<TSP(0,1);
     return 0;
}