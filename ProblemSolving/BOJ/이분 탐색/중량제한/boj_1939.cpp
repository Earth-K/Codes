#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
int N,M,start,target;
struct Edge {
    int v, weight;
};
vector<Edge> adj[10001];
bool visited[10001];

bool bfs(int w){
    memset(visited,0,sizeof(visited));
    queue<int> Q;

    visited[start]=true;
    Q.push(start);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        
        if(u == target){
            return true;
        }

        for(Edge e : adj[u]){
            int v = e.v;
            if(e.weight >= w && visited[v] == false){
                visited[v] = true;
                Q.push(v);
            }
        }        
    }

    return false;
}

int main(){
    cin>>N>>M;
    for(int i=0,u,v,w; i<M; i++){
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cin>>start>>target;

    int left,right,mid,answer;
    answer = 0;
    left = 1;
    right = 1000000000;
    while(left <= right){
        mid = (left+right)>>1;
        if(bfs(mid)){
            left = mid+1;
            if(answer < mid)
                answer = mid;
        }
        else{
            right = mid-1;
        }
    }
    
    cout<<answer;
    return 0;
}