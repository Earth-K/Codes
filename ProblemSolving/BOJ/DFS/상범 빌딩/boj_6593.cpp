#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

#define INF 987654321
struct Obj{
    int i,j,k,s;
};
int L,R,C,si,sj,sk,ei,ej,ek;

string map[31][31];
bool visited[31][31][31];
int di[6] = {0,0,1,-1,0,0};
int dj[6] = {1,-1,0,0,0,0};
int dk[6] = {0,0,0,0,1,-1};

bool chk(int i, int j, int k){
    return 0<=i && i<L && 0<=j && j<R && 0<=k && k<C && !visited[i][j][k] && map[i][j][k] != '#';
}
int bfs(int i, int j, int k, int s){
    queue<Obj> Q;
    Q.push({i,j,k,0});
    visited[i][j][k] = true;

    while(!Q.empty()){
        Obj o = Q.front();
        Q.pop();
        if(o.i == ei && o.j == ej && o.k == ek){
            return o.s;
        }

        for(int q=0; q<6; q++){
            int nextI = o.i+di[q];
            int nextJ = o.j+dj[q];
            int nextK = o.k+dk[q];
            if(chk(nextI,nextJ,nextK)){
                Q.push({nextI,nextJ,nextK,o.s+1});
                visited[nextI][nextJ][nextK] = true;
            }
        }
    }
    return INF;
}
int solve(){
    memset(visited,false,sizeof(visited));
    return bfs(si,sj,sk,0);
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    while(true){
        cin>>L>>R>>C;
        if(L==R && R==0) break;
        
        for(int i=0; i<L; i++)
            for(int j=0; j<R; j++)
                cin>>map[i][j];

        for(int i=0; i<L; i++){
            for(int j=0; j<R; j++){
                for(int k=0; k<C; k++){
                    if(map[i][j][k] == 'S'){
                        si=i, sj=j, sk=k;
                    }
                    else if(map[i][j][k] == 'E'){
                        ei=i, ej=j; ek=k;
                    }
                }
            }
        }
                    
        int ans = solve();
        if(ans != INF)
            cout<<"Escaped in "<<ans<<" minute(s).\n";
        else 
            cout<<"Trapped!\n";
    }
    return 0;
}