#include<iostream>
using namespace std;
int alp[26];
int main(){
    string S;
    cin>>S;
    for(int i=0 ;i<S.length(); i++)
        alp[S[i]-'a']++;
    for(int i=0 ;i<26; i++)
        cout<<alp[i]<<" ";
    return 0;
}