#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 5, mod = 1e9 + 7;

ll dp[N], s6[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();
    s = " " + s;
    for (int i = 1; i <= n; i++) {
        if (s[i] == '1')
            dp[i] = (dp[i - 1] * 2 + 1 - s6[i - 1] + mod) % mod;
        else
            dp[i] = (dp[i - 1] * 2 + 1) % mod;

        if (s[i] == '6')
            s6[i] = (s6[i - 1] + dp[i - 1] + 1) % mod;
        else
            s6[i] = s6[i - 1];
    }
    cout << dp[n] << endl;
    return 0;
    return 0;
}