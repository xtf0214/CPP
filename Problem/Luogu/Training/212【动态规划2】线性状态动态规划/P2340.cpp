/**
 * @file    :   P2340 奶牛展览 [USACO03FALL]Cow Exhibition G
 * @author  :   Tanphoon
 * @date    :   2023/01/15 00:31
 * @version :   2023/02/10 22:00
 * @link    :   https://www.luogu.com.cn/problem/P2340
 */
#include <bits/stdc++.h>
using namespace std;

template <typename T, int l, int r> class NegaIdArray {
    vector<T> dat;

  public:
    NegaIdArray(T a = 0) : dat(vector<T>(r - l + 1, a)) {}
    T &operator[](int i) { return dat[i - l]; }
};
const int MR = 400 * 1000;
const int INF = 0x3f3f3f3f;

int n;
vector<int> s, f;
int solve() {
    NegaIdArray<int, -MR, MR> dp(-INF);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] >= 0)
            for (int j = MR; j >= -MR + s[i]; j--)
                dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
        else
            for (int j = -MR; j <= MR + s[i]; j++)
                dp[j] = max(dp[j], dp[j - s[i]] + f[i]);
    int ans = -INF;
    for (int i = 0; i <= MR; i++)
        if (dp[i] >= 0)
            ans = max(ans, dp[i] + i);
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