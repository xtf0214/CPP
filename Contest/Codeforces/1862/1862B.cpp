/**
 * @file    :   1862B
 * @author  :   Tanphoon
 * @date    :   2023/08/24 23:01
 * @version :   2023/08/24 23:01
 * @link    :   https://codeforces.com/contest/1862/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            cnt++;
            continue;
        }
        if (a[i - 1] == 1) {
            cnt++;
        } else
            cnt += 2;
    }
    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cout << a[i] << " ";
            continue;
        }
        if (a[i - 1] == 1) {
            cout << a[i] << " ";
        } else
            cout << "1 " << a[i] << " ";
    }
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