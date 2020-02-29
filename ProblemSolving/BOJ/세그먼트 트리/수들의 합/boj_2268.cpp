#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
int n,m;

void update(vector<ll> &tree, int node, int begin, int end, int a, int diff){
    if(a<begin || end<a)
        return;

    tree[node] += diff;

    if(begin != end){
        int mid = (begin+end)>>1;
        update(tree, node*2, begin, mid, a, diff);
        update(tree, node*2+1, mid+1, end, a, diff);
    }
}
ll sum(vector<ll> &tree, int node, int begin, int end, int a, int b){
    if(end<a || b<begin){
        return 0;
    }
    else if(a<=begin && end<=b){
        return tree[node];
    }
    else{
        int mid = (begin+end)>>1;
        return sum(tree, node*2, begin,mid, a, b)+sum(tree, node*2+1, mid+1,end, a, b);
    }
}
vector<int> arr(1000001,0);

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;

    vector<ll> tree(n*4+10);
    for(int i=0,type,a,b; i<m; i++){
        cin>>type>>a>>b;
        if(type == 1){//modify
            int diff = b-arr[a];
            arr[a] += diff;
            update(tree, 1, 1,n, a, diff);  
        }
        else{//sum
            if(a>b)
                swap(a,b);
            cout<<sum(tree,1,1,n,a,b)<<'\n';
        }
    }
    return 0;
}