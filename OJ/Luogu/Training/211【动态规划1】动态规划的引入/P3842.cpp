// P3842 线段
// https://www.luogu.com.cn/problem/P3842
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<int> l, r;
int rec() {
    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[1][0] = r[1] + r[1] - l[1] - 1;
    dp[1][1] = r[1] - 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = min(dp[i - 1][0] + abs(l[i - 1] - r[i]), dp[i - 1][1] + abs(r[i - 1] - r[i])) + r[i] - l[i] + 1;
        dp[i][1] = min(dp[i - 1][0] + abs(l[i - 1] - l[i]), dp[i - 1][1] + abs(r[i - 1] - l[i])) + r[i] - l[i] + 1;
    }
    return min(dp[n][0] + (n - l[n]), dp[n][1] + (n - r[n]));
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    l.resize(n + 1);
    r.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    cout << rec();
    return 0;
}