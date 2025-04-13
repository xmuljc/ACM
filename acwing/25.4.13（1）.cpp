#include<iostream>
#include<algorithm>
#include<map>
//25年蓝桥杯A组第二道填空题
using namespace std;
const int N = 70;
int p[N][N] = {2};
map<string, int>h;
string str;
void dfs(int x,int y) {
	cout << x << ' ' << y <<' '<<str<< endl;
	if (y % 7 == 0) {
		x++;
		y = 1;
	}
	if (x == 7 && y == 1) {
		for (int i = 1; i <= 6; i++) {
			for (int j = 1; j <= 6; j++)
				cout << p[i][j] << ' ';
			cout << endl;
		}
		return;
	}

	if (p[x][y] == 2) {
		if (y > 1 && y < 6) {
			for (int i = 0; i <= 1; i++) {
				if (p[x][y - 1] != i && p[x][y + 1] != i) {
					p[x][y] = i;
					str += '0' + i;
					dfs(x, y + 1);
					str.pop_back();
					p[x][y] = 2;
				}
			}
		}
		else if (y == 1) {
			for (int i = 0; i <= 1; i++) {
				if (p[x][2] != i) {
					p[x][y] = i;
					str += '0' + i;
					dfs(x, y + 1);
					str.pop_back();
					p[x][y] = 2;
				}
			}
		}
		else if (y == 6) {
			for (int i = 0; i <= 1; i++) {
				if (p[x][5] != i) {
					string str_res = str.substr(6 * x, 5);
					str_res += '0' + i;
					if (h[str_res] == 0) {
						str += '0' + p[x][y];
						h[str_res]++;
						p[x][y] = i;
						dfs(x, y + 1);
						str.pop_back();
						h[str_res]--;
						p[x][y] = 2;
					}
				}
			}
		}
	}
	else {
		if (y == 6) {
			string str_res = str.substr(6*x,5);
			str_res += '0' + p[x][y];
			cout << '*' << str_res << endl;
			if (h[str_res] == 0) {
				str +='0'+p[x][y];
				h[str_res]++;
				dfs(x, y + 1);
				str.pop_back();
				h[str_res]--;
			}
		}
		else {
			str += '0' + p[x][y];
			dfs(x, y + 1);
			str.pop_back();
		}
	}
}

int main() {
	for (int i = 1; i <= 6; i++)
		for (int j = 1; j <= 6; j++)
			cin >> p[i][j];
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