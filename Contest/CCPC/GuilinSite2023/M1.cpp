/**
 * @file    :   M
 * @author  :   Tanphoon
 * @date    :   2023/11/13 00:21
 * @version :   2023/11/13 00:21
 * @link    :   https://codeforces.com/gym/104768/problem/M
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    auto check = [&](int x, int t) {
        int cnt = 0, ans = 0, xx = 0;
        for (int i = 0; i < n; i++) {
            // 原本就有的大于x的个数
            if (a[i] >= x)
                cnt++;
            // 该位置交换后能产生rt(1,0,-1)个大于x的个数
            // 如果x不在b[i]和a[i]之间，那么交换之后不会改变原有的大于x的个数，rt=0
            // 如果b[i]>=x>a[i]，rt=1，交换后个数+1
            // 如果b[i]<x<=a[i]，rt=-1，交换后个数-1
            int rt = (b[i] >= x) - (a[i] >= x);
            ans = max(ans + rt, 0);
            xx = max(xx, ans);
        }
        // 大于x的个数如果==(n+1)/2, 那么x就是中位数
        return cnt + xx >= (n + 1) / 2;
    };
    cout << *ranges::lower_bound(ranges::views::iota(1, 1e9 + 5), 0, check) - 1 << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    while (T--)
        solve();
    return 0;
}