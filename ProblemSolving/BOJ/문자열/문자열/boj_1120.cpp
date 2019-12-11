#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    int ans = 50;
    string A,B;
    cin>>A>>B;
    int diff = B.length() - A.length();
    for(int posB=0; posB<=diff; posB++){
        int cnt = 0;
        for(int posA = 0; posA < A.length(); posA++){
            if(A[posA] != B[posB+posA])
                cnt++;
        }
        ans = min(ans, cnt);
    }
    cout<<ans;
    return 0;
}