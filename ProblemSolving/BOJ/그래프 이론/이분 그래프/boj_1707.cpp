#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int K,V,E;
vector<int> adj[20001];
int color[20001];
void dfs(int n, int c){
    if(color[n] != 0) 
        return;

    color[n] = c;
    for(int v: adj[n]){
        if(c == 1)
            dfs(v,2);
        else
            dfs(v,1);
    }
}
bool isBinaryG(){
    for(int n=1; n<=V; n++){
        for(int v: adj[n]){
            if(color[n] == color[v])
                return false;
        }
    }
    return true;
}
int main(){
    cin>>K;
    while(K--){
        memset(color,0,sizeof(color));
        for(int i=1; i<=20000; i++)
            adj[i].clear();

        cin>>V>>E;
        for(int i=0,u,v; i<E; i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int n=1; n<=V; n++){
            if(color[n] == 0)
                dfs(n,1);
        }
        if(isBinaryG())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}