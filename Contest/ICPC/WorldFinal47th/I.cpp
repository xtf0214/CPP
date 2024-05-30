/** 
 * @file    :   I
 * @author  :   Tanphoon 
 * @date    :   2024/04/19 01:37
 * @version :   2024/04/19 01:37
 */
#include <bits/stdc++.h>
using namespace std;

inline void solve() {
    int n, m;
    cin >> n >> m;
    double s = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            s += x;
        }
    }
    s /= (n * m);
    printf("%.10lf", s);;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}