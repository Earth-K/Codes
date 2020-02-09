#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vt;
    int maxNum = 0;
    for(int i=0,n; i<9; i++){
        cin>>n;
        vt.push_back(n);
        if(maxNum<n)
            maxNum=n;
    }
    cout<<maxNum<<endl;
    for(int i=0; i<vt.size(); i++){
        if(vt[i] == maxNum)
            cout<<i+1;
    }
     return 0;
}