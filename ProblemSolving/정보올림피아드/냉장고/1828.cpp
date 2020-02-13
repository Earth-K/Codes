#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct C{
    int minT,maxT;
};

bool comp(const C& c1, const C& c2){
    if(c1.maxT == c2.maxT)
        return c1.minT<c2.minT;
    else
        return c1.maxT <= c2.maxT;
}

int main(){
    int N;
    vector<C> vt;

    cin>>N;
    for(int i=0,a,b; i<N; i++){
        cin>>a>>b;
        vt.push_back({a,b});
    }

    sort(vt.begin(),vt.end(),comp);
    
    C now = vt[0];
    int idx, answer;
    idx = answer = 1;
    while(idx<N){
        if(now.maxT < vt[idx].minT){
            answer += 1;
            now = vt[idx];
        }

        idx++;
    }
    cout<<answer;
     return 0;
}