#include<iostream>
#include<string>
#include<vector>
using namespace std;
int goLeft(int p){
    if(p+1 == 9)
        return 1;
    else
        return p+1;
}
int main(){
    int pos,N,time,ans;
    cin>>pos>>N;
    vector<pair<int,string>> vt;
    for(int i=0; i<N; i++){
        int T;
        string Z;
        cin>>T>>Z;
        vt.push_back({T,Z});
    }

    time = ans = 0;
    for(int i=0; i<N; i++){
        time += vt[i].first;
        if(time >= 210){
            ans = pos;
            break;
        }
        if(vt[i].second.compare("T") == 0){
            pos = goLeft(pos);
        }
    }
    cout<<ans;
    return 0;
}