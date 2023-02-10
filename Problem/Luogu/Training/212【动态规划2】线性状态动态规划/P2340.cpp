/**
 * @file    :   P2340 奶牛展览 [USACO03FALL]Cow Exhibition G
 * @author  :   Tanphoon
 * @date    :   2023/01/15 00:31
 * @version :   2023/02/10 22:00
 * @link    :   https://www.luogu.com.cn/problem/P2340
 */
#include <bits/stdc++.h>
using namespace std;

#define at(i) i + MR
const int MR = 400 * 1000;
const int INF = 0x3f3f3f3f;

int n;
vector<int> s, f;
int solve() {
    vector<int> dp(2 * MR + 5, -INF);
    dp[at(0)] = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] >= 0)
            for (int j = MR; j >= -MR + s[i]; j--)
                dp[at(j)] = max(dp[at(j)], dp[at(j) - s[i]] + f[i]);
        else
            for (int j = -MR; j <= MR + s[i]; j++)
                dp[at(j)] = max(dp[at(j)], dp[at(j) - s[i]] + f[i]);
    int ans = -INF;
    for (int i = 0; i <= MR; i++)
        if (dp[at(i)] >= 0)
            ans = max(ans, dp[at(i)] + i);
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