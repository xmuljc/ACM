#include<iostream>
#include<algorithm>
#include<cstdlib>
//Ве№И
/*https://www.luogu.com.cn/problem/P1331*/

using namespace std;

const int N = 1e3 + 10;
char f[N][N];
int r, c, flag, cnt,sum,sum_init;
bool vt[N][N];

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int col_sum(int x, int y) {
	int row_cnt = 0;
	int xw = x, yw = y;
	while (f[xw][y] == '#' && xw <= r) {
		vt[xw][y] = true;
		row_cnt++;
		xw++;
	}
	return row_cnt;
}

int row_sum(int x, int y) {
	int col_cnt = 0;
	int yw = y;
	while (f[x][yw] == '#' && yw <= c) {
		vt[x][yw] = true;
		col_cnt++;
		yw++;
	}
	return col_cnt;
}


void force() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (f[i][j] == '#'&&vt[i][j]==false) {
				int col_cnt = col_sum(i, j),row_cnt=row_sum(i,j);
				for (int k = i+1; k <= i + col_cnt - 1; k++) {
					int cow_cnt_res = row_sum(k, j);
					if (cow_cnt_res != row_cnt) {
						cout << "Bad placement." << endl;
						exit(0);
					}
				}

				for (int k = j + 1; k <= j + row_cnt - 1; k++) {
					int rol_cnt_res = col_sum(i, k);
					if (rol_cnt_res != col_cnt) {
						cout << "Bad placement." << endl;
						exit(0);
					}
				}


				cnt++;
				sum += col_cnt * row_cnt;
			}
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> f[i][j];
			if (f[i][j] == '#') {
				sum_init++;
			}
		}
	}
	force();
	if (sum_init != sum)cout << "Bad placement." << endl;
	else cout << "There are " << cnt << " ships." << endl;

	return 0;
}