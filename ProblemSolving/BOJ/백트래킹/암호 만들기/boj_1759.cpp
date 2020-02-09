#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int L,C;
vector<char> vt, c;

bool promise(vector<char>& c){
    int mCnt,jCnt;
    mCnt = jCnt = 0;

    for(int i=0; i<c.size() ;i++){
        char ch = c[i];
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            mCnt++;
        else
            jCnt++;
    }

    return (mCnt>=1 && jCnt>=2);
}

void solve(int idx, int cnt){

    if(cnt == L){
        if(promise(c)){
            for(int i=0; i<c.size(); i++)
                cout<<c[i];
            cout<<endl;
        }
        return;
    }

    if(idx == vt.size()){
        return;
    }

    c.push_back(vt[idx]);
    solve(idx+1,cnt+1);
    c.pop_back();
    solve(idx+1, cnt);
}

int main(){
    cin>>L>>C;
    for(int i=0; i<C; i++){
        char ch;
        cin>>ch;
        vt.push_back(ch);
    }
    sort(vt.begin(), vt.end());
    solve(0,0);
    return 0;
}