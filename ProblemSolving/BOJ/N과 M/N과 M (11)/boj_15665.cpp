#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void dfs(const vector<int>& numbers, int m, vector<int>& ans){
    if(ans.size() == m){
        for(int num : ans)
            cout<<num<<" ";
        cout<<"\n";
        return;
    }

    for(int i=0; i<numbers.size(); i++){
        ans.push_back(numbers[i]);
        dfs(numbers,m,ans);
        ans.pop_back();
    }
}

int main(){
    int n,m;
    vector<int> numbers, ans;
    cin>>n>>m;
    for(int i=0,num; i<n; i++){
        cin>>num;
        if(find(numbers.begin(), numbers.end(), num) == numbers.end())
            numbers.push_back(num);
    }
    sort(numbers.begin(), numbers.end());
    dfs(numbers,m,ans);
    return 0;
}