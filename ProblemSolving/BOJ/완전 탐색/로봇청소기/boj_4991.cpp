#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

struct Point{
    int r, c;
};

int w, h, answer;
const int dr[4] = {0,0,1,-1};
const int dc[4] = {1,-1,0,0};
char map[20][21];
bool visitedMap[20][20], visitedV[10];
int dist[10][10];
Point posRobot;
vector<Point> posDirty;
vector<int> firstDist;


int dfs(int v, int sum, int cnt){
    
    if(sum > answer)
        return sum;
    if(posDirty.size() == cnt)
        return sum;     
    
    int ret = 987654321;
    
    visitedV[v] = true;
    for(int t=0; t<posDirty.size(); t++){
        if(visitedV[t]) continue;
        ret = min(ret, dfs(t, sum+dist[v][t], cnt+1));
    }
    visitedV[v] = false;

    return ret;
}

//bfs 탐색
int getDist(Point start, Point target){
    memset(visitedMap,false,sizeof(visitedMap));
    queue<Point> Q;

    visitedMap[start.r][start.c] = true;
    Q.push(start);

    int dist = 0;
    while(!Q.empty()){
        int sz = Q.size();

        for(int i=0 ; i<sz; i++){
            int nowR = Q.front().r;
            int nowC = Q.front().c;
            Q.pop();

            if(nowR==target.r && nowC==target.c){
                return dist;
            }

            for(int dir=0; dir<4; dir++){
                int nextR = nowR+dr[dir];
                int nextC = nowC+dc[dir];
                if(nextR<0 || h<=nextR || nextC<0 || w<=nextC)  continue;
                if(map[nextR][nextC] == 'x') continue;
                if(visitedMap[nextR][nextC])   continue;

                visitedMap[nextR][nextC] = true;
                Q.push({nextR,nextC});
            }
        }

        dist++;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    while (true)
    {
        cin >> w >> h;
        if(w==0 && h==0)
            break;
            
        firstDist.clear();
        posDirty.clear();
        answer = 987654321;

        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                cin >> map[i][j];
                if (map[i][j] == 'o')
                    posRobot = {i, j};
                if (map[i][j] == '*')
                    posDirty.push_back({i, j});
            }
        }

        bool notFound = false;
        for (int i = 0; i < posDirty.size(); i++){
            Point s(posRobot), t(posDirty[i]);
            int d = getDist(s, t);
            if(d != -1){
                firstDist.push_back(d);
            }else{
                notFound = true;
                break;
            }
        }

        if (notFound){
            cout<<"-1"<<endl;
        } else{
            int numPosDirty = posDirty.size();

            for(int i=0; i<numPosDirty; i++){
                for(int j=i; j<numPosDirty; j++){
                    if(i==j) continue;
                    Point s = posDirty[i];
                    Point t = posDirty[j];
                    int d = getDist(s,t);
                    dist[i][j] = dist[j][i] = d;
                }
            }

            for(int i=0 ; i<firstDist.size(); i++){
                int res = dfs(i,firstDist[i],1);
                answer = min(answer, res);
            }
            cout<<answer<<endl;
        }
    }
    return 0;
}