#include<iostream>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;

vector<pair<int, int>> players;
deque<pair<int, int>> state[15][15];

int N, K, map[15][15];
int dr[5] = { 0,0,-1,1 };
int dc[5] = { 1,-1,0,0 };
int rev[4] = { 1,0,3,2 };
int getIdx(int r, int c, int n) {
	for (int i = 0; i < state[r][c].size(); i++) {
		if (state[r][c][i].first == n) {
			return i;
		}
	}
	return -1;
}

int main() {
	//freopen("input.txt","r",stdin);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0, r, c, d; i < K; i++) {
		cin >> r >> c >> d;
		state[r][c].push_front({ i,d - 1 });
		players.push_back({ r,c });
	}

	int cnt = 0;
	bool flag = false;
	while (true)
	{
		if (cnt == 1001) break;
		if (flag) break;
		cnt += 1;

		for (int i = 0; i < players.size(); i++)
		{
			pair<int, int> p = players[i];
			int r = p.first;
			int c = p.second;
			int idx = getIdx(r, c, i);
			//cout << idx << endl;
			int d = state[r][c][idx].second;
			int nextR = r + dr[d];
			int nextC = c + dc[d];

			if (1 <= nextR && nextR <= N && 1 <= nextC && nextC <= N)
			{
				if (map[nextR][nextC] == 0)
				{ // 흰
					for (int j = idx; j >=0; j--)
					{
						state[nextR][nextC].push_front(state[r][c][j]);
					}
					state[r][c].erase(state[r][c].begin(), state[r][c].begin()+idx+1);
					for (int j = idx; j >= 0; j--) {
						int pn = state[nextR][nextC][j].first;
						players[pn].first = nextR;
						players[pn].second = nextC;
					}
				}
				else if (map[nextR][nextC] == 1)
				{ // 빨
					for (int j = idx; j >= 0; j--)
					{
						state[nextR][nextC].push_front(state[r][c][j]);
					}
					state[r][c].erase(state[r][c].begin(), state[r][c].begin() + idx+1);

					idx = getIdx(nextR, nextC, i);
					reverse(state[nextR][nextC].begin(), state[nextR][nextC].begin()+idx+1);
					for (int j = idx; j >= 0; j--) {
						int pn = state[nextR][nextC][j].first;
						players[pn].first = nextR;
						players[pn].second = nextC;
					}
				}
				else if (map[nextR][nextC] == 2)
				{ // 파
					int d = state[r][c][idx].second;
					state[r][c][idx].second = rev[d];
					nextR = r + dr[rev[d]];
					nextC = c + dc[rev[d]];
					if (1 <= nextR && nextR <= N && 1 <= nextC && nextC <= N)
					{
						if (map[nextR][nextC] == 0)
						{ // 흰
							for (int j = idx; j >= 0; j--)
							{
								state[nextR][nextC].push_front(state[r][c][j]);
							}
							state[r][c].erase(state[r][c].begin(), state[r][c].begin() + idx+1);
						}
						else if (map[nextR][nextC] == 1)
						{ // 빨
							for (int j = idx; j >= 0; j--)
							{
								state[nextR][nextC].push_front(state[r][c][j]);
							}
							state[r][c].erase(state[r][c].begin(), state[r][c].begin() + idx+1);
							idx = getIdx(nextR, nextC, i);
							reverse(state[nextR][nextC].begin(), state[nextR][nextC].begin() + idx+1);
						}
						if (map[nextR][nextC] != 2) {
							for (int j = idx; j >= 0; j--) {
								int pn = state[nextR][nextC][j].first;
								players[pn].first = nextR;
								players[pn].second = nextC;
							}
						}
					}
				}

			}
			else {
				// 파
				int d = state[r][c][idx].second;
				state[r][c][idx].second = rev[d];
				nextR = r + dr[rev[d]];
				nextC = c + dc[rev[d]];
				if (1 <= nextR && nextR <= N && 1 <= nextC && nextC <= N)
				{
					if (map[nextR][nextC] == 0)
					{ // 흰
						for (int j = idx; j >= 0; j--)
						{
							state[nextR][nextC].push_front(state[r][c][j]);
						}
						state[r][c].erase(state[r][c].begin(), state[r][c].begin() + idx+1);
					}
					else if (map[nextR][nextC] == 1)
					{ // 빨
						for (int j = idx; j >= 0; j--)
						{
							state[nextR][nextC].push_front(state[r][c][j]);
						}
						state[r][c].erase(state[r][c].begin(), state[r][c].begin() + idx+1);
						idx = getIdx(nextR, nextC, i);
						reverse(state[nextR][nextC].begin(), state[nextR][nextC].begin() + idx+1);
					}
					
					if (map[nextR][nextC] != 2) {
						for (int j = idx; j >= 0; j--) {
							int pn = state[nextR][nextC][j].first;
							players[pn].first = nextR;
							players[pn].second = nextC;
						}
					}
				}
			}
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (state[i][j].size() >= 4) {
						flag = true;
					}
				}
			}
			if (flag) break;
		}
	}
	if (cnt == 1001)
		cout << "-1";
	else
		cout << cnt;
	return 0;
}