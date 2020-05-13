#include<iostream>
using namespace std;
int calc(int n, int base){
    int ret = 0;
    while(n){
        ret += n % base;
        n /= base;
    }
    return ret;
}
int main(){
    for(int n=1000; n<=9999; n++){
        int a = calc(n,10);
        int b = calc(n,12);
        int c = calc(n,16);
        if(a==b && b==c)
            cout<<n<<"\n";
    }
    return 0;
}