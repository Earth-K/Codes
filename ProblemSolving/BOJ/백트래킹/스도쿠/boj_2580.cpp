#include<iostream>
#include<vector>
using namespace std;

int map[9][9];
bool chkR[9][10], chkC[9][10], chkS[9][10], chkPos[81];

bool printAnswer(vector<pair<int,int>>& vt, int idx);

int main(){
    vector<pair<int,int>> vt;
    for(int r=0; r<9; r++){
        for(int c=0; c<9; c++){
            cin>>map[r][c];
            if(map[r][c] == 0){
                vt.push_back({r,c});
                continue;
            }
            chkR[r][map[r][c]] = true;
            chkC[c][map[r][c]] = true;
            chkS[(r/3)*3 + (c/3)][map[r][c]]= true;
        }
    }
    printAnswer(vt,0);

    return 0;
}
bool printAnswer(vector<pair<int,int>>& vt, int idx){
    if(idx == vt.size()){
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++)
                cout<<map[i][j]<<" ";
            cout<<endl;
        }
        return true;
    }

    int nowR = vt[idx].first;
    int nowC = vt[idx].second;
    
    for(int num=1; num<=9; num++){
        if(!chkR[nowR][num] && !chkC[nowC][num] && !chkS[(nowR/3)*3 + (nowC/3)][num]){
            chkPos[idx] = true;
            chkR[nowR][num] = true;
            chkC[nowC][num] = true;
            chkS[(nowR/3)*3 + (nowC/3)][num] = true;
            map[nowR][nowC] = num;

            if(printAnswer(vt, idx+1))
                return true;

            chkPos[idx] = false;
            chkR[nowR][num] = false;
            chkC[nowC][num] = false;
            chkS[(nowR/3)*3 + (nowC/3)][num] = false;
            map[nowR][nowC] = 0;
        }
    }
    return false;
}
