#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Pos{
    int k,r,c;
};

int C,R,H;
int map[100][100][100];
bool visited[100][100][100];
vector<Pos> vt;
queue<Pos> Q;
int dk[6] = {0,0,0,0,-1,1};
int dr[6] = {-1,1,0,0,0,0};
int dc[6] = {0,0,-1,1,0,0};

bool valid(int k, int r, int c){
    return 0<=k && k<H && 0<=r && r<R && 0<=c && c<C;
}

int bfs(){
    for(Pos tomato: vt){
        visited[tomato.k][tomato.r][tomato.c] = true;
        Q.push(tomato);
    }
    int day=0;
    while(!Q.empty()){
        int sz = Q.size();
        while (sz--){
            Pos now = Q.front();
            Q.pop();

            map[now.k][now.r][now.c] = 1;

            for (int i = 0; i < 6; i++){
                int nextK = now.k + dk[i];
                int nextR = now.r + dr[i];
                int nextC = now.c + dc[i];
                if (!valid(nextK, nextR, nextC))
                    continue;
                if (map[nextK][nextR][nextC] == -1)
                    continue;
                if (visited[nextK][nextR][nextC] == true)
                    continue;

                visited[nextK][nextR][nextC] = true;
                Q.push({nextK, nextR, nextC});
            }
        }
        if(!Q.empty())
            day+=1;
    }
    return day;
}

int main(){
    cin>>C>>R>>H;
    
    for(int k=0; k<H ;k++){
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                cin>>map[k][i][j];
                if(map[k][i][j] == 1)
                    vt.push_back({k,i,j});
            }
        }
    }

    int day = bfs();

    bool flag = true;
    for(int k=0; k<H ;k++){
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(map[k][i][j] == 0)
                    flag = false;
            }
        }
    }
    if(flag)
        cout<<day;
    else
        cout<<"-1";
    
    return 0;
}