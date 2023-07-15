/**
 * @file    :   I 密集
 * @author  :   Tanphoon
 * @date    :   2023/06/17 01:04
 * @version :   2023/06/17 01:04
 * @link    :   https://ac.nowcoder.com/acm/contest/38487/I
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, int>;
const int N = 1e5 + 5;

pii a[N], b[N];
int n, k;

bool check(int x) {
    for (int i = 1; i <= n; i++)
        b[i] = {a[i].first + a[i].second * x, i};
    sort(b + 1, b + 1 + n);
    int mn = n, ans = 0;
    for (int i = n; i >= 1; i--) {
        if (mn >= b[i].second)
            ++ans;
        mn = min(mn, b[i].second);
    }
    return ans > k;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first;
    for (int i = 1; i <= n; i++)
        cin >> a[i].second;
    sort(a + 1, a + 1 + n);
    ll l = -1, r = 2e9, mid;
    while (r - l > 1) {
        check(mid = (l + r) / 2) ? l = mid : r = mid;
    }
    if (r == 2e9)
        cout << "Never!";
    else
        cout << r;
    return 0;
}