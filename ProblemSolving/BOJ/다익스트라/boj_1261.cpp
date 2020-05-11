#include<iostream>
#include<queue>
#include<string>
using namespace std;

int N,M,answer;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
struct Node{
  int r,c,broken;  
};
string map[101];
bool visited[101][101];

struct comp{
    bool operator()(const Node& n1, const Node& n2){
        return n1.broken > n2.broken;
    }
};
bool chkBound(int r, int c){
    return 0<=r && r<N && 0<=c && c<M;
}

void solve(){
    priority_queue<Node,deque<Node>,comp> pq;
    visited[0][0] = true;
    pq.push({0,0,0});
    
    while(!pq.empty()){
        Node n = pq.top();
        pq.pop();
        if(n.r == N-1 && n.c == M-1){
            cout<<n.broken;
            return;
        }
        for(int i=0; i<4; i++){
            int nextR = n.r+dr[i];
            int nextC = n.c+dc[i];
            int nextBroken = n.broken;
            if(chkBound(nextR,nextC) && visited[nextR][nextC] == false){
                if(map[nextR][nextC] == '1')
                    nextBroken += 1;
                
                visited[nextR][nextC] = true;
                pq.push({nextR,nextC,nextBroken}); 
            }
        }
    }
}

int main(){
    cin>>M>>N;
    for(int i=0; i<N; i++)
        cin>>map[i];
    solve();
    return 0;
}