#include<iostream>
#include<string>
#include<vector>
using namespace std;
int N;
string input;
char A[10][11];
vector<int> ans;
bool endFlag;

bool check(vector<int> &ans){
    int size = ans.size();
    for(int i=0; i<size; i++){
        int sum = 0;
        for(int j=i; j<size; j++)
            sum += ans[j];
        if(sum == 0 && A[i][size-1] != '0') return false;
        if(sum < 0 && A[i][size-1] != '-') return false;
        if(sum > 0 && A[i][size-1] != '+') return false;
    }
    return true;
}
void solve(vector<int> &ans){
    if(endFlag)
        return;

    if(ans.size() == N){
        for(int n : ans)
            cout<<n<<' ';
        endFlag = true;
        return;
    }

    for(int num = -10 ; num<=10; num++){
        ans.push_back(num);
        if(check(ans)) 
            solve(ans);
        ans.pop_back();
    }
}

int main(){
    cin>>N>>input;
    int idx = 0;
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            A[i][j] = input[idx++];
        }
    }
    solve(ans);
     return 0;
}