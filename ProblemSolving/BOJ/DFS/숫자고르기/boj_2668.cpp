#include<iostream>
#include<vector>
using namespace std;

int arr[2][101], N;
bool used[101];
vector<int> ans;

bool chkAns(vector<int>& cnt){
    for(int c : cnt){
        if(c == 1)
            return false;
    }
    return true;
}
bool dfs(vector<int>& vt,int n,vector<int>& cnt){
    if(vt.size() == n){
        if(chkAns(cnt)){
            ans = vt;
            return true;
        }
        return false;
    }
    
    for(int i=1; i<=N; i++){
        if(used[i]) continue;
        used[i] = true;
        vt.push_back(i);
        cnt[i] += 1;
        cnt[arr[1][i]] += 1;

        if(dfs(vt,n,cnt))
            return true;

        used[i] = false;
        vt.pop_back();
        cnt[i] -= 1;
        cnt[arr[1][i]] -= 1;
    }
    return false;
}
bool solve(int n){
    vector<int> vt, cnt(N+1,0);
    return dfs(vt,n,cnt);
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for(int i=1; i<=N; i++)
        arr[0][i] = i;
    for(int i=1; i<=N; i++)
        cin>>arr[1][i];
    
    for(int n=N;n>=1; n--){
        if(solve(n))break;
    }
    cout<<ans.size()<<"\n";
    for(int n:ans)
        cout<<n<<"\n";
    
    return 0;
}