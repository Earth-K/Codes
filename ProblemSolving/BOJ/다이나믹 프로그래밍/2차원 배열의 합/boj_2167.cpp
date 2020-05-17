#include<iostream>
using namespace std;
int arr[301][301],sum[301][301],N,M;

int getAns(int i, int j, int x, int y){
    int ret = 0;
    for(int k=i; k<=x; k++){
        ret += sum[k][y] - sum[k][j-1];
    }
    return ret;
}

int main(){
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        for(int j=1 ;j<=M; j++){
            cin>>arr[i][j];
        }
    }
    
    for(int i=1; i<=N; i++){
        int s=0;
        for(int j=1 ;j<=M; j++){
            s += arr[i][j];
            sum[i][j] = s;   
        }
    }

    int T,i,j,x,y;
    cin>>T;
    while(T--){
        cin>>i>>j>>x>>y;
        cout<<getAns(i,j,x,y)<<"\n";
    }
    return 0;
}