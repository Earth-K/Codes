#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<deque>

#define pii pair<int,int>
using namespace std;

struct comp{
    bool operator()(const pii &p1, const pii &p2){
        return p1.second>p2.second;
    }
};
priority_queue<pii,deque<pii>,comp> pq;
    
int solution(vector<vector<int>> jobs) {
    int answer, time, idx;
    answer = time = idx = 0;
    sort(jobs.begin(), jobs.end());
    while(true){
        for(int i=idx; i<jobs.size(); i++){
            if(jobs[i][0] <= time){
                pq.push({jobs[i][0],jobs[i][1]});
                idx += 1;
            }
        }
        if(pq.empty()){
            time = jobs[idx][0];
        }
        else{
            pii p = pq.top();
            time += p.second;
            answer += time-p.first;
            pq.pop();
        }
        if(pq.empty() && idx==jobs.size()) break;
    }
    return answer/jobs.size();
}