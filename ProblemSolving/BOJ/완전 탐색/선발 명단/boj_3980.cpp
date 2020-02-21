#include<iostream>
#include<cstring>
using namespace std;

int stat[11][11], answer;
bool selectedPos[11];

void solve(int idx, int sum){
    if(idx == 11){
        if(answer < sum){
            answer = sum;
        }
        return;
    }

    for(int j=0; j<11; j++){
        if(stat[idx][j] == 0) continue;
        if(selectedPos[j]) continue;

        selectedPos[j] = true;
        solve(idx+1, sum+stat[idx][j]);
        selectedPos[j] = false;
    }
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        answer = 0;
        memset(selectedPos,0,sizeof(selectedPos));
        for(int i=0; i<11; i++)
            for(int j=0; j<11; j++)
                cin>>stat[i][j];
        
        solve(0,0);
        cout<<answer<<endl;
    }
     return 0;
}