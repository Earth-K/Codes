#include<iostream>
#include<algorithm>
#define INF 987654321
using namespace std;
int N, M, adj[101][101];
int main(){
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j) adj[i][j] = 0;
            else adj[i][j] = INF;
        }
    }
    for(int i=0,u,v; i<M; i++){
        cin>>u>>v;
        adj[u][v] = 1;
    }
    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);
            }
        }
    }
    for(int i=1; i<=N; i++){
        int cnt = 0;
        for(int j=1; j<=N; j++){
            if(i==j) continue;
            if(adj[i][j] == INF && adj[j][i] == INF)
                cnt += 1;
        }
        cout<<cnt<<endl;
    }
    return 0;
}