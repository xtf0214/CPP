// P1049 装箱问题
// https://www.luogu.com.cn/problem/P1049
#include <bits/stdc++.h>
using namespace std;
int W, n;
vector<int> w, dp;
int rec() {
    vector<int> dp(W + 1);
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + w[i]);
    return W - dp[W];
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> W >> n;
    w.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    cout << rec() << endl;
    return 0;
}