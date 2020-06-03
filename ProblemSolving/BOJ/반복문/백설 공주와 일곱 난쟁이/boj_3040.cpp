#include<iostream>
#include<vector>
using namespace std;

vector<int> vt,ans;
bool chk[9];

bool dfs(){
    if(ans.size() == 7){
        int sum = 0;
        for(int n: ans){
            sum += n;
        }
        return (sum == 100) ? true : false;
    }
    for(int i=0; i<vt.size(); i++){
        if(chk[i] == true) continue;
        
        chk[i] = true;
        ans.push_back(vt[i]);

        if(dfs())
            return true;

        chk[i] = false;
        ans.pop_back();
    }
    return false;
}

int main(){
    for(int i=0,n; i<9; i++){
        cin>>n;
        vt.push_back(n);
    }
    dfs();
    for(int n: ans){
        cout<<n<<"\n";
    }
    return 0;
}