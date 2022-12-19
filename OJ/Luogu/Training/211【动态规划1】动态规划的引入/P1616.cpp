// P1616 疯狂的采药
// https://www.luogu.com.cn/problem/P1616
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int n, W;
vector<int> w, v;
ll rec() {
    vector<ll> dp(W + 1);
    for (int i = 1; i <= n; i++)
        for (int j = w[i]; j <= W; j++)
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
    return 0;
}