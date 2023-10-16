/**
 * @file    :   POJ3061
 * @author  :   Tanphoon
 * @date    :   2023/05/19 17:38
 * @version :   2023/05/19 17:38
 * @link    :   https://vjudge.net/problem/POJ-3061
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int a[N];
int sum, res;
void add(int x) { sum += a[x]; }
void del(int x) { sum -= a[x]; }

void solve() {
    int n, s;
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sum = 0, res = n + 1;
    for (int l = 1, r = 1; l <= n; l++) {
        while (sum < s && r <= n)
            add(r++);
        if (sum < s)
            break;
        res = min(res, r - l);
        del(l);
    }
    if (res > n)
        res = 0;
    cout << res << '\n';
}
int main() {
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}