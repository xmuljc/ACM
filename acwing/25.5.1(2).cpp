/*
https://www.luogu.com.cn/problem/SP15436
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
#include<map>
using namespace std;
map<int, int>h;
const int N = 260;
int n, m, g[N][N];
bool vt[N][N];
int dx[4] = { 0,0,-1,1 }, dy[4] = { 1,-1,0,0 };

void bfs(int x, int y) {
	queue<pair<int, int>>q;
	q.push({ x,y });
	vt[x][y] = true;
	int cnt = 1;
	while (!q.empty()) {
		auto t = q.front();
		q.pop();
		x = t.first, y = t.second;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 1 && ny >= 1 && nx <= n && ny <= m && g[nx][ny] == 1&&vt[nx][ny]==false) {
				vt[nx][ny] = true;
				q.push({ nx,ny });
				cnt++;
			}
		}
	}
	h[cnt]++;
}


int main() {
	cin >> n >> m;
	while (!(m == 0 && n == 0)) {
		h.clear();
		memset(vt, false, sizeof vt);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> g[i][j];
			}
		}
		int id = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (vt[i][j] == false&&g[i][j]==1) {
					bfs(i, j);
					id++;
				}
			}
		}
		cout <<id<<endl;
		for (auto i = h.begin(); i != h.end(); i++) {
			cout << i->first << ' ' << i->second << endl;
		}
		cin >> n >> m;
	}


	return 0;
}