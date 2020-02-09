#include<iostream>
using namespace std;

int N, K, parent[50];
bool haveChild[50];
bool find(int p, int node){
    if(p == node) return true;
    if(p == -1) return false;

    return find(parent[p], node);
}
int main(){
    for(int i=0; i<N; i++)
        parent[i] = -1;

    cin>>N;
    for(int i=0, node; i<N; i++){
        cin>>node;
        parent[i] = node;
        if(node != -1)
            haveChild[node] = true;
    }

    cin>>K;
    int cnt = 0;
    
    for(int i=0; i<N ;i++){
        if(parent[i] == parent[K])
            cnt++;
    }
    if(cnt == 1)
        haveChild[parent[K]] = false;

    haveChild[K] = true;
    for(int i=0; i<N ;i++){
        if(find(i,K))
            haveChild[i] = true;
    }
    int answer = 0;
    for(int i=0; i<N; i++){
        if(haveChild[i] == false)
            answer++;
    }
    cout<<answer;
    return 0;
}