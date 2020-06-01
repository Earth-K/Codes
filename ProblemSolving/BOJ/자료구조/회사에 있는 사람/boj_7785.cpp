#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
unordered_map<string,bool> mp;
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string name, cmd;
        cin>>name>>cmd;
        if(cmd.compare("enter") == 0){
            mp[name] = true;
        }
        else{
            mp[name] = false;
        }
    }
    vector<string> vt;
    for(unordered_map<string,bool>::iterator it = mp.begin(); it != mp.end(); it++){
        if(it->second){
            vt.push_back(it->first);
        }
    }
    sort(vt.begin(), vt.end());
    for(int i=vt.size()-1; i>=0; i--){
        cout<<vt[i]<<"\n";
    }
    return 0;
}