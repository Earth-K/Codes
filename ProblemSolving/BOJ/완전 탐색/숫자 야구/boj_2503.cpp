#include<iostream>
#include<string>
using namespace std;

bool check[1000];
int main(){
    int N, input, strike, ball, cntStrike, cntBall, answer;
    answer=0;
    cin>>N;
    while(N--){
        cin>>input>>strike>>ball;
        string strInput = to_string(input);

        for(int n=123; n<=987; n++){
            string strNum = to_string(n);
            if(strNum[0] == '0' || strNum[1] == '0' || strNum[2]=='0')
                continue;
            if(strNum[0] == strNum[1] || strNum[0] == strNum[2] || strNum[1] == strNum[2])
                continue;

            cntStrike = cntBall = 0;
            for(int i=0; i<strInput.size(); i++){
                for(int j=0; j<strNum.size(); j++){
                    if(strInput[i] == strNum[j]){
                        if(i==j)
                            cntStrike += 1;
                        if(i!=j)
                            cntBall += 1;
                    }
                }
            }
            if(strike != cntStrike || ball != cntBall)
                check[n] = true;
        }
    }

    for(int n=123; n<=987; n++){
        string strNum = to_string(n);
        if(strNum[0] == '0' || strNum[1] == '0' || strNum[2]=='0')
                continue;
        if(strNum[0] == strNum[1] || strNum[0] == strNum[2] || strNum[1] == strNum[2])
            continue;

        if(!check[n])
            answer += 1;
    }

    cout<<answer;
    return 0;
}