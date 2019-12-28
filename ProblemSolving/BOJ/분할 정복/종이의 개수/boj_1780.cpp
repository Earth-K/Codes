#include<iostream>
using namespace std;
int N, map[2200][2200], cnt0, cnt1, cntm1;
bool chkPaper(int r, int c, int size){
    for(int i=r; i<r+size ;i++){
        for(int j=c; j<c+size; j++){
            if(map[r][c] != map[i][j])
                return false;
        }
    }
    return true;
}
void calcAnswer(int r, int c, int size){
    if(chkPaper(r,c,size)){
        if(map[r][c] == -1) cntm1++;
        else if(map[r][c] == 0) cnt0++;
        else cnt1++;
        return ;
    }

    int v = size / 3;
    calcAnswer(r, c, v);
    calcAnswer(r, c + v, v);
    calcAnswer(r, c + v * 2, v);
    calcAnswer(r + v, c, v);
    calcAnswer(r + v, c + v, v);
    calcAnswer(r + v, c + v * 2, v);
    calcAnswer(r + v * 2, c, v);
    calcAnswer(r + v * 2, c + v, v);
    calcAnswer(r + v * 2, c + v * 2, v);
}
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>N;
    for(int i=0; i<N ;i++){
        for(int j=0; j<N; j++)
            cin>>map[i][j];
    }
    calcAnswer(0,0,N);
    cout<<cntm1<<endl;
    cout<<cnt0<<endl;
    cout<<cnt1<<endl;
    return 0;
}