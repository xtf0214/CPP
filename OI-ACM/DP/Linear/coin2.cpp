#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, W;
vector<int> a;
int rec() {
    vector<int> dp(W + 1, 0);
    dp[0] = 1;
    for (int w = 1; w <= W; w++)
        for (int i = 0; i < n; i++)
            if (w - a[i] >= 0)
                dp[w] = dp[w] + dp[w - a[i]];
    return dp[W];
}
int main() {
    cin >> n >> W;
    a.resize(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << rec();
    return 0;
}