#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Info{
    int r, c, dist;
};

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
int N, M;

int getMaxDist(int r, int c, vector<string>& map){
    vector<vector<bool>> visited(N,vector<bool>(M,false));
    queue<Info> Q;

    visited[r][c] = true;
    Q.push({r,c,0});
    
    int maxDist = 0;
    while(!Q.empty()){
        int nowR = Q.front().r;
        int nowC = Q.front().c;
        int nowDist = Q.front().dist;
        Q.pop();

        if(maxDist < nowDist){
            maxDist = nowDist;
        }

        for(int i=0; i<4; i++){
            int nextR = nowR + dr[i];
            int nextC = nowC + dc[i];
            if(!(0<=nextR&&nextR<N && 0<=nextC&&nextC<M)) continue;
            if(visited[nextR][nextC]) continue;
            if(map[nextR][nextC] == 'W') continue;

            visited[nextR][nextC] = true;
            Q.push({nextR,nextC,nowDist+1});
        }
    }    
    return maxDist;
}
int solve(vector<string> map){
    int answer = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(map[i][j] == 'W') continue;
            answer = max(answer,getMaxDist(i,j,map));
        }
    }
    return answer;
}
int main(){
    cin>>N>>M;
    vector<string> map;
    for(int i=0; i<N; i++){
        string str;
        cin>>str;
        map.push_back(str);
    }
    cout<<solve(map);
    return 0;
}




