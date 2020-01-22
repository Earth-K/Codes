#include<iostream>
#include<cstring>
using namespace std;

int map[21][21], area[21][21], N;
int sum[6];

void getSum(int sum[], int x, int y, int d1, int d2){
    int r, c;
    memset(sum,0,sizeof(sum));
    memset(area,0,sizeof(area));

    for(int i=0; i<=d1; i++){
        r = x+i;
        c = y-i;
        sum[5] += map[r][c];
        area[r][c] = 5;
    }
    for(int i=1; i<=d2; i++){
        r = x+i;
        c = y+i;
        sum[5] += map[r][c];
        area[r][c] = 5;
    }
    for(int i=1; i<=d2; i++){
        r = x+d1+i;
        c = y-d1+i;
        sum[5] += map[r][c];
        area[r][c] = 5;
    }
    for(int i=1; i<d1; i++){
        r = x+d2+i;
        c = y+d2-i;
        sum[5] += map[r][c];
        area[r][c] = 5;
    }
    for(r=x+1, c=y-1 ; r<=x+d1; r++,c--){
        int j = 1;
        while(area[r][c+j] != 5){
            sum[5] += map[r][c+j];
            j++;
        }
    }
    for(r=x+d1+1, c=y-d1+1 ; r<x+d1+d2; r++,c++){
        int j = 1;
        while(area[r][c+j] != 5){
            sum[5] += map[r][c+j];
            j++;
        }
    }

    for(r=1,c=1; r<x+d1; r++){
        for(int j=c; j<=y; j++){
            if(area[r][j] != 5){
                sum[1] += map[r][j];
                area[r][j] = 1;
            }
        }
    }

    for(r=1,c=y+1; r<=x+d2; r++){
        for(int j=c; j<=N; j++){
            if(area[r][j] != 5){
                sum[2] += map[r][j];
                area[r][j] = 2;
            }
        }
    }

    for(r=x+d1,c=1; r<=N; r++){
        for(int j=c; j<y-d1+d2; j++){
            if(area[r][j] != 5){
                sum[3] += map[r][j];
                area[r][j] = 3;
            }
        }
    }

    for(r=x+d2+1,c=y-d1+d2; r<=N; r++){
        for(int j=c; j<=N; j++){
            if(area[r][j] != 5){
                sum[4] += map[r][j];
                area[r][j] = 4;
            }
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    cin>>N;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            cin>>map[i][j];
    
    int answer = 987654321;

    for(int x=1; x<=N; x++){
        for(int y=1; y<=N ;y++){
            for(int d1=1; d1<=N; d1++){
                for(int d2=1; d2<=N; d2++){
                    if(x<x+d1+d2 && x+d1+d2<=N && 1<=y-d1 && y+d2<=N){
                        getSum(sum,x,y,d1,d2);
                        int maxSum = 0;
                        int minSum = 987654321;
                        for(int i=1; i<=5; i++){
                            if(maxSum < sum[i]) maxSum = sum[i];
                            if(minSum > sum[i]) minSum = sum[i];
                        }
                        if(answer > maxSum-minSum)
                            answer = maxSum-minSum;
                    }
                }
            }
        }
    }
    cout<<answer<<endl;
    return 0;
}