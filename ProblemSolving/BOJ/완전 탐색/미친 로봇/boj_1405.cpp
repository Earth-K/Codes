#include<iostream>
using namespace std;

bool visited[29][29];
int n,r,c,numE,numW,numS,numN;
int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
double pe,pw,ps,pn;

double solve(int r, int c, int cnt, int E, int W, int S, int N){
    if(E == 0 || W == 0 || S == 0 || N == 0)
        return 0;
    if(visited[r][c])
        return 0;
    if(cnt == n)
        return 1;

    double answer = 0;

    visited[r][c] = true;
    answer += pe * solve(r,c+1,cnt+1,E-1,W,S,N);
    answer += pw * solve(r,c-1,cnt+1,E,W-1,S,N);
    answer += ps * solve(r+1,c,cnt+1,E,W,S-1,N);
    answer += pn * solve(r-1,c,cnt+1,E,W,S,N-1);
    visited[r][c] = false;
    
    return answer;
}

int main(){
    r = c = 14;
    cin>>n>>numE>>numW>>numS>>numN;
    pe = (double)numE / 100;
	pw = (double)numW / 100;
	ps = (double)numS / 100;
	pn = (double)numN / 100;
    printf("%.10f",solve(r,c,0,numE,numW,numS,numN));
     return 0;
}