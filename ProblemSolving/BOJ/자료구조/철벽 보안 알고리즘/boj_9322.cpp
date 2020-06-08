#include<iostream>
#include<string>
#include<vector>
using namespace std;
int T,n;
string str[1000], pk[1000], ck[1000], ans[1000];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=0; i<n; i++)
            cin>>str[i];
        for(int i=0; i<n; i++)
            cin>>pk[i];
        for(int i=0; i<n; i++)
            cin>>ck[i];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(str[i] == pk[j]){
                    ans[i] = ck[j];
                }
            }
        }
        for(int i=0; i<n; i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}