#include<iostream>
#include<queue>
#include<deque>
#include<cmath>
using namespace std;
struct Obj{
    int x, ax;
};
struct comp{
    bool operator()(const Obj& o1, const Obj& o2){
        if(o1.ax == o2.ax)
            return o1.x > o2.x;
        else 
            return o1.ax > o2.ax;
    }
};
priority_queue<Obj,deque<Obj>,comp> pq;

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    int n,num;
    cin>>n;
    while(n--){
        cin>>num;
        if(num == 0){
            if(pq.empty()){
                cout<<"0\n";
            }
            else{
                cout<<pq.top().x<<"\n";
                pq.pop();
            }
        }
        else{
            pq.push({num,abs(num)});
        }
    }
    return 0;
}