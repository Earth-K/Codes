#include<iostream>
using namespace std;
int N;
char map[2188][2188];

void setStar(int r, int c, int size){
    if(size == 1){
        map[r][c] = '*';
        return;
    }

    int m = size/3;
    int cnt = 0;
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cnt++;
            if(cnt != 5)
                setStar(r+i*m, c+j*m, m);
        }
    }
}
int main(){
    scanf("%d",&N);
    for(int i=0; i<2188; i++)
        for(int j=0; j<2188; j++)
            map[i][j] = ' ';
    setStar(0,0,N);

    for(int i=0; i<N; i++){
        for(int j=0; j<N ;j++)
            printf("%c", map[i][j]);
        printf("\n");
    }
    return 0;
}