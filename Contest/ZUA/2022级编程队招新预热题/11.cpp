#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;
ll f[N][4];
int main() {
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 3; j++) {
            f[i][j] = f[i - 1][j] + f[i - 1][j - 1] * (j > 0);
            // 搜索区间s[i-j,i-1]长度为j的字串是否有和s[i]相同的字符
            for (int k = i - 1; k >= max(1, i - j); k--)
                if (s[k] == s[i]) {
                    f[i][j] -= f[k - 1][k - (i - j)];
                    break;
                }
        }
    }
    ll ans = 0;
    for (int j = 0; j <= 3; j++)
        ans += f[n][j];
    cout << ans;
    return 0;
}