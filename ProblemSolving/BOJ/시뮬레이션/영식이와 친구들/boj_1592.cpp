#include<iostream>
using namespace std;
int N,M,L;
int receiveCnt[1001];

int getRightIdx(int idx){
    int cnt = L;
    while(cnt--){
        if(idx+1 == N+1)
            idx = 1;
        else
            idx += 1;
    }
    return idx;
}
int getLeftIdx(int idx){
    int cnt = L;
    while(cnt--){
        if(idx-1 == 0)
            idx = N;
        else
            idx -= 1;
    }
    return idx;
}

int main(){
    cin>>N>>M>>L;
    
    receiveCnt[1] = 1;
    int target = getRightIdx(1);
    int shootCnt = 1;

    while(true){
        receiveCnt[target] += 1;
        if(receiveCnt[target] == M){
            break;
        }

        if(receiveCnt[target]%2 == 1)
            target = getRightIdx(target);
        else
            target = getLeftIdx(target);
        shootCnt += 1;
    }
    cout<<shootCnt;
    return 0;
}