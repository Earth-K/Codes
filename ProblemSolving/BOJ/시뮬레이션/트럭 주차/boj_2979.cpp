#include<iostream>
#include<algorithm>
using namespace std;
int A, B, C, arr[3][2];
int main(){
    cin>>A>>B>>C;
    int minT = 100;
    int maxT = 0;
    for(int i=0,a,b; i<3; i++){
        cin>>a>>b;
        arr[i][0] = a;
        arr[i][1] = b;
        minT = min(minT, a);
        maxT = max(maxT, b);
    }
    
    int answer = 0;
    for(int t=minT; t<=maxT; t++){
        int cnt = 0;
        for(int i=0; i<3; i++){
            if(arr[i][0] <= t && t < arr[i][1]){
                cnt += 1;
            }
        }
        if (cnt == 1)
            answer += A;
        else if (cnt == 2)
            answer += B*2;
        else if(cnt == 3)
            answer += C*3;
    }
    cout<<answer;
    return 0;
}