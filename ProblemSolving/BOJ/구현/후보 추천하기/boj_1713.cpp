#include<iostream>
#include<algorithm>
using namespace std;

int N, T, photoCase[20], cnt;

struct Student{
    int recomend, time;
}stu[101];

int findStuIdx(int n){
    for(int i=0; i<cnt; i++){
        if(photoCase[i] == n)
            return i;
    }
    return -1;
}
int getDelStuIdx(){
    int ret = 0;
    int maxTime = -1;
    int minRecomend = 987654321;
    for(int i=0; i<N; i++){
        if(minRecomend > stu[photoCase[i]].recomend){
            minRecomend = stu[photoCase[i]].recomend;
            maxTime = stu[photoCase[i]].time;
            ret = i;
        }
        else if(minRecomend == stu[photoCase[i]].recomend){
            if(maxTime < stu[photoCase[i]].time){
                maxTime = stu[photoCase[i]].time;
                ret = i;
            }
        }
    }
    return ret;
}
int main(){
    cin>>N>>T;
    while(T--){
        int number;
        cin>>number;
        if(cnt<N){
            int idx = findStuIdx(number);
            if(idx == -1){
                photoCase[cnt++] = number;
                stu[number].recomend = 1;
                stu[number].time = T;
            }
            else
                stu[photoCase[idx]].recomend += 1;
        }
        else{
            int res = findStuIdx(number);
            if(res == -1){
                int idx = getDelStuIdx();
                stu[photoCase[idx]].recomend = 0;
                stu[photoCase[idx]].time = 0;
                stu[number].recomend = 1;
                stu[number].time = T;
                photoCase[idx] = number;
            }
            else{
                stu[photoCase[res]].recomend += 1;
            }
        }
    }
    sort(photoCase,photoCase+cnt);
    for(int i=0; i<cnt; i++)
        cout<<photoCase[i]<<" ";
    return 0;
}