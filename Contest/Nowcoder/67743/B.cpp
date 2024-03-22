/**
 * @file    :   B
 * @author  :   Tanphoon
 * @date    :   2024/02/26 13:41
 * @version :   2024/02/26 13:41
 * @link    :
 */
#include <bits/stdc++.h>
using namespace std;
inline void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] &= 1;
    }
    if (n & 1) {
        cout << "qcjj\n";
    } else {
        cout << "zn\n";
    }
    return;
    vector<int> b;
    for (int i = 0, j = 0; i < n;) {
        while (j < n && a[j] == a[i])
            j++;
        if ((j - i) & 1)
            b.push_back(a[i]);
        i = j;
    }
    if (b.size() & 1) {
        cout << "qcjj\n";
    } else {
        cout << "zn\n";
    }
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}