#include<iostream>
using namespace std;

char map[4*105][4*105];

void setStar(int r, int c, int k){
    if(k == 0){
        map[r][c] = '*';
        return;
    }
    else{
        int m = 1+4*k;
        for(int i=0; i<m; i++){
            map[r+i][c] = '*';
            map[r][c+i] = '*';
            map[r+m-1][c+m-1-i] = '*';
            map[r+m-1-i][c+m-1] = '*';
        }
        setStar(r+2, c+2, k-1);
    }
}
int main(){
    int N;
    cin>>N;
    for(int i=0; i<1+4*(N-1); i++){
        for(int j=0; j<1+4*(N-1); j++){
            map[i][j] = ' ';
        }
    }
    setStar(0,0,N-1);
    for(int i=0; i<1+4*(N-1); i++){
        for(int j=0; j<1+4*(N-1); j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
    return 0;
}