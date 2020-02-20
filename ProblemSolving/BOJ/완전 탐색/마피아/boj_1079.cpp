#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int N, mafia, answer, cnt;
int score[16], R[16][16];
bool live[16], endFlag;

void solve(int cloneN, int cntNight){
    if(endFlag){
        return;
    }
    if(cloneN == 1 || live[mafia] == false){
        if(cloneN == 1)
           endFlag = true;
           
        if(answer < cntNight){
            answer = cntNight;
        }
        return;
    }

    if(cloneN % 2 == 0){
        for(int target=0; target<N; target++){
            if(target == mafia) continue;
            if(live[target] == false) continue;

            int copyScore[16];
            memcpy(copyScore,score,sizeof(score));

            live[target] = false;
            for(int i=0; i<N; i++){
                score[i] += R[target][i];
            }

            solve(cloneN-1, cntNight+1);

            live[target] = true;
            memcpy(score,copyScore,sizeof(score));
        }
    }
    else{
        int maxScore = 0, target;
        for(int i=0; i<N; i++){
            if(live[i] == false) continue;
            if(maxScore < score[i]){
                maxScore = score[i];
                target = i;
            }
        }

        live[target] = false;
        solve(cloneN-1, cntNight);
        live[target] = true;
    }
}

int main(){
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>score[i];
        live[i] = true;
    }
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin>>R[i][j];
    cin>>mafia;

    solve(N,0);

    cout<<answer;
     return 0;
}