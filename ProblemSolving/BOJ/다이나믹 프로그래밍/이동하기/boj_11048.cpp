#include<iostream>
#include<algorithm>
using namespace std;

int map[1001][1001];

int main(){
    int N,M;
    cin>>N>>M;

    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            cin>>map[i][j];
        }
    }

    for(int i=1; i<=M; i++)
        map[1][i] += map[1][i-1];
    for(int i=1; i<=N; i++)
        map[i][1] += map[i-1][1];

    for(int i=2; i<=N; i++){
        for(int j=2; j<=M; j++){
            map[i][j] += max(map[i-1][j-1], max(map[i][j-1],map[i-1][j]));
        }
    }

    cout<<map[N][M];

    return 0;
}