/**
 * @file    :   P2340 奶牛展览 [USACO03FALL]Cow Exhibition G
 * @author  :   Tanphoon
 * @date    :   2023/01/15 00:31
 * @version :   2023/01/15 00:31
 * @link    :   https://www.luogu.com.cn/problem/P2340
 */
#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n;
vector<int> s, f;
int solve() {
    const int MR = 40000;
    vector<int> dp(40005 + MR, -INF);
    dp[0 + MR] = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] >= 0)
            for (int j = 40000; j >= -40000 + s[i]; j--)
                dp[j + MR] = max(dp[j + MR], dp[j + MR - s[i]] + f[i]);
        else
            for (int j = -40000; j <= 40000 + s[i]; j++)
                dp[j + MR] = max(dp[j + MR], dp[j + MR - s[i]] + f[i]);
    int ans = -INF;
    for (int i = 0; i <= 40000; i++)
        if (dp[i + MR] >= 0)
            ans = max(ans, dp[i + MR] + i);
    return ans;
}
int main() {
    cin >> n;
    s.resize(n + 1), f.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> s[i] >> f[i];
    cout << solve();
    return 0;
}