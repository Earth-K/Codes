#include<iostream>
#include<string>
using namespace std;
int alpCnt[26];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    while(T--){
        string str;
        for(int i=0; i<26; i++)
            alpCnt[i] = 0;
        
        cin>>str;
        bool flag = false;
        for(int i=0; str[i]; i++){
            alpCnt[str[i]-'A'] += 1;

            if(alpCnt[str[i]-'A']%3 == 0){
                if(str[i+1] != str[i]){
                    flag = true;
                    break;
                }
                i++;
            }
        }
        if(flag)
            cout<<"FAKE"<<"\n";
        else
            cout<<"OK"<<"\n";
    }
    return 0;
}