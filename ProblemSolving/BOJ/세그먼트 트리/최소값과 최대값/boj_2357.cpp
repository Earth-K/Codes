#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int N,M;
long long *treeMax, *treeMin;
int arr[100000];

long long initMax(int start, int end, int idx, long long *tree){
    if(start == end){
        tree[idx] = arr[start];
    }
    else{
        int mid = (start+end)>>1;
        tree[idx] = max(initMax(start,mid, idx*2+1,tree),initMax(mid+1,end, idx*2+2,tree));
    }
    return tree[idx];
}

long long initMin(int start, int end, int idx, long long *tree){
    if(start == end){
        tree[idx] = arr[start];
    }
    else{
        int mid = (start+end)>>1;
        tree[idx] = min(initMin(start,mid, idx*2+1,tree),initMin(mid+1,end, idx*2+2,tree));
    }
    return tree[idx];
}

long long query(int idx, int start, int end, int a, int b, long long *tree){
    if(end<a || b<start){
        if(tree == treeMin)
            return 1000000001;
        else
            return 0;        
    }
    else if(a <= start && end <= b){
        return tree[idx];
    }
    else{
        int mid = (start+end)>>1;
        if(tree == treeMin)
            return min(query(idx*2+1, start, mid, a, b, tree), query(idx*2+2, mid+1, end, a, b, tree));
        else
            return max(query(idx*2+1, start, mid, a, b, tree), query(idx*2+2, mid+1, end, a, b, tree));
    }
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>N>>M;
    for(int i=0; i<N; i++)
        cin>>arr[i];

    int h = ceil(log2(N));
    treeMax = new long long [1<<(h+1)];
    treeMin = new long long [1<<(h+1)];
    for(int i=0; i<(1<<(h+1)); i++){
        treeMax[i] = -1;
        treeMin[i] = -1;
    }
    initMax(0,N-1,0,treeMax);
    initMin(0,N-1,0,treeMin);

    for(int i=0,a,b; i<M; i++){
        cin>>a>>b;
        cout<<query(0,0,N-1,a-1,b-1,treeMin)<<' '<<query(0,0,N-1,a-1,b-1,treeMax)<<endl;
    }
     return 0;
}