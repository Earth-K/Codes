#include<iostream>
#include<vector>
#define MAX_SIZE 1000000
using namespace std;
int n;
vector<int> tree(MAX_SIZE*4+10);

void update(int node, int begin, int end, int b, int diff){
    if(b<begin || end<b)
        return;

    tree[node] += diff;
    if(begin != end){
        int mid = (begin+end)>>1;
        update(node*2, begin, mid, b, diff);
        update(node*2+1, mid+1, end, b, diff);
    }
}

int query(int node, int begin, int end, int b){
    if(begin == end){
        return begin;
    }
    else{
        int mid = (begin+end)>>1;
        if(tree[node*2] >= b)
            return query(node*2, begin, mid, b);
        else
            return query(node*2+1, mid+1, end, b-tree[node*2]);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin>>n;
    for(int i=0,a,b,c; i<n ;i++){
        cin>>a;
        if(a == 1){
            cin>>b;
            int idx = query(1,1,MAX_SIZE,b);
            cout<<idx<<'\n';
            update(1,1,MAX_SIZE,idx,-1);
        }
        else{
            cin>>b>>c;
            update(1,1,MAX_SIZE,b,c);
        }
    }    
     return 0;
}