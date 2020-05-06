#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

bool check[9];
set<vector<int>> s;

void dfs(const vector<int>& numbers, int m, vector<int>& ans, int idx){
    if(ans.size() == m){
        s.insert(ans);
        return;
    }

    for(int i=0; i<numbers.size(); i++){
        if(check[i]) continue;
        if(!ans.empty() && ans.back()>numbers[i]) continue;

        check[i] = true;
        ans.push_back(numbers[i]);
        dfs(numbers,m,ans,i+1);
        check[i] = false;
        ans.pop_back();
    }
}

int main(){
    int n,m;
    vector<int> numbers, ans;
    cin>>n>>m;
    for(int i=0,num; i<n; i++){
        cin>>num;
        numbers.push_back(num);
    }
    sort(numbers.begin(), numbers.end());
    dfs(numbers,m,ans,0);

    for(vector<int> ans : s){
        for(int num : ans)
            cout<<num<<" ";
        cout<<"\n";
    }
    return 0;
}