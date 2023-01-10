// P2285 打鼹鼠
// https://www.luogu.com.cn/problem/P2285
#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<int> t(m), y(m), x(m), dp(m);
    for (int i = 0; i < m; i++) {
        cin >> t[i] >> y[i] >> x[i];
        dp[i] = 1;
        for (int j = 0; j < i; j++)
            if (abs(x[i] - x[j]) + abs(y[i] - y[j]) <= t[i] - t[j])
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}