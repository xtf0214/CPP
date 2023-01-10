// P1802 五倍经验日
// https://www.luogu.com.cn/problem/P1802
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int W, n;
vector<int> use, win, lose;
vector<vector<int>> dp;
void rec() {
    vector<int> dp(W + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = W; j >= use[i]; j--)
            dp[j] = max(dp[j] + lose[i], dp[j - use[i]] + win[i]);
        for (int j = use[i] - 1; j >= 0; j--)
            dp[j] += lose[i];
    }
    cout << 5LL * dp[W];
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> W;
    use.resize(n + 1);
    win.resize(n + 1);
    lose.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> lose[i] >> win[i] >> use[i];
    rec();
    return 0;
}