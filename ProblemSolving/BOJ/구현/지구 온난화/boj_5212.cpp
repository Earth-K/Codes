#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int R, C;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
string map[10];
bool del_Island[10][10];
bool isDel(int r, int c){
    int cnt = 0;
    for(int i=0; i<4; i++){
        int nextR = r+dr[i];
        int nextC = c+dc[i];
        if(nextR<0 || R<=nextR || nextC<0 || C<=nextC)
            cnt += 1;
        else if(map[nextR][nextC] == '.')
            cnt += 1;
    }
    return (cnt >= 3) ? true:false;
}
int main(){
    cin>>R>>C;
    for(int i=0; i<R; i++)
        cin>>map[i];
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j] == 'X'){
                if(isDel(i,j)){
                    del_Island[i][j] = true;
                }
            }
        }
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(del_Island[i][j] == true)
                map[i][j] = '.';
        }
    }
    int minR,minC,maxR,maxC;
    minR = minC = 987654321;
    maxR = maxC = 0;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j] == 'X'){
                minR = min(minR,i);
                minC = min(minC,j);
                maxR = max(maxR,i);
                maxC = max(maxC,j);
            }
        }
    }
    
    for(int i=minR; i<=maxR; i++){
        for(int j=minC; j<=maxC; j++)
            cout<<map[i][j];
        cout<<"\n";
    }
    return 0;
}