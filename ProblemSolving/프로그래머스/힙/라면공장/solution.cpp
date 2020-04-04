#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

priority_queue<int> pq;
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int idx = 0;
    while(stock<k){
        for(int i=idx; i<dates.size(); i++){
            if(dates[i] <= stock){
                pq.push(supplies[i]);
                idx += 1;
            }
        }
        stock += pq.top();
        pq.pop();
        answer += 1;
    }
    return answer;
}