#include<iostream>
#include<deque>
#include<vector>
#include<cmath>
using namespace std;
int tc,N,M;
vector<int> tree, arr;
void update(int idx, int begin, int end, int i, int diff){
    if(i<begin || end<i)
        return;

    tree[idx] += diff;

    if(begin != end){
        int mid = (begin+end)>>1;
        update(idx*2, begin, mid, i, diff);
        update(idx*2+1, mid+1, end, i, diff);
    }
}
int sum(int idx, int begin, int end, int left, int right){
    if(end < left || right < begin){
        return 0;
    }
    else if(left <= begin &&end <= right){
        return tree[idx];
    }
    else{
        int mid = (begin+end)>>1;
        return sum(idx*2, begin, mid, left, right) + sum(idx*2+1, mid+1, end, left, right);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> tc;
    while(tc--){
        cin>>N>>M;
        int h = ceil(log2(N+M))+1;
        tree = vector<int>((1<<h)+10);
        arr = vector<int>(N+M+10);

        for(int i=M+1; i<=N+M; i++){
            update(1, 1, N+M, i, 1);
            arr[i-M] = i;
        }

        int idx = M;
        for(int i=0,n; i<M; i++){
            cin>>n;
            cout<< sum(1, 1,N+M, 1,arr[n]-1)<<' ';
            update(1, 1,N+M, arr[n], -1);
            arr[n] = idx--;
            update(1, 1,N+M, arr[n], 1);
        }
        cout<<'\n';
    }
     return 0;
}