#include<iostream>
#include<algorithm>
using namespace std;

int N, M;
char map[21][21];
int dr[4] = {-1,1,0,0};
int dc[4] = {0,0,-1,1};

int calcAnswer(int cnt, int r1, int c1, int r2, int c2);
bool checkBound(int r, int c);

int main(){
    int r1,c1, r2,c2;
    r1=c1=r2=c2= -1;
    cin>>N>>M;
    for(int r=0; r<N; r++){
        for(int c=0; c<M; c++){
            cin>>map[r][c];
            if(map[r][c] == 'o'){
                if(r1 == -1 && c1 == -1){
                    r1=r;
                    c1=c;
                }
                else{
                    r2=r;
                    c2=c;
                }
                map[r][c] = '.';
            }
        }
    }
    cout<<calcAnswer(0,r1,c1,r2,c2)<<endl;
    return 0;
}

int calcAnswer(int cnt, int r1, int c1, int r2, int c2){
    if(cnt == 11)
        return -1;
    
    bool dropFlag1, dropFlag2;
    dropFlag1 = dropFlag2 = false;
    if(checkBound(r1,c1) == false)
        dropFlag1 = true;
    if(checkBound(r2,c2) == false)
        dropFlag2 = true;

    if(dropFlag1 + dropFlag2 == 2)
        return -1;

    if(dropFlag1 + dropFlag2 == 1)
        return cnt;

    int answer = 987654321;
    for(int i=0; i<4; i++){
        int nextR1 = r1+dr[i];
        int nextC1 = c1+dc[i];
        int nextR2 = r2+dr[i];
        int nextC2 = c2+dc[i];
        if(map[nextR1][nextC1] == '#'){
            nextR1 = r1;
            nextC1 = c1;
        }
        if(map[nextR2][nextC2] == '#'){
            nextR2 = r2;
            nextC2 = c2;
        }
        int res = calcAnswer(cnt+1, nextR1,nextC1, nextR2,nextC2);
        if(res == -1)
            continue;
        else
            answer = min(answer,res);
    }

    return (answer==987654321) ? -1 : answer;
}

bool checkBound(int r, int c){
    return 0<=r && r<N && 0<=c && c<M;
}