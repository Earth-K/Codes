#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int answer;

bool check(string &S){
    for(int i=0; i<S.size()-1; i++){
        if(S[i] == S[i+1])
            return false;
    }
    return true;
}

int main(){
    string S;
    cin>>S;

    sort(S.begin(),S.end());
    do{
        if(check(S))
            answer += 1;
    }while(next_permutation(S.begin(), S.end()));

    cout<<answer;
     return 0;
}