#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int H,W;
string map[100];
int answer[100][100];
void moveCloud(){
    for(int r=0; r<H; r++){
        for(int i=W-1; i>=1; i--){
            map[r][i] = map[r][i-1];
        }
    }
}
int main(){
    cin>>H>>W;
    for(int i=0; i<H; i++){
        cin>>map[i];
    }
    memset(answer,-1,sizeof(answer));
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            if(map[i][j] == 'c')
                answer[i][j] = 0;
        }
    }
    int cnt = 1;
    while(cnt < W){
        moveCloud();
         for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                if(map[i][j] == 'c' && answer[i][j] == -1)
                    answer[i][j] = cnt;
            }
        }
        cnt++;
    }
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++)
            cout<<answer[i][j]<<' ';
        cout<<endl;
    }
     return 0;
}