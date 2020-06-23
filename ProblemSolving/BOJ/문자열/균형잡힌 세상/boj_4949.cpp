#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool close(char ch){
    return ch==')' || ch==']';
}
bool open(char ch){
    return ch=='(' || ch=='[';
}
int main(){
    string str;
    while(true){
        getline(cin,str);
        if(str.compare(".") == 0)
            break;

        stack<char> s;    
        bool flag = false;

        for(char ch : str){
            if(open(ch)){
                s.push(ch);
            }
            else if(close(ch)){
                if(s.empty()){
                    flag = true;
                    break;
                }
                char o = s.top();
                s.pop();
                if((o == '(' && ch ==']') || (o == '[' && ch == ')')){
                    flag = true;
                    break;
                }
            }
        }
        if(flag || !s.empty()) {
            cout<<"no\n";
        }
        else{
            cout<<"yes\n";
        }
    }
    return 0;
}