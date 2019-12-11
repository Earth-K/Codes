#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int begin = 0;
    int end = progresses.size();
    
    for(int time = 1; time<=100 ;time++){
        if(begin == end)
            break;
        
        for(int i=begin; i<end ;i++)
            progresses[i] += speeds[i];
        
        if(progresses[begin] >= 100){
            int cnt = 0;
            for(int i=begin; i<end; i++){
                if(progresses[i]>=100)
                    cnt++;
                else
                    break;
            }   
            answer.push_back(cnt);
            begin += cnt;
        }
    }
    
    return answer;
}