#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

bool comp(pair<int,float>& p1, pair<int,float>& p2){
    if(p1.second == p2.second)
        return p1.first < p2.first;
    else
        return p1.second > p2.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int,float>> vt;
    
    int num = 1;
    while(num<=N){
        float cnt = 0;
        float playersNum = 0;
        for(int i=0; i<stages.size(); i++){
            if(num <= stages[i])
                playersNum += 1;
            if(num == stages[i])
                cnt += 1;
        }
        float res = (playersNum == 0) ? 0 : cnt/playersNum;
        vt.push_back({num,res});
        num += 1;
    }
    
    sort(vt.begin(), vt.end(), comp);
    for(int i=0; i<vt.size(); i++)
        answer.push_back(vt[i].first);
    
    return answer;
}