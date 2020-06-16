#include<iostream>
#include<string>
using namespace std;
int N;
char map[101][2*101];
void setStar(int r, int c, int k){
    if(k==N){
        return;
    }
    else{
        map[r+k][c+k] = '*';
        map[r+k][c-k] = '*';
        setStar(r,c,k+1);
    }
}
int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        for(int j=0; j<2*N-1; j++){
            map[i][j] = ' ';
        }
    }
    setStar(0,N-1,0);

    for(int i=0; i<N; i++){
        for(int j=0; j<N+i; j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
    return 0;
}