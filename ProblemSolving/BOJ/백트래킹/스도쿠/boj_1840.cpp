#include<iostream>
using namespace std;
int input[82][3], map[10][10]={0,}, used[3][10][10]={0,};
int getAreaNum(int r, int c){
    return ((r-1)/3)*3 + (c-1)/3 + 1;
}
bool valid(int r, int c, int n){
    return !(used[0][getAreaNum(r,c)][n] || used[1][r][n] || used[2][c][n]);
}
bool fill(int r,int c){
    if(r==9&&c==10) return true;
    if(c==10) return fill(r+1,1);
    if(map[r][c]!=0) return fill(r,c+1);
    
    bool ret=false;
    for(int n=1; n<=9; n++){
        if(valid(r,c,n)){
            used[0][getAreaNum(r,c)][n] = used[1][r][n] = used[2][c][n] = 1; 
            ret=fill(r,c+1);
            used[0][getAreaNum(r,c)][n] = used[1][r][n] = used[2][c][n] = 0; 
            if(ret)break;
        }
    }
    return ret;
}
int main(){
    freopen("input.txt","r",stdin);
    for(int i=1; i<=81; i++){
        cin>>input[i][0]>>input[i][1]>>input[i][2];
    }
    int r,c,n,j=0;
    for(int i=1; i<=81; i++){
        r = input[i][0];
        c = input[i][1];
        n = input[i][2];
        if(!valid(r,c,n)){
            j = i;
            while(!fill(1,1)){
                --j;
                r=input[j][0];
                c=input[j][1];
                n=input[j][2];
                map[r][c] = 0;
                used[0][getAreaNum(r,c)][n] = used[1][r][n] = used[2][c][n] = 0;        
            }
            break;
        }
        map[r][c] = n;
        used[0][getAreaNum(r,c)][n] = used[1][r][n] = used[2][c][n] = 1;
    }
    cout<<(j==0?-1:j);
    return 0;
}