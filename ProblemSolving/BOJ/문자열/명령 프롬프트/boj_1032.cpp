#include<iostream>
#include<string>
using namespace std;

string fileNames[50];

int main(){
    int n,len;
    cin>>n>>fileNames[0];

    len = fileNames[0].length();
    for(int r=1; r<n; r++){
        cin>>fileNames[r];
        for(int c=0; c<len; c++){
             if(fileNames[r][c] != fileNames[0][c])
                fileNames[0][c] = '?';
        }
    }
    cout<<fileNames[0];
    return 0;
}