#include<iostream>
using namespace std;
int n,m;
int main(){
    cin>>n>>m;
    int maxM = m;
    bool flag = false;
    for(int i=0,in,out; i<n; i++){
        if(m < 0) {
            flag = true;
        }
        cin>>in>>out;
        m+=in;
        m-=out;
        if(maxM < m)
            maxM = m;
    }
    if(flag)
        cout<<"0";
    else
        cout<<maxM;
    return 0;
}