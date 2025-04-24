/*https://www.acwing.com/problem/content/277/*/
#include<iostream>
#include<algorithm>

using namespace std;
const int N = 60;

int f[N][N][N];
int g[N][N],n,m;

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> g[i][j];
		}
	}

	for (int k = 2; k <= n + m; k++) {
		for(int i = max(1, k - n);i<=min(n,k-1);i++)
			for (int j = max(1, k - m);j <= min(m, k - 1); j++) {
				int t = g[i][k-i];
				if (i != j || k == 2 || k == n + m) {
					t += g[j][k - j];
					f[k][i][j] = max(f[k][i][j], f[k - 1][i][j]+t);
					f[k][i][j] = max(f[k][i][j], f[k - 1][i-1][j-1]+t);
					f[k][i][j] = max(f[k][i][j], f[k - 1][i-1][j]+t);
					f[k][i][j] = max(f[k][i][j], f[k - 1][i][j-1]+t);
					//cout << k << ' ' << i << ' ' << ' ' << j << ' ' << f[k][i][j] << endl;
				}
			}
	}
	cout << f[m + n][n][m] << endl;
	return 0;
}