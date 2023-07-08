/**
 * @file    :   1846D
 * @author  :   Tanphoon
 * @date    :   2023/07/07 23:23
 * @version :   2023/07/07 23:23
 * @link    :   https://codeforces.com/contest/1846/problem/D
 */
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, d, h;
    cin >> n >> d >> h;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    double area = 0;
    double s = 1.0 * d * h / 2;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] + h > a[i + 1]) {
            double h1 = a[i + 1] - a[i];
            // cerr << 1.0 * (h - h1) * (h - h1) * s / h / h << '\n';
            area += s - 1.0 * (h - h1) * (h - h1) * s / h / h;
        } else {
            area += s;
        }
    }
    area += s;
    cout << fixed << setprecision(8) << area << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}