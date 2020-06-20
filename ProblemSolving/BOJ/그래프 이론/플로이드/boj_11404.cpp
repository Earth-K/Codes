#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321
using namespace std;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    int N,M;
    cin>>N>>M;
    vector<vector<int>> adj(N+1,vector<int>(N+1,INF));

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i==j)
                adj[i][j] = 0;
        }
    }

    for(int i=0,u,v,w; i<M; i++){
        cin>>u>>v>>w;
        if(adj[u][v] > w){
            adj[u][v] = w;
        }
    }

    for(int k=1; k<=N; k++){
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(adj[i][j] == INF)
                cout<<"0 ";
            else
                cout<<adj[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}