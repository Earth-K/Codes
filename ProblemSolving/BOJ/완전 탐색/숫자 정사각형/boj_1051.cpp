#include<iostream>
using namespace std;
int map[50][50], answer;
bool solve(int r, int c, int size){
    int num = map[r][c];
    if(map[r][c+size] == num && map[r+size][c] == num && map[r+size][c+size] == num)
        return true;
    else
        return false;
}
int main(){
    int N,M,answer;
    
    scanf("%d%d",&N,&M);
    for(int i=0; i<N ;i++)
        for(int j=0; j<M ;j++)
            scanf("%1d",&map[i][j]);
            
    answer = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<M ;j++){
            int size = 1;
            while(i+size<N && j+size<M){
                if(solve(i,j,size)){
                    if(answer < (size+1)*(size+1))
                        answer = (size+1)*(size+1);
                }
                size++;
            }
        }
    }
    cout<<answer;
    return 0;
}