#include<iostream>
using namespace std;
string map[9];
bool checkR[9][10], checkC[9][10], checkA[9][10];
bool endFlag;

int getAreaNum(int r, int c){
    return 3*(r/3) + (c/3);
}
bool check(int r, int c, int num){
    if(checkA[getAreaNum(r,c)][num] || checkR[r][num] || checkC[c][num])
        return false;
    return true;
}

void solve(int r, int c){
    if(endFlag)
        return;
    if(c==9){
        r += 1;
        c = 0;
    }
    if(r==9){
        for(int i=0; i<9; i++)
            cout<<map[i]<<endl;
        endFlag = true;
        return;
    }
    if(map[r][c] != '0'){
        solve(r,c+1);
        return;
    }
    for(int num=1; num<=9; num++){
        if(check(r,c,num)){
            map[r][c] = '0'+num;
            checkR[r][num] = true;
            checkC[c][num] = true;
            checkA[getAreaNum(r,c)][num] = true;
            solve(r,c+1);
            map[r][c] = '0';
            checkR[r][num] = false;
            checkC[c][num] = false;
            checkA[getAreaNum(r,c)][num] = false;
        }
    }
}

int main(){
    for(int i=0; i<9; i++)
        cin>>map[i];
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            checkR[i][map[i][j]-'0'] = true;
            checkC[j][map[i][j]-'0'] = true;
            checkA[getAreaNum(i,j)][map[i][j]-'0'] = true;
        }
    }
    solve(0,0);
     return 0;
}