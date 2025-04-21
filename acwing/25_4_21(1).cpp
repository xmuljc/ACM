/*cspÄ£°åÕ¹¿ª
https://sim.csp.thusaac.com/contest/37/submission/201374*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
const int N = 1e3 + 10;

unordered_map<string, vector<string>>h;
unordered_map<string, int>r;
unordered_map<string, bool>vt;
vector<string>vec;
int  f(string str) {
	vector<string>e = h[str];
		int u = 0,res=0;
		for (int i = 1; i < e.size(); i++) {
			string temp = e[i];
			res = 0;
			if (temp[0] == '$') {
				temp = temp.substr(1,temp.size() - 1);
				if (vt[temp] == false) {
					res = f(e[i]);
					vt[temp] = true;
					r[temp] = res;
				}
				else res=r[temp];
			}
			else {
				if (vt[temp] == false) {
					res = e[i].size();
					vt[temp] = true;
					r[temp] = res;
				}
				else res= r[temp];
			}
			u += res;
		}
		vt[str] = true;
		r[str] = u;
		return u;
	}

int main() {
	int x;
	string str;
	
	cin >> x;
	cin.ignore();
	int flag = 0;
	while (x--) {
		vector<string>res, res1;
		getline(cin,str);
		int j = 0;
		str += ' ';
			for (int i = 0; i < str.size(); i++) {
				if (str[i] == ' ') {
					res.push_back(str.substr(j, i - j));
					j = i + 1;
				}
			}
			for (int i = 0; i < res.size(); i++) {
				if (i != 1) {
					res1.push_back(res[i]);
				}
			}
			if(res[0] != "3")
			h[res[1]] = res1;

			if (res[0] == "1") {
				f(res[1]);
			}
			else if (res[0] == "2") {
				vec.push_back(res[1]);
			}
			else if (res[0] == "3") {
				for (int i = 0; i < vec.size(); i++) {
					string y = vec[i];
					f(y);
				}
				cout << r[res[1]] << endl;
			}
	}		
	return 0;
}