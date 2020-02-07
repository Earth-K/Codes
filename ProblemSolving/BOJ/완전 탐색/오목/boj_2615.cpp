#include<iostream>
#include<vector>
using namespace std;

int answer,R,C;
int dr[4]={0,1,1,1};
int dc[4]={1,-1,0,1};
int map[21][21];
bool visited[21][21][4];

bool findWinner(int r, int c, int cnt, int dir,int color){

    if(map[r][c] != color){
        if(cnt == 5){
            return true;
        }
        return false;
    }
    visited[r][c][dir] = true;
    return findWinner(r+dr[dir], c+dc[dir],cnt+1,dir,color);
}

int main(){
    //freopen("input.txt","r",stdin);
    for(int i=1; i<=19; i++){
        for(int j=1; j<=19; j++){
            cin>>map[i][j];
        }
    }
    answer = -1;
    bool flag = true;
    for(int i=1; i<=19; i++){
        for(int j=1; j<=19; j++){
            if(map[i][j] == 0) continue;

            for(int dir=0; dir<4; dir++){
                if(visited[i][j][dir]) continue;
                if(findWinner(i,j,0,dir,map[i][j]) == true){
                    answer = map[i][j];
                    R=i;
                    C=j;

                    if(dir == 1){
                        R=i+4;
                        C=j-4;
                    }

                    flag = false;
                    break;      
                }
            }
        }
        if(!flag) break;
    }

    if(answer == -1)
        cout<<"0";
    else{
        cout<<answer<<endl;
        cout<<R<<" "<<C;
    }
    return 0;
}