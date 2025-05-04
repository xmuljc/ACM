/*
https://www.acwing.com/problem/content/1019/
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 110;
int k, n, f[N], d1[N],d2[N];

int main() {
	cin >> k;
	while (k--) {
		cin >> n;
		memset(f, 0, sizeof f);
		int m = 1;
		for (int i = 1; i <= n; i++)d1[i] = 1;
		for (int i = 1; i <= n; i++)d2[i] = 1;
		
		for (int i = 1; i <= n; i++)cin >> f[i];

		for (int i = n-1; i >= 1; i--) {
			for (int j = i+1; j <=n; j++) {
				if (f[i] > f[j]) {
					d1[i] = max(d1[i], d1[j] + 1);
					m = max(m, d1[i]);
				}
			}
		}

		for (int i = 2; i <= n; i++) {
			for (int j = i -1; j >=1; j--) {
				if (f[j] <f[i]) {
					d2[i] = max(d2[j] + 1, d2[i]);
					m = max(m, d2[i]);
				}
			}
		}

		cout << m << endl;
	}

	return 0;
}