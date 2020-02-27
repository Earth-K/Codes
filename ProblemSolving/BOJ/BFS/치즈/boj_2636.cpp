#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

int N, M, map[100][100], cnt;
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};
struct Air{
    int r, c;
};

bool visited[100][100];
bool valid(int r, int c){
    if(!(0<=r && r<N && 0<=c && c<M) || visited[r][c])
        return false;
    return true;
}
vector<Air> bfs(int r, int c){
    memset(visited,0,sizeof(visited));
    vector<Air> vt;
    queue<Air> Q;

    Q.push({r,c});
    visited[r][c] = true;
    while(!Q.empty()){
        Air cur = Q.front();
        Q.pop();

        if(map[cur.r][cur.c] == 1){
            vt.push_back(cur);
            continue;
        }
        
        for(int i=0; i<4; i++){
            int nextR = cur.r+dr[i];
            int nextC = cur.c+dc[i];

            if(!valid(nextR,nextC))
                continue;
                
            Q.push({nextR,nextC});
            visited[nextR][nextC] = true;
        }
    }
    return vt;
}

int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
            if(map[i][j] == 1)
                cnt += 1;
        }
    }
    int day = 0;
    while(true){
        day += 1;
        vector<Air> vt = bfs(0,0);
        if(vt.size() == cnt)
            break;
        for(Air a : vt){
            map[a.r][a.c] = 0;
            cnt -= 1;
        }
    }
    cout<<day<<endl;
    cout<<cnt;
     return 0;
}