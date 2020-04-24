#include<iostream>
#include<vector>
using namespace std;

bool check[9];
void dfs(int N, int M, vector<int>& vt){
    if(vt.size() == M){
        for(int i: vt)
            cout<<i<<" ";
        cout<<"\n";
        return;
    }

    for(int n=1; n<=N; n++){
        if(check[n])continue;
        vt.push_back(n);
        check[n] = true;

        dfs(N,M,vt);

        vt.pop_back();
        check[n] = false;
    }
}
int main(){
    int N,M;
    vector<int> vt;
    cin>>N>>M;
    dfs(N,M,vt);
    return 0;
}