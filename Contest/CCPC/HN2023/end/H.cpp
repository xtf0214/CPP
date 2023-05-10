#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double eps = 1e-9;

inline void solve() {
	int n, k;
	scanf("%d%d", &n, &k);
	long long cnt = (int)(n / (0.5));
	cnt = min(cnt, 1LL * k);
	ll res = n - cnt * 0.5;
	ll mn;
	ll res2 = n - cnt * 0.5;
	//res2 += eps;
	if (1.0 * n / k < 0.5)
		printf("0 ");
	else {
		printf("%lld ", res2 + 1); 
	}
	ll mx = res + cnt;
	printf("%lld\n", mx);
}

int main() {
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}
