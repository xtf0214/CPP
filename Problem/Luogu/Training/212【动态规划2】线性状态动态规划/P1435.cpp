/**
 * @file    :   P1435 [IOI2000] 回文字串
 * @author  :   Tanphoon
 * @date    :   2023/01/13 22:02
 * @version :   2023/01/13 22:02
 * @link    :   https://www.luogu.com.cn/problem/P1435
 */
#include <bits/stdc++.h>
using namespace std;

string s, t;
int n;
int solve1() {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    return n - dp[n][n];
}
int solve2() {
    vector<vector<int>> dp(2, vector<int>(n + 1));
    int cur = 1;
    for (int i = 1; i <= n; i++, cur ^= 1)
        for (int j = 1; j <= n; j++)
            if (s[i - 1] == t[j - 1])
                dp[cur][j] = dp[cur ^ 1][j - 1] + 1;
            else
                dp[cur][j] = max(dp[cur ^ 1][j], dp[cur][j - 1]);
    return n - dp[cur ^ 1][n];
}
int main() {
    cin >> s;
    n = s.size();
    reverse_copy(s.begin(), s.end(), back_insert_iterator(t));
    cout << solve2();
    return 0;
}