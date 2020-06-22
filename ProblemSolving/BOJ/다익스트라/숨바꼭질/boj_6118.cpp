#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Obj{
    int dist, n;
};
struct comp{
    bool operator() (const Obj& o1, const Obj& o2){
        return o1.dist > o2.dist;
    }
};

priority_queue<Obj, deque<Obj>, comp> pq;
vector<int> adj[20001];
bool visited[20001];
int dist[20001], max_dist;

void dij(int start){
    pq.push({0,start});

    while(!pq.empty()){
        Obj o = pq.top();
        pq.pop();
        if(visited[o.n]) continue;

        visited[o.n] = true;
        dist[o.n] = o.dist;

        if(max_dist < o.dist)
            max_dist = o.dist;

        for(int v: adj[o.n]){
            if(visited[v] == false){
                pq.push({o.dist+1, v});
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    int N,M;
    cin>>N>>M;
    for(int i=0,u,v; i<M; i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dij(1);
    vector<int> vt;
    for(int i=1; i<=N; i++){
        if(max_dist == dist[i]){
            vt.push_back(i);
        }
    }
    sort(vt.begin(), vt.end());
    cout<<vt[0]<<" "<<max_dist<<" "<<vt.size();
    return 0;
}