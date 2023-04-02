#include <bits/stdc++.h>
using namespace std;
struct node {
	string s;
	int len;
	bool operator < (const node &A) const {
		return len > A.len;
	}
};
int n, cnt = 0, ans = 0;
string str;
set<node> st;
set<string> qq;
map<string, bool> mp;

bool check(string str) {
	if (str.substr(0, 7) == "what's ")
		return 1;
	else
		return 0;
}

int main() {
	cin >> n;
	getchar();
	for (int i = 1; i <= n; i++) {
		getline(cin, str);
		if (check(str)) {
			string s = str.substr(7, str.size() - 7);
			if (qq.count(s))
				continue;
			else {
				qq.insert(s);
                mp[s] = 0;
				node elem;
				elem.s = s, elem.len = s.size();
				st.insert(elem);
			}
		} else {
			int len_str = str.size();
			for (auto i : st) {
				string s2 = i.s;
				int len = i.len;
				if (len > len_str)
					continue;
				string str2 = str.substr(0, len);
				if (str2 == s2) {
					if (mp[s2] == 0) {
						mp[s2] = 1;
						++ans;
						break;
					} else
						continue;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}