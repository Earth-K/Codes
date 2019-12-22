#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void printAnswer(vector<int>& vt, vector<int>& answer, int n, int k, int target);

int main(){
    int k;
    while(true){
        cin>>k;
        if(k == 0)
            break;

        vector<int> vt, answer;
        for(int i=0,n; i<k; i++){
            cin>>n;
            vt.push_back(n);
        }
        printAnswer(vt, answer, k, 6, 0);
        cout<<'\n';
    }
    return 0;
}

void printAnswer(vector<int>& vt, vector<int>& answer, int n, int k, int target){
    if(k == 0){
        for(int i=0; i<answer.size(); i++)
            cout<<answer[i]<<" ";
        cout<<'\n';
        return;
    }
    if(target == n)
        return;

    answer.push_back(vt[target]);
    printAnswer(vt, answer, n, k-1, target+1);
    answer.pop_back();
    printAnswer(vt, answer, n, k, target+1);
}