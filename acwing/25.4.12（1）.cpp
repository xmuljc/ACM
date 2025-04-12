#include<iostream>
#include<algorithm>
/*
‘≠Ã‚Õ¯÷∑£∫
http://10.26.61.138:3296/contest/44/problem/L0410 
*/ 

#include<vector>

using namespace std;
const int N=1e5+10;
int a[N];

int main() {
	int n, m,cnt=0;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a+1, a+n);
	int l = 1, r = 1;
	while (r <= n) {
		if (a[r] - a[l]<=m) {
			r++;
		}
		else {
			cnt++;
			l = r;
		}
	}
	cnt++;
	cout << cnt << endl;
	return 0;
}

