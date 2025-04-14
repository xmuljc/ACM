#include<iostream>
#include<algorithm>
#include<vector>
//25年蓝桥杯A组第二道填空题

using namespace std;
int p[7][7];

bool check1(int x, int y,int ch) {//ch为1为检查行，2为检查列
	//每一行
	if (ch == 1) {
		for (int i = 1; i <= x; i++) {
			int cnt0 = 0, cnt1 = 0;
			for (int j = 1; j <= 6; j++) {
				if (p[i][j] == 0)cnt0++;
				if (p[i][j] == 1)cnt1++;
			}
			if (cnt0 != cnt1)return false;
		}

	}

	//每一列,只有当x=6，并且y=6时，才检查。
	else {

		for (int i = 1; i <= x; i++) {
			int cnt0 = 0, cnt1 = 0;
			for (int j = 1; j <= 6; j++) {
				if (p[i][j] == 0)cnt0++;
				if (p[i][j] == 1)cnt1++;
			}
			if (cnt0 != cnt1)return false;
		}



		for (int i = 1; i <= 6; i++) {
			int cnt0 = 0, cnt1 = 0;
			for (int j = 1; j <= 6; j++) {
				if (p[j][i] == 0)cnt0++;
				if (p[j][i] == 1)cnt1++;
			}
			if (cnt0 != cnt1)return false;
		}
	}
	return true;
}

bool check2(int x, int y,int z) {
	if (y > 1 && y < 6) {
		if (p[x][y - 1] != z && p[x][y + 1] != z) {
			return true;
		}

	}
	else if (y == 1) {
		if (p[x][2] != z)
			return true;
	}
	else if (y == 6) {
		if (p[x][5] != z) {
			return true;
		}
	}
	return false;
}

bool check3(int x, int y,int ch) {//ch为1时检查行，ch为2时检查列
	if (ch == 1) {//检查行
		for (int i = 1; i <= x; i++) {
			for (int j = i + 1; j <= x; j++) {
				int flag = 0;
				for (int k = 1; k <= 6; k++) {
					if (p[i][k] != p[j][k]) {
						flag = 1;
					}
				}
				if (flag == 0)return false;
			}
		}
	}
	else if (ch == 2) {

		for (int i = 1; i <= x; i++) {
			for (int j = i + 1; j <= x; j++) {
				int flag = 0;
				for (int k = 1; k <= 6; k++) {
					if (p[i][k] != p[j][k]) {
						flag = 1;
					}
				}
				if (flag == 0)return false;
			}
		}


		for (int i = 1; i <= 6; i++) {
			for (int j = i+1; j <= 6; j++) {
				int flag = 0;
				for (int k = 1; k <= 6; k++) {
					if (p[k][i] != p[k][j]) {
						flag = 1;
					}
				}
				if (flag == 0)return false;
			}
		}
	}
	return true;
}

void dfs(int x,int y) {
	cout << x << ' ' << y << endl;
	if (y == 7) {
		x++;
		y = 1;
	}
	if (x == 7) {
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 6; j++) {
				cout << p[i][j] << ' ';
			}
			cout << endl;
		}
	}

	if (x != 6 && y != 6) {
		cout << "**" << endl;
		for (int i = 0; i <= 1; i++) {

			if (p[x][y] != 2) {
				dfs(x, y + 1);
			}

			else if (check2(x, y, i)) {
				cout << "*" << endl;
				p[x][y] = i;
				dfs(x, y + 1);
				p[x][y] = 2;
			}
		}
	}
	else if (y == 6 && x != 6) {
		for (int i = 0; i <= 1; i++) {
			if (p[x][y] != 2) {
				dfs(x, y + 1);
			}

			else if (check2(x, y, i)) {
				p[x][y] = i;
				if (check1(x, y, 1) && check3(x, y, 1)) {
					dfs(x, y + 1);
				}
				p[x][y] = 2;
			}
		}

	}
	else if (x == 6 && y == 6) {
		for (int i = 0; i <= 1; i++) {

			if (p[x][y] != 2) {
				dfs(x, y + 1);
			}


			else if (check2(x, y, i)) {
				p[x][y] = i;
				if (check1(x, y, 2) && check3(x, y, 2)) {
					dfs(x, y + 1);
				}
				p[x][y] = 2;
			}
		}
	}
}

int main() {
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 6; j++) {
			cin >> p[i][j];
		}
	}
	dfs(1,1);
	return 0;
}



/*
1 0 2 0 2 2 
2 2 2 0 2 2
2 2 2 2 0 0
2 2 2 2 2 2 
2 2 1 2 2 1
2 0 2 2 1 2
*/