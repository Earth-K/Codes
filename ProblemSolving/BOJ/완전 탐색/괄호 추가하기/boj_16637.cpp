#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

vector<int> nums;
vector<char> ops;
long long answer = LLONG_MIN;
long long calc(char op, long long n1, long long n2){
    if(op == '+')
        return n1+n2;
    else if(op == '-')
        return n1-n2;
    else
        return n1*n2;
}
void solve(long long result, int nowOpIdx){
    if(nowOpIdx >= ops.size()){
        if(answer < result)
            answer = result;
        return;
    }
    long long res1 = calc(ops[nowOpIdx], result, nums[nowOpIdx+1]);
    solve(res1, nowOpIdx+1);
    
    if(nowOpIdx+1 < ops.size()){
        long long res2 = calc(ops[nowOpIdx+1], nums[nowOpIdx+1], nums[nowOpIdx+2]);
        solve(calc(ops[nowOpIdx],result,res2), nowOpIdx+2);
    }
}

int main(){
    int N;
    string str;
    cin >> N >> str;
    for(int i=0; str[i] ;i++){
        if(str[i] == '+' || str[i] == '-' || str[i] == '*')
            ops.push_back(str[i]);
        else
            nums.push_back(str[i]-'0');
    }
    solve(nums[0],0);
    cout<<answer<<endl;
    return 0;
}