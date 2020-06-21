#include<iostream>
#include<vector>
#include<algorithm>
#define INF 987654321
using namespace std;
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    int N,K,S;
    cin>>N>>K;
    vector<vector<int>> adj(N+1, vector<int>(N+1, INF));

    for(int i=0,u,v; i<K; i++){
        cin>>u>>v;
        adj[u][v] = 1;
    }

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }

    cin>>S;
    for(int i=0,u,v; i<S; i++){
        cin>>u>>v;
        if(adj[u][v] != INF && adj[v][u] == INF){
            cout<<"-1\n";
        }
        else if(adj[u][v] == INF && adj[v][u] != INF){
            cout<<"1\n";
        }
        else{
            cout<<"0\n";
        }
    }
    return 0;
}