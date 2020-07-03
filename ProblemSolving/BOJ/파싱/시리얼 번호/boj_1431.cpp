#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int getSum(const string& str){
    int ret = 0;
    for(int i=0; i<str.size(); i++){
        if('0'<=str[i] && str[i]<='9'){
            ret += str[i]-'0';
        }
    }
    return ret;
}
bool comp(const string& A, const string& B){
    if(A.size() == B.size()){
        int sumA,sumB;
        sumA = getSum(A);
        sumB = getSum(B);
        if(sumA != sumB){
            return sumA < sumB;
        }
        else{
            return A<B;
        }
    }
    else{
        return A.size() < B.size();
    }
}
int main(){
    int N;
    cin>>N;
    vector<string> vt(N,"");
    for(int i=0; i<N; i++){
        cin>>vt[i];
    }
    sort(vt.begin(), vt.end(), comp);
    for(int i=0; i<vt.size(); i++){
        cout<<vt[i]<<"\n";
    }
    return 0;
}