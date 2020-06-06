#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

struct Obj{
    int idx,number,cnt;
};
bool comp(const Obj& o1, const Obj& o2){
    if(o1.cnt == o2.cnt){
        return o1.idx < o2.idx;
    }
    else {
        return o1.cnt > o2.cnt;
    }
}

map<int,int> mp;
int N,C;

int main(){
    cin>>N>>C;
    vector<int> inputList;
    for(int i=0,n; i<N; i++){
        cin>>n;
        mp[n] += 1;
        inputList.push_back(n);
    }
    vector<Obj> vt;
    for(map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
        int idx = 0;
        for(int i=0; i<inputList.size(); i++){
            if(it->first == inputList[i]){
                idx = i;
                break;
            }
        }
        vt.push_back({idx,it->first,it->second});
    }
    sort(vt.begin(), vt.end(),comp);
    for(int i=0 ; i<vt.size(); i++){
        int cnt = vt[i].cnt;
        for(int j=0; j<cnt; j++){
            cout<<vt[i].number<<" ";
        }
    }
    return 0;
}