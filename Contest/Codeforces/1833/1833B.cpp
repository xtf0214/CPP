/**
 * @file    :   B. Restore the Weather
 * @author  :   Tanphoon
 * @date    :   2023/05/21 23:59
 * @version :   2023/05/21 23:59
 * @link    :   https://codeforces.com/contest/1833/problem/B
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a;
    vector<int> b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back({x, i});
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    map<int, int> idx;
    for (int i = 0; i < n; i++)
        idx[a[i].second] = i;
    for (int i = 0; i < n; i++)
        cout << b[idx[i]] << " ";
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}