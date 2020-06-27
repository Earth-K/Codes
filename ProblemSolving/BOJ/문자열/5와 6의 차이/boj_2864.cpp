#include<iostream>
#include<string>
using namespace std;
int main(){
    string A,B,a_min,a_max,b_min,b_max;
    cin>>A>>B;
    for(int i=0; i<A.size(); i++){
        if(A[i] == '5' || A[i] == '6'){
            a_min += '5';
            a_max += '6';
        }
        else{
            a_min += A[i];
            a_max += A[i];
        }
    }
    for(int i=0; i<B.size(); i++){
        if(B[i] == '5' || B[i] == '6'){
            b_min += '5';
            b_max += '6';
        }
        else{
            b_min += B[i];
            b_max += B[i];
        }
    }
    cout<<atoi(a_min.c_str()) + atoi(b_min.c_str())<<" ";
    cout<<atoi(a_max.c_str()) + atoi(b_max.c_str());
    return 0;
}