#include<iostream>
#include<vector>
using namespace std;

int n,s,arr[20];
int calcAnswer(int idx, int sum);

int main(){
    int answer=0;
    cin>>n>>s;
    for(int i=0; i<n ;i++)
        cin>>arr[i];
    answer = calcAnswer(0,0);
    if(s == 0) answer--;
    cout<<answer<<endl;
    return 0;
}
int calcAnswer(int idx, int sum){
    if(idx == n){
        if(sum == s)
            return 1;
        return 0;
    }

    int ret = 0;
    ret += calcAnswer(idx+1,sum+arr[idx]);
    ret += calcAnswer(idx+1,sum);
    return ret;
}