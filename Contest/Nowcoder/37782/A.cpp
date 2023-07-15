/**
 * @file    :   A 玉米大炮
 * @author  :   Tanphoon
 * @date    :   2023/05/18 12:47
 * @version :   2023/05/18 12:47
 * @link    :   https://ac.nowcoder.com/acm/contest/37782/A
 */
#include <bits/stdc++.h>
using namespace std;
using i128 = __int128;
int main() {
    int n, t;
    cin >> n >> t;
    i128 m = t;
    vector<pair<int, int>> a(n);
    for (auto &[x, y] : a) {
        cin >> x >> y;
        m -= x;
    }
    if (m <= 0) {
        cout << "0\n";
        return 0;
    }
    auto check = [&](i128 mid) {
        i128 w = 0;
        for (auto &[x, y] : a)
            w += mid / y * x; // 给mid的时间能造成的伤害
        return w >= m;
    };
    i128 l = 0, r = 1e18 + 1, mid; // 查询满足check的最小值，即为r
    while (r - l > 1)
        if (check(mid = (l + r) / 2))
            r = mid;
        else
            l = mid;
    cout << (long long)r << '\n';
    return 0;
}