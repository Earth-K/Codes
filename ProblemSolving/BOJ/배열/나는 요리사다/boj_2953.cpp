#include<iostream>
using namespace std;
int score[4];
int main(){
    for(int i=0; i<5; i++){
        for(int j=0,n; j<4; j++){
            cin>>n;
            score[i] += n;
        }
    }
    int answer = 0;
    int idx = 0;
    for(int i=0; i<5; i++){
        if(answer < score[i]){
            answer = score[i];
            idx = i+1;
        }
    }
    cout<<idx<<" "<<answer;
    return 0;
}