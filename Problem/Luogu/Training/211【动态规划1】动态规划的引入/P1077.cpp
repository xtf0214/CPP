// P1077 摆花
// https://www.luogu.com.cn/problem/P1077
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e6 + 7;

int n, W;
vector<int> c;
int rec() {
    vector<int> dp(W + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= 1; j--)
            for (int k = 1; j - k >= 0 && k <= c[i]; k++)
                dp[j] = (dp[j] + dp[j - k]) % mod;
    return dp[W];
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> W;
    c.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    cout << rec() << endl;
    return 0;
}