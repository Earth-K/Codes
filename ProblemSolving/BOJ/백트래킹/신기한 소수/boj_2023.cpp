#include<iostream>
#include<string>
#include<cmath>
using namespace std;

string num;
int N;
bool isPrime(int n){
    if(n==1)
        return false;

    for(int i=2; i<=sqrt(n); i++)
        if(n%i==0) return false;
    return true;
}
bool check(string &num){
    for(int len=1; len<=num.size(); len++){
        string subNum = num.substr(0,len);
        int iNum = atoi(subNum.c_str());
        if(isPrime(iNum) == false)
            return false;
    }
    return true;
}
void solve(string &num){
    if(num.size() == N){
        cout<<num<<endl;
        return;
    }
    for(int n=1; n<=9; n++){
        num.push_back('0'+n);
        if(check(num))
            solve(num);
        num.pop_back();
    }
}
int main(){
    cin>>N;
    solve(num);
     return 0;
}