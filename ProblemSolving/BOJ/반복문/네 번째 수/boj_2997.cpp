#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int a, b, c, sub;
    cin>>a>>b>>c;
    int arr[3] = {a,b,c};
    sort(arr,arr+3);
    int d1 = arr[1] - arr[0];
    int d2 = arr[2] - arr[1];
    int ans;
    if(d1 == d2){
        ans=arr[2]+d1;
    }
    else{
        if(d1 < d2){
            ans=arr[1]+d1;
        }
        else{
            ans=arr[0]+d2;
        }
    }
    cout<<ans;
    return 0;
}