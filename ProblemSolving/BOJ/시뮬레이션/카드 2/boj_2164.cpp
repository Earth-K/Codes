#include<iostream>
#include<deque>
using namespace std;
int N;
deque<int> dq;
int main(){
    cin>>N;
    for(int i=1; i<=N; i++)
        dq.push_back(i);
    
    while(dq.size()!=1){
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }
    cout<<dq.at(0);
     return 0;
}