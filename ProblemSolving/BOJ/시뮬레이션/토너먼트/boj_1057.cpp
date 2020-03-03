#include<iostream>
#include<vector>
using namespace std;
int n, a, b;
int main(){
    cin>>n>>a>>b;
    vector<int> vt(n,0);
    for(int i=0; i<n; i++)
        vt[i] = i+1;
        
    int cnt = 0;
    bool endFlag = false;
    while(vt.size() != 1){
        vector<int> tmp;
        cnt += 1;
        for(int i=0; i<vt.size()-1; i+=2){
            if((vt[i]==a && vt[i+1]==b) || (vt[i]==b && vt[i+1]==a)){
                cout<<cnt;
                endFlag = true;
                break;
            }   
            else if(vt[i]==a || vt[i+1]==a)
                tmp.push_back(a);
            else if(vt[i]==b || vt[i+1]==b)
                tmp.push_back(b);
            else
                tmp.push_back(0);                
        }
        if(endFlag)
            break;
        if(vt.size()%2 != 0){
            if(vt.back()==a)
                tmp.push_back(a);
            else if(vt.back()==b)
                tmp.push_back(b);
            else
                tmp.push_back(0);            
        }
        vt.resize(tmp.size());
        copy(tmp.begin(),tmp.end(),vt.begin());
    }
    if(cnt==0)
        cout<<"-1";
     return 0;
}