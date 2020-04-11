#include<iostream>
using namespace std;
int cups[4];
int getIdx(int n){
    for(int i=1; i<=3; i++){
        if(cups[i] == n){
            return i;
        }
    }
}
int main(){
    int m;
    cin>>m;
    for(int i=1; i<=3; i++)
        cups[i] = i;
    for(int i=0,a,b; i<m; i++){
        cin>>a>>b;
        int aIdx = getIdx(a);
        int bIdx = getIdx(b);
        int temp = cups[aIdx];
        cups[aIdx] = cups[bIdx];
        cups[bIdx] = temp;
    }
    cout<<cups[1];
    return 0;
}