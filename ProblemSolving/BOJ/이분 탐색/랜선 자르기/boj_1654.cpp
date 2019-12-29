#include<iostream>
#include<algorithm>
using namespace std;

int K, N, lan[10000];

bool check(long long length){
    long long numLan = 0;
    for(int i=0; i<K; i++)
        numLan += lan[i]/length;
    return numLan < N;
}

int main(){
    cin >> K >> N;
    long long left, right;
    left = 1;
    right= 0;
    for(int i=0; i<K; i++){
        cin>>lan[i];
        if(right < lan[i])
            right = lan[i];
    }

    long long ans = 0;
    while(left<=right){
        long long mid = (left+right)/2;
        if(check(mid)){
            right = mid-1;
        }
        else{
            ans = mid;
            left = mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}