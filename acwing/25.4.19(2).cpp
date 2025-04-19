#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m;
const int N = 1e3 + 10;
int f[N][N];
int d[N][N];

int main() {
	int T;
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> f[i][j];
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				d[i][j] = max(d[i - 1][j], d[i][j - 1]) + f[i][j];
			}
		}
		cout << d[n][m] << endl;

	}
	return 0;
}