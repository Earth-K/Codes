#include<iostream>
#include<string>
using namespace std;
int calc(string n){
    int ret = 0;
    for(char ch : n)
        ret += ch-'0';
    
    if(ret >= 10)
        return calc(to_string(ret));
    else
        return ret;
}
int main(){
    while(true){
        string n;
        cin>>n;
        if(n.compare("0") == 0) break;

        cout<<calc(n)<<"\n";
    }
    return 0;
}