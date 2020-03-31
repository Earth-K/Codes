#include<iostream>
#include<string>
using namespace std;
string str;
int main(){
    int n, cnt, cups;
    cin>>n>>str;

    int i = cnt = 0;
    cups = 1;
    while(str[i]){
        if(str[i] == 'S'){
            i++;
        }
        else{
            if(cups == 0)
                cnt += 1;
            else
                cups -= 1;
            i += 2;
        }
    }
    cout<<n-cnt<<endl;
     return 0;
}