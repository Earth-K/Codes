#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <cmath>

using namespace std;

void permutation(string& numbers, int idxNow, int k, int cntSelectedNum, vector<int>& ansPrimeNumbers);
int getInt(string strNum);
bool isPrimeNum(int num);

set<int> checkSet;
vector<int> ansPrimeNumbers;

int solution(string numbers) {
    for(int k=1; k<=numbers.length(); k++){
        permutation(numbers,0, k, 0, ansPrimeNumbers);
    }
    return ansPrimeNumbers.size();
}

void permutation(string& numbers, int idxNow, int k, int cntSelectedNum, vector<int>& ansPrimeNumbers){
    if(cntSelectedNum == k){
        int num = getInt(numbers.substr(0,k));
        if(checkSet.find(num) == checkSet.end()){
            checkSet.insert(num);
            if(isPrimeNum(num))
                ansPrimeNumbers.push_back(num);
        }
        return;
    }
    
    for(int i=idxNow ; i<numbers.length() ;i++){
        swap(numbers[i], numbers[idxNow]);
        permutation(numbers, idxNow+1, k, cntSelectedNum+1, ansPrimeNumbers);
        swap(numbers[i], numbers[idxNow]);
    }
}
int getInt(string strNum){
    int ret = 0;
    for(int i=0; strNum[i] ; i++){
        ret = (ret*10) + strNum[i]-'0';
    }
    return ret;
}
bool isPrimeNum(int num){
    if(num == 1 || num == 0) return false;
    for(int i=2; i<=sqrt(num); i++){
        if(num%i == 0)
            return false;
    }
    return true;
}