
//Âå¹È±©ËÑ
/*https://www.luogu.com.cn/problem/P1596*/
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 110;
int n, m;
char f[N][N];
int dx[8] = { 1,-1,0,0,-1,-1,1,1 }, dy[8] = { 0,0,1,-1,1,-1,1,-1};
void cnt(int x, int y) {
	f[x][y] = '.';
	for (int i = 0; i <= 7; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx >= 1 && ny >= 1 && nx <= n && ny <= m) {
			if (f[nx][ny] == 'W') {
				cnt(nx, ny);
			}
		}
	}
}
int main() {
	int res = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> f[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (f[i][j] == 'W') {
				cnt(i, j);
				res++;
			}
		}
	}
	cout << res << endl;
	return 0;
}
