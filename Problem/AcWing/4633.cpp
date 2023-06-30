/**
 * @file    :   4633. 学生和导师
 * @author  :   Tanphoon
 * @date    :   2023/06/29 16:13
 * @version :   2023/06/29 16:13
 * @link    :   https://www.acwing.com/problem/content/4636/
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;
    vector<int> b(a);
    sort(b.begin(), b.end());
    for (int x : a) {
        int y = upper_bound(b.begin(), b.end(), 2 * x) - 1 - b.begin();
        if (b[y] == x)
            y--;
        if (y >= 0)
            cout << b[y] << ' ';
        else 
            cout << -1 << ' ';
    }
    cout << '\n';
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