#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int N = 12;
int e[N];
int ans = 1e5,n;
vector<vector<int>>h;

int gcd(int x, int y) {
	if  (y == 0)return x;
	else {
		return gcd(y, x % y);
	}
}

bool judge(vector<int>p, int x) {

	int res;
	for (int i = 0; i < p.size(); i++) {
		if (p[i] > x)
			res = gcd(p[i], x);
		else
			res = gcd(x, p[i]);
		if (res != 1)return false;
	}
	return true;
}

void dfs(int u) {
	if (u == n + 1) {
		int x = h.size();
		ans = min(ans, x);
		return;
	}

			if (h.size() == 0) {
				h.resize(1);
				h[0].push_back(e[u]);
				dfs(u + 1);
				h[0].pop_back();
				h.pop_back();
			}
			else {
				for (int j = 0; j < h.size(); j++) {//查看能不能放入已有的集合中
			
					if (judge(h[j], e[u])) {
						h[j].push_back(e[u]);
						dfs(u + 1);
						h[j].pop_back();
					}
				}
				if (h.size()+1 > ans)return;
				int k = h.size()+1;//e[u]单独一个集合
				h.resize(k);
				h[k-1].push_back(e[u]);
				dfs(u + 1);
				h[k-1].pop_back();
				h.pop_back();
			}
	
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> e[i];
	dfs(1);
	cout << ans;
	return 0;
}