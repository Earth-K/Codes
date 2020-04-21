#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void moveDown(int m, int n, vector<string>& board){
    for(int j=0; j<n; j++){
        for(int i=m-1; i>=1; i--){
            if(board[i][j] == ' '){
                for(int k=i-1; k>=0; k--){
                    if(board[k][j] != ' '){
                        swap(board[i][j], board[k][j]);
                        break;
                    }
                }
            }
        }
    }
}
int delBlock(int m, int n, vector<vector<bool>>& delChk, vector<string>& board){
    int cnt = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(delChk[i][j]){
                cnt += 1;
                board[i][j] = ' ';
            }
        }
    }
    return cnt;
}
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while(true)
    {
        vector<vector<bool>> delChk(m,vector<bool>(n,false));
        
        for(int i=0; i<m-1; i++){
            for(int j=0; j<n-1; j++){
                if(board[i][j] == board[i][j+1] && board[i+1][j] == board[i+1][j+1] 
                   && board[i][j] == board[i+1][j] && board[i][j] != ' ')
                {
                    delChk[i][j] = delChk[i][j+1] = delChk[i+1][j] = delChk[i+1][j+1] = true;
                }
            }
        }
        
        int res = delBlock(m,n,delChk,board);
        answer += res;
        if(res > 0)
            moveDown(m,n,board);
        else
             break;
    }
    
    return answer;
}