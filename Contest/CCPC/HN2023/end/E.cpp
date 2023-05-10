#include <bits/stdc++.h>
using namespace std;

int n, m, k, f[501][501][501];
int a[501][501];

inline void solve() {
	scanf("%d%d%d", n, m, k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			char ch;
			cin >> ch;
			if (ch == '1')
				a[i][j] = 1;
			else if (ch == '0')
				a[i][j] = 0;
			else
				a[i][j] = 2;
		}
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	
	
	return 0;
}
