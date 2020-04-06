#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer(2,0);
    priority_queue<int> pqMax;
    priority_queue<int,deque<int>,greater<int>> pqMin;
    int cnt = 0;

    for(int i=0; i<operations.size(); i++){
        string cmd = operations[i];
        string s_num = cmd.substr(2);
        int i_num = atoi(s_num.c_str());
        
        if(cnt == 0) {
            while(!pqMax.empty())pqMax.pop();
            while(!pqMin.empty())pqMin.pop();
        }
        if(cmd[0] == 'I'){
            pqMax.push(i_num);
            pqMin.push(i_num);
            cnt += 1;
        }
        else{
            if(cnt == 0) 
                continue;
            if(i_num == 1) // 최댓값 삭제
                pqMax.pop();
            else
                pqMin.pop();
            cnt -=1;
        }
    }
    if(cnt != 0){
        answer[0] = pqMax.top();
        answer[1] = pqMin.top();
    }
    return answer;
}