#include<iostream>
using namespace std;
int N, R, C, cnt, answer;

bool getAnswer(int r, int c, int size){
    if(size == 1){
        if(R == r && C == c){
            answer = cnt;
            return true;
        }
        cnt += 1;
        return false;
    }

    if(!(r<=R && R<r+size && c<=C && C<c+size)){
        cnt += size*size;
        return false;
    }
    
    int m = size/2;
    for(int i=0; i<2 ;i++){
        for(int j=0; j<2 ;j++){
            if(getAnswer(r+i*m, c+j*m, m))
                return true;
        }
    }
    return false;
}

int main(){
    //freopen("input.txt","r",stdin);
    scanf("%d %d %d",&N,&R,&C);
    getAnswer(0,0,(1<<N));
    printf("%d",answer);
}