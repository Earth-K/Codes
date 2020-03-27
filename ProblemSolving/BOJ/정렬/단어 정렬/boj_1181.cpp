#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
bool comp(const string& s1, const string& s2){
    if(s1.size() < s2.size()){
        return true;
    }
    else if(s1.size() == s2.size()){
        int i=0;
        for( ; s1[i]; i++){
            if(s1[i] != s2[i])
                break;
        }
        if(i<s1.size()){
            return s1[i] < s2[i];
        }
        else 
            return false;
    }
    else
        return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    vector<string> vt;
    cin>>n;
    for(int i=0; i<n; i++){
        string str;
        cin>>str;
        vt.push_back(str);
    }
    sort(vt.begin(), vt.end(), comp);
    string preStr="";
    for(string str : vt){
        if(preStr.compare(str) == 0)
            continue;

        cout<<str<<"\n";
        preStr.assign(str);
    }
     return 0;
}