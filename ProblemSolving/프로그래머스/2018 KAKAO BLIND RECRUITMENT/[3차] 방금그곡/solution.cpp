#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

struct Obj{
    int idx, playtime;
    string title;
};
struct cmp{
    bool operator() (Obj& o1, Obj& o2){
        if(o1.playtime == o2.playtime)
            return o1.idx>o2.idx;
        else
            return o1.playtime < o2.playtime;
    }
};

void convertCode(string &m){
    string M;
    for(int i=0; i<m.size(); i++){
        if(m[i+1] == '#'){
            if(m[i] == 'A') M += 'a';
            if(m[i] == 'C') M += 'c';
            if(m[i] == 'D') M += 'd';
            if(m[i] == 'G') M += 'g';
            if(m[i] == 'F') M += 'f';
            i += 1;
        }
        else
            M+=m[i];
    }
    m = M;
}
int getPlaytime(string& startTime, string& endTime){
    int startH = atoi(startTime.substr(0,2).c_str());
    int endH = atoi(endTime.substr(0,2).c_str());
    int startM = atoi(startTime.substr(3,2).c_str());
    int endM = atoi(endTime.substr(3,2).c_str());
    int h = endH-startH;
    int m = endM-startM;
    return h*60+m;
}

string getPlaycode(string code, int playtime){
    string ret;
    convertCode(code);
    
    if(code.size() >= playtime){
        return code.substr(0, playtime);
    }
    else{
        while(ret.size() < playtime){
            ret += code;
        }
        return ret.substr(0, playtime);
    }
}
string solution(string m, vector<string> musicinfos) {
    priority_queue<Obj, deque<Obj>, cmp> pq;
    
    convertCode(m);
    
    for(int i=0; i<musicinfos.size(); i++){
        vector<int> vt;
        for(int j=0; musicinfos[i][j]; j++){
            if(musicinfos[i][j] == ','){
                vt.push_back(j);
            }
        }
        string startTime = musicinfos[i].substr(0,5);
        string endTime = musicinfos[i].substr(6,5);
        string title = musicinfos[i].substr(12,vt[2]-12);
        string code = musicinfos[i].substr(vt[2]+1);
        int playtime = getPlaytime(startTime,endTime);
        string playcode = getPlaycode(code,playtime);
        int idx = playcode.find(m);
        if(idx != -1){
            pq.push({i,playtime,title});
        }
    }
    string answer;
    if(pq.empty())
        answer = "(None)";
    else
        answer = pq.top().title;
    return answer;
}