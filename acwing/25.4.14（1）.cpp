//[���ű� 2025 ʡ A] �ô�����Ŀ
//ԭ������https://www.luogu.com.cn/problem/P12143
//���Ż�����������Ϊ1e5ʱ RE
#include<iostream>
#include<algorithm>
#include<vector>



using namespace std;
const int N = 1e4 + 10;
int f[N][N];//f[][]��¼�ǵݼ���
int main() {
	string str;
	cin >> str;
	int n = str.size(),cnt=n;

	for (int i = 0; i < n; i++)f[i][i] = 1;

	int size = 0;
	for (int i = 0; i < n; i++) {
		size++;
		for (int j = 0, k = size; k < n; k++, j++) {
			int flag = 0;
			for (int t = j + 1; t <= k; t++) {
				int left = f[j][t - 1], right = f[t][k];
				if (left != 0 && right != 0&&(str[t]==str[t-1]||str[t]==str[t-1]+1)) {
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				f[j][k] = 1;
			}
		}
	}

	size = 0;
	for (int i = 0; i < n; i++) {
		size++;
		for (int j = 0, k = size; k < n; k++, j++) {
			int flag = 0;
			for (int t = j + 1; t <= k; t++) {
				int left = f[j][t - 1], right = f[t][k];
				if (left != 0 && right != 0 ) {
					flag = 1;
					break;
				}
			}
			if (flag == 1) {
				cnt++;
			}
		}
	}

	cout << cnt;
	return 0;
}