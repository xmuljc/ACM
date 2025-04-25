#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
const int N = 1e6 + 10;
double f[N];
double ans = 1e7;
vector<double>s;
int n;
bool vt[N];

double cnt() {
	double m = 0;
	double a, b, c;
	for (int i = 1; i <= n - 1; i++) {
		a = s[i] + s[i - 1];
		b = fabs(s[i] - s[i - 1]);
		c = sqrt(a * a - b * b);
		m += c;
	}
	return m;
}



void dfs() {
	if (s.size() == n) {
		double y = cnt();
		y += s[0] + s[n - 1];
		ans = min(ans, y);
		/*cout << y << endl;*/
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (vt[i] == false) {
			vt[i] = true;
			s.push_back(f[i]);
			dfs();
			s.pop_back();
			vt[i] = false;
		}
	}


}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)cin >> f[i];
	dfs();
	printf("%.5lf", ans);
	return 0;
}