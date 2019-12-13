#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    int cntErasedNum = 0;
    while(cntErasedNum != k) {
        bool flagFind = false;
        for(auto it = number.begin(); it < number.end(); it++){
            if(*it < *(it+1)){
                number.erase(it);
                flagFind = true;
                break;
            }
        }
        if(flagFind == false)
            number.erase(number.end()-1);
        
        cntErasedNum++;
    }
    return number;
}