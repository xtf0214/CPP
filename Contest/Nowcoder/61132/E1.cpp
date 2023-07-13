/**
 * @file    :   E
 * @author  :   Tanphoon
 * @date    :   2023/07/13 00:37
 * @version :   2023/07/13 00:37
 * @link    :   https://ac.nowcoder.com/acm/contest/61132/E
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<ll> a(n + 1), pr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pr[i] = pr[i - 1] + a[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        // pr[r] - pr[l - 1] >= m
        int j = lower_bound(pr.begin() + i, pr.end(), m + pr[i - 1]) - pr.begin();
        if (j != n + 1 && pr[j] - pr[i - 1] == m)
            cnt++;
    }
    cout << cnt << '\n';
}