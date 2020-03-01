#include<iostream>
#include<vector>
#define MAX_SIZE 100000
using namespace std;

int n;
vector<int> tree(MAX_SIZE*4, 0);
vector<int> arr(MAX_SIZE+1, 0);

int update(int node, int begin, int end, int target, int val){
    if(target<begin || end<target)
        return tree[node];
    if(begin == end)
        return tree[node] = val;

    int mid = (begin+end)>>1;
    return tree[node] = update(node*2, begin, mid, target, val) + update(node*2+1, mid+1, end, target, val);
}
int query(int node, int begin, int end, int val){
    if(begin == end)
        return begin;
    
    int mid = (begin+end)>>1;
    if(tree[node*2] >= val)
        return query(node*2,begin,mid,val);
    else
        return query(node*2+1,mid+1,end,val-tree[node*2]);    
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1; i<=n ;i++)
        update(1,1,n,i,1);
    for(int i=1,p; i<=n; i++){
        cin>>p;
        int idx = query(1,1,n,p+1);
        arr[idx]=i;
        update(1,1,n,idx,0);
    }
    for(int i=1; i<=n; i++)
        cout<<arr[i]<<'\n';
     return 0;
}