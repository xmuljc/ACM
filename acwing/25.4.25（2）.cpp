#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 1e3 + 10;
int n, c, v[N], w[N];
int f[N][N],ans;
string str;

void reverse(int u) {
	if (u <0)return;
	int flag = 0;
	for(int i=0;i<=c;i++){
		if (ans - v[u + 1] == f[u][i]) {
			ans -= v[u + 1];
			str += '1';
			reverse(u - 1);
			flag = 1;
		}
	}	
	if (flag == 0) {
		str += '0';
		reverse(u - 1);
	}
}


int main() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++)cin >> v[i];
	for (int i = 1; i <= n; i++)cin >> w[i];

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= c; j++) {
			f[i][j] = f[i - 1][j];
			if (j >= w[i]) {
				f[i][j] = max(f[i][j], f[i - 1][j - w[i]] + v[i]);
			}
		}
	}

	ans = f[n][c];
	cout << f[n][c] << endl;
	reverse(n-1);
	for (int i = str.size() - 1; i >= 0; i--) {
		cout << str[i] << ' ' ;
	}

	return 0;
}