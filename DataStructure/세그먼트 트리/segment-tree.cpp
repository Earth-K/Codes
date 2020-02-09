#include<iostream>
#include<cmath>
using namespace std;
long long *tree;
long long A[10] = {1,2,3,4,5,6,7,8,9,10};

void update(int changed_idx, int diff, int index, int start, int end){
    
    if(changed_idx<start || end<changed_idx)
        return;

    tree[index] += diff;

    if(start == end)
        return;

    int mid = (start+end)>>1;
    update(changed_idx, diff, index*2+1, start, mid);
    update(changed_idx, diff, index*2+2, mid+1, end);
}

long long sum(int index, int start, int end, int left, int right){
    if(left>end || end<right)
        return 0;
    else if(start <= left && right <= end){
        return tree[index];
    }
    else{
        int mid = (left+right)>>1;
        return sum(index*2+1, start, mid, left, right) + sum(index*2+2, mid+1, end, left, right);
    }
}

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
    tree = new long long[1<<(h+1)]; //트리 크기 2^(h+1)
    for(int i=0; i<1<<(h+1); i++){
        tree[i] = -1;
    }

    cout<<"h : "<<(1<<(h+1))<<endl<<endl;

    init(0,0,N-1);
    
    for(int i=0; i< (1<<(h+1)); i++){
        cout<<tree[i]<<"\n";
    }

    cout<<"sum 0 to N-1 : "<<sum(0,0,N-1,0,N-1)<<endl<<endl;
    
    int num = 6;
    update(0,num-A[0],0,0,N-1);

    cout<<"sum 0 to N-1 : "<<sum(0,0,N-1,0,N-1)<<endl<<endl;
    return 0;
}