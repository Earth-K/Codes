#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string N;

int main(){ 
    cin>>N;
    sort(N.begin(), N.end());
    reverse(N.begin(), N.end());
    cout<<N;
    return 0;
}