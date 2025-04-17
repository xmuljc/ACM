//acwing单词接龙
//https://www.acwing.com/problem/content/1119/

/*
输入样例：
5
at
touch
cheat
choose
tact
a
输出23
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;
string str_max, str_res;
unordered_map<string, int>h;
char ch;

void dfs(string str) {
	str_res += str;
	if (str_res.size() > str_max.size()) {
		str_max = str_res;
	}
	int len;
	for (auto i = h.begin(); i != h.end(); i++) {
		if (i->second != 0) {
			string str_cur = i->first;
			int  flag = 0;
			len=1;
			if (str_cur.size() == 1)continue;
			while (len<str_res.size()&&len<str_cur.size()){
				string A = str_res.substr(str_res.size() - len);
				string B = str_cur.substr(0, len);
					if (str_res.substr(str_res.size()-len) == str_cur.substr(0, len)) {
						flag = 1;
					}
					if (flag == 1) {
						h[str_cur]--;
						dfs(str_cur.substr(len, str_cur.size() - len));
						h[str_cur]++;
						int u = str_cur.size() - len;
						while (u--) {
							str_res.pop_back();
						}
					}
					if (flag == 1)break;
					len++;
				}
			
		}
	}


}

int main() {
	string str;
	int n;
	cin >> n;
	while (n--) {
		cin >> str;
		h[str] = 2;
	}
	cin >> ch;

	for (auto i = h.begin(); i != h.end(); i++) {
		if (i->first[0] == ch) {
			h[i->first]--;
			dfs(i->first);
			h[i->first]++;
		}
	}
	cout << str_max << endl;
	cout << str_max.size() << endl;
	return 0;
}