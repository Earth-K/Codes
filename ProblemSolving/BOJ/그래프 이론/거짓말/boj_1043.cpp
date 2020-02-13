#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N,M,K;
vector<int> party[51], people[51], know;
bool visited[51];
queue<int> Q;

int main(){
    cin>>N>>M>>K;
    for(int i=0,n; i<K; i++){
        cin>>n;
        know.push_back(n);
    }
    for(int i=0; i<M; i++){
        cin>>K;
        while(K--){
            int n;
            cin>>n;
            party[i].push_back(n);
            people[n].push_back(i);
        }
    }
    for(int num: know){
        for(int i=0; i<people[num].size(); i++){
            int connPartyNum = people[num][i];
            if(!visited[connPartyNum]){
                visited[connPartyNum] = true;
                Q.push(connPartyNum);
            }
        }
    }
    while(!Q.empty()){
        int nowParty = Q.front();
        Q.pop();

        for(int connPersonNum: party[nowParty]){
            for(int i=0; i<people[connPersonNum].size(); i++){
                int connPartyNum = people[connPersonNum][i];
                if(!visited[connPartyNum]){
                    visited[connPartyNum] = true;
                    Q.push(connPartyNum);
                }
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<M; i++)
        if(!visited[i])
            cnt++;
    cout<<cnt;
     return 0;
}