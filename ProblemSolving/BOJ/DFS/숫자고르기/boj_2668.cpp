#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> ans, nextV;

void dfs(int startV, int curV, vector<bool>& visited){
    if(visited[curV]){
        if(curV == startV)
            ans.push_back(curV);
    }else{
        visited[curV] = true;
        dfs(startV, nextV[curV], visited);
    }
}
void solve(int n){
    vector<bool> visited(N+1,false);
    dfs(n,n,visited);
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);

    cin>>N;
    nextV = vector<int>(N+1,0);
    for(int i=1; i<=N; i++)
        cin>>nextV[i];
    
    for(int startV=1; startV<=N; startV++)
        solve(startV);
    
    cout<<ans.size()<<"\n";
    for(int v: ans)
        cout<<v<<"\n";
    return 0;
}