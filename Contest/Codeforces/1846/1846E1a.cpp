/**
 * @file    :   1846E1
 * @author  :   Tanphoon
 * @date    :   2023/07/07 23:59
 * @version :   2023/07/07 23:59
 * @link    :   https://codeforces.com/contest/1846/problem/E1
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 5;

int f[N];

void init() {
    for (ll k = 2; k <= N; k++) {
        ll s = 1 + k;
        for (ll mul = k * k; ;  mul *= k) {
            s += mul;
            if (s >= N)
                break;
            f[s] = 1;
        }
    }
}    
void solve() {
    int n;
    cin >> n;
    puts(f[n] ? "YES" : "NO");
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    init();
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}