#include <string>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

int M,N,startR,startC,ansCnt;

void rotate(vector<vector<int>>& key){
    vector<vector<int>> temp(key);
    for(int i=M-1; i>=0; i--){
        for(int j=0; j<M; j++){
            key[j][i] = temp[-i+(M-1)][j];
        }
    }
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    M = key.size();
    N = lock.size();
    ansCnt = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(lock[i][j] == 0)
               ansCnt += 1;
        }
    }
    if(ansCnt == 0) return true;
   
    for(int rep=0; rep<4; rep++){
        if(rep)rotate(key);
        for(int startR = -(M-1) ; startR<N; startR++){
            for(int startC = -(M-1); startC<N; startC++){
                int resCnt;
                for(int r = startR ; r<N; r++){
                    for(int c = startC; c<N; c++){
                        resCnt = 0;
                        for(int i=0; i<M; i++){
                            for(int j=0; j<M; j++){
                                if(0<=r+i && r+i<N && 0<=c+j && c+j<N){
                                    if(key[i][j] == 1 && lock[r+i][c+j] == 1){
                                        resCnt = 12342134;
                                    }
                                    if(key[i][j] == 1 && lock[r+i][c+j] == 0){
                                        resCnt += 1;
                                    }
                                }
                            }
                        }
                        if(ansCnt == resCnt){
                            return true;
                        }
                    }
                }
            }
        }
    }
    
    return false;
}