#include<iostream>
#include<vector>
using namespace std;

void dfs(int N, int M, vector<int>& vt){
    if(vt.size() == M){
        for(int i: vt)
            cout<<i<<" ";
        cout<<"\n";
        return;
    }

    for(int n=1; n<=N; n++){
        vt.push_back(n);
        dfs(N,M,vt);
        vt.pop_back();
    }
}
int main(){
    int N,M;
    vector<int> vt;
    cin>>N>>M;
    dfs(N,M,vt);
    return 0;
}