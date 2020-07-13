#include<iostream>
using namespace std;
int R,C,ZR,ZC;
char map[51][51];
int main(){
    cin>>R>>C>>ZR>>ZC;
    for(int i=0; i<R; i++){
        cin>>map[i];
    }
    for(int i=0; i<R; i++){
        for(int q=0; q<ZR; q++){
            for(int j=0; j<C; j++){
                for(int k=0; k<ZC; k++)
                    cout<<map[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}