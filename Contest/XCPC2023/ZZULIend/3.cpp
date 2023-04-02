#include <bits/stdc++.h>
using namespace std;

string str;
int n, mx = 0, a[200001], b[200001];
vector<int> v[200001];
vector<string> ans;

inline void dfs(int x, int cur) {
	if (cur > 9)
		return;
	str += b[x] + '0';
	for (auto y : v[x])
		dfs(y, cur + 1);
}

bool cmp(const string &a, const string &b) {
	return a > b;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		mx = max(mx, b[i]);
	}
	if (mx == 0) {
		printf("0\n");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		v[i].push_back(a[i]);
	for (int i = 1; i <= n; i++)
		if (b[i] == mx) {
			str = "";
			dfs(i, 1);
			ans.push_back(str);
		}
	sort(ans.begin(), ans.end(), cmp);
	cout << ans[0] << endl;
	return 0;
}