#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int N,M,maxCnt;
vector<int> adj[10001];
bool visited[10001];
int cnt[10001];

void dfs(int n, int cnt, int& maxCnt){
    visited[n] = true;
    maxCnt += 1;
    for(int i=0; i<adj[n].size(); i++){
        if(visited[adj[n][i]]==false)
            dfs(adj[n][i],cnt+1, maxCnt);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>N>>M;
    for(int i=0,a,b; i<M; i++){
        cin>>a>>b;
        adj[b].push_back(a);
    }
    int totalMaxCnt = 0;
    for(int i=1; i<=N; i++){
        int maxCnt = 0;
        memset(visited,0,sizeof(visited));
        dfs(i,0,maxCnt);
        cnt[i] = maxCnt;
        totalMaxCnt = max(totalMaxCnt, maxCnt);
    }
    for(int i=1; i<=N; i++){
        if(totalMaxCnt == cnt[i])
            cout<<i<<" ";
    }    

    return 0;
}