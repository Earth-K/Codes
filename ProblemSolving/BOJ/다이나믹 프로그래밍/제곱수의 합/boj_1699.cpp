#include<iostream>
#include<algorithm>
using namespace std;
int dp[100001];
int main(){
    int N;
    cin>>N;
    for(int i=1; i<=N; i++){
        dp[i] = i;
        for(int j=2; j*j<=i; j++){
            dp[i] = min(dp[i], dp[i-j*j]+1);
        }
    }
    cout<<dp[N];
    return 0;
}