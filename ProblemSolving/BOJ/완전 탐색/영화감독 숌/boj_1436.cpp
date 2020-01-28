#include<iostream>
#include<string>
using namespace std;
int main(){
    int N, cnt = 0;
    cin >> N;

    int num = 665;
    while(cnt != N){
        string n = to_string(++num);
        int numSix = 0;
        for(int i=0; n[i]; i++){
            if(n[i] == '6')
                numSix++;
            else
                numSix = 0;
            
            if(numSix==3){
                cnt++;
                break;
            }
        }
    }
    cout<<num<<endl;
    return 0;
}