#include <string>
#include <cmath>
#include <vector>
using namespace std;

int solution(string dartResult) {
    int answer = 0;
    vector<int> vt;
    
    int pos = 0;
    while(pos < dartResult.size()){
        int num = dartResult[pos]-'0';
        if(dartResult[pos+1] == '0'){
            num = 10;
            pos += 1;
        }
        
        if(dartResult[pos+1] == 'T'){
            num = pow(num,3);
        }else if(dartResult[pos+1] == 'D'){
            num = pow(num,2);
        }
        
        if(dartResult[pos+2] == '#'){
            num = -num;
            pos += 3;
        }
        else if(dartResult[pos+2] == '*'){
            if(!vt.empty())
                vt[vt.size()-1] *= 2;
            num *= 2;
            pos += 3;
        }
        else{
            pos += 2;
        }
        vt.push_back(num);
    }
    
    for(int i=0; i<vt.size(); i++){
        answer += vt[i];
    }
    return answer;
}