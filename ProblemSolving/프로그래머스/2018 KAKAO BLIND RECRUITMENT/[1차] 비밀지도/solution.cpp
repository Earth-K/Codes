#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <cmath>

using namespace std;
string getBinaryNum(int n, int num){
    string ret = "";
    int k = n-1;
    while(k>=0){
        int r = pow(2,k);
        if(r <= num){
            ret += '#';
            num -= r;
        }
        else{
            ret += ' ';
        }
        k--;
    }
    return ret;
}
vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for(int i=0; i<arr1.size(); i++){
        string str1 = getBinaryNum(n, arr1[i]);
        string str2 = getBinaryNum(n, arr2[i]);
        string res = "";
        for(int j=0; j<n; j++){
            if(str1[j]=='#' || str2[j]=='#')
                res += '#';
            else
                res += ' ';
        }
        answer.push_back(res);
    }
    return answer;
}