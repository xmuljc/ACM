//acwingÂí×ßÈÕ
//https://www.acwing.com/problem/content/1118/ 

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 10;
int cnt, n, m, f[N][N];
int v[N][N];
int dx[8] = { 1,1,-1,-1,2,2,-2,-2 };
int dy[8] = { 2,-2,2,-2,1,-1,1,-1 };


bool judge(int x, int y) {
	if (x >= 0 && x <= n - 1 && y >= 0 && y <= m - 1) {
		return true;
	}
	else {
		return false;
	}

}

int dfs(int x,int y) {
	if (cnt == n * m) {
		return 1;
	}
	int res = 0;

	for (int i = 0; i < 8; i++) {
		int x_res = x + dx[i], y_res = y + dy[i];
		if (judge(x_res, y_res) && v[x_res][y_res] == 0) {
	/*		cout << x_res << ' ' << y_res << endl;*/
			v[x][y] = 1;
			cnt++;
			res += dfs(x_res, y_res);
			cnt--;
			v[x][y] = 0;
		}
	}
	return res;
}


int main() {
	int z,x,y;
	cin >> z;
	while (z--) {
		memset(v, 0, sizeof v);
		cin >> n >> m >> x >> y;
		cnt = 1;
		v[x][y] = 1;
		cout << dfs(x,y) << endl;
	}


	return 0;
}

