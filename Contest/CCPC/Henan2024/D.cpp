/**
 * @file    :   D
 * @author  :   Tanphoon
 * @date    :   2024/05/15 13:13
 * @version :   2024/05/15 13:13
 * @link    :   https://codeforces.com/gym/105158/problem/D
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define x first
#define y second

long double dist(const pii &u, const pii &v) {
    long double x = abs(u.x - v.x), y = abs(u.y - v.y);
    return (x + y) / hypot(x, y);
}
inline void solve() {
    int n;
    cin >> n;
    vector<pii> points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    sort(points.begin(), points.end(), [](const pii &u, const pii &v) { return (u.x + u.y) < (v.x + v.y); });
    long double ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, dist(points[i - 1], points[i]));
    }
    sort(points.begin(), points.end(), [](const pii &u, const pii &v) { return (u.y - u.x) < (v.y - v.x); });
    for (int i = 1; i < n; i++) {
        ans = max(ans, dist(points[i - 1], points[i]));
    }
    cout << fixed << setprecision(15) << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}