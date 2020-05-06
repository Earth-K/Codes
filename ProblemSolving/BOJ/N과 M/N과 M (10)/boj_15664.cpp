#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

set<string> s;
bool idxCheck[9];

void dfs(const vector<int>& numbers, int m, vector<int>& ans){
    if(ans.size() == m){
        string str;
        for(int i=0; i<ans.size(); i++)
            str += to_string(ans[i]);
        if(s.find(str) != s.end()) return;

        s.insert(str);
        for(int num : ans)
            cout<<num<<" ";
        cout<<"\n";
        return;
    }

    for(int i=0; i<numbers.size(); i++){
        if(idxCheck[i]) continue;
        if(!ans.empty() && ans.back() > numbers[i]) continue;
        
        idxCheck[i] = true;
        ans.push_back(numbers[i]);

        dfs(numbers,m,ans);

        idxCheck[i] = false;
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
    dfs(numbers,m,ans);
    return 0;
}