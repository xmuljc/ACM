#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1e4 + 10;
int n, c,ans,res;
int w[N];
bool vt[N];
void dfs() {
	for (int i = 1; i <= n; i++) {
		if (w[i] <= c - res&&vt[i]==false) {
			res += w[i];
			ans = max(ans, res);
			vt[i] = true;
			dfs();
			vt[i] = false;
			res -= w[i];
		}
	}
}

int main() {
	cin >> n >> c;
	for (int i = 1; i <= n; i++)cin >> w[i];
	dfs();
	cout << ans;
	return 0;
}