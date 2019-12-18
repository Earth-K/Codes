#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    int end = prices.size();
    
    for(int begin=0; begin<end; begin++){
        int cntBigger = 0;
        for(int now = begin+1; now<end; now++){
            if(prices[begin] <= prices[now]){
                cntBigger++;
            }
            else{
                cntBigger++;
                break;
            }
        }
        answer.push_back(cntBigger);
    }
    
    return answer;
}