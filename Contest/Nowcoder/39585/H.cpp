/**
 * @file    :   H
 * @author  :   Tanphoon
 * @date    :   2023/09/07 16:34
 * @version :   2023/09/07 16:34
 * @link    :   https://ac.nowcoder.com/acm/contest/39585/H
 */
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> a;
    vector<int> row(n), col(m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int t;
            cin >> t;
            a.push_back({t, i, j});
        }
    sort(a.begin(), a.end(), greater());
    int ans = 0;
    while (n > 0 || m > 0) {
        auto [t, i, j] = a.back();
        a.pop_back();
        if (row[i] == 0 || col[j] == 0) {
            if (row[i] == 0)
                n--;
            if (col[j] == 0)
                m--;
            row[i] = 1;
            col[j] = 1;
            ans = t;
        }
    }
    cout << ans << '\n';
}