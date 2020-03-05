#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int R,C,x,y;
char map[100][101];
void flipLR(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            map[i][C*2-1-j] = map[i][j];
        }
    }
}
void flipUD(){
    for(int i=0; i<R; i++){
        for(int j=0; j<2*C; j++){
            map[R*2-1-i][j] = map[i][j];
        }
    }
}
int main(){
    cin>>R>>C;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>map[i][j];
        }
    }
    flipLR();
    flipUD();

    cin>>x>>y;
    x -= 1;
    y -= 1;
    if(map[x][y] == '.') 
        map[x][y] = '#';
    else 
        map[x][y] = '.';

    for(int i=0; i<2*R; i++){
        for(int j=0; j<2*C; j++){
            cout<<map[i][j];
        }
        cout<<'\n';
    }
     return 0;
}