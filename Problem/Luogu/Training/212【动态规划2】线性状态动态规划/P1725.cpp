// P1725 琪露诺
// https://www.luogu.com.cn/problem/P1725
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, l, r, ans = -INF;
    cin >> n >> l >> r;
    vector<int> a(n + 1), dp(n + 1, -INF);
    for (int i = 0; i <= n; i++)
        cin >> a[i];
    dp[0] = 0;
    deque<int> q;
    for (int i = l; i <= n; i++) {
        while (!q.empty() && q.front() < i - r)
            q.pop_front();
        while (!q.empty() && dp[q.back()] <= dp[i - l])
            q.pop_back();
        q.push_back(i - l);
        dp[i] = dp[q.front()] + a[i];
        if (i + r > n)
            ans = max(ans, dp[i]);
    }
    cout << ans << endl;
    return 0;
}