#include<cstdio>
using namespace std;

int dp[301][301],N,M,T;

int main(){
    scanf("%d%d",&N,&M);
    for(int i=1; i<=N; i++){
        for(int j=1,n; j<=M; j++){
            scanf("%d",&n);
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + n;
        }
    }
    scanf("%d",&T);
    while(T--){
        int i,j,x,y,ans;
        scanf("%d%d%d%d",&i,&j,&x,&y);
        ans = dp[x][y] - dp[i-1][y] - dp[x][j-1] + dp[i-1][j-1];
        printf("%d\n",ans);
    }
    return 0;
}