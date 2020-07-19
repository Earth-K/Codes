#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
struct Virus {
	int r, c, cnt;
};
vector<Virus> vt, selVirus;
bool usedVirus[10];
int map[51][51], tmp[51][51], N, M, oneCnt, virusCnt, answer;
bool visited[51][51];
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
void init() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				vt.push_back({ i,j,0 });
			else if (map[i][j] == 1)
				oneCnt += 1;
		}
	}
	answer = 987654321;
}
int bfs() {
	memset(visited, false, sizeof(visited));
	queue<Virus> Q;
	for (Virus v : vt)
		tmp[v.r][v.c] = -1;
	for (Virus v : selVirus) {
		Q.push(v);
		tmp[v.r][v.c] = 2;
		visited[v.r][v.c] = true;
	}
	
	while (!Q.empty()) {
		Virus now = Q.front();
		Q.pop();
		if (now.cnt >= answer)
			return answer;

		if (tmp[now.r][now.c] == 0) {
			tmp[now.r][now.c] = 2;
			virusCnt += 1;
		}
		
		if (virusCnt == N*N-oneCnt) {
			return now.cnt;
		}

		for (int i = 0; i < 4; i++) {
			int nextR = now.r + dr[i];
			int nextC = now.c + dc[i];
			if (!(0 <= nextR && nextR < N && 0 <= nextC && nextC < N)) continue;
			if (tmp[nextR][nextC] == 1) continue;
			if (visited[nextR][nextC]) continue;

			visited[nextR][nextC] = true;
			Q.push({nextR,nextC,now.cnt+1});
		}
	}
	return 987654321;
}
void comb(int idx) {
	if (selVirus.size() == M) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				tmp[i][j] = map[i][j];
			}
		}
		virusCnt = vt.size();
		int res = bfs();
		if (answer > res)
			answer = res;
		return;
	}
	for (int i = idx; i < vt.size(); i++) {
		if (usedVirus[i]) continue;

		selVirus.push_back(vt[i]);
		usedVirus[i] = true;

 		comb(i + 1);

		selVirus.pop_back();
		usedVirus[i] = false;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	init();
	comb(0);
	if (answer == 987654321)
		cout << "-1";
	else
		cout << answer;
	return 0;
}