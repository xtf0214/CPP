/**
 * @file    :   I
 * @author  :   Tanphoon
 * @date    :   2024/02/02 16:23
 * @version :   2024/02/02 16:23
 * @link    :   https://ac.nowcoder.com/acm/contest/67741/G
 */
#include <bits/stdc++.h>
using namespace std;
inline void solve() {
    int n;
    cin >> n;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        int x, y, r;
        cin >> x >> y >> r;
        sum += r;
    }
    sum = sum / 100000;
    if (abs(sum - 17) <= 1)
        cout << "bit-noob\n";
    else
        cout << "buaa-noob\n";
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}