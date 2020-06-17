#include<iostream>
using namespace std;
char map[2*101][101];
int main(){
    int N;
    cin>>N;
    if(N==1){
        cout<<'*';
        return 0;
    }
    
    for(int i=0; i<2*N; i++){
        for(int j=0; j<N; j++){
            map[i][j] = ' ';
        }
    }

    for(int i=0; i<2*N; i+=2){
        int cnt=0;
        int j=0;
        while(cnt <= N){
            if(cnt %2 == 0)
                map[i][j] = '*';
            else
                map[i+1][j] = '*';
            j += 1;
            cnt += 1;
        }
    }

    for(int i=0; i<2*N; i++){
        for(int j=0; j<N; j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }

    return 0;
}