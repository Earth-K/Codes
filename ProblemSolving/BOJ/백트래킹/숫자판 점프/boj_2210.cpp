#include<iostream>
#include<string>
using namespace std;

int map[5][5];
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
bool visited[1000000];
string number;
int answer;

void dfs(int r, int c){
    
    if(number.size() == 6){
        int i_num = atoi(number.c_str());
        if(visited[i_num] == false){
            visited[i_num] = true;
            answer += 1;
        }
        return;
    }

    for(int i=0; i<4; i++){
        int nextR = r+dr[i];
        int nextC = c+dc[i];
        if(0<=nextR && nextR<5 && 0<=nextC && nextC<5){
            number.push_back(map[nextR][nextC]+'0');
            dfs(nextR,nextC);
            number.pop_back();
        }
    }
}
int main(){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cin>>map[i][j];
        }
    }
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            number = to_string(map[i][j]);
            dfs(i,j);
        }
    }
    cout<<answer<<endl;
    return 0;
}