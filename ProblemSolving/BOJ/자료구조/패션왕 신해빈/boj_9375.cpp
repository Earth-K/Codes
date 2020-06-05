#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

unordered_map<string, int> mp;
unordered_set<string> s;
vector<int> vt;
int n,answer;

int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        mp.clear();
        vt.clear();
        s.clear();

        for(int i=0; i<n; i++){
            string type, str;
            cin>>str>>type;
            mp[type] += 1;
            s.insert(type);
        }
        for(unordered_set<string>::iterator it = s.begin() ; it!=s.end(); it++){
            vt.push_back(mp[*it]+1);
        }

        answer = 1;
        for(int i=0; i<vt.size(); i++){
            answer *= vt[i];
        }
        cout<<answer-1<<"\n";
    }
    return 0;
}