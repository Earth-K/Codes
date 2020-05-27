#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false),cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        unordered_set<string> s;
        vector<string> vt;
        bool isAnswer = true;
        cin>>n;
        for(int i=0; i<n; i++){
            string str;
            cin>>str;
            vt.push_back(str);
            s.insert(str);
        }
        for(string str : vt){
            for(int i=1; i<str.size(); i++){
                string sub = str.substr(0,i);
                if(s.find(sub) != s.end()){
                    isAnswer = false;
                    break;
                }
            }
            if(!isAnswer)break;
        }
        if(isAnswer) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}