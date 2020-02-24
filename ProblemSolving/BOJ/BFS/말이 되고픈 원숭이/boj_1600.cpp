#include<iostream>
#include<queue>
using namespace std;

int dr[12]={0,0,1,-1, -2,-1, -2,-1, 1,2, 1,2};
int dc[12]={-1,1,0,0, -1,-2, 1,2, 2,1, -2,-1};
int K,W,H,map[200][200];
int answer = -1;
bool visited[200][200][31];
struct Horse{
    int r,c,cnt;
};
void bfs(int r, int c){
    queue<Horse> Q;

    visited[r][c][0] = true;
    Q.push({r,c,0});

    int cntStep = 0;
    while(!Q.empty()){
        int sz = Q.size();
        while (sz--)
        {
            Horse now = Q.front();
            Q.pop();

            if (now.r == H - 1 && now.c == W - 1){
                answer = cntStep;
                return;
            }

            if (now.cnt < K){
                for(int i=4; i<12; i++){
                    int nextR = now.r + dr[i];
                    int nextC = now.c + dc[i];
                    if (!(0 <= nextR && nextR < H && 0 <= nextC && nextC < W))
                        continue;
                    if (map[nextR][nextC] == 1)
                        continue;
                    if (visited[nextR][nextC][now.cnt+1])
                        continue;
                    visited[nextR][nextC][now.cnt+1] = true;
                    Q.push({nextR, nextC, now.cnt+1});
                }
            }

            for (int i = 0; i < 4; i++){
                int nextR = now.r + dr[i];
                int nextC = now.c + dc[i];
                if (!(0 <= nextR && nextR < H && 0 <= nextC && nextC < W))
                    continue;
                if (map[nextR][nextC] == 1)
                    continue;
                if (visited[nextR][nextC][now.cnt])
                    continue;
                visited[nextR][nextC][now.cnt] = true;
                Q.push({nextR, nextC, now.cnt});
            }
        }
        cntStep += 1;
    }
}
int main(){
    
    cin>>K>>W>>H;
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            cin>>map[i][j];
        }
    }
    bfs(0,0);
    cout<<answer;
     return 0;
}