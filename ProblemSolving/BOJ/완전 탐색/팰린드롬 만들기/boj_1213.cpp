#include<iostream>
#include<string>
#include<deque>
using namespace std;

string str;
int cntAlp[26];
deque<char> dq;

int main(){
    cin>>str;
    for(int i=0; i<str.size(); i++){
        cntAlp[str[i]-'A']++;
    }

    char oddAlp=' ';
    int cnt = 0;
    for(int i=0; i<26; i++){
        if(cntAlp[i]%2 == 1){
            cnt++;
            oddAlp=i+'A';
            cntAlp[i]-=1;
        }
    }
    if(cnt > 1) {
        cout<<"I'm Sorry Hansoo";
        return 0;
    }
    if(cnt==1){    
        dq.push_front(oddAlp);
    }

    for (int i = 25; i >= 0; i--){
        while (cntAlp[i] > 0){
            dq.push_front(i + 'A');
            dq.push_back(i + 'A');
            cntAlp[i] -= 2;
        }
    }

    for(int i=0; i<dq.size(); i++){
        cout<<dq[i];
    }
    return 0;
}