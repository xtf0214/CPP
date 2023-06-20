#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e3 + 5;
int n;
int x[N], y[N];

int dist(int i, int j) {return (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]); }


signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) 
            for (int k = j + 1; k <= n; k++) {
                int l1 = dist(i, j);
                int l2 = dist(i, k);
                int l3 = dist(j, k);
                if ((l1 == l2) || (l1 == l3) || (l2 == l3)) {
                	double r1 = sqrt(l1), r2 = sqrt(l2), r3 = sqrt(l3);
                	if (r1 + r2 > r3 && r2 + r3 > r1 && r1 + r3 > r2) {
                        ans++;
					}
				}
            }
    cout << ans;
    return 0;
}
