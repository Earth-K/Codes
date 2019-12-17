#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;
    for(int w=1; w<=5000 ; w++){
        for(int h=1; h<=5000; h++){
            if(w < h)   break;
            if(brown == w*2+h*2-4 && red == w*h-brown){
                answer.push_back(w);
                answer.push_back(h);
                return answer;
            }
        }
    }
    return answer;
}