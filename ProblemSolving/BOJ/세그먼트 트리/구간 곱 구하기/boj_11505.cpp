#include<iostream>
#include<cmath>
#define MOD 1000000007
using namespace std;

int N, M, K;
int arr[1000000];
long long *tree;

long long calcMul(int idx, int begin, int end, int a, int b){
    if(b < begin || end < a)
        return 1;
    if(a <= begin && end <= b)
        return tree[idx];

    int mid = (begin+end)>>1;
    return ((calcMul(idx*2+1, begin, mid, a, b)%MOD) * (calcMul(idx*2+2, mid+1, end, a, b)%MOD))%MOD;
}
long long init(int idx, int begin, int end){
    if(begin == end)
        return tree[idx] = arr[begin];
    else{
        int mid = (begin+end)>>1;
        return tree[idx] = ((init(idx*2+1, begin, mid)%MOD) * (init(idx*2+2, mid+1, end))%MOD)%MOD;
    }
}
long long update(int idx, int a, int b, int begin, int end){
    if(!(begin <= a && a <= end))
        return tree[idx];

    if(begin == end)
        return tree[idx] = b;

    int mid = (begin+end)>>1;
    return tree[idx] = ((update(idx*2+1, a, b, begin, mid)%MOD) * (update(idx*2+2, a, b, mid+1, end)%MOD))%MOD;
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M>>K;
    for(int i=0; i<N; i++)
        cin>>arr[i];

    int h = ceil(log2(N))+1;
    tree = new long long[1<<h];
    init(0,0,N-1);

    for(int i=0,type,a,b; i<M+K; i++){
        cin>>type>>a>>b;
        if(type == 1){//a번째 수를 b로 update
            update(0,a-1,b,0,N-1);
        }
        else{ //a번째부터 b번째까지 수들의 곱 출력
            cout<<calcMul(0,0,N-1,a-1,b-1)<<'\n';
        }
    }
     return 0;
}