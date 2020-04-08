#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
#define pii pair<int,int>
using namespace std;

bool visited[105];
int t,n,start_x,start_y, end_x, end_y;
vector<pii> vt;

bool dfs(int idx){
    pii now = vt[idx];
    if(now.first == end_x && now.second == end_y)
        return true;

    visited[idx] = true;
    for(int i=0; i<n+2; i++){
        pii next = vt[i];
        int dist = abs(now.first - next.first) + abs(now.second - next.second);
        if(visited[i] || 1000 < dist) 
            continue;

        if(dfs(i))
            return true;
    }

    return false;
}
int main(){
    cin>>t;
    while(t--){
        vt.clear();
        memset(visited,0,sizeof(visited));
        cin>>n;
        cin>>start_x>>start_y;
        vt.push_back({start_x,start_y});
        for(int i=0,x,y; i<n; i++){
            cin>>x>>y;
            vt.push_back({x,y});
        }
        cin>>end_x>>end_y;
        vt.push_back({end_x,end_y});
        if(dfs(0))
            cout<<"happy"<<endl;
        else
            cout<<"sad"<<endl;        
    }
    return 0;
}