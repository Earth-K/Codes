#include<iostream>
using namespace std;
char map[1050*3][2*1050*3];
void setStar(int r, int c, int size){
    if(size == 3){
        map[r][c] = '*';
        map[r+1][c-1] = map[r+1][c+1] = '*';
        for(int i=c-2; i<c-2+5; i++)
            map[r+2][i] = '*';
        return;
    }
    int k = size/2;
    setStar(r,c,k);
    setStar(r+k,c-k,k);
    setStar(r+k,c+k,k);
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<2*N; j++){
            map[i][j] = ' ';
        }
        map[i][2*N] = '\0';
    }
    setStar(0,N-1,N);
    for(int i=0; i<N; i++){
        for(int j=0; j<2*N; j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }

    return 0;
}