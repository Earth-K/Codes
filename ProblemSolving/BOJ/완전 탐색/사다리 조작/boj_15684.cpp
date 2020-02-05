#include<iostream>
using namespace std;
int N,M,H,ladder[31][12], answer=987654321;
bool isAnswer(){
    for(int c=1; c<=N; c++){
        int nowR = 1;
        int nowC = c;
        while(nowR<=H){
            if(ladder[nowR][nowC] == 1)
                nowC += 1;
            else if(ladder[nowR][nowC-1] == 1)
                nowC -= 1;
            nowR += 1;
        }
        if(nowC != c) 
            return false;
    }
    return true;
}
void solve(int cnt, int startIdx){
    if(cnt>=4){
        return;
    }
    if(isAnswer()){
        if(answer > cnt)
            answer = cnt;
        return;
    }

    for(int a=startIdx; a<=H; a++){
        for(int b=1; b<N; b++){
            if(ladder[a][b] == 0 && ladder[a][b-1] == 0 && ladder[a][b+1] == 0){
                ladder[a][b] = 1;
                solve(cnt+1, a);
                ladder[a][b] = 0;
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    cin>>N>>M>>H;
    for(int i=0,a,b; i<M; i++){
        cin>>a>>b;
        ladder[a][b] = 1;
    }
    
    solve(0, 1);

    if(answer == 987654321)
        cout<<"-1";
    else
        cout<<answer;
    return 0;
}