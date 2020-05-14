#include<iostream>
using namespace std;
double factorial(int n){
    if(n == 0) return 1;
    return n * factorial(n-1);
}
double calc(int n){
    double ret = 0;
    for(int i=0; i<=n; i++)
        ret += 1/factorial(i);
    return ret;
}
int main(){
    printf("n e\n");
    printf("- -----------\n");
    for(int n=0; n<=9; n++){
        printf("%d ",n);
        if     (n==0) printf("1");
        else if(n==1) printf("2");
        else if(n==2) printf("2.5");
        else          printf("%.9f",calc(n));
        printf("\n");
    }
    return 0;
}