#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int dr[4]={0,0,1,-1};
int dc[4]={1,-1,0,0};
int R,C,ans;
char map[1000][1001];
bool visited[1000][1000];
bool endFlag,successFlag;
struct Pos{
    int r, c;
};
Pos start;
vector<Pos> fire, jihun;

void bfs(){
    queue<Pos> fireQ;
    for(Pos p: fire)
        fireQ.push(p);
    fire.clear();

    while(!fireQ.empty()){
        Pos now = fireQ.front();
        fireQ.pop();

        for(int i=0; i<4; i++){
            int nextR = now.r+dr[i];
            int nextC = now.c+dc[i];
            if(!(0<=nextR && nextR<R && 0<=nextC && nextC<C))continue;
            if(map[nextR][nextC] == 'F'|| map[nextR][nextC] == '#') continue;
            fire.push_back({nextR,nextC});
            map[nextR][nextC] = 'F';
        }
    }

    queue<Pos> jihunQ;
    for(Pos p: jihun)
        jihunQ.push(p);
    jihun.clear();

    while(!jihunQ.empty()){
        Pos now = jihunQ.front();
        jihunQ.pop();
        for(int i=0; i<4; i++){
            int nextR = now.r+dr[i];
            int nextC = now.c+dc[i];
            if(nextR>=R || nextC>=C || 0>nextR || 0>nextC){
                successFlag = true;
                return;
            }
            if(!(0<=nextR && nextR<R && 0<=nextC && nextC<C))continue;
            if(map[nextR][nextC] == 'J' || map[nextR][nextC] == 'F'|| map[nextR][nextC] == '#') continue;
            jihun.push_back({nextR,nextC});
            map[nextR][nextC] = 'J';
        }
    }
}
int main(){
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>map[i][j];
            if(map[i][j] == 'J')
                start={i,j};
            if(map[i][j] == 'F')
                fire.push_back({i,j});
        }
    }
    int time = 1;
    jihun.push_back(start);
    while(true){
        bfs();
        if(successFlag){
            cout<<time;
            break;
        }
        if(jihun.size() == 0){
            cout<<"IMPOSSIBLE";
            break;
        }
        time++;
    }
    return 0;
}