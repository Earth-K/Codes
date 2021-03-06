#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool check[9];

void dfs(const vector<int>& numbers, int m, vector<int>& vt){
    if(vt.size() == m){
        for(int n : vt)
            cout<<n<<" ";
        cout<<"\n";
        return;
    }

    for(int i=0; i<numbers.size(); i++){
        if(check[i]) continue;
        if(!vt.empty() && vt.back() >= numbers[i]) continue;

        check[i] = true;
        vt.push_back(numbers[i]);

        dfs(numbers,m,vt);

        check[i] = false;
        vt.pop_back();
    }
}

int main(){
    int n,m;
    vector<int> numbers, vt;
    cin>>n>>m;
    for(int i=0,k; i<n; i++){
        cin>>k;
        numbers.push_back(k);
    }
    sort(numbers.begin(), numbers.end());
    dfs(numbers,m,vt);
    return 0;
}