#include<iostream>
#include<vector>
using namespace std;
bool used[1001];
int main(){
    vector<int> vt;
    int answer = 0;
    for(int i=0,n; i<10; i++){
        cin>>n;
        vt.push_back(n%42);
        if(used[n%42] == false){
            used[n%42] = true;
            answer += 1;
        }
    }
    cout<<answer;
    return 0;
}