#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;
string str;
stack<char> result, temp;

void left(){
    if(!result.empty()){
        temp.push(result.top());
        result.pop();
    }
}
void right(){
    if(!temp.empty()){
        result.push(temp.top());
        temp.pop();
    }
}
void backSpace(){
    if(!result.empty())
        result.pop();
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        cin>>str;
        for(int i=0; str[i]; i++){
            if(str[i] == '<'){
                left();
            }
            else if(str[i] == '>'){
                right();
            }
            else if(str[i] == '-'){
                backSpace();
            }
            else{
                result.push(str[i]);
            }
        }
        while(!temp.empty()){
            result.push(temp.top());
            temp.pop();
        }
        string ans;
        while(!result.empty()){
            ans.push_back(result.top());
            result.pop();
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
    }
     return 0;
}