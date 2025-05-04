#include<iostream>
#include<algorithm>
#include<unordered_set>

using namespace std;
unordered_set<int>set1[10];
unordered_set<int>set2[10];
unordered_set<int>set3[10];
char g[10][10];
int flag;
string res;
void dfs(int u) { 
	//cout << u << endl;
	if (flag == 1)return;
	if (u >= 81) {
		flag = 1;
		return;
	}
	int x = u / 9, y = u % 9;
	if (g[x][y] >= '1' && g[x][y] <= '9')dfs(u + 1);
	else {
		for (int i = 1; i <= 9; i++) {
			if (set1[x].find(i) != set1[x].end())continue;
			if (set2[y].find(i) != set2[y].end())continue;

			int k = (x / 3) * 3 + y / 3;//µÚ¼¸¿é3x3µÄ¿é
			if (set3[k].find(i) != set3[k].end()) {
				continue;
			}
			set1[x].insert(i);
			set2[y].insert(i);
			set3[k].insert(i);
			g[x][y] = '0' + i;
			dfs(u + 1);
			if (flag == 1)return;
			g[x][y] = '.';
			set1[x].erase(i);
			set2[y].erase(i);
			set3[k].erase(i);
		}
	}
}



int main() {
	string str;
	cin >> str;
	while (str[0] != 'e') {
		for (int i = 0; i < 9; i++) {
			set1[i].clear();
			set2[i].clear();
			set3[i].clear();
		}
		flag = 0;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				g[i][j] = str[i * 9+j];
				if (g[i][j] >= '1' && g[i][j] <= '9') {
					int k= (i / 3) * 3 + j / 3;
					set1[i].insert(g[i][j]-'0');
					set2[j].insert(g[i][j] - '0');
					set3[k].insert(g[i][j] - '0');
				}
			}
		}
		dfs(0);
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++) {
				cout << g[i][j];
			}
		cout << endl;
		cin >> str;
	}
	return 0;
}
