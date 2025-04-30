/*
https://www.luogu.com.cn/problem/P1141
*/
//¼ÇÒä»¯ËÑË÷
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<vector>

using namespace std;
const int N = 1010;
int n, m;
char g[N][N];
int id[N][N],sz[N*N];
bool vt[N][N];
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
void bfs(int x, int y, int cc_idx) {
	int cnt = 1;
	vt[x][y] = true;
	id[x][y] = cc_idx;
	queue<pair<int, int>>q;
	q.push({ x,y });
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		int a = t.first, b = t.second;
		char cur = g[a][b];
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i], ny = b + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= n && ny <= n && vt[nx][ny] == false && cur != g[nx][ny]) {
				id[nx][ny] = cc_idx;
				vt[nx][ny] = true;
				cnt++;
				q.push({ nx,ny });
			}
		}
	}
		sz[cc_idx] = cnt;
}


int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> g[i][j];
		}
	}

	int cc_idx = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (id[i][j] == 0) {
				bfs(i, j,cc_idx++);
			}
		}
	}

	while (m--) {
		int a, b;
		cin >> a >> b;
		cout << sz[id[a][b]] << endl;
	}


	return 0;
}