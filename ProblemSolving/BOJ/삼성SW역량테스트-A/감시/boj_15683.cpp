#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

struct Cctv{
    int r,c, type, dir;
};
int N, M, map[8][8], ans;
int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};
vector<Cctv> tvs;

void setCCTV(vector<Cctv>& tvs, int idx);
int getAns();
bool chkValid(int r, int c);
void initMap();
void fillWay(int nowR, int nowC, int dir);
void setVisible(const vector<Cctv>& tvs);

int main(){
    cin>>N>>M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin>>map[i][j];
            if(1<=map[i][j] && map[i][j]<=5){
                tvs.push_back({i,j,map[i][j]});
            }
        }
    }
    ans = 987654321;
    setCCTV(tvs, 0);
    cout<<ans;

    return 0;
}

void setCCTV(vector<Cctv>& tvs, int idx){
    if(idx == tvs.size()){
        setVisible(tvs);
        ans = min(ans, getAns());
        return;
    }

    for(int d=0; d<=3 ;d++){
        tvs[idx].dir = d;
        setCCTV(tvs, idx+1);
    }
}
int getAns(){
    int ret = 0;
    for(int i=0; i<N ;i++){
        for(int j=0; j<M ;j++){
            if(map[i][j] == 0)
                ret++;
        }
    }
    return ret;
}
void setVisible(const vector<Cctv>& tvs){
    initMap();
    for(Cctv tv : tvs){
        int nowR, nowC, nowDir;
        nowR = tv.r;
        nowC = tv.c;
        nowDir = tv.dir;
        if(tv.type == 1){
            fillWay(nowR,nowC,(nowDir+1)%4);
        }
        else if(tv.type == 2){
            fillWay(nowR,nowC,(nowDir+1)%4);
            fillWay(nowR,nowC,(nowDir+3)%4);
        }
        else if(tv.type == 3){
            fillWay(nowR,nowC,nowDir);
            fillWay(nowR,nowC,(nowDir+1)%4);
        }
        else if(tv.type == 4){
            fillWay(nowR,nowC,nowDir);
            fillWay(nowR,nowC,(nowDir+1)%4);
            fillWay(nowR,nowC,(nowDir+3)%4);
        }
        else if(tv.type == 5){
            fillWay(nowR,nowC,0);
            fillWay(nowR,nowC,1);
            fillWay(nowR,nowC,2);
            fillWay(nowR,nowC,3);
        }
    }
}
void initMap(){
  for(int i=0; i<N ;i++){
        for(int j=0 ;j<M ;j++){
            if(map[i][j] == -1)
                map[i][j] = 0;
        }
    }
}
void fillWay(int nowR, int nowC, int dir){
    int nextR = nowR+dr[dir];
    int nextC = nowC+dc[dir];
    while (chkValid(nextR, nextC)){
        if(!(1<=map[nextR][nextC]&&map[nextR][nextC]<=5))
            map[nextR][nextC] = -1;
        nextR += dr[dir];
        nextC += dc[dir];
    }
}
bool chkValid(int r, int c){
    return 0<=r && r<=7 && 0<=c && c<=7 && map[r][c] !=6;
}