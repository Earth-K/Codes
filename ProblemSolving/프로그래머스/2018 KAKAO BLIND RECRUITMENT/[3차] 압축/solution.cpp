#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map<string,int> mp;

vector<int> solution(string msg) {
    vector<int> answer;
    
    for(int i=0; i<26; i++){
        char ch = 'A'+i;
        string alp = "";
        alp.push_back(ch);
        mp[alp] = i+1;
    }
    
    int pos = 0;
    int cnt = 27;
    while(pos<msg.size()){
        string valid;
        for(int len = 1; len <= msg.size()-pos; len++){
            string str = msg.substr(pos,len);
            bool flag = false;
            map<string,int>::iterator it = mp.begin();
            while(it != mp.end()){
                if(it->first.compare(str) == 0){
                    flag = true;
                    valid = str;
                    break;
                }
                it++;
            }
            if(!flag) {
                mp[str] = cnt++;
                break;
            }
        }
        answer.push_back(mp[valid]);
        pos += valid.size();
    }
    
    return answer;
}