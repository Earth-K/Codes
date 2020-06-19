#include<iostream>
#include<string>
using namespace std;
string map[5*101+1];
int ans[5];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int M,N;
    cin>>M>>N;
    
    for(int i=0; i<5*M+1; i++){
        cin>>map[i];
    }
    for(int i=1; i<5*M+1; i+=5){
        for(int j=1; j<5*N+1; j+=5){
            int cnt = 0;
            int r = i;
            while(map[r][j] != '#' && map[r][j] !='.'){
                cnt += 1;
                r += 1;
            }
            ans[cnt] += 1;
        }
    }

    for(int i=0; i<5; i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}