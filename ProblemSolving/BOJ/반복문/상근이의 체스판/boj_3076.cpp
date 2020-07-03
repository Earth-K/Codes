#include<iostream>
using namespace std;
char map[100][101];
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    int R,C,A,B;
    cin>>R>>C>>A>>B;
    for(int r=0;r<R*A; r+=A){
        for(int c=0; c<C*B; c+=B){
            if((r/A)%2 == 0){
                for(int i=r; i<r+A; i++){
                    for(int j=c; j<c+B; j++){                            
                        if((c/B)%2 == 0){
                            map[i][j] = 'X';
                        }
                        else{
                            map[i][j] = '.';
                        }
                    }
                }        
            }
            else{
                for(int i=r; i<r+A; i++){
                    for(int j=c; j<c+B; j++){                            
                        if((c/B)%2 == 1){
                            map[i][j] = 'X';
                        }
                        else{
                            map[i][j] = '.';
                        }
                    }
                }       
            }
        }
    }
    for(int i=0; i<R*A; i++){
        for(int j=0; j<C*B; j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
    return 0;
}