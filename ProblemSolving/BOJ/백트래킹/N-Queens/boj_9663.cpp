#include<iostream>
using namespace std;
int N;
int map[15][15];
bool usedCol[15];

int calcAnswer(int row);
bool check(int row, int col);

int main(){
    int answer=0;
    cin >> N;
    answer = calcAnswer(0);
    cout<<answer<<endl;
    return 0;
}

int calcAnswer(int row){
    int ret = 0;

    if(row == N)
        return 1;

    for(int col=0; col<N; col++){
        if(check(row,col)){
            map[row][col] = 1;
            usedCol[col] = true;
            ret += calcAnswer(row+1);
            map[row][col] = 0;
            usedCol[col] = false;
        }
    }

    return ret;
}
bool check(int row, int col){
    if(usedCol[col])
        return false;
    
    int r,c;
    r=row-1;
    c=col-1;
    while(0<=r && 0<=c){
        if(map[r][c] == 1)
            return false;
        r--;
        c--;
    }
    r=row-1;
    c=col+1;
    while(0<=r && c<N){
        if(map[r][c] == 1)
            return false;
        r--;
        c++;
    }

    return true;
}