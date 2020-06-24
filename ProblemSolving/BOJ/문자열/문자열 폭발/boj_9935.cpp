#include<iostream>
#include<string>
using namespace std;
int main(){
    string str,ptn,ans;
    cin>>str>>ptn;
    int str_sz = str.size();
    int ptn_sz = ptn.size();

    for(int i=0; i<str_sz; i++){
        ans.push_back(str[i]);
        int ans_sz = ans.size();

        bool flag = false;
        if(str[i] == ptn[ptn_sz-1] && i >= ptn_sz-1){
            for(int j=0; j<ptn_sz; j++){
                if(ptn[ptn_sz-1-j] != ans[ans_sz-1-j]){
                    flag = true;
                    break;
                }
            }
            if(!flag){
                ans.erase(ans.size()-ptn_sz);
            }
        }
    }
    if(ans.empty())
        cout<<"FRULA";
    else
        cout<<ans;

    return 0;
}