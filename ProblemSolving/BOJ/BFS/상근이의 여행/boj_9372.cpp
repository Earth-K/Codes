#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,M,T,visitedNum;

vector<int> adj[1001];
int bfs(){
    int ret = 0;
    bool visited[1001] = {false,};
    queue<int> Q;
    visited[1] = true;
    Q.push(1);
    
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();

        for(int next : adj[now]){
            if(visited[next]) continue;
            visited[next] = true; 
            ret += 1;
            Q.push(next);
        }
    }
    return ret;
}
int main(){
    cin>>T;
    while(T--){
        cin>>N>>M;
        for(int i=1; i<=N; i++)
            adj[i].clear();

        for(int i=0,u,v; i<M; i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        cout<<bfs()<<endl;
    }

    return 0;
}
