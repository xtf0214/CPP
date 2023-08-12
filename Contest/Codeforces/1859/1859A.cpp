/**
 * @file    :   1859A
 * @author  :   Tanphoon
 * @date    :   2023/08/12 22:38
 * @version :   2023/08/12 22:38
 * @link    :   https://codeforces.com/contest/1859/problem/A
 */
#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx, x);
        mp[x]++;
    }
    if (mp.size() == 1) {
        cout << -1 << '\n';
        return;
    } else {
        vector<int> a, b;
        for (auto &[k, v] : mp) {
            if (k != mx)
                for (int i = 0; i < v; i++)
                    a.push_back(k);
            else {
                for (int i = 0; i < v; i++)
                    b.push_back(k);
            }
        }
        cout << a.size() << ' ' << b.size() << '\n';
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << ' ';
        cout << '\n';
        for (int i = 0; i < b.size(); i++)
            cout << b[i] << ' ';
        cout << '\n';
    }
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}