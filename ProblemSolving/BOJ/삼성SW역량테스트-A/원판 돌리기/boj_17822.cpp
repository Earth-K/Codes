#include<iostream>
#include<deque>
using namespace std;

int N, M, T;
deque<int> dq[51];
bool delChk[51][51];

void delUpDown(int r,int j, int num) {
	if (r == 0) {
		if (num == dq[r + 1][j]) {
			delChk[r + 1][j] = true;
			delChk[r][j] = true;
		}
	}
	else if (r == N - 1) {
		if (dq[r - 1][j] == num) {
			delChk[r - 1][j] = true;
			delChk[r][j] = true;
		}
	}
	else {
		if (dq[r - 1][j] == num) {
			delChk[r - 1][j] = true;
			delChk[r][j] = true;
		}
		if (num == dq[r + 1][j]) {
			delChk[r + 1][j] = true;
			delChk[r][j] = true;
		}
	}
}
void delNum(int r) {
	bool flag = true;
	for (int j = 0; j < M; j++) {
		if (dq[r][j] == 0)continue;

		flag = false;
		int num = dq[r][j];

		delUpDown(r, j, num);

		if (j == 0) {
			if (dq[r][M - 1] == num) {
				delChk[r][M - 1] = true;
				delChk[r][j] = true;
			}
			if (num == dq[r][j + 1]) {
				delChk[r][j + 1] = true;
				delChk[r][j] = true;
			}
			
		}
		else if (j == M - 1) {
			if (dq[r][j - 1] == num) {
				delChk[r][j - 1] = true;
				delChk[r][j] = true;
			}
			if (num == dq[r][0]) {
				delChk[r][0] = true;
				delChk[r][j] = true;
			}
		}
		else {
			if (dq[r][j - 1] == num) {
				delChk[r][j - 1] = true;
				delChk[r][j] = true;
			}
			if (num == dq[r][j + 1]) {
				delChk[r][j + 1] = true;
				delChk[r][j] = true;
			}
		}
	}
}
int main() {
	//freopen("input.txt","r",stdin);
	cin >> N >> M >> T;
	for (int k = 0; k <N; k++) {
		for (int i = 0,n; i < M; i++) {
			cin >> n;
			dq[k].push_back(n);
		}
	}
	for (int i = 0, x, d, k; i < T; i++) {
		cin >> x >> d >> k;
		//번호가 x배수인 원판을 d방향으로 k칸 회전
		if (d == 0) {
			//시계
			for (int r = 0; r < N; r++) {
				if ((r + 1) % x == 0) {
					//r이 x의 배수
					for (int j = 0; j < k; j++) {
						//k칸 회전
						int n = dq[r].back();
						dq[r].pop_back();
						dq[r].push_front(n);
					}
				}
			}
		}
		else {
			//반시계
			for (int r = 0; r < N; r++) {
				if ((r + 1) % x == 0) {
					//r이 x의 배수
					for (int j = 0; j < k; j++) {
						int n = dq[r].front();
						dq[r].pop_front();
						dq[r].push_back(n);
					}
				}
			}
		}
		for (int i = 0; i < N; i++)
			delNum(i);

		bool f = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (delChk[i][j]) {
					f = true;
				}
			}
		}
		if (f) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (delChk[i][j]) {
						delChk[i][j] = false;
						dq[i][j] = 0;
					}
				}
			}
		}
		else {
			int sum = 0;
			int cnt = 0;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (dq[i][j] == 0) continue;
					sum += dq[i][j];
					cnt += 1;
				}
			}
			float avg = (float)sum / (float)cnt;
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < M; j++) {
					if (dq[i][j] == 0) continue;

					if (dq[i][j] > avg) {
						dq[i][j] -= 1;
					}
					else if (dq[i][j] < avg) {
						dq[i][j] += 1;
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans += dq[i][j];
		}
	}
	cout << ans;
	return 0;
}