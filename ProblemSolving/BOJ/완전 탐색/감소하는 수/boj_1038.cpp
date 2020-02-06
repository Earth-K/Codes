#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int N;
vector<int> arr;
void makeArray(int idx){
    if(idx > 1023)
        return;
    if(arr[idx]==987654321)
        return;

    int tailNum = arr[idx]%10;
    for(int i=0; i<tailNum; i++){
        arr.push_back(arr[idx]*10+i);
    }
    makeArray(idx+1);
}
int main(){
    for(int i=0; i<10; i++)
        arr.push_back(i);
    makeArray(0);
    sort(arr.begin(), arr.end());
    cin>>N;
    
    if(N >= 1023){
        cout<<"-1";
    }
    else if(N == 1022){
        cout<<"9876543210";
    }
    else{
        cout<<arr[N];
    }
    return 0;
}