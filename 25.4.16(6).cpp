//acwingµ¥´Ê½ÓÁú
//https://www.acwing.com/problem/content/1119/
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;
string str_max,str_res;
unordered_map<string, int>h;
char ch;

void dfs(string str) {
	str_res += str;
	if (str_res.size() > str_max.size()) {
		str_max = str_res;
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



	return 0;
}