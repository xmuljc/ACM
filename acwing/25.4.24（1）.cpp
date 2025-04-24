#include<iostream>
#include<algorithm>
//luoguµ›πÈ£¨∫Û–Ú±È¿˙
/*https://www.luogu.com.cn/problem/P1087*/

using namespace std;
const int N = 1e3;
int n;
int e[N], ne[N], h[N], idx;
char w[N];
int lenmax;


int judge(string str) {//b 0 /i 1 /f 2
	int b_flag = 0, i_flag = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '0')b_flag = 1;
		else i_flag = 1;
		if (b_flag == 1 && i_flag == 1)return 2;
	}
	if (b_flag)return 0;
	else return 1;
}

int build(string str,int k) {

	if (str.size()==0)return 0;
	int flag = judge(str);
	char ch;
	if (flag == 0)ch = 'B';
	else if (flag == 1)ch = 'I';
	else ch = 'F';
	 build(str.substr(0, str.size() / 2), 2 * k);
	 build(str.substr(str.size() / 2, str.size() / 2), 2 * k + 1);
	w[k] = ch;
	
	return 1;
}


void print(int k) {
	if (k >lenmax)return;
	print(2*k);
	print(2*k+1);
	cout << w[k];
}
int main() {
	string str;
	cin >> n;
	cin >> str;
	lenmax = 2 * str.size() - 1;
	build(str,1);
	print(1);
	/*for (int i = 1; i <= 15; i++) {
		cout << i << ' ' << w[i] << endl;
	}*/
	return 0;
}