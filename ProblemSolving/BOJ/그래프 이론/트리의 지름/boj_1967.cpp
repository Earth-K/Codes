#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<pair<int,int>> adj[10001];
bool visited[100001];

pair<int,int> dfs(int v, int w){
    visited[v] = true;
    vector<pair<int,int>> vt;
    for(int i=0; i<adj[v].size(); i++){
        int nextV = adj[v][i].first;
        int nextW = adj[v][i].second + w;
        if(!visited[nextV]) {
            vt.push_back(dfs(nextV,nextW));
        }
    }
    if(vt.empty())
        return {w,v};

    sort(vt.begin(), vt.end());
    return vt.back();
}
int solve(int v, int n){
    memset(visited,false,sizeof(visited));
    pair<int,int> p1 = dfs(v,0);
    memset(visited,false,sizeof(visited));
    pair<int,int> p2 = dfs(p1.second,0);
    return p2.first;
}
int main(){
    int n,answer;
    cin>>n;
    for(int i=0; i<n-1; i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    cout<<solve(1,n);
    
    return 0;
}