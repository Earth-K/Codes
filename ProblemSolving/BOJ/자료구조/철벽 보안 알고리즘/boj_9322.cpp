#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int T;
    cin>>T;
    while(T--){
        int n,conv[1000];
        cin>>n;
        vector<vector<string>> vt(3);
        for(int i=0; i<3; i++){
            for(int j=0; j<n; j++){
                string s;
                cin>>s;
                vt[i].push_back(s);
            }
        }
        for(int i=0; i<vt[0].size(); i++){
            for(int j=0; j<vt[1].size(); j++){
                if(vt[0][i].compare(vt[1][j]) == 0){
                    conv[j] = i;
                }
            }
        }
        vector<string> ans(vt[2]);
        for(int i=0; i<vt[2].size(); i++){
            ans[conv[i]] = vt[2][i];
        }
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}