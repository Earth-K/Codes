#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void comb(vector<int> &vt, int target, vector<int> &answer){
    
    if(answer.size() == 7){
        int sum = 0;
        for(int n: answer)
            sum += n;
            
        if(sum == 100){
            sort(answer.begin(), answer.end());
            for(int n : answer)
                cout<<n<<endl;
        }
        return;
    }

    if(target == vt.size())
        return;

    answer.push_back(vt[target]);
    comb(vt, target+1, answer);
    answer.pop_back();
    comb(vt, target+1, answer);
}

int main(){
    vector<int> vt, answer;
    for(int i=0,n; i<9; i++){
        cin>>n;
        vt.push_back(n);
    }
    comb(vt, 0, answer);
    return 0;
}