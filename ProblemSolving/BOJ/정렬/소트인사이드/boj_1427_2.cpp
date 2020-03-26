#include<iostream>
#include<vector>
#include<string>
using namespace std;

int arr[10];
int temp[10];

bool cmp(const int& a, const int& b){
    return a>b;
}

void merge(int s, int e){
    if(s>=e) return;

    int mid = (s+e)>>1;
    int i=s, j=mid+1, k=s;

    merge(s,mid);
    merge(mid+1,e);

    while(i<=mid && j<=e){
        if(cmp(arr[i],arr[j]))
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];        
    }
    while(i<=mid)   temp[k++] = arr[i++];
    while(j<=e)     temp[k++] = arr[j++];

    for(int i=s; i<=e; i++)
        arr[i] = temp[i];
}

string N;
int main(){
    cin>>N;
    for(int i=0; i<N.size(); i++){
        arr[i] = N[i]-'0';
    }

    merge(0,N.size()-1);

    for(int i=0; i<N.size(); i++)
        cout<<arr[i];

     return 0;
}