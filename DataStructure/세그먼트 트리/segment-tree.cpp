#include<iostream>
#include<cmath>
using namespace std;
long long *tree;
long long A[10] = {1,2,3,4,5,6,7,8,9,10};
long long init(int index, int start, int end){
    if(start == end)
        tree[index] = A[start];
    else{
        int mid = (start+end)/2;
        tree[index] = init(index*2+1, start, mid) + init(index*2+2, mid+1, end);
    }
    return tree[index];
}
int main(){
    int N = 10;
    int h = ceil(log2(N));//long(N) == 3.xxx
    tree = new long long[1<<(h+1)];
    for(int i=0; i<1<<(h+1); i++){
        tree[i] = -1;
    }
    cout<<(1<<(h+1))<<endl<<endl;
    init(0,0,N-1);
    for(int i=0; i< (1<<(h+1)); i++){
        cout<<tree[i]<<"\n";
    }

    return 0;
}