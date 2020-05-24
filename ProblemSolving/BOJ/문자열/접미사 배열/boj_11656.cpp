#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string S;
    vector<string> vt;
    cin>>S;
    for(int i=S.size()-1; i>=0 ;i--){
        vt.push_back(S.substr(i));
    }
    sort(vt.begin(), vt.end());
    for(string s : vt)
        cout<<s<<"\n";
    return 0;
}