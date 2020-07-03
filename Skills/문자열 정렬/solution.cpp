#include<iostream>
#include<cstring>
using namespace std;

char arr[101][101];
char tmp[101][101];

bool comp(char* a1, char* a2){
    int len1 = strlen(a1);
    int len2 = strlen(a2);
    if(len1 == len2){
        for(int i=0; i<len1; i++){
            if(a1[i] != a2[i]){
                return a1[i] < a2[i];
            }
        }
        return false;
    }
    else {
        return len1 < len2;
    }
}

void sort(int start, int end){
    if(start >= end) return;

    int i,j,k,mid;
    mid = (start+end)/2;
    i = start, j = mid+1; k = start;

    sort(start,mid);
    sort(mid+1,end);

    while(i<=mid && j<=end){
        if(comp(arr[i], arr[j]))
            strcpy(tmp[k++], arr[i++]);
        else
            strcpy(tmp[k++], arr[j++]);
    }
    while(i<=mid){
        strcpy(tmp[k++], arr[i++]);
    }
    while(j<=end){
        strcpy(tmp[k++], arr[j++]);
    }
    for(int i=start; i<=end; i++){
        strcpy(arr[i], tmp[i]);
    }
}

int main(){
    int N;
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>arr[i];
    }
    sort(0,N-1);
    for(int i=0; i<N; i++){
        cout<<arr[i]<<endl;
    }
    return 0;
}