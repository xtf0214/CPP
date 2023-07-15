/**
 * @file    :   J 神奇数字
 * @author  :   Tanphoon
 * @date    :   2023/06/15 21:36
 * @version :   2023/06/15 21:36
 * @link    :   https://ac.nowcoder.com/acm/contest/37782/J
 */
#include <bits/stdc++.h>
using namespace std;

int a, b, c;
vector<int> res;
void solve() {
    res.clear();
    cin >> a >> b >> c;
    if (a == b && b == c) {
        cout << -1 << endl;
        return;
    }
    int x = __gcd(abs(a - b), abs(b - c));
    for (int i = 1; i <= x / i; i++) {
        if (x % i == 0) {
            res.push_back(i);
            if (x / i != i)
                res.push_back(x / i);
        }
    }
    sort(res.begin(), res.end());
    for (auto x : res)
        cout << x << ' ';
    cout << endl;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}