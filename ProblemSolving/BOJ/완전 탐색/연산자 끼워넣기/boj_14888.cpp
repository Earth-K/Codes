#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int N, arr[11];

pair<int,int> findAnswer(int idx, int cur, int plus, int minus, int mul, int div){
    if(idx == N){
        return {cur, cur};
    }
    vector<pair<int,int>> answer;
    if(plus>0)
        answer.push_back(findAnswer(idx+1, cur+arr[idx], plus-1, minus, mul, div));
    if(minus>0)
        answer.push_back(findAnswer(idx+1, cur-arr[idx], plus, minus-1, mul, div));
    if(mul>0)
        answer.push_back(findAnswer(idx+1, cur*arr[idx], plus, minus, mul-1, div));
    if(div>0)
        answer.push_back(findAnswer(idx+1, cur/arr[idx], plus, minus, mul, div-1));

    int minNum = 1000000001, maxNum = -minNum;
    for(int i=0; i<answer.size(); i++){
        maxNum = max(maxNum, answer[i].first);
        minNum = min(minNum, answer[i].second);
    }
    return {maxNum, minNum};
}

int main(){
    cin>>N;
    for(int i=0; i<N ;i++)
        cin >> arr[i];
    int plus,minus,mul,div;
    cin>>plus>>minus>>mul>>div;

    pair<int,int> answer = findAnswer(1,arr[0],plus,minus,mul,div);
    cout<<answer.first<<endl;
    cout<<answer.second<<endl;
    return 0;
}