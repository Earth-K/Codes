#include<iostream>
#include<algorithm>
using namespace std;

char map[50][50];
bool visited[50][50];
int dr[4]={0,-1,0,1};
int dc[4]={-1,0,1,0};
int N, answer;

int getCnt(int r, int c, char color, int dir){
    if(!(0<=r && r<N && 0<=c && c<N)){
        return 0;
    }
    if(map[r][c] != color){
        return 0;
    }

    visited[r][c] = true;
    int ret = 0;
    int nextR = r+dr[dir];
    int nextC = c+dc[dir];
    if(visited[nextR][nextC] == false){
        ret = 1 + getCnt(nextR,nextC,color,dir);
    }
    visited[r][c] = false;
    return ret;
}
void updateAnswer(int r,int c){
        int cntUD = getCnt(r,c,map[r][c],1)+getCnt(r,c,map[r][c],3) - 1;
        int cntLR = getCnt(r,c,map[r][c],0)+getCnt(r,c,map[r][c],2) - 1;
        int maxCnt = max(cntUD,cntLR);
        if(answer<maxCnt)
            answer = maxCnt;
}
void solve(){
    int r=0, c=0;
    for(int i=0; i<N ;i++){
        for(int j=0; j<N ;j++){
            updateAnswer(i,j);
        }
    }
    while(r!=N){
        if(c==N){
            r += 1;
            c = 0;
            continue;
        }
        for(int i=0; i<4; i++){
            int nextR = r+dr[i];
            int nextC = c+dc[i];
            if(0<=nextR && nextR<N && 0<=nextC && nextC<N){
                if(map[r][c] == map[nextR][nextC]) continue;

                swap(map[r][c],map[nextR][nextC]);
                updateAnswer(r,c);
                updateAnswer(nextR,nextC);
                swap(map[r][c],map[nextR][nextC]);
            }
        }
        c += 1;
    }
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>map[i][j];
    solve();
    cout<<answer;
     return 0;
}