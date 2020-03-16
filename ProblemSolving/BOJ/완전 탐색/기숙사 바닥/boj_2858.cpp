#include<iostream>
using namespace std;
int R, B;
int main(){
    cin>>R>>B;
    bool flag = false;
    for(int L=3; L<=2000000; L++){
        for(int W=1; W<=L; W++){
            if(R+B < W*L) break;
            if(2*L+2*W-4 == R){
                cout<<L<<' '<<W;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    return 0;
}