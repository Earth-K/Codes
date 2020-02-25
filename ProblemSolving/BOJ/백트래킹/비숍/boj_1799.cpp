#include<iostream>
using namespace std;

int N,map[10][10],answer[2];
bool leftChk[201][2],rightChk[201][2];

bool valid(int r, int c){
    return 0<=r&&r<N && 0<=c&&c<N;
}
bool check(int r, int c, int type){
    if(map[r][c] == 0 || leftChk[r-c+N][type] || rightChk[r+c][type])
        return false;
    return true;
}

void solve(int r, int c, int cnt, int type){
    if(c >= N){
        r += 1;
        if(type == 0)
            c = (r%2 == 0) ? 0 : 1;
        else
            c = (r%2 == 0) ? 1 : 0;
    }

    if(r==N){
        if(answer[type] < cnt)
            answer[type] = cnt;
        return;
    }

    if(check(r,c,type)){
        leftChk[r-c+N][type] = true;
        rightChk[r+c][type] = true;
        solve(r,c+2,cnt+1,type);
        leftChk[r-c+N][type] = false;
        rightChk[r+c][type] = false;
    }
    solve(r,c+2,cnt,type);
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>map[i][j];
            
    solve(0,0,0,0);
    solve(0,1,0,1);
    cout<<answer[0]+answer[1];
     return 0;
}