/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2024/06/12 17:46
 * @version :   2024/06/12 17:46
 * @link    :   https://ac.nowcoder.com/acm/contest/84773/A
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n;
    cin >> n;
    int sum = 0;
    vector<int> cnt(4);
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        cnt[x]++;
    }
    if (sum % 2 == 1) {
        cout << "NO\n";
        return;
    }
    for (int i = 1; i <= 3; i++) {
        int x = cnt[i];
        for (int b = 1; b < x; x -= b, b <<= 1)
            a.push_back(i * b);
        a.push_back(x * i);
    }
    vector<int> f(sum / 2 + 1, 0);
    f[0] = 1;
    for (int v : a)
        for (int j = sum / 2; j >= v; j--)
            f[j] |= f[j - v];
    cout << (f[sum / 2] ? "YES" : "NO") << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}