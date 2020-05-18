#include<iostream>
#define MOD 15746
using namespace std;
long long dp[1000001]={0,1,2};
int calc(int n){
    if(n==1) return 1;
    else if(n==2) return 2;
    
    if(dp[n] != 0) return dp[n];

    return dp[n] = (calc(n-1) + calc(n-2)) % MOD;
}
int main(){
    int N;
    cin>>N;
    cout<<calc(N);
    return 0;
}