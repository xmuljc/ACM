#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 110;
int f[N][N],n;
int d[N][N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> f[i][j];
		}
	}
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if(i>1&&j>1)
			d[i][j] = min(d[i - 1][j], d[i][j - 1]) + f[i][j];
			else if(i==1)
			d[i][j] = d[i][j - 1] + f[i][j];
			else
			d[i][j] = d[i-1][j] + f[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << d[i][j] << ' ';
		}
		cout << endl;
	}

	cout << d[n][n] << endl;

	return 0;
}