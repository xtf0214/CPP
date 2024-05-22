/** 
 * @file    :   L
 * @author  :   Tanphoon 
 * @date    :   2024/05/07 22:56
 * @version :   2024/05/07 22:56
 * @link    :   https://codeforces.com/gym/102803/problem/L
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
using ll = long long;

ll f(ll n) { return 2 * n * (n + 1); } // 第i层的最后一个
ll getLayer(ll n) {
    ll l = -1, r = 1e8;
    while (r - l > 1) {
        ll mid = (l + r) / 2;
        (f(mid) < n) ? l = mid : r = mid;
    }
    return r;
}
inline void solve() {
    int T;
    cin >> T;
    int pre_x = 0, pre_y = 0;
    while (T--) {
        int op;
        int id, x, y;
        cin >> op;
        if (op == 1) {
            cin >> id;
            int c = getLayer(id);
            int hd = f(c - 1) + 1;     // 最上边
            int mid = hd + 2 * c - 1;  // 最右边
            if (id < mid) {            // 上部分
                x = (id - hd + 1) / 2; // 距离y的偏移
                y = c - x;
                id % 2 ? x = -x : x = x;
            } else { // 下部分
                x = c - (id - mid);
                y = -(c - abs(x));
            }
            cout << x - pre_x << ' ' << y - pre_y << '\n';
        } else {
            cin >> x >> y;
            int c = abs(x) + abs(y);
            int hd = f(c - 1) + 1;    // 最上边
            int mid = hd + 2 * c - 1; // 最右边
            if (y > 0) {              // 上部分
                id = hd + abs(x) * 2;
                x > 0 ? id-- : id;
            } else { // 下部分
                id = mid + c - x;
            }
            cout << id << '\n';
        }
        pre_x = x, pre_y = y;
    }
}
signed main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}