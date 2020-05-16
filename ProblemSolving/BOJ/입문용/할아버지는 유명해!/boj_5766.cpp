#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int cnt[10001];

int getMaxCnt(){
    int maxCnt = 0;
    for(int i=1; i<=10000; i++){
        if(maxCnt < cnt[i])
            maxCnt = cnt[i];
    }
    return maxCnt;
}
vector<int> getNumList(int c){
    vector<int> ret;
    for(int i=1; i<=10000; i++){
        if(cnt[i] == c){
            ret.push_back(i);
        }
    }
    return ret;
}
void delNum(const vector<int>& vt){
    for(int n : vt)
        cnt[n] = 0;
}   

int main(){
    while(true){
        int N,M;
        cin>>N>>M;
        if(N==0 && M==0) break;
        memset(cnt,0,sizeof(cnt));

        for(int i=0; i<N; i++){
            for(int j=0,n; j<M; j++){
                cin>>n;
                cnt[n] += 1;
            }
        }
        int maxCnt = getMaxCnt();
        vector<int> vt = getNumList(maxCnt);
        delNum(vt);
        maxCnt = getMaxCnt();
        vt = getNumList(maxCnt);
        for(int n : vt)
            cout<<n<<" ";
        cout<<"\n";
    }
    return 0;
}