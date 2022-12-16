#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, res = 0;
    cin >> n;
    for (int k = 1; k <= 1000000; k *= 10)
        for (int i = 1; i <= 9; i++)
            if (k * i <= n)
                res++;
            else {
                cout << res << endl;
                return;
            }
}
signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}