#include<iostream>
#include<vector>
using namespace std;

vector<int> xList[10001];
struct Node{
    int parent,n,left,right;
}tree[10001];

int cnt;

void inOrder(int v, int level){
    if(tree[v].left == 0 && tree[v].right == 0)
        return;

    inOrder(tree[v].left, level+1);
    xList[level].push_back(++cnt);
    inOrder(tree[v].right, level+1);
}

int main(){
    int N;
    cin>>N;
    for(int i=1; i<=N; i++)
        tree[i].parent = -1;
    for(int i=0,v,l,r; i<N; i++){
        cin>>v>>l>>r;
        tree[v].left = l;
        tree[v].right = r;
        tree[l].parent = v;
        tree[r].parent = v;
    }
    int root;
    for(int i=1; i<=N; i++){
        if(tree[i].parent == -1)
            root = i;
    }
    inOrder(root,1);

    int maxLen = 0;
    int minLevel = 987654321;
    for(int i=N; i>=1; i--){
        if(xList[i].size() == 0)
            continue;
        int lastIdx=xList[i].size()-1;
        int len = xList[i][lastIdx] - xList[i][0] + 1;
        if(maxLen <= len){
            minLevel = i;
            maxLen = len;
        }
    }
    cout<<minLevel<<" "<<maxLen;
    return 0;
}