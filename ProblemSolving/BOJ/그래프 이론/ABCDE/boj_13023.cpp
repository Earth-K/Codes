#include<iostream>
#include<vector>
using namespace std;

int N, M;
vector<int> adj[2000];
bool visited[2000];

bool findABCDE(int v, int cnt){
    if(visited[v] == true){
        return false;
    }
    if(cnt == 4){
        return true;
    }

    visited[v] = true;
    for(int i=0; i<adj[v].size(); i++){
        if(findABCDE(adj[v][i],cnt+1))
            return true;
    }
    visited[v] = false;

    return false;
}

int main(){
    cin>>N>>M;
    for(int i=0,u,v; i<M; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int answer = 0;
    for(int i=0; i<N; i++){
        if(findABCDE(i,0)){
            answer = 1;
            break;
        }
    }
    cout<<answer;
     return 0;
}