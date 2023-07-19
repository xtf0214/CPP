/**
 * @file    :   A
 * @author  :   Tanphoon
 * @date    :   2023/07/19 14:39
 * @version :   2023/07/19 14:39
 * @link    :   https://ac.nowcoder.com/acm/contest/61657/A
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> a(n + 1), v(n + 1), f(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] += v[i - 1];
    }
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    deque<int> q;
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && i - q.front() >= k)
            q.pop_front();
        if (a[i - 1] < a[i])
            q.push_back(i - 1);
        if (i > k) {
            if (q.empty())
                f[i] = i - k + 1;
            else
                f[i] = f[q.front()];
        }
    }
    while (m--) {
        int x;
        cin >> x;
        cout << v[x] - v[f[x] - 1] << '\n';
    }
    return 0;
}