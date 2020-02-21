#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

int N,answer;
string num;
bool usedNum[10000000];


bool isPrimeNum(int n){
    for(int i=2; i<=sqrt(n); i++){
        if(n%i==0)
            return false;
    }
    return true;
}
int solve(string num){
    int ret = 0;
    sort(num.begin(), num.end());
    //cout<<"sortedNum: "<<num<<endl;
    do{
        int n = atoi(num.c_str());
        if(usedNum[n])continue;
        if(isPrimeNum(n)){
            usedNum[n] = true;
            ret += 1;
        }
    }while(next_permutation(num.begin(), num.end()));

    return ret;
}

void comb(int idx, int target, int k, string& madeNum){
    if(k == 0){
        //cout<<madeNum<<endl;
        answer += solve(madeNum);
        return;
    }
    if(target == num.size()){
        return;
    }
    madeNum.push_back(num[target]);
    comb(idx+1, target+1, k-1, madeNum);
    madeNum.pop_back();
    comb(idx, target+1, k, madeNum);
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>num;
        answer = 0;
        for(int k=1; k<=num.size();k++){
            string madeNum;
            comb(0,0,k,madeNum);
        }
        cout<<answer<<endl;
    }
     return 0;
}