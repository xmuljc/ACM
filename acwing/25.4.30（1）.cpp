#include<iostream>
#include<algorithm>
#include<cstring>


//dfs进行记忆化搜索
using namespace std;
const int N = 1e3 + 10;
int n, m;
char g[N][N];
bool vt[N][N];
int dy[4] = { 1,-1,0,0 }, dx[4] = { 0,0,1,-1 };


int dfs(int x, int y) {

	int res = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		int flag;
		if (g[x][y] - '0' + g[nx][ny] - '0' == 1)flag = 1;
		else flag = 0;

		if (flag&&nx >= 1 && ny >= 1 && ny <= n && nx <= n&&vt[nx][ny]==false) {
			vt[nx][ny] = true;
			res = max(dfs(nx, ny), res);
			vt[nx][ny] = false;
		}
	}
	return res + 1;
}

int main() {
	cin >> n >> m;
	getchar();
	for (int i = 1; i <=n; i++) {
		for (int j = 1; j <= n; j++) {
			g[i][j] = getchar();
		}	
		getchar();
	}
	//for (int i = 1; i <= n; i++) {
	//	for (int j = 1; j <= n; j++) {
	//		cout << g[i][j] << ' ';
	//	}
	//	cout << endl;
	//}
	while (m--) {
		int a, b;
		cin >> a >> b;
		memset(vt, false,sizeof vt);
		vt[a][b] = true;
		cout<<dfs(a, b)<<endl;
	}
	return 0;
}