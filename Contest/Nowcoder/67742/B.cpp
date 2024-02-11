/**
 * @file    :   Tokitsukaze_and_Cats
 * @author  :   Tanphoon
 * @date    :   2024/02/09 12:06
 * @version :   2024/02/09 12:06
 * @link    :   https://ac.nowcoder.com/acm/contest/67742/B
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int LEFT = 0, UP = 1;

inline void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    set<array<int, 3>> st;
    while (k--) {
        int x, y;
        cin >> x >> y;
        st.insert({x - 1, y, LEFT});
        st.insert({x, y, LEFT});
        st.insert({x, y - 1, UP});
        st.insert({x, y, UP});
    }
    cout << st.size() << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    while (T--)
        solve();
    return 0;
}