#include<iostream>
using namespace std;
int N, cnt[10001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin>>N;
    for(int i=0,n; i<N; i++){
        cin>>n; 
        cnt[n] += 1; 
    }
    for(int i=0;i<=10000; i++){
        if(cnt[i] != 0){
            for(int j=0; j<cnt[i]; j++)
                cout<<i<<"\n";
        }
    }
    return 0;
}