// P1048 [NOIP2005 普及组] 采药
// https://www.luogu.com.cn/problem/P1048
#include <bits/stdc++.h>
using namespace std;
int n, W;
vector<int> w, v;
int rec() {
    vector<int> dp(W + 1);
    for (int i = 1; i <= n; i++)
        for (int j = W; j >= w[i]; j--)
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
    return dp[W];
}
int main() {
    cin >> W >> n;
    w.resize(n + 1);
    v.resize(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> w[i] >> v[i];
    cout << rec() << endl;
}