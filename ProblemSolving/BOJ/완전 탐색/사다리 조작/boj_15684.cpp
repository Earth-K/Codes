#include<iostream>
#include<vector>
using namespace std;
int map[31][11];

vector<int> arr;

int main(){
    int N,M,H;
    cin>>N>>M>>H;
    for(int i=0,a,b; i<M; i++){
        cin>>a>>b;
        map[a][b] = 1;
        map[a][b+1] = 1;
    }
    for(int i=1; i<=H; i++){
        for(int j=1; j<=N; j++){
            cout<<map[i][j];
        }
        cout<<endl;
    }
    
    for(int c=1; c<=N; c++){
        int nowC=c;
        int nowR=1;
        while(nowR<=H){
            if(map[nowR][nowC] == 1){
                if(map[nowR][nowC+1] == 1)
                    nowC += 1;
                else if(map[nowR][nowC-1] == 1)
                    nowC -= 1;
            }
            nowR += 1;
        }
        cout<<nowC<<endl;
    }
    return 0;
}