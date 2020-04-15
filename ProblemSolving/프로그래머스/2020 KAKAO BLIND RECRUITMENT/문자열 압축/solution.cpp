#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int sz;
int solution(string s) {
    int answer = 987654321;
    sz = s.size();
    
    for(int len=1; len<=sz/2; len++){
        string pre;
        int cnt = 1;
        string ret;
        
        for(int i=0; i<sz; i+=len){
            string now = s.substr(i,len);
            if(pre.compare(now) == 0){
                cnt += 1;
            }
            else{
                if(cnt == 1)
                    ret += pre;
                else
                    ret += to_string(cnt)+pre;
                cnt = 1;
            }
            pre = now;
        }
        if(cnt == 1)
            ret += pre;
        else
            ret += to_string(cnt)+pre;
        
        int retSz = ret.size();
        answer = min(answer, retSz);
    }
    if(answer == 987654321)
        answer = 1;
    return answer;
}