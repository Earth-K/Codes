#include <string>
#include <vector>

using namespace std;
void findNetworkNum(int n, int nowComputer, const vector<vector<int>>& computers, vector<bool>& visited){
    visited[nowComputer] = true;
    
    for(int linkedComputer=0; linkedComputer<n ;linkedComputer++){
        if(visited[linkedComputer] == false && computers[nowComputer][linkedComputer]){
            findNetworkNum(n, linkedComputer, computers, visited);
        }
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    for(int computer=0; computer<n ;computer++){
        if(visited[computer] == false){
            findNetworkNum(n, computer, computers, visited);
            answer++;
        }
    }
    return answer;
}