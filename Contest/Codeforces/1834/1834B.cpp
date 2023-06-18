/**
 * @file    :   Codeforces Round 879 (Div. 2) 1834B
 * @author  :   Tanphoon
 * @date    :   2023/06/18 22:20
 * @version :   2023/06/18 22:20
 * @link    :   https://codeforces.com/contest/1834/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

int calc(const string &a, const string &b) {
    int n = a.size(), s = 0;
    for (int i = 0; i < n; i++)
        s += abs(a[i] - b[i]);
    return s;
}
void solve() {
    string a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    int ans = 0;
    if (a.size() != b.size()) {
        ans += b[0] - '0' + (b.size() - 1) * 9;
    } else {
        int i = 0;
        while (a[i] == b[i])
            i++;
        ans += calc(a.substr(0, i + 1), b.substr(0, i + 1));
        ans += (a.size() - (i + 1)) * 9;
    }
    cout << ans << '\n';
}
// void solve1() {
//     string a, b;
//     cin >> a >> b;
//     a = string(b.size() - a.size(), '0') + a;
//     while (!a.empty() && !b.empty() && a.front() == b.front()) {
//         a.erase(a.begin());
//         b.erase(b.begin());
//     }
//     if (a.empty())
//         cout << 0 << endl;
//     else
//         cout << (b[0] - a[0]) + (a.size() - 1) * 9 << '\n';
// }
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}