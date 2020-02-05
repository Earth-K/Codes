#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;

int N, M, answer=987654321;
bool brokenNum[10];

int main(){
    cin>>N>>M;
    for(int i=0,n; i<M ;i++){
        cin>>n;
        brokenNum[n] = true;
    }

    answer = abs(100-N);
    
    for(int num=0; num<=999999; num++){
        string strNum = to_string(num);
        bool flag = true;
        for(int i=0; i<strNum.size(); i++){
            if(brokenNum[strNum[i]-'0'])
                flag=false;
        }
        if(!flag) continue;

        int cnt = strNum.size();
        answer = min(answer, cnt+abs(N-num));
    }

    cout<<answer;
    return 0;
}