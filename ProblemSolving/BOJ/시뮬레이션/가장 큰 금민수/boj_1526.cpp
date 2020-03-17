#include<iostream>
using namespace std;
int N;
bool isGMS(string& num){
    for(int i=0; num[i]; i++){
        if(!(num[i] == '4' || num[i] == '7'))
            return false;
    }
    return true;
}
int main(){
    cin>>N;
    int ans = 0;
    for(int i=4; i<=N; i++){
        string num = to_string(i);
        if(isGMS(num)){
            if(ans<i) ans = i;
        }
    }
    cout<<ans;
    return 0;
}