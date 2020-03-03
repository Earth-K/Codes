#include<iostream>
#include<deque>
#include<cmath>
using namespace std;
deque<int> dq;
int N,M;
int cntLeft(int target){
    int cnt = 0;
    for(int i=0 ;i<dq.size(); i++){
        if(dq[i]==target)
            return cnt;
        cnt += 1;
    }
    return -1;
}
int cntRight(int target){
    int cnt = 0;
    for(int i=dq.size()-1 ; i>=0 ; i--){
        if(dq[i]==target)
            return cnt;
        cnt += 1;
    }
    return -1;
}
void leftRotate(){
    dq.push_back(dq.front());
    dq.pop_front();
}
void rightRotate(){
    dq.push_front(dq.back());
    dq.pop_back();
}
int main(){
    cin>>N>>M;
    for(int i=1; i<=N; i++)
        dq.push_back(i);
    int cnt = 0;
    for(int i=0,n; i<M; i++){
        cin>>n;
        while(true){
            int front = dq.front();
            int back = dq.back();
            if(front == n){
                dq.pop_front();
                break;
            }
            else if(cntLeft(n)<=cntRight(n)){
                leftRotate();
                cnt+=1;
            }
            else{
                rightRotate();
                cnt+=1;
            }
        }
    }
    cout<<cnt;
     return 0;
}