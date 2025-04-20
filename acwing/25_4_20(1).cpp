#include<iostream>
#include<algorithm>
/*
* ˫��״̬dp
https://www.acwing.com/problem/content/1029/
*/


using namespace std;
const int N = 100;
const int M = 2 * N - 1;
int f[N][N];
int d[M][N][N];/*����·��ͬʱ�ߣ�d[k][i][j]��ʾ��Ϊ����·��ͬ���ߵĲ���Ϊk��
iΪ��һ��·�ߵ�x����һ��·�ߵ�yΪk - i����jΪ�ڶ���·�ߵ�x*/

int max4(int a, int b, int c, int d) {
	int arr[4] = { a,b,c,d };
	sort(arr, arr + 4);
	return arr[3];
}

int main() {
	int n;
	cin >> n;
	int a, b, c;
	cin >> a >> b >> c;
	while (a != 0 ||b != 0 ||c != 0) {
		f[a][b] = c;
		cin >> a >> b >> c;
	}

	for (int k = 1; k <= 2*n; k++) {//����дk<=2n-1,��Ϊ����©���ڴ���ֵ
		for (int i = 1; i <= n&&i<=k; i++) {
			for (int j = 1; j <= n && j <= k; j++) {


				int res;
				if (i != j) {
					res = f[i][k - i] + f[j][k - j];
				}
					
				else {
					res = f[i][k - i];
				}
					
				d[k][i][j] = max4(d[k - 1][i - 1][j], d[k - 1][i][j - 1], d[k - 1][i][j], d[k - 1][i - 1][j - 1]) + res;
			}
		}
	}
	cout << d[2 * n][n][n] << endl;
	return 0;
}