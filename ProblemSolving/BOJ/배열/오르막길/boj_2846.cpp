#include<iostream>
#include<vector>
using namespace std;
int main(){
    int N;
    vector<int> vt;
    cin>>N;
    for(int i=0,n; i<N; i++){
        cin>>n;
        vt.push_back(n);
    }
    int sum = 0;
    int answer = 0;
    int pre = vt[0];
    for(int i=1; i<vt.size(); i++){
        if(pre < vt[i]){
            sum += vt[i] - pre;
            if(answer < sum)
                answer = sum;
        }
        else{
            sum = 0;
        }
        pre = vt[i];
    }
    cout<<answer;
    return 0;
}