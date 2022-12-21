// P1164 小A点菜
// https://www.luogu.com.cn/problem/P1164
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int W, n;
vector<int> w;

int rec() {
    vector<int> dp(W + 1);
    dp[0] = 1; // 没钱,啥也不买也是一种方案
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= w[i]; j--)
            dp[j] = dp[j] + dp[j - w[i]];
    return dp[W];
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> W;
    w.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    cout << rec();
    return 0;
}