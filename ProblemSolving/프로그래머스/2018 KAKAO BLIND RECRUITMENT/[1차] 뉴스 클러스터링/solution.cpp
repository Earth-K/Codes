#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <map>

using namespace std;
float calc(map<string, int> &mp1, map<string, int> &mp2){
    
    float gyo,hop;
    gyo = hop = 0;
    
    map<string, int>::iterator it = mp1.begin();
    while(it!=mp1.end()){
        string s = it->first;
        map<string, int>::iterator it2 = mp2.find(s);
        if(it2 != mp2.end()){
            gyo += min(mp1[s],mp2[s]);
            hop += max(mp1[s],mp2[s]);
            it = mp1.erase(it);
            mp2.erase(it2);
            continue;
        }
        else{
            hop +=it->second;
        }
        it++;
    }
    
    it = mp2.begin();
    while(it != mp2.end()){
        hop += it->second;
        it++;
    }
    
    return (gyo==0 && hop == 0)? 1 : gyo/hop;
}
void create_mp(map<string, int> &mp, string str){
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    for(int i=0; i<str.size()-1; i++){
        if('a'<=str[i] && str[i]<='z' && 'a'<=str[i+1] && str[i+1]<='z'){
            string s="  ";
            s[0]=str[i];
            s[1]=str[i+1];
            mp[s] += 1;
        }
    }
}
int solution(string str1, string str2) {
    int answer = 0;
    map<string, int> mp1, mp2;
    
    create_mp(mp1,str1);
    create_mp(mp2,str2);
    
    return calc(mp1,mp2) * 65536;
}