/**
 * @file    :   4672. 布料排序
 * @author  :   Tanphoon
 * @date    :   2023/06/29 16:13
 * @version :   2023/06/29 16:13
 * @link    :   https://www.acwing.com/problem/content/4675/
 */
#include <bits/stdc++.h>
using namespace std;

struct node {
    string C;
    int D, U;
};
void solve() {
    int n;
    cin >> n;
    vector<node> a(n);
    for (auto &[C, D, U] : a)
        cin >> C >> D >> U;
    vector<node> b(a);
    sort(a.begin(), a.end(), [](const node &a, const node &b) { return a.C != b.C ? a.C < b.C : a.U < b.U; });
    sort(b.begin(), b.end(), [](const node &a, const node &b) { return a.D != b.D ? a.D < b.D : a.U < b.U; });
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (a[i].U == b[i].U)
            cnt++;
    cout << cnt << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
    return 0;
}