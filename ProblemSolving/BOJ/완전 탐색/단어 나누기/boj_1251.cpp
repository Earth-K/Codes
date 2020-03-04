#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    string str;
    vector<string> ans;
    cin>>str;
    for(int i=0; i<str.size()-2; i++){
        for(int j=i+1; j<str.size()-1; j++){
            for(int k=j+1; k<str.size(); k++){
                string a = str.substr(0,j);
                string b = str.substr(j,k-j);
                string c = str.substr(k,str.size()-k);
                reverse(a.begin(), a.end());
                reverse(b.begin(), b.end());
                reverse(c.begin(), c.end());
                ans.push_back(a+b+c);
            }
        }
    }
    sort(ans.begin(), ans.end());
    cout<<ans[0];
    return 0;
}