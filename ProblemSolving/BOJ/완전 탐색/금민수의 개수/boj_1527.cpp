#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int cnt,a,b;

void solve(string& num){
    int n;
    stringstream ss(num);
    ss>>n;

    if(n>1000000000)
        return;

    if(a<=n && n<=b){
        cnt += 1;
    }
    
    num.push_back('4');
    solve(num);
    num.pop_back();

    num.push_back('7');
    solve(num);
    num.pop_back();
}

int main(){
    cin>>a>>b;
    string str;
    str = "4";
    solve(str);
    str = "7";
    solve(str);

    cout<<cnt;
    return 0;
}