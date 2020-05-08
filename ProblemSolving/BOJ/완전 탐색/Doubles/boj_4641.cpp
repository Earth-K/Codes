#include<iostream>
#include<vector>
using namespace std;
int main(){
    while(true){
        bool endFlag = false;
        int n;
        vector<int> vt;
    
        while(true){
            cin>>n;
            if(n == 0) break;
            if(n == -1) {
                endFlag = true;
                break;
            }
            vt.push_back(n);
        }
        if(endFlag) break;
        int cnt = 0;
        int sz = vt.size();
        for(int i=0; i<sz; i++){
            for(int j=0; j<sz; j++){
                if(vt[i]*2 == vt[j])
                    cnt += 1;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}