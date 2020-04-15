#include <string>
#include <iostream>

using namespace std;
bool check(string str){
    int i = 0;
    int cnt = 0;
    for(; str[i]; i++){
        if(str[i]=='('){
            cnt += 1;
        }
        else{
            if(cnt == 0)
                return false;
            cnt -= 1;
        }
    }
    if(cnt != 0) 
        return false;
    
    return true;
}

string solution(string p) {
    if(p.compare("") == 0)  return "";
    if(check(p))    return p;
    
    string u, v;
    int i = 1;
    int cnt = 1;
    for(; p[i]; i++){
        cnt += (p[0] == p[i]) ? 1: -1;
        if(cnt == 0) break;
    }
    u = p.substr(0,i+1);
    v = p.substr(i+1);
    
    if(check(u) == false) {
        string str = "(" + solution(v) + ")";
        u = u.substr(1);
        u.pop_back();
        
        for(int i=0; u[i]; i++)
            u[i] = (u[i] == '(') ? ')' : '(';
        
        return str+u;
    } 
    else {
        string res = solution(v);
        return u+res;
    }
    
    return "";
}