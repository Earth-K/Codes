#include<iostream>
#include<string>
using namespace std;

int R, C;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
string map[10];

int getWallNumber(int r, int c){
    int wallCnt = 0;
    for(int i=0; i<4; i++){
        int nextR = r+dr[i];
        int nextC = c+dc[i];
        if(nextR<0 || R<=nextR || nextC<0 || C<=nextC)
            wallCnt += 1;
        else if(map[nextR][nextC] == 'X')
            wallCnt += 1;
    }
    return wallCnt;
}

int main(){
    cin>>R>>C;
    for(int i=0; i<R; i++){
        cin>>map[i];
    }
    bool flag = false;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j] == '.'){
                int wallNum = getWallNumber(i,j);
                if(wallNum >= 3){
                    flag = true;
                    break;
                }
            }
        }
        if(flag)
            break;
    }

    if(flag) cout<<"1";
    else cout<<"0";
    
     return 0;
}