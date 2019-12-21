#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int calcAnswer(vector<int>& energy);

int main(){
    int N;
    cin >> N;
    vector<int> energy(N);
    for(int i=0,e; i<N ;i++)
        cin>>energy[i];
    cout<<calcAnswer(energy)<<endl;
    return 0;
}

int calcAnswer(vector<int>& energy){
    int N = energy.size();
    if( N == 2)
        return 0;

    int answer = 0;
    for(int i=1; i<N-1; i++){
        int sum = energy[i-1] * energy[i+1];
        vector<int> vt(energy);
        vt.erase(vt.begin()+i);
        sum += calcAnswer(vt);
        answer = max(sum,answer);
    }

    return answer;
}