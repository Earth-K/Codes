#include<iostream>
#include<vector>
#define MAX_SIZE 100000
using namespace std;
int n;
vector<int> tree(MAX_SIZE*4);
vector<int> arr(MAX_SIZE+1);
vector<int> ans(MAX_SIZE+1);
int update(int idx, int begin, int end, int target, int val){
    if(target<begin || end<target)
        return tree[idx];

    if(begin == end)
        return tree[idx] = val;

    int mid = (begin+end)>>1;
    return tree[idx] = update(idx*2+1,mid+1,end,target,val) + update(idx*2,begin,mid,target,val);
}
int query(int idx, int begin, int end, int val){
    if(begin==end)
        return begin;

    int mid = (begin+end)>>1;
    if(tree[idx*2+1] >= val)
        return query(idx*2+1, mid+1, end, val);
    else
        return query(idx*2, begin, mid, val-tree[idx*2+1]);    
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    for(int i=1; i<=n; i++)
        update(1,1,n,i,1);

    for(int i=n; i>=1; i--){
        int idx = query(1,1,n,arr[i]+1);
        ans[idx] = i;
        update(1,1,n,idx,0);
    }
    for(int i=1; i<=n; i++)
        cout<<ans[i]<<' ';
     return 0;
}