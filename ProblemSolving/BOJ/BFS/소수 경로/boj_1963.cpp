#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
int T;
string a,b;
int visited[10000];
bool isPrime(string n){
    int num = atoi(n.c_str());
    for(int i=2; i<=sqrt(num); i++){
        if(num%i == 0)
            return false;
    }
    return true;
}
void solve(string a, string b){
    queue<string> Q;
    Q.push(a);
    visited[atoi(a.c_str())] = true;
    int cnt = 0;
    while(!Q.empty()){
        int size = Q.size();
        while(size--){
            string cur = Q.front(); Q.pop();
            if(cur.compare(b) == 0){
                cout<<cnt<<endl;
                return;
            }
            for(int i=0; i<4; i++){
                for(int j=0; j<=9; j++){
                    string tmp(cur);
                    tmp[i] = '0' + j;
                    int nextN = atoi(tmp.c_str());
                    if(nextN > 1000 && visited[nextN] == false && isPrime(tmp)){
                        Q.push(tmp);
                        visited[nextN] = true;
                    }
                }
            }
        }
        cnt += 1;
    }

    cout<<"Impossible"<<endl;
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>T;
    while(T--){
        cin>>a>>b;
        memset(visited,0,sizeof(visited));
        solve(a,b);
    }
     return 0;
}