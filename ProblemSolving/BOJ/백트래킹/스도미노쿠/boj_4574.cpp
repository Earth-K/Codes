#include<cstring>
#include<iostream>
using namespace std;

int map[9][9];
int dr[2] = {0,1};
int dc[2] = {1,0};
bool chkQuad[10][10], chkCol[10][10], chkRow[10][10], chkTile[10][10];
int N;

int quadNum(int r, int c){
    return 3*(r/3) + (c/3);
}

void setChkNum(int r, int c, int num, bool b){
    chkCol[c][num] = b;
    chkRow[r][num] = b;
    chkQuad[quadNum(r,c)][num] = b;
}

bool checkValid(int r, int c, int num){
    return !chkQuad[quadNum(r,c)][num] && !chkCol[c][num] && !chkRow[r][num];
}

bool printAnswer(int cnt){
    if(cnt == 81){
        for(int i=0; i<9 ;i++){
            for(int j=0; j<9; j++)
                cout<<map[i][j];
            cout<<endl;
        }
        return true;
    }

    int r1 = cnt/9;
    int c1 = cnt%9;
    
    if(map[r1][c1] != 0){
        return printAnswer(cnt+1);
    }
    else{
        for(int dir=0; dir<2; dir++){
            int r2 = r1+dr[dir];
            int c2 = c1+dc[dir];
            if(!(0<=r2&&r2<9 && 0<=c2&&c2<9)) continue;
            if(map[r2][c2] != 0) continue;

            for(int n1=1; n1<=9; n1++){
                for(int n2=1; n2<=9; n2++){
                    if(n1==n2) continue;
                    if(chkTile[n1][n2]) continue;

                    if(checkValid(r1,c1,n1) && checkValid(r2,c2,n2)){
                        setChkNum(r1,c1,n1,true);
                        setChkNum(r2,c2,n2,true);
                        chkTile[n1][n2] = chkTile[n2][n1] = true;
                        map[r1][c1] = n1;
                        map[r2][c2] = n2;

                        if(printAnswer(cnt+1))
                            return true;

                        setChkNum(r1,c1,n1,false);
                        setChkNum(r2,c2,n2,false);
                        chkTile[n1][n2] = chkTile[n2][n1] = false;
                        map[r1][c1] = 0;
                        map[r2][c2] = 0;
                    }
                }
            }
        }
    }

    return false;
}

int main(){
    int tc = 1;
    while(true){
        cin >> N;
        if (N == 0)
            break;
        int n1, n2, r1, c1, r2, c2;
        string s1, s2;
        memset(map,0,sizeof(map));
        memset(chkCol,0,sizeof(chkCol));
        memset(chkRow,0,sizeof(chkRow));
        memset(chkQuad,0,sizeof(chkQuad));
        memset(chkTile,0,sizeof(chkTile)); 

        for (int i = 0; i < N; i++)
        {
            cin >> n1 >> s1 >> n2 >> s2;
            r1 = s1[0] - 'A';
            c1 = s1[1] - '1';
            r2 = s2[0] - 'A';
            c2 = s2[1] - '1';
            setChkNum(r1, c1, n1, true);
            setChkNum(r2, c2, n2, true);
            chkTile[n1][n2] = chkTile[n2][n1] = true;
            map[r1][c1] = n1;
            map[r2][c2] = n2;
        }
        for (int num = 1; num <= 9; num++)
        {
            cin >> s1;
            r1 = s1[0] - 'A';
            c1 = s1[1] - '1';
            setChkNum(r1, c1, num, true);
            map[r1][c1] = num;
        }
        cout<<"Puzzle "<<tc++<<endl;
        printAnswer(0);
    }
    return 0;
}