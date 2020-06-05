#include<iostream>
#include<vector>
using namespace std;

int n,r;
vector<int> vt, tmp;

//idx는 vt의 원소를 가리키는 인덱스
void combination(int idx){
    if(tmp.size() == r){
        // r개의 원소를 모두 선택한 경우
        for(int num: tmp){
            cout<<num<<" ";
        }
        cout<<"\n";
        return;
    }
    
    if(idx == n) 
        return;

    tmp.push_back(vt[idx]);
    combination(idx+1);
    tmp.pop_back();
    combination(idx+1);
}
int main(){
    cin>>n>>r;
    for(int i=0,k; i<n; i++){
        cin>>k;
        vt.push_back(k);
    }
    combination(0);
    return 0;
}