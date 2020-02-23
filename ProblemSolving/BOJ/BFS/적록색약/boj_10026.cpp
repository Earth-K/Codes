#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int N;
char map[100][101];
bool visited[100][100];
int dr[4]={0,0,-1,1};
int dc[4]={1,-1,0,0};
struct Color{
    int r, c;
};
void bfs(int r, int c, char color){
    queue<Color> Q;
    visited[r][c] = true;
    Q.push({r,c});

    while(!Q.empty()){
        Color now = Q.front();
        Q.pop();
        
        if(map[now.r][now.c] == 'R')
            map[now.r][now.c] = 'G';

        for(int i=0; i<4; i++){
            int nextR=now.r+dr[i];
            int nextC=now.c+dc[i];
            if(!(0<=nextR && nextR<N && 0<=nextC && nextC<N))
                continue;
            if(visited[nextR][nextC])
                continue;
            if(map[nextR][nextC] != color)
                continue;

            visited[nextR][nextC]= true;
            Q.push({nextR,nextC});
        }
    }
}
int getAreaNum(){
    int ret=0;
    for(int i=0; i<N; i++){
        for(int j=0 ;j<N ;j++){
            if(visited[i][j]) continue;
            bfs(i,j,map[i][j]);
            ret += 1;
        }
    }
    return ret;
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++)
        cin>>map[i];

    cout<<getAreaNum()<<' ';
    memset(visited,false,sizeof(visited));
    cout<<getAreaNum();
     return 0;
}