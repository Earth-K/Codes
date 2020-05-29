#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    int N;
    cin>>N;
    for(int i=N; i>=1; i--)
        dq.push_back(i);

    while(dq.size() != 1){
        cout<<dq.back()<<" ";
        dq.pop_back();
        
        dq.push_front(dq.back());
        dq.pop_back();
    }
    cout<<dq.front();
    return 0;
}