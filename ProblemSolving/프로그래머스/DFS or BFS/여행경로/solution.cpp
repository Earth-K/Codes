#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N;
bool usedTicket[10000];

bool findPath(vector<string>& answer, vector<vector<string>> tickets, string city, int cnt){
    if(N == cnt) return true;
    
    for(int i=0; i<tickets.size() ; i++){
        if(usedTicket[i] == false && city.compare(tickets[i][0]) == 0){
            usedTicket[i] = true;
            answer.push_back(tickets[i][1]);
            
            bool res = findPath(answer, tickets, tickets[i][1], cnt+1);
            if(res) return true;
            
            usedTicket[i] = false;
            answer.pop_back();
        }
    }
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    sort(tickets.begin(), tickets.end());
    answer.push_back("ICN");
    N = tickets.size();
    findPath(answer, tickets, "ICN", 0);
    return answer;
}