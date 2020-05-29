#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string str;
    string cambridge = "CAMBRIDGE";
    cin>>str;
    for(char ch : str){
        if(cambridge.find(ch) == string::npos){
            cout<<ch;
        }
    }
    return 0;
}