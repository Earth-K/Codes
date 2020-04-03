#include <string>
#include<iostream>
#include <vector>
#include<algorithm>

#define INF 987654321
using namespace std;

int adj[101][101];
int D[101][101];

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i==j) adj[i][j] = 0;
            else adj[i][j] = INF;
        }
    }
    for(int i=0; i<results.size(); i++){
        int u = results[i][0];
        int v = results[i][1];
        adj[u][v] = 1;
    }
    for(int k=1; k<=n ;k++){
        for(int i=1; i<=n ;i++){
            for(int j=1; j<=n; j++){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }
    
    int cnt[101]={0,};
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(adj[i][j] < INF || adj[j][i] < INF)
                cnt[i] += 1;
        }
    }
    for(int i=1; i<=n ;i++){
        if(cnt[i] == n)
            answer += 1;
    }    
    
    return answer;
}