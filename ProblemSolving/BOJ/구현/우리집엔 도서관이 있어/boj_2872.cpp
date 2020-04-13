#include<iostream>
#include<list>
using namespace std;
int N,arr[300001];
int main(){
    cin >> N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    int checkNum = N;
    int ans = 0;
    for(int i=N-1; i>=0; i--){
        if(arr[i] == checkNum){
            checkNum -= 1;
        }
        else
            ans += 1;
    }
    cout<<ans;
    return 0;
}