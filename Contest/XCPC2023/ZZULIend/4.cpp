#include <bits/stdc++.h>
using namespace std;

int n, m, a[1002], f[1002][1002];

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++) {
		a[i] %= m;
		if (a[i] == 0)
			a[i] = m;
	}
	for (int i = 1; i <= n; i++)
		f[i][0] = f[i][a[i]] = 1;
	for (int i = 1; i <= n; i++) {
		f[i][a[i]] = 1;
		for (int j = 0; j <= m; j++) {
			f[i][j] |= f[i - 1][j];
			int x = (j + a[i]) % m;
			if (x == 0)
				x = m;
			f[i][x] |= f[i - 1][j];
//			if (f[i - 1][j]) {
//				int x = (j + a[i]) % m;
//				if (x == 0)
//					x = m;
//				f[i][x] |= f[i - 1][j];
//			}
		}
	}
	if (f[n][m])
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}