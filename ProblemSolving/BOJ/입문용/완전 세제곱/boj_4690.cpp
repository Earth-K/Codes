#include<iostream>
#include<cmath>
using namespace std;
int main(){
    for(int a=2; a<=100; a++){
        int A = a*a*a;
        for(int b=2; b<a; b++){
            for(int c=b+1; c<a; c++){
                for(int d=c+1; d<a; d++){
                    if(A == b*b*b + c*c*c + d*d*d){
                        cout<<"Cube = "<<a<<", Triple = ("<<b<<","<<c<<","<<d<<")"<<"\n";
                    }
                }
            }
        }
    }
    return 0;
}