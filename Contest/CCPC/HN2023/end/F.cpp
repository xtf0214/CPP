#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;

int n, h, k, a[500002], b[500002];
int f[2000002];
map<int, int> mp;

inline void buildtree(int k, int l, int r) {
	if (l == r) {
		f[k] = b[l];
		return;
	}
	int m = (l + r) / 2;
	buildtree(k + k, l, m);
	buildtree(k + k + 1, m + 1, r);
	f[k] = min(f[k + k], f[k + k + 1]);
}

int calc(int k, int l, int r, int x, int y) {
	if (l == x && r == y) {
		return f[k];
	}
	int m = (l + r) / 2;
	if (y <= m)
		return calc(k + k, l, m, x, y);
	else if (x > m)
		return calc(k + k + 1, m + 1, r, x, y);
	else
		return min(calc(k + k, l, m, x, m), calc(k + k + 1, m + 1, r, m + 1, y));
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	h = n - 1;
	for (int i = 1; i <= h; i++)
		b[i] = a[i + 1] - a[i];
	buildtree(1, 1, h);
	long long ans = 1LL << 60;
//	printf("%d\n", f[1]);
	if (k == 2) {
		for (int i = 1; i <= n; i++) {
			ans = min(ans, 1LL * (a[i + 1] - a[i]) * (a[i + 1] - a[i]));
		}
		printf("%lld\n", ans);
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		int x = i, y = i + k - 1;
		if (y > n)
			break;
		ans = min(ans, 1LL * (a[y] - a[x]) * calc(1, 1, n, x, y - 1));
//		printf("%lld %lld\n", a[y] - a[x], calc(1, 1, n, x, y));
	}
	printf("%lld\n", ans);
	return 0;
}
